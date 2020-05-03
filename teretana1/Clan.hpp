#include <iostream>
#include "Osoba.hpp"
#include "Clanarina.hpp"
using namespace std;
enum VRSTA_CLANA { OBICAN = 1, VIP };
class Clan : public Osoba {
private:
    int kodKartice;
    VRSTA_CLANA clan;
    List<Clanarina> clanarine;
    int brClanova;
public:
    Clan() : Osoba(),clanarine() {
        kodKartice = 123;
        clan = OBICAN;
        brClanova = 50;
    }
    Clan(DinString i, DinString p, DinString dr, DinString b, int k, VRSTA_CLANA c, int bc,List<Clanarina> cla) : Osoba(i, p, dr, b),clanarine(cla) {
        kodKartice = k;
        clan = c;
        brClanova = bc;
    }
    Clan(const Clan& c) : Osoba((Osoba)c),clanarine(c.clanarine) {
        kodKartice = c.kodKartice;
        clan = c.clan;
        brClanova = c.brClanova;
    }
    ~Clan() {}
    List<Clanarina> get_clanarine(){
        return clanarine;
    }
    int get_kodKartice()const {
        return kodKartice;
    }
    VRSTA_CLANA get_vrstaClana()const {
        return clan;
    }
    int get_brClanova()const {
        return brClanova;
    }
    void set_kodKartice(const int k) {
        kodKartice = k;
    }
    void set_vrstaClana(const VRSTA_CLANA c) {
        clan = c;
    }
    void set_brClanoca(const int c) {
        brClanova = c;
    }
    void set_clanarine(List<Clanarina> cla){
        clanarine = cla;
    }
    friend ostream& operator<<(ostream& out,Clan& c) {
        if ( c.get_brClanova() > 0) {

            out << "CLAN br.";
            out << c.brClanova << ":" << endl;
            out << "\tIme:";
            out << c.ime << endl;
            out << "\tPrezime:";
            out << c.prezime << endl;
            out << "\tDatum rodjenja:";
            out << c.datumRodjenja << endl;
            out << "\tBroj telefona:";
            out << c.brTelefona << endl;
            out << "\tKod kartice:";
            out << c.kodKartice << endl;
            out << "\tTip clana:";
            if (c.clan == OBICAN) {
                out << "Svakodnevni";
            }
            else if (c.clan == VIP) {
                out << "VIP";
            }
            else {
                out << "Tip clana ne postoji.";
            }
        }
        return  out;
    }
    bool dodajClanarinu(Clanarina &c){
        return clanarine.add(clanarine.size()+1,c);
    }
        void vidiClanarinu(){
                    if(clanarine.size() == 0){
                cout << "\nNemate clanarinu!"<<endl;
            }
            else{
                Clanarina c;
                cout << "CLANARINE      CLANARINE       CLANARINE";
                cout << "\n====================================================================" << endl;
                for(int i = 1;i <= clanarine.size();i++){
                        clanarine.read(i,c);
                        cout << "Clanarina za "<<i<<". clana:"<<c << endl;
                        cout << "====================================================================" << endl;
                    }
            }
        }



};
#endif
