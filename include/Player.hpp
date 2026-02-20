#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>

#include "Board.hpp"

// Die Klasse modelliert einen Spieler

class Player {
 private:
  char spielFigur_;  // die SpielFigur eines Spielers
  std::list<int>
      pawnPosition_;  // speichert alle Spielfigurpositionen eines Spielers

 public:
  Player(char symbol);

  // gibt die SpielFigur des Spielers zurück
  char symbol() const;

  // Ausgabe der Felder wo sich bewegliche PlayerFiguren befinden,
  void displayPawnPosition() const;

  // gibt true zurück, wenn es eine PlayerFigur auf diesem Feld gibt.
  bool hasPawn(int i) const;
};

#endif