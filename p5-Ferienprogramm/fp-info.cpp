#include "fp-info.h"

using namespace std;

void Ferienprogramm::buchungsListeAnzeigen(){
  int anId;
  cout << "Id des Angebotes?" << endl;
  cin >> anId;

  Angebot* angebot = getById(anId);
  vector<Kind*> buchungen = angebot->getTeilnehmer();

  cout << endl << "KW" << angebot->getKw() << " #" << angebot->getId() << " - " << angebot->getTitel() << endl;
  cout << "----------------------------------------------------" << endl;
  for (vector<Kind*>::iterator i = buchungen.begin(); i < buchungen.end(); i++){
      cout
          << setw(5) << (**i).getId()
          << setw(15) << (**i).getNachname()
          << setw(15) << (**i).getVorname()
          << setw(15) << (**i).getGeburtsdatum()
          << endl;
    }
  cout << "Es sind noch " << angebot->freiePlaetze() << "Plaetze frei"
       << endl
       << "----------------------------------------------------"
       << endl << endl << endl;
};

void Ferienprogramm::angeboteAnzeigen(){
  cout << endl
       << "----------------------------------------------------"
       << endl << "Angebotsliste" << endl;

  for (Angebot* an : angebotsListe){
      cout << endl
           << setw(2) << an->getId() << " :"
           << "KW:" << "[" << an->getKw() << "]"
           << setw(15) << an->getTitel()
           << setw(3) << " - "
           << setw(2) << an->freiePlaetze()
           << setw(5) << " von "
           << setw(2) << an->getPlaetze()
           << " Plaetze frei";

    }
  cout << endl
       << "----------------------------------------------------"
       << endl;;
};
