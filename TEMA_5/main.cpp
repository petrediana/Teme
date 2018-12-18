#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class Factura{
protected:
    const int id;
    string denumire_produs;
    unsigned  int cantitate;
    float *preturi;
    bool emis;

public:
    Factura();
    Factura(int id, string denumire, unsigned int cantitate, float *pret, bool emis);
    Factura(const Factura &copie);
    ~Factura();

    virtual void afisare();
    virtual void calculTVA() = 0;

    float mediaGeometrica();

    int getID();
    string getDEN();
    unsigned int getCANT();
    float* getPRET();
    bool getEMIS();

    void setDEN(string den);
    void setCANT(unsigned int cant);
    void setPRET(float *pr, int y);
    void setEMIS(bool emis);

    friend istream &operator >>(istream &in, Factura &factura);
    Factura &operator =(const Factura &factura);
    Factura &operator +=(const Factura &factura);
    Factura &operator +(float penalizare);
    Factura &operator -(float discount);
    Factura &operator++();
    Factura operator++(int);
    Factura &operator--();
    Factura operator--(int);
    bool operator!();
    bool operator>(Factura factura);
    bool operator<(Factura factura);
    bool operator==(Factura factura);
    bool operator>=(Factura factura);
    bool operator<=(Factura factura);
    float &operator[](unsigned int index);
    float operator()();
    explicit operator double();
};

class FElectronica : public Factura{
private:
    string metoda_plata;
public:
    FElectronica();
    FElectronica(string metoda_plata, int id, string denumire, unsigned int cantitate, float *pret, bool emis);
    FElectronica(const FElectronica &copie);
    ~FElectronica();

    void afisare();

};

class FacturaTVA : public FElectronica{
public:
    FacturaTVA();
    FacturaTVA(string metoda_plata, int id, string denumire, unsigned int cantitate, float *pret, bool emis);
    ~FacturaTVA();
    FacturaTVA(const FacturaTVA &copie);

    void calculTVA();
};

class Gestiune_facturi{
private:
    Factura *f;
};

int main(){
    float pr[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5};
    float pr2[] = {7.5, 8.5, 9.5, 10.5};

    Factura f1;
    f1.afisare();

    Factura f2(10, "Factura2", 4, pr, 1);
    f2.afisare();

    cout << "\n\n\tFunctii get: ";
    cout << "\n" << f2.getID();
    cout << "\n" << f2.getDEN();
    cout << "\n" << f2.getCANT();
    cout << "\n" << f2.getPRET();
    cout << "\n" << f2.getEMIS();

    f2.setDEN("Factura2.1");
    f2.setCANT(2);
    f2.setPRET(pr2, 2);
    f2.setEMIS(0);
    f2.afisare();

    /*Factura *facturi;
    int nrf;
   // float suma = 0;
    cout << "\n\n\nCate facturi?: ";
    cin >> nrf;

    facturi = new Factura[nrf];
    for(int i = 0; i < nrf; i++){
        cin >> facturi[i];

        cout << "\nPentru factura " << i + 1 << " media geometrica a atributelor de tip float este: " << facturi[i].mediaGeometrica();
    }*/

    Factura f3;
    f3 = f2;

    cout << boolalpha;
    cout << "\n\nEste f1 initializat?: " << (!f1);
    cout << "\nAu aceeasi cantitate comandata f1 cu f2?: " << (f1 == f2);
    cout << "\nAu aceeasi cantitate comandata f2 cu f3?: " << (f2 == f3);
    cout << "\nEste cantitatea lui f2 mai mare decat cantitatea lui f1?: " << (f2 > f1);
    cout << "\nEste cantitatea lui f1 mai mica decat cantitatea lui f2?: " << (f1 < f2);
    cout << "\nEste cantitatea lui f2 mai mare sau egala decat cantitatea lui f1?: " << (f2 >= f1);
    cout << "\nEste cantitatea lui f1 mai mica sau egala decat cantitatea lui f2?: " << (f1 <= f2);

    f2 = f2 + 1;
    f2.afisare();

    f2 = f2 - 1;
    f2.afisare();

    f2 += f3;
    f2.afisare();

    ++f2;
    f2.afisare();

    --f2;
    f2.afisare();

    f2 ++;
    f2.afisare();

    f2 --;
    f2.afisare();

    cout << "\n\nf2[0] = " << f2[0] << ", f2[1] = " << f2[1];

    cout << "\nSuma preturilor cu operatorul () pentru f2: " << f2();

    double cant = (double)f3;
    cout << "\nCantitate: " << cant;

    FElectronica fe1;
    fe1.afisare();

    char mp[] = "Cu cardul";
    char denfe[] = "Plata servicii";
    FElectronica fe2(mp, 5, denfe, 4, pr, 1);
    fe2.afisare();

    FacturaTVA fe2tva(mp, 5, denfe, 4, pr, 1);
    fe2tva.calculTVA();
    cout << "\n\tPreturi dupa impunerea TVA: ";
    for(unsigned int i = 0; i < fe2tva.getCANT(); i++)
        cout << fe2tva.getPRET()[i];

    //delete facturi;
    return 0;
}

