#ifndef OPREMA_HPP_INCLUDED
#define OPREMA_HPP_INCLUDED
#include <iostream>
class Oprema{
protected:
    float kvalitet;
    int kvantitet;
public:
    Oprema()  {
        kvalitet = 100;
        kvantitet = 170;
    }
    Oprema(int bf, float kf){
        kvalitet = 80;
        kvantitet = 150;
    }
    Oprema(const Oprema& o) {
        kvalitet = o.kvalitet;
        kvantitet = o.kvantitet;
    }
    ~Oprema() {}
    float get_kvalitet()const {
        return kvalitet;
    }
    int get_kvantitet()const {
        return kvantitet;
    }
    void set_kvalitet(const float k) {
        kvalitet = k;
    }
    void set_kvantitet(const int k1) {
        kvantitet = k1;
    }

    virtual DinString vratiTip(){}
};

#endif // OPREMA_HPP_INCLUDED
