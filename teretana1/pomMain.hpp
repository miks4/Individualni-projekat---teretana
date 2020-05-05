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
    cout << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << "\t" << tr.get_naziv() << endl;
    Oprema o1(40,70);
    //List<Oprema> opreme;
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
    i.vidiOpremu();

    Prostorija prostorija;
    Prostorija p1(40);

    i.kupiStvari(p1);
    i.vidiStanjeProstorija();

    RadnoVreme r();
    RadnoVreme r1("10:00:00AM","22:00:00PM");
    RadnoVreme r2(r1);

    Adresa a();
    Adresa a1(SRBOBRAN, "Sveti Sava", 4);
    Adresa a2(a1);

    Info i3();
    Info i1(SRBOBRAN, "Sveti Sava", 4, "10:00:00AM","22:00:00PM", 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA);
    Info i2(i1);
    Info in;
    in.vidiRadnoVreme();

    Ostava ostava();
    Ostava ostava1(50, 20, SAJLA, OSVEZIVAC,40);
    Ostava ostava2(ostava1);

    Svlacionica s();
    Svlacionica s1(10, 5, 10, 3, true,40);
    Svlacionica s2(s1);

    Kupatilo k();
    Kupatilo k1(7, 2, 3, 3,40);
    Kupatilo k2(k1);

    Prostorija pr();
    Prostorija pr1(40);
    Prostorija pr2(pr1);

    Tegovi t();
    Tegovi t1(20, SIPKA, 60, 75,80,150);
    Tegovi t2(t1);

    Sprava spr();
    Sprava spr1(RUKE, ODLICNO,90,80,150);
    Sprava spr2(spr1);

    FitnesOprema f();
    FitnesOprema f1(STRUNJACA, 2, 40, 80,"1.1.2020","1.1.2021",80,150);
    FitnesOprema f2(f1);

    List<Oprema> opr;
    List<Prostorija> pro;
    Inventar ii();
    Inventar ii1(10, 400, 400,opr,pro);
    Inventar ii2(ii1);

    ReklamniMaterijal rm();
    ReklamniMaterijal rm1(50, 50, 20, 25, 80);
    ReklamniMaterijal rm2(rm1);

    PlanTreninga pt();
    PlanTreninga pt1(90, 2000, 40, FITNES);
    PlanTreninga pt2(pt1);

    Suplementi sup();
    Suplementi sup1(150, PROTEIN);
    Suplementi sup2(sup1);

    Clanarina c4();
    Clanarina c2(2000, "1.4.2020.", "2.4.2020");
    Clanarina c5(3000, "4.1.2020.", "4.2.2020");
    Clanarina c3(c2);

    Osoba os();
    Osoba os1("Marko", "Milosevic", "10.10.2001.", "0615019011");
    Osoba os2(os1);

    List<Clanarina> cla;
    Clan cl2();
    Clan cl3("Luka", "Obradovic", "12.12.2001.", "0605009000",123, OBICAN, 1,cla);
    Clan cl4("Milos", "Markovic", "11.11.2000.", "0605007800",444, VIP, 2,cla);
    Clan cl5(cl3);
    Clan cl;


    Zaposleni z();
    Zaposleni z1("Todor", "Todorovic", "12.12.2001.", "0635039033", 1, POMOCNIK);
    Zaposleni z3("Rajko", "Mihajlovic", "6.3.1999.", "0605539333", 2, TRENER);
    Zaposleni z2(z1);

    List<ReklamniMaterijal> ra;
    List<PlanTreninga> pla;
    List<Suplementi> sa;
    List<Clanarina> ca;
    Kasa ka();
    Kasa ka1(50, 50,ra,pla,sa,ca);
    Kasa ka2(ka1);

    List<Zaposleni> zap;
    List<Clan> ccc;
    Teretana ter();
    Teretana ter1(50, 50,ra,pla,sa,ca,SRBOBRAN, "Sveti Sava", 4, "10:00:00AM","22:00:00PM", 25, 3, 50, "0613150983", RADNI_DAN_I_SUBOTA, 10, 400, 400,opr,pro, true, 10, 200, "HERKUL",zap,ccc);
    Teretana ter5(55, 55,ra,pla,sa,ca,NOVI_SAD, "Sveti Nikola", 6, "10:00:00AM","22:00:00PM", 30, 4, 55, "0623150983", PRAZNICI, 15, 500, 500,opr,pro, true, 15, 250, "APOLON",zap,ccc);
    Teretana ter2(ter1);
    tr.dodajClana(cl3);
    tr.dodajClana(cl4);
    tr.popisClanova();
    cl.dodajClanarinu(c2);
    cl.dodajClanarinu(c5);
    cl.vidiClanarinu();
    tr.zaposliOsobu(z1);
    tr.zaposliOsobu(z3);
    tr.vidiStanjeZaposlenih();
    if (ter1 != ter5) {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste." << endl;
    }
    else {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste." << endl;
    }

    if (ter1 < ter5) {
        cout << "teretana '" << ter1 << "' je manja od '" << ter5 << "' teretane." << endl;
    }
    else if (ter1 > ter5) {
        cout << "teretana '" << ter1 << "' je veca od '" << ter5 << "' teretane." << endl;
    }
    else {
        cout << "teretane '" << ter1 << "' i '" << ter5 << " su iste povrsine." << endl;
    }
    ter5 = ter1;
    if (ter1 == ter5) {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << " su iste." << endl;
    }
    else {
        cout << "Dve teretane koje ste uporedili: '" << ter1 << "'  i  '" << ter5 << "' nisu iste." << endl;
    }

}
// Run program: Ctrl + F5 or Debu
#endif
