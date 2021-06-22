#include <iostream>

using namespace std;

struct provider {
  string name;
  double price_monthly;
  double price_kwh;
  int bonus;
} p_bevenergie,
  p_emmaenergie,
  p_vattenfall,
  p_enerswitch,
  p_123energie,
  p_rheinpower;

// func: main
int main()
{
  //build providers dataset;
  builddataset();

  cout << "Wo hoch ist der jährliche Energieverbrauch in kWH?\n";
  cin >>


  cout << "Hello World!" << endl;
  return 0;
}



// func: calculate

// func: sort calculated list

// func: search selected



// func: build dataset
void builddataset()
{
  p_bevenergie.name = "BEV Energie";
  p_bevenergie.price_monthly = 17.78;
  p_bevenergie.price_kwh = 0.2455;
  p_bevenergie.bonus = 185;
  p_emmaenergie.name = "EMMA Energie";
  p_emmaenergie.price_monthly = 11.50;
  p_emmaenergie.price_kwh = 0.2489;
  p_emmaenergie.bonus = 240;
  p_vattenfall.name = "Vattenfall";
  p_vattenfall.price_monthly = 12.40;
  p_vattenfall.price_kwh = 0.2532;
  p_vattenfall.bonus = 275;
  p_enerswitch.name = "enerSwitch";
  p_enerswitch.price_monthly = 11.85;
  p_enerswitch.price_kwh = 0.2423;
  p_enerswitch.bonus = 230;
  p_123energie.name = "123energie";
  p_123energie.price_monthly = 13.86;
  p_123energie.price_kwh = 0.2441;
  p_123energie.bonus = 250;
  p_rheinpower.name = "RHEINPOWER";
  p_rheinpower.price_monthly = 13.10;
  p_rheinpower.price_kwh = 0.2477;
  p_rheinpower.bonus = 241;
}
