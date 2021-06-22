#include <iostream>
#include <cmath>
using namespace std;
double argument_input = 0;
double error_input = 0;
static double reihendarstellung_result = 0;
static uint32_t anzahl_sumanden_result = 0;

double get_error(double x){
     return ((   abs(reihendarstellung_result - exp(x))  )/exp(x));
}

bool check_if_error_of_result_is_bigger_than_error(double x, double error){
    if(get_error(x) > error){
        return true;
    }
    return false;
}

double get_fakultaet(uint32_t anzahl){
    double result = 1;
    for(int i = 1; i <= anzahl; i++){
        result = result*i;
    }
    return result;
}

double get_exponation_of(double x, uint32_t anzahl){
    double result = 1;
    for(int i = 1; i <= anzahl; i++){
       result = result * x;
    }
    return result;
}

double get_summand(double x, uint32_t anzahl){
    double expo = get_exponation_of(x, anzahl);
    double fak = get_fakultaet(anzahl);
    uint32_t anzahl_buffer = anzahl;
    return expo/fak;
}

double function(double x, uint32_t anzahl){
    if(anzahl == 0){
        return 1;
    }
    uint32_t number_buffer = anzahl -1.0;
    double summant_1 =  get_summand(x, anzahl);
    double summant_2 = function(x, number_buffer);
//    cout << summant_1 << " / " << summant_2 << " + ";
    return summant_1 + summant_2;
}

uint32_t compute_rec(double x, double error, uint32_t anzahl){
    reihendarstellung_result = function(x, anzahl);
    double buffer = reihendarstellung_result;
    uint32_t number_buffer = anzahl + 1.0;
    if(check_if_error_of_result_is_bigger_than_error( x,  error)){
        return compute_rec( x,  error,number_buffer);
    }
    return anzahl;
}

void compute(double x, double error){
    //Überprüft reihendarstellung_result mit dem eigentlichen result wert von x
    anzahl_sumanden_result =  compute_rec( x, error, 0) + 1;
}

int main()
{
    // ask for number of arguments
        cout << "Geben Sie das Argument ein: ";
    // User Input Argument
        cin >> argument_input;
        cout << endl;
    // Ask for error
        cout << "Geben Sie den maximalen zugelassenen Fehler ein: ";
    // User Input Error
        cin >> error_input;
        cout << endl;
    // Compute result
       compute(argument_input,error_input);
    // print Reihendarstellung
        cout << "Reihendarstellung: " << reihendarstellung_result;
    // Print Exakter Wert
        cout << "\nExakter Wert: " << exp(argument_input);
    // Print Fehler
        cout << "\nFehler: " << get_error(argument_input);
    // Print Anzahl Summanden
        cout << "\nAnzahl Summanden: " << anzahl_sumanden_result << "\n" << endl;
    return 0;
}
