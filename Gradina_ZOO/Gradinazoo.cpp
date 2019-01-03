#include "Gradinazoo.h"

Animal::Animal() {
    this -> index_putere = 0;
    this -> exista = 0;
    //this -> tip = 0;
}

Animal::Animal(int index_putere, bool exista, TipAnimal tip) {
    if(index_putere > 0)
        this -> index_putere = index_putere;
    else
        throw string("Index putere invalid");

    this -> exista = exista;
    this -> tip = tip;
}

Animal::Animal(const Animal &copie) {
    if(copie.index_putere > 0)
        this -> index_putere = copie.index_putere;
    else
        throw string("Index putere invalid");

    this -> index_putere = copie.index_putere;
    this -> tip = copie.tip;
}

int Animal::getPutere() {
    return this -> index_putere;
}

bool Animal::getExista() {
    return this -> exista;
}

string Animal::getTip() {
    switch (this -> tip){
        case PUI:
            return "Pui";
        case MATUR:
            return "Matur";
        case BATRAN:
            return "BATRAN";
        default:
            return "";
    }
}
TipAnimal Animal::getTipp(){
    return this -> tip;
}

void Animal::setExista(bool e) {
    this -> exista = e;
}

void Animal::setPutere(int p) {
    this -> index_putere = p;
}

void Animal::setTip(TipAnimal tip) {
    this -> tip = tip;
}

Animal& Animal::operator=(const Animal &copie) {
    if(this != &copie){
        this -> index_putere = copie.index_putere;
        this -> exista = copie.exista;
        this -> tip = copie.tip;
    }

    return *this;
}

bool Animal::operator>(const Animal &animal){
    return (this->index_putere > animal.index_putere);
}
//----------------------------------------------------------------------------------------------------------
Lup::Lup():Animal() {
    this -> denumire_rasa = "Nu se stie";
}

Lup::Lup(string denumire, int indexp, bool exista, TipAnimal tip):Animal(indexp, exista, tip) {
    if(denumire.length() > 0)
        this -> denumire_rasa = denumire;
    else
        this -> denumire_rasa = "Nu se stie";
}

Lup::Lup(const Lup &copie):Animal(copie) {
    if(copie.denumire_rasa.length() > 0)
        this -> denumire_rasa = copie.denumire_rasa;
    else
        this -> denumire_rasa = "Nu se stie";
}

string Lup::getDenumire() {
    return this -> denumire_rasa;
}

void Lup::descriere() {
    cout << "\n\n\t Descriere Lup: ";
    cout << "\nLupii fac parte din tribul Canini";
    cout << "\nRasa din care face parte: " << this -> denumire_rasa;
    cout << "\nAcest lup este: " << getTip();
    cout << "\nPoate sa fie periculos, puterea sa fiind: " << this -> index_putere;

    if(this -> exista)
        cout << "\nSe poate vizita in gradina";
    else
        cout << "\nNu este in gradina";
}

istream &operator>>(istream &in, Lup &lup){
    cout << "\n\n\tAdaugare lup: ";
    bool e; int p; string t;
    cout << "\nRasa din care face parte: "; in >> lup.denumire_rasa;
    cout << "Se va putea vizita in gradina?(1-Da/0-Nu): "; in >> e;
    lup.setExista(e);
    cout << "Cat de periculos este?(1- inofensiv, 100-foarte periculos): "; in >> p;
    lup.setPutere(p);
    cout << "Cum este animalul?(PUI/MATUR/BATRAN): "; in >> t;

    if(t == "pui" || t == "PUI")
        lup.setTip(PUI);
    else{
        if(t == "matur" || t == "MATUR")
            lup.setTip(MATUR);
        else
            lup.setTip(BATRAN);
    }

    return in;
}

ostream &operator<<(ostream &out, Lup &lup){
    out << "\n\nLup din rasa: " << lup.denumire_rasa;
    return out;
}

Lup& Lup::operator=(const Lup &lup) {
    if(this != &lup){
        this -> denumire_rasa = lup.denumire_rasa;
        this -> exista = lup.exista;
        this -> tip = lup.tip;
        this -> index_putere = lup.index_putere;
    }
    return *this;
}

bool Lup::operator>(const Lup &lup) {
    return (this -> index_putere > lup.index_putere);
}
//----------------------------------------------------------------------------------------------------------

Urs::Urs():Animal() {
    this -> denumire_rasa = "Nu se stie";
    this -> greutate = 0;
}

Urs::Urs(string denumire, unsigned int greutate, int indexp,
         bool exista, TipAnimal tip):Animal(indexp, exista, tip) {
    if(denumire.length() > 0)
        this -> denumire_rasa = denumire;
    else
        throw string("Denumire invalida");

    if(greutate > 0)
        this -> greutate = greutate;
    else
        throw string("Greutate invalida");
}

