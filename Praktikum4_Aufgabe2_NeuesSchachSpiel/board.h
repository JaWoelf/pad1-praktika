#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

namespace brd{
using namespace std;

const string whiteBauer    = "b";
const string whiteTurm     = "t";
const string whiteSpringer = "s";
const string whiteLaeufer  = "l";
const string whiteDame     = "d";
const string whiteKoenig   = "k";
const string blackBauer    = "B";
const string blackTurm     = "T";
const string blackSpringer = "S";
const string blackLaeufer  = "L";
const string blackDame     = "D";
const string blackKoenig   = "K";
const string emptyField    = " ";


class ChessBoard
{
  public:
    ChessBoard()
    {

    }
    string getFigure();
    string getBoard();
  private:
    string boardArray[8][8];
};

}

#endif // BOARD_H
