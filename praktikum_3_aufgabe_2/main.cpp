#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
  const string w_B = " w_BAUER___ "; // WHITE FIGURES
  const string w_T = " w_TURM____ ";
  const string w_S = " w_SPRINGER ";
  const string w_L = " w_LÄUFER__ ";
  const string w_D = " w_DAME____ ";
  const string w_K = " w_KOENIG__ ";
  const string b_B = " s_BAUER___ "; // BLACK FIGURES
  const string b_T = " s_TURM____ ";
  const string b_S = " s_SPRINGER ";
  const string b_L = " s_LÄUFER__ ";
  const string b_D = " s_DAME____ ";
  const string b_K = " s_KOENIG__ ";
  const string f_F = " __________ "; // FREE FIELD

  /*
   * VARs
   * ------------------------------------------
   */
  // Board with start setup.
  string board[8][8] = {
    {b_T,b_S,b_L,b_K,b_D,b_L,b_S,b_T},
    {b_B,b_B,b_B,b_B,b_B,b_B,b_B,b_B},
    {f_F,f_F,f_F,f_F,f_F,f_F,f_F,f_F},
    {f_F,f_F,f_F,f_F,f_F,f_F,f_F,f_F},
    {f_F,f_F,f_F,f_F,f_F,f_F,f_F,f_F},
    {f_F,f_F,f_F,f_F,f_F,f_F,f_F,f_F},
    {w_B,w_B,w_B,w_B,w_B,w_B,w_B,w_B},
    {w_T,w_S,w_L,w_K,w_D,w_L,w_S,w_T}
  };
  // Last User Input
  char userInputArray[5];

  // Move
  char sourceHorizontal,
      sourceVertical,
      targetHorizontal,
      targetVertical;

  while (true){
    /*
    *   DRAW BOARD
    * ------------------------------------------
    */

    // Clear CLI
    cout << "\x1B[2J\x1B[H";
    // draw horizontal Index
    cout << "\n         A           B           C           D           E           F           G           H       ";

    for (int i = 0; i < 8; i++){
        // draw vertical Index
        cout << "\n  " << i+1 << " ";
        for (int j = 0; j < 8; j++){
            // Place Figures
          cout << board[i][j];
        } // vertical
    } // horizontal


    /*
    *   USER INTERFACE
    * ------------------------------------------
    */
    cout << "\n                                                                                     ";
    cout << "\n  Geben Sie den nächsten Zug ein. (Format: d7-a4)"
            "\n  Zum Verlassen 'exit' Eingeben. ";



    // close Game
    if (userInputString == "exit")
      return 0;

    // unexpected input
    if (userInputString.length() != 5)
      continue;
    //
    strcpy( userInputArray, cin.c_str());

return 0;
  } //while true

};




