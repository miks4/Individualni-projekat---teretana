#include <iostream>
#include "RadnoVreme.hpp"
#include "Adresa.hpp"
#include "dinstring.hpp"
using namespace std;
enum DANI { RADNI_DAN_I_SUBOTA = 1, NEDELJA, PRAZNICI };
class Info {
private:
    Adresa adresa;
    RadnoVreme radnoVreme;
    int kapacitet;
    int brTeretana;
    int velicina;
    DinString telefon;
    DANI dan;
public:
    Info() : adresa(), radnoVreme() {
        kapacitet = 25;
        brTeretana = 3;
        velicina = 50;
        telefon = "0613150983";
        dan = RADNI_DAN_I_SUBOTA;
    }
    Info(GRAD gg, DinString u, int br, DinString prv, DinString krv, int kkk, int ttt, int v, DinString tel, DANI d) : adresa(gg, u, br), radnoVreme(prv, krv) {
        kapacitet = kkk;
        brTeretana = ttt;
        velicina = v;
        telefon = tel;
        dan = d;
    }
    Info(const Info& i) : adresa(i.adresa), radnoVreme(i.radnoVreme) {
        kapacitet = i.kapacitet;
        brTeretana = i.brTeretana;
        velicina = i.velicina;
        telefon = i.telefon;
        dan = i.dan;
    }
    ~Info() {}
    DinString get_pocetakRadnoVremenaInfo()const {
        return radnoVreme.get_pocetak();
    }
    DinString get_krajkRadnoVremenaInfo()const {
        return radnoVreme.get_kraj();
    }
    DANI get_dan()const {
        return dan;
    }
    GRAD get_grad()const {
        return adresa.get_grad();
    }
    DinString get_ulica()const {
        return  adresa.get_ulica();
    }
    int get_brUlice()const {
        return adresa.get_brUlice();
    }
    int get_kapacitet()const {
        return kapacitet;
    }
    int get_brTeretana()const {
        return brTeretana;
    }
    int get_velicina()const {
        return velicina;
    }
    DinString get_telefon()const {
        return telefon;
    }
    void set_dan(const DANI d) {
        dan = d;
    }
    void set_grad(const GRAD g) {
        adresa.set_grad(g);
    }
    void set_ulica(const DinString u) {
        adresa.set_ulica(u);
    }
    void set_brUlice(const int br) {
        adresa.set_brUlice(br);
    }
    void set_kapacitet(const int k) {
        kapacitet = k;
    }
    void set_brTeretana(const int br) {
        brTeretana = br;
    }
    void set_velicina(const int v) {
        velicina = v;
    }
    void set_telefon(const DinString tel) {
        telefon = tel;
    }
    void set_pocetakRadnoVremenaInfo(const DinString p) {
        radnoVreme.set_pocetak(p);
    }
    void set_krajRadnoVremenaInfo(const DinString k) {
        radnoVreme.set_kraj(k);
    }
    void vidiRadnoVreme() {
        cout << "\t     RADNO VREME  RADNO VREME RADNO VREME " << endl;
        cout << "====================================================================" << endl;
        cout << "radno vreme za vreme radnih dana je isto kao i subotom." << endl;
        cout << "\tpocetak radnog vremena:" << radnoVreme.get_pocetak()  << endl;
        cout << "\tkraj radnog vremena:" << radnoVreme.get_kraj()  << endl;
        cout << "\tpraznicima i nedeljom ne radimo." << endl;
        cout << "====================================================================" << endl;

    }
    Info& operator=(const Info& i) {
        adresa = i.adresa;
        radnoVreme = i.radnoVreme;
        kapacitet = i.kapacitet;
        brTeretana = i.brTeretana;
        velicina = i.velicina;
        telefon = i.telefon;
        dan = i.dan;
        return *this;
    }
    friend bool operator==(Info& i1, Info& i2) {
        if (i1.get_brTeretana() != i2.get_brTeretana() || i1.get_brUlice() != i2.get_brUlice() || i1.get_dan() != i2.get_dan() || i1.get_grad() != i2.get_grad() ||
            i1.get_kapacitet() != i2.get_kapacitet() || i1.get_krajkRadnoVremenaInfo() != i2.get_krajkRadnoVremenaInfo() || i1.get_pocetakRadnoVremenaInfo() != i2.get_pocetakRadnoVremenaInfo() ||
            i1.get_telefon() != i2.get_telefon() || i1.get_ulica() != i2.get_ulica() || i1.get_velicina() != i2.get_velicina()) {
            return false;
        }
        else {
            return true;
        }
    }
    friend bool operator!=(Info& i1, Info& i2) {
        if (i1 == i2) {
            return false;
        }
        else {
            return true;
        }
    }
    friend bool operator<(Info& i1, Info& i2) {
        if (i1.get_velicina() < i2.get_velicina()) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator>(Info& i1, Info& i2) {
        if (i1.get_velicina() > i2.get_velicina()) {
            return true;
        }
        else {
            return false;
        }
    }
};
#endif
