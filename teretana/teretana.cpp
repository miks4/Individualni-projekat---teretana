

#include <iostream>
using namespace std;
enum GRAD{NOVI_SAD = 1,BEOGRAD,NIS,SRBOBRAN};
enum REZERVNI_DEO{SAJLA = 1,SIPKA,TEG,SUNDJER};
enum SREDSTVO_ZA_HIGIJENU {OSVEZIVAC = 1,KRPA,SPREJ};
template <class T>
class List {
private:
    struct listEl {
        T content;
        struct listEl* next;
    };
    listEl* head;
    listEl* tail;
    int noEl;

public:
    List() {
        head = tail = NULL;
        noEl = 0;
    }

    List(const List<T>&);

    List<T>& operator=(const List<T>&);

    virtual ~List();

    int size() const { return noEl; }

    bool empty() const { return head == NULL ? 1 : 0; }

    bool add(int, const T&);

    bool remove(int);

    bool read(int, T&)const;

    void clear();
};


template <class T>
ostream& operator<<(ostream& out, const List<T>& rl) {
    out << endl;
    out << "--------" << endl;
    for (int i = 1; i <= rl.size(); i++) {
        if (i != 1) out << ", ";
        T res;
        rl.read(i, res);
        out << res;
    }
    out << endl << "--------" << endl;
    return out;
}

template <class T>
List<T>::List(const List<T>& rl) {
    head = NULL;
    tail = NULL;
    noEl = 0;

    for (int i = 1; i <= rl.noEl; i++) {
        T res;
        if (rl.read(i, res))
            add(i, res);
    }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& rl) {
    if (this != &rl) {
        clear();
        head = NULL;
        tail = NULL;
        noEl = 0;

        for (int i = 1; i <= rl.noEl; i++) {
            T res;
            if (rl.read(i, res))
                add(i, res);
        }
    }
    return *this;
}

template <class T>
List<T>::~List() {
    while (!empty())
        remove(1);
}

template <class T>
bool List<T>::add(int n, const T& newContent) {
    if (n < 1 || n > noEl + 1)
        return false;
    else {
        listEl* newEl = new listEl;
        if (newEl == NULL)
            return false;
        else {
            newEl->content = newContent;
            if (n == 1) {
                newEl->next = head;
                head = newEl;
            }
            else if (n == noEl + 1) {
                newEl->next = NULL;
                tail->next = newEl;
            }
            else {
                listEl* temp = head;
                for (int i = 2; i < n; i++)
                    temp = temp->next;
                newEl->next = temp->next;
                temp->next = newEl;
            }
            noEl++;
            if (newEl->next == NULL)
                tail = newEl;
            return true;
        }
    }
}

template <class T>
bool List<T>::remove(int n) {
    if (n < 1 || n > noEl)
        return false;
    else {
        if (n == 1) {
            listEl* del = head;
            head = head->next;
            if (tail == del)
                tail = NULL;
            delete del;
            noEl--;
        }
        else {
            listEl* temp = head;
            for (int i = 2; i < n; i++)
                temp = temp->next;
            listEl* del = temp->next;
            temp->next = del->next;
            if (tail == del)
                tail = temp;
            delete del;
            noEl--;
        }
        return true;
    }
}

template <class T>
bool List<T>::read(int n, T& retVal) const {
    if (n < 1 || n > noEl)
        return false;
    else {
        if (n == 1)
            retVal = head->content;
        else if (n == noEl)
            retVal = tail->content;
        else {
            listEl* temp = head;
            for (int i = 1; i < n; i++)
                temp = temp->next;
            retVal = temp->content;
        }
        return true;
    }
}

