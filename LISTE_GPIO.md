# Doboz T12 DIY v20 — GPIO confirmés

Ce tableau ne contient que les GPIO dont la fonction a été validée par le firmware de test et par Vincent sur son module. Les fonctions jack encore incertaines sont séparées plus bas.

| GPIO RP2040 | Fonction | Protocole / sens | Confirmation |
|---|---|---|---|
| GP0 | MPR121 SDA | I²C0, bidirectionnel | Test capacitif fonctionnel; les 12 pads sont lus. |
| GP1 | MPR121 SCL | I²C0, horloge | Test capacitif fonctionnel. |
| GP2 | Données des 12 LED RGB adressables | Sortie série à un fil, GRB, 800 kHz | Mode 1 du test LED donne les couleurs rouge, vert, bleu et blanc attendues; GP2 confirmé. |
| GP3 | Clock In | Entrée numérique après conditionnement, pull-up interne, logique active-bas | Affectation et fonctionnement confirmés par Vincent. |
| GP6 | Reset In | Entrée numérique après conditionnement, pull-up interne, logique active-bas | Affectation et fonctionnement confirmés par Vincent. |
| GP7 | Gate Out | Sortie numérique | Sortie Gate confirmée par Vincent. |
| GP10 | Clic de l’encodeur | Entrée numérique, active à l’état bas | Clic et affichage testés. |
| GP11 | Encodeur, phase A | Entrée numérique; change en rotation antihoraire (CCW) | Rotation testée. |
| GP12 | Encodeur, phase B | Entrée numérique; change en rotation horaire (CW) | Rotation testée. |
| GP16 | OLED D/C | Sortie numérique | OLED fonctionnel. |
| GP17 | OLED CS | SPI0 CSn | OLED fonctionnel. |
| GP18 | OLED CLK | SPI0 SCK | OLED fonctionnel. |
| GP19 | OLED MOSI | SPI0 TX | OLED fonctionnel. |
| GP20 | OLED RESET | Sortie numérique | OLED fonctionnel. |
| GP21 | LED du bouton Octave + | Sortie numérique | LED testée et commandée par le bouton. |
| GP22 | LED du bouton Octave − | Sortie numérique | LED testée et commandée par le bouton. |
| GP26 / A0 / ADC0 | CV In | Entrée analogique | Entrée CV confirmée par Vincent. |
| GP27 / A1 / ADC1 | Bouton Octave − | Entrée numérique | Bouton testé. |
| GP28 / A2 / ADC2 | Bouton Octave + | Entrée numérique | Bouton testé. |

Le MPR121 gère les 12 touches capacitives via I²C : les pads ne correspondent donc pas à 12 GPIO distincts du RP2040. Le firmware de test conserve aussi l’OLED, l’encodeur, les boutons octave et leurs LED actifs en même temps.

## Comportement des jacks restant à vérifier

| GPIO candidat | Fonction d’après l’UF2 v20 | État de validation |
|---|---|---|
| GP4 | CV Notes Out (PWM2 A) | Test v23 : moyenne DC suit les paliers 0–7 V à ±50 mV. Ondulation PWM importante à caractériser. |
| GP5 | Auxiliary CV Out (PWM2 B) | Test v22 : pente inverse mesurée; test v23 avec calibration compensée à vérifier au multimètre. |

Vincent confirme que GP3 = Clock In et GP6 = Reset In fonctionnent en pull-up interne et en logique active-bas. Sur l’écran de diagnostic, `UP-LOW` signifie « pull-up activé » et « niveau bas interprété comme actif »; `LOW` ne décrit pas le niveau instantané du jack. Le niveau instantané est affiché séparément (`H` ou `L`) et les compteurs `+` / `−` indiquent les fronts montants / descendants. GP4 et GP5 sont des sorties PWM selon l’UF2; leur signal aux jacks reste à vérifier à l’oscilloscope.

## GPIO encore à identifier

| GPIO | État |
|---|---|
| GP8, GP9 | Vincent confirme qu’ils sont reliés à quelque chose; rôle inconnu. |
| GP13–GP15 | Vincent indique qu’ils ne sont pas reliés sur son module. Non-connexion non démontrée par les photos seules ; laissés intacts dans le séquenceur. |
| GP23–GP25, GP29 | Vincent indique qu’ils ne sont pas reliés sur son module; exclus des tests. |

La page 9 du test v21 balaie GP3–GP6, GP8, GP9 et GP13–GP15. GP4 et GP5 passent temporairement en entrée haute impédance; le PWM CV est rétabli en quittant cette page. Le balayage de GP3/GP6 n’est plus nécessaire : leurs rôles et leur fonctionnement sont confirmés.

Le gros plan IMG_7890 montre le marquage RP2-B2 et le repère du boîtier RP2040 QFN-56. En prenant le repère comme pin 1, GP8/GP9 sont les broches de boîtier 11/12 (rangée gauche); GP13/GP14/GP15 sont les broches 16/17/18 (rangée du bas, près du coin gauche). La photo montre des pistes qui s’échappent de plusieurs broches, mais ne permet pas de suivre chaque net jusqu’à sa destination ni de prouver un non-raccordement : vias, couches internes, pistes sous le boîtier et composants hors cadre restent invisibles. L’état connecté/non connecté ci-dessus repose donc sur les observations et tests de Vincent, pas seulement sur ce cliché.

