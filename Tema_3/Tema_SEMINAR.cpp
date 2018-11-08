#include <bits/stdc++.h>
using namespace std;

class Produs {

private:
	const int id;
	char* nume;
	float pret;
	char unitateMasura[10];
	static int nr_produse;
public:

	Produs();
	Produs(char* nume, float pret, char unitateMasura[10]);
	Produs(const Produs& copie);
	~Produs();
	int getId();
	void setNume(char* v_nume);
	char* getNume();
	void setPret(float v_pret);
	float getPret();
	void setUnitateMasura(char v_unitateMasura[10]);
	char* getUnitateMasura();
	Produs& operator=(const Produs& produs);
	friend ostream& operator<<(ostream& out, Produs& produs);
	friend istream& operator>>(istream& in, Produs& produs);

};
int Produs ::nr_produse = 0;


int main() {

    Produs p1;
    cout << p1;

    char nume[10], unit[10];
    strcpy(nume, "produs2");
    strcpy(unit, "kg");

    Produs p2(nume, 10, unit);
    cout << p2 << endl;

    Produs p3;
    p3 = p2;
    cout << p3 << endl;

    cout << "\n\nCitire obiect de la tastatura: ";
    Produs p4;
    cin >> p4;
    cout << p4;


    return 0;
}


Produs ::Produs(): id(nr_produse) {
    this -> nume = new char[strlen("numenull") + 1];
    strcpy(this -> nume, "numenull");

    this -> pret = 0;
    strcpy(this -> unitateMasura, "nimic");
    Produs ::nr_produse ++;
}

Produs ::Produs(char *nume, float pret, char *unitateMasura): id(nr_produse) {
    if(nume != NULL){
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);
    }

    if(pret > 0)
        this -> pret = pret;

    strcpy(this -> unitateMasura, unitateMasura);
    Produs ::nr_produse ++;
}

Produs ::Produs(const Produs &copie): id(copie.id) {
    if(this -> nume != NULL)
        delete[] this -> nume;

    if(copie.nume != NULL){
        this -> nume = new char[strlen(copie.nume) + 1];
        strcpy(this -> nume, copie.nume);
    }

    strcpy(this -> unitateMasura, copie.unitateMasura);
}

int Produs ::getId() {
    return this -> id;
}

char* Produs ::getNume() {
    return this -> nume;
}

float Produs ::getPret() {
    return this -> pret;
}

char* Produs ::getUnitateMasura() {
    return this -> unitateMasura;
}

void Produs ::setNume(char *v_nume) {
    if(this -> nume != NULL)
        delete[] this -> nume;

    if(v_nume != NULL){
        this -> nume = new char [strlen(v_nume) + 1];
        strcpy(this -> nume, v_nume);
    }
}

void Produs ::setPret(float v_pret) {
    if(pret > 0)
        this -> pret = v_pret;
}

void Produs ::setUnitateMasura(char *v_unitateMasura) {
    if(v_unitateMasura != NULL)
        strcpy(this -> unitateMasura, v_unitateMasura);
}

Produs& Produs::operator=(const Produs& produs){
    if(this != &produs) {

        if (this->nume != NULL)
            delete[] this->nume;

        if (produs.nume != NULL) {
            this->nume = new char[strlen(produs.nume) + 1];
            strcpy(this->nume, nume);
        }

        if (produs.pret > 0)
            this->pret = produs.pret;

        if (produs.unitateMasura != NULL)
            strcpy(this->unitateMasura, produs.unitateMasura);
    }
    return *this;
}

ostream &operator<<(ostream &out, Produs &produs){
    out << "\n\n\tAfisare produs: ";

    out <<"\nId: "; out << produs.id;
    out << "\nNume: "; out << produs.nume;
    out << "\nPret: "; out << produs.pret;
    out << "\nUnitate de masura: "; out << produs.unitateMasura;

    return out;
}

istream &operator>>(istream &in, Produs &produs){
    cout << "\n\n\tCitire produs: ";

    cout << "\nId: " << produs.id << endl;

    if(produs.nume != NULL)
        delete[] produs.nume;

    char buf[100];
    cout << "Nume: "; in.getline(buf, 100);
    produs.nume = new char [strlen(buf) + 1];
    strcpy(produs.nume, buf);
    //in.ignore();

    cout << "Pret: "; in >> produs.pret;
    cout << "Unitate de masura: "; in >> produs.unitateMasura;

    return in;
}

Produs ::~Produs() {
    delete[] this -> nume;
}