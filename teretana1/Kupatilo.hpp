#include <iostream>
#include "Prostorija.hpp"
using namespace std;
class Kupatilo : public Prostorija {
protected:
    int pisoar;
    int tusKabina;
    int umivaonik;
    int ogledala;
public:
    Kupatilo() : Prostorija() {
        pisoar = 7;
        tusKabina = 2;
        umivaonik = 3;
        ogledala = 3;
    }
    Kupatilo(int p, int t, int u, int o,int pr) : Prostorija(pr) {
        pisoar = p;
        tusKabina = t;
        umivaonik = u;
        ogledala = o;
    }
    Kupatilo(const Kupatilo& k) : Prostorija((Prostorija)k) {
        pisoar = k.pisoar;
        tusKabina = k.tusKabina;
        umivaonik = k.umivaonik;
        ogledala = k.ogledala;
    }
    ~Kupatilo() {}
    int get_pisoar()const {
        return pisoar;
    }
    int get_tusKabina()const {
        return tusKabina;
    }
    int get_umivaonik()const {
        return umivaonik;
    }
    int get_ogledalo()const {
        return ogledala;
    }
    void set_pisoar(const int p) {
        pisoar = p;
    }
    void set_tusKabina(const int t) {
        tusKabina = t;
    }
    void set_umivaonik(const int u) {
        umivaonik = u;
    }
    void set_ogledalo(const int o) {
        ogledala = o;
    }
    int vratiBroj(){
        return tusKabina + umivaonik + ogledala + pisoar;
    }
};

#endif
