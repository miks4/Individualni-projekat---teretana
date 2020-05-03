#include <iostream>
#include "Oprema.hpp"
using namespace std;
enum TIP_SPRAVE { RUKE = 1, GRUDI, NOGE, LEDJA, STOMAK, RAME };
enum STANJE_SPRAVE { ODLICNO = 1, LOSE, NA_POPRAVCI };

class Sprava : public Oprema{
protected:
    TIP_SPRAVE tipSPrave;
    STANJE_SPRAVE stanjeSprave;
    float kvalitetSprava;
public:
    Sprava() : Oprema() {
        tipSPrave = RUKE;
        stanjeSprave = ODLICNO;
        kvalitetSprava = 90;
    }
    Sprava(TIP_SPRAVE t, STANJE_SPRAVE s, float k,int kvan,float kval) : Oprema(kvan,kval) {
        tipSPrave = t;
        stanjeSprave = s;
        kvalitetSprava = k;
    }
    Sprava(const Sprava& s) : Oprema((Oprema)s) {
        tipSPrave = s.tipSPrave;
        stanjeSprave = s.stanjeSprave;
        kvalitetSprava = s.kvalitetSprava;
    }
    ~Sprava() {}
    TIP_SPRAVE get_tipSprave()const {
        return tipSPrave;
    }
    STANJE_SPRAVE get_stanjeSprave()const {
        return stanjeSprave;
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
    void popravi() {
        if (staviNaPopravak() == true) {
            if (stanjeSprave == NA_POPRAVCI) {
                stanjeSprave = ODLICNO;
            }
        }

    }
    DinString vratiTip(){
        if(tipSPrave == RUKE){
            return " Za ruke.";
        }
        else if(tipSPrave == NOGE){return " Za noge.";}
        else if(tipSPrave == GRUDI){return " Za grudi.";}
        else if(tipSPrave == LEDJA){return " Za ledja.";}
        else if(tipSPrave == RAME){return " Za rame.";}
        else{return " Za stomak.";}
    }
};

#endif
