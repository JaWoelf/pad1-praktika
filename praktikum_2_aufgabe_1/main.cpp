#include <iostream>

using namespace std;

int main()
{
  // run programm in endless repetition
  // while true.
  while (true) {
    int input1, input2, sum = 0;

    // Welcome
    cout << "##################################################\n"
            "# This Programm calculates the sum of all Numbers,\n"
            "# from Input 1 to Input 2.\n"
            "#\n"
            "# e.g. Input1 = 1, Input2 = 5\n"
            "# 1+2+3+4+5 = 15\n\n";

    // Get Input
    cout << "Set Input 1 (1/2)" << endl;
    cin >> input1;
    cout << "Set Input 2 (2/2)" << endl;
    cin >> input2;

    // sort Input
    if (input1 > input2){
        int tmp = input2;
        input2 = input1;
        input1 = tmp;
      }

    // Calculation
    // prä-output
    cout << sum;
    while (input1 <= input2){
        sum += input1;
        input1 ++;
        //step-output
        cout << " + " << input1 ;
      }

    //readability linefeed
    cout  << "\n\n";
    // Show Results
    cout << "Sum = " << sum;
    //readability linefeed
    cout  << "\n\n";

  } // While true
  return 0;
}
