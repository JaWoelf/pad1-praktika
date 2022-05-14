#ifndef FERIENPROGRAMM_H
#define FERIENPROGRAMM_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "kind.h"
#include "angebot.h"

class Ferienprogramm{
  std::vector<Angebot*> angebotsListe;
  std::vector<Kind*> kinderListe;
  int start,ende;
  Angebot* getById(int id); // existiert angebot mit id?
  Kind* getById(long id); //existiert kind mit id?
  void angebotEintragen();
  void angebotLoeschen();
  void angeboteAnzeigen();
  void kindAnmelden();
  void kindAbmelden();
  void kindZuAngebotAnmelden();
  void kindVonAngebotAbmelden();
  void buchungsListeAnzeigen();
  void testDaten();
public:
  Ferienprogramm(): start(26),ende(32){};
  void mainDialog();
};

#endif // FERIENPROGRAMM_H
