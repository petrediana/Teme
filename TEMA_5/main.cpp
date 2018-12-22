#include <iostream>
#include <string>
#include <stdexcept>

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
    Factura(int id, unsigned int cantitate = 2, bool emis = false);
    Factura(const Factura &copie);
    virtual ~Factura();

    void afisare();

    virtual void calcul_cu_TVA() = 0;
    //clasa abstractizata

    int getID()const;
    string getDEN()const;
    unsigned int getCANT()const;
    float* getPRET()const;
    bool getEMIS()const;

    void setDEN(string den);
    void setCANT(unsigned int cant);
    void setPRET(float *pr, int y);
    void setEMIS(bool emis);

    Factura &operator =(const Factura &factura);

    /*friend istream &operator >>(istream &in, Factura &factura);
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
    explicit operator double();*/
};

class FacturaElectronica : public Factura{
private:
    string metoda_plata;
public:
    FacturaElectronica();
    FacturaElectronica(string metoda_plata, int id, string denumire, unsigned int cantitate, float *pret, bool emis);
    FacturaElectronica(const FacturaElectronica &copie);
    ~FacturaElectronica();

    friend ostream &operator<<(ostream &out, FacturaElectronica &fe);
    FacturaElectronica &operator=(const FacturaElectronica &copie);
    void calcul_cu_TVA();
};

class FacturaAchitata : public Factura{
private:
    bool achitat;
public:
    FacturaAchitata();
    FacturaAchitata(bool achitat, int id, string denumire, unsigned int cantitate, float *pret, bool emis);
    FacturaAchitata(const FacturaAchitata &copie);
    ~FacturaAchitata();

    void calcul_cu_TVA();
};

//simulare clasa <vector>
class GestiuneFacturi{
private:
    Factura **facturi;
    int nr_facturi;
    int size;
    bool valid;
public:
    GestiuneFacturi();
    GestiuneFacturi(int nrf);
    GestiuneFacturi(const GestiuneFacturi &copie);
    /*  constructorul de copiere -> in copie o sa copieze pointerul
        cand copia e distrusa si da delete pe pointer
        invalideaza pointerul din obiectul initial!!!!!!!
     */
    ~GestiuneFacturi();

    void pushback(Factura *p);
    void afisare();

};

