#include <iostream>
#include "Pies.h"

using namespace std;

Pies::Pies() : Zwierze(), poziomWytresowania(1){}

Pies::Pies(int id, const string& imie, int poziomWytresowania)
    : Zwierze(id, imie), poziomWytresowania(poziomWytresowania){}

int Pies::getPoziomWytresowania() const {return poziomWytresowania;}

void Pies::nakarm(int ilosc){
    setGlod(getGlod() - ilosc);
    setSzczescie(getSzczescie() + 5);
    cout << getImie() << " Zjadł wszystko (nie ma nawet okruszka) \n";
    cout << "Aktualny głód: " << getGlod() << endl; 
}

void Pies::bawSie(){
    setSzczescie(getSzczescie() + 20);
    setEnergia(getEnergia() -15);
    setGlod(getGlod() + 10);
    poziomWytresowania++;
    cout << getImie() << "biegał wesoło po łące aportując piłkę \n";
    cout << "Poziom wytresowania: " << poziomWytresowania << endl;

}

void Pies::uplywDnia(){
    setGlod(getGlod() + 20);
    setSzczescie(getSzczescie() - 10);
    setEnergia(getEnergia() + 15);
}

string Pies::getGatunek() const{
    return "Pies";
}


