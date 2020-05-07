#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED
#include <iostream>
#include "dinstring.hpp"
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

#endif // OSOBA_HPP_INCLUDED
