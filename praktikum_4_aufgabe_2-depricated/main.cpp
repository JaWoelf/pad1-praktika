#include <iostream>
#include <regex>
#include <string>
using namespace std;

// Figures
// WHITE FIGURES
const string wB = " w_BAUER___ ";
const string wT = " w_TURM____ ";
const string wS = " w_SPRINGER ";
const string wL = " w_LÄUFER__ ";
const string wD = " w_DAME____ ";
const string wK = " w_KOENIG__ ";
// BLACK FIGURES
const string bB = " s_BAUER___ ";
const string bT = " s_TURM____ ";
const string bS = " s_SPRINGER ";
const string bL = " s_LÄUFER__ ";
const string bD = " s_DAME____ ";
const string bK = " s_KOENIG__ ";
// FREE FIELD
const string fF = " __________ ";

// BOARD
string board[8][8] = {
  {bT,bS,bL,bK,bD,bL,bS,bT},
  {bB,bB,bB,bB,bB,bB,bB,bB},
  {fF,fF,fF,fF,fF,fF,fF,fF},
  {fF,fF,fF,fF,fF,fF,fF,fF},
  {fF,fF,fF,fF,fF,fF,fF,fF},
  {fF,fF,fF,fF,fF,fF,fF,fF},
  {wB,wB,wB,wB,wB,wB,wB,wB},
  {wT,wS,wL,wK,wD,wL,wS,wT}
};

// User Input
string input;
regex pattern("[a-h][1-8]-[a-h][1-8]");
int fromx, fromy, tox, toy;

/*
 *    RUNTIME
 */

int main(){

  // Play-Time
  while (true)
  {
    // Clear CLI and draw horizontal index
    cout << "\x1B[2J\x1B[H";
    cout << "\n         A           B           C           D           E           F           G           H       ";

    // draw board (with figures) line by line
    // beginning each line with vertical index
    for (int y = 0; y < 8; y++)
    {
      cout << "\n " << y+1 << " ";
      for (int x = 0; x < 8; x++)
      {
        cout << board[y][x];
      }
    }

    // User Input Area
    cout << "\n\n  Geben Sie den nächsten Zug ein.\nz.B. d7-a4 'exit' beendet das Spiel.\n";
    cin >> input;


    // Checks exit command and sanity
    if (input == "exit")
    {
      return 0;
    }
    else if (regex_match(input, pattern))
    {
      // convert input to numerical index of board array.
      fromx = input[0] - 97;
      fromy = input[1] - 49;
      tox = input[3] - 97;
      toy = input[4] - 49;

      // move
      board[toy][tox] = board[fromy][fromx];
      board[fromy][fromx] = fF;

    }

  } //while true

};

// func: move_beats

bool move_beats()
{

  return true;
}

// func: is_check
bool is_check()
{

  return false;
}

// func: is_check_mate
bool is_check_mate()
{

  return false;
}

// func: is_move_assignable
bool is_move_assignable(int coords[2][2])
{
  bool isassignable = true;
  string figure = board[coords[1][1]][coords[1][2]];
  bool iswhite = false;
  
  // what color?
  if(figure[1] == 'w')
  {
    iswhite = true;    
  };
  
  // move targets field occupied by friendly figure?
  string targetfigure = board[coords[1][2][]]
  
  if(figure == wB or figure == bB)
  {
      isassignable = is_move_assignable_bauer(iswhite,coords);
  }
  else if(figure == wT)
  {
      isassignable = is_move_assignable_turm(iswhite,coords);
  }
  else if(figure == wS)  
  {
      isassignable = is_move_assignable_springer(iswhite,coords);
  }
  else if(figure == wL)  "w"
  {
      isassignable = is_move_assignable_laeufer()iswhite,coords);
  }
  else if(figure == wD)
  {
      isassignable = is_move_assignable_turm(iswhite,coords);
  }
  else if(figure == wK)
  {
      isassignable = is_move_assignable_turm(iswhite,coords);
  }

  }
    
    
  return isassignable;
};

    
// func: is_move_assignable_bauer
bool is_move_assignable_bauer(bool iswhite, int coords[2][2])
{
  return true;
};

// func: is_move_assignable_turm
bool is_move_assignable_turm(bool iswhite, int coords[2][2])
{
  return true;
};

// func: is_move_assignable_springer
bool is_move_assignable_springer(bool iswhite, int coords[2][2])
{
  return true;
};

// func: is_move_assignable_laeufer
bool is_move_assignable_laeufer(bool iswhite, int coords[2][2])
{
  return true;
};

// func: is_move_assignable_koenig
bool is_move_assignable_koenig(bool iswhite, int coords[2][2])
{
  return true;
};

// func: is_move_assignable_dame
bool is_move_assignable_dame(bool iswhite, int coords[2][2])
{
  return true;
};


