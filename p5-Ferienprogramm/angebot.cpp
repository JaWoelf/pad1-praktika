#include "angebot.h"

using namespace std;

int Angebot::idCounter = 0;

void Angebot::kindAufnehmen(Kind* kind){
  teilnehmer.push_back(kind);
  static int belegung = teilnehmer.size();
  voll = (belegung >= plaetze);
};

void Angebot::kindAbmelden(long id){
  for (vector<Kind*>::iterator i = teilnehmer.begin(); i < teilnehmer.end(); i++){
      if ((**i).getId() == id){
          teilnehmer.erase(i);
      };
  };
};

int Angebot::freiePlaetze(){
  return plaetze - teilnehmer.size();
};

int Angebot::getPlaetze(){
  return plaetze;
}

bool Angebot::istVoll(){
  return voll;
}

int Angebot::getId(){
  return id;
}

int Angebot::getKw(){
  return kw;
}

string Angebot::getTitel(){
  return titel;
}

vector<Kind*> Angebot::getTeilnehmer(){
  return teilnehmer;
};