Urs::Urs(const Urs &copie):Animal(copie) {
    if(copie.denumire_rasa.length() > 0)
        this -> denumire_rasa = copie.denumire_rasa;
    else
        throw string("Denumire invalida");

    if(copie.greutate > 0)
        this -> greutate = copie.greutate;
    else
        throw string("Greutate invalida");
}

void Urs::descriere() {
    cout << "\n\n\tDescriere urs: ";
    cout << "\nUrsii sunt animale carnivore de talie mare, voluminoase, masive si greoaie";
    cout << "\nUrs: " << this -> denumire_rasa;
    cout << "\nAre: " << this -> greutate << " kg";
    cout << "\nAcest urs de tipul: " << getTip();
    cout << "\nEste periculos! Index de putere: " << this -> index_putere;
    if(this -> exista)
        cout << "\nSe poate vizita in gradina";
    else
        cout << "\nNu este in gradina";
}

string Urs::getDenumire() {
    return this -> denumire_rasa;
}

unsigned int Urs::getGreutate() {
    return this -> greutate;
}

istream &operator>>(istream &in, Urs &urs){
    bool e; int p; string t;

    cout << "\n\n\tAdaugare urs: ";
    cout << "\nRasa urs: "; in >> urs.denumire_rasa;
    cout << "Ursul cantareste (kg):  "; in >> urs.greutate;

    cout << "Se va putea vizita in gradina?(1-Da/0-Nu): "; in >> e;
    urs.setExista(e);
    cout << "Cat de periculos este?(1- inofensiv, 100-foarte periculos): "; in >> p;
    urs.setPutere(p);
    cout << "Cum este animalul?(PUI/MATUR/BATRAN): "; in >> t;

    if(t == "pui" || t == "PUI")
        urs.setTip(PUI);
    else{
        if(t == "matur" || t == "MATUR")
            urs.setTip(MATUR);
        else
            urs.setTip(BATRAN);
    }
    return in;
}

ostream &operator<<(ostream &out, Urs &urs){
    out << "\n\nAfisare urs " << urs.denumire_rasa;
    out << "\nAre " << urs.greutate << " kg";
    return out;
}

Urs& Urs ::operator=(const Urs &urs) {
    if(this != &urs){
        this -> denumire_rasa = urs.denumire_rasa;
        this -> greutate = urs.greutate;
        this -> index_putere = urs.index_putere;
        this -> exista = urs.exista;
        this -> tip = urs.tip;
    }

    return *this;
}
bool Urs::operator>(const Urs &urs) {
    return (this -> index_putere > urs.index_putere);
}

//----------------------------------------------------------------------------------------------------------

GradinaZoo::GradinaZoo() {
    this -> animale = NULL;
    this -> nr_animale = 0;
    this -> size = 0;
    this -> valid = true;
    this -> denumire_gradina = "Anonim";
}

GradinaZoo::GradinaZoo(int nr_animale, string denumire) {
    this -> valid = true;
    this -> size = 0;

    if(denumire.length() > 0)
        this -> denumire_gradina = denumire;
    else
        throw string("Denumire invalida");

    if(nr_animale > 0)
        this -> nr_animale = nr_animale;
    else
        throw string("Nr de animale invalid");

    this -> animale = new Animal*[nr_animale];
}

GradinaZoo::GradinaZoo(const GradinaZoo &copie) {
    if(copie.denumire_gradina.length() > 0)
        this -> denumire_gradina = copie.denumire_gradina;
    else
        throw string("Denumire invalida");

    if(copie.nr_animale > 0)
        this -> nr_animale = copie.nr_animale;
    else
        throw string("Nr de animale invalid");

    if(copie.size > 0)
        this -> size = copie.size;
    else
        throw string("Dimensiunea actuala invalida");

    this -> valid = false;

    if(copie.animale != NULL)
        for(int i = 0; i < this -> nr_animale; i++)
            animale[i] = copie.animale[i];
    else
        throw string("Date invalide");

}

GradinaZoo::~GradinaZoo() {
    if((!this -> valid)){
        delete this->animale;
        return;
    }

    for(int i = 0; i < this->nr_animale; i++)
        delete this -> animale[i];
    delete this -> animale;
}

void GradinaZoo::pushback(Animal *p) {
    if(this -> nr_animale <= size  || this -> animale == NULL)
        return;

    this -> animale[(this ->size)++] = p;

}

void GradinaZoo::afisare_date_gradina() {
    cout << "\n\n\tGradinaZoo: " << this->denumire_gradina;

    if(this -> size > 0 && this -> animale != NULL && this -> nr_animale > 0){
        for(int i = 0; i < this -> nr_animale; i++){
            cout << "\n\tAnimalul: " << i + 1;
            cout << "\nEste: " << this ->animale[i]->getTip();
            cout << "\nIndex putere: " << this->animale[i]->getPutere();
            cout << boolalpha;
            cout << "\nExista in gradina?: " << this->animale[i]->getExista();
        }
    }
    else
        throw string("Date invalide");
}
