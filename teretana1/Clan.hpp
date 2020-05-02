#include <iostream>
#include "Osoba.hpp"
#include "Clanarina.hpp"
using namespace std;
enum VRSTA_CLANA { OBICAN = 1, VIP };
class Clan : public Osoba {
protected:
    int kodKartice;
    VRSTA_CLANA clan;
    Clanarina clanarina;
    int brClanova;
public:
    Clan() : Osoba() , clanarina(){
        kodKartice = 123;
        clan = OBICAN;
        brClanova = 50;
    }
    Clan(DinString i,DinString p,DinString dr,DinString b,int cena,DinString du,int tra,int k, VRSTA_CLANA c,int bc) : Osoba(i,p,dr,b) , clanarina(cena,du,tra){
        kodKartice = k;
        clan = c;
        brClanova = bc;
    }
    Clan(const Clan& c) : Osoba((Osoba)c),clanarina(c.clanarina) {
        kodKartice = c.kodKartice;
        clan = c.clan;
        brClanova = c.brClanova;
    }
    ~Clan(){}
    int get_kodKartice()const {
        return kodKartice;
    }
    VRSTA_CLANA get_vrstaClana()const {
        return clan;
    }
    int get_brClanova()const{
        return brClanova;
    }
    void set_kodKartice(const int k) {
        kodKartice = k;
    }
    void set_vrstaClana(const VRSTA_CLANA c) {
        clan = c;
    }
    void set_brClanoca(const int c){
        brClanova = c;
    }
    friend ostream& operator<<(ostream& out, const Clan& c){
        if(c.brClanova > 0){
            out << "CLAN br.";
            out << c.brClanova<<":"<<endl;
            out << "\tIme:";
            out << c.ime<<endl;
            out << "\tPrezime:";
            out << c.prezime<<endl;
            out << "\tDatum rodjenja:";
            out << c.datumRodjenja<<endl;
            out << "\tBroj telefona:";
            out << c.brTelefona<<endl;
            out << "\tDatum uplate:";
            out << c.clanarina.get_datumUplate()<<endl;
            out << "\tKod kartice:";
            out << c.kodKartice<<endl;
            out << "\tTip clana:";
            if(c.clan == OBICAN){
                out << "Svakodnevni";
            }
            else if(c.clan == VIP){
                out << "VIP";
            }
            else{
                out << "Tip clana ne postoji.";
            }
            out << "\nClanarina vazi ";
            out << c.clanarina.get_trajanje();
            out << " dana";
        }

        return  out;
    }

};
#endif
