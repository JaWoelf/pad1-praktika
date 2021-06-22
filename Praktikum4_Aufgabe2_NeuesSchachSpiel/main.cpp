#include <iostream>
#include <regex>
#include <string>
#include "board.h"

using namespace std;

const string WHITE_PAWN   = "p";
const string WHITE_ROOK   = "t";
const string WHITE_KNIGHT = "s";
const string WHITE_BISHOP = "l";
const string WHITE_QUEEN  = "d";
const string WHITE_KING   = "k";
const string BLACK_PAWN   = "B";
const string BLACK_ROOK   = "T";
const string BLACK_KNIGHT = "S";
const string BLACK_BISHOP = "L";
const string BLACK_QUEEN  = "D";
const string BLACK_KING   = "K";
const string EMPTY_FIELD  = " ";

/*      A B C D E F G H
 *
 *  1   r j b q k b j r    WHITE
 *  2   p p p p p p p p    +- x (A-B)
 *  3                      +  y (1-8)
 *  4
 *  5
 *  6                      BLACK
 *  7   P P P P P P P P    +- x (A-B)
 *  8   R J B Q K B J R     - y (1-8)
 */

string board[8][8] = {
  {WHITE_ROOK,WHITE_KNIGHT,WHITE_BISHOP,WHITE_QUEEN,WHITE_KING,WHITE_BISHOP,WHITE_KNIGHT,WHITE_ROOK},
  {WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN},
  {EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD},
  {EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD},
  {EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD},
  {EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD},
  {BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN},
  {BLACK_ROOK,BLACK_KNIGHT,BLACK_BISHOP,BLACK_KING,BLACK_QUEEN,BLACK_BISHOP,BLACK_KNIGHT,BLACK_ROOK},
};

array<int, 4> coords;
string errormessage;
string lolmessage;
const bool WHITE = true;
const bool BLACK = false;
bool turn = WHITE;
static regex inputpattern("[a-h][1-8]-[a-h][1-8]");
static regex whitepattern("[a-z]");
static regex blackpattern("[A-Z]");
// ###############################################################
// ###############################################################
//
//      DRAW

void drawUi()
{
  // Clear CLI and draw horizontal index
  cout << "\x1B[2J\x1B[H";
  cout << "\n   A B C D E F G H ";
  // draw board (with figures) line by line
  // beginning each line with vertical index
  for (int x = 0; x < 8; x++)
  {
    cout << "\n " << x+1 << " ";
    for (int y = 0; y < 8; y++)
    {
      cout << board[x][y] << " ";
    }
  }

  // User Input Area
  if(errormessage != "")
  {
    cout << "\n" << errormessage << "\n" << lolmessage;
    lolmessage = "";
    errormessage = "";
  }
  if (turn && true)
    cout << "\nWHITE's turn";
  else
    cout << "\n BLACK's turn";

  cout << "\n\n  Geben Sie den nächsten Zug ein.\nz.B. d7-a4 'exit' beendet das Spiel.\n";
}


// ###############################################################
// ###############################################################
//
//      INPUT
array<int, 4> userInput()
{

  string inputstring;
  cin >> inputstring;

  if (inputstring == "exit")
      return {1000,0,0,0}; // EXIT PROGRAMM

  else if (regex_match(inputstring, inputpattern))
  {
      return {
          inputstring[0] - 97,
          inputstring[1] - 49,
          inputstring[3] - 97,
          inputstring[4] - 49,
        };
  }
  return {1999,0,0,0}; // ERROR
};

// ###############################################################
// ###############################################################
//
//      MOVE PAWN
bool movePawnValidation(string target)
{
  int verticaldistance;
  int horizontaldistance;
  bool initialmove;

  if(turn == WHITE)
  {
      verticaldistance = coords[1] - coords[3];
      horizontaldistance = coords[0] - coords[2];
      initialmove = (coords[3] == 2) ? true : false;
  }
  else
  {
      verticaldistance = coords[3] - coords[1];
      horizontaldistance = coords[2] - coords[0];
      initialmove = (coords[3] == 7) ? true : false;
  }

  lolmessage = "vert: ";
  lolmessage+= verticaldistance;
  lolmessage+= ", hor: ";
  lolmessage+=  horizontaldistance;

  if ((verticaldistance == 1) and (horizontaldistance == 0))
    return true;
  if ((verticaldistance == 2) and (initialmove == true))
    return true;
  if (verticaldistance > 2)
    return false;
  if ((horizontaldistance == 1) and (target == EMPTY_FIELD))
    return false;
  if (horizontaldistance > 1)
    return false;
  else
    return false;

}
// ###############################################################
// ###############################################################
//
//      MOVE ROOK
bool moveRookValidation(string figure, string target)
{
  return false;
}
// ###############################################################
// #############################target == "9"##################################
//
//      MOVE KNIGHT
bool moveKnightValidation(string figure, string target)
{
  return false;
}
// ###############################################################
// ###############################################################
//
//      MOVE BISHOP
bool moveBishopValidation(string figure, string target)
{
  return false;
}
// ###############################################################
// ###############################################################
//
//      MOVE QUEEN
bool moveQueenValidation(string figure, string target)
{
  return false;
}
// ###############################################################
// ###############################################################
//
//      MOVE KING
bool moveKingValidation(string figure, string target)
{
  return false;
}

