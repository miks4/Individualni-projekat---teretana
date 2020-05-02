#include <iostream>
#include "dinstring.hpp"
using namespace std;
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

#endif
