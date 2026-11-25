#ifndef KON_H
#define KON_H

#include "Zwierze.h"

class Kon : public Zwierze{
    private:
        int szybkoscGalopu;

    public:
        Kon();
        Kon(int id, const std::string& imie, int szybkoscGalopu = 30);

        int getSzybkoscGalopu() const;

        void nakarm(int ilosc) override;
        void bawSie() override;
        void uplywDnia() override;
        std::string getGatunek() const override;

};
#endif