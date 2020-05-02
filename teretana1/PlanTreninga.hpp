
#include <iostream>

using namespace std;
enum VRSTA_TRENINGA { FITNES = 1, BODYWEIGHT, BODYBUILDING };
class PlanTreninga {
private:
    int kvalitet;
    int cena;
    int rok;
    VRSTA_TRENINGA vrstaTreninga;
public:
    PlanTreninga() {
        kvalitet = 90;
        cena = 20000;
        rok = 40;
        vrstaTreninga = FITNES;
    }
    PlanTreninga(int k, int c, int r, VRSTA_TRENINGA t) {
        kvalitet = k;
        cena = c;
        rok = r;
        vrstaTreninga = t;
    }
    PlanTreninga(const PlanTreninga& p) {
        kvalitet = p.kvalitet;
        cena = p.cena;
        rok = p.rok;
        vrstaTreninga = p.vrstaTreninga;
    }
    ~PlanTreninga() {}
    int get_kvalitet()const {
        return kvalitet;
    }
    int get_cena()const {
        return cena;
    }
    int get_rok()const {
        return rok;
    }
    VRSTA_TRENINGA get_vrstaTreninga()const {
        return vrstaTreninga;
    }
    void set_kvalitet(const int k) {
        kvalitet = k;
    }
    void set_cena(const int c) {
        cena = c;
    }
    void set_rok(const int r) {
        rok = r;
    }
    void set_vrstaTreninga(const VRSTA_TRENINGA v) {
        vrstaTreninga = v;
    }
};
#endif
