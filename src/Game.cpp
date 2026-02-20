#include "Game.hpp"

#include <iostream>

Game::Game() : player1_('X'), player2_('H') {
  // Game wird initialisiert
}

// "zentrale" Memberfunction von Game,
// die die Partie startet und verwaltet
// Eine Partie beginnt mit der Initialisierung
// dann kommt die Platzierungsphase
// dann wechseln sich die Spieler ab,
// bis es einen Gewinner gibt
void Game::run() {
  initialize();
  display();
  firstPhase();
  std::cout << std::endl;
  display();
  while (!game_over_) {
    playTurn();
    display();
    if (checkWin() != 0) {
      endGame();
      std::cout << "END OF GAME\n";
      return;
    }
    switchPlayer();
  }
}

// Ausgabe des Bretts
void Game::display() { brett_.display(); }

// Initialisierung der Partie
void Game::initialize() {
  brett_.initialize();  // Das Brett ist bereit
  // Die Spieler sind bereit
  game_over_ = false;           // Anfang der Partie
  current_player_ = &player1_;  // Player1 startet das Spiel
}

// setzt fest, wer ist dran
void Game::switchPlayer() {
  if (current_player_ == &player1_)
    current_player_ = &player2_;
  else {
    current_player_ = &player1_;
  }
}

// setzt fest, wie ein Zug gespielt wird
void Game::playTurn() {
  int platz;     // welche Spielfigur wird bewegt
  int zielFeld;  // nach wohin ?
  std::string namePlayer =
      (current_player_ == &player1_) ? "Player 1" : "Player 2";
  std::cout << namePlayer << " ist dran!\n";
  std::cout << "Was ist Ihr naechster Zug ?\n";
  while (true) {
    std::cout << "Bitte ein Feld waehlen. (";
    brett_.displayMovablePawn(
        current_player_->symbol());  // Spielfiguren, die beweglich sind
    std::cout << ") : ";
    std::cin >> platz;
    if (!brett_.caseHasMovablePawn(platz - 1, current_player_->symbol())) {
      std::cout << "Es befindet sich keine bewegliche Spielfigur auf diesem "
                   "Feld !!!\n";
    } else {
      std::cout << "Geben Sie das ZielFeld: ";
      std::cin >> zielFeld;
      if (!brett_.isAccessible(platz - 1, zielFeld - 1)) {
        std::cout << "Ungueltige Bewegung!!!\n";
      } else
        break;
    }
  }
  // führe die Bewegund durch
  removePawn(platz);
  putPawn(zielFeld, current_player_->symbol());
}

// setze SpielFigur auf dem Zielfeld
void Game::putPawn(int zielFeld, char Spielfigur) {
  int feld = zielFeld - 1;
  brett_.placePawn(feld, Spielfigur);
}

// entferne SpielFigur aus dem Feld
void Game::removePawn(int platz) {
  int feld = platz - 1;
  brett_.removePawn(feld);
}

// Gibt es einen Gewinner ?
bool Game::checkWin() const { return brett_.victoryDetected(); }

// Ende der Partie
void Game::endGame() {
  std::string namePlayer =
      (current_player_ == &player1_) ? "Player 1" : "Player 2";
  std::cout << namePlayer << " gewinnt !!!\n";
  game_over_ = true;
}

// Platzierungsphase
// Jeder Spieler platziert seine drei Spielfiguren auf dem Brett
// Gibt es nach dieser Phase schon einen Gewinner ?, dann Ende der Partie
// Sonst geht es weiter
void Game::firstPhase() {
  int turn = 0;
  while (turn < 6) {
    int platz;
    bool validation = false;
    while (!validation) {
      std::string namePlayer =
          (current_player_ == &player1_) ? "Player 1" : "Player 2";
      std::cout << namePlayer << ", Figur platzieren. Vorschläge: ";
      brett_.displayFreeCases();  // zeige noch nicht besetzte Felder
      std::cout << " : ";
      std::cin >> platz;
      if (!brett_.isValid(platz - 1) || brett_.isOccupied(platz - 1)) {
        std::cout << "illegale Platzierung!!!\n";
      } else {
        validation = true;
      }
    }
    putPawn(platz, current_player_->symbol());  // platziert die Spielfigur
    display();
    ++turn;
    if (turn >= 5) {  // Ab der 3.Platzierung, überprüfe den Sieg
      if (checkWin() != 0) {
        endGame();
        std::cout << "END OF GAME\n";
        return;
      }
    }
    switchPlayer();
  }
}
