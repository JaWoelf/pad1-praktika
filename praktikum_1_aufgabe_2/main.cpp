#include <iostream>


using namespace std;

int main()
{
    //var
    double x, y, z, sum, product, average;

    // task
    cout << "\n --> Geben Sie 3 Zahlen als double ein\n" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Info: Dezimaltrennzeichen [.]!                     |" << endl;
    cout << "Info: Trennung der Zahlen mit einem Leerzeichen!   |" << endl;
    cout << "Beispiel: 5.2 3.7 1.4                              |" << endl;
    cout << "----------------------------------------------------\n" << endl;


    // process input
    cout << "Eingabe: ";
    cin >>x>>y>>z;


    // calculation
    sum = x + y + z;
    product = x * y * z;
    average = (x + y + z)/3;


    //result
    cout << "----------------------------------------------------\n" << endl;
    cout << "Summe [+]:        " << sum << endl;
    cout << "Produkt [*]:      " << product << endl;
    cout << "Durchschnitt:     " << average << endl;

    cout << "----------------------------------------------------\n" << endl;
    cout << "[Done]" << endl;


    return 0;
}
