#include <iostream>

using namespace std;

int main(void)
{
  // Set input vars
  double a,b,c;
  double sum,product,average;

  // Welcome
  cout << "Double Floatingpoint Calculator\n\n"
          "This programm will take 3 floating-point numbers to calculate and return\n"
          "SUM, PRODUCT, AVERAGE.\n\n";

  // Get Userinput
  cout << "Define first number:\n";
  cin >> a;
  cout << "Define second number:\n";
  cin >> b;
  cout << "Define third number:\n";
  cin >> c;

  // Calculate results
  sum = a+b+c;
  product = a*b*c;
  average = a*b*c/3;

  // Print results
  cout << "--------------\n"
          "Input given: " << a << ", " << b << ", " << c << "\n"
          "--------------\n";
  cout << "Sum: " << sum << "\n";
  cout << "Product: " << product << "\n";
  cout << "Average: " << average << "\n";

  return 0;

}
