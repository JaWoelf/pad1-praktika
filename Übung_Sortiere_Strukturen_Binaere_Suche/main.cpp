#include <iostream>
#include <vector>
using namespace std;


int n = 0;
enum Studiengang{Bachelor, KOSI, Master, KITS};
struct Studierende{
    string vorname;
    string nachname;
    string matrikelNummer;
    Studiengang studiengang;
};
Studierende studierende;
vector<Studierende> alleStudierenden;

/*
 *  INPUT FUNCTION
 */
void input() {
    cout << "Vorname: ";
    cin >> studierende.vorname;
    cout << "Nachname: ";
    cin >> studierende.nachname;
    cout << "MatrikelNr.: ";
    cin >> studierende.matrikelNummer;
    cout << "Studiengang: 0 fuer Bachelor, 1 fuer KOSI, 2 fuer Master, 3 fuer KITS" << endl;
    int studiengangsNummer;
    cin >> studiengangsNummer;

    switch(studiengangsNummer){
    case 0: studierende.studiengang=Bachelor;
        break;
    case 1: studierende.studiengang=KOSI;
        break;
    case 2: studierende.studiengang=Master;
        break;
    case 3: studierende.studiengang=KITS;
        break;
    default:{
        cout << "Bitte ganze Zahl zwischen 0 und 3 eingeben" << endl;
        return;
    }
    }
    alleStudierenden.push_back(studierende);

    cout << "Mehr Teilnehmer erfassen ('J', 'N')?" << endl;
    char weiter;
    cin >> weiter;
    if (weiter == 'N')
        return;
    else
      input();
}

/*
 *   SORTING FUNCTION
 */
void sort()
{
  // Sortieren
  for (int i = 1; i < n; i++) {// n-1 Durchläufe
      for (int j = n - 1; j >= i; j--) {// variable Anzahl von Schritten in 								      // einem Durchlauf
          if (alleStudierenden[j - 1].nachname > alleStudierenden[j].nachname) { // vertauschen zweier Elemente falls noetig
              Studierende tmp = alleStudierenden[j - 1];
              alleStudierenden[j - 1] = alleStudierenden[j];
              alleStudierenden[j] = tmp;
          }
      }
  }
}

/*
 *  SEARCH FUNCTION
 */
void search(){
  string suchname;
  cout << "Geben Sie den Suchnamen ein!" << endl;
  cin >> suchname;

  int left = 0,
      right = alleStudierenden.size()-1,
      mid=0;
  bool found = false;
  int pos = -1;

  while (left <= right) {
      mid = (left + right)/2; // Intervall-Mitte bestimmen
      if (suchname < alleStudierenden[mid].nachname)
          right = mid - 1;
      else if (suchname > alleStudierenden[mid].nachname)
          left = mid + 1;
      else { // gefunden
          found = true;
          pos = mid;
          break;
      }
  }

  if (!found)
      cout << "Name nicht vorhanden!" << endl;
  else
      cout << "Name liegt an Stelle " << pos << endl;


}

/*
 *  OUTPUT FUNCTION
 */
void output(unsigned int from, unsigned int to)
{
  for (unsigned int i=from; i <= to; i++){

      // Gebe Detaildaten aus:
      cout << "Vorname: " << alleStudierenden[i].vorname << endl;
      cout << "Nachname: " << alleStudierenden[i].nachname << endl;
      cout << "MatrikelNr.: " << alleStudierenden[i].matrikelNummer << endl;
      cout << "Studiengang: ";
      switch(alleStudierenden[i].studiengang){
      case Bachelor: cout << "Bachelor" << endl;
          break;
      case KOSI: cout << "KOSI" << endl;
          break;
      case Master: cout << "Master" << endl;
          break;
      case KITS: cout << "KITS" << endl;
          break;
      default:
          cout << "Unbekannt" << endl;
      }
  }
}


/*
 *  MAIN FUNCTION
 */
int main()
{


    input();
    n = alleStudierenden.size();
    sort();


    cout << "Eintrag suchen (Name eingeben) oder Liste ausgeben (Zwei aufeinander folgende Indizes eingeben)\n";
    cin >>

    output(0,2);
    search();



    return 0;
}


