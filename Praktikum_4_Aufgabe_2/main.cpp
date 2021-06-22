#include <iostream>
#include <regex>
#include <string>
#include <stdlib.h>
using namespace std;
#define WHITE true;
#define BLACK false;


// Figure types
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

// Whos Turn is this flag? WHITE=true BLACK=false
bool turn = WHITE;
// Who's figure is this? regex_match(ownerPattern, figure)
// -> WHITE = true, BLACK = false
static regex ownerPattern("[a-z]");

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
 *    FUNCTIONAL
 *
 *  ############################################
 */

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
}


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




//    Whos figure is that?
//      returns true if white, false if not.
//    ! Be aware that void tiles would also return false. Shall be
bool isWhitesFigure(coordinates coords){
    return regex_match(board[coords.x][coords.y], ownerPattern);
}

//    Whos move is it?
//      returns true i
bool isWhitesMove(){
  return turn;
}


/*  is Move Valid  - Called from main()
 *  args: movementCoordinates move | struct containing 2 x/y pairs of board-coordinates
 *                                   indexing moving figure and target field.
 *  return: bool                   | Rather move is valid or not
 *  throw:
 *
 *  Funktion:
 */
bool isMoveValid(movementCoordinates move)
{

  string figure = board[move.figure.x][move.figure.y];
  string target = board[move.target.x][move.target.y];

  if ( figure == voidtile){
      notificationsStack.push_back("Cannot move empty Field.");
  }

  if ((figure == whitepawn) || (figure == blackpawn))
    return isPawnMoveValid();
  else if ((figure == whiterook) || (figure == blackrook))
    return isRookMoveValid();
  else if ((figure == whiteknight) || (figure == blackknight))
    return isKnightMoveValid();
  else if ((figure == whitebishop) || (figure == blackbishop))
    return isBishopMoveValid();
  else if ((figure == whitequeen) || (figure == blackqueen))
    return isQueenMoveValid();
  else if ((figure == whiteking) || (figure == blackking))
    return isKingMoveValid();
  else
    throw "Unknown figure exception";
}


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
      } catch (string err) {
        // Sanity Check failed - malformatted user input.
        notificationsStack.insert( notificationsStack.begin(), err);
        continue;
      }

      // Validate Movement
      //    Some very basic
      //    Identify selected figure
      //    Call movement validation function for that figure
      if ( isMoveValid(move)){

        }




      // Now  Validate
     // isMoveValid(move);


      //return 0;


  } // while(true)
}// main()
