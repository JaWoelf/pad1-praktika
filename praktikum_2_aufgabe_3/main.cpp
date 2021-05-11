#include <iostream>

using namespace std;

int main()
{
    // uppercase char ASCII dez: 65 - 90
    // lowercase char ASCII dez: 97 - 122

    //get Input
    char input;

    // loop forever
    while (true){

        //Verify Lower Case
        cout << "Type a lowercase char (a-z):"<<endl;
        cin >> input;

        //check input
        if (input == 0){
            cout << "Exit."<<endl;
            return 0;
        } else if ((input >= 97) && (input <= 122)){
            input = input - 32;
            cout << "Input in uppercase: "<< char(input)<<endl;
        } else {
            //error handling
            cout << "There is something wrong with what you entered."<<endl;
        }
    }

    return 0;
}
