# Firmware de diagnostic T12

| Version | État matériel | Brochage / fonction | UF2 |
|---|---|---|---|
| v24_cv_pwm_carrier | Utilisé dans un VCO; aucun artefact audible selon Vincent. Suivi 1 V/oct encore à calibrer. | Même balayage 0–7 V et même mapping calibré empiriquement que v23; diviseur PWM 1 au lieu de 16, porteuse attendue ~48,8 kHz, résolution conservée à 12 bits. | `../build/versions/v24_cv_pwm_carrier/T12_CV_PWM_Carrier.ino.uf2` |
| v23_cv_octave_sweep | GP4 vérifié au multimètre : 0–7 V suivent la consigne à ±50 mV; ondulation PWM ~3,051 kHz mesurée. GP5 à mesurer sous v23. | Pages CV 4/5 balayent 0–7 V par pas de 1 V. Mapping PWM inversé et compensé par ajustement empirique. | `../build/versions/v23_cv_octave_sweep/T12_CV_Octave_Sweep.ino.uf2` |
| v22_cv_zero_test | Compilé pour RP2040 ; mesure à effectuer | Pages CV 4/5 ajoutent 0 V / PWM 0 avant les demi-tons C3–C4 (Pitch) et C2–C3 (Aux). Les autres pages et contrôles sont conservés. | `../build/versions/v22_cv_zero_test/T12_CV_Zero_Test.ino.uf2` |
| v05_recovered_gpio_input_test | Confirmé fonctionnel | Scan GPIO passif avec OLED. Aucun GPIO d’entrée n’est piloté. | `../build/versions/v05_recovered_gpio_input_test/T12_GPIO_Input_Test.ino.uf2` |
| v06_mpr121_touch_test | Écran noir signalé ; ne pas reflasher | Première tentative MPR121 via Arduino Wire. Conservée pour traçabilité. | `../build/versions/v06_mpr121_touch_test/T12_MPR121_Touch_Test.ino.uf2` |
| v07_mpr121_touch_i2c0 | Compilé ; pas encore vérifié sur le module | OLED v05 inchangé ; pilote MPR121 via I²C0 direct sur GP0/GP1 ; GP2 non configuré (IRQ probable). | `../build/versions/v07_mpr121_touch_i2c0/T12_MPR121_Touch_Test.ino.uf2` |
| v08_screen_button_rgb_test | Confirmé fonctionnel par l’utilisateur | OLED, encodeur, boutons Octave et leurs LED. Le scan des LED RGB n’a rien détecté. | `../build/versions/v08_screen_button_rgb_test/T12_Screen_Button_RGB_Test.ino.uf2` |
| v09_capacitive_touch_screen | Confirmé fonctionnel par Vincent | OLED et lecture des 12 pads MPR121 confirmées. GP0=SDA, GP1=SCL sur I²C0 confirmés par le test sur le module. | `../build/versions/v09_capacitive_touch_screen/T12_Capacitive_Touch_Test.ino.uf2` |
| v10_oled_column_wrap | Rejeté ; ne pas utiliser | Décalage des colonnes OLED empirant l’affichage. Le UF2 actif a été restauré au v09 confirmé. | `../build/versions/v10_oled_column_wrap/T12_Capacitive_Touch_Test.ino.uf2` |
| v11_pixel_column_wrap | Non concluant ; bande à droite persistante | Réordonne les colonnes framebuffer mais ne règle pas le décalage de la fenêtre OLED. | `../build/versions/v11_pixel_column_wrap/T12_Capacitive_Touch_Test.ino.uf2` |
| v12_oled_window_wrap | Compilé ; à vérifier sur le module | Réordonne les colonnes 126–127 en tête et débute l’écriture à la colonne RAM 2 pour la fenêtre visible OLED. | `../build/versions/v12_oled_window_wrap/T12_Capacitive_Touch_Test.ino.uf2` |
| v13_jack_io_test | Compilé ; les jacks restent à vérifier | Six pages de test Reset/Clock/CV In/CV Notes/CV Aux/Gate. Reprend les contrôles confirmés et l’alignement OLED v12. CV/Gate commencent à zéro et sont remis à zéro en quittant leur page de sortie. | `../build/versions/v13_jack_io_test/T12_Jack_IO_Test.ino.uf2` |
| v14_jack_io_cv_test | Compilé ; CV In et Gate Out confirmés par l’utilisateur; Reset/Clock et sorties CV à mesurer | Conserve les contrôles confirmés; compte les fronts Reset/Clock via IRQ; consignes CV 0–8 V hypothétiques avec code PWM affiché. | `../build/versions/v14_jack_io_cv_test/T12_Jack_IO_CV_Test.ino.uf2` |
| v15_cv_range_gpio_scan | Compilé ; scan matériel en attente | CV Notes GP4 : C3–C4 chromatique; CV Aux GP5 : C2–C3; hypothèse 1 V/octave, code PWM affiché. Page de scan d’entrées sans pulls/sorties pour GPIO non attribués; Gate Out basculable depuis cette page pour test en boucle. | `../build/versions/v15_cv_range_gpio_scan/T12_CV_Range_GPIO_Scan.ino.uf2` |
| v16_gpio_scan_visible | Compilé ; à vérifier sur le module | Corrige la page 7 : état Gate visible et compteurs GP3/GP6 inclus avec les GPIO candidats. Octave + bascule Gate, Octave − LOW. | `../build/versions/v16_gpio_scan_visible/T12_GPIO_Scan_Visible.ino.uf2` |
| v17_gpio_scan_levels | Compilé ; à vérifier sur le module | Page 7 affiche les niveaux bruts H/L et les fronts GP3/GP6 et candidats; Gate reste visible et pilotable. | `../build/versions/v17_gpio_scan_levels/T12_GPIO_Scan_Levels.ino.uf2` |
| v18_rgb_led_protocol_test | GP2 et le format GRB 800 kHz confirmés par l’utilisateur | Le mode 1 affiche la suite attendue rouge, vert, bleu, blanc. Les autres modes montrent des permutations ou un mauvais décodage. | `../build/versions/v18_rgb_led_protocol_test/T12_RGB_LED_Protocol_Test.ino.uf2` |
| v19_rgb_animations | Compilé pour RP2040 ; animations à vérifier sur le module | Page 8 utilise uniquement GP2 en GRB 800 kHz. Octave −/+ parcourt 7 animations : arc-en-ciel, poursuite, rebond, remplissage, guirlande, bandes de couleurs et respiration de luminosité. | `../build/versions/v19_rgb_animations/T12_RGB_LED_Animations.ino.uf2` |
| v20_clock_gpio_scan | Compilé pour RP2040 ; scan à vérifier au module | Page 9 balaie GP3–GP6, GP8–GP9, GP13–GP15 et GP23–GP25/GP29 en entrée. L’écran alterne deux groupes, avec le niveau brut et les fronts montants/descendants. Octave −/+ essaie aucun pull/pull-down/pull-up; le clic inverse l’interprétation actif bas/haut. GP4/GP5 passent en entrée haute impédance sur cette page et retrouvent le PWM en la quittant. | `../build/versions/v20_clock_gpio_scan/T12_Clock_GPIO_Scan.ino.uf2` |

