#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int input=0,
        process_input;

    //Interface
    cout << "Primfaktorzerlegung\n" << endl;
    cout << "Geben Sie eine ganzzahlige positive Zahl ein:" << endl;
    cin >>input;


    //validate input
    while(input <= 0){
        cout << "\nError:" << endl;
        cout << "Geben Sie eine ganzzahlige positive Zahl ein:" << endl;
        cout << "Bsp.: 5" << endl;
        cin >>input;
    }

    if (input == 1) {
        cout << "Primzahlzerlegung von " << input <<endl;
        cout << "Die Zahl 1 ist keine Primzahl"<<endl;
        return 0;
    }


     string primeFactors = "";
     int primeCandidate = 2;

     process_input = input;

     while (primeCandidate * primeCandidate <= process_input){
         if ((process_input % primeCandidate) == 0){
             primeFactors.push_back(primeCandidate);
             process_input = process_input / primeCandidate;
           }else{
             primeCandidate++;
           }
       }

     primeFactors.push_back(process_input);



    cout << "Primzahlzerlegung: " <<input <<" = ";

    bool first = true;
    //for each loop
    for (int element: primeFactors){        //cycle through every number of the arraylist
        if (first){
            cout << element;
            first = false;
        } else {
            cout << " * " << element;
        }


    }
    cout << endl;
    return 0;
}
