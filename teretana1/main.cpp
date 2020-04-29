

#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
using namespace std;
enum DANI { RADNI_DAN_I_SUBOTA = 1, NEDELJA, PRAZNICI };
enum GRAD { NOVI_SAD = 1, BEOGRAD, NIS, SRBOBRAN };
enum REZERVNI_DEO { SAJLA = 1, POMOCNA_SIPKA, TEG, SUNDJER };
enum SREDSTVO_ZA_HIGIJENU { OSVEZIVAC = 1, KRPA, SPREJ };
enum VRSTA_TEGA { SIPKA = 1, BUCICA };
enum TIP_SPRAVE { RUKE = 1, GRUDI, NOGE, LEDJA, STOMAK, RAME };
enum STANJE_SPRAVE { ODLICNO = 1, LOSE, NA_POPRAVCI };
enum VRSTA_FITNES_OPREME { STRUNJACA = 1, LOPTA, DZAK, GUMA };
enum VRSTA_TRENINGA { FITNES = 1, BODYWEIGHT, BODYBUILDING };
enum VRSTA_SUPLEMENATA{PROTEIN = 1,KREATIN,AMINOKISELINA};


class RadnoVreme {
private:
    int krajRadnogVremena;
    int pocetakRadnogVremena;

public:
    RadnoVreme() {
        krajRadnogVremena = 22;
        pocetakRadnogVremena = 10;
    }
    RadnoVreme(int k, int p) {
        krajRadnogVremena = k;
        pocetakRadnogVremena = p;
    }
    RadnoVreme(const RadnoVreme& k) {
        pocetakRadnogVremena = k.pocetakRadnogVremena;
        krajRadnogVremena = k.pocetakRadnogVremena;
    }
    ~RadnoVreme() {}
    int get_kraj()const {
        return krajRadnogVremena;
    }
    int get_pocetak()const {
        return pocetakRadnogVremena;
    }
    void set_kraj(const int k) {
        krajRadnogVremena = k;
    }
    void set_pocetak(const int p) {
        pocetakRadnogVremena = p;
    }
    bool otvoreno(int v) {
        if ((v > pocetakRadnogVremena) && (v < krajRadnogVremena)) {
            return true;
        }
        return false;
    }
    int trajanjeRadnogVremena() {
        int t = krajRadnogVremena - pocetakRadnogVremena;
        return t;
    }

};
class Adresa {
private:
    GRAD grad;
    DinString ulica;
    int ulicniBr;
public:
    Adresa() {
        grad = SRBOBRAN;
        ulica = "Sveti Sava";
        ulicniBr = 4;
    }
    Adresa(GRAD g, DinString u, int br) {
        grad = g;
        ulica = u;
        ulicniBr = br;
    }
    Adresa(const Adresa& a) {
        grad = a.grad;
        ulica = a.ulica;
        ulicniBr = a.ulicniBr;
    }
    ~Adresa() {}
    GRAD get_grad()const {
        return grad;
    }
    DinString get_ulica()const {
        return  ulica;
    }
    int get_brUlice()const {
        return ulicniBr;
    }
    void set_grad(const GRAD g) {
        grad = g;
    }
    void set_ulica(const DinString u) {
        ulica = u;
    }
    void set_brUlice(const int br) {
        ulicniBr = br;
    }
};
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
    Info() : adresa() {
        kapacitet = 25;
        brTeretana = 3;
        velicina = 50;
        telefon = "0613150983";
        dan = RADNI_DAN_I_SUBOTA;
    }
    Info(GRAD g, DinString u, int br, int prv, int krv, int k, int t, int v, DinString tel, DANI d) : adresa(g, u, br), radnoVreme(prv, krv) {
        kapacitet = k;
        brTeretana = t;
        velicina = v;
        telefon = tel;
        dan = d;
    }
    Info(const Info& i) : adresa(i.adresa) {
        kapacitet = i.kapacitet;
        brTeretana = i.brTeretana;
        velicina = i.velicina;
        telefon = i.telefon;
        dan = i.dan;
    }
    ~Info() {}
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
    void ispisRadnogVremena() {
        if (dan == RADNI_DAN_I_SUBOTA) {
            cout << "radno vreme za vreme radnih dana je isto kao i subotom";
            cout << "pocetak radnog vremena:" << radnoVreme.get_pocetak() << " h." << endl;
            cout << "kraj radnog vremena:" << radnoVreme.get_kraj() << " h." << endl;
            cout << "dnevno radimo:" << radnoVreme.trajanjeRadnogVremena() << " h." << endl;
        }
        else if (dan == PRAZNICI) {
            cout << "praznici su, ne radimo!" << endl;
        }
        else {
            cout << "nedeljom ne radimo" << endl;
        }
    }
};

