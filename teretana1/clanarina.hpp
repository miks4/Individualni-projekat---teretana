#ifndef CLANARINA_HPP_INCLUDED
#define CLANARINA_HPP_INCLUDED
#include <iostream>
#include "dinstring.hpp"
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

#endif // CLANARINA_HPP_INCLUDED
