#include <iostream>
#include "ReklamniMaterijal.hpp"
#include "PlanTreninga.hpp"
#include "Suplementi.hpp"
#include "Clanarina.hpp"
using namespace std;

class Kasa {
private:
    int profit;
    int trosak;
    ReklamniMaterijal reklamniM;
    PlanTreninga planT;
    Suplementi suplement;
    Clanarina clanarina;
public:
    Kasa() : reklamniM(),planT(),suplement(),clanarina(){
        profit = 100000;
        trosak = 30000;
    }
    Kasa(int m,int t,int k,int kal,int ol,int kval,int c,int r,VRSTA_TRENINGA vt,int ce,VRSTA_SUPLEMENATA vs,int g,int cen,DinString dd,int traj,int p,int tr) : reklamniM(m,t,k,kal,ol),planT(kval,c,t,vt),suplement(ce,vs,g),clanarina(cen,dd,traj){
        profit = p;
        trosak = tr;
    }
    Kasa(const Kasa &k) : reklamniM(k.reklamniM),planT(k.planT),suplement(k.suplement),clanarina(k.clanarina){
        profit = k.profit;
        trosak = k.trosak;
    }
    ~Kasa(){}
    int get_profit()const{
        return profit;
    }
    int get_trosak()const{
        return trosak;
    }
    int get_cenaClanarinaKasa()const{
        return clanarina.get_cena();
    }
    DinString get_datumUplateKasa()const{
        return clanarina.get_datumUplate();
    }
    int get_trajanjeClanarineKasa()const{
        return clanarina.get_trajanje();
    }
    int get_cenaTreningaKasa()const{
        return planT.get_cena();
    }
    int get_kvalitetTreningaKasa()const{
        return planT.get_kvalitet();
    }
    int get_rokTreningaKasa()const{
        return planT.get_rok();
    }
    VRSTA_TRENINGA get_vrstaTreningaKasa()const{
        return planT.get_vrstaTreninga();
    }
    int get_majiceKasa()const{
        return reklamniM.get_majice();
    }
    int get_trenerkeKasa()const{
        return reklamniM.get_trenerke();
    }
    int get_kacketiKasa()const{
        return reklamniM.get_kacketi();
    }
    int get_kalendariKasa()const{
        return reklamniM.get_kalendari();
    }
    int get_olovkeKasa()const{
        return reklamniM.get_olovke();
    }
    int get_cenaSuplemenataKasa()const{
        return suplement.get_cena();
    }
    VRSTA_SUPLEMENATA get_vrstaSuplemenataKasa()const{
        return suplement.get_suplement();
    }
    int get_brojSuplementKasa()const{
        return suplement.get_broj();
    }
    void set_profit(const int p){
        profit = p;
    }
    void set_trosak(const int t){
        trosak = t;
    }
    void set_cenaClanarineKasa(const int c){
        clanarina.set_cena(c);
    }
    void set_datumUplateKasa(const DinString d){
        clanarina.set_datumUplate(d);
    }
    void set_trajanjeClanarineKasa(const int t){
        clanarina.set_trajanje(t);
    }
    void set_kvalitetTreningaKasa(const int k){
        planT.set_kvalitet(k);
    }
    void set_cenaTreningaKasa(const int c){
        planT.set_cena(c);
    }
    void set_rokTreningaKasa(const int r){
        planT.set_rok(r);
    }
    void set_vrstaTreningaKasa(const VRSTA_TRENINGA v){
        planT.set_vrstaTreninga(v);
    }
    void set_majiceKasa(const int m){
        reklamniM.set_majice(m);
    }
    void set_trenerkeKasa(const int t){
        reklamniM.set_trenerke(t);
    }
    void set_kacketiKasa(const int k){
        reklamniM.set_kacketi(k);
    }
    void set_kalendariKasa(const int ka){
        reklamniM.set_kalendari(ka);
    }
    void set_olovkeKasa(const int o){
        reklamniM.set_olovke(o);
    }
    void set_cenaSuplemenataKasa(const int c){
        suplement.set_cena(c);
    }
    void set_vrstaSuplementaKasa(const VRSTA_SUPLEMENATA v){
        suplement.set_suplement(v);
    }
    void set_brojSuplemenataKasa(const int b){
        suplement.set_broj(b);
    }
    bool prodajMajice(int brMajci){
        if(reklamniM.get_majice() >= brMajci){
            reklamniM.set_majice(reklamniM.get_majice() - brMajci);
            return true;
        }
        return false;
    }
    bool prodajTrenerke(int brTrenerki){
        if(reklamniM.get_trenerke() >= brTrenerki){
            reklamniM.set_trenerke(reklamniM.get_trenerke() - brTrenerki);
            return true;
        }
        return false;
    }
    bool prodajKalendare(int BrKalendara){
        if(reklamniM.get_kalendari() >= BrKalendara){
            reklamniM.set_kalendari(reklamniM.get_kalendari() - BrKalendara);
            return true;
        }
        return false;
    }
    bool prodajKackete(int brKacketa){
        if(reklamniM.get_kacketi() >= brKacketa){
            reklamniM.set_kacketi(reklamniM.get_kacketi() - brKacketa);
            return true;
        }
        else{return false;}

    }
    bool prodajOlovke(int BrOlovaka){
        if(reklamniM.get_olovke() >= BrOlovaka){
            reklamniM.set_olovke(reklamniM.get_olovke() - BrOlovaka);
            return true;
        }
        else{return false;}
    }

