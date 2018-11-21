#include <bits/stdc++.h>
using namespace std;

class Misiune{
private:
    const int id_misiune;
    int nr_camioane;
    float *greutate_camioane;
    char *nume_misiune;
    bool aprobare;
    float pret_misiune;
    const static float pret_mediu_misiune = 500;

public:
    static int nr_comenzi;
    Misiune();
    Misiune(int nr_camioane, float *greutate_camioane, char *nume_misiune, bool aprobare, float pret_misiune);
    Misiune(const Misiune &misiune);
    ~Misiune();

    float getPret();
    void setNume(char *Numenou);

    friend ostream &operator <<(ostream &out, Misiune &misiune);
    friend istream &operator >>(istream &in, Misiune &misiune);

    float operator [](int index);

    Misiune &operator ++();
    Misiune operator ++(int);

    Misiune &operator --();
    Misiune operator --(int);

    Misiune &operator =(const Misiune &misiune);

    Misiune &operator +=(const Misiune &misiune);
    Misiune operator +(float penalizare);
    Misiune operator -(float discount);

    float operator()();

    bool operator ==(Misiune misiune);
    bool operator >(Misiune misiune);
    bool operator <(Misiune misiune);

    explicit operator double();

};
int Misiune ::nr_comenzi = 1;


int main() {

    Misiune m1;
    char nume[] = "Misiunea1";
    Misiune m2(2, new float[2]{15,16}, nume, true, 540);

    cout << m1 << endl;
    cout << m2 << endl;

    /*cout << m2.getPret() << endl;
    ++m2;
    cout << m2.getPret() << endl;
    m2 ++;
    cout <<m2.getPret() << endl;
*/
    /*cout << m2.getPret() << endl;
    --m2;
    cout << m2.getPret() << endl;
    m2 --;
    cout << m2.getPret() << endl;
    */
    Misiune m3, m4, m5;
   // m3 += m2;
   // cout << m3 << endl;

    //m4 + 10;
    //cout << m4 << endl;

   // m4 - 10;
    //cout << m4;

    //m4 ++;
    //cout << m4;

    //m4 --;
    //cout << m4;
    cout << "Au acelasi nume? " << (m3 == m4) << endl; //au acelasi nume

    char var[] = "Anonim2";
    char var2[] = "Anoni";

    m4.setNume(var);
    cout << "Numele misiunii 3 mai scurt decat numele misiunii 4? " << (m3 < m4);

    m5.setNume(var2);
    cout << "Numele misiunii 3 mai lung decat numele misiunii 5? " << (m3 > m5);


    return 0;
}

Misiune ::Misiune():id_misiune(nr_comenzi) {
    this -> nr_camioane = 0;
    this -> greutate_camioane = NULL;

    this -> nume_misiune = new char[strlen("Anonim") + 1];
    strcpy(this -> nume_misiune, "Anonim");

    this -> aprobare = false;
    this -> pret_misiune = pret_mediu_misiune;

    Misiune ::nr_comenzi ++;
}

Misiune ::Misiune(int nr_camioane, float *greutate_camioane, char *nume_misiune, bool aprobare, float pret_misiune):id_misiune(nr_comenzi) {
    if(nr_camioane > 0)
        this -> nr_camioane = nr_camioane;

    if(greutate_camioane != NULL){
        this -> greutate_camioane = new float[nr_camioane];

        for(int i = 0; i < nr_camioane; i++)
            this -> greutate_camioane[i] = greutate_camioane[i];
    }

    this -> nume_misiune = new char[strlen(nume_misiune) + 1];
    strcpy(this -> nume_misiune, nume_misiune);

    this -> aprobare = aprobare;

    if(pret_misiune > pret_mediu_misiune)
        this -> pret_misiune = pret_misiune;
    else
        this -> pret_misiune = pret_mediu_misiune;

    Misiune ::nr_comenzi ++;
}

Misiune ::Misiune(const Misiune &misiune):id_misiune(misiune.id_misiune) {
    if(misiune.nr_camioane > 0)
        this -> nr_camioane = misiune.nr_camioane;

    if(this -> greutate_camioane != NULL)
        delete[] this -> greutate_camioane;

    if(misiune.greutate_camioane != NULL){
        this -> greutate_camioane = new float [this -> nr_camioane];
        for(int i = 0; i < this -> nr_camioane; i++)
            this -> greutate_camioane[i] = misiune.greutate_camioane[i];
    }

    if(this -> nume_misiune != NULL)
        delete[] this -> nume_misiune;

    if(misiune.nume_misiune != NULL){
        this -> nume_misiune = new char[strlen(misiune.nume_misiune) + 1];
        strcpy(this -> nume_misiune, misiune.nume_misiune);
    }

    this -> aprobare = misiune.aprobare;
    this -> pret_misiune = misiune.pret_misiune;
}

Misiune ::~Misiune() {
    Misiune ::nr_comenzi --;

    delete[] this -> greutate_camioane;
    delete[] this -> nume_misiune;

    //cout << "\n\tDistrus";
}