class Ostava {
protected:
    int rezervniDelovi;
    int higijenskaredstva;
    REZERVNI_DEO tipRezervnogDela;
    SREDSTVO_ZA_HIGIJENU tipHigijenskogSredstva;
public:
    Ostava() {
        rezervniDelovi = 50;
        higijenskaredstva = 20;
        tipRezervnogDela = SAJLA;
        tipHigijenskogSredstva = SPREJ;
    }
    Ostava(int d, int s, REZERVNI_DEO r, SREDSTVO_ZA_HIGIJENU h) {
        rezervniDelovi = d;
        higijenskaredstva = s;
        tipRezervnogDela = r;
        tipHigijenskogSredstva = h;
    }
    Ostava(const Ostava& o) {
        rezervniDelovi = o.rezervniDelovi;
        higijenskaredstva = o.higijenskaredstva;
        tipRezervnogDela = o.tipRezervnogDela;
        tipHigijenskogSredstva = o.tipHigijenskogSredstva;
    }
    ~Ostava() {}
    int get_rezervniDeo()const {
        return rezervniDelovi;
    }
    int get_sredstvoZaHigijenu()const {
        return higijenskaredstva;
    }
    REZERVNI_DEO get_tipRezervnogDela()const {
        return tipRezervnogDela;
    }
    SREDSTVO_ZA_HIGIJENU get_tipSredstvaZaHigijenu()const {
        return tipHigijenskogSredstva;
    }
    void set_rezervniDeo(const int d) {
        rezervniDelovi = d;
    }
    void set_sredstvoZaHigijenu(const int s) {
        higijenskaredstva = s;
    }
    void set_tipRezervnogDela(const REZERVNI_DEO r) {
        tipRezervnogDela = r;
    }
    void set_tipSredstvoZaHigijenu(const SREDSTVO_ZA_HIGIJENU h) {
        tipHigijenskogSredstva = h;
    }
};
class Svlacionica {
protected:
    int ormaric;
    int klupa;
    int cipelarnik;
    int civiluk;
    bool podnoGrejanje;
public:
    Svlacionica() {
        ormaric = 10;
        klupa = 5;
        cipelarnik = 10;
        civiluk = 3;
        podnoGrejanje = true;
    }
    Svlacionica(int o, int k, int c, int ci, bool p) {
        ormaric = o;
        klupa = k;
        cipelarnik = c;
        civiluk = ci;
        podnoGrejanje = p;
    }
    Svlacionica(const Svlacionica& s) {
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
};
class Kupatilo {
protected:
    int pisoar;
    int tusKabina;
    int umivaonik;
    int ogledala;
public:
    Kupatilo() {
        pisoar = 7;
        tusKabina = 2;
        umivaonik = 3;
        ogledala = 3;
    }
    Kupatilo(int p, int t, int u, int o) {
        pisoar = p;
        tusKabina = t;
        umivaonik = u;
        ogledala = o;
    }
    Kupatilo(const Kupatilo& k) {
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
};
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
            izlaz << "broj stvari:";
            izlaz << p.predmeti;
            izlaz << "\nOSTAVA:";
            izlaz << "\n~~~~~~~";
            izlaz << "\n\trezervni deo:";
            if (p.tipRezervnogDela == SAJLA) { izlaz << "sajla"; }
            else if (p.tipRezervnogDela == POMOCNA_SIPKA) { izlaz << "pomocna sipka"; }
            else if (p.tipRezervnogDela == TEG) { izlaz << "teg"; }
            else if (p.tipRezervnogDela == SUNDJER) { izlaz << "sundjer"; }
            else {
                izlaz << "ne postoji rezervni deo";
            }
            izlaz << "\n\tbroj rezervnog dela:";
            izlaz << p.rezervniDelovi;
            izlaz << "\n\thigijensko sredstvo:";
            if (p.tipHigijenskogSredstva == OSVEZIVAC) { izlaz << "osvezivac"; }
            else if (p.tipHigijenskogSredstva == KRPA) { izlaz << "krpa"; }
            else if (p.tipHigijenskogSredstva == SPREJ) { izlaz << "sprej"; }
            else {
                izlaz << "ne postoji higijensko sredstvo";
            }
            izlaz << "\n\tbroj higijenskog sredstva:";
            izlaz << p.higijenskaredstva;

