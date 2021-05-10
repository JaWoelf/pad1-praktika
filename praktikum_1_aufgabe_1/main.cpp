#include <iostream>

using namespace std;

int main(void)
{
  // Set vars
  int length, volume, surface, square;

  // Get Userinput
  cout << "Gibe Integer!\n";
  cin >> length;

  // Calculate results
  square = length * length;
  surface = 6 * square;
  volume = square * length;

  // Print results
  cout << "Oberfläche: " << surface << endl;
  cout << "Volumen: " << volume << endl;

  return 0;

}
