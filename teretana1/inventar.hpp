#ifndef INVENTAR_HPP_INCLUDED
#define INVENTAR_HPP_INCLUDED
#include "list.hpp"
#include "oprema.hpp"
#include "prostorija.hpp"
#include "tegovi.hpp"
#include "sprava.hpp"
#include "fitnesOprema.hpp"
#include "ostava.hpp"
#include "svlacionica.hpp"
#include "kupatilo.hpp"
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

#endif // INVENTAR_HPP_INCLUDED
