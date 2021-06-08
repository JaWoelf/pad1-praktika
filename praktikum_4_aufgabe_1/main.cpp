#include <iostream>
#include <string.h>
#include "func_one.h"
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


int search_result;
string selection;
double input;
double result;


stromanbieter BEV_Energie{};
stromanbieter EMMA_Energie{};
stromanbieter Vattenfall{};
stromanbieter ener_switch{};
stromanbieter Energie_123{};
stromanbieter Rheinpower{};





double price_calculation(struct stromanbieter single_anbieter[], int len){
    cout << "-----------------" << endl;
    cout << "price_calculation" << endl;

    for(int i = 0; i < len; i++){
        single_anbieter[i].result = ((12*single_anbieter[i].mtl_fixkosten) + (input * single_anbieter[i].price)) - single_anbieter[i].bonus;
        cout << single_anbieter[i].name<< ", " << single_anbieter[i].result << "; ";
    }
    cout << endl;

    return 0;
}




double sort_name(struct stromanbieter single_anbieter[], int len){
    cout << "--------------" << endl;
    cout << "filter names" << endl;


    // Sorting strings using bubble sort
    for (int j=0; j<len-1; j++)
    {
        for (int i=j+1; i<len; i++)
        {
            if (strcmp(single_anbieter[j].name, single_anbieter[i].name) > 0)
            {
                char* temp = single_anbieter[j].name;
                strcpy(single_anbieter[j].name, single_anbieter[i].name);
                strcpy(single_anbieter[i].name, temp);

            }
            //cout << single_anbieter[i].name << endl;
        }
    }



    cout << single_anbieter[0].name << endl;
    cout << single_anbieter[1].name << endl;
    cout << single_anbieter[3].name << endl;
    return 0;
}


double sort_results(struct stromanbieter single_anbieter[], int len){
    cout << "--------------" << endl;
    cout << "filter results" << endl;

    bool swapped;
    do {
        swapped = false;
        for (int count = 0; count < (len-1); count++){
            if (single_anbieter[count].result > single_anbieter[count +1].result ){
                swap(single_anbieter[count], single_anbieter[count +1]);
                swapped = true;
            }
        }

    } while (swapped);

    //for (int i = 0; i < len; i++){
        //for (int j = len -1; j >=i; j--){

            //if (single_anbieter[j -1].result > single_anbieter[j].result){

                //int tmp = single_anbieter[j - 1].result;

                //int tmp = single_anbieter[j - 1].result;
                //single_anbieter[j -1].result = single_anbieter[j].result;
                //single_anbieter[j].result = tmp;
            //}
        //}
    //}

    return 0;
}


int binary_search(struct stromanbieter single_anbieter[], int len){




}

void user_selection(){
    cout << "Bitte trage dem Namen deines zukuenftigen Stromanbieters ein." << endl;
    cin >> selection;
}


void output(struct stromanbieter single_anbieter[], int len){
    cout << "--------------" << endl;
    cout << "output" << endl;

    for (int i = 0; i < len; i++){
        cout << single_anbieter[i].name << ", ";
        cout << single_anbieter[i].result << "; ";
    }
    cout << endl;
}


void process_user_input(){
    cout << "Bitte den Jahresverbrauch in kWH eintragen:" << endl;
    cin >> input;
}


void compute(struct stromanbieter single_anbieter[], size_t len){
    cout << "compute" << endl;
    result = price_calculation(single_anbieter, len);
    sort_results(single_anbieter, len);




}

void init_data(struct stromanbieter single_anbieter[], int len){
    //stromanbieter single_anbieter[6];

    //You can't assign to an array, only copy to it.
    strcpy(single_anbieter[0].name,"BEV_Energie");
    single_anbieter[0].mtl_fixkosten= 17.78;
    single_anbieter[0].price= 0.2455;
    single_anbieter[0].bonus= 185;
    single_anbieter[0].result= 0;

    strcpy(single_anbieter[1].name,"EMMA_Energie");
    single_anbieter[1].mtl_fixkosten= 11.50;
    single_anbieter[1].price= 0.2489;
    single_anbieter[1].bonus= 240;
    single_anbieter[1].result= 0;


    strcpy(single_anbieter[2].name,"Vattenfall");
    single_anbieter[2].mtl_fixkosten= 12.40;
    single_anbieter[2].price= 0.2532;
    single_anbieter[2].bonus= 275;
    single_anbieter[2].result= 0;


    strcpy(single_anbieter[3].name,"ener_switch");
    single_anbieter[3].mtl_fixkosten= 11.85;
    single_anbieter[3].price= 0.2423;
    single_anbieter[3].bonus= 230;
    single_anbieter[3].result= 0;


    strcpy(single_anbieter[4].name,"Energie_123");
    single_anbieter[4].mtl_fixkosten= 13.86;
    single_anbieter[4].price= 0.2441;
    single_anbieter[4].bonus= 250;
    single_anbieter[4].result= 0;

    strcpy(single_anbieter[5].name,"Rheinpower");
    single_anbieter[5].mtl_fixkosten= 13.10;
    single_anbieter[5].price= 0.2477;
    single_anbieter[5].bonus= 241;
    single_anbieter[5].result= 0;

}

int main()
{
    stromanbieter single_anbieter[6];
    //while (true) {
        process_user_input();

        init_data(single_anbieter, sizeof(single_anbieter) / sizeof(*single_anbieter));

        compute(single_anbieter, sizeof(single_anbieter) / sizeof(*single_anbieter));

        output(single_anbieter, sizeof(single_anbieter) / sizeof(*single_anbieter));

        sort_name(single_anbieter, sizeof(single_anbieter) / sizeof(*single_anbieter));

        user_selection();


        search_result= binary_search(single_anbieter, sizeof(single_anbieter) / sizeof(*single_anbieter));

        if (search_result == -1){
            cout << "Dieser Anbieter existiert nicht." << endl;
        } else {
            cout << "Sie haben sich fuer Anbieter '" << search_result << "' entschieden. Der Jahrespreis betraegt " << " Euro." << endl;
        }
    //}



    return 0;
}