SHA-256 v05 : `58df972ef6db4bd32ea4e4e51693b539385464b98d6edb48d763a6e9f72fd0eb`

SHA-256 v07 : `0eecef2a0482d7e588eae1903b3cf33a15e5eeae6bfd5b0c3b00aa59634fd8f4`

SHA-256 v08 : `d8bfa843b15edefb999922cd081f7143c695f172c66ba5544ebcb323f8980b8a`

SHA-256 v12 : `5368df7f3515ca97395e90ee8a06e6d4314d7fc2428d9b7d46304c16c762face`

SHA-256 v13 : `b4ee452f95e53de6a6a3261bfc57da440869f6a6203b788ff03de59aae12fd6e`

SHA-256 v14 : `60989600f7d5e1f232f07aeb10bbda3dfa0ba1515b1ecd883c5b6625bd0d91d2`

SHA-256 v15 : `872c031016567ff2772cd7e1ad55ebec9d7350460c075d742ff6716fd58d6b9e`

SHA-256 v16 : `b1986ea9313761fc85aef528b3c1c98730cf2c65147ea5490634d827b5bf3196`

SHA-256 v17 : `ea93bae12659ff7dab9e5678e4fc8a46b70611667f5c0a7250d849c3201250ce`

SHA-256 v18 : `931bea3d4dca7950c1747dd40fe1d0ebf01e7e82f7811df32a7c274e2dd113ab`

SHA-256 v19 : `5338ad0dc33d3fcf01f8cc2113d43f4856a12cb1a02c6721fea1e9081d01f2d0`

SHA-256 v20 : `a86a303f002f0c54ea88ec28086c60fa27a70065400fa01346451c3702fafe7b`

SHA-256 v22 : `9050053924e942794a630514ab244988ab08cc7192a2cbef77b2f4b5c0db5496`

SHA-256 v23 : `79a13be0cf2f1aa5b560f5f1c3cc1080136d3908ac6534e10a6a729b0f24bfe7`

SHA-256 v24 : `c96adf01f0037b5b7e95a26871042549eb8f175147f32df4ec68bdd80353c28b`
