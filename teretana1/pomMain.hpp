#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
#include "RadnoVreme.hpp"
#include "Adresa.hpp"
#include "Info.hpp"
#include "Ostava.hpp"
#include "Svlacionica.hpp"
#include "Kupatilo.hpp"
#include "Prostorija.hpp"
#include "Tegovi.hpp"
#include "Sprava.hpp"
#include "FitnesOprema.hpp"
#include "Oprema.hpp"
#include "Inventar.hpp"
#include "Osoba.hpp"
#include "Zaposleni.hpp"
#include "Clan.hpp"
#include "ReklamniMaterijal.hpp"
#include "Suplementi.hpp"
#include "Clanarina.hpp"
#include "PlanTreninga.hpp"
#include "Kasa.hpp"
#include "Teretana.hpp"
using namespace std;
int main()
{
    Teretana tr;
    cout <<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<"\t"<<tr.get_naziv()<<endl;
    //List<Oprema> opreme;
    Oprema o1(5, SIPKA, 60, 75, RUKE, ODLICNO, 20, 90, STRUNJACA, 2, 40, 80);
    Oprema o2(10, BUCICA, 65, 85, RAME, LOSE, 25, 90, LOPTA, 3, 45, 75);
    /*  opreme.add(1, o1);
      opreme.add(2, o2);

      Oprema o;
      for (int i = 1; i <= opreme.size(); i++) {
          opreme.read(i, o);

          cout << "\n\n\n\t\tOPREMA BR. " << i << " JESTE SLEDECA:\n" << o << endl;
      };
*/
    Inventar i;
    cout << "====================================================================" << endl;
    i.kupiOpremu(o1);
    i.kupiOpremu(o2);
    i.vidiOpremu();

    List<Prostorija> prostorija;
    Prostorija p1(10, 20, SAJLA, OSVEZIVAC, 10, 3, 5, 5, 15, 3, 15, 3, true);
    Prostorija p2(20, 25, TEG, SPREJ, 9, 2, 4, 4, 14, 2, 14, 2, false);

    i.kupiStvari(p1);
    i.kupiStvari(p2);
    i.vidiStanjeProstorija();

    RadnoVreme r();
    RadnoVreme r1(10, 22);
    RadnoVreme r2(r1);

    Adresa a();
    Adresa a1(SRBOBRAN, "Sveti Sava", 4);
    Adresa a2(a1);

    Info i3();
    Info i1(SRBOBRAN, "Sveti Sava", 4, 10, 22, 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA);
    Info i2(i1);
    Info in;
    in.vidiRadnoVreme();

    Ostava ostava();
    Ostava ostava1(50, 20, SAJLA, OSVEZIVAC);
    Ostava ostava2(ostava1);

    Svlacionica s();
    Svlacionica s1(10, 5, 10, 3, true);
    Svlacionica s2(s1);

    Kupatilo k();
    Kupatilo k1(7, 2, 3, 3);
    Kupatilo k2(k1);

    Prostorija pr();
    Prostorija pr1(50, 20, SAJLA, OSVEZIVAC, 7, 2, 3, 3, 10, 5, 10, 3, true);
    Prostorija pr2(pr1);

    Tegovi t();
    Tegovi t1(20, SIPKA, 60, 75);
    Tegovi t2(t1);

    Sprava spr();
    Sprava spr1(RUKE, ODLICNO, 20, 90);
    Sprava spr2(spr1);

    FitnesOprema f();
    FitnesOprema f1(STRUNJACA, 2, 40, 80);
    FitnesOprema f2(f1);

    Oprema o();
    Oprema o3(20, SIPKA, 60, 75, RUKE, ODLICNO, 20, 90, STRUNJACA, 2, 40, 80);
    Oprema o4(o3);

    Inventar ii();
    Inventar ii1(10, 400, 400);
    Inventar ii2(ii1);

    ReklamniMaterijal rm();
    ReklamniMaterijal rm1(50, 50, 20, 25, 80);
    ReklamniMaterijal rm2(rm1);

    PlanTreninga pt();
    PlanTreninga pt1(90, 2000, 40, FITNES);
    PlanTreninga pt2(pt1);

    Suplementi sup();
    Suplementi sup1(150, PROTEIN,1000);
    Suplementi sup2(sup1);

    Clanarina c4();
    Clanarina c2(2000, "1.4.2020.", 30);
    Clanarina c3(c2);

    Osoba os();
    Osoba os1("Marko","Milosevic","10.10.2001.","0615019011");
    Osoba os2(os1);

    Clan cl2();
    Clan cl3("Luka","Obradovic","12.12.2001.","0605009000",2000,"1.3.2020.",30,123, OBICAN,1);
    Clan cl4("Milos","Markovic","11.11.2000.","0605007800",2000,"1.5.2020.",30,444, VIP,2);
    Clan cl5(cl3);

    Zaposleni z();
    Zaposleni z1("Todor","Todorovic","12.12.2001.","0635039033",1,POMOCNIK);
    Zaposleni z2(z1);

    Kasa ka();
    Kasa ka1(50,50,20,25,80,90,20000,40,FITNES,150,PROTEIN,1000,2000,"3.3.2020",30,100000,30000);
    Kasa ka2(ka1);

    Teretana ter();
    Teretana ter1(50,50,20,25,80,90,20000,40,FITNES,150,PROTEIN,1000,2000,"3.3.2020",30,100000,30000,SRBOBRAN, "Sveti Sava", 4, 10, 22, 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA,10, 400, 400,true,10,200,"HERKUL");
    Teretana ter5(55,55,25,30,90,95,20000,45,BODYWEIGHT,150,KREATIN,1000,2500,"5.4.2020",30,120000,40000,NOVI_SAD, "Sveti Nikola", 6, 10, 22, 30, 4, 55, "0623150983", PRAZNICI,15, 500, 500,true,15,250,"APOLON");
    Teretana ter2(ter1);
    tr.dodajClana(cl3);
    tr.dodajClana(cl4);
    tr.popisClanova();
    tr.zaposliOsobu(z1);
    tr.vidiStanjeZaposlenih();
    if(ter1 != ter5){
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste."<<endl;
    }
    else{
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste."<<endl;
    }

    if(ter1 < ter5){
        cout << "teretana '" << ter1 << "' je manja od '" << ter5 << "' teretane." << endl;
    }
    else if(ter1 > ter5){
        cout << "teretana '" << ter1 << "' je veca od '" << ter5 << "' teretane." << endl;
    }
    else{
        cout << "teretane '" << ter1 << "' i '"<< ter5 << " su iste povrsine."<<endl;
    }
    ter5 = ter1;
    if(ter1 == ter5){
           cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste."<<endl;
    }
    else{
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste."<<endl;
    }

}
#endif
