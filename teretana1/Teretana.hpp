#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
#include "Kasa.hpp"
#include "Info.hpp"
#include "Inventar.hpp"
#include "Zaposleni.hpp"
#include "Clan.hpp"
using namespace std;

class Teretana {
private:
    Kasa kasa;
    Info info;
    Inventar inventar;
    List<Zaposleni> zaposlen;
    List<Clan> clan;
    bool cisto;
    int maxZaposleni;
    int maxClanova;
    DinString naziv;
public:
    Teretana() : kasa(), info(), inventar(),zaposlen(),clan() {
        cisto = true;
        maxZaposleni = 10;
        maxClanova = 200;
        naziv = "HERKUL";
    }
    Teretana(double p, double tr,List<ReklamniMaterijal> r,List<PlanTreninga> pl,List<Suplementi> s,List<Clanarina> c, GRAD gg, DinString u, int br, DinString prv, DinString krv, int kkk, int ttt, int v, DinString tel, DANI d, int pp, int kk, int mm,List<Oprema> opr,List<Prostorija> pro, bool a, int mz, int mc, DinString nazi,List<Zaposleni> zap,List<Clan> ccc) : kasa(p, tr,r,pl,s,c), info(gg, u, br, prv, krv, kkk, ttt, v, tel, d), inventar(pp, kk, mm,opr,pro),zaposlen(zap),clan(ccc) {
        cisto = a;
        maxZaposleni = mz;
        maxClanova = mc;
        naziv = nazi;
    }
    Teretana(const Teretana& t) : kasa(t.kasa), info(t.info), inventar(t.inventar),zaposlen(t.zaposlen),clan(t.clan) {
        cisto = t.cisto;
        maxZaposleni = t.maxZaposleni;
        maxClanova = t.maxClanova;
        naziv = t.naziv;
    }
    ~Teretana() {}
    Info& get_info() {
        return info;
    }
    Kasa& get_kasa() {
        return kasa;
    }
    Inventar& get_inventar() {
        return inventar;
    }
    List<Zaposleni>& get_zaposleni() {
        return zaposlen;
    }
    List<Clan>& get_clan() {
        return clan;
    }
    DinString get_naziv()const {
        return naziv;
    }
    bool get_cisto()const {

        return cisto;
    }
    int get_maxZaposleni()const {
        return maxZaposleni;
    }
    int get_maxClanovi()const {
        return maxClanova;
    }
    void set_cisto(const bool c) {
        cisto = c;
    }
    void set_maxZaposleni(const int z) {
        maxZaposleni = z;
    }
    void set_maxClanovi(const int h) {
        maxClanova = h;
    }
    void set_naziv(const DinString n) {
        naziv = n;
    }

    double get_profitTrt()const {
        return kasa.get_profit();
    }
    double get_trosakTrt()const {
        return kasa.get_trosak();
    }


    void set_profitTrt(const double p) {
        kasa.set_profit(p);
    }
    void set_trosakTrt(const double t) {
        kasa.set_trosak(t);
    }

    DinString get_pocetakRadnoVremenaTrt()const {
        return info.get_pocetakRadnoVremenaInfo();
    }
    DinString get_krajkRadnoVremenaTrt()const {
        return info.get_krajkRadnoVremenaInfo();
    }
    DANI get_danTrt()const {
        return info.get_dan();
    }
    GRAD get_gradTrt()const {
        return info.get_grad();
    }
    DinString get_ulicaTrt()const {
        return  info.get_ulica();
    }
    int get_brUliceTrt()const {
        return info.get_brUlice();
    }
    int get_kapacitetTrt()const {
        return info.get_kapacitet();
    }
    int get_brTeretanaTrt()const {
        return info.get_brTeretana();
    }
    int get_velicinaTrt()const {
        return info.get_velicina();
    }
    DinString get_telefonTrt()const {
        return info.get_telefon();
    }
    void set_danTrt(const DANI d) {
        info.set_dan(d);
    }
    void set_gradTrt(const GRAD g) {
        info.set_grad(g);
    }
    void set_ulicaTrt(const DinString u) {
        info.set_ulica(u);
    }
    void set_brUliceTrt(const int br) {
        info.set_brUlice(br);
    }
    void set_kapacitetTrt(const int k) {
        info.set_kapacitet(k);
    }
    void set_brTeretanaTrt(const int br) {
        info.set_brTeretana(br);
    }
    void set_velicinaTrt(const int v) {
        info.set_velicina(v);
    }
    void set_telefonTrt(const DinString tel) {
        info.set_telefon(tel);
    }
    void set_pocetakRadnoVremenaTrt(const DinString p) {
        info.set_pocetakRadnoVremenaInfo(p);
    }
    void set_krajRadnoVremenaTrt(const DinString k) {
        info.set_krajRadnoVremenaInfo(k);
    }

