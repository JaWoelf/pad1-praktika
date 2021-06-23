#include <iostream>
#include <regex>
#include <string>
#include <stdlib.h>
using namespace std;
#define WHITE true;
#define BLACK false;


// Figure Strings (As string is required by specification)
// single character allows neat praesentation
// also   whitepam = "p"
// while  whitepam = 'p'
const string whitepawn  = "p",
            whiterook   = "r",
            whiteknight = "j",
            whitebishop = "b",
            whitequeen  = "q",
            whiteking   = "k",
            blackpawn   = "P",
            blackrook   = "R",
            blackknight = "J",
            blackbishop = "B",
            blackqueen  = "Q",
            blackking   = "K",
            voidtile    = " ";

// 8*8 array as board, start setup.

string board[8][8] = {
  {whiterook,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackrook},
  {whiteknight,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackknight},
  {whitebishop,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackbishop},
  {whiteking,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackking},
  {whitequeen,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackqueen},
  {whitebishop,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackbishop},
  {whiteknight,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackknight},
  {whiterook,whitepawn,voidtile,voidtile,voidtile,voidtile,blackpawn,blackrook},
};

// regex pattern for user input sanity check
static regex saneInputPattern("[a-h][1-8]-[a-h][1-8]");

// Whos Turn is this flag? WHITE=true BLACK=false (see #define  entries at beginning of file)
bool turn = WHITE;

// regex pattern to recognise, to whom a figure belongs.
static regex whiteFigurePattern("[a-z]");
static regex blackFigurePattern("[A-Z]");

// UI templates
static string cliClear = "\x1B[2J\x1B[H";
static string uiIndexHorizontal = "\n   A B C D E F G H ";

// certain functions will generate UI notifications.
// notificationStack collects these for drawUI() to print.
// drawUI() shall empty notificationStack on print.
vector<string> notificationsStack;


// several functions require x/y coordinates in differend context, better use a template.
struct coordinates{int x, y;};
struct movementCoordinates{coordinates figure, target;};


/*
 *
 *
 *    Board Information Functions
 *
 *  ############################################
 */
// Check if location is occupied by white figure.
bool isFieldWhite(coordinates m_coords){
    return regex_match(board[m_coords.x][m_coords.y], whiteFigurePattern);
}

// Check if location is occupied by black figure.
bool isFieldBlack(coordinates m_coords){
    return regex_match(board[m_coords.x][m_coords.y], blackFigurePattern);
}

// Check if location is empty.
bool isFieldEmpty(coordinates m_coords){
    return ( board[m_coords.x][m_coords.y] == voidtile );
}

// location color bool
// as #defined WHITE true  BLACK false
// may also return false on void tiles.
bool fieldColorBool(coordinates m_coords){
    return regex_match(board[m_coords.x][m_coords.y], whiteFigurePattern);
}

// figure color bool
// as #defined WHITE true BLACK false
// may also return false on void tiles
bool figureColorBool(string m_figure){
    return regex_match(m_figure, whiteFigurePattern);
}

// Whos turn bool
// as #defined WHITE true  BLACK false
bool isWhitesTurn(){
    return turn;
}
// Whos turn string  (for UI)
string turnColorString(){
    if (isWhitesTurn())
        return "WHITE";
    return "BLACK";
}


/*
 *
 *
 *    User Interface
 *
 *  ############################################
 */
//  Draw CLI
void drawUI()
{
  cout << cliClear;
  cout << uiIndexHorizontal;

  for (int y = 0; y < 8; y++)
  {
    cout << "\n " << y +1 << " ";
    for (int x = 0; x < 8; x++)
    {
       cout << board[x][y] << " ";
    }//for x
  }//for y

  while (notificationsStack.size() > 0){
      cout << "\n" + notificationsStack.back();
      notificationsStack.pop_back();
  }
  cout << "\nSet your turn. e.g. a7-b6\n";
}


// Get and process user Input
movementCoordinates userInput(){
  movementCoordinates move;
  string userInputString;
  cin >> userInputString;

  if (userInputString == "exit"){
  // Tell OS to close runtime.
    cout << "User Aborted";
    _Exit (EXIT_SUCCESS);

  } else if ( regex_match(userInputString, saneInputPattern) ){
  // input seems sane, now build movementCoordinates
    move.figure.x = userInputString[0] - 97;
    move.figure.y = userInputString[1] - 49;
    move.target.x = userInputString[3] - 97;
    move.target.y = userInputString[4] - 49;
    return move;

  } else {
      throw "Input malformatted - repeat.";

  };
};

/*
 *
 *
 *    Movement & Chess Rules Checking
 *
 *  ############################################
 */
//


int normaliseMoveDirection(int m_index){
    if ( m_index > 0 )
        return m_index;
    else
        return m_index * (-1);
}

bool hasLineOfSight(movementCoordinates m_move){
  return true;
}

bool isLegalMovePawn(movementCoordinates m_move){
    coordinates figure = m_move.figure;
    coordinates target = m_move.target;
    int verticalDistance   = normaliseMoveDirection( (figure.y - target.y) );
    int horizontalDistance = normaliseMoveDirection( (figure.x - target.x) );

    if (horizontalDistance > 1)
        return false;

    switch(verticalDistance){
        case(1):
            return true;
        case(2):
            if ((figure.y == 2) && isWhitesTurn())
                return true;

            if ((figure.y == 7) && !isWhitesTurn())
                return true;

    }//switch
    return false;
} //isLegalMovePawn


