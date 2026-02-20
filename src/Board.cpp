#include "Board.hpp"

#include <iostream>

// initialization
BoardCase::BoardCase(bool occupied, int number, char symbol)
    : number_case_{number}, symbol_case_{symbol}, occupied_{occupied} {}

// initialization
Board::Board() {}

// fülle das Brett initial auf
// erlaube mögliche Bewegungen
// setze die SiegKombinationen fest
void Board::initialize() {
  // leeres Brett
  for (int i = 0; i < 9; ++i) {
    board_[i].number_case_ = i + 1;
    board_[i].symbol_case_ = '0' + board_[i].number_case_;
  }

  // mögliche Züge
  accessible_from_[0] = {1, 3, 4};
  accessible_from_[1] = {0, 2, 4};
  accessible_from_[2] = {1, 4, 5};
  accessible_from_[3] = {0, 4, 6};
  accessible_from_[4] = {0, 1, 2, 3, 5, 6, 7, 8};
  accessible_from_[5] = {2, 4, 8};
  accessible_from_[6] = {3, 4, 7};
  accessible_from_[7] = {6, 4, 8};
  accessible_from_[8] = {4, 5, 7};

  // SiegKombinationen : 3 Linien, 3 Kolonnen, 2 Diagonalen
  configWinner_[0] = {0, 1, 2};
  configWinner_[1] = {3, 4, 5};
  configWinner_[2] = {6, 7, 8};
  configWinner_[3] = {0, 3, 6};
  configWinner_[4] = {1, 4, 7};
  configWinner_[5] = {2, 5, 8};
  configWinner_[6] = {0, 4, 8};
  configWinner_[7] = {2, 4, 6};
}

// Ausgabe des Brettzustands
void Board::display() const {
  for (int i = 0; i < 9; ++i) {
    std::cout << board_[i].symbol_case_ << "  ";
    if ((i + 1) % 3 == 0) std::cout << std::endl << std::endl;
  }
}

// Ausgabe der freien Felder bei der Platzierungsphase
void Board::displayFreeCases() const {
  for (int i = 0; i < 9; ++i) {
    if (board_[i].occupied_) continue;
    std::cout << board_[i].number_case_ << " ";
  }
}

// gibt true zurück, wenn i € [0,8]
bool Board::isValid(int i) const {
  if (i < 0) return false;
  if (i < 9) return true;
  return false;
}
// gibt true zurück, wenn dieses Feld besetzt ist
bool Board::isOccupied(int i) const { return board_[i].occupied_; }

// gibt das Symbol auf diesem Feld zurück
char Board::getSymbol(int i) const { return board_[i].symbol_case_; }

// setzt eine SpielFigur auf einem Brettfeld
void Board::placePawn(int i, char symbol) {
  board_[i].occupied_ = true;
  board_[i].symbol_case_ = symbol;
}

// entferne eine Figur aus einem Brettfeld
void Board::removePawn(int i) {
  board_[i].occupied_ = false;
  board_[i].symbol_case_ = board_[i].number_case_ + '0';
}

// Ausgabe der Spielfiguren eines Spielers,
// die bewegt werden können
void Board::displayMovablePawn(char spielFigur) const {
  for (int i = 0; i < 9; ++i) {  // für jedes Brettfeld
    if (getSymbol(i) ==
        spielFigur) {  // spielFigur befindet sich auf dem Feld i
      // Was sind alle mögliche erreichbare Felder ?
      // ist mindestens eines davon frei
      // dann können wir die spielFigur auf dem Feld i dorthin bewegen
      for (int x : accessible_from_.at(i)) {
        // Was sind die erreichbaren Felder von i aus ?
        // Ist mindestens eins davon frei ?
        // dann kann die SpielFigur bewegt werden
        if (!isOccupied(x)) {
          std::cout << board_[i].number_case_ << " ";
          break;
        }
      }
    }
  }
}

// überprüft ob auf dem Feld i, sich spielFigur befindet
// und diese sich bewegen kann
bool Board::caseHasMovablePawn(int i, char spielFigur) const {
  if (!isValid(i)) return false;  // index out of range!!!
  if (getSymbol(i) != spielFigur)
    return false;  // keine entsprechende SpielFigur auf dem Feld
  for (int x : accessible_from_.at(i)) {  // mindestens ein erreichbares Feld
    if (!isOccupied(x)) return true;      // ist frei, dann OK
  }
  return false;  // sonst, alle erreichbare Felder sind besetzt
}

// gibt true zurück, wenn from -> to ein möglicher Zug ist.
// das heißt, von "from" aus ist das Feld "to" erreichbar,
// und dieses ist unbesetzt
bool Board::isAccessible(int from, int to) {
  // ist das Feld "to" besetzt, dann gibt false zurück
  if (board_[to].occupied_) return false;
  // "to" gehört nicht zur Liste der erreichbaren Felder, gibt false zurück
  if (std::find(accessible_from_[from].begin(), accessible_from_[from].end(),
                to) == accessible_from_[from].end())
    return false;
  return true;  // sonst true
}

// Gibt es einen Gewinner ?
bool Board::victoryDetected() const {
  for (int i = 0; i < 8; ++i) {
    char a = board_[configWinner_.at(i)[0]].symbol_case_;
    char b = board_[configWinner_.at(i)[1]].symbol_case_;
    char c = board_[configWinner_.at(i)[2]].symbol_case_;
    if (a == b && b == c) return a;
  }
  return 0;
}
