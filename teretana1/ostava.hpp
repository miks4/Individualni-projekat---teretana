#ifndef OSTAVA_HPP_INCLUDED
#define OSTAVA_HPP_INCLUDED
#include <iostream>
#include "prostorija.hpp"
enum REZERVNI_DEO { SAJLA = 1, POMOCNA_SIPKA, TEG, SUNDJER };
enum SREDSTVO_ZA_HIGIJENU { OSVEZIVAC = 1, KRPA, SPREJ };
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

#endif // OSTAVA_HPP_INCLUDED
