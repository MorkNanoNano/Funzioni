#include <iostream>
#include <fstream>
#include <cmath>
#include "funzioni.h"

double eta(particella part) {
    return 0.5 + log((part.p[0] + part.p[3])/(part.p[0]-part.p[3]));
}

using namespace std;
int main(){

    fstream infile;
    infile.open("particelle.dat",ios::in);
    if(!infile.good())
        throw runtime_error("Error...");
    
    Vector list;
    cout << list.len << endl;
    particella p;
    for (;;) {
        if (infile.eof()) break;
        particella t;
        infile >> t.p[0] >> t.p[1] >> t.p[2] >> t.p[3] >> t.carica;
        list.append(t);
    }
    cout << list.len << endl;
    //for (int i=0; i<list.len; i++) cout << list.arr[i].p[0] << endl;
    //list.val(0);
    list.sort(&eta, false);
    for (int i=0; i<list.len; i++) cout << list.arr[i].p[0] << endl;


    return 0;
}
