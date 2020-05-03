#include <iostream>
#include "list.hpp"
#include "Oprema.hpp"
#include "Prostorija.hpp"
using namespace std;

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
            Tegovi t;
            Sprava s;
            FitnesOprema f;
            cout << "    SPISAK OPREME      SPISAK OPREME       SPISAK OPREME" << endl;
            cout << "====================================================================" << endl;
            for (int i = 1; i <= oprema.size(); i++) {
                oprema.read(i, o);
                cout << "Broj tegova:"<<t.get_brTegova()<<", vrsta:"<<t.vratiTip()<<endl;
                cout << "Broj sprava: 20"<<", vrsta:"<<s.vratiTip()<<endl;
                cout << "Broj fitnes opreme:"<<f.get_brFitnesOpreme()<<", vrsta:"<<f.vratiTip()<<endl;
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
            Ostava o;
            Svlacionica s;
            Kupatilo k;
            cout << " PREGLED PROSTORIJA     PREGLED PROSTORIJA      PREGLED PROSTORIJA" << endl;
            cout << "====================================================================" << endl;
            for (int i = 1; i <= prostorija.size(); i++) {
                prostorija.read(i, p);
                cout << "OSTAVA"<< endl<< "ukupno predmeta:" << o.vratiBroj() <<endl<<"tip 1.prdmeta:" << o.vratiTip()<<endl<<"tip 2. predmeta"<<o.vratiTip2()<<endl;
                cout << "SVLACIONICA"<< endl<< "ukupno predmeta:" << s.vratiBroj()<<endl;
                cout << "KUPATILO"<< endl<< "ukupno predmeta:" << k.vratiBroj() <<endl;
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
#endif
