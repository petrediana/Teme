#include <iostream>
#include <cstring>
using namespace std;

class Film{
private:
    char *nume;
    int nr_cinematografe;
    float *incasari;
    const int id;


public:
    static int nr_filme;

    Film(int v_id);
    //Film(static const int v_id);
    Film(int v_id, char *v_nume, int v_nr_cinematografe, float *v_incasari);
    Film(const Film &copie);
    ~Film();

    Film &operator=(const Film &copie);
    friend ostream &operator<<(ostream &out, const Film &copie);
    Film &operator+(float numar);
    float operator()();
    float &operator[](int index);
    bool operator==(const Film &film);

    char* getNume();
    int getNrCinematografe();
    float IncasareMinima();
    void setIncasari(float *v_incasari, int nr);
};
int Film ::nr_filme = 0;


int main() {


    Film f2(100);
    cout << f2.getNume() << endl;
    cout << f2.getNrCinematografe() << endl;


    float incasari[2] = {10.6, 5.2};
    char nume[100];
    strcpy(nume, "stapanul inelelor");

    Film f3(101, nume, 2, incasari);
    cout << f3 << endl;

    Film f4 = f3;
    cout << f4 << endl;

    cout << f3.IncasareMinima() <<endl;

    float incasare2[3] = {11.6, 7.8, 20.6};
    f3.setIncasari(incasare2, 3);
    cout << f3.IncasareMinima() << endl;
   // cout << f3 << endl;

    f2 = f4 = f3;
    cout << f4.IncasareMinima() << endl;
    cout << f2.IncasareMinima() << endl;

    char nume2[100];
    strcpy(nume2, "Harry Potter si camera secretelor");

    Film *pf5 = new Film(102, nume2, 2, incasari);
    cout << pf5->getNrCinematografe() << endl;

    Film pf6 = ((*pf5) + 2.8);
    cout << pf6.getNrCinematografe() << endl;
    cout << pf6.IncasareMinima() << endl;

    cout << "In aplicatie sunt total: " << Film::nr_filme << " filme." << endl;
    cout << "Incasari totale: " << f2() << endl;

    f2[0] = 1.3;
    cout << f2[0];

    if(f2 == f3)
        cout << "\nFilmele au acelasi nume";
    else
        cout << "\nFilmele au nume diferite";

    delete pf5;
    return 0;
}

Film::Film(int v_id):id(v_id){

    this -> nume = new char[strlen("Necunoscut") + 1];
    strcpy(this -> nume, "Necunoscut");

    this -> nr_cinematografe = 0;
    this -> incasari = NULL;

    Film::nr_filme++;
}

Film::Film(int v_id, char *v_nume, int v_nr_cinematografe, float *v_incasari):id(v_id){
    if(v_nume != NULL){
        this -> nume = new char[strlen(v_nume) + 1];
        strcpy(this -> nume, v_nume);
    }

    if(v_nr_cinematografe >= 0)
        this -> nr_cinematografe = v_nr_cinematografe;

    this -> incasari = new float[this -> nr_cinematografe];
    for(int i = 0; i < this -> nr_cinematografe; i++){
        if(v_incasari[i] >= 0)
            this -> incasari[i] = v_incasari[i];
        else
            this -> incasari[i] = 0;
    }
    Film::nr_filme++;
}

Film::Film(const Film &copie):id(copie.id){
    //cout << copie.nume;
    if (copie.nume != NULL) {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy(this->nume, copie.nume);
    }
    if(copie.nr_cinematografe >= 0)
        this -> nr_cinematografe = copie.nr_cinematografe;

    this -> incasari = new float[this -> nr_cinematografe];
    if(copie.incasari != NULL){
        for(int i = 0; i < this ->nr_cinematografe; i++){
            if(copie.incasari[i] > 0)
                this -> incasari[i] = copie.incasari[i];
            else
                this -> incasari[i] = 0;
        }
    }

    Film ::nr_filme++;
}

Film::~Film() {
    if(this -> nume != NULL)
    delete[] this -> nume;

    if(this -> incasari != NULL)
    delete[] this -> incasari;

    Film ::nr_filme --;
}

ostream &operator<<(ostream &out, const Film &copie){
    out << "\n\n\tAfisare obiect:";
    out << "\nAfisare id: " << copie.id;
    out << "\nAfisare nume: " << copie.nume;
    out << "\nAfisare nr cinematografe: " << copie.nr_cinematografe;

    if(copie.incasari != NULL) {
        for (int i = 0; i < copie.nr_cinematografe; i++) {
            out << "\nIncasarea " << i + 1 << " cu pretul " << copie.incasari[i];
        }
    }

    return out;
}

char* Film::getNume() {
    return this -> nume;
}

int Film::getNrCinematografe() {
    return this -> nr_cinematografe;
}

Film &Film::operator=(const Film &copie){
    if(this -> nume != NULL)
        delete[] this -> nume;

    if(copie.nume != NULL){
        this -> nume = new char[strlen(copie.nume) + 1];
        strcpy(this -> nume, copie.nume);
    }

    if(copie.nr_cinematografe >= 0)
        this -> nr_cinematografe = copie.nr_cinematografe;

    if(this -> incasari != NULL)
        delete[] this -> incasari;

    this -> incasari = new float[this->nr_cinematografe];

    if(copie.incasari != NULL){
        for(int i = 0; i < this -> nr_cinematografe; i++){
            if(copie.incasari[i] >= 0)
                this -> incasari[i] = copie.incasari[i];
        }
    }

    return *this;
}

float Film::IncasareMinima() {
    float min;
    int i;

    if(this -> incasari != NULL) {
        min = this->incasari[0];

        for (i = 1; i < this->nr_cinematografe; i++) {
            if (min > this->incasari[i])
                min = this->incasari[i];
        }
    }
    else
        min = 0.0;

    return min;
}

void Film::setIncasari(float *v_incasari, int nr) {
    if(this -> incasari != NULL)
        delete[] this -> incasari;

    if(nr >= 0)
        this -> incasari = new float[nr];

    this -> nr_cinematografe = nr;

    if(v_incasari != NULL){
        for(int i = 0; i < nr; i++)
            this -> incasari[i] = v_incasari[i];
    }
}

Film &Film::operator+(float numar){
    float *aux;
    aux = new float[this -> nr_cinematografe + 1];
    for(int i = 0; i < this -> nr_cinematografe; i++)
        aux[i] = this -> incasari[i];

    aux[this -> nr_cinematografe] = numar;
    delete[] this -> incasari;

    this -> nr_cinematografe ++;
    this -> incasari = new float[this -> nr_cinematografe];
    for(int i = 0; i < this -> nr_cinematografe; i++)
        this -> incasari[i] = aux[i];
    delete[] aux;

    return *this;
}

float Film::operator()(){
    float suma = 0;

    for(int i = 0; i < this -> nr_cinematografe; i++)
        suma += this -> incasari[i];

    return suma;
}

float &Film::operator[](int index){
    float gresit = -1;

    if((index >= 0) && (index < this -> nr_cinematografe) && (this -> incasari != NULL))
        return this -> incasari[index];
    else
        return gresit;
}

bool Film::operator==(const Film &film){
    if(strcmp(this -> nume, film.nume) == 0)
        return true;
    else
        return false;
}