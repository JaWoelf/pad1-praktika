#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  string input, input_is_integer;
  long num = 0;
  int input_length;

  // User Input with sanity check.
  while (true){
    cout << "Bitte Zahlenstring eingeben (0-5 Zeichen): ";
    cin >> input;

    // Check length
    input_length = input.length();
    if( (input_length < 1) or (input_length > 5) ){
      cout << "\nUngültige länge.\n";
      continue;
    }

    // Disect input.
    // Check every char is numerical and add
    // its value to num.
    for( int i=input_length; i>0; i--){
      char c = input[i-1] - 48;
      cout << "\nc at " << i << " = " << c+0;
      if (c < 0 or c > 9){
        cout << "\nUngültiges Zeichen an Stelle " << i+1;
        break;
      }
      num += c * pow(10,input_length-i);
    }

    //
    num = pow(num,2);

    // Dismantel Num into character Array
    cout << "\nQuadrat der eingegebenen Zahl: " << num;
    int last_digit = 0;

    // get length of number, as needet for char array
    int number_length = 0;
    long n = num;
    do {
        ++number_length;
        n /= 10;
    } while(n);

    char result[number_length*2-1];

    for(int i=0; i < number_length; i++){
      cout << "dbg: " << num % 10;
      result[i*2] = num % 10;
      result[i*2+1] = ' ';
      num = num / 10;
    }

    cout << "\nchar-Array: ";
    for(int i=0; i < number_length; i++){
      cout << "\ni: " <<  result[i]+0;
    }
    /*

    if( (input.lenth() < 1) or (input.length() > 5) ){
      cout << "\nStringlänge unzulässig.\n";

    }else if(){
      cout << "\nString darf nur Ziffern enthalten.\n";

    }else{
      break;
    }*/
    cout << "\n\n\n" << input_length << endl;
    cout << input[1];
  }//while



}//main()
