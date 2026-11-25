#include "Zwierze.h"
#include <iostream>

using namespace std;

Zwierze::Zwierze() // konstruktor domyślny z listą inicjalizacyjną
 : id(0), imie("Bezimmienny"), glod(50), szczescie(50), energia(50), zdrowie(true), zyje(true), wiek(1), dniChoroby(0) {}

Zwierze::Zwierze(int id, const string& imie) // konstruktor parametryczny
    : id(id), imie(imie) , glod(50), szczescie(50), energia(50), zdrowie(true), zyje(true), wiek(1), dniChoroby(0) {}

int Zwierze::getId() const{ return id;}
string Zwierze::getImie() const{return imie;}
int Zwierze::getGlod() const{return glod;}
int Zwierze::getSzczescie() const {return szczescie;}
int Zwierze::getEnergia() const { return energia;}
bool Zwierze::getZdrowie() const { return zdrowie;}
bool Zwierze::czyZyje() const {return zyje;}
int Zwierze::getWiek() const {return wiek;}


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

void Zwierze::ulecz(){
    if(!zyje) return;
    zdrowie = true;
    dniChoroby = 0;
    setEnergia(energia + 20);
}

void Zwierze::sprawdzStanPoDniu(){
    if(!zyje) return;

    wiek++;
    if(wiek > getMaxWiek()){
        zyje = false; //smierc ze starosci
        return;
    }

    if(!zdrowie){
        dniChoroby++;
        if(dniChoroby >= 2){
            zyje=false; // smierc z powodu dwudniowej choroby
        }

    } else {
        dniChoroby =0;
    }
}



bool Zwierze::operator==(const Zwierze& inne)const{
    return this->id == inne.id;
}

bool Zwierze::operator<(const Zwierze& inne)const{
    return this->glod < inne.glod;
}

ostream& operator<<(ostream& os, const Zwierze& z){
    os << "[" << z.getGatunek() << "] ID: " << z.id
       << "| Imie: " << z.imie
       << "| Głód: " << z.glod
       << "| Szczęście: " << z.szczescie << "/100"
       << "| Energia: " << z.energia << "/100"
       << "| Wiek: " << z.wiek << "/" << z.getMaxWiek()
       << "| Stan: " << (!z.zyje ? "MARTWE [R.I.P] [*]" : (z.zdrowie ? "Zdrowe <3" : "CHORE!!!"));
    return os;
}