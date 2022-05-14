#include "fp-angebot.h"

using namespace std;

void Ferienprogramm::angebotEintragen(){
  string title;
  int plaetze,kw;
  cout << "Titel des Angebotes?" << endl;
  cin >> title;
  cout << "Plaetze des Angebotes?" << endl;
  cin >> plaetze;
  cout << "Kalenderwoche?" << endl;
  cin >> kw;

  if ((kw < start) || (kw > ende )){
      cout << "Angebot muss innerhalb des Ferienprogrammes liegen." << endl;
      return;
  }

  Angebot* angebot = new Angebot(title,plaetze,kw);
  angebotsListe.push_back(angebot);
};

void Ferienprogramm::angebotLoeschen(){
  int input;
  cout << "ID des Angebotes?";
  cin >> input;
  for (vector<Angebot*>::iterator i = angebotsListe.begin(); i < angebotsListe.end(); i++){
      if ((**i).getId() == input){
          if ((**i).freiePlaetze() < (**i).getPlaetze()){
              cout << endl << "Angebot nicht leer.";
            }
          (**i).~Angebot();       // Deconstruct Object
          angebotsListe.erase(i); // Delete Pointer & Resize Vector
          delete (*i);
        };
  };
};