template <class T>
void List<T>::clear() {
    while (!empty())
        remove(1);
}
class RadnoVreme {
private:
    int krajRadnogVremena;
    int pocetakRadnogVremena;
public:
    RadnoVreme() {
        krajRadnogVremena = 22;
        pocetakRadnogVremena = 10;
    }
    RadnoVreme(int k, int p, int t) {
        krajRadnogVremena = k;
        pocetakRadnogVremena = p;
    }
    RadnoVreme(const RadnoVreme& k) {
        pocetakRadnogVremena = k.pocetakRadnogVremena;
        krajRadnogVremena = k.pocetakRadnogVremena;
    }
    int get_kraj()const {
        return krajRadnogVremena;
    }
    int get_pocetak()const {
        return pocetakRadnogVremena;
    }
    void set_kraj(const int k){
        krajRadnogVremena = k;
    }
    void set_pocetak(const int p) {
        pocetakRadnogVremena = p;
    }
    bool otvoreno(int v) {
        if ((v > pocetakRadnogVremena) && (v < krajRadnogVremena)){
            return true;
        }
        return false;
    }
    int trajanjeRadnogVremena() {
        int t = krajRadnogVremena - pocetakRadnogVremena;
        return t;
    }
};
class Adresa {
private:
    GRAD grad;
    string ulica;
    int ulicniBr;
public:
    Adresa() {
        grad = SRBOBRAN;
        ulica = "Sveti Sava";
        ulicniBr = 4;
    }
    Adresa(GRAD g, string u, int br) {
        grad = g;
        ulica = u;
        ulicniBr = br;
    }
    Adresa(const Adresa& a) {
        grad = a.grad;
        ulica = a.ulica;
        ulicniBr = a.ulicniBr;
    }
    GRAD get_grad()const{
        return grad;
    }
    string get_ulica()const {
        return  ulica;
    }
    int get_brUlice()const {
        return ulicniBr;
    }
    void set_grad(const GRAD g) {
        grad = g;
    }
    void set_ulica(const string u) {
        ulica = u;
    }
    void set_brUlice(const int br) {
        ulicniBr = br;
    }
};
class Info {
private:
    Adresa adresa;
    int kapacitet;
    int brTeretana;
    int velicina;
    string telefon;
public:
    Info() : adresa() {
        kapacitet = 25;
        brTeretana = 3;
        velicina = 50;
        telefon = "0613150983";
    }
    Info(GRAD g, string u, int br, int k, int t, int v, string tel) : adresa(g, u, br) {
        kapacitet = k;
        brTeretana = t;
        velicina = v;
        telefon = tel;
    }
    Info(const Info& i) : adresa(i.adresa) {
        kapacitet = i.kapacitet;
        brTeretana = i.brTeretana;
        velicina = i.velicina;
        telefon = i.telefon;
    }
    GRAD get_grad()const{
        return adresa.get_grad();
    }
    string get_ulica()const {
        return  adresa.get_ulica();
    }
    int get_brUlice()const {
        return adresa.get_brUlice();
    }
    int get_kapacitet()const {
        return kapacitet;
    }
    int get_brTeretana()const {
        return brTeretana;
    }
    int get_velicina()const {
        return velicina;
    }
    string get_telefon()const {
        return telefon;
    }
    void set_grad(const GRAD g) {
        adresa.set_grad(g);
    }
    void set_ulica(const string u) {
        adresa.set_ulica(u);
    }
    void set_brUlice(const int br) {
        adresa.set_brUlice(br);
    }
    void set_kapacitet(const int k) {
        kapacitet = k;
    }
    void set_brTeretana(const int br) {
        brTeretana = br;
    }
    void set_velicina(const int v) {
        velicina = v;
    }
    void set_telefon(const string tel) {
        telefon = tel;
    }
};
class Prostorija {
private:
    int velicina;
public:
    Prostorija() {
        velicina = 40;
    }
    Prostorija(int v) {
        velicina = v;
    }
    Prostorija(const Prostorija &p) {
        velicina = p.velicina;
    }
    int get_velicina()const {
        return velicina;
    }
    void set_velicina(const int v) {
        velicina = v;
    }
};
class Ostava : public Prostorija {
private:
    int rezervniDelovi;
    int higijenskaredstva;
    REZERVNI_DEO tipRezervnogDela;
    SREDSTVO_ZA_HIGIJENU tipHigijenskogSredstva;
public:
    Ostava() : Prostorija(12) {
        rezervniDelovi = 50;
        higijenskaredstva = 20;
        tipRezervnogDela = SAJLA;
        tipHigijenskogSredstva = SPREJ;
    }
    Ostava(int v, int d, int s, REZERVNI_DEO r, SREDSTVO_ZA_HIGIJENU h) : Prostorija(v) {
        rezervniDelovi = d;
        higijenskaredstva = s;
        tipRezervnogDela = r;
        tipHigijenskogSredstva = h;
    }
    Ostava(const Ostava &o) : Prostorija((Prostorija)o) {
        rezervniDelovi = o.rezervniDelovi;
        higijenskaredstva = o.higijenskaredstva;
        tipRezervnogDela = o.tipRezervnogDela;
        tipHigijenskogSredstva = o.tipHigijenskogSredstva;
    }
    int get_rezervniDeo()const {
        return rezervniDelovi;
    }
    int get_sredstvoZaHigijenu()const {
        return higijenskaredstva;
    }
    REZERVNI_DEO get_tipRezervnogDela()const {
        return tipRezervnogDela;
    }
    SREDSTVO_ZA_HIGIJENU get_tipSredstvaZaHigijenu()const {
        return tipHigijenskogSredstva;
    }
    void set_rezervniDeo(const int d) {
        rezervniDelovi = d;
    }
    void set_sredstvoZaHigijenu(const int s) {
        higijenskaredstva = s;
    }
    void set_tipRezervnogDela(const REZERVNI_DEO r) {
        tipRezervnogDela = r;
    }
    void set_tipSredstvoZaHigijenu(const SREDSTVO_ZA_HIGIJENU h) {
        tipHigijenskogSredstva = h;
    }
};
class Svlacionica : public Prostorija {
private:
    int ormaric;
    int klupa;
    int cipelarnik;
    int civiluk;
    bool podnoGrejanje;
public:
    Svlacionica() : Prostorija(30) {
        ormaric = 10;
        klupa = 5;
        cipelarnik = 10;
        civiluk = 3;
        podnoGrejanje = true;
    }
    Svlacionica(int v, int o, int k, int c, int ci,bool p) : Prostorija(v) {
        ormaric = o;
        klupa = k;
        cipelarnik = c;
        civiluk = ci;
        podnoGrejanje = p;
    }
    Svlacionica(const Svlacionica& s) : Prostorija((Prostorija)s) {
        ormaric = s.ormaric;
        klupa = s.klupa;
        cipelarnik = s.cipelarnik;
        civiluk = s.civiluk;
        podnoGrejanje = s.podnoGrejanje;
    }
    int get_ormaric()const {
        return ormaric;
    }
    int get_klupa()const {
        return klupa;
    }
    int get_cipelarnik()const {
        return cipelarnik;
    }
    int get_civiluk()const {
        return civiluk;
    }
    bool get_podnoGrejanje()const {
        return podnoGrejanje;
    }
    void set_ormaric(const int o) {
        ormaric = o;
    }
    void set_klupa(const int k) {
        klupa = k;
    }
    void set_cipelarnik(const int c) {
        cipelarnik = c;
    }
    void set_civiluk(const int ci) {
        civiluk = ci;
    }
    void set_podnoGrejanje(const bool p) {
        podnoGrejanje = p;
    }
};
class Kupatilo : public Prostorija {
private:
    int pisoar;
    int tusKabina;
    int umivaonik;
    int ogledala;
public:
    Kupatilo() : Prostorija(25) {
        pisoar = 7;
        tusKabina = 2;
        umivaonik = 3;
        ogledala = 3;
    }
    Kupatilo(int v, int p, int t, int u, int o) : Prostorija(v) {
        pisoar = p;
        tusKabina = t;
        umivaonik = u;
        ogledala = o;
    }
    Kupatilo(const Kupatilo& k) : Prostorija((Prostorija)k) {
        pisoar = k.pisoar;
        tusKabina = k.tusKabina;
        umivaonik = k.umivaonik;
        ogledala = k.ogledala;
    }
    int get_pisoar()const {
        return pisoar;
    }
    int get_tusKabina()const {
        return tusKabina;
    }
    int get_umivaonik()const {
        return umivaonik;
    }
    int get_ogledalo()const {
        return ogledala;
    }
    void set_pisoar(const int p) {
        pisoar = p;
    }
    void set_tusKabina(const int t) {
        tusKabina = t;
    }
    void set_umivaonik(const int u) {
        umivaonik = u;
    }
    void set_ogledalo(const int o) {
        ogledala = o;
    }
};
class Oprema {
private:
    int kvalitet;
    int kvantitet;
public:
    Oprema() {
        kvalitet = 100;
        kvantitet = 30;
    }
    Oprema(int k, int k1) {
        kvalitet = k;
        kvantitet = k1;
    }
    Oprema(const Oprema& o) {
        kvalitet = o.kvalitet;
        kvantitet = o.kvantitet;
    }
    int get_kvalitet()const {
        return kvalitet;
    }
    int get_kvantitet()const {
        return kvantitet;
    }
    void set_kvalitet(const int k) {
        kvalitet = k;
    }
    void set_kvantitet(const int k1) {
        kvantitet = k1;
    }
    virtual bool kupi(){}
};
int main()
{
    cout << "Hello World!\n" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

