# T12 Sequencer — MVP 0.1.5

Firmware en **C++20 natif, Raspberry Pi Pico SDK 2.2.0**, pour le Doboz T12 DIY v20 / RP2040. Aucune dépendance au framework Arduino. Les protocoles du diagnostic matériel validé sont repris : OLED SPI avec correction des deux colonnes, MPR121, LED GRB 800 kHz, boutons, encodeur, jacks et PWM CV inversé. Les touches et LED suivent la même grille : Key 1 en haut à gauche, Key 4 en haut à droite, Key 9 en bas à gauche et Key 12 en bas à droite.

**UF2 : [T12_Sequencer_MVP_v0.1.5.uf2](../T12_Sequencer_MVP_v0.1.5.uf2).** Au démarrage l’écran affiche `T12 SEQUENCER / MVP 0.1.5 / C++ PICO SDK`, puis `STOP`.

Le binaire est compilé et les tests logiciels passent. Le fonctionnement de cette nouvelle application complète reste à confirmer sur le module. La calibration précise 1 V/oct reste celle à affiner à partir du diagnostic v24.

## Premier essai

1. Charger l’UF2 avec la méthode BOOTSEL déjà utilisée pour les diagnostics.
2. Cliquer sur l’encodeur, sélectionner `EDIT KEYS`, cliquer. Toucher un pad, tourner pour lui assigner une note. Les boutons −/+ changent son octave.
3. Maintenir l’encodeur pour ouvrir le menu. Sélectionner `RECORD NEW`, puis `ERASE AND RECORD`. Toucher les pads dans l’ordre voulu. Un clic termine l’enregistrement ; il s’arrête automatiquement à 32 pas.
4. Cliquer, choisir `PLAY`. Par défaut, l’horloge interne tourne à 120 BPM si aucune horloge externe n’est reçue. Brancher Pitch CV et Gate au synthétiseur.
5. Maintenir l’encodeur, choisir `EDIT STEPS` : tourner sélectionne le pas, toucher un pad remplace sa touche, cliquer ouvre ses paramètres.

La nouvelle séquence est vide au premier démarrage. Les touches sont initialement assignées de C3 à B3, gamme chromatique. Une séquence sauvegardée dans le slot 1 est rechargée au démarrage, toujours à l’arrêt.

## Commandes

| Écran | Encodeur | Clic | Octave − | Octave + |
|---|---|---|---|---|
| Performance (`PLAY`/`STOP`) | Sélection visuelle du pas | Menu | Transposition −1 octave | Transposition +1 octave |
| Edit Keys | Note de la touche sélectionnée | Menu | Note −1 octave | Note +1 octave |
| Record | — | Terminer | Ajouter un repos | Annuler le dernier pas |
| Edit Steps | Sélectionner un pas | Paramètres du pas | Basculer repos/note | Écouter le pas |
| Liste/menu | Sélection ; valeur si `=` | Entrer/valider | Retour | Identique au clic |
| Gamme personnalisée | Choisir une note du piano | Activer/désactiver | Annuler/retour | Sauvegarder la gamme |
| Nom de sauvegarde | Changer le caractère | Caractère suivant | Annuler | Sauvegarder |

Un **appui long de 800 ms** ouvre le menu principal. Pendant l’enregistrement, il termine la séquence. Dans l’éditeur de nom, il annule ; en calibration, il revient aux réglages. Les LED des deux boutons suivent leur appui.

En jeu, les pads permettent une écoute directe à l’arrêt. Pendant la lecture, une touche maintenue remplace la touche jouée aux changements de pas. La séquence continue d’avancer. Le moteur est monophonique ; si plusieurs nouvelles touches arrivent dans la même lecture MPR121, elles sont traitées par numéro croissant. Une touche doit être relâchée puis retouchée pour enregistrer une nouvelle occurrence.

La direction de l’encodeur est inversée par défaut par rapport au diagnostic, conformément au retour utilisateur. `SETTINGS > ENC REVERSE` permet de changer ce choix ; `SAVE SETTINGS` le conserve.

## Séquence et paramètres

Chaque pas mémorise **un numéro de touche**, pas une copie de la note. La longueur peut être réglée de 1 à 32 dans `EDIT STEPS > LENGTH`. Un projet vide est autorisé avant le premier enregistrement.

| Paramètre | Comportement |
|---|---|
| TIME = HALF | Durée d’une demi-horloge |
| TIME = REST | Repos d’une horloge, Gate bas |
| TIME = 1…8 | Durée de 1 à 8 horloges |
| RETRIGGER | Nouvelle impulsion à chaque horloge pendant un pas long |
| RATCHET | Divise la durée totale du pas en 1 à 8 gates réguliers. Dès que la valeur est supérieure à 1, il remplace le retrigger de ce pas. |
| GLIDE | Transition depuis la dernière hauteur vers celle du pas ; durée d’une demi-horloge, limitée à 10–500 ms |
| VIBRATO | Modulation de hauteur ; fréquence et profondeur dans Settings |
| STEP SHIFT | Transposition cumulative de −7 à +7 degrés de la scale, appliquée à chaque nouveau passage de ce pas. Reset remet tous les décalages à zéro. |

