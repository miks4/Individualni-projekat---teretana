#include <iostream>

using namespace std;
enum VRSTA_SUPLEMENATA { PROTEIN = 1, KREATIN, AMINOKISELINA };
class Suplementi {
private:
    int cena;
    VRSTA_SUPLEMENATA suplement;
    int broj;
public:
    Suplementi() {
        cena = 150;
        suplement = PROTEIN;
        broj = 1000;
    }
    Suplementi(int c, VRSTA_SUPLEMENATA v,int b) {
        cena = c;
        suplement = v;
        broj = b;
    }
    Suplementi(const Suplementi& s) {
        cena = s.cena;
        suplement = s.suplement;
        broj = s.broj;
    }
    ~Suplementi(){}
    int get_cena()const {
        return cena;
    }
    VRSTA_SUPLEMENATA get_suplement()const {
        return suplement;
    }
    int get_broj()const{
        return broj;
    }
    void set_cena(const int c) {
        cena = c;
    }
    void set_suplement(const VRSTA_SUPLEMENATA v) {
        suplement = v;
    }
    void set_broj(const int b){
        broj = b;
    }
};
#endif
