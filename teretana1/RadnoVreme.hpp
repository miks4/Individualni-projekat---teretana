#include <iostream>
#include "dinstring.hpp"
using namespace std;
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
#endif
