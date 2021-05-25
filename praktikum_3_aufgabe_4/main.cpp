#include <iostream>
#include <ctime>


using namespace std;

int main()
{
    srand (time(NULL));
    int x=0;
    int input;

    bool start=false;


    cout << "DFB Team Generator" << endl;
    cout << "Type 1 to start" << endl;
    cin >> input;

    if (input == 1){
        start= true;
    }

    while(start){
        string team[4][8] = {
            {"Neuer", "ter Stegen", "Trapp"},
            {"Klostermann", "Ginter", "Can", "Gosens", "Ruediger", "Halstenberg", "Suele"},
            {"Kimmich", "Can", "Havertz", "Goretzka", "Guendogan", "Kroos", "Mueller", "Neuhaus"},
            {"Gnabry","Younes","Werner", "Sane"}
        };

        string sel_tor[1]= {};
        string sel_abwehr[4]= {};
        string sel_mittelfeld[4]= {};
        string sel_angriff[2]= {};



        //pick players
        for(int i = 0; i < 4; i++){
            //tor
            if (i == 0){
                sel_tor[i] = team[i][rand()%3];
            }

            //abwehr
            if (i == 1){
                for (int j = 0; j < 4; j++){
                    int random = rand()%(7);
                    string selected_player = team[i][random];
                    sel_abwehr[j] = selected_player;

                    team[i][random] = "none";

                    if (selected_player == "none"){
                        do {
                            random = rand()%(7);
                            selected_player = team[i][random];
                            sel_abwehr[j] = selected_player;
                            team[i][random] = "none";
                        }
                        while(selected_player == "none");
                    }
                }
            }

            //mittelfeld
            if (i == 2){
                for (int j = 0; j < 4; j++){
                    int random = rand()%(8);
                    string selected_player = team[i][random];
                    sel_mittelfeld[j] = selected_player;

                    team[i][random] = "none";

                    if (selected_player == "none"){
                        do {
                            random = rand()%(8);
                            selected_player = team[i][random];
                            sel_mittelfeld[j] = selected_player;
                            team[i][random] = "none";
                        }
                        while(selected_player == "none");
                    }
                }
            }

            //angriff
            if (i == 3){
                for (int j = 0; j < 2; j++){
                    int random = rand()%(4);
                    string selected_player = team[i][random];
                    sel_angriff[j] = selected_player;

                    team[i][random] = "none";

                    if (selected_player == "none"){
                        do {
                            random = rand()%(4);
                            selected_player = team[i][random];
                            sel_angriff[j] = selected_player;
                            team[i][random] = "none";
                        }
                        while(selected_player == "none");
                    }
                }
            }
        }


        cout << "Tor: " << sel_tor[0] << endl;
        cout << "Abwehr: " << sel_abwehr[0]<< ", "<< sel_abwehr[1]<< ", "<< sel_abwehr[2]<< ", "<< sel_abwehr[3]<< endl;
        cout << "Mittelfeld: " << sel_mittelfeld[0]<< ", " << sel_mittelfeld[1]<< ", " << sel_mittelfeld[2]<< ", "<< sel_mittelfeld[3]<< endl;
        cout << "Angriff: " << sel_angriff[0]<< ", "<< sel_angriff[1] << endl;

        cout << "Es sind " <<  x << " verschiedene Aufstellungen moeglich." << endl;





        input = -1;
        cout << "\nAbbrechen mit 0, Neue Aufstellung mit 1\n\n" << endl;
        cin >> input;
        if (input == 0){
            cout << "Exit."<<endl;
            return 0;
        }
    }


    return 0;
}
