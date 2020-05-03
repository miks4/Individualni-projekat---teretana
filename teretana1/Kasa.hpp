#include <iostream>
#include "List".hpp
#include "ReklamniMaterijal.hpp"
#include "PlanTreninga.hpp"
#include "Suplementi.hpp"
#include "Clanarina.hpp"
using namespace std;

class Kasa {
private:
    float profit;
    float trosak;
    List<ReklamniMaterijal> reklamniM;
    List<PlanTreninga> planT;
    List<Suplementi> suplement;
    List<Clanarina> clanarina;
public:
    Kasa() : reklamniM(), planT(), suplement(), clanarina() {
        profit = 100000;
        trosak = 30000;
    }
    Kasa(float p, float tr,List<ReklamniMaterijal> r,List<PlanTreninga> pl,List<Suplementi> s,List<Clanarina> c) {
        profit = p;
        trosak = tr;
        reklamniM = r;
        planT = pl;
        suplement = s;
        clanarina = c;
    }
    Kasa(const Kasa& k) : reklamniM(k.reklamniM), planT(k.planT), suplement(k.suplement), clanarina(k.clanarina) {
        profit = k.profit;
        trosak = k.trosak;
    }
    ~Kasa() {}
    List<ReklamniMaterijal> get_reklamni(){
        return reklamniM;
    }
    List<PlanTreninga> get_planTreninga(){
        return planT;
    }
    List<Suplementi> get_suplementi(){
        return suplement;
    }
    List<Clanarina> get_clanarina(){
        return clanarina;
    }
    float get_profit()const {
        return profit;
    }
    float get_trosak()const {
        return trosak;
    }

    void set_profit(const float p) {
        profit = p;
    }
    void set_trosak(const float t) {
        trosak = t;
    }
    void set_reklamniMat(List<ReklamniMaterijal> rm)
    {
        reklamniM = rm;
    }
    void set_suplementi(List<Suplementi> sss){
        suplement = sss;
    }
    void set_planTreninga(List<PlanTreninga> pln){
        planT = pln;
    }
    void set_clanrine(List<Clanarina> cla){
        clanarina = cla;
    }
    Kasa& operator=(const Kasa& k) {
        profit = k.profit;
        trosak = k.trosak;
        planT = k.planT;
        suplement = k.suplement;
        clanarina = k.clanarina;
        reklamniM = k.reklamniM;
        return *this;
    }
    friend bool operator ==(Kasa& k1, Kasa& k2) {
        if (k1.get_profit() != k2.get_profit() || k1.get_trosak() != k2.get_trosak())
        {

            return false;
        }
        else { return true; }
    }
    friend bool operator!=(Kasa& k1, Kasa& k2) {
        if (k1 == k2) {
            return false;
        }
        else { return true; }
    }
    friend bool operator<(Kasa& k1, Kasa& k2) {
        if (k1.get_profit() < k2.get_profit()) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator>(Kasa& k1, Kasa& k2) {
        if (k1.get_profit() > k2.get_profit()) {
            return true;
        }
        else {
            return false;
        }
    }
};
#endif