Factura::Factura():id(0) {
    this -> denumire_produs = "Anonim";
    this -> cantitate = 0;
    this -> preturi = NULL;
    this -> emis = 0;
}

Factura::Factura(int id, string denumire, unsigned int cantitate, float *pret, bool emis):id(id) {
    if(denumire.length() > 0)
        this -> denumire_produs = denumire;

    this -> cantitate = cantitate;
    this -> preturi = new float[this -> cantitate];
    for(unsigned int i = 0; i < this -> cantitate; i++)
        this -> preturi[i] = pret[i];

    this -> emis = emis;
}

Factura::Factura(const Factura &copie):id(copie.id) {
    this -> denumire_produs = copie.denumire_produs;
    this -> cantitate = copie.cantitate;
    this -> preturi = new float[this -> cantitate];
    for(unsigned int i = 0; i < this -> cantitate; i++)
        this -> preturi[i] = copie.preturi[i];

    this -> emis = copie.emis;
}

Factura::~Factura() {
    if(this -> preturi != NULL)
        delete[] this -> preturi;
}

void Factura::afisare() {
    cout << "\n\n\tMetoda de afisare Facatura parinte:";

    cout << "\nId: " << this -> id;
    cout << "\nDenumire: " << this -> denumire_produs;
    cout << "\nCantitate: " << this -> cantitate;
    cout << "\nPreturi: ";
    for(unsigned int i = 0; i < this -> cantitate; i++)
        cout << this -> preturi[i] << " ";

    cout << boolalpha;
    cout << "\nEste factura emisa? " << this -> emis;
}

float Factura::mediaGeometrica() {
    float medie = 1.0;

    if(this -> cantitate > 0 && this -> preturi != NULL){
        for(unsigned int i = 0; i < this -> cantitate; i++)
            medie *= this -> preturi[i];
        return pow(medie, (1/this -> cantitate));
    } else
        return 0;
}

int Factura::getID() {
    return this -> id;
}

string Factura::getDEN() {
    return this -> denumire_produs;
}

unsigned int Factura::getCANT() {
    return this -> cantitate;
}

float *Factura::getPRET() {
    return this -> preturi;
}

bool Factura::getEMIS() {
    return this -> emis;
}

void Factura::setDEN(string den) {
    if(den.length() > 0)
        this -> denumire_produs = den;
}

void Factura::setCANT(unsigned int cant) {
    this -> cantitate = cant;
}

void Factura::setPRET(float *pr, int y) {
    if(this -> preturi != NULL)
        delete[] this -> preturi;

    this -> preturi = new float[y];
    for(int i = 0; i < y; i++)
        this -> preturi[i] = pr[i];
}

void Factura::setEMIS(bool emis) {
    this -> emis = emis;
}

istream &operator>>(istream &in, Factura &factura){
    cout << "\n\n\tCitire Factura:";

    cout << "\nDenumire: ";
    in >> factura.denumire_produs;

    cout <<"Cantitate: ";
    in >> factura.cantitate;

    cout << "Preturi: ";
    factura.preturi = new float[factura.cantitate];
    for(unsigned int i = 0 ; i < factura.cantitate; i++)
        in >> factura.preturi[i];

    cout << "Factura emisa? 1-Da/0-Nu";
    in >>factura.emis;

    return in;
}

Factura &Factura::operator=(const Factura &factura) {
    if(this != &factura){
        if(factura.denumire_produs.length() > 0)
            this -> denumire_produs = factura.denumire_produs;

        this -> cantitate = factura.cantitate;
        if(this -> preturi != NULL)
            delete[] this -> preturi;

        this -> preturi = new float[factura.cantitate];
        for(unsigned int i = 0; i < factura.cantitate; i++)
            this -> preturi[i] = factura.preturi[i];

        this -> emis = factura.emis;
    }
    return *this;
}

