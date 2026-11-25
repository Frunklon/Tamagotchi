#include <iostream>
#include "Kot.h"

using namespace std;

Kot::Kot() : Zwierze(), poziomNiezaleznosci(5){}

Kot::Kot(int id , const string& imie, int poziomNiezaleznosci)
    : Zwierze(id, imie), poziomNiezaleznosci(poziomNiezaleznosci){}

int Kot::getPoziomNiezaleznosci() const{ return poziomNiezaleznosci; }

void Kot::nakarm(int ilosc) {
    setGlod(getGlod() - (ilosc - 2));
    cout << getImie() << " Kręcił się wokół miski i trochę zjadł \n";
    cout << "Aktualny głod: " << getGlod() << endl;

}

void Kot::bawSie(){
    if(getEnergia() < 30){
        cout << getImie() << " nie jest zainteresowany zabawką i ziewa (jest zbyt zmęczony)";
        return;
    }
    cout << getImie() << " biega za laserem \n";
    setSzczescie(getSzczescie() + 15);
    setEnergia(getEnergia() - 10);
    setGlod(getGlod() + 5);
    
}

void Kot::uplywDnia(){
    setGlod(getGlod() + 15);
    setSzczescie(getSzczescie() - 5);
    setEnergia(getEnergia() + 20);
}

string Kot::getGatunek() const {
    return "Kot";
}
int Kot::getMaxWiek() const {return 18;}

void Kot::rysuj() const{
    cout << R"(
      /\     /\
     /  \___/  \
    |   o   o   |
   --=\   v   /=--
    --=\ \_/ /=--
      /       \
     |  |   |  |
     (__|___|__)
    )" << endl;
}