            izlaz << "\nSVLACIONICA:";
            izlaz << "\n~~~~~~~~~~~~";
            izlaz << "\n\tbroj klupa:";
            izlaz << p.klupa;
            izlaz << "\n\tbroj ormarica:";
            izlaz << p.ormaric;
            izlaz << "\n\tbroj cipelarnika:";
            izlaz << p.cipelarnik;
            izlaz << "\n\tbroj civiluka:";
            izlaz << p.civiluk;
            izlaz << "\n\tpodno grejanje?";
            if (p.podnoGrejanje == true) {
                izlaz << "\n\tnasa teretana ima podno grejanje.";
            }
            else {
                izlaz << "\n\tnasa teretana nema podno grejanje";
            }

            izlaz << "\nKUPATILO:";
            izlaz << "\n~~~~~~~~~";
            izlaz << "\n\tbroj tus kabina:";
            izlaz << p.tusKabina;
            izlaz << "\n\tbroj pisoara:";
            izlaz << p.pisoar;
            izlaz << "\n\tbroj umivaonika:";
            izlaz << p.umivaonik;
            izlaz << "\n\tbroj ogledala:";
            izlaz << p.ogledala;
        }
        return izlaz;
    }
};


class Tegovi {
protected:
    int tezina;
    VRSTA_TEGA teg;
    int brTegova;
    float kvalitetTegova;
public:
    Tegovi() {
        tezina = 20;
        teg = SIPKA;
        brTegova = 60;
        kvalitetTegova = 75;
    }
    Tegovi(int t, VRSTA_TEGA v, int b, float k) {
        tezina = t;
        teg = v;
        brTegova = b;
        kvalitetTegova = k;
    }
    Tegovi(const Tegovi& t) {
        tezina = t.tezina;
        teg = t.teg;
        brTegova = t.brTegova;
        kvalitetTegova = t.kvalitetTegova;
    }
    ~Tegovi() {}
    VRSTA_TEGA get_vrstaTega()const {
        return teg;
    }
    int get_tezinaTega()const {
        return tezina;
    }
    int get_brTegova()const {
        return brTegova;
    }
    float get_kvalitetTegova()const {
        return kvalitetTegova;
    }
    void set_vrstaTega(const VRSTA_TEGA& v) {
        teg = v;
    }
    void set_tezinaTega(const int t) {
        tezina = t;
    }
    void set_brTegova(const int b) {
        brTegova = b;
    }
    void set_kvalitetTegova(const float k) {
        kvalitetTegova = k;
    }
};
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

            out << "kvalitet celokupne opreme:";
            out << o.kvalitet;
            out << "\nkvantitet celokupne opreme:";
            out << o.kvantitet;

            out << "\nTEGOVI:";
            out << "\n~~~~~~~";
            out << "\n\tvrsta tega:";
            if (o.teg == SIPKA) {
                out << "sipka";
            }
            else if (o.teg == BUCICA) {
                out << "bucica";
            }
            else { out << "vrsta tega ne postoji"; }

            out << "\n\ttezina vrste tega:";
            out << o.tezina;
            out << "\n\tbroj tegova u teretani:";
            out << o.brTegova;
            out << "\n\tkvalitet tegova u teretani:";
            out << o.kvalitetTegova;

            out << "\nSPRAVE:";
            out << "\n~~~~~~~";
            out << "\n\ttip sprave:";
            if (o.tipSPrave == RUKE) { out << "za ruke"; }
            else if (o.tipSPrave == GRUDI) { out << "za grudi"; }
            else if (o.tipSPrave == NOGE) { out << "za noge"; }
            else if (o.tipSPrave == LEDJA) { out << "za ledja"; }
            else if (o.tipSPrave == STOMAK) { out << "za stomak"; }
            else if (o.tipSPrave == RAME) { out << "za rame"; }
            else { out << "tip sprave ne postoji"; }

            out << "\n\tstanje sprave:";
            if (o.stanjeSprave == ODLICNO) { out << "moze se koristiti"; }
            else if (o.stanjeSprave == LOSE) { out << "trebalo b staviti da se popravlja"; }
            else if (o.stanjeSprave == NA_POPRAVCI) { out << "ne moze da se koristi, trenutno je na popravci"; }
            else {
                out << "stanje spave ne postoji";
            }
            out << "\n\tbroj sprava u teretani:";
            out << o.brSprava;
            out << "\n\tkvalitet sprava u teretani:";
            out << o.kvalitetSprava;

            out << "\nFITNES OPREMA:";
            out << "\n~~~~~~~~~~~~~~";
            out << "\n\tvrsta fitnes opreme:";
            if (o.vrstaFitnesOpreme == STRUNJACA) { out << "strunjaca"; }
            else if (o.vrstaFitnesOpreme == LOPTA) { out << "lopta"; }
            else if (o.vrstaFitnesOpreme == DZAK) { out << "dzak"; }
            else if (o.vrstaFitnesOpreme == GUMA) { out << "guma"; }
            else {
                out << "vrsta fitens opreme ne postoji";
            }

            out << "\n\tamortizacija vrste fitnes opreme:";
            out << o.amortizacija;
            out << "\n\tbroj fitnes opreme u teretani:";
            out << o.brFitnesOpreme;
            out << "\n\tkvalitet fitnes opreme u teretani:";
            out << o.kvalitetFitnesOpreme;
        }
        return out;
    }
};

