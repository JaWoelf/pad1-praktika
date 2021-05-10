#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Vars
  int integer, sums;
  double tolerance, row, exact = 1;

  // User Input
  cout << "\nGeben Sie einen positiven Integer ein: ";
  cin >> integer;
  cout << "\nGeben Sie den maximal zugelassenen Fehler ein: ";
  cin >> tolerance;

  cout << "\nEXP:  " << exp(integer);
  // Output
  cout << "\n\nReihendarstellung: " << row;
  cout << "\nExakter Wert: " << exact;
  cout << "\nFehler: " << error;
  cout << "\nAnzahl Summanden: " << sums;
  return 0;
}

int faculty(){

}

double error(int x){
  double ex = exp(x);
  double tau = (faculty(x) - ex) / ex;
  return tau;
}

