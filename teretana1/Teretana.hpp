#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
#include "Kasa.hpp"
#include "Info.hpp"
#include "Inventar.hpp"
#include "Zaposleni.hpp"
#include "Clan.hpp"
using namespace std;

class Teretana {
private:
    Kasa kasa;
    Info info;
    Inventar inventar;
    List<Zaposleni> zaposlen;
    List<Clan> clan;
    bool cisto;
    int maxZaposleni;
    int maxClanova;
    DinString naziv;
public:
    Teretana() : kasa(),info(),inventar() {
        cisto = true;
        maxZaposleni = 10;
        maxClanova = 200;
        naziv = "HERKUL";
    }
    Teretana(int m,int t,int k,int kal,int ol,int kval,int c,int r,VRSTA_TRENINGA vt,int ce,VRSTA_SUPLEMENATA vs,int g,int cen,DinString dd,int traj,int p,int tr,GRAD gg, DinString u, int br, int prv, int krv, int kkk, int ttt, int v, DinString tel, DANI d,int pp, int kk, int mm,bool a,int mz,int mc,DinString nazi) : kasa(m,t,k,kal,ol,kval,c,r,vt,ce,vs,g,cen,dd,traj,p,tr),info(gg,u,br,prv,krv,kkk,ttt,v,tel,d),inventar(pp,kk,mm) {
        cisto = a;
        maxZaposleni = mz;
        maxClanova = mc;
        naziv = nazi;
    }
    Teretana(const Teretana &t) : kasa(t.kasa),info(t.info),inventar(t.inventar){
        cisto = t.cisto;
        maxZaposleni = t.maxZaposleni;
        maxClanova = t.maxClanova;
        naziv = t.naziv;
    }
    ~Teretana(){}
    Info& get_info(){
        return info;
    }
    Kasa& get_kasa(){
        return kasa;
    }
    Inventar& get_inventar(){
        return inventar;
    }
    List<Zaposleni>& get_zaposleni(){
        return zaposlen;
    }
    List<Clan>& get_clan(){
        return clan;
    }
    DinString get_naziv()const{
        return naziv;
    }
    bool get_cisto()const{

        return cisto;
    }
    int get_maxZaposleni()const{
        return maxZaposleni;
    }
    int get_maxClanovi()const{
        return maxClanova;
    }
    void set_cisto(const bool c){
        cisto = c;
    }
    void set_maxZaposleni(const int z){
        maxZaposleni = z;
    }
    void set_maxClanovi(const int h){
        maxClanova = h;
    }
    void set_naziv(const DinString n){
        naziv = n;
    }

    int get_profitTrt()const{
        return kasa.get_profit();
    }
    int get_trosakTrt()const{
        return kasa.get_trosak();
    }
    int get_cenaClanarinaTrt()const{
        return kasa.get_cenaClanarinaKasa();
    }
    DinString get_datumUplateTrt()const{
        return kasa.get_datumUplateKasa();
    }
    int get_trajanjeClanarineTrt()const{
        return kasa.get_trajanjeClanarineKasa();
    }
    int get_cenaTreningaTrt()const{
        return kasa.get_cenaTreningaKasa();
    }
    int get_kvalitetTreningaTrt()const{
        return kasa.get_kvalitetTreningaKasa();
    }
    int get_rokTreningaTrt()const{
        return kasa.get_rokTreningaKasa();
    }
    VRSTA_TRENINGA get_vrstaTreningaTrt()const{
        return kasa.get_vrstaTreningaKasa();
    }
    int get_majiceTrt()const{
        return kasa.get_majiceKasa();
    }
    int get_trenerkeTrt()const{
        return kasa.get_trenerkeKasa();
    }
    int get_kacketiTrt()const{
        return kasa.get_kacketiKasa();
    }
    int get_kalendariTrt()const{
        return kasa.get_kalendariKasa();
    }
    int get_olovkeTrt()const{
        return kasa.get_olovkeKasa();
    }
    int get_cenaSuplemenataTrt()const{
        return kasa.get_cenaSuplemenataKasa();
    }
    VRSTA_SUPLEMENATA get_vrstaSuplemenataTrt()const{
        return kasa.get_vrstaSuplemenataKasa();
    }
    int get_brojSuplementTrt()const{
        return kasa.get_brojSuplementKasa();
    }
    void set_profitTrt(const int p){
        kasa.set_profit(p);
    }
    void set_trosakTrt(const int t){
        kasa.set_trosak(t);
    }
    void set_cenaClanarineTrt(const int c){
        kasa.set_cenaClanarineKasa(c);
    }
    void set_datumUplateTrt(const DinString d){
        kasa.set_datumUplateKasa(d);
    }
    void set_trajanjeClanarineTrt(const int t){
        kasa.set_trajanjeClanarineKasa(t);
    }
    void set_kvalitetTreningaTrt(const int k){
        kasa.set_kvalitetTreningaKasa(k);
    }
    void set_cenaTreningaTrt(const int c){
        kasa.set_cenaTreningaKasa(c);
    }
    void set_rokTreningaTrt(const int r){
        kasa.set_rokTreningaKasa(r);
    }
    void set_vrstaTreningaTrt(const VRSTA_TRENINGA v){
        kasa.set_vrstaTreningaKasa(v);
    }
    void set_majiceTrt(const int m){
        kasa.set_majiceKasa(m);
    }
    void set_trenerkeTrt(const int t){
        kasa.set_trenerkeKasa(t);
    }
    void set_kacketiTrt(const int k){
        kasa.set_kacketiKasa(k);
    }
    void set_kalendariTrt(const int ka){
        kasa.set_kalendariKasa(ka);
    }
    void set_olovkeTrt(const int o){
        kasa.set_olovkeKasa(o);
    }
    void set_cenaSuplemenataTrt(const int c){
        kasa.set_cenaSuplemenataKasa(c);
    }
    void set_vrstaSuplementaTrt(const VRSTA_SUPLEMENATA v){
        kasa.set_vrstaSuplementaKasa(v);
    }
    void set_brojSuplemenataTrt(const int b){
            kasa.set_brojSuplemenataKasa(b);
    }