## Mesures des sorties CV au scope

Mesures au multimètre communiquées par Vincent :

| Sortie | Consigne affichée | Tension DC mesurée |
|---|---:|---:|
| Auxiliary CV | 0 V (PWM 0) | 7,78 V |
| Auxiliary CV | 2 V (PWM 1024) | 5,644 V |
| Auxiliary CV | 3 V (PWM 1536) | 4,581 V |
| CV Pitch | 0 V (PWM 0) | 7,82 V |
| CV Pitch | 3 V (PWM 1536) | 4,60 V |
| CV Pitch | 4 V (PWM 2048) | 3,536 V |

Les deux sorties ont une pente mesurée proche de −1,07 V par volt de consigne, avec un décalage voisin de +7,8 V. Elles répondent donc au PWM mais la tension moyenne observée est inversée par rapport à la valeur affichée; cette dernière n’est pas une mesure ni une calibration du jack. Au scope, Vincent a aussi observé une sinusoïde d’environ 3,053 kHz, de 5,547 Vpp sur Pitch à 3 V et de 4,297 Vpp sur Auxiliary à 2 V (couplage DC, sonde et scope réglés en ×10). Le ripple important reste à expliquer séparément de la pente DC inversée.


## Test de balayage CV v23

Le firmware v23 remplace le balayage chromatique par 8 consignes de 0 à 7 V, par pas de 1 V (une octave), sur CV Pitch GP4 et Auxiliary CV GP5. Il applique une correspondance PWM inversée calculée à partir des mesures multimètre ci-dessus : GP4 utilise environ 7,787 V d’intercept et 1,058 V/V de pente; GP5 environ 7,780 V et 1,066 V/V. Cette correction est empirique et sert au test; elle n’est pas une calibration finale.

### Mesures v23 — CV Pitch GP4

| Consigne | Multimètre DC | Erreur | Ondulation scope Vpp |
|---:|---:|---:|---:|
| 0 V | 0,024 V | +0,024 V | 1,563 Vpp |
| 1 V | 1,035 V | +0,035 V | 3,516 Vpp |
| 2 V | 2,050 V | +0,050 V | 5,078 Vpp |
| 3 V | 3,002 V | +0,002 V | 6,250 Vpp |
| 4 V | 4,013 V | +0,013 V | 6,250 Vpp |
| 5 V | 5,025 V | +0,025 V | 5,078 Vpp |
| 6 V | 6,025 V | +0,025 V | 3,906 Vpp |
| 7 V | 7,020 V | +0,020 V | 1,953 Vpp |

La fréquence mesurée au scope est de 3,051 kHz à tous les paliers. La moyenne DC est très proche de la consigne (erreur absolue maximale 50 mV). L’ondulation est maximale au milieu de la plage et plus faible près des extrêmes, ce qui correspond au comportement attendu d’une porteuse PWM dont l’ondulation dépend du rapport cyclique. Le test configure actuellement `TOP=4095` et diviseur PWM 16; la porteuse mesurée est donc visible à la sortie analogique. La précision DC est confirmée, mais cette ondulation reste élevée pour un CV de pitch stable.

Le v24 conserve la conversion inversée/calibrée et le `TOP=4095`, mais passe le diviseur PWM de 16 à 1. D’après la fréquence précédemment mesurée, la porteuse attendue est environ 48,8 kHz; la résolution de commande reste 12 bits. Comparer le Vpp v24 et v23 à niveaux identiques, surtout à 3–4 V. Si l’ondulation ne baisse pas nettement, le filtrage analogique de cette voie est insuffisant pour le CV et il faudra envisager un filtre passe-bas analogique ou utiliser un DAC matériel.

Vincent a testé le v24 avec un VCO et ne perçoit pas d’artefact audible. Le suivi 1 V/oct du VCO reste à calibrer; les mesures de fréquence/octave ne sont pas encore consignées. Pour distinguer le suivi du VCO de l’erreur de sortie, garder le réglage du VCO fixe et mesurer la fréquence à plusieurs niveaux CV successifs.


Vincent rapporte que le suivi 1 V/oct du VCO semble dévier vers 4–5 V; 6–7 V restent à mesurer. C’est une vérification de calibration de la sortie CV et du VCO, pas une incertitude sur le GPIO GP4. Le v24 ne produit pas d’artefact audible selon Vincent.

## Implémentation C++ native — MVP 0.1.0

Le brochage ci-dessus est repris dans [sequencer/src/hardware.hpp](sequencer/src/hardware.hpp). Les fonctions validées du diagnostic sont portées vers le Pico SDK sans Arduino. GP4/GP5 conservent le PWM inversé 12 bits à environ 48,8 kHz et les coefficients empiriques du v24. L’alignement OLED reprend exactement la méthode v12 : colonne RAM 2, colonnes framebuffer 126–127 envoyées en premier. GP8/GP9, GP13–GP15, GP23–GP25 et GP29 ne sont pas configurés par cette application. La validation de ce nouveau firmware sur le module reste à effectuer ; elle est distincte de la confirmation matérielle du brochage.
