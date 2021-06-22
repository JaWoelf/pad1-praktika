#include <iostream>
#include <regex>
#include <string>
#include "board.h"

using namespace brd;
using namespace std;



class ChessBoard
{
private:
  string boardArray[8][8];

public:
  string getFigure();
  string getBoard();
  ChessBoard()
  {

  }

};







