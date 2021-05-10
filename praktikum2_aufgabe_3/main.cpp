#include <iostream>

using namespace std;

int main()
{
  char input;
  //  großbuchstabe   ASCII dez: 65 - 90;
  //  kleinbuchstaben ASCII Dez: 97 - 122;

  //runtime at infinito
  while (true){
      // get char input
      cout << "Type a lowercase char (a-z).\n";
      cin >> input;

      // perform checks on input
      if (input == 0){
          cout << "\nABORT PROGRAMM\n";
          return 0;

      //actually lowercase char?
      }else if ((input >= 'a') && (input <= 'z' )){
          input -= 32;
          cout << "Here's your input in uppercase: " << input << "\n";

      // wrong input
      }else{
          cout << "\nERROR: Input was malformated.";
      }
    } //while
}

