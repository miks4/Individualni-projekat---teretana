#include <iostream>
#include "Oprema.hpp"
using namespace std;
enum VRSTA_FITNES_OPREME { STRUNJACA = 1, LOPTA, DZAK, GUMA };
class FitnesOprema : public Oprema{
protected:
    VRSTA_FITNES_OPREME vrstaFitnesOpreme;
    float amortizacija;
    int brFitnesOpreme;
    float kvalitetFitnesOpreme;
    DinString nabavljena;
    DinString garancija;
public:
    FitnesOprema() : Oprema() {
        vrstaFitnesOpreme = STRUNJACA;
        amortizacija = 2;
        brFitnesOpreme = 40;
        kvalitetFitnesOpreme = 80;
        nabavljena = "1.1.2020";
        garancija = "1.1.2021";
    }
    FitnesOprema(VRSTA_FITNES_OPREME v, float a, int b, float k,DinString n,DinString g,int kvan,float kval) : Oprema(kvan,kval) {
        vrstaFitnesOpreme = v;
        amortizacija = a;
        brFitnesOpreme = b;
        kvalitetFitnesOpreme = k;
        nabavljena = n;
        garancija = g;
    }
    FitnesOprema(const FitnesOprema& f) : Oprema((Oprema)f) {
        vrstaFitnesOpreme = f.vrstaFitnesOpreme;
        amortizacija = f.amortizacija;
        brFitnesOpreme = f.brFitnesOpreme;
        kvalitetFitnesOpreme = f.kvalitetFitnesOpreme;
        nabavljena = f.nabavljena;
        garancija = f.garancija;
    }
    ~FitnesOprema() {}
    VRSTA_FITNES_OPREME get_vrstaFitnesOpreme()const {
        return vrstaFitnesOpreme;
    }
    float get_amortizacija()const {
        return amortizacija;
    }
    int get_brFitnesOpreme()const {
        return brFitnesOpreme;
    }
    float get_kvalitetFitnesOpreme()const {
        return kvalitetFitnesOpreme;
    }
    DinString get_nabavljena()const{
        return nabavljena;
    }
    DinString get_garancija()const{
        return garancija;
    }
    void set_vrstaFitnesOpreme(const VRSTA_FITNES_OPREME v) {
        vrstaFitnesOpreme = v;
    }
    void set_amortizacija(const float a) {
        amortizacija = a;
    }
    void set_brFitnesOpreme(const int b) {
        brFitnesOpreme = b;
    }
    void set_kvalitetFitnesOpreme(const float k) {
        kvalitetFitnesOpreme = k;
    }
    void set_naavljena(const DinString n){
        nabavljena = n;
    }
    void set_garancija(const DinString g){
        garancija = g;
    }
    DinString vratiTip(){
        if(vrstaFitnesOpreme == STRUNJACA){return " Strunjaca.";}
        else if(vrstaFitnesOpreme == LOPTA){return " Lopta.";}
        else if(vrstaFitnesOpreme == DZAK){return " DZak.";}
        else{return " Guma.";}
    }
};
#endif
