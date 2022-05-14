#include "ferienprogramm.h"
#include "fp-kind.h"
#include "fp-info.h"
#include "fp-helper.h"

using namespace std;


void Ferienprogramm::mainDialog(){
  int input;
  cout
      << "Hauptmenü - Kinferferienprogramm" << endl
      << "----------------------------------------------------" <<endl
      << "   [1] Angebot anlegen" << endl
      << "   [2] Angebot löschen" << endl
      << "   [3] Kind    anlegen" << endl
      << "   [4] Kind    löschen" << endl
      << "   [5] Kind    zu Angebot anmelden" << endl
      << "   [6] Kind    von Angebot abmelden" << endl
      << "   [7] Info    Alle Angebote" << endl
      << "   [8] Info    Buchungslisten" << endl
      << "   [0] ENDE" << endl
      << " [111] TESTDATEN" << endl
      << "----------------------------------------------------" << endl;
  cin >> input;

  if ( (input < 0) || input > 8 )
    if ( input != 111 ){
        cout << "Fehlerhafte Eingabe" << endl;
        return;
      }

  switch(input){
    case(0):
      _Exit (EXIT_SUCCESS);
      break;
    case(1):
      this->angebotEintragen();
      break;
    case(2):
      this->angebotLoeschen();
      break;
    case(7):
      this->angeboteAnzeigen();
      break;
    case(3):
      this->kindAnmelden();
      break;
    case(4):
      this->kindAbmelden();
      break;
    case(5):
      this->kindZuAngebotAnmelden();
      break;
    case(6):
      this->kindVonAngebotAbmelden();
      break;
    case(8):
      this->buchungsListeAnzeigen();
      break;
    case(111):
      this->testDaten();
    default:
      return;
    }
};

