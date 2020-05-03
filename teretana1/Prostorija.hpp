#include <iostream>

using namespace std;

class Prostorija {
protected:
    int predmeti;
public:
    Prostorija() {
        predmeti = 400;
    }
    Prostorija(int d) {
        predmeti = d;
    }
    Prostorija(const Prostorija& p) {
        predmeti = p.predmeti;
    }
    ~Prostorija() {}
    int get_predmeti()const {
        return predmeti;
    }
    void set_predmeti(const int v) {
        predmeti = v;
    }
    virtual DinString vratiTip(){}
    virtual DinString vratiTip2(){}
    virtual int vratiBroj(){}
};
#endif
