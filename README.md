# Doboz T12 — séquenceur C++ natif

- **[UF2 MVP 0.1.4](T12_Sequencer_MVP_v0.1.4.uf2)**
- [Mode d’emploi et compilation](sequencer/README.md)
- [Code C++](sequencer/src/main.cpp)

Le MVP reprend les GPIO validés et ajoute l’application séquenceur. Il est compilé et vérifié par des tests logiciels ; son essai matériel reste à effectuer.

# Doboz T12 DIY v20 — tests conservés

- GPIO confirmés : [LISTE_GPIO.md](LISTE_GPIO.md)
- Test CV avec porteuse PWM accélérée : [UF2 v24](T12_CV_PWM_Carrier.uf2) · [code source](firmware_versions/v24_cv_pwm_carrier/T12_CV_PWM_Carrier/T12_CV_PWM_Carrier.ino)
- Test CV inversé, paliers 0–7 V : [UF2 v23](T12_CV_Octave_Sweep.uf2) · [code source](firmware_versions/v23_cv_octave_sweep/T12_CV_Octave_Sweep/T12_CV_Octave_Sweep.ino)
- Test CV avec palier 0 V : [UF2 v22](T12_CV_Zero_Test.uf2) · [code source](firmware_versions/v22_cv_zero_test/T12_CV_Zero_Test/T12_CV_Zero_Test.ino)
- Test de scan Clock/GPIO : [UF2 v20](T12_Clock_GPIO_Scan.uf2) · [code source](firmware_versions/v20_clock_gpio_scan/T12_Clock_GPIO_Scan/T12_Clock_GPIO_Scan.ino)
- Test LED RGB animé : [UF2 v19](T12_RGB_LED_Animations.uf2) · [code source](firmware_versions/v19_rgb_animations/T12_RGB_LED_Animations/T12_RGB_LED_Animations.ino)

Sur les pages CV 4 et 5 du v23, Octave −/+ choisit une consigne de 0 à 7 V par pas de 1 V (une octave). Le PWM est inversé et ajusté selon la pente observée au multimètre; cette calibration empirique reste à vérifier au scope. Les pages de diagnostic et les contrôles confirmés sont conservés.

Le v24 conserve ce mapping et cette résolution 12 bits, mais passe le diviseur PWM de 16 à 1 : la porteuse attendue monte d’environ 3,05 kHz à 48,8 kHz. Comparer le Vpp sur GP4 et GP5, notamment aux consignes 3–4 V.

Le v05 est le scan GPIO de référence, confirmé fonctionnel. Le v06 a été signalé écran noir sur le module et ne doit pas être reflasher. Le v08 a confirmé écran, encodeur, boutons Octave et leurs LED. Les révisions v09/v12 ont confirmé le MPR121.

## Test boutons et LED RGB v08

- UF2 : [T12_Screen_Button_RGB_Test.uf2](T12_Screen_Button_RGB_Test.uf2)
- Code : [T12_Screen_Button_RGB_Test.ino](firmware_versions/v08_screen_button_rgb_test/T12_Screen_Button_RGB_Test/T12_Screen_Button_RGB_Test.ino)
- SHA-256 : `d8bfa843b15edefb999922cd081f7143c695f172c66ba5544ebcb323f8980b8a`

Le v08 reprend l'initialisation OLED du v05. Vincent confirme que l’écran, l’encodeur, les boutons Octave et leurs LED fonctionnent. Le scan des LED RGB n’a pas identifié leur GPIO.

## Test des touches capacitives v09 — confirmé

- Code confirmé : [T12_Capacitive_Touch_Test.ino](firmware_versions/v09_capacitive_touch_screen/T12_Capacitive_Touch_Test/T12_Capacitive_Touch_Test.ino)

Vincent confirme que l’écran et le test du MPR121 fonctionnent sur le module. **GP0 = SDA et GP1 = SCL de l’I²C0 du MPR121** sont donc confirmés par le firmware et l’essai matériel. L’écran affiche les 12 touches et marque `P` quand une touche est appuyée.

## Test capacitif confirmé — v12

- UF2 : [T12_Capacitive_Touch_Test.uf2](T12_Capacitive_Touch_Test.uf2)
- Code : [T12_Capacitive_Touch_Test.ino](firmware_versions/v12_oled_window_wrap/T12_Capacitive_Touch_Test/T12_Capacitive_Touch_Test.ino)
- SHA-256 : `5368df7f3515ca97395e90ee8a06e6d4314d7fc2428d9b7d46304c16c762face`

