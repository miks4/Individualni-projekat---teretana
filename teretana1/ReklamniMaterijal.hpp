#include <iostream>

using namespace std;
class ReklamniMaterijal {
private:
    int majice;
    int trenerke;
    int kacketi;
    int kalendari;
    int olovke;
public:
    ReklamniMaterijal() {
        majice = 50;
        trenerke = 50;
        kacketi = 20;
        kalendari = 25;
        olovke = 80;
    }
    ReklamniMaterijal(int m, int t, int k, int kal, int o) {
        majice = m;
        trenerke = t;
        kacketi = k;
        kalendari = kal;
        olovke = o;
    }
    ReklamniMaterijal(const ReklamniMaterijal& r) {
        majice = r.majice;
        trenerke = r.trenerke;
        kacketi = r.kacketi;
        kalendari = r.kalendari;
        olovke = r.olovke;
    }
    ~ReklamniMaterijal() {}
    int get_majice()const { return majice; }
    int get_trenerke()const { return trenerke; }
    int get_kacketi()const { return kacketi; }
    int get_kalendari()const { return kalendari; }
    int get_olovke()const { return olovke; }
    void set_majice(const int m) { majice = m; }
    void set_trenerke(const int t) { trenerke = t; }
    void set_kacketi(const int k) { kacketi = k; }
    void set_kalendari(const int kal) { kalendari = kal; }
    void set_olovke(const int o) { olovke = o; }
    int brojReklamnogMaterijala(){
       int b = majice + trenerke + kacketi + olovke + kalendari;
       return b;
    }
};

#endif
