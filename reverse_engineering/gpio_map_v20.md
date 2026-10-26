# Doboz T12 DIY v20 — carte GPIO issue de l’UF2

L’analyse porte sur `t12_doboz_v20.uf2`, le pseudo-C Ghidra et le désassemblage Thumb. « Élevée » signifie que le firmware configure la broche et que son usage est visible dans le code. « Moyenne » signale une attribution à la prise ou au circuit déduite de l’usage et des observations du module. « Indéterminée » ne veut pas dire broche libre.

> **État matériel actualisé :** GP0=SDA et GP1=SCL sont confirmés par le test capacitif v09. GP2 est confirmé par le test LED v18 : le mode GRB 800 kHz affiche correctement rouge, vert, bleu et blanc. Vincent avait aussi observé une troisième piste entre le MPR121 et le MCU; son rôle électrique exact reste à tracer, mais le test combiné MPR121/LED fonctionne.

| GPIO RP2040 | Fonction identifiée | Sens / protocole | Confiance | Indice principal |
|---|---|---|---|---|
| GP0 | MPR121 SDA | I²C0, bidirectionnel | Confirmée par UF2 et test matériel | Le test capacitif v09 fonctionne sur le module avec GP0 en SDA ; analyse UF2 : `0x10006928` et transactions à `0x5A` |
| GP1 | MPR121 SCL | I²C0, sortie horloge | Confirmée par UF2 et test matériel | Le test capacitif v09 fonctionne sur le module avec GP1 en SCL ; analyse UF2 : `0x10006928` |
| GP2 | Données de la chaîne des 12 LED RGB | PIO, sortie série GRB à 800 kHz | Confirmée par UF2 et test matériel v18 | `0x10003468` configure une routine PIO avec broche `2` ; transfert DMA de 12 mots à `0x1000343c`; le mode 1 produit les couleurs attendues |
| GP3 | Clock In, après conditionnement | Entrée numérique active à l’état bas | Élevée pour l’usage logiciel ; moyenne pour la prise | `0x10004dc0` la configure en entrée ; l’ISR `0x10003228` l’échantillonne et la logique `0x10003af4` l’utilise comme horloge externe |
| GP4 | CV pitch | PWM2 A, sortie | Élevée pour le canal PWM ; moyenne pour la prise | `0x10004dc0` sélectionne PWM (4) ; l’ISR écrit le demi-mot bas de `PWM2_CC` depuis une table de notes, `0x1000324c` |
| GP5 | CV auxiliaire | PWM2 B, sortie | Élevée pour le canal PWM ; moyenne pour la prise | `0x10004dc0` sélectionne PWM (4) ; l’ISR écrit le demi-mot haut de `PWM2_CC`, `0x1000325e` |
| GP6 | Reset In, après conditionnement | Entrée numérique active à l’état bas | Élevée pour l’usage logiciel ; moyenne pour la prise | `0x10004dc0` la configure en entrée ; l’ISR `0x10003228` l’échantillonne et `0x10003af4` remet la séquence au début |
| GP7 | Gate Out | Sortie numérique | Élevée pour la fonction ; moyenne pour la prise | `0x10004dc0` la configure en sortie ; l’ISR `0x10003228` écrit `0x80` dans les registres GPIO SET/CLR |
| GP8 | Rôle non établi | — | Indéterminée | Pas de configuration explicite trouvée dans les fonctions analysées |
| GP9 | Rôle non établi | — | Indéterminée | Même limite |
| GP10 | Clic encodeur | Entrée numérique, active à l’état bas | Élevée | `0x10004dc0` la configure en entrée ; lectures dans `0x1001535c` et `0x10013c54`, observation du module |
| GP11 | Encodeur, phase A | Entrée numérique | Élevée | `0x10004dc0` + lecture du bit 11 dans `0x1001535c`, observation du module |
| GP12 | Encodeur, phase B | Entrée numérique | Élevée | `0x10004dc0` + lecture du bit 12 dans `0x1001535c`, observation du module |
| GP13 | Rôle non établi | — | Indéterminée | Pas de configuration explicite trouvée |
| GP14 | Rôle non établi | — | Indéterminée | Même limite |
| GP15 | Rôle non établi | — | Indéterminée | Même limite |
| GP16 | OLED D/C | Sortie numérique | Élevée | `0x10006c44` ; bas pour commandes, haut pour données dans `0x10006abc` et `0x10006bdc` |
| GP17 | OLED CS | SPI0 CSn | Élevée | `0x10006c44` sélectionne fonction SPI (1) |
| GP18 | OLED CLK | SPI0 SCK | Élevée | `0x10006c44` sélectionne fonction SPI (1) |
| GP19 | OLED MOSI | SPI0 TX | Élevée | `0x10006c44` sélectionne fonction SPI (1) |
| GP20 | OLED RESET | Sortie numérique | Élevée | `0x10006c44` la configure en sortie puis applique une impulsion de réinitialisation |
| GP21 | LED du bouton Octave + | Sortie numérique | Élevée | `0x10004dc0` puis commande dans `0x1001535c`, observation du module |
| GP22 | LED du bouton Octave − | Sortie numérique | Élevée | `0x10004dc0` puis commande dans `0x1001535c`, observation du module |
| GP23 | Rôle non établi | — | Indéterminée | Pas de configuration explicite trouvée |
| GP24 | Rôle non établi | — | Indéterminée | Même limite |
| GP25 | Rôle non établi | — | Indéterminée | Même limite |
| GP26 / ADC0 | CV In | Entrée analogique | Élevée | `0x10004dc0` active l’ADC sur GP26 ; l’ISR lit `ADC_RESULT` et stocke les échantillons |
| GP27 / ADC1 | Bouton Octave − | Entrée numérique | Élevée | Tableau de broches `0x10029584` = `27, 28`, lecture dans `0x1001535c`, observation du module |
| GP28 / ADC2 | Bouton Octave + | Entrée numérique | Élevée | Même tableau et observation du module |
| GP29 / ADC3 | Rôle non établi | — | Indéterminée | Aucune utilisation du canal ADC3 mise en évidence ; l’utilisateur ne voit pas de connexion |

