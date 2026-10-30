# Journal des versions T12 KeySeq

## 0.1.31 — 2026-10-27

- Calibration CV multipoints pour Pitch et Aux : mesures à 0, 2, 4, 6 et 8 V, interpolation entre les mesures.
- La lecture est arrêtée dès l’entrée dans `EDIT KEYS` ou `EDIT STEPS`.
- Sur Performance, clic encodeur = Start/Stop ; maintien = menu.
- Format de réglages flash v3 : les anciens réglages sont réinitialisés une fois après installation.

## 0.1.48 — 2026-10-29

- Ajout de paramètres CAP SENSE persistants par pad : `capIdle[12]` et `capRange[12]`.
- Le delta `baseline - filtered` est maintenant normalisé par la plage propre à la touche avant conversion en CV Auxiliary 0–8 V.
- Valeurs par défaut : idle 0, plage 256 ; l’interface de capture idle/contact reste à ajouter.
- Version de stockage : 8.
- UF2 : `T12_Sequencer_MVP_v0.1.48.uf2`.

## 0.1.47 — 2026-10-29

- Correction de la lecture MPR121 : filtered data limité à 10 bits avec masque `0x03`.
- Lecture de la baseline par électrode et calcul de `baseline - filtered` pour CAP SENSE.
- Auxiliary CV et luminosité RGB utilisent maintenant le delta positif 10 bits.
- UF2 : `T12_Sequencer_MVP_v0.1.47.uf2`.

## 0.1.46 — 2026-10-28

- Le paramètre de step `GLIDE` devient un `SLIDE` de type TB-303 : le pitch change avec glide sans retrigger de gate lorsque la note précédente est encore active.
- Les pages Keys, Steps et Calibration forcent l’état `IDLE` : séquence arrêtée et horloge ignorée jusqu’à la sortie de la page.
- UF2 : `T12_Sequencer_MVP_v0.1.46.uf2`.

## 0.1.45 — 2026-10-28

- Renommage Performance : `LOOP LENGTH` et `LOOP OFFSET`.
- La longueur enregistrée reste intacte ; la boucle sélectionne maintenant une fenêtre dans la séquence complète.
- Exemple : 32 pas enregistrés, loop length 8 et loop offset 8 = lecture des pas 9 à 16.
- UF2 : `T12_Sequencer_MVP_v0.1.45.uf2`.

## 0.1.44 — 2026-10-28

- Les boutons `- / +` se répètent automatiquement lorsqu’ils restent maintenus en Performance.
- La longueur active peut parcourir la fenêtre des 32 pas enregistrés ; l’offset déplace cette fenêtre sans supprimer les pas hors boucle.
- L’horloge externe est ignorée pendant l’édition des Keys et des Steps.
- UF2 : `T12_Sequencer_MVP_v0.1.44.uf2`.

## 0.1.43 — 2026-10-28

- Ajout de paramètres Performance sélectionnables à l’encodeur pendant la lecture : direction de séquence, direction d’arpège, longueur de gate, division d’horloge, longueur et offset de séquence.
- Les boutons `- / +` modifient le paramètre sélectionné ; par défaut ils transposent la séquence par octave.
- Directions de séquence : forward, backward, random. Directions d’arpège : up, down, up/down.
- Les nouveaux réglages persistants utilisent la version de stockage 7.
- UF2 : `T12_Sequencer_MVP_v0.1.43.uf2`.

## 0.1.42 — 2026-10-27

- La luminosité de chaque pad RGB suit maintenant la capacitance filtrée mesurée par le MPR121 pendant l’appui.
- Une luminosité minimale est conservée pour que les touches restent visibles lors d’un contact léger.
- UF2 : `T12_Sequencer_MVP_v0.1.42.uf2`.

## 0.1.41 — 2026-10-27

- Ajout du réglage `GATE LENGTH` dans Settings, réglable de 10 % à 90 % de l’intervalle de clock.
- La durée de gate est calculée à chaque step selon ce pourcentage, avec une durée minimale de sécurité de 1 ms.
- Le réglage est sauvegardé avec les Settings ; la version de stockage passe à 5.
- UF2 : `T12_Sequencer_MVP_v0.1.41.uf2`.

## 0.1.30 — 2026-10-27

- Sorties Pitch CV et Auxiliary CV configurées en PWM 13 bits : porteuse 24,414 kHz à 200 MHz, avec 8192 niveaux sur 0–8 V.

## 0.1.5 — 2026-10-26

- La boucle principale ne calcule et n’écrit plus le CV/Gate deux fois par cycle.
- Les entrées sont lues et traitées avant l’unique mise à jour moteur et l’unique écriture matérielle.
- UF2 : `T12_Sequencer_MVP_v0.1.5.uf2`.

## 0.1.4 — 2026-10-26

- Polling MPR121 réduit de 5 ms à 1 ms pour rendre le déclenchement live pendant l’enregistrement plus immédiat.
- UF2 : `T12_Sequencer_MVP_v0.1.4.uf2`.

## 0.1.3 — 2026-10-26

- Correction du traitement Clock externe : un front ne peut plus traiter deux fois le demi-pas interpolé.
- Cette correction évite un double déclenchement lors de la lecture synchronisée par Clock In.
- UF2 : `T12_Sequencer_MVP_v0.1.3.uf2`.

