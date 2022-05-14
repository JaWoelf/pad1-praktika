#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Schiff{
private:
  string name;
  const int kapazitaet;
public:
  Schiff()
    : name("leer"), kapazitaet(0){
  };
  Schiff( string na, int ka)
    : name(na), kapazitaet(ka){
  };

  string getName(){
    return name;
  };
  int getKapazitaet(){
    return kapazitaet;
  };
};


class Fahrt{
private:
  string startOrt, zielOrt, abfahrt, ankunft;
  int ladung, frachtPreis, id;
  static int idCounter;
  Schiff schiff;
public:
  Fahrt(string so, string zo, string af, string an, int ld, int fp, string na, int ka){
    startOrt = so;
    zielOrt = zo;
    abfahrt = af;
    ankunft = an;
    ladung = ld;
    frachtPreis = fp;
    id = idCounter++;
    Schiff schiff = Schiff(na, ka);
  };
  string getStartOrt(){
    return startOrt;
  };
  string getZielOrt(){
    return zielOrt;
  };
  string getAbfahrt(){
    return abfahrt;
  }
  string getAnkunft(){
    return ankunft;
  }
  int getLadung(){
    return ladung;
  }
  int getFrachtPreis(){
    return frachtPreis;
  }
  Schiff getSchiff(){
    return schiff;
  }
  int getId(){
    return id;
  }

};



class Fahrtenbuch{
private:
  vector<Fahrt> fahrten;

public:
  bool fahrtAnlegen(string so, string zo, string af, string an, int ld, int fp, string na, int ka){
    if ( ld > ka )
      return false;
    else if ( !fahrtPruefen(af,an,na) ){
      cout << "\nSchiff im Zeitraum belegt.";
      return false;
    }

    Fahrt fahrt(so,zo,af,an,ld,fp,na,ka);
    fahrten.push_back(fahrt);
    return true;
  };

  void fahrtenAusgeben(){
    for (auto element : fahrten){
        cout << "\n Fahrt " << element.getId() << " von\t " << element.getStartOrt() << ",\t " << element.getAbfahrt() << " nach\t " << element.getZielOrt() << ",\t " << element.getAnkunft();
    }
  };

  bool fahrtPruefen(string neuAbfahrt, string neuAnkunft, string name){
    bool istFrei = true;
    for (auto element : fahrten){
        if (element.getSchiff().getName() == name){
            // ist früher zurück, oder startet später
            istFrei = (neuAnkunft < element.getAbfahrt() ) || ( neuAbfahrt > element.getAnkunft() );
        };
    };
    return istFrei;
  };
};






int main()
{
  int userinput;
  Fahrtenbuch log;
class
  while (true){

      cout << "\n\n1: Fahrt anlegen\n2: Fahrten ausgeben\n0: Programmende\n";
      cin >> userinput;


      switch(userinput){
        case(0):
          _Exit (EXIT_SUCCESS);
        case(1):{
          string so,zo,af,an,na;
          int ld,fp,ka;
          cout << "Abfahrt? (JJJJ_MM_DD)";
          cin >> af;
          cout << "Ankunft? (JJJJ_MM_DD)";
          cin >> an;
          cout << "Fahrt von? (Ortsname)";
          cin >> so;
          cout << "Fahrt nach? (Ortsname)";
          cin >> zo;
          cout << "Menge? (Containerzahl)";
          cin >> ld;
          cout << "Frachtpreis? (Euro ohne Cent)";
          cin >> fp;
          cout << "Schiffsname? ";
          cin >> na;
          cout << "Schiffs-Kapazitaet? (Containerzahl)";
          cin >> ka;
          if (log.fahrtAnlegen(so,zo,af,an,ld,fp,na,ka))
            cout << "\nFahrt wurde angelegt.";
          else
            cout << "\nKonfiguration fehlerhaft, Fahrt nicht angelegt.";
          break;
        }
        case(2):{
           log.fahrtenAusgeben();
           break;
        }//case(2)
      }//switch


    }// while true
}