Le v12 conserve la lecture MPR121 du v09 confirmé. Vincent confirme que l’écran est maintenant aligné avec l’écriture débutant à la colonne RAM 2 et les colonnes framebuffer 126–127 envoyées en premier. Cette méthode est réutilisée ci-dessous.

## Test des LED RGB adressables — v18

- UF2 : [T12_RGB_LED_Protocol_Test.uf2](T12_RGB_LED_Protocol_Test.uf2)
- Code : [T12_RGB_LED_Protocol_Test.ino](firmware_versions/v18_rgb_led_protocol_test/T12_RGB_LED_Protocol_Test/T12_RGB_LED_Protocol_Test.ino)
- SHA-256 : `931bea3d4dca7950c1747dd40fe1d0ebf01e7e82f7811df32a7c274e2dd113ab`

La page 8 envoie un motif RGB sur les 12 LED. Elle démarre sur GP2. Octave − parcourt six modes (GRB/RGB/BGR à 800 kHz, GRB à 400 kHz, GRBW/RGBW à 800 kHz); Octave + change de GPIO parmi GP2, GP8, GP9, GP13–GP15 et GP23–GP25. L’écran affiche le GPIO et le mode actuels. Seule la broche testée devient une sortie; en quittant la page, les LED sont éteintes et la broche revient en entrée.

Ces réglages couvrent des protocoles courants de LED à un fil; sans référence du composant, l’absence d’éclairage ne permet pas à elle seule de conclure que le GPIO est incorrect.

## Diagnostic des niveaux d’entrée — v17

- UF2 : [T12_GPIO_Scan_Levels.uf2](T12_GPIO_Scan_Levels.uf2)
- Code : [T12_GPIO_Scan_Levels.ino](firmware_versions/v17_gpio_scan_levels/T12_GPIO_Scan_Levels/T12_GPIO_Scan_Levels.ino)
- SHA-256 : `ea93bae12659ff7dab9e5678e4fc8a46b70611667f5c0a7250d849c3201250ce`

La page 7 affiche maintenant le niveau brut H/L et le compteur de fronts pour GP3, GP6 et les GPIO candidats, ce qui aide si un pin reste bloqué à un niveau constant. L’état de Gate reste visible et Octave +/− le bascule ou le force à LOW. Les GPIO observés restent en entrée sans pull interne.

## Diagnostic page 7 corrigé — v16

- UF2 : [T12_GPIO_Scan_Visible.uf2](T12_GPIO_Scan_Visible.uf2)
- Code : [T12_GPIO_Scan_Visible.ino](firmware_versions/v16_gpio_scan_visible/T12_GPIO_Scan_Visible/T12_GPIO_Scan_Visible.ino)
- SHA-256 : `b1986ea9313761fc85aef528b3c1c98730cf2c65147ea5490634d827b5bf3196`

La page 7 affiche maintenant l’état Gate (LOW/HIGH) et les compteurs de fronts GP3 Clock, GP6 Reset et des GPIO non attribués. Octave + bascule Gate; Octave − la remet à LOW. Cela rend visible le test même si aucun signal externe ne change les GPIO.

## Test de gamme CV et scan GPIO — v15

- UF2 : [T12_CV_Range_GPIO_Scan.uf2](T12_CV_Range_GPIO_Scan.uf2)
- Code : [T12_CV_Range_GPIO_Scan.ino](firmware_versions/v15_cv_range_gpio_scan/T12_CV_Range_GPIO_Scan/T12_CV_Range_GPIO_Scan.ino)
- SHA-256 : `872c031016567ff2772cd7e1ad55ebec9d7350460c075d742ff6716fd58d6b9e`

Page 4 : Octave −/+ parcourt C3 à C4 par demi-tons sur GP4. Page 5 : même geste pour C2 à C3 sur GP5. L’écran affiche la note et le code PWM. Le calcul suppose 1 V/octave et C0=0 V; vérifie les tensions réelles au multimètre. Une seule sortie CV est activée à la fois, et elle est remise à zéro en quittant sa page.

Page 1/2 garde Reset GP6 et Clock GP3 avec compteur de fronts et inversion de logique au clic encodeur. Page 7 scanne sans pull les GPIO non attribués (GP2, 8, 9, 13–15, 23–25, 29) et affiche leur nombre de transitions. Octave + bascule Gate Out GP7; Octave − le remet à LOW. Un câble entre Gate Out et l’entrée à tester permet de vérifier si l’impulsion arrive à un candidat. Les GPIO observés restent en entrée haute impédance.

