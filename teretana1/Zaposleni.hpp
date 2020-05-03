#include <iostream>
#include "Osoba.hpp"
using namespace std;
enum ZAPOSLENI { TRENER = 1,CISTACICA,POMOCNIK };
class Zaposleni : public Osoba {
protected:
    int brZaposleni;
    ZAPOSLENI zaposleni;
public:
    Zaposleni() : Osoba() {
        brZaposleni = 5;
        zaposleni = TRENER;
    }
    Zaposleni(DinString i, DinString p, DinString dr, DinString br, int b, ZAPOSLENI z) : Osoba(i, p, dr, br) {
        brZaposleni = b;
        zaposleni = z;
    }
    Zaposleni(const Zaposleni& z) : Osoba((Osoba)z) {
        brZaposleni = z.brZaposleni;
        zaposleni = z.zaposleni;
    }
    ~Zaposleni() {}
    int get_brZaposlenih()const {
        return brZaposleni;
    }
    ZAPOSLENI get_zaposleni()const {
        return zaposleni;
    }
    void set_brZaposlenih(const int z) {
        brZaposleni = z;
    }
    void set_zaposleni(const ZAPOSLENI s) {
        zaposleni = s;
    }
    void odradjenjiPoslovi(ZAPOSLENI z) {
        if (z == TRENER) {
            cout << ",sefe, danas sam uradio 5 personalnih treninga." << endl;
        }
        else if (z == CISTACICA) {
            cout << ",sefe, prostorije su sve ociscene." << endl;
        }
        else {
            cout << ",sefe, posto vas danas nije bilo na poslu, da vam javim" << endl << "\tda je sve odradjeno danas kao i svaki drugi dan." << endl;
        }
    }
    friend ostream& operator<<(ostream& out, const Zaposleni& z) {
        if (z.brZaposleni > 0) {
            out << "ZAPOSLENI br.";
            out << z.brZaposleni << ":" << endl;
            out << "\tIme:";
            out << z.ime << endl;
            out << "\tPrezime:";
            out << z.prezime << endl;
            out << "\tDatum rodjenja:";
            out << z.datumRodjenja << endl;
            out << "\tBroj telefona:";
            out << z.brTelefona << endl;
            out << "\tTip zaposlenog:";
            if (z.zaposleni == CISTACICA) {
                out << "Cistacica";
            }
            else if (z.zaposleni == TRENER) {
                out << "Personalni trener";
            }
            else if (z.zaposleni == POMOCNIK) {
                out << "Desna ruka teretane";
            }
            else {
                out << "Ovakav zaposleni ne postoji.";
            }
            Zaposleni z1;
            z1.odradjenjiPoslovi(z.zaposleni);
        }
        return out;
    }
    /*
     friend bool operator==(Zaposleni &z1,Zaposleni &z2){
         if(z1.get_brTelefona()!=z2.get_brTelefona()){
             return false;
         }
         else{
             return true;
         }
     }
     friend bool operator!=(Zaposleni &z1,Zaposleni &z2){
         if(z1 == z2){
             return false;
         }
         else{
             return true;
         }
     }
     */
};
#endif
