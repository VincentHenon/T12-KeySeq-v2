#include "display.hpp"
#include "hardware.hpp"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"
#include "rgb.pio.h"
#include <cstdio>
#include <initializer_list>
using namespace t12;
namespace {
constexpr unsigned RgbPin=2, Plus=hw::pin::Plus, Minus=hw::pin::Minus, Click=hw::pin::Click;
PIO pio=pio0; int sm=0; unsigned selected=0; int hue=0, turns=0; uint8_t prevState=0,detent=0; int quarters=0; bool lp=true,lm=true,lc=true; unsigned maskMode=0;
void irq(unsigned gpio,uint32_t){if(gpio!=hw::pin::EncoderA&&gpio!=hw::pin::EncoderB)return;uint8_t s=(gpio_get(hw::pin::EncoderA)?2:0)|(gpio_get(hw::pin::EncoderB)?1:0);static constexpr int8_t t[16]={0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};quarters+=t[(prevState<<2)|s];prevState=s;if(s==detent){if(quarters>=4)++turns;if(quarters<=-4)--turns;quarters=0;}}
uint32_t rainbow(int h){h=(h%360+360)%360;unsigned x=(h%60)*255/60, r=0,g=0,b=0;switch(h/60){case 0:r=255;g=x;break;case 1:r=255-x;g=255;break;case 2:g=255;b=x;break;case 3:g=255-x;b=255;break;case 4:r=x;b=255;break;default:r=255;b=255-x;}if(maskMode==1)r=0;if(maskMode==2)g=0;if(maskMode==3)b=0;return ((g*220/255)<<16)|((r*220/255)<<8)|(b*220/255);}
void sendFrame(int active){
  // The RP2040 PIO consumes the 24 least-significant bits when shifting right.
  // Send exactly one complete 12-pixel frame, then let the reset time latch it.
  pio_sm_clear_fifos(pio,sm); pio_sm_restart(pio,sm);
  for(unsigned stream=0;stream<12;++stream){
    unsigned logical=(stream<4?stream+8:(stream<8?stream:stream-8));
    uint32_t v=(active>=0 && logical==unsigned(active)) ? (rainbow(hue) << 8) : 0;
    pio_sm_put_blocking(pio,sm,v);
  }
  sleep_us(800);
}
bool haveSelection=true;
bool idlePlus=true,idleMinus=true,idleClick=true;
void send(){ sendFrame(haveSelection ? int(selected) : -1); }
void draw(){Canvas c;c.text(0,0,"RGB ADDRESS TEST");char b[40];unsigned stream=(selected<4?selected+8:(selected<8?selected:selected-8));std::snprintf(b,sizeof b,"KEY %02u  BUS %02u",selected+1,stream+1);c.text(0,16,b);const char*n[]={"RAINBOW","NO RED","NO GREEN","NO BLUE"};std::snprintf(b,sizeof b,"COLOR: %s",n[maskMode]);c.text(0,30,b);c.text(0,46,"+/- SELECT  ENC HUE");c.text(0,57,"CLICK RGB FILTER");display::publish(c);}
void setup(){auto off=pio_add_program(pio,&rgb_program);auto cfg=rgb_program_get_default_config(off);sm_config_set_sideset_pins(&cfg,RgbPin);sm_config_set_out_shift(&cfg,false,true,24);sm_config_set_fifo_join(&cfg,PIO_FIFO_JOIN_TX);sm_config_set_clkdiv(&cfg,float(clock_get_hz(clk_sys))/8000000.0f);pio_gpio_init(pio,RgbPin);pio_sm_set_consecutive_pindirs(pio,sm,RgbPin,1,true);pio_sm_init(pio,sm,off,&cfg);pio_sm_set_enabled(pio,sm,true);}
}
int main(){stdio_init_all();display::launch();for(auto p:{hw::pin::EncoderA,hw::pin::EncoderB,Plus,Minus,Click}){gpio_init(p);gpio_set_dir(p,false);gpio_pull_up(p);}idlePlus=gpio_get(Plus);idleMinus=gpio_get(Minus);idleClick=gpio_get(Click);lp=idlePlus;lm=idleMinus;lc=idleClick;prevState=detent=(gpio_get(hw::pin::EncoderA)?2:0)|(gpio_get(hw::pin::EncoderB)?1:0);gpio_set_irq_enabled_with_callback(hw::pin::EncoderA,GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL,true,&irq);gpio_set_irq_enabled(hw::pin::EncoderB,GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL,true);setup();draw();send();while(true){if(turns){hue+=turns*15;turns=0;draw();send();}bool p=gpio_get(Plus),m=gpio_get(Minus),c=gpio_get(Click);if(p!=idlePlus&&lp==idlePlus){selected=(selected+1)%12;haveSelection=true;draw();send();sleep_ms(40);}if(m!=idleMinus&&lm==idleMinus){selected=(selected+11)%12;haveSelection=true;draw();send();sleep_ms(40);}if(c!=idleClick&&lc==idleClick){maskMode=(maskMode+1)%4;haveSelection=true;draw();send();sleep_ms(40);}lp=p;lm=m;lc=c;sleep_ms(2);}}
