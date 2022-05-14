#ifndef KIND_H
#define KIND_H

#include <string>

class Kind{
  long id;
  static long idCounter;
  std::string vorname;
  std::string nachname;
  std::string geburtsdatum;
public:
  Kind(std::string _vorname, std::string _nachname, std::string _geburtsdatum)
    : id(idCounter++),vorname(_vorname),nachname(_nachname),geburtsdatum(_geburtsdatum) {
  }; // allg. constr.
  long getId();
  std::string getVorname();
  std::string getNachname();
  std::string getGeburtsdatum();
};

#endif // KIND_H