## Conclusions matérielles

- Les sorties GP4 et GP5 utilisent le **PWM2 du RP2040** avec `TOP = 0xFFF` (12 bits) et un diviseur de `0x10` selon `0x10004e90`. Le TL074 et le réseau de filtrage/amplification peuvent transformer ces PWM en CV ; cette route analogique précise n’est pas visible entièrement dans le binaire.
- Le MPR121 est piloté par I²C0 à l’adresse `0x5A`. L’UF2 utilise GP2 pour les LED RGB et lit le MPR121 par interrogation; la relation physique de la troisième piste observée près du MPR121 n’est pas établie ici.
- GP3 et GP6 sont lus périodiquement par l’interruption PWM, en logique **active bas**. Une impulsion courte peut donc être absente d’un affichage qui ne compte que les niveaux stables.
- GP4 reçoit la valeur issue de la table de notes (`0x10013268` → `0x200031BE`), GP5 une valeur calculée séparément (`0x10013200` → `0x200031E8`). Cela fonde l’attribution pitch/aux ; l’association finale aux prises est encore inférée.
- Le pseudo-C Ghidra ne représente qu’une des deux écritures consécutives vers l’alias XOR de `PWM2_CC` dans `pwm_irq`. Le désassemblage aux adresses `0x1000324C` et `0x1000325E` montre les deux canaux. Pour ce point, le désassemblage prime.

Les fonctions alternatives des broches et les adresses des registres proviennent de la [documentation officielle RP2040](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf) et du [SDK Raspberry Pi](https://github.com/raspberrypi/pico-sdk/blob/master/src/rp2040/hardware_regs/include/hardware/regs/addressmap.h).
