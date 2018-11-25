#include <iostream>
#include <cstring>
using namespace std;


class Comanda{
private:
    const int cod;
    int nrProduse;
    float *listaPr;
    bool PlataCard;
    static int nrCom;

public:
    Comanda();
    Comanda(int v_nrProduse, float *v_listaPr, bool v_PlataCard);
    Comanda(const Comanda &copie);
    ~Comanda();

    friend istream &operator>>(istream &in, Comanda &comanda);
    friend ostream &operator<<(ostream &out, Comanda &comanda);
    Comanda &operator=(const Comanda &comanda);
    explicit operator float();
    Comanda &operator /=(float numar);

};
int Comanda:: nrCom = 0;

int main(){

    Comanda c1;
    float preturi[] = {10.4, 23.6, 35, 19};
    Comanda c2(4, preturi, true);
    //Comanda *pc;

    cin >> c1;
    cout << c1;

    c1 = c2;
    Comanda c3 = c1;
    cout << c3;

    float maxpr = (float) c2;
    cout <<"\n"<< maxpr;

    c2 /= 0.1;
    cout << c2;
    //delete pc;
    return 0;
}

Comanda::Comanda():cod(Comanda::nrCom){
    this -> nrProduse = 0;
    this -> listaPr = NULL;
    this -> PlataCard = false;
    Comanda::nrCom++;
}

Comanda::Comanda(int v_nrProduse, float *v_listaPr, bool v_PlataCard):cod(Comanda::nrCom) {
    if(v_nrProduse > 0)
    this -> nrProduse = v_nrProduse;

    this ->listaPr = new float[v_nrProduse];
    if(v_listaPr != NULL){
        for(int i = 0; i < v_nrProduse; i++)
            this -> listaPr[i] = v_listaPr[i];
    }

    this -> PlataCard = v_PlataCard;
    Comanda::nrCom++;
}

Comanda::Comanda(const Comanda &comanda):cod(comanda.cod){
    if(comanda.nrProduse > 0)
        this -> nrProduse = comanda.nrProduse;

    this -> listaPr = new float[comanda.nrProduse];
    if(comanda.listaPr != NULL){
        for(int i = 0; i < comanda.nrProduse; i++)
            this -> listaPr[i] = comanda.listaPr[i];
    }

    this ->PlataCard = comanda.PlataCard;
    //Comanda::nrCom++;
}

Comanda::~Comanda() {
    if(this -> listaPr != NULL)
        delete[] this -> listaPr;

    Comanda::nrCom--;
}

istream &operator>>(istream &in,  Comanda &comanda){
    cout << "\n\n\tCitire comanda:";
    cout << "\nId comanda: " << comanda.cod;
    cout << "\nIntroduceti nr de produse: ";
    in >> comanda.nrProduse;

    cout <<"Introduceti preturi: ";
    if(comanda.listaPr != NULL)
        delete[] comanda.listaPr;

    comanda.listaPr = new float[comanda.nrProduse];
    if(comanda.nrProduse > 0)
    for(int i = 0; i < comanda.nrProduse; i++)
        in >> comanda.listaPr[i];

    cout <<"Plata cu cardul 1-Da/0-Nu: ";
    in >> comanda.PlataCard;

    return in;
}

ostream &operator<<(ostream &out, Comanda &comanda){
    out << "\n\n\tAfisare comanda:";
    out << "\nId: " << comanda.cod;
    out << "\nNr produse: " << comanda.nrProduse;

    out <<"\nLista de preturi: ";
    for(int i = 0; i < comanda.nrProduse; i++)
        out << comanda.listaPr[i] << " ";

    out << "\nPlata card?: " << comanda.PlataCard;

    return out;
}

Comanda &Comanda::operator=(const Comanda &comanda){
    if(comanda.nrProduse > 0)
        this -> nrProduse = comanda.nrProduse;

    if(this -> listaPr != NULL)
        delete[] this->listaPr;

    this -> listaPr = new float[this -> nrProduse];
    if(comanda.listaPr != NULL){
        for(int i = 0; i < this->nrProduse; i++)
            this -> listaPr[i] = comanda.listaPr[i];
    }

    this -> PlataCard = comanda.PlataCard;

    return *this;
}

Comanda::operator float(){
    float max;
    max = this -> listaPr[0];

    for(int i = 1; i < this -> nrProduse; i++)
        if(max < this -> listaPr[i])
            max = this -> listaPr[i];

    return max;
}

Comanda &Comanda::operator/=(float numar){
    for(int i = 0; i < this -> nrProduse; i++)
        this -> listaPr[i] -=(this->listaPr[i] * numar);

    return *this;
}