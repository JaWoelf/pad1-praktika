#include "kind.h"

using namespace std;

long Kind::idCounter = 0;

long Kind::getId(){
  return id;
}

string Kind::getVorname(){
  return vorname;
}

string Kind::getNachname(){
  return nachname;
}

string Kind::getGeburtsdatum(){
  return geburtsdatum;
}