Le Gate occupe 50 % de la durée du pas, ou 50 % de chaque horloge en mode retrigger, comme dans le sketch. À chaque écriture matérielle, le firmware applique le PWM du CV avant le niveau Gate, dans la même itération, sans ajouter de délai musical. Le glide agit sur la hauteur et ne transforme pas le Gate en legato. Les courbes smoothstep, linéaire et exponentielle sont disponibles. Les repos durent effectivement une horloge ; les demi-pas successifs sont gérés individuellement.

`STEP SHIFT` reprend le principe d’accumulation par stage du Metropolix : un step peut se décaler progressivement dans la scale à chacune de ses répétitions. Le décalage courant est limité à ±24 degrés, puis Reset le remet à zéro. Les ratchets restent à hauteur fixe ; le décalage est appliqué au prochain passage du step.

## Gammes

15 gammes prédéfinies : chromatique, majeure, mineure naturelle, dorienne, phrygienne, lydienne, mixolydienne, locrienne, mineure harmonique, mineure mélodique, pentatoniques majeure/mineure, blues, par tons et diminuée. Quatre gammes utilisateur sont sauvegardables.

`SCALES` permet de choisir la gamme, la tonique et de remplir les 12 touches avec ses degrés successifs à partir de la première touche. `EDIT KEYS` permet ensuite d’assigner chaque note librement parmi les notes autorisées.

La **note assignée originale est conservée** lors d’un changement de gamme. La note jouée est la plus proche dans la gamme courante ; à distance égale, la note inférieure est choisie. Revenir à la gamme chromatique retrouve donc la note assignée originale. Modifier explicitement une touche ou utiliser `FILL 12 KEYS` remplace son assignation.

Pour éditer `USER 2`, par exemple, sélectionner d’abord `USER 2` dans la liste, puis `EDIT USER SCALE`. Si une gamme prédéfinie est sélectionnée, cet éditeur ouvre User 1. Les points indiquent les notes actives ; au moins une note doit rester active. `+ SAVE` sauvegarde les quatre masques de gammes dans les réglages et sélectionne la gamme éditée. Sauvegarder ensuite le projet pour conserver cette sélection au redémarrage.

## Horloge et Reset

- `AUTO` : l’horloge externe est prioritaire dès qu’un front arrive. Après une absence de fronts de `max(2 secondes, 3 périodes externes)`, retour à l’horloge interne si la lecture est lancée.
- `INTERNAL` : tempo réglable de 20 à 300 BPM ; l’entrée Clock ne pilote pas la lecture.
- `EXTERNAL` : attente d’impulsions ; pas de reprise automatique interne à la déconnexion.
- `DIVIDE` : 1, 2, 4, 8 ou 16 impulsions par horloge du moteur. Une impulsion par temps, division 1 par défaut.
- `TAP TEMPO` : cliquer plusieurs fois sur cette ligne pour fixer le tempo interne. Il ne remplace pas une horloge externe active en mode Auto.
- Reset réarme le premier pas et coupe le Gate. En externe, le premier pas joue au prochain front Clock ; en interne, au prochain passage du moteur.

Clock GP3 utilise son pull-up interne et le **front descendant** : l’entrée conditionnée est active basse, comme le trig Pamela. Reset GP6 reste une entrée active basse sur front descendant. Les événements sont capturés en interruption. Les demi-pas sont interpolés entre les fronts : leur précision dépend de la dernière période mesurée, particulièrement à la première impulsion et lors d’un changement brusque de tempo.

La page `CLOCK` affiche aussi `CLOCK IN` et `RESET IN` : le compteur augmente à chaque front reçu et l’état `HIGH`/`LOW` montre le niveau électrique actuel du RP2040. Sur cette révision, le front utile de Clock est montant ; Reset est inversé par le conditionnement et déclenche sur sa descente.

## CV, Gate et LED

- GP4 : Pitch CV, C0 = 0 V, 1 V/oct, plage 0–8 V.
- GP5 : Auxiliary CV ; `OFF` par défaut. Modes disponibles dans Settings : copie du pitch, vibrato unipolaire 0–5 V centré sur 2,5 V, position du pas 0–5 V.
- GP7 : Gate Out.
- GP26 : CV In est configuré en ADC et lu. Son affectation musicale reste à définir ; il n’agit pas sur le MVP.
- GP2 : LED RGB des pads ; sélection bleutée, touche jouée verte, touche appuyée blanche.

