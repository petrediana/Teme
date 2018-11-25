#include <iostream>
using namespace std;

class ComplexRezidential{
private:
    const int codComplex;
    unsigned int nrAp;
    float *suprafeteAp;


public:
    static float pretMetruPatrat;

    ComplexRezidential(int v_cod);
    ComplexRezidential(int v_cod, unsigned int v_nrAp, float *v_suprafeteAp);
    ComplexRezidential(const ComplexRezidential &copie);
    ~ComplexRezidential();

    ComplexRezidential &operator=(const ComplexRezidential &copie);
    friend ostream &operator <<(ostream &out, const ComplexRezidential &complex);
    friend ComplexRezidential operator +(float numar, ComplexRezidential &complex);
    float &operator[](int index);
    bool operator<(const ComplexRezidential &complex);

    unsigned int getNrAp();
    int getCodComplex();
    float getSuprafataMedie();

    void setSuprafeteAp(float *suprafete, unsigned int ap);

};

float ComplexRezidential::pretMetruPatrat = 700;

int main() {
    cout << "-----";
    ComplexRezidential cr1(12);
    cout << "\n" << cr1.getNrAp();
    float suprafeteAp[] = {65.5, 45.5, 70.5, 85};
    ComplexRezidential cr2(13, 4, suprafeteAp);
    cout << "\n" << cr2.getCodComplex();
    cout << "\n-----";

    ComplexRezidential cr3 = cr2;
    cout << "\n" << cr3.getNrAp();
    cout << "\n-----";

    float suprafeteAp2[] = {50, 60.5, 70, 80.5, 120};
    cr3.setSuprafeteAp(suprafeteAp2, 5);
    cout << "\n" << cr3.getNrAp();
    cout << "\n-----";

    cr1 = cr2;
    cout << "\n" << cr1.getSuprafataMedie();
    cout << "\n-----";

    ComplexRezidential *pcr = new ComplexRezidential(19, 5, suprafeteAp2);
    ComplexRezidential cr4 = 50 + (*pcr);
    //ComplexRezidential cr4 = (*pcr);
    cout << cr4;
    cout << "\n-----";

    ComplexRezidential::pretMetruPatrat = 800;
    cout << "\n" << cr4[2] *  ComplexRezidential::pretMetruPatrat;
    cout << "\n-----";

    if(cr1 < cr2)
        cout << "\ncr1 are sup < cr2";
    else
        cout <<"\ncr2 are sup >cr1";


    delete pcr;
    return 0;
}

ComplexRezidential::ComplexRezidential(int v_cod):codComplex(v_cod) {
    this -> nrAp = 0;
    this -> suprafeteAp = NULL;
}

ComplexRezidential::ComplexRezidential(int v_cod, unsigned int v_nrAp, float *v_suprafeteAp):codComplex(v_cod) {
    this -> nrAp = v_nrAp;
    this -> suprafeteAp = new float[this -> nrAp];
    if(v_suprafeteAp != NULL){
        for(unsigned int i = 0; i < v_nrAp; i++)
            this -> suprafeteAp[i] = v_suprafeteAp[i];
    }
}

ComplexRezidential::ComplexRezidential(const ComplexRezidential &copie):codComplex(copie.codComplex) {
    this -> nrAp = copie.nrAp;

    this -> suprafeteAp = new float[copie.nrAp];
    if(copie.suprafeteAp != NULL){
        for(unsigned int i = 0; i < copie.nrAp; i++)
            this -> suprafeteAp[i] = copie.suprafeteAp[i];
    }
}

ComplexRezidential::~ComplexRezidential() {
    if(this ->suprafeteAp != NULL)
        delete[] this->suprafeteAp;
    ComplexRezidential::pretMetruPatrat = 0;
}

unsigned int ComplexRezidential::getNrAp() {
    return this -> nrAp;
}

int ComplexRezidential::getCodComplex() {
    return this -> codComplex;
}

ComplexRezidential &ComplexRezidential::operator=(const ComplexRezidential &copie){
    this -> nrAp = copie.nrAp;

    if(this -> suprafeteAp != NULL)
        delete[] this -> suprafeteAp;

    this -> suprafeteAp = new float[copie.nrAp];
    if(copie.suprafeteAp != NULL){
        for(unsigned int i = 0; i < copie.nrAp; i++)
            this -> suprafeteAp[i] = copie.suprafeteAp[i];
    }

    return *this;
}

void ComplexRezidential::setSuprafeteAp(float *suprafete, unsigned int ap) {
    this -> nrAp = ap;

    if(this -> suprafeteAp != NULL)
        delete[] this -> suprafeteAp;

    this -> suprafeteAp = new float[ap];
    if(suprafete != NULL){
        for(unsigned int i = 0; i < ap; i++)
            this -> suprafeteAp[i] = suprafete[i];
    }
}

float ComplexRezidential::getSuprafataMedie() {
    float medie = 0;

    if(this -> suprafeteAp != NULL){
        for(unsigned int i = 0; i < this -> nrAp; i++)
            medie += this -> suprafeteAp[i];
    }

    return (float)(medie/this->nrAp);
}

ostream &operator <<(ostream &out, const ComplexRezidential &complex){
    out << "\n\n\tAfisare complex:";
    out <<"\nId: " << complex.codComplex;
    out << "\nNr apartamente: " << complex.nrAp;
    out << "\nSuprafetele ap: ";
    for(unsigned int i = 0; i < complex.nrAp; i++)
        out << complex.suprafeteAp[i] << " ";

    return out;
}

ComplexRezidential operator+(float numar, ComplexRezidential &complex){
    ComplexRezidential copie = complex;
    float *aux;
    unsigned int i;

    aux = new float[copie.nrAp + 1];
    for(i = 0; i < copie.nrAp; i++)
        aux[i] = copie.suprafeteAp[i];


    aux[copie.nrAp++] = numar;
    copie.suprafeteAp = new float[copie.nrAp];

    //copie.suprafeteAp = aux;
    for(i = 0; i < copie.nrAp; i++)
        copie.suprafeteAp[i] = aux[i] ;

    delete[] aux;

    return copie;
}

float &ComplexRezidential::operator[](int index){
    float gresit = 0.0;
    if((index >= 0) && (index < this -> nrAp) && (this -> suprafeteAp != NULL))
        return this -> suprafeteAp[index];
    else
        return gresit;
}

bool ComplexRezidential::operator<(const ComplexRezidential &complex) {
    float sup1 = 0, sup2 = 0;
    unsigned  int i;

    for(i = 0; i < this -> nrAp; i++)
        sup1 += this -> suprafeteAp[i];

    for(i = 0; i < complex.nrAp; i++)
        sup2+= complex.suprafeteAp[i];

    if(sup1 < sup2)
        return true;
    else
        return false;
}