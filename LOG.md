# Journal des versions T12 KeySeq

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
