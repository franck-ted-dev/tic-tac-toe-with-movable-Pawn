#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "Board.hpp"
#include "Player.hpp"

class Game {
 private:
  // Wie wird eine Partie verwaltet ?
  Board brett_;     // Wir brauchen ein Brett
  Player player1_;  // zwei Spieler
  Player player2_;
  Player* current_player_;  // wer ist dran ?
  bool game_over_;          // ist die Partie am Ende ?

 public:
  Game();

  // "zentrale" Memberfunction von Game,
  // die die Partie startet und verwaltet
  void run();

 private:
  // Ausgabe des Bretts
  void display();

  // Alle Elemente der Partie werden bereitgestellt
  void initialize();

  // setzt fest, wer ist dran
  void switchPlayer();

  // setzt fest, wie ein Zug gespielt wird
  void playTurn();

  // setze SpielFigur auf dem Zielfeld
  void putPawn(int zielFeld, char Spielfigur);

  // entferne SpielFigur aus dem Feld
  void removePawn(int platz);

  // Gibt es einen Gewinner ?
  bool checkWin() const;

  // Die Partie ist am Ende
  void endGame();

  // Die Platzierungsphase
  // Die Spieler platzieren ihre Spielfiguren auf dem Brett
  void firstPhase();
};

#endif  // GAME_HPP