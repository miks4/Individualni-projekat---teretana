#ifndef KASA_HPP_INCLUDED
#define KASA_HPP_INCLUDED
#include <ostream>
#include "list.hpp"
#include "reklamniMaterijal.hpp"
#include "planTreninga.hpp"
#include "suplementi.hpp"
#include "clanarina.hpp"
class Kasa {
private:
    double profit;
    double trosak;
    List<ReklamniMaterijal> reklamniM;
    List<PlanTreninga> planT;
    List<Suplementi> suplement;
    List<Clanarina> clanarina;
public:
    Kasa() : reklamniM(), planT(), suplement(), clanarina() {
        profit = 100000;
        trosak = 30000;
    }
    Kasa(double p, double tr,List<ReklamniMaterijal> r,List<PlanTreninga> pl,List<Suplementi> s,List<Clanarina> c) {
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
    double get_profit()const {
        return profit;
    }
    double get_trosak()const {
        return trosak;
    }

    void set_profit(const double p) {
        profit = p;
    }
    void set_trosak(const double t) {
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

#endif // KASA_HPP_INCLUDED
