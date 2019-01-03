#ifndef GRADINA_ZOO_GRADINAZOO_H
#define GRADINA_ZOO_GRADINAZOO_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

enum TipAnimal{
    PUI,
    MATUR,
    BATRAN,
};

template <typename T>
bool compara(T a, T b){
    return (a > b);
}

class Animal{
protected:
    int index_putere;
    bool exista;
    TipAnimal tip;

public:
    Animal();
    Animal(int index_putere, bool exista, TipAnimal tip);
    Animal(const Animal &copie);
    virtual ~Animal(){};
    virtual void descriere() = 0;
    int getPutere();
    bool getExista();
    string getTip();
    TipAnimal getTipp();
    void setExista(bool e);
    void setPutere(int p);
    void setTip(TipAnimal tip);

    Animal &operator=(const Animal &copie);
    bool operator>(const Animal &animal);
};

class Lup : public Animal{
private:
    string denumire_rasa;

public:
    Lup();
    Lup(string denumire, int indexp, bool exista, TipAnimal tip);
    Lup(const Lup &copie);
    ~Lup(){};
    void descriere();
    string getDenumire();

    friend istream &operator>>(istream &in, Lup &lup);
    friend ostream &operator<<(ostream &out, Lup &lup);
    Lup &operator=(const Lup &lup);
    bool operator>(const Lup &lup);
};

class Urs : public Animal{
private:
    string denumire_rasa;
    unsigned int greutate;

public:
    Urs();
    Urs(string denumire, unsigned int greutate, int indexp, bool exista, TipAnimal tip);
    Urs(const Urs &copie);
    ~Urs(){};
    void descriere();
    string getDenumire();
    unsigned int getGreutate();

    friend istream &operator>>(istream &in, Urs &urs);
    friend ostream &operator<<(ostream &out, Urs &urs);
    Urs &operator=(const Urs &urs);
    bool operator>(const Urs &urs);

};

class GradinaZoo{
private:
    Animal **animale;
    int nr_animale;
    int size;
    bool valid;
    string denumire_gradina;
public:
    GradinaZoo();
    GradinaZoo(int nr_animale, string denumire);
    GradinaZoo(const GradinaZoo &copie);
    ~GradinaZoo();

    void pushback(Animal *p);
    void afisare_date_gradina();
};



#endif //GRADINA_ZOO_GRADINAZOO_H
