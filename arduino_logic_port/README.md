# T12 KeySeq — port de la logique Arduino

Ce dossier contient une copie isolée du sketch Arduino `KeySeq_stable_version_v2.1.ino`.
La logique de lecture, d’enregistrement, de génération du Gate et de calcul des notes doit rester la référence de ce port.

## Adaptation matérielle T12

| Fonction | T12 |
|---|---:|
| MPR121 SDA/SCL | GP0 / GP1 |
| LED RGB pads | GP2 |
| Clock In | GP3, pull-up, actif bas |
| Pitch CV PWM | GP4 |
| Auxiliary CV PWM | GP5 |
| Reset In | GP6, pull-up, actif bas |
| Gate Out | GP7 |
| Encoder click / A / B | GP10 / GP11 / GP12 |
| OLED DC / CS / SCK / MOSI / RESET | GP16 / GP17 / GP18 / GP19 / GP20 |
| CV In | GP26 / ADC0 |

Le MCP4725 du sketch original n’est pas utilisé ici : les sorties CV sont générées par les PWM 12 bits du RP2040 sur GP4 et GP5, avec la polarité inversée imposée par l’étage analogique du T12. Le clavier TTP229 est remplacé par le MPR121.

## État

Le port Arduino est compilé avec le core `rp2040:rp2040` pour Raspberry Pi Pico. Le sketch conserve l’ordre du code original : calcul CV, écriture de la sortie CV, puis déclenchement Gate. Le firmware natif situé dans `sequencer/` n’est pas modifié par ce travail.

Compilation :

```text
arduino-cli compile --fqbn rp2040:rp2040:rpipico T12_KeySeq_ArduinoLogic
Sketch uses 120720 bytes (5%)
Global variables use 13680 bytes (5%)
```