    int get_paarkingMestaTrt()const {
        return inventar.get_paarkingMesta();
    }
    int get_kapacitetInventarTrt()const {
        return inventar.get_kapacitet();
    }
    int get_maxBrojPredmetaTrt()const {
        return inventar.get_maxBrojPredmeta();
    }
    void set_parkingMestaTrt(const int p) {
        inventar.set_parkingMesta(p);
    }
    void set_kapacitetInventarTrt(const int k) {
        inventar.set_kapacitet(k);
    }
    void set_maxBrojPredmetaTrt(const int br) {
        inventar.set_maxBrojPredmeta(br);
    }

    bool dodajClana(const Clan& c) {
        if (clan.size() < maxClanova) {
            return clan.add(clan.size() + 1, c);
        }
        else {
            return false;
        }
    }

    void popisClanova() {
        if (clan.size() == 0) {
            cout << "nemate clanova u teretani" << endl;
        }
        else {
            Clan c;
            cout << "\t    CLANOVI\t    CLANOVI\t    CLANOVI" << endl;
            cout << "====================================================================" << endl;
            for (int i = 1; i <= clan.size(); i++) {
                clan.read(i, c);
                cout << c << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    bool zaposliOsobu(const Zaposleni& z) {
        if (zaposlen.size() < maxZaposleni) {
            return zaposlen.add(zaposlen.size() + 1, z);
        }
        else {
            return false;
        }
    }
    void vidiStanjeZaposlenih() {
        if (zaposlen.size() == 0) {
            cout << "niste jos nikoga zaposlili." << endl;
        }
        else {
            Zaposleni zz;
            cout << "\t   ZAPOSLENI\t  ZAPOSLENI\t   ZAPOSLENI";
            cout << "\n====================================================================" << endl;
            for (int i = 1; i <= zaposlen.size(); i++) {
                zaposlen.read(i, zz);
                cout << zz << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    friend ostream& operator<<(ostream& out, const Teretana& t) {
        out << t.get_naziv();
        return out;
    }
    Teretana& operator=(const Teretana& t) {
        kasa = t.kasa;
        info = t.info;
        inventar = t.inventar;
        zaposlen = t.zaposlen;
        clan = t.clan;
        cisto = t.cisto;
        maxZaposleni = t.maxZaposleni;
        maxClanova = t.maxClanova;
        naziv = t.naziv;
        return *this;
    }
    friend bool operator==(Teretana& t1, Teretana& t2) {
        if (t1.get_kasa() != t2.get_kasa() || t1.get_info() != t2.get_info() || t1.get_inventar() != t2.get_inventar() ||
            t1.get_cisto() != t2.get_cisto() || t1.get_maxZaposleni() != t2.get_maxZaposleni() || t1.get_maxClanovi() != t2.get_maxClanovi() ||
            t1.get_naziv() != t2.get_naziv()) {

            return false;
        }
        return true;
    }
    friend bool operator!=(Teretana& t1, Teretana& t2) {
        if (t1 == t2) {
            return false;
        }
        else {
            return true;
        }
    }
    friend bool operator<(Teretana& t1, Teretana& t2) {
        if (t1.get_velicinaTrt() < t2.get_velicinaTrt()) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator>(Teretana& t1, Teretana& t2) {
        if (t1.get_velicinaTrt() > t2.get_velicinaTrt()) {
            return true;
        }
        else {
            return false;
        }
    }
};
#endif
