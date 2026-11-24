#ifndef ZWIERZE_H
#define ZWIERZE_H

#include <string>

class Zwierze{
    private:
        int id;
        std::string imie;
        int glod; 
        int szczescie;
        int energia;
        bool zdrowie;

    public:
        Zwierze();
        Zwierze(int id, const std::string& imie);
        virtual ~Zwierze() = default;

        //gettery
        int getId() const;
        std::string getImie() const;
        int getGlod() const;
        int getSzczescie() const;
        int getEnergia() const;
        bool getZdrowie() const;

        //settery
        void setImie(const std::string& noweImie);
        void setGlod(int nowyGlod);
        void setSzczescie(int noweSzczescie);
        void setEnergia(int nowaEnergia);
        void setZdrowie(bool stan); 

        virtual void nakarm(int ilosc) = 0;
        virtual void bawSie() = 0;
        virtual void uplywDnia() = 0;
        virtual std::string getGatunek() const=0;

};
#endif