    bool prodajSuplemente(VRSTA_SUPLEMENATA zeljeniProizvod,int br){
        if(suplement.get_broj() > br && suplement.get_suplement() == zeljeniProizvod){
            suplement.set_broj(suplement.get_broj() - br);
            return true;
        }
        else{return false;}
    }
    Kasa& operator=(const Kasa &k){
        profit = k.profit;
        trosak = k.trosak;
        planT = k.planT;
        suplement = k.suplement;
        clanarina = k.clanarina;
        reklamniM = k.reklamniM;
        return *this;
    }
    friend bool operator ==(Kasa& k1,Kasa& k2) {
        if (k1.get_profit()!=k2.get_profit() || k1.get_trosak()!=k2.get_trosak()|| k1.get_brojSuplementKasa()!=k2.get_brojSuplementKasa() || k1.get_cenaClanarinaKasa()!=k2.get_cenaClanarinaKasa() ||
            k1.get_cenaSuplemenataKasa()!=k2.get_cenaSuplemenataKasa() || k1.get_cenaTreningaKasa()!=k2.get_cenaTreningaKasa() || k1.get_datumUplateKasa()!=k2.get_datumUplateKasa() ||
            k1.get_kacketiKasa()!=k2.get_kacketiKasa() || k1.get_kacketiKasa()!=k2.get_kacketiKasa() || k1.get_kalendariKasa()!=k2.get_kalendariKasa() ||
            k1.get_kvalitetTreningaKasa()!=k2.get_kvalitetTreningaKasa() || k1.get_majiceKasa()!=k2.get_majiceKasa() || k1.get_olovkeKasa()!=k2.get_olovkeKasa() ||
            k1.get_rokTreningaKasa()!=k2.get_rokTreningaKasa() || k1.get_trajanjeClanarineKasa()!=k2.get_trajanjeClanarineKasa() || k1.get_trenerkeKasa()!=k2.get_trenerkeKasa() ||
            k1.get_vrstaSuplemenataKasa()!=k2.get_vrstaSuplemenataKasa() || k1.get_vrstaTreningaKasa()!=k2.get_vrstaTreningaKasa())
        {

            return false;
        }
        else{return true;}
    }
    friend bool operator!=(Kasa&k1,Kasa&k2){
        if(k1 == k2){
            return false;
        }
        else{return true;}
    }
    friend bool operator<(Kasa&k1,Kasa&k2){
        if(k1.get_profit()<k2.get_profit()){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator>(Kasa&k1,Kasa&k2){
        if(k1.get_profit()>k2.get_profit()){
            return true;
        }
        else{
            return false;
        }
    }
};
#endif
