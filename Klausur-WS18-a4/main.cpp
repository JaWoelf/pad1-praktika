#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Schiff{
private:
  string name;
  const int kapazitaet;
  static int idCounter;
  int id;
public:
  Schiff()
    : name("leer"), kapazitaet(0){
    id = ++idCounter;
  };
  Schiff( string na, int ka)
    : name(na), kapazitaet(ka), id(idCounter++){
  };

  string getName(){
    return name;
  };
  int getKapazitaet(){
    return kapazitaet;
  };
  int getId(){
    return id;
  }
};
int Schiff::idCounter;
vector<Schiff> schiffe;

class Fahrt{
private:
  string startOrt, zielOrt, abfahrt, ankunft;
  int ladung, frachtPreis, id;
  static int idCounter;
  Schiff schiff;
public:
  Fahrt(string so, string zo, string af, string an, int ld, int fp){
    startOrt = so;
    zielOrt = zo;
    abfahrt = af;
    ankunft = an;
    ladung = ld;
    frachtPreis = fp;
    id = idCounter++;
    Schiff schiff;
  };
  Fahrt(string so,string zo,string af, string an, int ld, int fp, int nr){
    startOrt = so;
    zielOrt = zo;
    abfahrt = af;
    ankunft = an;
    ladung = ld;
    frachtPreis = fp;
    id = idCounter++;
    Schiff schiff = schiffe[nr];
  }
  Fahrt(const Fahrt& _fahrt)
    : id(_fahrt.id){
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
int Fahrt::idCounter;


class Fahrtenbuch{
private:
  vector<Fahrt> fahrten;

public:
  bool fahrtAnlegen(string so, string zo, string af, string an, int ld, int fp, int id){
    if (!istSchiff(id)){
        cout << "\nSchiff existiert nicht.";
        return false;
    } else if (!istKapazitaet(id,ld)){
        cout << "\nSchiff wäre überladen";
        return false;
    } else if (!istSchiffFrei(af,an,id)){
        cout << "\nSchiff im Zeitraum belegt";
        return false;
    } else {
        Fahrt fahrt(so,zo,af,an,ld,fp);
        fahrten.push_back(fahrt);
        return true;
    }
  };

  void fahrtenAusgeben(){
    for (auto fahrt : fahrten){
        cout << "\n Fahrt " << fahrt.getId() << " von\t " << fahrt.getStartOrt() << ",\t " << fahrt.getAbfahrt() << " nach\t " << fahrt.getZielOrt() << ",\t " << fahrt.getAnkunft();
    }
  };

  bool istSchiff(int id){
    for (auto schiff : schiffe){
         if (schiff.getId() == id)
           return true;
    }
    return false;
  }

  bool istKapazitaet(int id, int ld){
    for (auto schiff : schiffe){
        if ( schiff.getId() == id )
          return ( schiff.getKapazitaet() >= ld ) ;
    };
    return false;
  };

  bool istSchiffFrei(string neuAbfahrt, string neuAnkunft, int id){
    bool istFrei = true;
    for (auto fahrt : fahrten){
        if (fahrt.getSchiff().getId() == id){
            // ist früher zurück, oder startet später
            istFrei = (neuAnkunft < fahrt.getAbfahrt() ) || ( neuAbfahrt > fahrt.getAnkunft() );
        };
    };
    return istFrei;
  };

  void umsatzListe(){

      // Per schiff, summiere umsätze aller fahrten.
      struct umsatz{string schiffsname; int umsatz;};
      vector<umsatz> umsaetze;
      for (auto schiff : schiffe){
          umsaetze.push_back({schiff.getName(),0});
          for (auto fahrt : fahrten){
              if (fahrt.getSchiff().getId() == schiff.getId())
                  umsaetze.back().umsatz += fahrt.getFrachtPreis();
          };
      };

      // sortiere umsaetze
      bool swapped;
      int size = umsaetze.size();
      for (int i = 0; i < size; i++ ){
          swapped = false;
          for ( int j = 0; j < size - i - 1; j++){
              if (umsaetze.at(j).umsatz > umsaetze.at(j+1).umsatz){
                    swap(umsaetze[j],umsaetze[j+1]);
              };
          }
          if (!swapped)
            break;
      }


      // sortiere Fahrten
      size = fahrten.size();
      fahrten.shrink_to_fit();
      for (int i = 0; i < size; i++ ){
          swapped = false;
          for ( int j = 0; j < size - i - 1; j++){
              // j > j+1
              if (fahrten.at(j).getFrachtPreis() > fahrten.at(j+1).getFrachtPreis()){
                  fahrten.insert(fahrten.begin(), j,fahrten[j+1]);
                  fahrten[j+2].~Fahrt();
                  fahrten.shrink_to_fit();
              };
          }
          if (!swapped)
            break;
      }

      // Ausgabe
      fahrtenAusgeben();
      for ( auto umsatz : umsaetze ){
          cout << "\n" << umsatz.schiffsname << ":\t" << umsatz.umsatz;
      }

  };
};









int main(){
  while (true){
      int userinput;
      Fahrtenbuch log;
      cout << "\n\n1: Fahrt anlegen\n2: Fahrten ausgeben\n3: Schiff anlegen\n4: Umsatzliste\n5: Testbefüllung\n0: Programmende\n";
      cin >> userinput;


      switch(userinput){
        case(0):
          _Exit (EXIT_SUCCESS);
        case(1):{
          string so,zo,af,an;
          int ld,fp,id;
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
          cout << "Schiffs-ID? ";
          cin >> id;
          if (log.fahrtAnlegen(so,zo,af,an,ld,fp,id))
            cout << "\nFahrt wurde angelegt.";
          else
            cout << "\nKonfiguration fehlerhaft, Fahrt nicht angelegt.";
          break;
        }
        case(2):{
             log.fahrtenAusgeben();
             break;
        }
        case(3):{
            string na;
            int ka;
            cout << "Schiffsname: ";
            cin >> na;
            cout << "Kapazität: ";
            cin >> ka;
            Schiff schiff(na,ka);
            schiffe.push_back(schiff);
            cout << "\nSchiff Nr. " << schiff.getId() << " angelegt";
            break;
        }
        case(4):{
            log.umsatzListe();
        }
        case(5):{
            schiffe.push_back(Schiff("Lorelei",100));
            schiffe.push_back(Schiff("Marry",120));
            schiffe.push_back(Schiff("Nophretete",85));
            log.fahrtAnlegen("Hamburg","Alexandria","2021_10_03","2021_11_01",199,308500,0);
            log.fahrtAnlegen("Alexandria","Rotterdam","2021_11_03","2021_11_27",92,271000,0);
            log.fahrtAnlegen("Rotterdam","Shanghai","2021_11_03","2020_01_13",97,112800,0);
            log.fahrtAnlegen("Dubai","Leam Chabang","2021_09_03","2021_11_01",120,2000000,1);
            log.fahrtAnlegen("Leam Chabang","Shenzen","2021_11_07","2021_12_27",109,271010,1);
            log.fahrtAnlegen("Shenzen","Los Angeles","2022_01_03","2022_05_27",78,1800000,1);
            log.fahrtAnlegen("Hamburg","Alexandria","2021_10_03","2021_11_01",81,308500,2);
            log.fahrtAnlegen("Alexandria","Rotterdam","2021_11_03","2021_11_27",80,271000,2);
            log.fahrtAnlegen("Rotterdam","Shanghai","2021_11_03","2021_11_27",78,112800,2);
        }
      }//switch


    }// while true
}

//  Test-Objekte
