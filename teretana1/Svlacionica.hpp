#include <iostream>
#include "Prostorija.hpp"
using namespace std;

class Svlacionica : public Prostorija{
protected:
    int ormaric;
    int klupa;
    int cipelarnik;
    int civiluk;
    bool podnoGrejanje;
public:
    Svlacionica() : Prostorija(){
        ormaric = 10;
        klupa = 5;
        cipelarnik = 10;
        civiluk = 3;
        podnoGrejanje = true;
    }
    Svlacionica(int o, int k, int c, int ci, bool p,int pr) : Prostorija(pr) {
        ormaric = o;
        klupa = k;
        cipelarnik = c;
        civiluk = ci;
        podnoGrejanje = p;
    }
    Svlacionica(const Svlacionica& s) : Prostorija((Prostorija)s) {
        ormaric = s.ormaric;
        klupa = s.klupa;
        cipelarnik = s.cipelarnik;
        civiluk = s.civiluk;
        podnoGrejanje = s.podnoGrejanje;
    }
    ~Svlacionica() {}
    int get_ormaric()const {
        return ormaric;
    }
    int get_klupa()const {
        return klupa;
    }
    int get_cipelarnik()const {
        return cipelarnik;
    }
    int get_civiluk()const {
        return civiluk;
    }
    bool get_podnoGrejanje()const {
        return podnoGrejanje;
    }
    void set_ormaric(const int o) {
        ormaric = o;
    }
    void set_klupa(const int k) {
        klupa = k;
    }
    void set_cipelarnik(const int c) {
        cipelarnik = c;
    }
    void set_civiluk(const int ci) {
        civiluk = ci;
    }
    void set_podnoGrejanje(const bool p) {
        podnoGrejanje = p;
    }
    int vratiBroj(){
        return ormaric + klupa + cipelarnik + civiluk;
    }

};
#endif
