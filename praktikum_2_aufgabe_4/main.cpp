#include <iostream>

using namespace std;

int main()
{
  const int sum = 10000;
  const double rate = 0.07;

  double annuity,
         interest,
         repayment,
         balance = sum;

  int    year = 0;

  // UI
  while(true){
    cout << "10.000 Loan at 7% interest\n"
            "What is your annuity of choice?\n";
            "Annuity must be 701€ or higher.\n";
    cin >> annuity;
    cout << "\n\n";


    // ensure annuity is above interest, otherwise repayment couldn't happen.
    if (annuity > ( sum * rate)){
        break;
      }
  }

  // Calculation
  // each while cycle is a year
  while (balance > 0){
    year ++;
    interest = balance * rate;
    repayment = annuity - interest;
    balance = balance - repayment;



    if ((balance + interest) < annuity){
        // schluss rate
        cout << "Year: " << year << ", Interest: " << interest << "€, Repayment: " << balance << "€, Rest: " << 0 << "€\n";
        return 0;
    }else{
        cout << "Year: " << year << ", Interest: " << interest << "€, Repayment: " << repayment << "€, Rest: " << balance << "€\n";
      }

  }//while

  return 0;
}