class Inventar {
private:
    int parkingMesta;
    int kapacitet;
    int predmetiMax;
    List<Oprema> oprema;
    List<Prostorija> prostorija;
public:
    Inventar() {
        parkingMesta = 10;
        kapacitet = 400;
        predmetiMax = 400;
    }
    Inventar(int p, int k, int m) {
        parkingMesta = p;
        kapacitet = k;
        predmetiMax = m;
    }
    Inventar(const Inventar& i) {
        parkingMesta = i.parkingMesta;
        kapacitet = i.kapacitet;
        predmetiMax = i.predmetiMax;
    }
    ~Inventar() {}
    int get_paarkingMesta()const {
        return parkingMesta;
    }
    int get_kapacitet()const {
        return kapacitet;
    }
    int get_maxBrojPredmeta()const {
        return predmetiMax;
    }
    void set_parkingMesta(const int p) {
        parkingMesta = p;
    }
    void set_kapacitet(const int k) {
        kapacitet = k;
    }
    void set_maxBrojPredmeta(const int br) {
        predmetiMax = br;
    }
    bool kupiOpremu(const Oprema& o) {
        if (oprema.size() < kapacitet) {
            return oprema.add(oprema.size() + 1, o);
        }
        return false;
    }
    void vidiOpremu() {
        if (oprema.size() == 0) {
            cout << "nemate nista od opreme" << endl;
        }
        else {
            Oprema o;
            cout << "    SPISAK OPREME      SPISAK OPREME       SPISAK OPREME" << endl;
            cout << "====================================================================" << endl;
            for (int i = 1; i <= oprema.size(); i++) {
                oprema.read(i, o);
                cout << o << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    bool kupiStvari(const Prostorija& p) {
        if (prostorija.size() < predmetiMax) {
            return prostorija.add(prostorija.size() + 1, p);
        }
        return false;
    }
    void vidiStanjeProstorija() {
        if (prostorija.size() == 0) {
            cout << "nemate nista u inventaru" << endl;
        }
        else {
            Prostorija p;
            cout << " PREGLED PROSTORIJA     PREGLED PROSTORIJA      PREGLED PROSTORIJA" << endl;
            cout << "====================================================================" << endl;
            for (int i = 1; i <= prostorija.size(); i++) {
                prostorija.read(i, p);
                cout << p << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
};

class ReklamniMaterijal {
private:
    int majice;
    int trenerke;
    int kacketi;
    int kalendari;
    int olovke;
public:
    ReklamniMaterijal() {
        majice = 50;
        trenerke = 50;
        kacketi = 20;
        kalendari = 25;
        olovke = 80;
    }
    ReklamniMaterijal(int m, int t, int k, int kal, int o) {
        majice = m;
        trenerke = t;
        kacketi = k;
        kalendari = kal;
        olovke = o;
    }
    ReklamniMaterijal(const ReklamniMaterijal& r) {
        majice = r.majice;
        trenerke = r.trenerke;
        kacketi = r.kacketi;
        kalendari = r.kalendari;
        olovke = r.olovke;
    }
    ~ReklamniMaterijal() {}
    int get_majice()const { return majice; }
    int get_trenerke()const { return trenerke; }
    int get_kacketi()const { return kacketi; }
    int get_kalendari()const { return kalendari; }
    int get_olovke()const { return olovke; }
    void set_majice(const int m) { majice = m; }
    void set_trenerke(const int t) { trenerke = t; }
    void set_kacketi(const int k) { kacketi = k; }
    void set_kalendari(const int kal) { kalendari = kal; }
    void set_olovke(const int o) { olovke = o; }
};
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
class Suplementi {
private:
    int cena;
    VRSTA_SUPLEMENATA suplement;
public:
    Suplementi() {
        cena = 150;
        suplement = PROTEIN;
    }
    Suplementi(int c, VRSTA_SUPLEMENATA v) {
        cena = c;
        suplement = v;
    }
    Suplementi(const Suplementi& s) {
        cena = s.cena;
        suplement = s.suplement;
    }
    int get_cena()const {
        return cena;
    }
    VRSTA_SUPLEMENATA get_suplement()const {
        return suplement;
    }
    void set_cena(const int c) {
        cena = c;
    }
    void set_suplement(const VRSTA_SUPLEMENATA v) {
        suplement = v;
    }
};
class Clanarina {
private:
    int cena;
    DinString datumUplate;
    int trajanje;
public:
    Clanarina() {
        cena = 2000;
        datumUplate = "1.4.2020";
        trajanje = 30;
    }
    Clanarina(int c, DinString d, int t) {
        cena = c;
        datumUplate = d;
        trajanje = t;
    }
    Clanarina(const Clanarina& c) {
        cena = c.cena;
        datumUplate = c.datumUplate;
        trajanje = c.trajanje;
    }
    int get_cena()const {
        return cena;
    }
    DinString get_datumUplate()const {
        return datumUplate;
    }
    int get_trajanje()const {
        return trajanje;
    }
    void set_cena(const int c) {
        cena = c;
    }
    void set_datumUplate(const DinString d) {
        datumUplate = d;
    }
    void set_trajanje(const int t) {
        trajanje = t;
    }
};

int main()
{
    //List<Oprema> opreme;
    Oprema o1(5, SIPKA, 60, 75, RUKE, ODLICNO, 20, 90, STRUNJACA, 2, 40, 80);
    Oprema o2(10, BUCICA, 65, 85, RAME, LOSE, 25, 90, LOPTA, 3, 45, 75);
    /*  opreme.add(1, o1);
      opreme.add(2, o2);

      Oprema o;
      for (int i = 1; i <= opreme.size(); i++) {
          opreme.read(i, o);

          cout << "\n\n\n\t\tOPREMA BR. " << i << " JESTE SLEDECA:\n" << o << endl;
      };
    */
    Inventar i;
    cout << "====================================================================" << endl;
    i.kupiOpremu(o1);
    i.kupiOpremu(o2);
    i.vidiOpremu();

    List<Prostorija> prostorija;
    Prostorija p1(10, 20, SAJLA, OSVEZIVAC, 10, 3, 5, 5, 15, 3, 15, 3, true);
    Prostorija p2(20, 25, TEG, SPREJ, 9, 2, 4, 4, 14, 2, 14, 2, false);

    i.kupiStvari(p1);
    i.kupiStvari(p2);
    i.vidiStanjeProstorija();

    RadnoVreme r();
    RadnoVreme r1(10, 22);
    RadnoVreme r2(r1);

    Adresa a();
    Adresa a1(SRBOBRAN, "sveti sava", 4);
    Adresa a2(a1);

    Info i3();
    Info i1(SRBOBRAN, "sveti sava", 4, 10, 22, 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA);
    Info i2(i1);

    Ostava ostava();
    Ostava ostava1(50, 20, SAJLA, OSVEZIVAC);
    Ostava ostava2(ostava1);

    Svlacionica s();
    Svlacionica s1(10, 5, 10, 3, true);
    Svlacionica s2(s1);

    Kupatilo k();
    Kupatilo k1(7, 2, 3, 3);
    Kupatilo k2(k1);

    Prostorija pr();
    Prostorija pr1(50, 20, SAJLA, OSVEZIVAC, 7, 2, 3, 3, 10, 5, 10, 3, true);
    Prostorija pr2(pr1);

    Tegovi t();
    Tegovi t1(20, SIPKA, 60, 75);
    Tegovi t2(t1);

    Sprava spr();
    Sprava spr1(RUKE, ODLICNO, 20, 90);
    Sprava spr2(spr1);

    FitnesOprema f();
    FitnesOprema f1(STRUNJACA, 2, 40, 80);
    FitnesOprema f2(f1);

    Oprema o();
    Oprema o3(20, SIPKA, 60, 75, RUKE, ODLICNO, 20, 90, STRUNJACA, 2, 40, 80);
    Oprema o4(o3);

    Inventar ii();
    Inventar ii1(10, 400, 400);
    Inventar ii2(ii1);

    ReklamniMaterijal rm();
    ReklamniMaterijal rm1(50, 50, 20, 25, 80);
    ReklamniMaterijal rm2(rm1);

    PlanTreninga pt();
    PlanTreninga pt1(90, 2000, 40, FITNES);
    PlanTreninga pt2(pt1);

    Suplementi sup();
    Suplementi sup1(150, PROTEIN);
    Suplementi sup2(sup1);

    Clanarina cl();
    Clanarina c2(2000, "1.4.2020", 30);
    Clanarina c3(c2);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