ostream &operator <<(ostream &out, Misiune &misiune){
    out << "\n\n\tAfisare misiune:";
    out << "\nId misiune: " << misiune.id_misiune;
    out << "\nNumar camioane implicate: " << misiune.nr_camioane;

    for(int i = 0; i < misiune.nr_camioane; i++){
        out << "\nCamionul " << i + 1 << " are greutatea: " << misiune.greutate_camioane[i];
    }

    out << "\nDenumirea misiunii: " << misiune.nume_misiune;

    if(misiune.aprobare)
        out << "\nMisiune aprobata";
    else
        out << "\nMisiunea nu este aprobata :(";

    out << "\nPretul total pentru executarea misiunii: " << misiune.pret_misiune;

    return out;
}

istream &operator >>(istream &in, Misiune &misiune){
    cout << "\n\n\tCitire misiune: ";

    cout << "\nId misiune: " << misiune.id_misiune;
    cout << "\nNumar camioane implicate: "; in >> misiune.nr_camioane;

    if(misiune.greutate_camioane != NULL)
        delete[] misiune.greutate_camioane;

    misiune.greutate_camioane = new float[misiune.nr_camioane];
    for(int i = 0; i < misiune.nr_camioane; i++){
        cout << "Camionul " << i + 1 << " transporta(tone): ";
        in >> misiune.greutate_camioane[i];
    }

    in.ignore();
    cout << "Nume misiune: ";
    char buf[50];
    in.getline(buf, 50);
    if (misiune.nume_misiune != NULL) {
        delete[] misiune.nume_misiune;
    }

    misiune.nume_misiune = new char[strlen(buf) + 1];
    strcpy(misiune.nume_misiune, buf);

    cout << "Se va aproba 1-Da/0-Nu? ";
    in >> misiune.aprobare;

    cout << "Pretul total pentru executarea misiunii: (nu poate fi mai mic de 500): ";
    int pret;
    in >> pret;

    if(pret > 500)
        misiune.pret_misiune = pret;
    else
        misiune.pret_misiune = misiune.pret_mediu_misiune;

    return in;
}

float Misiune ::getPret(){
    return this -> pret_misiune;
}

void Misiune ::setNume(char *Numenou) {
    if(this -> nume_misiune != NULL)
        delete[] this -> nume_misiune;

    if(nume_misiune != NULL) {
        this->nume_misiune = new char[strlen(Numenou) + 1];
        strcpy(this->nume_misiune, Numenou);
    }
}


float Misiune ::operator[](int index){
    if((index >= 0) && (index < this -> nr_camioane) && (this -> nr_camioane > 0) && (this -> greutate_camioane != NULL))
        return this -> greutate_camioane[index];
    else
        return -1;
}
//++x -> preincrementare
Misiune& Misiune ::operator++() {
    this -> pret_misiune ++;
    return *this;
}

// x++ ->postincrementare
Misiune Misiune ::operator++(int) {
    Misiune copie = *this;
    this -> pret_misiune ++;

    return copie;
}

//--x -> preincrementare
Misiune &Misiune ::operator--(){
    this -> pret_misiune --;
    return *this;
}

Misiune Misiune ::operator--(int){
    Misiune copie = *this;
    this -> pret_misiune --;
    return copie;
}

Misiune& Misiune ::operator +=(const Misiune &misiune){
    this -> pret_misiune += misiune.pret_misiune;
    return *this;
}

Misiune Misiune ::operator +(float penalizare){
    Misiune copie = *this;
    if(penalizare > 0){
        copie.pret_misiune += penalizare;
    }
    return copie;
}

Misiune Misiune ::operator-(float discount){
    Misiune copie = *this;
    if(discount > 0){
        copie.pret_misiune -= discount;
    }
    return copie;
}


float Misiune ::operator() (){
    float tone = 0;
    if((this -> nr_camioane > 0) && (this -> greutate_camioane != NULL)){
        for(int i = 0; i < this -> nr_camioane; i++)
            tone += this -> greutate_camioane[i];
    }

    return tone;
}

Misiune ::operator double (){
    return this -> pret_misiune;
}

bool Misiune ::operator ==(Misiune misiune){
    if(strcmp(this -> nume_misiune, misiune.nume_misiune) == 0)
        return true;
    else
        return false;
}

bool Misiune ::operator >(Misiune misiune){
    if(strcmp(this -> nume_misiune, misiune.nume_misiune) > 0)
        return true;
    else
        return false;
}

bool Misiune ::operator <(Misiune misiune){
    if(strcmp(this -> nume_misiune, misiune.nume_misiune) < 0)
        return true;
    else
        return false;
}

Misiune& Misiune ::operator=(const Misiune &misiune) {
    this -> nr_camioane = misiune.nr_comenzi;

    delete[] this -> nume_misiune;
    this -> nume_misiune = new char[misiune.nume_misiune];
    strcpy(this -> nume_misiune, misiune.nume_misiune);

    return *this;
}