#ifndef KOT_H
#define KOT_H

#include "Zwierze.h"

class Kot : public Zwierze{
    private:
        int poziomNiezaleznosci;

    public:
        Kot();
        Kot(int id, const std::string& imie, int poziomNiezaleznosci = 5);

        int getPoziomNiezaleznosci() const;
        
        void nakarm(int ilosc) override;
        void bawSie() override;
        void uplywDnia() override;
        std::string getGatunek() const override;
};

#endif