#include <iostream>

using namespace std;
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
#endif
