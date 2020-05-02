#include <iostream>
#include "Tegovi.hpp"
#include "Sprava.hpp"
#include "FitnesOprema.hpp"
using namespace std;

class Oprema : public Tegovi, public Sprava, public FitnesOprema {
private:
    float kvalitet;
    int kvantitet;
public:
    Oprema() : Tegovi(), Sprava(), FitnesOprema() {
        kvalitet = 100;
        kvantitet = 170;
    }
    Oprema(int t, VRSTA_TEGA v, int bt, float kt, TIP_SPRAVE ts, STANJE_SPRAVE s, int bs, float ks, VRSTA_FITNES_OPREME vfo, int a, int bf, float kf) : Tegovi(t, v, bt, kt), Sprava(ts, s, bs, ks), FitnesOprema(vfo, a, bf, kf) {
        kvalitet = (kt + ks + kf) / 3;
        kvantitet = bt + bs + bf;
    }
    Oprema(const Oprema& o) : Tegovi((Tegovi)o), Sprava((Sprava)o), FitnesOprema((FitnesOprema)o) {
        kvalitet = o.kvalitet;
        kvantitet = o.kvantitet;
    }
    ~Oprema() {}
    float get_kvalitet()const {
        return kvalitet;
    }
    int get_kvantitet()const {
        return kvantitet;
    }
    void set_kvalitet(const float k) {
        kvalitet = k;
    }
    void set_kvantitet(const int k1) {
        kvantitet = k1;
    }
    void popravi() {
        if (staviNaPopravak() == true) {
            if (stanjeSprave == NA_POPRAVCI) {
                stanjeSprave = ODLICNO;
            }
        }

    }
    friend ostream& operator<<(ostream& out, const Oprema& o) {
        if (o.kvantitet > 0) {

            out << "Kvalitet celokupne opreme:";
            out << o.kvalitet;
            out << "\nKvantitet celokupne opreme:";
            out << o.kvantitet;

            out << "\nTEGOVI:";
            out << "\n~~~~~~~";
            out << "\n\tVrsta tega:";
            if (o.teg == SIPKA) {
                out << "Sipka";
            }
            else if (o.teg == BUCICA) {
                out << "Bucica";
            }
            else { out << "Vrsta tega ne postoji"; }

            out << "\n\tTezina vrste tega:";
            out << o.tezina;
            out << "\n\tBroj tegova u teretani:";
            out << o.brTegova;
            out << "\n\tKvalitet tegova u teretani:";
            out << o.kvalitetTegova;

            out << "\nSPRAVE:";
            out << "\n~~~~~~~";
            out << "\n\tTip sprave:";
            if (o.tipSPrave == RUKE) { out << "Za ruke"; }
            else if (o.tipSPrave == GRUDI) { out << "Za grudi"; }
            else if (o.tipSPrave == NOGE) { out << "Za noge"; }
            else if (o.tipSPrave == LEDJA) { out << "Za ledja"; }
            else if (o.tipSPrave == STOMAK) { out << "Za stomak"; }
            else if (o.tipSPrave == RAME) { out << "Za rame"; }
            else { out << "Tip sprave ne postoji"; }

            out << "\n\tstanje sprave:";
            if (o.stanjeSprave == ODLICNO) { out << "Moze se koristiti"; }
            else if (o.stanjeSprave == LOSE) { out << "Trebalo b staviti da se popravlja"; }
            else if (o.stanjeSprave == NA_POPRAVCI) { out << "Ne moze da se koristi, trenutno je na popravci"; }
            else {
                out << "Stanje spave ne postoji";
            }
            out << "\n\tBroj sprava u teretani:";
            out << o.brSprava;
            out << "\n\tKvalitet sprava u teretani:";
            out << o.kvalitetSprava;

            out << "\nFITNES OPREMA:";
            out << "\n~~~~~~~~~~~~~~";
            out << "\n\tVrsta fitnes opreme:";
            if (o.vrstaFitnesOpreme == STRUNJACA) { out << "Strunjaca"; }
            else if (o.vrstaFitnesOpreme == LOPTA) { out << "Lopta"; }
            else if (o.vrstaFitnesOpreme == DZAK) { out << "DZak"; }
            else if (o.vrstaFitnesOpreme == GUMA) { out << "Guma"; }
            else {
                out << "Vrsta fitens opreme ne postoji";
            }

            out << "\n\tAmortizacija vrste fitnes opreme:";
            out << o.amortizacija;
            out << "\n\tBroj fitnes opreme u teretani:";
            out << o.brFitnesOpreme;
            out << "\n\tKvalitet fitnes opreme u teretani:";
            out << o.kvalitetFitnesOpreme;
        }
        return out;
    }
};
#endif
