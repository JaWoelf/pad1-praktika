#include "fp-helper.h"

using namespace std;


Angebot* Ferienprogramm::getById(int id){
  for (vector<Angebot*>::iterator i = angebotsListe.begin(); i < angebotsListe.end(); i++){
     if ((**i).getId() == id)
       return (*i);
  }
  return nullptr;
};



Kind* Ferienprogramm::getById(long id){
  for (vector<Kind*>::iterator i = kinderListe.begin(); i < kinderListe.end(); i++){
     if ((**i).getId() == id)
       return (*i);
  }
  return nullptr;
};



void Ferienprogramm::testDaten(){
  Kind* kind = new Kind("Klaus","Kleber","1955_09_02");
  kinderListe.push_back(kind);
  kind = new Kind("Gundula", "Gause", "1965_04_30");
  kinderListe.push_back(kind);
  kind = new Kind("Steffen","Seibert","1960_06_07");
  kinderListe.push_back(kind);
  kind = new Kind("Martina","Fietz","1959_11_22");
  kinderListe.push_back(kind);
  kind = new Kind("Ulrike","Demmer","1973_04_03");
  kinderListe.push_back(kind);

  Angebot* angebot = new Angebot("Bogenschießen",12,26);
  angebotsListe.push_back(angebot);
  angebot = new Angebot("Topfschlagen",8,27);
  angebotsListe.push_back(angebot);
  angebot = new Angebot("Minigolf",15,28);
  angebotsListe.push_back(angebot);
  angebot = new Angebot("Wildtierpark",20,29);
  angebotsListe.push_back(angebot);

  angebotsListe[0]->kindAufnehmen(kinderListe[0]);
  angebotsListe[0]->kindAufnehmen(kinderListe[3]);
  angebotsListe[1]->kindAufnehmen(kinderListe[1]);
  angebotsListe[1]->kindAufnehmen(kinderListe[4]);
  angebotsListe[1]->kindAufnehmen(kinderListe[2]);
  angebotsListe[1]->kindAufnehmen(kinderListe[0]);
  angebotsListe[2]->kindAufnehmen(kinderListe[1]);
  angebotsListe[0]->kindAufnehmen(kinderListe[0]);

}

