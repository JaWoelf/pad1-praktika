#include <iostream>
#include <vector>

using namespace std;
// Vector Type used as dynamic List for Prime Factors
// Fills at Algorithm execution
// vector<int> primeFactors;
vector<int> primeFactors;
// Temporary (per while execution) int as prime Factor Candidat.
// Gets stored in primeFactors
int primeCandidate = 2;
// User Input for calculation.
int input = 0;

int main()
{
  // UI
  cout << "Integer factorization\n"
          " - Takes a positive Integer\n"
          " - Prints the results of prime decomposition of that Integer\n.";

  //Ensure positive Integer
  while (!(input > 0)){
      cout << "\nSet positive Integer:\n";
      cin >> input;
  }
  // Don't waste CPU Time for that.
  if (input == 1) {
      cout << "Prime factors of " << input << " are: " << "none";
      return 0;
  }

  /*  Algorithm
   *
   */
  while (primeCandidate <= (input / 2)){
      if ((input % primeCandidate) == 0){
          primeFactors.push_back(primeCandidate);
          input = input / primeCandidate;
        }else{
          primeCandidate++;
        }
    }

  // Remaining bit of input is itself a prime
  primeFactors.push_back(input);

  // Output
  cout << "\nCalculation results: \n\n";
  for (int element: primeFactors)

    cout << element << "\n";

  return 0;
}


/* 
PSEUDOCODE OF ALGORITHM
SOURCE: https://de.wikibooks.org/wiki/Algorithmensammlung:_Zahlentheorie:_Primfaktorisierung

  function primfaktoren (n)
  f ← Leere Liste
  if n = 1 then return f
  t ← 2
  while t * t ≤ n do
    begin
    if n mod t = 0 then
      begin
      Füge t zur Liste f hinzu
      n ← n / t
      end
    else t ← t + 1
    end
  Füge n zur Liste f hinzu
  return f
*/
