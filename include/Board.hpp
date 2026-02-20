#ifndef BOARD_HPP
#define BOARD_HPP

#include <algorithm>
#include <array>
#include <list>
#include <map>
#include <vector>

// modelliere ein Brettfeld
struct BoardCase {
  int number_case_;
  char symbol_case_;
  bool occupied_;

  BoardCase(bool occupied = false, int number = 0, char symbol = 0);
};

// die Klasse Brett
class Board {
 private:
  std::array<BoardCase, 9> board_;  // das Brett besteht aus 9 Feldern
  std::map<int, std::list<int>> accessible_from_;  // zulässige Bewegungen
  std::map<int, std::vector<int>> configWinner_;   // SiegKombinationen

 public:
  // initialization
  Board();

  // fülle das Brett initial auf
  // und erlaube mögliche Bewegungen
  void initialize();

  // Ausgabe des Brettzustands
  void display() const;

  // Ausgabe der freien Felder bei der Platzierungsphase
  void displayFreeCases() const;

  // Ausgabe der Spielfiguren eines Spielers
  // die bewegt werden können
  void displayMovablePawn(char spielFigur) const;

  // gibt true zurück, wenn dieses Feld besetzt ist
  bool isOccupied(int i) const;

  // gibt true zurück, wenn i € [0,8]
  bool isValid(int i) const;

  // gibt das Symbol auf diesem Feld zurück
  char getSymbol(int i) const;

  // setzt eine SpielFigur auf einem Brettfeld
  void placePawn(int i, char symbol);

  // entferne eine SpielFigur aus einem Brettfeld
  void removePawn(int i);

  // gibt true zurück, wenn from -> to ein möglicher Zug ist.
  // das heißt, von "from" aus ist das Feld "to" erreichbar,
  // und dieses ist unbesetzt
  bool isAccessible(int from, int to);

  // überprüft ob auf dem Feld i, sich spielFigur befindet
  // und diese sich bewegen kann
  bool caseHasMovablePawn(int i, char spielFigur) const;

  // Gibt es einen Gewinner ?
  bool victoryDetected() const;
};

#endif  // BOARD_HPP