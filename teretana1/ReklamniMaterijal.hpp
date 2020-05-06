#include <iostream>

using namespace std;
class ReklamniMaterijal {
private:
    List<DinString> naziv;
    int *kolicinaStvari;
public:
    ReklamniMaterijal() {
        naziv.add(1,"majica");
        kolicinaStvari = (int*)calloc(sizeof(int),1);
        ///majice = 50;
        ///trenerke = 50;
        ///kacketi = 20;
        ///kalendari = 25;
        ///olovke = 80;


    }
    ReklamniMaterijal(List<DinString> ime,int *br) {
        naziv = ime;
        kolicinaStvari = br;
        ///majice
        ///trenerke
        ///kacketi = k;
        ///kalendari = kal;
        ///olovke = o;
    }
    ReklamniMaterijal(const ReklamniMaterijal& r) {
        naziv = r.naziv;
        kolicinaStvari = r.kolicinaStvari;
        ///majice = r.majice;
        ///trenerke = r.trenerke;
        ///kacketi = r.kacketi;
        ///kalendari = r.kalendari;
        ///olovke = r.olovke;
    }
    ~ReklamniMaterijal() {}
//    int get_majice()const { return majice; }
//    int get_trenerke()const { return trenerke; }
//    int get_kacketi()const { return kacketi; }
//    int get_kalendari()const { return kalendari; }
//    int get_olovke()const { return olovke; }
//    void set_majice(const int m) { majice = m; }
//    void set_trenerke(const int t) { trenerke = t; }
//    void set_kacketi(const int k) { kacketi = k; }
//    void set_kalendari(const int kal) { kalendari = kal; }
//    void set_olovke(const int o) { olovke = o; }
//    int brojReklamnogMaterijala() {
//        int b = majice + trenerke + kacketi + olovke + kalendari;
//        return b;
//    }

    void dodajReklamniMaterijal(DinString ime,int br){
        naziv.add(naziv.size()+1,ime);
        kolicinaStvari = (int*)realloc(kolicinaStvari,sizeof(int)*naziv.size());
        kolicinaStvari[naziv.size()-1] = br;

    }
    void vidiStvari(){
        for(int i = 1;i <= naziv.size();i++){
            DinString temp;
            naziv.read(i,temp);
            cout << "naziv: " << temp << endl << "broj stvari: " << kolicinaStvari[i-1]<<endl;
        }
    }
};

#endif
