#include <iostream>
#include "Oprema.hpp"
using namespace std;
enum VRSTA_TEGA { SIPKA = 1, BUCICA };
class Tegovi : public Oprema{
protected:
    int tezina;
    VRSTA_TEGA teg;
    int brTegova;
    float kvalitetTegova;
public:
    Tegovi() : Oprema() {
        tezina = 20;
        teg = SIPKA;
        brTegova = 60;
        kvalitetTegova = 75;
    }
    Tegovi(int t, VRSTA_TEGA v, int b, float k,int kvan,float kval) : Oprema(kvan,kval) {
        tezina = t;
        teg = v;
        brTegova = b;
        kvalitetTegova = k;
    }
    Tegovi(const Tegovi& t) : Oprema((Oprema)t) {
        tezina = t.tezina;
        teg = t.teg;
        brTegova = t.brTegova;
        kvalitetTegova = t.kvalitetTegova;
    }
    ~Tegovi() {}
    VRSTA_TEGA get_vrstaTega()const {
        return teg;
    }
    int get_tezinaTega()const {
        return tezina;
    }
    int get_brTegova()const {
        return brTegova;
    }
    float get_kvalitetTegova()const {
        return kvalitetTegova;
    }
    void set_vrstaTega(const VRSTA_TEGA& v) {
        teg = v;
    }
    void set_tezinaTega(const int t) {
        tezina = t;
    }
    void set_brTegova(const int b) {
        brTegova = b;
    }
    void set_kvalitetTegova(const float k) {
        kvalitetTegova = k;
    }
    DinString vratiTip(){
        if(teg == SIPKA){
            return " Sipka.";
        }
        else{
            return " Bucica.";
        }
    }
};
#endif
