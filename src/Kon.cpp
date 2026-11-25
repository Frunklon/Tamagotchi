#include <iostream>
#include "Kon.h"

using namespace std;

Kon::Kon() : Zwierze(), szybkoscGalopu(30){}
Kon::Kon(int id, const string& imie, int szybkoscGalopu)
    : Zwierze(id,imie), szybkoscGalopu(szybkoscGalopu){}

int Kon::getSzybkoscGalopu() const{return szybkoscGalopu;}

void Kon::nakarm(int ilosc){
    setGlod(getGlod() - ilosc);
    setEnergia(getEnergia() +10);
    cout << getImie() << " zjadł spokojnie siano \n";
    cout << "Aktualny głod: " << getGlod() << endl;
}

void Kon::bawSie(){
    if(getEnergia() < 25){
        cout << getImie() << " jest zbyt zmęczony na trening w galopie :( \n";
        return;
    }
    setSzczescie(getSzczescie() + 20);
    setEnergia(getEnergia() - 20);
    setGlod(getGlod() + 15);
    szybkoscGalopu +=2;
    cout << getImie() << " galopował radośnie po zagrodzie \n";
    cout << "Szybkosc galopu wzrosła do: " << szybkoscGalopu << endl;

}

void Kon::uplywDnia() {
    setGlod(getGlod() + 25);
    setSzczescie(getSzczescie() - 10);
    setEnergia(getEnergia() + 25);
}

string Kon::getGatunek() const{
    return "Kon";
}
int Kon::getMaxWiek() const {return 25;}

void Kon::rysuj() const{
   cout << R"(
         /\  _,,,_  /\
        /  \/ / / \/  \
       / /\  / / /  /\ \
      | /  \/ / / \/  \ |
      |/               \|
      |   (o)     (o)   |
      |                 |
      |     .-----.     |
      |    / () () \    |
      |   |   \_/   |   |
       \   \ '---' /   /
        '.  '-----'  .'
         /|         |\
        / |         | \
       /  |         |  \
)" << endl;
}