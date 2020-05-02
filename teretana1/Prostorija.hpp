#include <iostream>
#include "Kupatilo.hpp"
#include "Ostava.hpp"
#include "Svlacionica.hpp"
using namespace std;

class Prostorija : public Ostava, public Kupatilo, public Svlacionica {
private:
    int predmeti;
public:
    Prostorija() : Ostava(), Kupatilo(), Svlacionica() {
        predmeti = higijenskaredstva + rezervniDelovi + klupa + ormaric + cipelarnik + civiluk;
    }
    Prostorija(int d, int s, REZERVNI_DEO r, SREDSTVO_ZA_HIGIJENU h, int p, int t, int u, int o, int orm, int k, int c, int ci, bool pg) : Ostava(d, s, r, h), Kupatilo(p, t, u, o), Svlacionica(orm, k, c, ci, pg) {
        predmeti = d + s + p + t + u + o + orm + k + c + ci;
    }
    Prostorija(const Prostorija& p) : Ostava((Ostava)p), Kupatilo((Kupatilo)p), Svlacionica((Svlacionica)p) {
        predmeti = p.predmeti;
    }
    ~Prostorija() {}
    int get_predmeti()const {
        return predmeti;
    }
    void set_predmeti(const int v) {
        predmeti = v;
    }
    friend ostream& operator<<(ostream& izlaz, const Prostorija& p) {
        if (p.predmeti > 0) {
            izlaz << "Broj stvari:";
            izlaz << p.predmeti;
            izlaz << "\nOSTAVA:";
            izlaz << "\n~~~~~~~";
            izlaz << "\n\tRezervni deo:";
            if (p.tipRezervnogDela == SAJLA) { izlaz << "Sajla"; }
            else if (p.tipRezervnogDela == POMOCNA_SIPKA) { izlaz << "Pomocna sipka"; }
            else if (p.tipRezervnogDela == TEG) { izlaz << "Teg"; }
            else if (p.tipRezervnogDela == SUNDJER) { izlaz << "Sundjer"; }
            else {
                izlaz << "Ne postoji rezervni deo";
            }
            izlaz << "\n\tBroj rezervnog dela:";
            izlaz << p.rezervniDelovi;
            izlaz << "\n\tHigijensko sredstvo:";
            if (p.tipHigijenskogSredstva == OSVEZIVAC) { izlaz << "Osvezivac"; }
            else if (p.tipHigijenskogSredstva == KRPA) { izlaz << "Krpa"; }
            else if (p.tipHigijenskogSredstva == SPREJ) { izlaz << "Sprej"; }
            else {
                izlaz << "Ne postoji higijensko sredstvo";
            }
            izlaz << "\n\tBroj higijenskog sredstva:";
            izlaz << p.higijenskaredstva;

            izlaz << "\nSVLACIONICA:";
            izlaz << "\n~~~~~~~~~~~~";
            izlaz << "\n\tBroj klupa:";
            izlaz << p.klupa;
            izlaz << "\n\tBroj ormarica:";
            izlaz << p.ormaric;
            izlaz << "\n\tBroj cipelarnika:";
            izlaz << p.cipelarnik;
            izlaz << "\n\tBroj civiluka:";
            izlaz << p.civiluk;
            izlaz << "\n\tPodno grejanje?";
            if (p.podnoGrejanje == true) {
                izlaz << "\n\tNasa teretana ima podno grejanje.";
            }
            else {
                izlaz << "\n\tNasa teretana nema podno grejanje";
            }

            izlaz << "\nKUPATILO:";
            izlaz << "\n~~~~~~~~~";
            izlaz << "\n\tBroj tus kabina:";
            izlaz << p.tusKabina;
            izlaz << "\n\tBroj pisoara:";
            izlaz << p.pisoar;
            izlaz << "\n\tBroj umivaonika:";
            izlaz << p.umivaonik;
            izlaz << "\n\tBroj ogledala:";
            izlaz << p.ogledala;
        }
        return izlaz;
    }
};
#endif