bool isLegalMoveRook(movementCoordinates m_move){
    coordinates figure = m_move.figure;
    coordinates target = m_move.target;
    int verticalDistance   = normaliseMoveDirection( (figure.y - target.y) );
    int horizontalDistance = normaliseMoveDirection( (figure.x - target.x) );

    // must only move in one direction
    if ( (verticalDistance > 0) && (horizontalDistance > 0) )
        return false;

    // move is Valid, if target is in line of sight.
    return hasLineOfSight(m_move);

} //isLegalMoveRook


bool isLegalMoveKnight(movementCoordinates m_move){
    coordinates figure = m_move.figure;
    coordinates target = m_move.target;
    int verticalDistance   = normaliseMoveDirection( (figure.y - target.y) );
    int horizontalDistance = normaliseMoveDirection( (figure.x - target.x) );

    // must move 2x/1y or 1x/2y
    if ((verticalDistance + horizontalDistance) == 3)
        return true;
    else
        return false;

} //isLegalMoveKnight


bool isLegalMoveBishop(movementCoordinates m_move){
    coordinates figure = m_move.figure;
    coordinates target = m_move.target;
    int verticalDistance   = normaliseMoveDirection( (figure.y - target.y) );
    int horizontalDistance = normaliseMoveDirection( (figure.x - target.x) );

    // must move diagonally
    if ( verticalDistance != horizontalDistance)
        return false;
    else
        return hasLineOfSight(m_move);

} //isLeghalMove


bool isLegalMoveQueen(movementCoordinates m_move){
    return (isLegalMoveBishop(m_move) or isLegalMoveRook(m_move));

} //isLegal QUEEN


bool isLegalMoveKing(movementCoordinates m_move){
    if ( (  normaliseMoveDirection((m_move.figure.y - m_move.target.y))
          + normaliseMoveDirection((m_move.figure.x - m_move.target.x)))
         <= 2)
        return true;
    else
        return false;

} //isLegal KING


// Moves which expose own king to check are illegal.
bool isMoveSelfCheck(movementCoordinates m_move){
    return false;

} // isMoveSelfCheck



/*  from main()
 *      args:
 *          movementCoordinates move {figure{x,y},target{x,y}}
 *          Indizes, pointing to figute and target in board[8][8]
 *      functional:
 *          1. basic sanity check
 *             e.g. color of figure & target differ, figure is not voidtile,... *
 *          2. identify figuretype
 *             e.g. figure is whitepawn or is blackpawn
 *                -> return isPawnMoveValid()
 *      returns:
 *          bool func() | function validating figures movement.
 *      exception:
 *          sanity check fails
 *          figure isn't recogniced
 */
bool isMoveValid(movementCoordinates m_move)
{
  string figure = board[m_move.figure.x][m_move.figure.y];
  string target = board[m_move.target.x][m_move.target.y];
  bool isLegal = true;

  // Generic Checks

  // invalid: figure cannot be voidtile
  if ( figure == voidtile ){
      notificationsStack.push_back("Select one of your figures to move.");
      return false;

  // Wrong color wants to move
  } else if ( isWhitesTurn() != isFieldWhite(m_move.figure) ){
      notificationsStack.push_back(turnColorString() + " - make a move.");
      return false;

  // target is of same color as figure
  } else if ( figureColorBool(figure) == figureColorBool(target) ){
      notificationsStack.push_back("Cannot beat friendly figures.");
      return false;
  }


  // Figure Specific Checks

  if ((figure == whitepawn) || (figure == blackpawn))
     isLegal = isLegalMovePawn(m_move);

  else if ((figure == whiterook) || (figure == blackrook))
      isLegal = isLegalMoveRook(m_move);

  else if ((figure == whiteknight) || (figure == blackknight))
      isLegal = isLegalMoveKnight(m_move);

  else if ((figure == whitebishop) || (figure == blackbishop))
     isLegal = isLegalMoveBishop(m_move);

  else if ((figure == whitequeen) || (figure == blackqueen))
      isLegal = isLegalMoveQueen(m_move);

  else if ((figure == whiteking) || (figure == blackking))
      isLegal = isLegalMoveKing(m_move);

  else
      throw "Unknown figure exception";

  return isLegal;

}// isMoveLegal()

bool isFigureBeaten(coordinates move){
    return (board[move.x][move.y] == voidtile);
};

/*
 *        MAIN
 *
 */

int main()
{
  while(true){

      // Draw UI
      //    Checkboard
      //    Figures
      //    Notifications
      drawUI();


      // User Input -> Move
      //    Listen for Input
      //    Fetch Keyword "exit" to terminate
      //    Sanitycheck (regex)
      //    Convert input string to movementCoordinates
      movementCoordinates move; // must declare out of try for visibility
      try {
          move = userInput();
          int tgtx = move.target.x, tgty = move.target.y,
              fgrx = move.figure.x, fgry = move.figure.y;

          // on invalid move, re-try turn.
          if (!isMoveValid(move))
               continue;

          // notify UI if a figure gets beaten.
          if (isFigureBeaten(move.target))
             notificationsStack.push_back(board[fgrx][fgry] + " beats " + board[tgtx][tgty] + ".");

          // apply move
          board[tgtx][tgty] = board[fgrx][fgry];
          board[fgrx][fgry] = voidtile;

          // CHECK-STATE?
          //
          isCheckState();


      } catch (string err) {
          // Sanity Check failed - malformatted user input.
          notificationsStack.insert( notificationsStack.begin(), err);
          continue;
      }
  } // while(true)
}// main()
