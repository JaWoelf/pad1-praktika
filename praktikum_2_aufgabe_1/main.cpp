#include <iostream>

using namespace std;

int main()
{
    int input1=0, input2=0, sum=0;

    while(true){
        //Interface
        cout << "Geben Sie 2 positive Zahlen ein:" << endl;
        cout << "Bsp.: 5 8 " << endl;

        cin >>input1>>input2;


        //check if input is correct
        while(input1 <= 0 || input2 <= 0){
            cout << "Geben Sie 2 positive Zahlen ein:" << endl;
            cout << "Bsp.: 5 8 " << endl;

            cin >>input1>>input2;
        }

        // sort input
        if (input1 > input2){
            int tmp = input2;
            input2 = input1;
            input1 = tmp;
        }

        //calc
        //cout << sum;
        while (input1 <= input2){
            sum += input1;

            //create result string
            if (input1 == input2){
                cout << input1;
            } else {
                cout << input1 << " + ";
            }

            input1 ++;

        }


        //result
        cout << " = " << sum << endl;
        cout << "------------------------" << endl;
        cout << "\n\n" << endl;

    }

    return 0;
}
