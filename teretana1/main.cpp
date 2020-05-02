#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"

using namespace std;
enum GRAD { NOVI_SAD = 1, BEOGRAD, NIS, SRBOBRAN };
enum DANI { RADNI_DAN_I_SUBOTA = 1, NEDELJA, PRAZNICI };
enum REZERVNI_DEO { SAJLA = 1, POMOCNA_SIPKA, TEG, SUNDJER };
enum SREDSTVO_ZA_HIGIJENU { OSVEZIVAC = 1, KRPA, SPREJ };
enum VRSTA_TEGA { SIPKA = 1, BUCICA };
enum TIP_SPRAVE { RUKE = 1, GRUDI, NOGE, LEDJA, STOMAK, RAME };
enum STANJE_SPRAVE { ODLICNO = 1, LOSE, NA_POPRAVCI };
enum VRSTA_FITNES_OPREME { STRUNJACA = 1, LOPTA, DZAK, GUMA };
enum VRSTA_TRENINGA { FITNES = 1, BODYWEIGHT, BODYBUILDING };
enum VRSTA_SUPLEMENATA { PROTEIN = 1, KREATIN, AMINOKISELINA };
enum VRSTA_CLANA { OBICAN = 1, VIP };
enum ZAPOSLENI { TRENER = 1,CISTACICA,POMOCNIK };

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
    Info() : adresa(),radnoVreme() {
        kapacitet = 25;
        brTeretana = 3;
        velicina = 50;
        telefon = "0613150983";
        dan = RADNI_DAN_I_SUBOTA;
    }
    Info(GRAD gg, DinString u, int br, int prv, int krv, int kkk, int ttt, int v, DinString tel, DANI d) : adresa(gg, u, br), radnoVreme(prv, krv) {
        kapacitet = kkk;
        brTeretana = ttt;
        velicina = v;
        telefon = tel;
        dan = d;
    }
    Info(const Info& i) : adresa(i.adresa),radnoVreme(i.radnoVreme) {
        kapacitet = i.kapacitet;
        brTeretana = i.brTeretana;
        velicina = i.velicina;
        telefon = i.telefon;
        dan = i.dan;
    }
    ~Info() {}
    int get_pocetakRadnoVremenaInfo()const {
        return radnoVreme.get_pocetak();
    }
    int get_krajkRadnoVremenaInfo()const{
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
    void set_pocetakRadnoVremenaInfo(const int p){
        radnoVreme.set_pocetak(p);
    }
    void set_krajRadnoVremenaInfo(const int k){
        radnoVreme.set_kraj(k);
    }
    void vidiRadnoVreme() {
        cout << "\t     RADNO VREME  RADNO VREME RADNO VREME "<<endl;
        cout << "====================================================================" << endl;
            cout << "radno vreme za vreme radnih dana je isto kao i subotom,dnevno radimo 12h."<<endl;
            cout << "\tpocetak radnog vremena:" << radnoVreme.get_pocetak() << "h." << endl;
            cout << "\tkraj radnog vremena:" << radnoVreme.get_kraj() << "h." << endl;
            cout << "\tpraznicima i nedeljom ne radimo."<<endl;
            cout << "====================================================================" << endl;

    }
    Info& operator=(const Info &i){
        adresa = i.adresa;
        radnoVreme = i.radnoVreme;
        kapacitet = i.kapacitet;
        brTeretana = i.brTeretana;
        velicina = i.velicina;
        telefon = i.telefon;
        dan = i.dan;
        return *this;
    }
    friend bool operator==(Info& i1,Info& i2) {
        if (i1.get_brTeretana() != i2.get_brTeretana() || i1.get_brUlice() != i2.get_brUlice() || i1.get_dan() != i2.get_dan() || i1.get_grad() != i2.get_grad() ||
            i1.get_kapacitet() != i2.get_kapacitet() || i1.get_krajkRadnoVremenaInfo() != i2.get_krajkRadnoVremenaInfo() || i1.get_pocetakRadnoVremenaInfo() != i2.get_pocetakRadnoVremenaInfo() ||
            i1.get_telefon() != i2.get_telefon() || i1.get_ulica() != i2.get_ulica() || i1.get_velicina() != i2.get_velicina()) {
            return false;
        }
        else{
            return true;
        }
    }
    friend bool operator!=(Info& i1,Info& i2) {
        if (i1 == i2) {
            return false;
        }
        else{
            return true;
        }
    }
    friend bool operator<(Info &i1,Info &i2){
        if(i1.get_velicina() < i2.get_velicina()){
            return true;
        }
        else{
                    return false;
        }
    }
    friend bool operator>(Info &i1,Info &i2){
        if(i1.get_velicina() > i2.get_velicina()){
            return true;
        }
        else{
                    return false;
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

class Inventar {
private:
    int parkingMesta;
    int kapacitet;
    int predmetiMax;
    List<Oprema> oprema;
    List<Prostorija> prostorija;
public:
    Inventar(){
        parkingMesta = 10;
        kapacitet = 400;
        predmetiMax = 400;
    }
    Inventar(int pp, int kk, int mm) {
        parkingMesta = pp;
        kapacitet = kk;
        predmetiMax = mm;
    }
    Inventar(const Inventar& i) {
        parkingMesta = i.parkingMesta;
        kapacitet = i.kapacitet;
        predmetiMax = i.predmetiMax;
    }
    ~Inventar() {}
    List<Oprema>& get_oprema(){
        return oprema;
    }
    List<Prostorija>& get_prostorija(){
        return prostorija;
    }
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
    Inventar& operator=(const Inventar &i){
        parkingMesta = i.parkingMesta;
        kapacitet = i.kapacitet;
        predmetiMax = i.predmetiMax;
        oprema = i.oprema;
        prostorija = i.prostorija;
        return *this;
    }
    friend bool operator==(Inventar &i1,Inventar &i2){
        if(i1.get_kapacitet()!=i2.get_kapacitet() || i1.get_paarkingMesta()!=i2.get_paarkingMesta() || i1.get_maxBrojPredmeta()!=i2.get_maxBrojPredmeta() ||
            i1.get_oprema()!=i2.get_oprema() || i1.get_prostorija()!=i2.get_prostorija()){
                    return false;
        }
        else{
            return true;
        }
    }
    friend bool operator!=(Inventar &i1,Inventar &i2){
        if(i1 == i2){
            return false;
        }
        else{
            return true;
        }
    }
    friend bool operator<(Inventar &i1,Inventar &i2){
        if(i1.get_kapacitet() < i2.get_kapacitet()){
            return true;
        }
        else{
               return false;
        }
    }
    friend bool operator>(Inventar &i1,Inventar &i2){
        if(i1.get_kapacitet() > i2.get_kapacitet()){
            return true;
        }
        else{
               return false;
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
    int brojReklamnogMaterijala(){
       int b = majice + trenerke + kacketi + olovke + kalendari;
       return b;
    }
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
    int broj;
public:
    Suplementi() {
        cena = 150;
        suplement = PROTEIN;
        broj = 1000;
    }
    Suplementi(int c, VRSTA_SUPLEMENATA v,int b) {
        cena = c;
        suplement = v;
        broj = b;
    }
    Suplementi(const Suplementi& s) {
        cena = s.cena;
        suplement = s.suplement;
        broj = s.broj;
    }
    ~Suplementi(){}
    int get_cena()const {
        return cena;
    }
    VRSTA_SUPLEMENATA get_suplement()const {
        return suplement;
    }
    int get_broj()const{
        return broj;
    }
    void set_cena(const int c) {
        cena = c;
    }
    void set_suplement(const VRSTA_SUPLEMENATA v) {
        suplement = v;
    }
    void set_broj(const int b){
        broj = b;
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
    ~Clanarina(){}
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

class Kasa {
private:
    int profit;
    int trosak;
    ReklamniMaterijal reklamniM;
    PlanTreninga planT;
    Suplementi suplement;
    Clanarina clanarina;
public:
    Kasa() : reklamniM(),planT(),suplement(),clanarina(){
        profit = 100000;
        trosak = 30000;
    }
    Kasa(int m,int t,int k,int kal,int ol,int kval,int c,int r,VRSTA_TRENINGA vt,int ce,VRSTA_SUPLEMENATA vs,int g,int cen,DinString dd,int traj,int p,int tr) : reklamniM(m,t,k,kal,ol),planT(kval,c,t,vt),suplement(ce,vs,g),clanarina(cen,dd,traj){
        profit = p;
        trosak = tr;
    }
    Kasa(const Kasa &k) : reklamniM(k.reklamniM),planT(k.planT),suplement(k.suplement),clanarina(k.clanarina){
        profit = k.profit;
        trosak = k.trosak;
    }
    ~Kasa(){}
    int get_profit()const{
        return profit;
    }
    int get_trosak()const{
        return trosak;
    }
    int get_cenaClanarinaKasa()const{
        return clanarina.get_cena();
    }
    DinString get_datumUplateKasa()const{
        return clanarina.get_datumUplate();
    }
    int get_trajanjeClanarineKasa()const{
        return clanarina.get_trajanje();
    }
    int get_cenaTreningaKasa()const{
        return planT.get_cena();
    }
    int get_kvalitetTreningaKasa()const{
        return planT.get_kvalitet();
    }
    int get_rokTreningaKasa()const{
        return planT.get_rok();
    }
    VRSTA_TRENINGA get_vrstaTreningaKasa()const{
        return planT.get_vrstaTreninga();
    }
    int get_majiceKasa()const{
        return reklamniM.get_majice();
    }
    int get_trenerkeKasa()const{
        return reklamniM.get_trenerke();
    }
    int get_kacketiKasa()const{
        return reklamniM.get_kacketi();
    }
    int get_kalendariKasa()const{
        return reklamniM.get_kalendari();
    }
    int get_olovkeKasa()const{
        return reklamniM.get_olovke();
    }
    int get_cenaSuplemenataKasa()const{
        return suplement.get_cena();
    }
    VRSTA_SUPLEMENATA get_vrstaSuplemenataKasa()const{
        return suplement.get_suplement();
    }
    int get_brojSuplementKasa()const{
        return suplement.get_broj();
    }
    void set_profit(const int p){
        profit = p;
    }
    void set_trosak(const int t){
        trosak = t;
    }
    void set_cenaClanarineKasa(const int c){
        clanarina.set_cena(c);
    }
    void set_datumUplateKasa(const DinString d){
        clanarina.set_datumUplate(d);
    }
    void set_trajanjeClanarineKasa(const int t){
        clanarina.set_trajanje(t);
    }
    void set_kvalitetTreningaKasa(const int k){
        planT.set_kvalitet(k);
    }
    void set_cenaTreningaKasa(const int c){
        planT.set_cena(c);
    }
    void set_rokTreningaKasa(const int r){
        planT.set_rok(r);
    }
    void set_vrstaTreningaKasa(const VRSTA_TRENINGA v){
        planT.set_vrstaTreninga(v);
    }
    void set_majiceKasa(const int m){
        reklamniM.set_majice(m);
    }
    void set_trenerkeKasa(const int t){
        reklamniM.set_trenerke(t);
    }
    void set_kacketiKasa(const int k){
        reklamniM.set_kacketi(k);
    }
    void set_kalendariKasa(const int ka){
        reklamniM.set_kalendari(ka);
    }
    void set_olovkeKasa(const int o){
        reklamniM.set_olovke(o);
    }
    void set_cenaSuplemenataKasa(const int c){
        suplement.set_cena(c);
    }
    void set_vrstaSuplementaKasa(const VRSTA_SUPLEMENATA v){
        suplement.set_suplement(v);
    }
    void set_brojSuplemenataKasa(const int b){
        suplement.set_broj(b);
    }
    bool prodajMajice(int brMajci){
        if(reklamniM.get_majice() >= brMajci){
            reklamniM.set_majice(reklamniM.get_majice() - brMajci);
            return true;
        }
        return false;
    }
    bool prodajTrenerke(int brTrenerki){
        if(reklamniM.get_trenerke() >= brTrenerki){
            reklamniM.set_trenerke(reklamniM.get_trenerke() - brTrenerki);
            return true;
        }
        return false;
    }
    bool prodajKalendare(int BrKalendara){
        if(reklamniM.get_kalendari() >= BrKalendara){
            reklamniM.set_kalendari(reklamniM.get_kalendari() - BrKalendara);
            return true;
        }
        return false;
    }
    bool prodajKackete(int brKacketa){
        if(reklamniM.get_kacketi() >= brKacketa){
            reklamniM.set_kacketi(reklamniM.get_kacketi() - brKacketa);
            return true;
        }
        else{return false;}

    }
    bool prodajOlovke(int BrOlovaka){
        if(reklamniM.get_olovke() >= BrOlovaka){
            reklamniM.set_olovke(reklamniM.get_olovke() - BrOlovaka);
            return true;
        }
        else{return false;}
    }

    bool prodajSuplemente(VRSTA_SUPLEMENATA zeljeniProizvod,int br){
        if(suplement.get_broj() > br && suplement.get_suplement() == zeljeniProizvod){
            suplement.set_broj(suplement.get_broj() - br);
            return true;
        }
        else{return false;}
    }
    Kasa& operator=(const Kasa &k){
        profit = k.profit;
        trosak = k.trosak;
        planT = k.planT;
        suplement = k.suplement;
        clanarina = k.clanarina;
        reklamniM = k.reklamniM;
        return *this;
    }
    friend bool operator ==(Kasa& k1,Kasa& k2) {
        if (k1.get_profit()!=k2.get_profit() || k1.get_trosak()!=k2.get_trosak()|| k1.get_brojSuplementKasa()!=k2.get_brojSuplementKasa() || k1.get_cenaClanarinaKasa()!=k2.get_cenaClanarinaKasa() ||
            k1.get_cenaSuplemenataKasa()!=k2.get_cenaSuplemenataKasa() || k1.get_cenaTreningaKasa()!=k2.get_cenaTreningaKasa() || k1.get_datumUplateKasa()!=k2.get_datumUplateKasa() ||
            k1.get_kacketiKasa()!=k2.get_kacketiKasa() || k1.get_kacketiKasa()!=k2.get_kacketiKasa() || k1.get_kalendariKasa()!=k2.get_kalendariKasa() ||
            k1.get_kvalitetTreningaKasa()!=k2.get_kvalitetTreningaKasa() || k1.get_majiceKasa()!=k2.get_majiceKasa() || k1.get_olovkeKasa()!=k2.get_olovkeKasa() ||
            k1.get_rokTreningaKasa()!=k2.get_rokTreningaKasa() || k1.get_trajanjeClanarineKasa()!=k2.get_trajanjeClanarineKasa() || k1.get_trenerkeKasa()!=k2.get_trenerkeKasa() ||
            k1.get_vrstaSuplemenataKasa()!=k2.get_vrstaSuplemenataKasa() || k1.get_vrstaTreningaKasa()!=k2.get_vrstaTreningaKasa())
        {

            return false;
        }
        else{return true;}
    }
    friend bool operator!=(Kasa&k1,Kasa&k2){
        if(k1 == k2){
            return false;
        }
        else{return true;}
    }
    friend bool operator<(Kasa&k1,Kasa&k2){
        if(k1.get_profit()<k2.get_profit()){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator>(Kasa&k1,Kasa&k2){
        if(k1.get_profit()>k2.get_profit()){
            return true;
        }
        else{
            return false;
        }
    }
};

class Osoba {
protected:
    DinString ime,prezime,datumRodjenja,brTelefona;
public:
    Osoba(){
        ime = "luka";
        prezime = "obradovic";
        datumRodjenja = "24.5.2001.";
        brTelefona = "0605009000";
    }
    Osoba(DinString i,DinString p,DinString dr,DinString b){
        ime = i;
        prezime = p;
        datumRodjenja = dr;
        brTelefona = b;
    }
    Osoba(const Osoba &o){
        ime = o.ime;
        prezime = o.prezime;
        datumRodjenja = o.datumRodjenja;
        brTelefona = o.brTelefona;
    }
    ~Osoba(){}
    DinString get_ime()const{
        return ime;
    }
    DinString get_prezime()const{
        return prezime;
    }
    DinString get_datumRodjenja()const{
        return datumRodjenja;
    }
    DinString get_brTelefona()const{
        return brTelefona;
    }
    void set_ime(const DinString i){
        ime = i;
    }
    void set_prezime(const DinString p){
        prezime = p;
    }
    void set_datumRodjenja(const DinString dr){
        datumRodjenja = dr;
    }
    void set_brTelefona(const DinString b){
        brTelefona = b;
    }
    virtual void odradjenjiPoslovi(){}
};
class Clan : public Osoba {
protected:
    int kodKartice;
    VRSTA_CLANA clan;
    Clanarina clanarina;
    int brClanova;
public:
    Clan() : Osoba() , clanarina(){
        kodKartice = 123;
        clan = OBICAN;
        brClanova = 50;
    }
    Clan(DinString i,DinString p,DinString dr,DinString b,int cena,DinString du,int tra,int k, VRSTA_CLANA c,int bc) : Osoba(i,p,dr,b) , clanarina(cena,du,tra){
        kodKartice = k;
        clan = c;
        brClanova = bc;
    }
    Clan(const Clan& c) : Osoba((Osoba)c),clanarina(c.clanarina) {
        kodKartice = c.kodKartice;
        clan = c.clan;
        brClanova = c.brClanova;
    }
    ~Clan(){}
    int get_kodKartice()const {
        return kodKartice;
    }
    VRSTA_CLANA get_vrstaClana()const {
        return clan;
    }
    int get_brClanova()const{
        return brClanova;
    }
    void set_kodKartice(const int k) {
        kodKartice = k;
    }
    void set_vrstaClana(const VRSTA_CLANA c) {
        clan = c;
    }
    void set_brClanoca(const int c){
        brClanova = c;
    }
    friend ostream& operator<<(ostream& out, const Clan& c){
        if(c.brClanova > 0){
            out << "CLAN br.";
            out << c.brClanova<<":"<<endl;
            out << "\tIme:";
            out << c.ime<<endl;
            out << "\tPrezime:";
            out << c.prezime<<endl;
            out << "\tDatum rodjenja:";
            out << c.datumRodjenja<<endl;
            out << "\tBroj telefona:";
            out << c.brTelefona<<endl;
            out << "\tDatum uplate:";
            out << c.clanarina.get_datumUplate()<<endl;
            out << "\tKod kartice:";
            out << c.kodKartice<<endl;
            out << "\tTip clana:";
            if(c.clan == OBICAN){
                out << "Svakodnevni";
            }
            else if(c.clan == VIP){
                out << "VIP";
            }
            else{
                out << "Tip clana ne postoji.";
            }
            out << "\nClanarina vazi ";
            out << c.clanarina.get_trajanje();
            out << " dana";
        }

        return  out;
    }

};
class Zaposleni : public Osoba {
protected:
    int brZaposleni;
    ZAPOSLENI zaposleni;
public:
    Zaposleni() : Osoba() {
        brZaposleni = 5;
        zaposleni = TRENER;
    }
    Zaposleni(DinString i,DinString p,DinString dr,DinString br,int b, ZAPOSLENI z) : Osoba(i,p,dr,br) {
        brZaposleni = b;
        zaposleni = z;
    }
    Zaposleni(const Zaposleni& z) : Osoba((Osoba)z) {
        brZaposleni = z.brZaposleni;
        zaposleni = z.zaposleni;
    }
    ~Zaposleni(){}
    int get_brZaposlenih()const {
        return brZaposleni;
    }
    ZAPOSLENI get_zaposleni()const {
        return zaposleni;
    }
    void set_brZaposlenih(const int z) {
        brZaposleni = z;
    }
    void set_zaposleni(const ZAPOSLENI s) {
        zaposleni = s;
    }
    void odradjenjiPoslovi(ZAPOSLENI z){
        if(z == TRENER){
            cout << ",sefe, danas sam uradio 5 personalnih treninga."<<endl;
        }
        else if(z == CISTACICA){
            cout << ",sefe, prostorije su sve ociscene."<<endl;
        }
        else{
            cout << ",sefe, posto vas danas nije bilo na poslu, da vam javim"<<endl<<"\tda je sve odradjeno danas kao i svaki drugi dan."<<endl;
        }
    }
    friend ostream& operator<<(ostream& out, const Zaposleni& z){
        if(z.brZaposleni > 0){
            out << "ZAPOSLENI br.";
            out << z.brZaposleni<<":"<<endl;
            out << "\tIme:";
            out << z.ime<<endl;
            out << "\tPrezime:";
            out << z.prezime<<endl;
            out << "\tDatum rodjenja:";
            out << z.datumRodjenja<<endl;
            out << "\tBroj telefona:";
            out << z.brTelefona<<endl;
            out << "\tTip zaposlenog:";
            if(z.zaposleni == CISTACICA){
                out << "Cistacica";
            }
            else if(z.zaposleni == TRENER){
                out << "Personalni trener";
            }
            else if(z.zaposleni == POMOCNIK){
                out << "Desna ruka teretane";
            }
            else{
                out << "Ovakav zaposleni ne postoji.";
            }
            Zaposleni z1;
            z1.odradjenjiPoslovi(z.zaposleni);
        }
        return out;
    }
   /*
    friend bool operator==(Zaposleni &z1,Zaposleni &z2){
        if(z1.get_brTelefona()!=z2.get_brTelefona()){
            return false;
        }
        else{
            return true;
        }
    }
    friend bool operator!=(Zaposleni &z1,Zaposleni &z2){
        if(z1 == z2){
            return false;
        }
        else{
            return true;
        }
    }
    */
};

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
    Teretana() : kasa(),info(),inventar() {
        cisto = true;
        maxZaposleni = 10;
        maxClanova = 200;
        naziv = "HERKUL";
    }
    Teretana(int m,int t,int k,int kal,int ol,int kval,int c,int r,VRSTA_TRENINGA vt,int ce,VRSTA_SUPLEMENATA vs,int g,int cen,DinString dd,int traj,int p,int tr,GRAD gg, DinString u, int br, int prv, int krv, int kkk, int ttt, int v, DinString tel, DANI d,int pp, int kk, int mm,bool a,int mz,int mc,DinString nazi) : kasa(m,t,k,kal,ol,kval,c,r,vt,ce,vs,g,cen,dd,traj,p,tr),info(gg,u,br,prv,krv,kkk,ttt,v,tel,d),inventar(pp,kk,mm) {
        cisto = a;
        maxZaposleni = mz;
        maxClanova = mc;
        naziv = nazi;
    }
    Teretana(const Teretana &t) : kasa(t.kasa),info(t.info),inventar(t.inventar){
        cisto = t.cisto;
        maxZaposleni = t.maxZaposleni;
        maxClanova = t.maxClanova;
        naziv = t.naziv;
    }
    ~Teretana(){}
    Info& get_info(){
        return info;
    }
    Kasa& get_kasa(){
        return kasa;
    }
    Inventar& get_inventar(){
        return inventar;
    }
    List<Zaposleni>& get_zaposleni(){
        return zaposlen;
    }
    List<Clan>& get_clan(){
        return clan;
    }
    DinString get_naziv()const{
        return naziv;
    }
    bool get_cisto()const{

        return cisto;
    }
    int get_maxZaposleni()const{
        return maxZaposleni;
    }
    int get_maxClanovi()const{
        return maxClanova;
    }
    void set_cisto(const bool c){
        cisto = c;
    }
    void set_maxZaposleni(const int z){
        maxZaposleni = z;
    }
    void set_maxClanovi(const int h){
        maxClanova = h;
    }
    void set_naziv(const DinString n){
        naziv = n;
    }

    int get_profitTrt()const{
        return kasa.get_profit();
    }
    int get_trosakTrt()const{
        return kasa.get_trosak();
    }
    int get_cenaClanarinaTrt()const{
        return kasa.get_cenaClanarinaKasa();
    }
    DinString get_datumUplateTrt()const{
        return kasa.get_datumUplateKasa();
    }
    int get_trajanjeClanarineTrt()const{
        return kasa.get_trajanjeClanarineKasa();
    }
    int get_cenaTreningaTrt()const{
        return kasa.get_cenaTreningaKasa();
    }
    int get_kvalitetTreningaTrt()const{
        return kasa.get_kvalitetTreningaKasa();
    }
    int get_rokTreningaTrt()const{
        return kasa.get_rokTreningaKasa();
    }
    VRSTA_TRENINGA get_vrstaTreningaTrt()const{
        return kasa.get_vrstaTreningaKasa();
    }
    int get_majiceTrt()const{
        return kasa.get_majiceKasa();
    }
    int get_trenerkeTrt()const{
        return kasa.get_trenerkeKasa();
    }
    int get_kacketiTrt()const{
        return kasa.get_kacketiKasa();
    }
    int get_kalendariTrt()const{
        return kasa.get_kalendariKasa();
    }
    int get_olovkeTrt()const{
        return kasa.get_olovkeKasa();
    }
    int get_cenaSuplemenataTrt()const{
        return kasa.get_cenaSuplemenataKasa();
    }
    VRSTA_SUPLEMENATA get_vrstaSuplemenataTrt()const{
        return kasa.get_vrstaSuplemenataKasa();
    }
    int get_brojSuplementTrt()const{
        return kasa.get_brojSuplementKasa();
    }
    void set_profitTrt(const int p){
        kasa.set_profit(p);
    }
    void set_trosakTrt(const int t){
        kasa.set_trosak(t);
    }
    void set_cenaClanarineTrt(const int c){
        kasa.set_cenaClanarineKasa(c);
    }
    void set_datumUplateTrt(const DinString d){
        kasa.set_datumUplateKasa(d);
    }
    void set_trajanjeClanarineTrt(const int t){
        kasa.set_trajanjeClanarineKasa(t);
    }
    void set_kvalitetTreningaTrt(const int k){
        kasa.set_kvalitetTreningaKasa(k);
    }
    void set_cenaTreningaTrt(const int c){
        kasa.set_cenaTreningaKasa(c);
    }
    void set_rokTreningaTrt(const int r){
        kasa.set_rokTreningaKasa(r);
    }
    void set_vrstaTreningaTrt(const VRSTA_TRENINGA v){
        kasa.set_vrstaTreningaKasa(v);
    }
    void set_majiceTrt(const int m){
        kasa.set_majiceKasa(m);
    }
    void set_trenerkeTrt(const int t){
        kasa.set_trenerkeKasa(t);
    }
    void set_kacketiTrt(const int k){
        kasa.set_kacketiKasa(k);
    }
    void set_kalendariTrt(const int ka){
        kasa.set_kalendariKasa(ka);
    }
    void set_olovkeTrt(const int o){
        kasa.set_olovkeKasa(o);
    }
    void set_cenaSuplemenataTrt(const int c){
        kasa.set_cenaSuplemenataKasa(c);
    }
    void set_vrstaSuplementaTrt(const VRSTA_SUPLEMENATA v){
        kasa.set_vrstaSuplementaKasa(v);
    }
    void set_brojSuplemenataTrt(const int b){
            kasa.set_brojSuplemenataKasa(b);
    }

    int get_pocetakRadnoVremenaTrt()const {
        return info.get_pocetakRadnoVremenaInfo();
    }
    int get_krajkRadnoVremenaTrt()const{
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
    void set_pocetakRadnoVremenaTrt(const int p){
        info.set_pocetakRadnoVremenaInfo(p);
    }
    void set_krajRadnoVremenaTrt(const int k){
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

    bool dodajClana(const Clan &c){
        if(clan.size() < maxClanova){
            return clan.add(clan.size()+1,c);
        }
        else{
           return false;
        }
    }

    void popisClanova(){
        if(clan.size() == 0){
            cout << "nemate clanova u teretani"<<endl;
        }
        else{
            Clan c;
            cout << "\t    CLANOVI\t    CLANOVI\t    CLANOVI"<<endl;
            cout << "====================================================================" << endl;
            for(int i = 1; i <= clan.size();i++){
                clan.read(i,c);
                cout << c << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    bool zaposliOsobu(const Zaposleni &z){
        if(zaposlen.size() < maxZaposleni){
           return zaposlen.add(zaposlen.size()+1,z);
        }
        else{
           return false;
        }
    }
    void vidiStanjeZaposlenih(){
        if(zaposlen.size()==0){
            cout << "niste jos nikoga zaposlili."<<endl;
        }
        else{
            Zaposleni zz;
            cout << "\t   ZAPOSLENI\t  ZAPOSLENI\t   ZAPOSLENI";
            cout << "\n====================================================================" << endl;
            for(int i = 1;i <= zaposlen.size();i++){
                zaposlen.read(i,zz);
                cout << zz << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    friend ostream& operator<<(ostream& out, const Teretana& t){
        out << t.get_naziv();
        return out;
    }
    Teretana& operator=(const Teretana &t){
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
    friend bool operator==(Teretana &t1,Teretana &t2){
        if(t1.get_kasa()!=t2.get_kasa() || t1.get_info()!=t2.get_info() || t1.get_inventar()!=t2.get_inventar() ||
           t1.get_cisto()!=t2.get_cisto() ||t1.get_maxZaposleni()!=t2.get_maxZaposleni() || t1.get_maxClanovi()!=t2.get_maxClanovi() ||
           t1.get_naziv()!=t2.get_naziv()){

            return false;
        }
        return true;
    }
    friend bool operator!=(Teretana &t1,Teretana &t2){
        if(t1 == t2){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator<(Teretana &t1,Teretana &t2){
        if(t1.get_velicinaTrt() < t2.get_velicinaTrt()){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator>(Teretana &t1,Teretana &t2){
        if(t1.get_velicinaTrt() > t2.get_velicinaTrt()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    Teretana tr;
    cout <<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<endl;
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
    Adresa a1(SRBOBRAN, "Sveti Sava", 4);
    Adresa a2(a1);

    Info i3();
    Info i1(SRBOBRAN, "Sveti Sava", 4, 10, 22, 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA);
    Info i2(i1);
    Info in;
    in.vidiRadnoVreme();

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
    Suplementi sup1(150, PROTEIN,1000);
    Suplementi sup2(sup1);

    Clanarina c4();
    Clanarina c2(2000, "1.4.2020.", 30);
    Clanarina c3(c2);

    Osoba os();
    Osoba os1("Marko","Milosevic","10.10.2001.","0615019011");
    Osoba os2(os1);

    Clan cl2();
    Clan cl3("Luka","Obradovic","12.12.2001.","0605009000",2000,"1.3.2020.",30,123, OBICAN,1);
    Clan cl4("Milos","Markovic","11.11.2000.","0605007800",2000,"1.5.2020.",30,444, VIP,2);
    Clan cl5(cl3);

    Zaposleni z();
    Zaposleni z1("Todor","Todorovic","12.12.2001.","0635039033",1,POMOCNIK);
    Zaposleni z2(z1);

    Kasa ka();
    Kasa ka1(50,50,20,25,80,90,20000,40,FITNES,150,PROTEIN,1000,2000,"3.3.2020",30,100000,30000);
    Kasa ka2(ka1);

    Teretana ter();
    Teretana ter1(50,50,20,25,80,90,20000,40,FITNES,150,PROTEIN,1000,2000,"3.3.2020",30,100000,30000,SRBOBRAN, "Sveti Sava", 4, 10, 22, 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA,10, 400, 400,true,10,200,"HERKUL");
    Teretana ter5(55,55,25,30,90,95,20000,45,BODYWEIGHT,150,KREATIN,1000,2500,"5.4.2020",30,120000,40000,NOVI_SAD, "Sveti Nikola", 6, 10, 22, 30, 4, 55, "0623150983", PRAZNICI,15, 500, 500,true,15,250,"APOLON");
    Teretana ter2(ter1);
    tr.dodajClana(cl3);
    tr.dodajClana(cl4);
    tr.popisClanova();
    tr.zaposliOsobu(z1);
    tr.vidiStanjeZaposlenih();
    if(ter1 != ter5){
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste."<<endl;
    }
    else{
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste."<<endl;
    }

    if(ter1 < ter5){
        cout << "teretana '" << ter1 << "' je manja od '" << ter5 << "' teretane." << endl;
    }
    else if(ter1 > ter5){
        cout << "teretana '" << ter1 << "' je veca od '" << ter5 << "' teretane." << endl;
    }
    else{
        cout << "teretane '" << ter1 << "' i '"<< ter5 << " su iste povrsine."<<endl;
    }
    ter5 = ter1;
    if(ter1 == ter5){
           cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste."<<endl;
    }
    else{
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste."<<endl;
    }

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
