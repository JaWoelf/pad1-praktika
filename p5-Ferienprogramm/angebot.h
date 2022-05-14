#ifndef ANGEBOT_H
#define ANGEBOT_H

#include <string>
#include <vector>
#include <kind.h>

class Angebot{
  int plaetze;
  std::string titel;
  int id;
  static int idCounter;
  std::vector<Kind*> teilnehmer;
  bool voll;
  int kw;
public:
  Angebot(std::string _titel, int _plaetze, int _kw)
    : plaetze(_plaetze), titel(_titel), id(idCounter++), voll(false), kw(_kw){};
  void kindAufnehmen(Kind* kind);
  void kindAbmelden(long id);
  int getId();
  int freiePlaetze();
  int getPlaetze();
  int getKw();
  bool istVoll();
  std::string getTitel();
  std::vector<Kind*> getTeilnehmer();
};

#endif // ANGEBOT_H
