#include <iostream>

using namespace std;
enum GRAD{NOVI_SAD = 0,BEOGRAD,NIS,SRBOBRAN};
class RadnoVreme {
private:
    int krajRadnogVremena;
    int pocetakRadnogVremena;
    int trajanje;
public:
    RadnoVreme() {
        krajRadnogVremena = 22;
        pocetakRadnogVremena = 10;
        trajanje = 12;
    }
    RadnoVreme(int k, int p, int t) {
        krajRadnogVremena = k;
        pocetakRadnogVremena = p;
        trajanje = t;
    }
    RadnoVreme(const RadnoVreme& k) {
        pocetakRadnogVremena = k.pocetakRadnogVremena;
        krajRadnogVremena = k.pocetakRadnogVremena;
        trajanje = k.trajanje;
    }
    int get_kraj()const {
        return krajRadnogVremena;
    }
    int get_pocetak()const {
        return pocetakRadnogVremena;
    }
    int get_trajanje()const {
        return trajanje;
    }
    void set_kraj(const int k){
        krajRadnogVremena = k;
    }
    void set_pocetak(const int p) {
        pocetakRadnogVremena = p;
    }
    void set_trajanje(const int t) {
        trajanje = t;
    }
    bool otvoreno(int v) {
        if ((v > pocetakRadnogVremena) && (v < krajRadnogVremena)){
            return true;
        }
        return false;
    }

};
class Adresa {
private:
    GRAD grad;
    string ulica;
    int ulicniBr;
public:
    Adresa() {
        grad = SRBOBRAN;
        ulica = "Sveti Sava";
        ulicniBr = 4;
    }
    Adresa(GRAD g, string u, int br) {
        grad = g;
        ulica = u;
        ulicniBr = br;
    }
    Adresa(const Adresa& a) {
        grad = a.grad;
        ulica = a.ulica;
        ulicniBr = a.ulicniBr;
    }
    GRAD get_grad()const {
        return grad;
    }
    string get_ulica()const {
        return  ulica;
    }
    int get_brUlice()const {
        return ulicniBr;
    }
    void set_grad(const GRAD g) {
        grad = g;
    }
    void set_ulica(const string u) {
        ulica = u;
    }
    void set_brUlice(const int br) {
        ulicniBr = br;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
