#include <iostream>

using namespace std;


class Material{
private:
  int matNumber;
  string matText;
  int stock;
public:
  Material(int number, string text, int stk)
    : matNumber(number), matText(text), stock(stk){
  }
  void changeStock(int stk){
    stock = stk;
  };
};

class Warehouse{
private:
  static const int maxBins = 840;
  int storageBins[maxBins];
  Material material;
public:
  Warehouse()
    : material(Material(1,"Daemmstoff_16cm",0)){
  };
  void goodsReceipt(){

  };
  void goodsIssue(){

  };

};



int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
