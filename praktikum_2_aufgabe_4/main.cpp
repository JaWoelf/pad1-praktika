#include <iostream>

using namespace std;

int main()
{
    const double credit = 10000;
    const double rate = 0.07;
    int year = 0;
    double annuity,
           zinswert,
           leftToPay,
           tilgung;

    // Interface
    cout << "Kreditsumme: 10.000 Euro" << endl;
    cout << "Geben Sie die Annuitaet an:" << endl;
    cin >> annuity;
    cout << "\n\n" << endl;


    //calc
    leftToPay = credit;

    while (leftToPay > 0) {
        year ++;
        zinswert = leftToPay * rate;
        leftToPay = zinswert + leftToPay;


        if (leftToPay < annuity){
            tilgung = leftToPay;
            leftToPay = 0;

        } else {
            leftToPay = leftToPay - annuity;
            tilgung = annuity - zinswert;
        }


        cout << "Jahr: " << year << ",      Zinsen: " << zinswert << "Euro,             Tilgung:" << tilgung << "Euro,              Restschuld:" << leftToPay << endl;
    }
    return 0;
}