## Test des jacks — v14

- UF2 : [T12_Jack_IO_CV_Test.uf2](T12_Jack_IO_CV_Test.uf2)
- Code : [T12_Jack_IO_CV_Test.ino](firmware_versions/v14_jack_io_cv_test/T12_Jack_IO_CV_Test/T12_Jack_IO_CV_Test.ino)
- SHA-256 : `60989600f7d5e1f232f07aeb10bbda3dfa0ba1515b1ecd883c5b6625bd0d91d2`

Cette version conserve l’OLED, le MPR121, l’encodeur et les boutons/LEDs octave. Les pages CV Notes GP4 et Auxiliary CV GP5 proposent chacune des consignes de 0 à 8 V, sélectionnées avec Octave −/+; l’écran montre aussi le code PWM appliqué. L’échelle 0–8 V est une hypothèse de test, pas une calibration : mesurer chaque palier au multimètre. Les sorties reviennent à zéro en quittant leur page. Gate Out GP7 est confirmé; Octave + le bascule et Octave − le force à LOW.

Reset In GP6 et Clock In GP3 sont encore à valider. Les pages affichent le niveau brut, le niveau logique interprété et le compteur de fronts matériels (montants et descendants), capturés par IRQ afin de ne pas manquer une impulsion courte. Le clic encodeur inverse l’interprétation active-bas/active-haut pour l’entrée affichée. CV In GP26/A0 affiche la valeur ADC et la tension estimée au pin MCU.

Le UF2 est compilé pour RP2040; le comportement physique des sorties CV et des entrées Reset/Clock reste à confirmer sur le module.

## Test des jacks — v13 (historique)

- UF2 : [T12_Jack_IO_Test.uf2](T12_Jack_IO_Test.uf2)
- Code : [T12_Jack_IO_Test.ino](firmware_versions/v13_jack_io_test/T12_Jack_IO_Test/T12_Jack_IO_Test.ino)
- SHA-256 : `b4ee452f95e53de6a6a3261bfc57da440869f6a6203b788ff03de59aae12fd6e`

Tourner l’encodeur parcourt les six pages : Reset In GP6, Clock In GP3, CV In GP26/A0, CV Notes Out GP4, Auxiliary CV Out GP5, Gate Out GP7. Cliquer sur l’encodeur inverse la logique de Reset ou Clock selon la page. Les entrées CV affichent le compte ADC et la tension estimée au pin MCU (0–3,3 V), pas la tension du jack avant conditionnement. Sur les pages CV Out, Octave +/− ajuste le PWM en 10 paliers; le code PWM est affiché pour comparaison au multimètre. Ces sorties démarrent à 0 et reviennent à 0 en quittant leur page. Sur Gate Out, Octave + bascule la sortie et Octave − la force à zéro; Gate revient à zéro en quittant sa page. Les LED des boutons suivent toujours leur état; le MPR121 est interrogé en continu et le nombre de pads actifs est affiché.

Le UF2 est compilé pour RP2040 mais ces six jacks restent à valider physiquement. Les broches jack sont candidates selon l’analyse UF2 jusqu’à vérification au module.

## Test MPR121 v07

- UF2 : [build/versions/v07_mpr121_touch_i2c0/T12_MPR121_Touch_Test.ino.uf2](build/versions/v07_mpr121_touch_i2c0/T12_MPR121_Touch_Test.ino.uf2)
- Code : [T12_MPR121_Touch_Test.ino](firmware_versions/v07_mpr121_touch_i2c0/T12_MPR121_Touch_Test/T12_MPR121_Touch_Test.ino)
- Pilote : [T12MPR121.cpp](firmware_versions/v07_mpr121_touch_i2c0/T12_MPR121_Touch_Test/T12MPR121.cpp)
- SHA-256 : `0eecef2a0482d7e588eae1903b3cf33a15e5eeae6bfd5b0c3b00aa59634fd8f4`

I²C0 est explicitement muxé sur SDA=GP0 et SCL=GP1. Le test v07 laissait GP2 intact et lisait les touches par polling; à l’époque son rôle était supposé être IRQ. Le test matériel v18 a depuis confirmé GP2 comme données RGB en GRB 800 kHz. Le pilote reprend les registres et seuils configurés par le firmware Doboz v20. La sortie IRQ du MPR121 est open-drain active bas, mais elle n’est pas utilisée par le test capacitif.

Pour revenir au test connu comme fonctionnel : [UF2 v05](build/versions/v05_recovered_gpio_input_test/T12_GPIO_Input_Test.ino.uf2).