// ###############################################################
// ###############################################################
//
//      IS MOVE VALID
bool moveValidation()
{
  string figure = board[coords[1]][coords[0]];
  string target = board[coords[3]][coords[2]];
  bool figureiswhite = regex_match(figure,whitepattern);
  bool figureisblack = regex_match(figure,blackpattern);
  bool targetiswhite = regex_match(target,whitepattern);
  bool targetisblack = regex_match(target,blackpattern);

  lolmessage = "\nfigure: " + figure + "    target: " + target + "\nfigure: ";
  lolmessage+= figureiswhite ? "white" : "black";
  lolmessage+= "\ntarget: ";
  lolmessage+= targetiswhite ? "white" : "black";


  // Cannot move empty field:
  if(figure == EMPTY_FIELD)
      errormessage = "\nSelect figure damnit!";

  // Not this players turn!
  else if (((turn == WHITE) and figureisblack) or ((turn == BLACK) and figureiswhite))
  //else if (((turn == WHITE) and regex_match(figure,blackpattern)) or ((turn == BLACK) and regex_match(figure,whitepattern)))
      errormessage = "\nNot ya turn!";

  else if (((turn == WHITE) and targetiswhite) or ((turn == BLACK) and targetisblack))
  //else if (((turn == WHITE) and regex_match(target,whitepattern)) or ((turn == BLACK) and regex_match(target,blackpattern)))
      errormessage = "\nFriendly fire - don't you dare?";

  // Pawn moving
  else if (figure == WHITE_PAWN or figure == BLACK_PAWN)
      return movePawnValidation(target);

  // Rook moving
  else if (figure == WHITE_ROOK or figure == BLACK_ROOK)
      return moveRookValidation(figure, target);

  // Knight moving
  else if (figure == WHITE_KNIGHT or figure == BLACK_KNIGHT)
      return moveKnightValidation(figure, target);

  // Bishop moving
  else if (figure == WHITE_BISHOP or figure == BLACK_BISHOP)
      return moveBishopValidation(figure, target);

  // Queen moving
  else if (figure == WHITE_QUEEN or figure == BLACK_QUEEN)
      return moveQueenValidation(figure, target);

  // King moving
  else if (figure == WHITE_KING or figure == BLACK_KING)
      return moveKingValidation(figure, target);

  else
    errormessage = "\nunvorseen exception @moveValidation#else\n";

  if(errormessage != "")
      return false;

  return true;
};

// ###############################################################
// ###############################################################
//
//      MAIN
int main()
{
  // Play-Time
  while (true)
  {
    drawUi();
    coords = userInput();

    switch(coords[0])
    {
      case 1000 :
        return 0;
      case 1999 :
        errormessage = "Invalid Input was given.";
        continue;
    }

    // on invalid turn, restart turn (continue loop without changing gamespace)
    if(not moveValidation())
    {
      continue;
    }


    // move from old to new pos
    board[coords[3]][coords[2]] = board[coords[1]][coords[0]];
    board[coords[1]][coords[0]] = EMPTY_FIELD;

    // switch turn flag
    // which player's next?
    // white == true, black == false
    turn = !turn;
  } //while true

};


/*

1. Implementieren Sie eine Funktion istZugGueltig, die nach jeder Eingabe eines Zuges prüft, ob der Zug gültig ist.
Diese Funktion soll über ein switch-Statement oder
eine if-else-Kette entscheiden, welche Spielgur gesetzt wurde und für jede Spiel-
gur eine eigene Funktion (z.B. istBauernZugGueltig) aufrufen, mit der der Zug geprüft wird.

Beispiel 1: Der eingegebene Zug sei d2  d3 und auf d2 steht ein Bauer. Dann muss
mit der Funktion istBauernZugGueltig geprüft werden, ob
• d2  d3 ein erlaubter Zug für einen Bauern ist.
• auf d3 noch keine andere Spielgur steht.
Falls beide Bedingungen erfüllt sind, soll die Funktion true zurückgeben sonst false.
Beispiel 2: Der eingegebene Zug sei c1  f4 und auf c1 stehe ein Läufer. Dann
muss mit der Funktion istLaeuferZugGueltig geprüft werden, ob
• c1  f4 eine Diagonalbewegung ist (nur die ist für einen Läufer erlaubt).
• zwischen c1 und f4 andere Figuren im Weg stehen, die den Zug verhindern
würden.
• auf d3 noch keine andere eigene Spielgur steht.
Falls alle drei Bedingungen erfüllt sind, soll die Funktion true zurückgeben sonst
false.
Die aufrufende Funktion istZugGueltig gibt das Ergebnis (true oder false) dann
weiter an ihren Aufrufer.


2. Falls die Prüf-Funktion false zurückgibt, reagieren Sie mit einer Ausgabe, und fordern Sie den Spieler auf,
 den Zug zu korrigieren.


3. Implementieren Sie eine weitere Funktion schlaegtZugFigur, die prüft, ob der Zug
auf einem Feld endet, auf dem eine gegnerische Figur steht. In diesem Fall wird
diese Figur geschlagen (vom Spielfeld entfernt). Falls die Funktion true zurückgibt,
reagieren Sie ebenfalls mit einer passenden Ausgabe.


4. Implementieren Sie die Funktion schachDrohungAktiv, die prüft, ob nach einem Zug
der gegnerische oder eigene König im Schach steht, und reagieren Sie im Aufrufer
mit einer entsprechenden Meldung z.B. Weiÿer König auf d5 steht im Schach.


5. Verteilen Sie Ihr Programm sinnvoll auf mehrere Dateien.


*/
