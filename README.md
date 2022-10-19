# Microcomputer
Project für the 3rd term

# Reaktionsspiel

Fernbedienung

7 Segment Anzeige

## Spielidee:

Auf 7 Segmentanzeige wird Zahl angezeigt, 2 Spieler spielen gegeneinander.

Reaktionszeit wird gemessen, wer schneller ist bekommt Punkt -->angezeigt per 7Segmentanzeigen.
Spieler 1 spielt 1 Runde, Zeit wird gemessen. Danach spielt Spieler 2 eine runde. Die schnellere Runde gewinnt.

Randmoized Zahl angegeben


# Tic Tac Toe (Nico)

## Spielidee
klassisches Tic Tac Toe 
Spielfeld jeweils 4 LEDs pro Feld
1 Spieler : Feld ausgefüllt
2. Spieler: Querstrich

Spiel mit Fernbedienung --> pro Feld 1 Ziffer

Bei Gewinn leuchtet ganze Matrix in LEDs des jeweiligen Spielers --> Strich/ ausgefüllt

## Aufgaben 

### Ansteuerung der Matrix (Uli)


- [ ] Ansteuerung der passenden LEDs
- [ ] Schieberegister zur Ansteuerung ??

- [ ] Abwechseln der Spielanzeige Ausgefüllt & Querstrich

- [ ] Fehlermeldung, wenn bereits angesteuertes Feld nochmal angesteuert werden soll

- [ ] Gewinn Bedingung checken, wenn 3 in einer Reihe gleich sind --> ganze Matrix in Gewinner Form
- [ ] Array um Gewinn zu checken und überschreiben zu verhindern 

### Fernbedienung (Clemens)

- [ ] Einarbeitung, wie Signale empfangen & ausgewertet werden
- [ ] Auswertung der Fernbedienungssignale, welche LEDs angesteuert werden sollen

### 7-Segment Anzeige (Daniel)
- [ ] Ausgabe der Zahlen