    int get_pocetakRadnoVremenaTrt()const {
        return info.get_pocetakRadnoVremenaInfo();
    }
    int get_krajkRadnoVremenaTrt()const{
        return info.get_krajkRadnoVremenaInfo();
    }
    DANI get_danTrt()const {
        return info.get_dan();
    }
    GRAD get_gradTrt()const {
        return info.get_grad();
    }
    DinString get_ulicaTrt()const {
        return  info.get_ulica();
    }
    int get_brUliceTrt()const {
        return info.get_brUlice();
    }
    int get_kapacitetTrt()const {
        return info.get_kapacitet();
    }
    int get_brTeretanaTrt()const {
        return info.get_brTeretana();
    }
    int get_velicinaTrt()const {
        return info.get_velicina();
    }
    DinString get_telefonTrt()const {
        return info.get_telefon();
    }
    void set_danTrt(const DANI d) {
        info.set_dan(d);
    }
    void set_gradTrt(const GRAD g) {
        info.set_grad(g);
    }
    void set_ulicaTrt(const DinString u) {
        info.set_ulica(u);
    }
    void set_brUliceTrt(const int br) {
        info.set_brUlice(br);
    }
    void set_kapacitetTrt(const int k) {
        info.set_kapacitet(k);
    }
    void set_brTeretanaTrt(const int br) {
        info.set_brTeretana(br);
    }
    void set_velicinaTrt(const int v) {
        info.set_velicina(v);
    }
    void set_telefonTrt(const DinString tel) {
        info.set_telefon(tel);
    }
    void set_pocetakRadnoVremenaTrt(const int p){
        info.set_pocetakRadnoVremenaInfo(p);
    }
    void set_krajRadnoVremenaTrt(const int k){
        info.set_krajRadnoVremenaInfo(k);
    }

    int get_paarkingMestaTrt()const {
        return inventar.get_paarkingMesta();
    }
    int get_kapacitetInventarTrt()const {
        return inventar.get_kapacitet();
    }
    int get_maxBrojPredmetaTrt()const {
        return inventar.get_maxBrojPredmeta();
    }
    void set_parkingMestaTrt(const int p) {
        inventar.set_parkingMesta(p);
    }
    void set_kapacitetInventarTrt(const int k) {
        inventar.set_kapacitet(k);
    }
    void set_maxBrojPredmetaTrt(const int br) {
        inventar.set_maxBrojPredmeta(br);
    }

    bool dodajClana(const Clan &c){
        if(clan.size() < maxClanova){
            return clan.add(clan.size()+1,c);
        }
        else{
           return false;
        }
    }

    void popisClanova(){
        if(clan.size() == 0){
            cout << "nemate clanova u teretani"<<endl;
        }
        else{
            Clan c;
            cout << "\t    CLANOVI\t    CLANOVI\t    CLANOVI"<<endl;
            cout << "====================================================================" << endl;
            for(int i = 1; i <= clan.size();i++){
                clan.read(i,c);
                cout << c << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    bool zaposliOsobu(const Zaposleni &z){
        if(zaposlen.size() < maxZaposleni){
           return zaposlen.add(zaposlen.size()+1,z);
        }
        else{
           return false;
        }
    }
    void vidiStanjeZaposlenih(){
        if(zaposlen.size()==0){
            cout << "niste jos nikoga zaposlili."<<endl;
        }
        else{
            Zaposleni zz;
            cout << "\t   ZAPOSLENI\t  ZAPOSLENI\t   ZAPOSLENI";
            cout << "\n====================================================================" << endl;
            for(int i = 1;i <= zaposlen.size();i++){
                zaposlen.read(i,zz);
                cout << zz << endl;
                cout << "====================================================================" << endl;
            }
        }
    }
    friend ostream& operator<<(ostream& out, const Teretana& t){
        out << t.get_naziv();
        return out;
    }
    Teretana& operator=(const Teretana &t){
        kasa = t.kasa;
        info = t.info;
        inventar = t.inventar;
        zaposlen = t.zaposlen;
        clan = t.clan;
        cisto = t.cisto;
        maxZaposleni = t.maxZaposleni;
        maxClanova = t.maxClanova;
        naziv = t.naziv;
        return *this;
    }
    friend bool operator==(Teretana &t1,Teretana &t2){
        if(t1.get_kasa()!=t2.get_kasa() || t1.get_info()!=t2.get_info() || t1.get_inventar()!=t2.get_inventar() ||
           t1.get_cisto()!=t2.get_cisto() ||t1.get_maxZaposleni()!=t2.get_maxZaposleni() || t1.get_maxClanovi()!=t2.get_maxClanovi() ||
           t1.get_naziv()!=t2.get_naziv()){

            return false;
        }
        return true;
    }
    friend bool operator!=(Teretana &t1,Teretana &t2){
        if(t1 == t2){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator<(Teretana &t1,Teretana &t2){
        if(t1.get_velicinaTrt() < t2.get_velicinaTrt()){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator>(Teretana &t1,Teretana &t2){
        if(t1.get_velicinaTrt() > t2.get_velicinaTrt()){
            return true;
        }
        else{
            return false;
        }
    }
};
#endif
