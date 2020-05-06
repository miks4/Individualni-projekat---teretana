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
enum ZAPOSLENI { TRENER = 1, CISTACICA, POMOCNIK };

class RadnoVreme {

private:
    DinString krajRadnogVremena;
    DinString pocetakRadnogVremena;

public:
    RadnoVreme() {
        krajRadnogVremena = "10:00:00AM";
        pocetakRadnogVremena = "22:00:00PM";
    }
    RadnoVreme(DinString k,DinString p) {
        krajRadnogVremena = k;
        pocetakRadnogVremena = p;
    }
    RadnoVreme(const RadnoVreme& k) {
        pocetakRadnogVremena = k.pocetakRadnogVremena;
        krajRadnogVremena = k.pocetakRadnogVremena;
    }
    ~RadnoVreme() {}
    DinString get_kraj()const {
        return krajRadnogVremena;
    }
    DinString get_pocetak()const {
        return pocetakRadnogVremena;
    }
    void set_kraj(const DinString k) {
        krajRadnogVremena = k;
    }
    void set_pocetak(const DinString p) {
        pocetakRadnogVremena = p;
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

class Prostorija {
protected:
    int predmeti;
public:
    Prostorija() {
        predmeti = 400;
    }
    Prostorija(int d) {
        predmeti = d;
    }
    Prostorija(const Prostorija& p) {
        predmeti = p.predmeti;
    }
    ~Prostorija() {}
    int get_predmeti()const {
        return predmeti;
    }
    void set_predmeti(const int v) {
        predmeti = v;
    }
    virtual DinString vratiTip(){}
    virtual DinString vratiTip2(){}
    virtual int vratiBroj(){}
};

class Ostava : public Prostorija{
protected:
    int rezervniDelovi;
    int higijenskaredstva;
    REZERVNI_DEO tipRezervnogDela;
    SREDSTVO_ZA_HIGIJENU tipHigijenskogSredstva;
public:
    Ostava() : Prostorija(){
        rezervniDelovi = 50;
        higijenskaredstva = 20;
        tipRezervnogDela = SAJLA;
        tipHigijenskogSredstva = SPREJ;
    }
    Ostava(int d, int s, REZERVNI_DEO r, SREDSTVO_ZA_HIGIJENU h,int pr) : Prostorija(pr) {
        rezervniDelovi = d;
        higijenskaredstva = s;
        tipRezervnogDela = r;
        tipHigijenskogSredstva = h;
    }
    Ostava(const Ostava& o) : Prostorija((Prostorija)o) {
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
    DinString vratiTip(){

        if(tipHigijenskogSredstva == OSVEZIVAC){
            return " Osvezivac.";
        }
        else if(tipHigijenskogSredstva == KRPA){
            return " Krpa.";
        }
        else{
            return " Sprej.";
        }
    }
    DinString vratiTip2(){
        if(tipRezervnogDela == TEG){
            return " Teg.";
        }
        else if(tipRezervnogDela == SAJLA){
            return " Sajla.";
        }
        else if(tipRezervnogDela == POMOCNA_SIPKA){
            return " Sipka.";
        }
        else{
            return " Sundjer.";
        }
    }
    int vratiBroj(){
        return higijenskaredstva + rezervniDelovi;
    }
};
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

class Oprema{
protected:
    float kvalitet;
    int kvantitet;
public:
    Oprema()  {
        kvalitet = 100;
        kvantitet = 170;
    }
    Oprema(int bf, float kf){
        kvalitet = 80;
        kvantitet = 150;
    }
    Oprema(const Oprema& o) {
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

    virtual DinString vratiTip(){}
};

class Tegovi : public Oprema{
protected:
    int tezina;
    VRSTA_TEGA teg;
    int brTegova;
    float kvalitetTegova;
public:
    Tegovi() : Oprema() {
        tezina = 20;
        teg = SIPKA;
        brTegova = 60;
        kvalitetTegova = 75;
    }
    Tegovi(int t, VRSTA_TEGA v, int b, float k,int kvan,float kval) : Oprema(kvan,kval) {
        tezina = t;
        teg = v;
        brTegova = b;
        kvalitetTegova = k;
    }
    Tegovi(const Tegovi& t) : Oprema(t.kvalitet,t.kvantitet) {
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
    DinString vratiTip(){
        if(teg == SIPKA){
            return " Sipka.";
        }
        else{
            return " Bucica.";
        }
    }
};
class Sprava : public Oprema{
private:
    TIP_SPRAVE tipSPrave;
    STANJE_SPRAVE stanjeSprave;
    float kvalitetSprava;
    static int brSprava;
public:
    Sprava() : Oprema() {
        tipSPrave = RUKE;
        stanjeSprave = ODLICNO;
        kvalitetSprava = 90;
        brSprava++;
    }
    Sprava(TIP_SPRAVE t, STANJE_SPRAVE s, float k,int kvan,float kval) : Oprema(kvan,kval) {
        tipSPrave = t;
        stanjeSprave = s;
        kvalitetSprava = k;
    }
    Sprava(const Sprava& s) : Oprema(s.kvalitet,s.kvantitet) {
        tipSPrave = s.tipSPrave;
        stanjeSprave = s.stanjeSprave;
        kvalitetSprava = s.kvalitetSprava;
    }
    ~Sprava() {brSprava--;}
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
class FitnesOprema : public Oprema{
protected:
    VRSTA_FITNES_OPREME vrstaFitnesOpreme;
    float amortizacija;
    int brFitnesOpreme;
    float kvalitetFitnesOpreme;
    DinString nabavljena;
    DinString garancija;
public:
    FitnesOprema() : Oprema() {
        vrstaFitnesOpreme = STRUNJACA;
        amortizacija = 2;
        brFitnesOpreme = 40;
        kvalitetFitnesOpreme = 80;
        nabavljena = "1.1.2020";
        garancija = "1.1.2021";
    }
    FitnesOprema(VRSTA_FITNES_OPREME v, float a, int b, float k,DinString n,DinString g,int kvan,float kval) : Oprema(kvan,kval) {
        vrstaFitnesOpreme = v;
        amortizacija = a;
        brFitnesOpreme = b;
        kvalitetFitnesOpreme = k;
        nabavljena = n;
        garancija = g;
    }
    FitnesOprema(const FitnesOprema& f) : Oprema(f.kvalitet,f.kvantitet) {
        vrstaFitnesOpreme = f.vrstaFitnesOpreme;
        amortizacija = f.amortizacija;
        brFitnesOpreme = f.brFitnesOpreme;
        kvalitetFitnesOpreme = f.kvalitetFitnesOpreme;
        nabavljena = f.nabavljena;
        garancija = f.garancija;
    }
    ~FitnesOprema() {}
    VRSTA_FITNES_OPREME get_vrstaFitnesOpreme()const {
        return vrstaFitnesOpreme;
    }
    float get_amortizacija()const {
        return amortizacija;
    }
    int get_brFitnesOpreme()const {
        return brFitnesOpreme;
    }
    float get_kvalitetFitnesOpreme()const {
        return kvalitetFitnesOpreme;
    }
    DinString get_nabavljena()const{
        return nabavljena;
    }
    DinString get_garancija()const{
        return garancija;
    }
    void set_vrstaFitnesOpreme(const VRSTA_FITNES_OPREME v) {
        vrstaFitnesOpreme = v;
    }
    void set_amortizacija(const float a) {
        amortizacija = a;
    }
    void set_brFitnesOpreme(const int b) {
        brFitnesOpreme = b;
    }
    void set_kvalitetFitnesOpreme(const float k) {
        kvalitetFitnesOpreme = k;
    }
    void set_naavljena(const DinString n){
        nabavljena = n;
    }
    void set_garancija(const DinString g){
        garancija = g;
    }
    DinString vratiTip(){
        if(vrstaFitnesOpreme == STRUNJACA){return " Strunjaca.";}
        else if(vrstaFitnesOpreme == LOPTA){return " Lopta.";}
        else if(vrstaFitnesOpreme == DZAK){return " DZak.";}
        else{return " Guma.";}
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
    Inventar() : oprema(),prostorija(){
        parkingMesta = 10;
        kapacitet = 400;
        predmetiMax = 400;
    }
    Inventar(int pp, int kk, int mm,List<Oprema> o,List<Prostorija> p) {
        parkingMesta = pp;
        kapacitet = kk;
        predmetiMax = mm;
        oprema = o;
        prostorija = p;
    }
    Inventar(const Inventar& i) : oprema(i.oprema),prostorija(i.prostorija) {
        parkingMesta = i.parkingMesta;
        kapacitet = i.kapacitet;
        predmetiMax = i.predmetiMax;
    }
    ~Inventar() {}
    List<Oprema>& get_oprema() {
        return oprema;
    }
    List<Prostorija>& get_prostorija() {
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
    void set_oprema(List<Oprema> o){
        oprema = o;
    }
    void set_prostorija(List<Prostorija> p){
        prostorija = p;
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
            Oprema *o1;
            Oprema *o2;
            Oprema *o3;
            Tegovi tegic(5,BUCICA,30,70,40,60);
            Sprava spravica(RUKE,ODLICNO,60,30,80);
            FitnesOprema fitneska(STRUNJACA,2,40,80,"1.1.2020","1.1.2021",40,80);
            o1 = &tegic;
            o2 = &spravica;
            o3 = &fitneska;
            cout << "    SPISAK OPREME      SPISAK OPREME       SPISAK OPREME" << endl;
            cout << "====================================================================" << endl;
            for (int i = 1; i <= oprema.size(); i++) {
                    oprema.read(i,o);
                cout << "Broj opreme: " << o.get_kvantitet()<<endl<<"kvalitet opreme: "<< o.get_kvalitet()<<endl;
                oprema.read(i, *o1);
                cout << "Vrsta tega: "<< o1->vratiTip()<<endl;
                oprema.read(i, *o2);
                cout << "Vrsta sprave: " << o2->vratiTip()<<endl;
                oprema.read(i, *o2);
                cout << "Vrsta fitnes opreme: " << o3->vratiTip()<<endl;
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
            Ostava o(30,40,SAJLA,OSVEZIVAC,50);
            Svlacionica s(3,5,5,2,true,50);
            Kupatilo k(5,3,5,5,50);
            Prostorija *p1 = &o;
            Prostorija *p2 = &s;
            Prostorija *p3 = &k;
            cout << " PREGLED PROSTORIJA     PREGLED PROSTORIJA      PREGLED PROSTORIJA" << endl;
            cout << "====================================================================" << endl;
            for (int i = 1; i <= prostorija.size(); i++) {
                cout << "OSTAVA:"<<endl;
                prostorija.read(i, *p1);
                cout << "\tTip pomocnog predmeta: " <<p1->vratiTip() << endl<<"\tTip dezinfikaciong sredstva: " <<p1->vratiTip2() << endl<<"\tIma ih ukupno: " <<p1->vratiBroj()<<endl;
                prostorija.read(i, *p2);
                cout << "SVLACIONICA:"<<endl;
                cout << "\tBroj stvari u svlacionici(ormarici,klupe,cipleranik,civiluci) :" << p2->vratiBroj()<<endl;
                cout << "KUPATILO:" <<endl;
                prostorija.read(i, *p3);
                cout << "\tBroj stvari u kupatilu(ogledala,umivaonici,pisoari i tus kabine) :" << p3->vratiBroj()<<endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    Inventar& operator=(const Inventar& i) {
        parkingMesta = i.parkingMesta;
        kapacitet = i.kapacitet;
        predmetiMax = i.predmetiMax;
        oprema = i.oprema;
        prostorija = i.prostorija;
        return *this;
    }
    friend bool operator==(Inventar& i1, Inventar& i2) {
        if (i1.get_kapacitet() != i2.get_kapacitet() || i1.get_paarkingMesta() != i2.get_paarkingMesta() || i1.get_maxBrojPredmeta() != i2.get_maxBrojPredmeta() ||
            i1.get_oprema() != i2.get_oprema() || i1.get_prostorija() != i2.get_prostorija()) {
            return false;
        }
        else {
            return true;
        }
    }
    friend bool operator!=(Inventar& i1, Inventar& i2) {
        if (i1 == i2) {
            return false;
        }
        else {
            return true;
        }
    }
    friend bool operator<(Inventar& i1, Inventar& i2) {
        if (i1.get_kapacitet() < i2.get_kapacitet()) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator>(Inventar& i1, Inventar& i2) {
        if (i1.get_kapacitet() > i2.get_kapacitet()) {
            return true;
        }
        else {
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
    int brojReklamnogMaterijala() {
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
    static int brSUplemenata;
public:
    Suplementi() {
        cena = 150;
        suplement = PROTEIN;
        brSUplemenata++;
    }
    Suplementi(int c, VRSTA_SUPLEMENATA v) {
        cena = c;
        suplement = v;
    }
    Suplementi(const Suplementi& s) {
        cena = s.cena;
        suplement = s.suplement;
    }
    ~Suplementi() {brSUplemenata--;}
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
    float cena;
    DinString datumUplate;
    DinString trajanje;
public:
    Clanarina() {
        cena = 2000;
        datumUplate = "1.4.2020";
        trajanje = "2.4.2020";
    }
    Clanarina(float c, DinString d, DinString t) {
        cena = c;
        datumUplate = d;
        trajanje = t;
    }
    Clanarina(const Clanarina& c) {
        cena = c.cena;
        datumUplate = c.datumUplate;
        trajanje = c.trajanje;
    }
    ~Clanarina() {}
    float get_cena()const {
        return cena;
    }
    DinString get_datumUplate()const {
        return datumUplate;
    }
    DinString get_trajanje()const {
        return trajanje;
    }
    void set_cena(const float c) {
        cena = c;
    }
    void set_datumUplate(const DinString d) {
        datumUplate = d;
    }
    void set_trajanje(const DinString t) {
        trajanje = t;
    }
    friend ostream& operator<<(ostream& out, const Clanarina& c){
        out << "\n\tDatum uplate: "<<c.get_datumUplate()<<endl<<"\tClanarina Vam vazi do:"<<c.get_trajanje()<<endl<<"\tPlatili ste: "<<c.get_cena()<<" din."<<endl;
        return out;
    }
};

class Kasa {
private:
    double profit;
    double trosak;
    List<ReklamniMaterijal> reklamniM;
    List<PlanTreninga> planT;
    List<Suplementi> suplement;
    List<Clanarina> clanarina;
public:
    Kasa() : reklamniM(), planT(), suplement(), clanarina() {
        profit = 100000;
        trosak = 30000;
    }
    Kasa(double p, double tr,List<ReklamniMaterijal> r,List<PlanTreninga> pl,List<Suplementi> s,List<Clanarina> c) {
        profit = p;
        trosak = tr;
        reklamniM = r;
        planT = pl;
        suplement = s;
        clanarina = c;
    }
    Kasa(const Kasa& k) : reklamniM(k.reklamniM), planT(k.planT), suplement(k.suplement), clanarina(k.clanarina) {
        profit = k.profit;
        trosak = k.trosak;
    }
    ~Kasa() {}
    List<ReklamniMaterijal> get_reklamni(){
        return reklamniM;
    }
    List<PlanTreninga> get_planTreninga(){
        return planT;
    }
    List<Suplementi> get_suplementi(){
        return suplement;
    }
    List<Clanarina> get_clanarina(){
        return clanarina;
    }
    double get_profit()const {
        return profit;
    }
    double get_trosak()const {
        return trosak;
    }

    void set_profit(const double p) {
        profit = p;
    }
    void set_trosak(const double t) {
        trosak = t;
    }
    void set_reklamniMat(List<ReklamniMaterijal> rm)
    {
        reklamniM = rm;
    }
    void set_suplementi(List<Suplementi> sss){
        suplement = sss;
    }
    void set_planTreninga(List<PlanTreninga> pln){
        planT = pln;
    }
    void set_clanrine(List<Clanarina> cla){
        clanarina = cla;
    }
    Kasa& operator=(const Kasa& k) {
        profit = k.profit;
        trosak = k.trosak;
        planT = k.planT;
        suplement = k.suplement;
        clanarina = k.clanarina;
        reklamniM = k.reklamniM;
        return *this;
    }
    friend bool operator ==(Kasa& k1, Kasa& k2) {
        if (k1.get_profit() != k2.get_profit() || k1.get_trosak() != k2.get_trosak())
        {

            return false;
        }
        else { return true; }
    }
    friend bool operator!=(Kasa& k1, Kasa& k2) {
        if (k1 == k2) {
            return false;
        }
        else { return true; }
    }
    friend bool operator<(Kasa& k1, Kasa& k2) {
        if (k1.get_profit() < k2.get_profit()) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator>(Kasa& k1, Kasa& k2) {
        if (k1.get_profit() > k2.get_profit()) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Osoba {
protected:
    DinString ime, prezime, datumRodjenja, brTelefona;
public:
    Osoba() {
        ime = "luka";
        prezime = "obradovic";
        datumRodjenja = "24.5.2001.";
        brTelefona = "0605009000";
    }
    Osoba(DinString i, DinString p, DinString dr, DinString b) {
        ime = i;
        prezime = p;
        datumRodjenja = dr;
        brTelefona = b;
    }
    Osoba(const Osoba& o) {
        ime = o.ime;
        prezime = o.prezime;
        datumRodjenja = o.datumRodjenja;
        brTelefona = o.brTelefona;
    }
    ~Osoba() {}
    DinString get_ime()const {
        return ime;
    }
    DinString get_prezime()const {
        return prezime;
    }
    DinString get_datumRodjenja()const {
        return datumRodjenja;
    }
    DinString get_brTelefona()const {
        return brTelefona;
    }
    void set_ime(const DinString i) {
        ime = i;
    }
    void set_prezime(const DinString p) {
        prezime = p;
    }
    void set_datumRodjenja(const DinString dr) {
        datumRodjenja = dr;
    }
    void set_brTelefona(const DinString b) {
        brTelefona = b;
    }

};
class Clan : public Osoba {
private:
    int kodKartice;
    VRSTA_CLANA clan;
    List<Clanarina> clanarine;
    int brClanova;
public:
    Clan() : Osoba(),clanarine() {
        kodKartice = 123;
        clan = OBICAN;
        brClanova = 50;
    }
    Clan(DinString i, DinString p, DinString dr, DinString b, int k, VRSTA_CLANA c, int bc,List<Clanarina> cla) : Osoba(i, p, dr, b),clanarine(cla) {
        kodKartice = k;
        clan = c;
        brClanova = bc;
    }
    Clan(const Clan& c) : Osoba((Osoba)c),clanarine(c.clanarine) {
        kodKartice = c.kodKartice;
        clan = c.clan;
        brClanova = c.brClanova;
    }
    ~Clan() {}
    List<Clanarina> get_clanarine(){
        return clanarine;
    }
    int get_kodKartice()const {
        return kodKartice;
    }
    VRSTA_CLANA get_vrstaClana()const {
        return clan;
    }
    int get_brClanova()const {
        return brClanova;
    }
    void set_kodKartice(const int k) {
        kodKartice = k;
    }
    void set_vrstaClana(const VRSTA_CLANA c) {
        clan = c;
    }
    void set_brClanoca(const int c) {
        brClanova = c;
    }
    void set_clanarine(List<Clanarina> cla){
        clanarine = cla;
    }
    friend ostream& operator<<(ostream& out,Clan& c) {
        if ( c.get_brClanova() > 0) {

            out << "CLAN br.";
            out << c.brClanova << ":" << endl;
            out << "\tIme:";
            out << c.ime << endl;
            out << "\tPrezime:";
            out << c.prezime << endl;
            out << "\tDatum rodjenja:";
            out << c.datumRodjenja << endl;
            out << "\tBroj telefona:";
            out << c.brTelefona << endl;
            out << "\tKod kartice:";
            out << c.kodKartice << endl;
            out << "\tTip clana:";
            if (c.clan == OBICAN) {
                out << "Svakodnevni";
            }
            else if (c.clan == VIP) {
                out << "VIP";
            }
            else {
                out << "Tip clana ne postoji.";
            }
        }
        return  out;
    }
    bool dodajClanarinu(Clanarina &c){
        return clanarine.add(clanarine.size()+1,c);
    }
        void vidiClanarinu(){
                    if(clanarine.size() == 0){
                cout << "\nNemate clanarinu!"<<endl;
            }
            else{
                Clanarina c;
                cout << "CLANARINE      CLANARINE       CLANARINE";
                cout << "\n====================================================================" << endl;
                for(int i = 1;i <= clanarine.size();i++){
                        clanarine.read(i,c);
                        cout << "Clanarina za "<<i<<". clana:"<<c << endl;
                        cout << "====================================================================" << endl;
                    }
            }
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
    Zaposleni(DinString i, DinString p, DinString dr, DinString br, int b, ZAPOSLENI z) : Osoba(i, p, dr, br) {
        brZaposleni = b;
        zaposleni = z;
    }
    Zaposleni(const Zaposleni& z) : Osoba((Osoba)z) {
        brZaposleni = z.brZaposleni;
        zaposleni = z.zaposleni;
    }
    ~Zaposleni() {}
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
    void odradjenjiPoslovi(ZAPOSLENI z) {
        if (z == TRENER) {
            cout << ",sefe, danas sam uradio 5 personalnih treninga." << endl;
        }
        else if (z == CISTACICA) {
            cout << ",sefe, prostorije su sve ociscene." << endl;
        }
        else {
            cout << ",sefe, posto vas danas nije bilo na poslu, da vam javim" << endl << "\tda je sve odradjeno danas kao i svaki drugi dan." << endl;
        }
    }
    friend ostream& operator<<(ostream& out, const Zaposleni& z) {
        if (z.brZaposleni > 0) {
            out << "ZAPOSLENI br.";
            out << z.brZaposleni << ":" << endl;
            out << "\tIme:";
            out << z.ime << endl;
            out << "\tPrezime:";
            out << z.prezime << endl;
            out << "\tDatum rodjenja:";
            out << z.datumRodjenja << endl;
            out << "\tBroj telefona:";
            out << z.brTelefona << endl;
            out << "\tTip zaposlenog:";
            if (z.zaposleni == CISTACICA) {
                out << "Cistacica";
            }
            else if (z.zaposleni == TRENER) {
                out << "Personalni trener";
            }
            else if (z.zaposleni == POMOCNIK) {
                out << "Desna ruka teretane";
            }
            else {
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
            return true;
        }
        else {
            return false;
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


int Sprava::brSprava = 0;
int Suplementi::brSUplemenata = 0;
int main()
{
    Teretana tr;
    cout << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << endl;
    Oprema o1(40,70);
    //List<Oprema> opreme;
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
    i.vidiOpremu();

    Prostorija prostorija;
    Prostorija p1(40);

    i.kupiStvari(p1);
    i.vidiStanjeProstorija();

    RadnoVreme r();
    RadnoVreme r1("10:00:00AM","22:00:00PM");
    RadnoVreme r2(r1);

    Adresa a();
    Adresa a1(SRBOBRAN, "Sveti Sava", 4);
    Adresa a2(a1);

    Info i3();
    Info i1(SRBOBRAN, "Sveti Sava", 4, "10:00:00AM","22:00:00PM", 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA);
    Info i2(i1);
    Info in;
    in.vidiRadnoVreme();

    Ostava ostava();
    Ostava ostava1(50, 20, SAJLA, OSVEZIVAC,40);
    Ostava ostava2(ostava1);

    Svlacionica s();
    Svlacionica s1(10, 5, 10, 3, true,40);
    Svlacionica s2(s1);

    Kupatilo k();
    Kupatilo k1(7, 2, 3, 3,40);
    Kupatilo k2(k1);

    Prostorija pr();
    Prostorija pr1(40);
    Prostorija pr2(pr1);

    Tegovi t();
    Tegovi t1(20, SIPKA, 60, 75,80,150);
    Tegovi t2(t1);

    Sprava spr();
    Sprava spr1(RUKE, ODLICNO,90,80,150);
    Sprava spr2(spr1);

    FitnesOprema f();
    FitnesOprema f1(STRUNJACA, 2, 40, 80,"1.1.2020","1.1.2021",80,150);
    FitnesOprema f2(f1);

    List<Oprema> opr;
    List<Prostorija> pro;
    Inventar ii();
    Inventar ii1(10, 400, 400,opr,pro);
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

    Clanarina c4();
    Clanarina c2(2000, "1.4.2020.", "2.4.2020");
    Clanarina c5(3000, "4.1.2020.", "4.2.2020");
    Clanarina c3(c2);

    Osoba os();
    Osoba os1("Marko", "Milosevic", "10.10.2001.", "0615019011");
    Osoba os2(os1);

    List<Clanarina> cla;
    Clan cl2();
    Clan cl3("Luka", "Obradovic", "12.12.2001.", "0605009000",123, OBICAN, 1,cla);
    Clan cl4("Milos", "Markovic", "11.11.2000.", "0605007800",444, VIP, 2,cla);
    Clan cl5(cl3);
    Clan cl;


    Zaposleni z();
    Zaposleni z1("Todor", "Todorovic", "12.12.2001.", "0635039033", 1, POMOCNIK);
    Zaposleni z3("Rajko", "Mihajlovic", "6.3.1999.", "0605539333", 2, TRENER);
    Zaposleni z2(z1);

    List<ReklamniMaterijal> ra;
    List<PlanTreninga> pla;
    List<Suplementi> sa;
    List<Clanarina> ca;
    Kasa ka();
    Kasa ka1(50, 50,ra,pla,sa,ca);
    Kasa ka2(ka1);

    List<Zaposleni> zap;
    List<Clan> ccc;
    Teretana ter();
    Teretana ter1(50, 50,ra,pla,sa,ca,SRBOBRAN, "Sveti Sava", 4, "10:00:00AM","22:00:00PM", 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA, 10, 400, 400,opr,pro, true, 10, 200, "HERKUL",zap,ccc);
    Teretana ter5(55, 55,ra,pla,sa,ca,NOVI_SAD, "Sveti Nikola", 6, "10:00:00AM","22:00:00PM", 30, 4, 55, "0623150983", PRAZNICI, 15, 500, 500,opr,pro, true, 15, 250, "APOLON",zap,ccc);
    Teretana ter2(ter1);
    tr.dodajClana(cl3);
    tr.dodajClana(cl4);
    tr.popisClanova();
    cl.dodajClanarinu(c2);
    cl.dodajClanarinu(c5);
    cl.vidiClanarinu();
    tr.zaposliOsobu(z1);
    tr.zaposliOsobu(z3);
    tr.vidiStanjeZaposlenih();
    if (ter1 != ter5) {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste." << endl;
    }
    else {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste." << endl;
    }

    if (ter1 < ter5) {
        cout << "teretana '" << ter1 << "' je manja od '" << ter5 << "' teretane." << endl;
    }
    else if (ter1 > ter5) {
        cout << "teretana '" << ter1 << "' je veca od '" << ter5 << "' teretane." << endl;
    }
    else {
        cout << "teretane '" << ter1 << "' i '" << ter5 << " su iste povrsine." << endl;
    }
    ter5 = ter1;
    if (ter1 == ter5) {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste." << endl;
    }
    else {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste." << endl;
    }

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
