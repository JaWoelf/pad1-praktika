#include "fp-kind.h"

using namespace std;


void Ferienprogramm::kindAnmelden(){
  string vor,nac,geb;
  cout << "Vorname des Kindes?" << endl;
  cin >> vor;
  cout << "Nachname des Kindes?" << endl;
  cin >> nac;
  cout << "Geburtsdatum des Kindes?" << endl;
  cin >> geb;

  Kind* kind = new Kind(vor,nac,geb);
  kinderListe.push_back(kind);
};

void Ferienprogramm::kindAbmelden(){
  long kiId;
  bool isFree;
  cout << "ID des Kindes?" << endl;
  cin >> kiId;

  // Check ob kind noch in angeboten ist
  // for angebotsliste
  //     for teilnehmer von angebot
  //          if teilnehmer.id = kiId -> Kind ist noch angemeldet.
  for (vector<Angebot*>::iterator i = angebotsListe.begin(); i < angebotsListe.end(); i++){
        vector<Kind*> kinder = (**i).getTeilnehmer();
        for (vector<Kind*>::iterator j = kinder.begin(); j < kinder.end() ; j++){
            if ((**j).getId() == kiId){
                isFree = false;
                cout << "Kind ist noch in Angebot " << (**i).getId() << " angemeldet" << endl;
            }
        }
  }

  if (not isFree)
    return;

  // Kind Objekt löschen
  // Pointer aus liste löschen
  for (vector<Kind*>::iterator i = kinderListe.begin(); i < kinderListe.end(); i++){
      (**i).~Kind();
      kinderListe.erase(i);
      delete (*i);
  };
};

void Ferienprogramm::kindZuAngebotAnmelden(){
  int anId;
  long kiId;
  cout << "ID des Angebotes?" << endl;
  cin >> anId;
  cout << "ID des Kindes?" << endl;
  cin >> kiId;

  Angebot* angebot = getById(anId);
  Kind* kind = getById(kiId);

  if (angebot == nullptr){
      cout << "Angebot existiert nicht" << endl;
      return;
  }else if (kind == nullptr){
      cout << "Kind existiert nicht" << endl;
      return;
  }else if (angebot->istVoll()){
      cout << "Angebot ist ausgebrucht" << endl;
      return;
  };

  angebot->kindAufnehmen(kind);
};

void Ferienprogramm::kindVonAngebotAbmelden(){
  int anId;
  long kiId;
  cout << "ID des Angebotes?" << endl;
  cin >> anId;
  cout << "ID des Kindes?" << endl;
  cin >> kiId;

  getById(anId)->kindAbmelden(kiId);
};