## 0.1.2 — 2026-10-26

- Clock GP3 inversée sur front descendant, avec pull-up interne, pour correspondre au trig actif-bas du Pamela Workout.
- UF2 : `T12_Sequencer_MVP_v0.1.2.uf2`.

## 0.1.1 — 2026-10-26

- Suppression du délai artificiel entre la préparation du CV et le Gate.
- L’ordre matériel reste garanti dans `hardware::write()` : PWM Pitch/Aux, puis Gate dans la même mise à jour.
- Ratchet et Step Shift conservés.
- Sauvegarde automatique des réglages après 1,5 s d’inactivité lorsque la lecture est arrêtée.
- Tests hôte : 8 groupes moteur et 3 groupes interface passés.
- UF2 : `T12_Sequencer_MVP_v0.1.1.uf2`.

## 0.1.0 — historique

- Première version MVP native C++ Pico SDK.
- OLED SPI, MPR121, encodeur, boutons octave, LED RGB, séquenceur 32 pas, horloge, Reset, CV Pitch/Aux et Gate.
- UF2 conservé sous `T12_Sequencer_MVP_v0.1.0.uf2`.

## v0.1.49 — step gate model
- Added per-step gate types: SINGLE, MULTI, HOLD, REST and SKIP.
- Added per-step lengths X1–X4 and variant degree accumulation.
- Kept ratchet, slide and vibrato available in the step editor.
- Step editing remains transport-safe: entering the editor stops playback and ignores clock input.
- Storage schema bumped to version 9 for the new step fields.

## v0.1.50 — clear stopped key LED
- Stopping playback no longer leaves the last selected key illuminated.
- Selected-key highlighting remains available in Keys, Steps and Record editing pages.

## v0.1.51 — bounded variant and idle editing
- Added per-step VARIANT MIN and VARIANT MAX bounds, with wraparound at the next cycle.
- Step, key and CV calibration pages now remain in IDLE and ignore transport controls/clock input.

## v0.1.52 — backup restore compatibility
- Restore now accepts backups from the pre-variant step format and converts them to the current model.
- Restore validates the complete binary payload and reports size/CRC/validation errors before flash writes.

## v0.1.53 — variant-aware MULTI repeats
- MULTI repetitions now replay the pitch/gate event at each internal step boundary.
- When VARIANT is enabled, each MULTI repetition advances the variant degree and wraps between its configured minimum and maximum.

## v0.1.54 — extended step length
- Step length options are now X1 through X8.
- Validation, playback duration and the step editor all accept the extended range.

## v0.1.55 — touch LED priority
- Touch-pad illumination now suppresses the sequence playhead LED while any pad is held.
- This prevents a second blinking LED from appearing during live pad interaction.

## v0.1.56 — no playhead LED in key editing
- Key and step editing pages no longer display a stale preview as a second blinking LED.
- Playhead indication remains active on the performance and recording pages.

## v0.1.57 — SK6812 RGBW framing
- Changed the RGB PIO stream from 24-bit RGB to 32-bit SK6812 RGBW frames.
- The white channel is sent as zero; this prevents frame misalignment and ghost LEDs.

## v0.1.58 — RGB 24-bit frame reset
- Restored the confirmed 24-bit GRB protocol.
- The PIO FIFO/state is cleared before every complete LED frame to prevent residual or misaligned pixels.

## v0.1.59 — dark idle LEDs
- LEDs are now fully off when they are not selected, touched or playing.
- The playhead LED is no longer rendered after transport stops, eliminating the latched last-step light.

## v0.1.60 — validated RGB frame transfer
- Replaced the asynchronous RGB queue with the complete blocking 12-pixel transfer validated by `T12_RGB_Address_Test_v7`.
- Retained the confirmed 24-bit GRB 800 kHz protocol and physical row mapping.
- Each frame now keeps its color buffer immutable until all packets are queued, then waits for the latch interval; this removes partial frames, duplicate addresses and erratic blinking.
- UF2: `T12_Sequencer_MVP_v0.1.60.uf2`.

## v0.1.61 — clear playhead LED on stop
- A playback LED is now shown only while its gate is physically active.
- Transitioning from PLAY to STOP immediately transmits a fully dark RGB frame instead of waiting for the periodic LED refresh.
- UF2: `T12_Sequencer_MVP_v0.1.61.uf2`.

## v0.1.62 — full-step playhead LEDs
- Restored the playback LED for the complete duration of every played step; short gate lengths no longer make steps appear missing.
- Retained the immediate fully dark RGB frame when transport changes from PLAY to STOP.
- UF2: `T12_Sequencer_MVP_v0.1.62.uf2`.

## v0.1.63 — key note carousel
- Redesigned Key Edit around a large centered current note, flanked by the previous and next notes available in the active scale.
- The selected Key number remains visible in the top corner and the screen shows the long-click exit gesture.
- The Key currently being edited is identified by a dedicated orange LED.
- Long-click now exits Key Edit directly to the stopped Performance page.
- UF2: `T12_Sequencer_MVP_v0.1.63.uf2`.
