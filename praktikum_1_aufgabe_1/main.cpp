#include <iostream>
using namespace std;


int main(void)
{
    /*vars*/
    int length, volume, surface, square, i;

    cout << "Geben Sie eine ganze Zahl ein!" << endl;

    /*user input*/
    cin >> length;

    /*calculation*/
    //length = i;
    square = length * length;
    surface = 6 * square;
    volume = square * length;

    /*result*/
    cout << "Oberflaeche: " << surface << endl;
    cout << "Volumen: " << volume << endl;


    return 0;
}
