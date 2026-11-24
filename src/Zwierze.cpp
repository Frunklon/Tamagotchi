#include "Zwierze.h"

using namespace std;

Zwierze::Zwierze() // konstruktor domyślny z listą inicjalizacyjną
 : id(0), imie("Bezimmienny"), glod(50), szczescie(50), energia(50), zdrowie(true) {}

Zwierze::Zwierze(int id, const string& imie) // konstruktor parametryczny
    : id(id), imie(imie) , glod(50), szczescie(50), energia(50), zdrowie(true){}

int Zwierze::getId() const{ return id;}
string Zwierze::getImie() const{return imie;}
int Zwierze::getGlod() const{return glod;}
int Zwierze::getSzczescie() const {return szczescie;}
int Zwierze::getEnergia() const { return energia;}
bool Zwierze::getZdrowie() const { return zdrowie;}

void Zwierze::setImie(const string& noweImie){
    if(!noweImie.empty()){
        imie = noweImie;
    }
}

void Zwierze::setGlod(int nowyGlod) {
    if(nowyGlod < 0) glod=0;
    else if (nowyGlod > 100) glod=100;
    else glod = nowyGlod;

    if(glod ==100){
        zdrowie = false; // full glod powoduje chorobe
    }
}

void Zwierze::setSzczescie(int noweSzczescie){
    if(noweSzczescie <0) szczescie =0;
    else if(noweSzczescie > 100) szczescie = 100;
    else szczescie = noweSzczescie;
}

void Zwierze::setEnergia(int nowaEnergia){
    if(nowaEnergia < 0) energia = 0;
    else if(nowaEnergia > 100) energia =100;
    else energia = nowaEnergia;

    if(energia == 0){
        zdrowie = false; // totalne wyczerpanie powoduje chorobe
    }
}

void Zwierze::setZdrowie(bool stan){
    zdrowie = stan;
}