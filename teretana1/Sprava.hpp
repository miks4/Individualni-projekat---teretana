#include <iostream>

using namespace std;
enum TIP_SPRAVE { RUKE = 1, GRUDI, NOGE, LEDJA, STOMAK, RAME };
enum STANJE_SPRAVE { ODLICNO = 1, LOSE, NA_POPRAVCI };

class Sprava {
protected:
    TIP_SPRAVE tipSPrave;
    STANJE_SPRAVE stanjeSprave;
    int brSprava;
    float kvalitetSprava;
public:
    Sprava() {
        tipSPrave = RUKE;
        stanjeSprave = ODLICNO;
        brSprava = 20;
        kvalitetSprava = 90;
    }
    Sprava(TIP_SPRAVE t, STANJE_SPRAVE s, int b, float k) {
        tipSPrave = t;
        stanjeSprave = s;
        brSprava = b;
        kvalitetSprava = k;
    }
    Sprava(const Sprava& s) {
        tipSPrave = s.tipSPrave;
        stanjeSprave = s.stanjeSprave;
        brSprava = s.brSprava;
        kvalitetSprava = s.kvalitetSprava;
    }
    ~Sprava() {}
    TIP_SPRAVE get_tipSprave()const {
        return tipSPrave;
    }
    STANJE_SPRAVE get_stanjeSprave()const {
        return stanjeSprave;
    }
    int get_brSprava()const {
        return brSprava;
    }
    float get_kvalitetSprava()const {
        return kvalitetSprava;
    }
    void set_tipSprave(const TIP_SPRAVE t) {
        tipSPrave = t;
    }
    void set_stanjeSprave(const STANJE_SPRAVE s) {
        stanjeSprave = s;
    }
    void set_brSprava(const int b) {
        brSprava = b;
    }
    void set_kvalitetSprava(const float k) {
        kvalitetSprava = k;
    }
    bool staviNaPopravak() {
        if (stanjeSprave == LOSE) {
            stanjeSprave = NA_POPRAVCI;
            return true;
        }
        else {
            return false;
        }
    }
    virtual void popravi() {}
};

#endif