int main(){
    float pr[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5};
    float pr2[] = {7.5, 8.5, 9.5, 10.5};
/*
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

    Factura *facturi;
    int nrf;
    float suma = 1;
    cout << "\n\n\nCate facturi?: ";
    cin >> nrf;

    facturi = new Factura[nrf];
    for(int i = 0; i < nrf; i++){
        cin >> facturi[i];

        for(unsigned int j = 0; j < facturi[i].getCANT(); j++)
            suma *= facturi[i].getPRET()[j];
        cout << "\nMedia geometrica: " << pow(suma, (1/facturi[i].getCANT()));
    }


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

*/
    //delete facturi;

    FacturaElectronica fe1;
    cout << fe1;

    FacturaElectronica fe2("Cu cardul", 10, "Servicii", 4, pr, 1);
    cout << fe2;

    fe2.calcul_cu_TVA();
    cout << "\nPreturile finale cu tva: ";
    for(unsigned int i = 0; i < fe2.getCANT(); i++)
        cout << fe2.getPRET()[i] << " ";

    cout << fe2 << endl;

    FacturaAchitata fa1;
    fa1.calcul_cu_TVA();

    FacturaAchitata fa2(true, 11, "Factura telefonica", 2, pr2, true);
    fa2.calcul_cu_TVA();


    Factura *pf1 = new FacturaElectronica("Cu cardul", 10, "Servicii", 4, pr, 1);
    Factura *pf2 = new FacturaElectronica("Cu cardul", 11, "Alte Servicii", 3, pr2, 1);

    GestiuneFacturi vf(2); //vector facturi
    vf.pushback(pf1);
    vf.pushback(pf2);

    vf.afisare();
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

Factura::Factura(int id, unsigned int cantitate, bool emis):id(id) {
    this -> cantitate = cantitate;
    this -> emis = emis;
    this -> preturi = new float[cantitate];
    for(unsigned int i = 0; i < cantitate; i++)
        this ->preturi[i] = 0;
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
    cout << "\n\n\tMetoda de afisare obiect:";

    cout << "\nId: " << this -> id;
    cout << "\nDenumire: " << this -> denumire_produs;
    cout << "\nCantitate: " << this -> cantitate;
    cout << "\nPreturi: ";
    for(unsigned int i = 0; i < this -> cantitate; i++)
        cout << this -> preturi[i] << " ";

    cout << boolalpha;
    cout << "\nEste factura emisa? " << this -> emis;
}

int Factura::getID() const{
    return this -> id;
}

string Factura::getDEN() const{
    return this -> denumire_produs;
}

unsigned int Factura::getCANT() const{
    return this -> cantitate;
}

float *Factura::getPRET() const{
    return this -> preturi;
}

bool Factura::getEMIS() const{
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

/*istream &operator>>(istream &in, Factura &factura){
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
*/
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
/*
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
*/
FacturaElectronica::FacturaElectronica():Factura() {
    this -> metoda_plata = "Anonim";
}

FacturaElectronica::FacturaElectronica(string metoda_plata, int id, string denumire, unsigned int cantitate,
                                       float *pret, bool emis):Factura(id, denumire, cantitate, pret, emis) {
    if(metoda_plata.length() > 0)
        this -> metoda_plata = metoda_plata;
    else
        this -> metoda_plata = "Anonim";
}

FacturaElectronica::FacturaElectronica(const FacturaElectronica &copie):Factura(copie) {
    if(copie.metoda_plata.length() > 0)
        this -> metoda_plata = copie.metoda_plata;
    else
        this -> metoda_plata = "Anonim";
}

FacturaElectronica& FacturaElectronica::operator=(const FacturaElectronica &copie) {
    this -> denumire_produs = copie.getDEN();
    this -> cantitate = copie.getCANT();
    this -> emis = copie.getEMIS();

    if(this -> preturi != NULL)
        delete[] this->preturi;

    this -> preturi = new float[this -> cantitate];
    if(copie.preturi != NULL)
        for(unsigned int i = 0 ;i < this -> cantitate; i++)
            this -> preturi[i] = copie.getPRET()[i];

    return *this;
}

ostream &operator<<(ostream &out, FacturaElectronica &fe){
    out << "\n\n\tOperatorul << pentru subclasa Factura Electronica: ";
    out << "\nMetoda plata: " << fe.metoda_plata;
    out << "\nId: " << fe.id;
    out << "\nDenumire: " << fe.denumire_produs;
    out << "\nCantitate: " << fe.cantitate;
    out << "\nPreturile: ";
    for(unsigned int i = 0; i < fe.cantitate; i++)
        out << fe.preturi[i] << ", ";
    out <<boolalpha;
    out << "\nEste emisa? " << fe.emis;

    return out;
}

FacturaElectronica::~FacturaElectronica() {}

void FacturaElectronica::calcul_cu_TVA() {
    float tva = (19.0 /100);
    if(this -> cantitate > 0 && this -> preturi != NULL && this -> emis){
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] += (this -> preturi[i]) * tva;
    }
}

FacturaAchitata::FacturaAchitata():Factura() {
    this -> achitat = false;
}

FacturaAchitata::FacturaAchitata(bool achitat, int id, string denumire, unsigned int cantitate, float *pret,
                                 bool emis):Factura(id, denumire, cantitate, pret, emis) {
    this -> achitat = achitat;
}

FacturaAchitata::FacturaAchitata(const FacturaAchitata &copie):Factura(copie) {
    this -> achitat = copie.achitat;
}

FacturaAchitata::~FacturaAchitata(){}

void FacturaAchitata::calcul_cu_TVA() {
    float tva = (19.0 /100);
    float suma = 0;

    if(this -> cantitate > 0 && this -> preturi != NULL && this -> emis){
        for(unsigned int i = 0; i < this -> cantitate; i++)
            this -> preturi[i] += (this -> preturi[i]) * tva;

        if(this -> achitat){
            for(unsigned int i = 0; i < this -> cantitate; i++)
                suma += this -> preturi[i];
            cout << "\nS-a achitat suma de: " << suma << " lei";
        }
        else
            cout << "\nFactura nu a fost inca achitata.";
    }
    else
        cout << "\nDate invalide pentru calcul";
}

GestiuneFacturi::GestiuneFacturi() {
    this -> facturi = NULL;
    this -> nr_facturi = 0;
    this -> size = 0;
    this -> valid = true;
}

GestiuneFacturi::GestiuneFacturi(int nrf) {
    this -> valid = true;
    this -> size = 0;

    if(nrf > 0)
        this -> nr_facturi = nrf;

    this -> facturi = new Factura*[this -> nr_facturi];
    //cout << "\n" << this -> nr_facturi;
}

GestiuneFacturi::~GestiuneFacturi() {
    if(!(this->valid)){
        delete this->facturi;
        return;
    }

    for(int i = 0; i < this->size; i++){
        delete this->facturi[i];
    }
    delete this->facturi;
}

GestiuneFacturi::GestiuneFacturi(const GestiuneFacturi &copie) {
    if(copie.size > 0)
    this -> size = copie.size;

    if(copie.nr_facturi > 0)
        this -> nr_facturi = copie.nr_facturi;

    this -> valid = false;

    for(int i = 0 ;i < this -> size; i++){
        facturi[i] = copie.facturi[i];
    }
}

void GestiuneFacturi::pushback(Factura *p) {
    if(this ->size >= this ->nr_facturi || this ->facturi == NULL)
        return;

    this->facturi[this->size] = p;

    this -> size++;
}

void GestiuneFacturi::afisare() {
    cout << "\n\n\tAfisare vector de facturi:";
    if(this -> size > 0 && this -> nr_facturi > 0 && this -> facturi != NULL){
        for(int i = 0; i < size; i++){
            cout << "\n\tFactura: " << i + 1;
            cout << "\nId: " << this->facturi[i]->getID();
            cout << "\nDenumire: " << this->facturi[i]->getDEN();
            cout << "\nCantitate: " << this->facturi[i]->getCANT();
            cout << "\nPreturile: ";

            if(this->facturi[i]->getPRET() != NULL) {
                for (unsigned int j = 0; j < this->facturi[i]->getCANT(); j++)
                    cout << this->facturi[i]->getPRET()[j] << " ";
            }

            cout << boolalpha;
            cout << "\nEste emisa? " << this->facturi[i]->getEMIS();
        }
    }
    else
        cout << "\nObiectele nu au fost initializate";
}