#ifndef PIES_H
#define PIES_H

#include "Zwierze.h"

class Pies : public Zwierze{
    private:
        int poziomWytresowania;

    public:
        Pies();
        Pies(int id, const std::string& imie, int poziomWytresowania = 1);

        int getPoziomWytresowania() const;

        void nakarm(int ilosc) override;
        void bawSie() override;
        void uplywDnia() override;
        std::string getGatunek() const override;


};
#endif