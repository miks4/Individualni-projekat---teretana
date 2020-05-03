#include <iostream>
#include "dinstring.hpp"
using namespace std;
enum GRAD { NOVI_SAD = 1, BEOGRAD, NIS, SRBOBRAN };
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

#endif