Les sorties utilisent le PWM 13 bits à **24,414 kHz**, avec horloge système 200 MHz. Le RP2040 est donc surcadencé par rapport à sa fréquence nominale. La conversion conserve la pente inversée et les coefficients empiriques du test. Les sorties logiques à 0 V utilisent le rapport cyclique calibré : un code PWM nul correspondrait ici à une tension élevée au jack.

`CV CALIBRATION` propose cinq consignes : 0, 2, 4, 6 et 8 V. Pour chaque sortie, sélectionner la consigne, mesurer le jack au multimètre puis saisir la valeur affichée par le multimètre. `SAVE 5 POINTS` sauvegarde les mesures et le firmware calcule par interpolation la commande PWM nécessaire entre les cinq points.

Les GPIO GP8/9 et ceux déclarés non connectés sont laissés intacts. Il n’y a pas de sortie Clock dédiée : le jack Gate reste utilisé pour les notes.

## Sauvegardes

Huit slots avec nom de 16 caractères : `SAVE WITH NAME`, `LOAD`, `CLEAR SLOT` et `QUICK SAVE`. Un slot contient la séquence, ses paramètres, les notes des touches, la transposition, la gamme et la tonique. Les réglages globaux contiennent le tempo, la source/division d’horloge, les paramètres de modulation, la luminosité, la direction d’encodeur, la calibration et les quatre gammes utilisateur. Chaque modification est sauvegardée automatiquement 1,5 seconde après le dernier geste, dès que la lecture est arrêtée. Cette temporisation regroupe les rotations d’encodeur afin de préserver la flash.

Sauvegarder une séquence sauvegarde aussi les réglages globaux. `SAVE SETTINGS` suffit pour les réglages seuls. Charger une séquence n’écrase pas ces réglages globaux. Les écritures explicites arrêtent brièvement la lecture et coupent physiquement le Gate avant l’effacement flash ; si elle était en cours, la lecture redémarre du premier pas après la sauvegarde.

Chaque enregistrement possède deux secteurs alternés, une génération et un CRC32 couvrant en-tête et contenu. La copie précédente reste disponible pendant l’écriture de la suivante. Les 72 derniers Kio des 2 premiers Mio de flash sont réservés et exclus du lien du programme. La sauvegarde est désactivée si l’identifiant JEDEC ne confirme pas au moins 2 Mio ou si le programme empiète sur la zone réservée. Le chargement valide aussi les plages de chaque paramètre.

## Organisation du code

| Fichier | Rôle |
|---|---|
| `src/model.*` | Données, gammes, quantification et validation |
| `src/engine.*` | Lecture, tempo, Gate, durée, retrigger, glide, vibrato |
| `src/hardware.*` | Brochage confirmé, MPR121, encodeur, ADC, PWM et événements jacks |
| `src/rgb.pio` | Signal LED GRB 800 kHz matériel |
| `src/graphics.cpp` | Dessin du framebuffer monochrome |
| `src/display.cpp` | SPI OLED sur cœur 1, correction des colonnes v12 |
| `src/ui.*` | Pages et commandes |
| `src/storage.*` | Sauvegardes flash avec deux copies et CRC |
| `src/main.cpp` | Boucle d’application sur cœur 0 |

Le rendu SPI est découplé du moteur. Les entrées Clock/Reset passent par une file de 64 événements ; une saturation arrête la lecture et affiche `CLOCK OVERFLOW`. L’I²C possède des délais maximum, et une erreur temporaire de lecture est retentée. Un MPR121 qui n’a pas pu être initialisé au démarrage est signalé à l’écran.

## Compilation et vérifications

Avec CMake, le Pico SDK et une chaîne Arm GCC complète (incluant newlib) :

```sh
PICO_SDK_PATH=/chemin/pico-sdk \
PICO_TOOLCHAIN_PATH=/chemin/arm-gnu-toolchain \
./sequencer/build.sh
```

Sur cette machine, le script retrouve le SDK `~/pico/pico-sdk` et la chaîne `~/.pico-sdk/toolchain/14_2_Rel1`. Il produit l’UF2 à la racine du dépôt et les fichiers ELF/BIN/MAP dans `build/sequencer-native/`. Aucun téléversement automatique n’est effectué.

```sh
./sequencer/test.sh
```

Les tests hôte utilisent AddressSanitizer et UndefinedBehaviorSanitizer : gammes et bornes, maintien des assignations, repos/bouclage, demi-pas, durée/retrigger, horloge externe accélérée, Reset, division, retour interne Auto, glide/vibrato, jeu à vide, tap tempo, enregistrement/édition, limite 32 pas, création de gamme et parcours de sauvegarde/chargement. Le stockage matériel est simulé dans les tests d’interface ; ils ne remplacent pas un essai d’écriture flash ou des mesures sur le module.
