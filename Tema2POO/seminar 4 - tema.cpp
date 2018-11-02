//seminar 3 + seminar 4
#include <iostream>
#include <cstring>

using namespace std;

class Hotel{
private:
    const int id;
    char *nume;
    char adresa[60];
    bool deschis;
    unsigned int nr_camere;
    float *pret;

public:
    static int nr_total_hotel;

    Hotel();
    Hotel(int v_id, char *v_nume, bool v_deschis = true);
    //tema
    Hotel(int id, char *nume, char adresa[60], bool deschis, unsigned int nr_camere, float *pret);

    Hotel(const Hotel &copie);

    ~Hotel();
    void afisare();


    void setname(char *v_nume);
    void setAdresa(char adresa[60]);
    void setNrCamere(unsigned int nr_camere);
    void setPret(float *pret);
    void setDeschis(bool dechis);

    char *getAdresa();
    bool getDeschis();
    unsigned int getNr_camere();
    float *getPret();
    int getID();
    char* getName();
};
int Hotel:: nr_total_hotel = 0;

int main() {

   /* Hotel h1;
    h1.afisare();

    Hotel *h2 = new Hotel;
    h2 -> afisare();
    delete h2;

    char *Nume;
    Nume = new char [strlen("costructor variabila normala") + 1];
    strcpy(Nume, "costructor variabila normala");
    Hotel h3(1, Nume);
    h3.afisare();
    delete [] Nume;

    char *AltNume;
    AltNume = new char [strlen("Constructor") + 1];
    strcpy(AltNume, "Constructor");
    Hotel *h4 = new Hotel(2, AltNume, false);
    h4 -> afisare();
    delete h4;
    delete [] AltNume;


    float pret1[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    char *numeHotel;
    numeHotel = new char[strlen("Hotel5") + 1];
    strcpy(numeHotel, "Hotel5");
    char adresa[60];
    strcpy(adresa, "Adresa mea");
    Hotel h5(5, numeHotel, adresa, 1, 5, pret1);
    h5.afisare();
    delete [] numeHotel;

    Hotel *h6 = new Hotel(6, "nume6", "adresa6",1, 2, new float[2]{1, 2});
    h6 -> afisare();
    delete h6;
*/
    Hotel h7;
    h7.setname("nume7");
    h7.setNrCamere(2);
    h7.setDeschis(true);
    h7.setAdresa("adresa7");
    h7.setPret(new float[2]{7, 8});

    cout << h7.getID() << endl;
    cout << h7.getName() << endl;
    cout << h7.getAdresa() << endl;
    cout << h7.getDeschis() << endl;
    cout << h7.getNr_camere() << endl;
    cout << h7.getPret() << endl;

    cout << "\n\n\tNr de hoteluri: " << Hotel ::nr_total_hotel;
    cout << "\n\n";
    return 0;
}

Hotel ::Hotel(): id(-1) { //Hotel *Hotel(Hotel *this) cum arata in memorie
    //this -> id = -1;
    this -> nume = new char [strlen("Anonim") + 1];
    strcpy(this -> nume, "Anonim");
    strcpy(this -> adresa, "Anonim");
    this -> deschis = false;
    this -> nr_camere = 0;
    this -> pret = NULL;

    Hotel ::nr_total_hotel ++;
}

Hotel ::Hotel(int v_id, char *v_nume, bool v_deschis): id(v_id) {
    //this -> id = v_id;
    this -> nume = new char[strlen(v_nume) + 1];
    strcpy(this -> nume, v_nume);
    strcpy(this -> adresa, "Anonim");
    this -> deschis = v_deschis;
    this -> nr_camere = 0;
    this -> pret = NULL;
    Hotel ::nr_total_hotel ++;
}

void Hotel ::afisare() {
    cout << "\n\n\tAfisare hotel: ";

    cout << "\nId: " << this -> id;
    cout << "\nNume: " << this -> nume;
    cout << "\nAdresa: " << this -> adresa;

    if(this -> deschis){
        cout << "\nHotel deschis";
    }
    else{
        cout << "\nHotel nu e deschis";
    }

    cout << "\nNumarul de camere: " << this -> nr_camere;

    if(this -> pret != NULL){
        for(unsigned int i = 0; i < this -> nr_camere; i++){
            cout << "\nPretul camerei|" << i +1 << "| este: " << this -> pret[i];
        }
    }
}

//tema
Hotel ::Hotel(int id, char *nume, char adresa[60], bool deschis, unsigned int nr_camere, float *pret): id(id) {
   // this -> id = id;

    if(nume != NULL) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    if(adresa != NULL)
    strcpy(this -> adresa, adresa);

    this -> deschis = deschis;

    this -> nr_camere = nr_camere;

    if(pret != NULL) {
        this->pret = new float[this->nr_camere];
        for (unsigned int i = 0; i < this->nr_camere; i++)
            this->pret[i] = pret[i];
    }
    Hotel ::nr_total_hotel ++;

}

Hotel ::Hotel(const Hotel &copie):id(copie.id) {//copy constructor
    if(copie.nume != NULL){
        this -> nume = new char[strlen(copie.nume) + 1];
        strcpy(this -> nume, copie.nume);
    }

    if(copie.adresa != NULL){
        strcpy(this -> adresa, copie.adresa);
    }

    this -> deschis = copie.deschis;
    this -> nr_camere = copie.nr_camere;

    if(copie.pret != NULL){
        this -> pret = new float[copie.nr_camere];
        for(unsigned int i = 0; i < copie.nr_camere; i++)
            this -> pret[i] = copie.pret[i];
    }

    Hotel ::nr_total_hotel++;
}

void Hotel ::setname(char *v_nume) {
    if(this -> nume != NULL){
        delete [] this -> nume;
    }

    if(v_nume != NULL){
        this -> nume = new char [strlen(v_nume) + 1];
        strcpy(this -> nume, v_nume);
    }
}

void Hotel ::setAdresa(char adresa[60]) {
    if (adresa != NULL)
        strcpy(this -> adresa, adresa);
}

void Hotel ::setDeschis(bool dechis) {
    this -> deschis = deschis;
}

void Hotel ::setNrCamere(unsigned int nr_camere) {
    this -> nr_camere = nr_camere;
}

void Hotel ::setPret(float *pret) {
    if(this -> pret != NULL)
        delete[] this -> pret;

    if(pret != NULL){
        this -> pret = new float[this -> nr_camere];
        for(int i = 0; i < this -> nr_camere; i++)
            this -> pret[i] = pret[i];
    }
}

unsigned int Hotel ::getNr_camere() {
    return this -> nr_camere;
}

float *Hotel ::getPret() {
    //if(this -> pret != NULL)
        return this -> pret;
}

bool Hotel ::getDeschis() {
    return this -> deschis;
}

char *Hotel ::getAdresa() {
    //if(this -> adresa != NULL)
        return this -> adresa;
}

int Hotel ::getID() {
    return this -> id;
}

char *Hotel ::getName() {
    return this -> nume;
}




Hotel ::~Hotel() {
    cout << "\nApel destructor";
    if(this -> nume != NULL){
        delete [] this -> nume;
    }

    if(this -> pret != NULL){
        delete [] this -> pret;
    }

    Hotel ::nr_total_hotel --;

    cout << "\nMemoria a fost dezalocata";
}