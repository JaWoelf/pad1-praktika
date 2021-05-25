#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // atol and toString not allowed
    // read string max 5 only num
    // convert string to long
    // calc exponent from long
    // save result in char array

    long num = 0;
    string input;
    int input_length;

    while(true){

        cout << "Bitte Zahlenstring eingeben (max. 5): " << endl;
        cin >> input;

        //check input length
        input_length = input.length();
        if ((input_length < 1) or (input_length > 5)){
            cout << "String zu lang, bitte neu eingeben." << endl;
            continue;
        }


        //check input is num
        for( int i=input_length; i>0; i--){
            char c = input[i-1] -48;
            //cout << c << endl;

            if (c < 0 or c >9){
                cout << "String enthaelt nicht nur Ziffern, bitte neu eingeben." << endl;
                break;
            }
            num += c * pow(10,input_length-i);

        }

        num = pow(num,2);
        cout << "Quadrat der eingegebenen Zahl: " << num << endl;

        // get length of number, as needed for char array
        //https://stackoverflow.com/questions/12945168/how-to-convert-int-to-string-in-c-without-access-to-int-to-string-function
        string convert_to_str;
        int i = 0;
        while (num != 0)
            {
                 i = num % 10;
                 convert_to_str.insert(0, 1, '0' + i);
                 num = num/10;
            }
        int number_length = convert_to_str.length();
        //cout << "number length: "<< number_length<< endl;

        char result[number_length*2-1];

        for(int i=0; i < number_length; i++){
          result[i*2] = convert_to_str.at(i);
          result[i*2+1] = ' ';

        }

        //cout << "convert_to_str: "<< convert_to_str.length()<< endl;
        cout << "\nchar-Array: "<< result<< endl;
        cout << "\n\n\n" << endl;

    }

    return 0;
}
