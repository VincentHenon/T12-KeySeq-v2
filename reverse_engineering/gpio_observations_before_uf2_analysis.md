# T12 v20 — observations GPIO rapportées avant l’analyse du UF2

> **Mise à jour après les essais :** les incertitudes GP2 ci-dessous sont historiques. Le test LED v18 a confirmé GP2 comme sortie de données des LED RGB; le mode GRB 800 kHz donne les couleurs attendues. Le test MPR121 et les LED fonctionnent ensemble. Voir la carte GPIO mise à jour dans [gpio_map_v20.md](gpio_map_v20.md) et [LISTE_GPIO.md](../LISTE_GPIO.md).

Ce document sépare les éléments explicitement rapportés par Vincent des hypothèses qui n’avaient pas été vérifiées. Les attributions ci-dessous ne proviennent pas de l’analyse du firmware Doboz.

## Confirmations de Vincent

| Broche / alias | Observation rapportée | Portée de la confirmation |
|---|---|---|
| GP0, GP1 | Le test capacitif v09 affiche correctement l’état des pads via le MPR121. | Fonctionnel confirmé sur le module : GP0=SDA et GP1=SCL en I²C0, adresse MPR121 0x5A. |
| GP2 | Une troisième ligne a été observée entre le MPR121 et le RP2040. | Rôle encore incertain (probablement IRQ selon l’inspection). Le firmware Doboz analysé semble aussi configurer GP2 pour la chaîne RGB ; ne pas piloter en sortie avant résolution. |
| GP10 | Clic de l’encodeur. | Attribution donnée par Vincent ; les essais de diagnostic n’avaient pas détecté d’action. |
| GP11 | Encodeur ; change lors d’une rotation CCW. | Attribution et sens CCW confirmés par essai. |
| GP12 | Encodeur ; change lors d’une rotation CW. | Attribution et sens CW confirmés par essai. |
| GP21 | LED du bouton Octave +. | La LED s’allume lorsque le bouton Octave + est pressé. |
| GP22 | LED du bouton Octave −. | La LED s’allume lorsque le bouton Octave − est pressé. |
| A0 | Entrée CV. | Attribution confirmée par Vincent. Ne pas confondre automatiquement l’alias Arduino A0 avec un numéro GPIO sans vérifier le variant de carte. |
| A1 | Bouton Octave −. | Attribution confirmée par Vincent. |
| A2 | Bouton Octave +. | Attribution confirmée par Vincent. |
| GPIO 19/20/18/17 | Vincent avait relevé CLK=19, MOSI=20, CS=18 et DC=17 pour l’écran, avec incertitude sur CS/DC. | Relevé initial incertain. Le test OLED récupéré v05 fonctionne avec sa configuration propre ; il ne faut pas mélanger les deux relevés. |

## Hypothèses ou attributions non confirmées avant l’analyse

| Broche / fonction proposée | État avant l’analyse |
|---|---|
| GP3 = Clock In | Proposition initiale basée sur le circuit supposé de conditionnement ; essais non concluants et Vincent a ensuite indiqué qu’il pouvait s’être trompé. |
| GP6 = Reset In | Proposition testée sans détection concluante ; pas une confirmation matérielle. |
| GP2 = ligne des LED RGB | Hypothèse avant analyse; depuis confirmée par le test matériel v18 (GRB 800 kHz). |
| GP4/GP5 = sorties CV | Question/hypothèse de Vincent, non vérifiée avant l’analyse. |
| GP7 = Gate Out | Hypothèse d’analyse, non confirmée avant l’analyse. |
| ADC3 / GP29 | Aucun signal remarqué par Vincent. Cela ne prouve pas que la broche soit libre. |

## Test restauré

Le test `v05_recovered_gpio_input_test` est l’ancien scanner passif retrouvé dans l’artefact de compilation. Vincent confirme qu’il fonctionne à nouveau avec le matériel. Il affiche l’OLED et lit GP3, GP6, GP10, GP11, GP12 et GP26–GP29 sans configurer ces broches en sortie ni activer de résistances internes. Il ne teste pas les LED octave ou la chaîne RGB.

## Règle pour la suite

Les mesures directes et confirmations de Vincent restent distinctes des conclusions tirées du binaire. Les contradictions historiques, en particulier GP2, doivent être réévaluées à la lumière des tests matériels plus récents avant d’écrire un nouveau test.
