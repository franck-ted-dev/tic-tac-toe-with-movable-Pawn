#include "Player.hpp"

#include <algorithm>
#include <iostream>

// initialization
Player::Player(char symbol) : spielFigur_{symbol} {
  // Ein Player wird erstellt
}

// gibt die SpielFigur des Spielers zurück
char Player::symbol() const { return spielFigur_; }

// Ausgabe der Felder, wo sich bewegliche PlayerFiguren befinden,
void Player::displayPawnPosition() const {
  for (int x : pawnPosition_) {
    if (x == *pawnPosition_.end()) return;
    std::cout << ", ";
  }
}

// gibt true zurück, wenn es eine PlayerFigur auf diesem Feld gibt.
bool Player::hasPawn(int i) const {
  return std::find(pawnPosition_.begin(), pawnPosition_.end(), i) !=
         pawnPosition_.end();
}
