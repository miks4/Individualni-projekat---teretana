#include <iostream>

using namespace std;
enum VRSTA_FITNES_OPREME { STRUNJACA = 1, LOPTA, DZAK, GUMA };
class FitnesOprema {
protected:
    VRSTA_FITNES_OPREME vrstaFitnesOpreme;
    int amortizacija;
    int brFitnesOpreme;
    float kvalitetFitnesOpreme;
public:
    FitnesOprema() {
        vrstaFitnesOpreme = STRUNJACA;
        amortizacija = 2;
        brFitnesOpreme = 40;
        kvalitetFitnesOpreme = 80;
    }
    FitnesOprema(VRSTA_FITNES_OPREME v, int a, int b, float k) {
        vrstaFitnesOpreme = v;
        amortizacija = a;
        brFitnesOpreme = b;
        kvalitetFitnesOpreme = k;
    }
    FitnesOprema(const FitnesOprema& f) {
        vrstaFitnesOpreme = f.vrstaFitnesOpreme;
        amortizacija = f.amortizacija;
        brFitnesOpreme = f.brFitnesOpreme;
        kvalitetFitnesOpreme = f.kvalitetFitnesOpreme;
    }
    ~FitnesOprema() {}
    VRSTA_FITNES_OPREME get_vrstaFitnesOpreme()const {
        return vrstaFitnesOpreme;
    }
    int get_amortizacija()const {
        return amortizacija;
    }
    int get_brFitnesOpreme()const {
        return brFitnesOpreme;
    }
    float get_kvalitetFitnesOpreme()const {
        return kvalitetFitnesOpreme;
    }
    void set_vrstaFitnesOpreme(const VRSTA_FITNES_OPREME v) {
        vrstaFitnesOpreme = v;
    }
    void set_amortizacija(const int a) {
        amortizacija = a;
    }
    void set_brFitnesOpreme(const int b) {
        brFitnesOpreme = b;
    }
    void set_kvalitetFitnesOpreme(const float k) {
        kvalitetFitnesOpreme = k;
    }
};

#endif
