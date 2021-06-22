#include <iostream>
#include <string.h>
#include "func_one.h"
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


int search_result =0;
int search_index =0;
string selection, input_selection;
double input;
double result;

long long size;

stromanbieter BEV_Energie{};
stromanbieter EMMA_Energie{};
stromanbieter Vattenfall{};
stromanbieter ener_switch{};
stromanbieter Energie_123{};
stromanbieter Rheinpower{};





double get_price(struct stromanbieter single_anbieter[], int len){
    cout << "-----------------------------------" << endl;
    cout << "unordered list; price calculation:" << endl;
    cout << "-----------------------------------" << endl;

    for(int i = 0; i < len; i++){
        single_anbieter[i].result = ((12*single_anbieter[i].mtl_fixkosten) + (input * single_anbieter[i].price)) - single_anbieter[i].bonus;
        cout << single_anbieter[i].name<< ": " << single_anbieter[i].result << " Euro; \n";
    }
    cout << endl;

    return 0;
}




double sort_id(struct stromanbieter single_anbieter[], int len){
    // Sorting strings using bubble sort
    //for (int i=1; i<len; i++){
        //for (int j=len -1; j >= i; j--){
            //if (strcmp(single_anbieter[j-1].name, single_anbieter[j].name) >0){
                //struct stromanbieter temp = single_anbieter[j-1];
                //single_anbieter[j-1] = single_anbieter[j];
                //single_anbieter[j] = temp;

            //}
        //}
    //}

    bool swapped;
    do {
        swapped = false;
        for (int count = 0; count < (len-1); count++){
            if (single_anbieter[count].id > single_anbieter[count +1].id ){
                swap(single_anbieter[count], single_anbieter[count +1]);
                swapped = true;
            }
        }

    } while (swapped);


    return 0;
}


double sort_results(struct stromanbieter single_anbieter[], int len){
    cout << "-----------------------------------" << endl;
    cout << "filterd price (ascending)" << endl;

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


int binary_search(struct stromanbieter single_anbieter[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (single_anbieter[mid].id == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (single_anbieter[mid].id > x)
            return binary_search(single_anbieter, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binary_search(single_anbieter, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;


}

void user_selection(struct stromanbieter single_anbieter[], int len){
    cout << "\nBitte trage den Namen deines zukuenftigen Stromanbieters ein." << endl;
    cin >> input_selection;

    search_index =-1;

    for (int i = 0; i < len; i++){
        if (input_selection == single_anbieter[i].name){
            search_index = single_anbieter[i].id;
        }
    }

    if (search_index == -1){
        cout << "Dieser Anbieter existiert nicht." << endl;
        user_selection(single_anbieter, size);
    }


}


void output(struct stromanbieter single_anbieter[], int len){
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < len; i++){
        cout << single_anbieter[i].name << ": ";
        cout << single_anbieter[i].result << " Euro; \n";
    }
    cout << endl;
}


void process_user_input(){
    cout << "Bitte den Jahresverbrauch in kWH eintragen: ";
    cin >> input;
}


void compute(struct stromanbieter single_anbieter[], size_t len){
    result = get_price(single_anbieter, len);
    sort_results(single_anbieter, len);

}

void init_data(struct stromanbieter single_anbieter[]){
    //stromanbieter single_anbieter[6];

    //You can't assign to an array, only copy to it.
    strcpy(single_anbieter[0].name,"BEV_Energie");
    single_anbieter[0].mtl_fixkosten= 17.78;
    single_anbieter[0].price= 0.2455;
    single_anbieter[0].bonus= 185;
    single_anbieter[0].result= 0;
    single_anbieter[0].id= 0;

    strcpy(single_anbieter[1].name,"EMMA_Energie");
    single_anbieter[1].mtl_fixkosten= 11.50;
    single_anbieter[1].price= 0.2489;
    single_anbieter[1].bonus= 240;
    single_anbieter[1].result= 0;
    single_anbieter[1].id= 1;


    strcpy(single_anbieter[2].name,"Vattenfall");
    single_anbieter[2].mtl_fixkosten= 12.40;
    single_anbieter[2].price= 0.2532;
    single_anbieter[2].bonus= 275;
    single_anbieter[2].result= 0;
    single_anbieter[2].id= 2;


    strcpy(single_anbieter[3].name,"Ener_switch");
    single_anbieter[3].mtl_fixkosten= 11.85;
    single_anbieter[3].price= 0.2423;
    single_anbieter[3].bonus= 230;
    single_anbieter[3].result= 0;
    single_anbieter[3].id= 3;


    strcpy(single_anbieter[4].name,"Energie_123");
    single_anbieter[4].mtl_fixkosten= 13.86;
    single_anbieter[4].price= 0.2441;
    single_anbieter[4].bonus= 250;
    single_anbieter[4].result= 0;
    single_anbieter[4].id= 4;

    strcpy(single_anbieter[5].name,"Rheinpower");
    single_anbieter[5].mtl_fixkosten= 13.10;
    single_anbieter[5].price= 0.2477;
    single_anbieter[5].bonus= 241;
    single_anbieter[5].result= 0;
    single_anbieter[5].id= 5;

}


void process_result(struct stromanbieter single_anbieter[]){

    cout << "\nSie haben sich fuer Anbieter '" << single_anbieter[search_result].name << "' entschieden. Der Jahrespreis betraegt "<< single_anbieter[search_result].result << " Euro.\n\n\n\n" << endl;
}


int main()
{
    stromanbieter single_anbieter[6];
    while (true) {

        init_data(single_anbieter);
        size = sizeof(single_anbieter) / sizeof(*single_anbieter);

        process_user_input();
        compute(single_anbieter, size);

        output(single_anbieter, size);


        user_selection(single_anbieter, size);

        sort_id(single_anbieter, size);

        search_result= binary_search(single_anbieter, 0, size -1, search_index);


        process_result(single_anbieter);

    }



    return 0;
}