Factura &Factura::operator+=(const Factura &factura){
    if(this -> cantitate == factura.cantitate)
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] += factura.cantitate;

    return *this;
}

Factura &Factura::operator+(float penalizare) {
    if(this -> preturi != NULL && this -> cantitate != 0){
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] += penalizare;
    }

    return *this;
}

Factura &Factura::operator-(float discount) {
    if(this -> preturi != NULL && this -> cantitate != 0) {
        for (unsigned int i = 0; i < this->cantitate; i++)
            this->preturi[i] -= discount;
    }

    return *this;
}

Factura &Factura::operator++() {
    if(this -> preturi != NULL && this -> cantitate > 0)
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] ++;

    return *this;
}

Factura &Factura::operator--(){
    if(this -> preturi != NULL && this -> cantitate > 0)
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] --;

    return *this;
}

Factura Factura ::operator++(int) {
    Factura copie = *this;

    if(this -> preturi != NULL && this -> cantitate > 0)
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] ++;

    return copie;
}

Factura Factura ::operator--(int) {
    Factura copie = *this;

    if(this -> preturi != NULL && this -> cantitate > 0)
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] --;

    return copie;
}

bool Factura::operator!(){
    return (this -> preturi != NULL && this -> cantitate != 0);
}

bool Factura::operator>(Factura factura){
    return (this -> cantitate > factura.cantitate);
}

bool Factura::operator>=(Factura factura){
    return (this -> cantitate >=factura.cantitate);
}

bool Factura::operator<(Factura factura){
    return (this -> cantitate < factura.cantitate);
}

bool Factura::operator<=(Factura factura){
    return (this -> cantitate <= factura.cantitate);
}

bool Factura::operator==(Factura factura){
    return (this -> cantitate == factura.cantitate);
}

float &Factura::operator[](unsigned int index){
    if(this -> preturi != NULL && index < this -> cantitate)
        return this -> preturi[index];
    else
       throw runtime_error("indexul nu e bun");
}

float Factura::operator()(){
    float suma = 0.0;
    if(this -> preturi != NULL && this -> cantitate > 0)
        for(unsigned int i = 0; i < this -> cantitate; i++)
            suma += this -> preturi[i];

    return suma;
}

Factura::operator double(){
    return this -> cantitate;
}

FElectronica::FElectronica():Factura() {
    this -> metoda_plata = "Anonim";
}

FElectronica::FElectronica(string metoda_plata, int id, string denumire, unsigned int cantitate, float *pret,
                           bool emis):Factura(id, denumire, cantitate, pret,emis) {

    if(metoda_plata.length() > 0)
        this -> metoda_plata = metoda_plata;
    else
        this -> metoda_plata = "Anonim";
}

FElectronica::FElectronica(const FElectronica &copie):Factura(copie) {
    this -> metoda_plata = copie.metoda_plata;
}

FElectronica::~FElectronica() {

}

void FElectronica::afisare() {
    cout << "\n\n\tMetoda de afisare factura electronica";
    cout << "\nMetoda plata: " << this -> metoda_plata;
    cout << "\nId: " << this -> id;
    cout << "\nDenumire: " << this -> denumire_produs;
    cout << "\nCantitate: " << this -> cantitate;
    cout << "\nPreturi: ";
    for(unsigned int i = 0; i < this -> cantitate; i++)
        cout << this -> preturi[i] << " ";

    cout << boolalpha;
    cout << "\nEste factura emisa? " << this -> emis;

}

FacturaTVA::FacturaTVA():FElectronica() {}
FacturaTVA::FacturaTVA(string metoda_plata, int id, string denumire,
                       unsigned int cantitate, float *pret, bool emis):FElectronica(metoda_plata, id, denumire,
                                                                    cantitate, pret, emis) {}
FacturaTVA::FacturaTVA(const FacturaTVA &copie):FElectronica(copie){}
FacturaTVA::~FacturaTVA() {}

void FacturaTVA::calculTVA() {
    float tva = (19.0 / 100.0);
    if(this -> cantitate > 0 && this -> preturi != NULL && this -> emis){
        for(unsigned int i = 0; i < this -> cantitate; i++){
            this -> preturi[i] *= tva;
        }
    }
}