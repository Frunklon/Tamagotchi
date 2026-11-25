#ifndef ZWIERZE_H
#define ZWIERZE_H

#include <string>
#include <iostream>

class Zwierze{
    private:
        int id;
        std::string imie;
        int glod; 
        int szczescie;
        int energia;
        bool zdrowie;
        bool zyje;
        int wiek;
        int dniChoroby;

    protected:
        void sprawdzStanPoDniu();


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
        bool czyZyje() const;
        int getWiek() const;

        //settery
        void setImie(const std::string& noweImie);
        void setGlod(int nowyGlod);
        void setSzczescie(int noweSzczescie);
        void setEnergia(int nowaEnergia);
        void setZdrowie(bool stan); 
        void ulecz();

        virtual void nakarm(int ilosc) = 0;
        virtual void bawSie() = 0;
        virtual void uplywDnia() = 0;
        virtual std::string getGatunek() const=0;
        virtual int getMaxWiek() const = 0;
        virtual void rysuj() const =0;


        bool operator==(const Zwierze& inne) const;
        bool operator<(const Zwierze& inne) const;
        friend std::ostream& operator<<(std::ostream& os, const Zwierze& z);
};
#endif