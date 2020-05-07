#ifndef SUPLEMENTI_HPP_INCLUDED
#define SUPLEMENTI_HPP_INCLUDED
#include <iostream>
enum VRSTA_SUPLEMENATA { PROTEIN = 1, KREATIN, AMINOKISELINA };
class Suplementi {
private:
    int cena;
    VRSTA_SUPLEMENATA suplement;
    static int brSUplemenata;
public:
    Suplementi() {
        cena = 150;
        suplement = PROTEIN;
        brSUplemenata++;
    }
    Suplementi(int c, VRSTA_SUPLEMENATA v) {
        cena = c;
        suplement = v;
    }
    Suplementi(const Suplementi& s) {
        cena = s.cena;
        suplement = s.suplement;
    }
    ~Suplementi() {brSUplemenata--;}
    int get_cena()const {
        return cena;
    }
    VRSTA_SUPLEMENATA get_suplement()const {
        return suplement;
    }

    void set_cena(const int c) {
        cena = c;
    }
    void set_suplement(const VRSTA_SUPLEMENATA v) {
        suplement = v;
    }
};

#endif // SUPLEMENTI_HPP_INCLUDED
