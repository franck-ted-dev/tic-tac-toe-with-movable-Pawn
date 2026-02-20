# Tic-Tac-Toe mit beweglichen Figuren

Ein klassisches Tic-Tac-Toe-Spiel, erweitert mit **beweglichen Spielfiguren**, entwickelt in C++. Dieses Projekt ermöglicht es zwei menschlichen Spielern, direkt im Terminal zu spielen, mit einem interaktiven Spielfeld und automatischer Siegüberprüfung.

## Funktionen

- **Zwei-Spieler-Modus**  
- **Bewegliche Figuren** nach der Anfangsphase  
- Automatische Überprüfung der Gewinnkombinationen  
- Klare Darstellung des Spielfelds im Terminal  
- Zukünftige Erweiterungen: **Mensch vs CPU**, Schwierigkeitsstufen und grafische Benutzeroberfläche

## Installation

### Voraussetzungen

- Ein moderner C++ Compiler (z. B. `g++`)  
- Terminal

### Kompilieren

Vom Projektstammverzeichnis aus:
```bash
g++ -I include main.cpp src/Board.cpp src/Game.cpp src/Player.cpp -o tictactoe
```

### Ausführen

```bash
./tictactoe
```


## Ablauf einer Partie

- Platzierungsphase: Die beiden Spieler setzen abwechselnd ihre Spielfiguren (drei pro Spieler) auf dem Brett.
  Falls es nach dieser Phase keinen Sieger gibt ( das ist so gut wie immer der Fall ), dann müssen die Spieler
  Schlacht liefern, um zu gewinnen.

- Bewegungsphase: Nachdem alle Figuren platziert sind, können die Spieler ihre Figuren gemäß den erlaubten Bewegungen verschieben.

- Das Spiel zeigt das Spielfeld automatisch an und fordert die Eingabe der Spieler ab.

- Das Spiel endet, wenn ein Spieler drei Figuren in einer Reihe hat (Sieg). 


## Spielregeln

- Spielfiguren dürfen nur auf unbesetzte Brettfelder platziert werden
- Bei der Bewegungsphase sind erlaubte Bewegungen folgende:
  * Ein Spieler bewegt seine Spielfigur von einem Feld aus nach einem freien benachbarten
  * Für das zentrale Feld (genau in der Mitte) können in einem Zug alle anderen Felder erreicht werden,
    natürlich vorausgessetzt, dass diese frei sind.
  * Für die anderen Felder sind "diagonalen" Bewegungen nicht erlaubt, es sei dann das Zielfeld die Mitte ist.

## Darstellung des Bretts und erlaubte Bewegungen...

1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>
4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>
7&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;8&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;9<br>

### erlaubte Bewegungen

| Vom Feld x aus | erreichbare Felder |
|----------------|--------------------|
|      1         |   2  &nbsp;  4  &nbsp;  5      |
|  2   |1&nbsp;&nbsp;3&nbsp;&nbsp;5 |
| 3   |2&nbsp;&nbsp;5&nbsp;&nbsp;6|
| 4   |1&nbsp;&nbsp;5&nbsp;&nbsp;7|
| 5   |1&nbsp;&nbsp;2&nbsp;&nbsp;3&nbsp;&nbsp;4&nbsp;&nbsp;6&nbsp;&nbsp;7&nbsp;&nbsp;8&nbsp;&nbsp;9&nbsp;|
|  6   |3&nbsp;&nbsp;5&nbsp;&nbsp;9|
|  7   |4&nbsp;&nbsp;5&nbsp;&nbsp;8|
|  8   |5&nbsp;&nbsp;7&nbsp;&nbsp;9|
|  9   |5&nbsp;&nbsp;6&nbsp;&nbsp;8|
