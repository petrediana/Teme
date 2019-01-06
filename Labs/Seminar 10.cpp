//// Seminar10.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
#include "pch.h"
//#include <iostream>
//#include<string>
//using namespace std;
//
////garaj cu biciclete-culoare, serie, pret, getNrRoti
////si masini - culoare, nr_inmatriculare,pret, getNrRoti
//
////comun culoare si pret
//class Vehicul {
//protected:
//	string culoare;
//	float pret;
//public:
//	Vehicul(string v_culoare, float v_pret);
//	float getPret();
//	virtual int getNrRoti()=0;//virtuala pura
//	virtual void afisare();
//};
//
////interfata
//class IDeInchiriat {
//public:
//	virtual float pretM() = 0;
//	virtual void adaugaTaxa(int procent) = 0;
//};
//
//class Masina :public Vehicul, public IDeInchiriat {
//private:
//	string nr_inmatriculare;
//public:
//	Masina(string v_nr_inmatriculare,
//		string v_culoare,
//		float v_pret);
//	int getNrRoti();
//	void afisare();
//	float pretM();
//	void adaugaTaxa(int procent);
//};
//
//class Bicicleta : public Vehicul, public IDeInchiriat {
//private:
//	string serie;
//public:
//	Bicicleta(string v_serie,
//		string v_culoare,
//		float v_pret);
//	int getNrRoti();
//	void afisare();
//	float pretM();
//	void adaugaTaxa(int procent);
//};
//
//class Garaj {
//private:
//	unsigned int nr_vehicule;
//	Vehicul** vehicule;
//public:
//	Garaj(unsigned int v_nr_vehicule,
//		Vehicul** v_vehicule);
//	Garaj(const Garaj& copie);
//	~Garaj();
//	friend ostream& operator<<(ostream& out, Garaj g);
//};
//
//
//int main()
//{
//    cout << "Hello World!\n"; 
//
//	Masina m("B10GR39", "Rosie", 23.2F);
//	m.afisare();
//	Bicicleta b("ASXADS", "Alb", 1.5F);
//	b.afisare();
//
//	Vehicul* v1 = &m;
//	Vehicul* v2 = &b;
//
//	v1->afisare();
//	v2->afisare();
//
//	IDeInchiriat* vehicule[2] = { &m,&b };
//
//	for (int i = 0; i < 2; i++) {
//		cout << "Pret inainte: " << vehicule[i]->pretM() << endl;
//		vehicule[i]->adaugaTaxa(-1);
//		cout << "Pret dupa: " << vehicule[i]->pretM() << endl;
//	}
//
//	Vehicul* vector[2] = { &m,&b };
//
//	Garaj g(2, vector);
//
//	cout << g;
//}
//
//Vehicul::Vehicul(string v_culoare, float v_pret) {
//	if (v_culoare.length() > 0) {
//		this->culoare = v_culoare;
//	}
//	else {
//		this->culoare = "Anonim";
//	}
//
//	if (v_pret >= 0) {
//		this->pret = v_pret;
//	}
//}
//
//float Vehicul::getPret() {
//	return this->pret;
//}
//
//void Vehicul::afisare() {
//	cout << "Afisare caracteristici vehicul" << endl;
//	cout << "Culoare: " << this->culoare << endl;
//	cout << "Pret: " << this->pret << endl;
//}
//
//Masina::Masina(string v_nr_inmatriculare,
//	string v_culoare,
//	float v_pret):Vehicul(v_culoare, v_pret) {
//
//	if (v_nr_inmatriculare.length() > 0) {
//		this->nr_inmatriculare = v_nr_inmatriculare;
//	}else{
//		this->nr_inmatriculare = "Anonim";
//	}
//}
//
//int Masina::getNrRoti() {
//	return 4;
//}
//
//void Masina::afisare() {
//	cout << "Afisare masina: " << endl;
//	cout << "Numar inmatriculare: " << this->nr_inmatriculare << endl;
//	cout << "Culoare: " << this->culoare << endl;
//	cout << "Pret: " << this->pret << endl;
//}
//
//void Masina::adaugaTaxa(int procent) {
//	if (procent > 0 && procent <= 100) {
//		this->pret *= (1 + procent / 100);
//		//this->pret = this->pret +this->pret*procent/100;
//	}
//	else {
//		this->pret *= 1.1;
//	}
//}
//
//float Masina::pretM() {
//	return this->getPret();
//}
//
//Bicicleta::Bicicleta(string v_serie,
//	string v_culoare,
//	float v_pret) :Vehicul(v_culoare, v_pret) {
//	if (v_serie.length() > 0) {
//		this->serie = v_serie;
//	}
//	else {
//		this->serie = "Anonim";
//	}
//}
//int Bicicleta::getNrRoti() {
//	return 2;
//}
//void Bicicleta::afisare() {
//	cout << "Afisare bicicleta: " << endl;
//	cout << "Serie: " << this->serie << endl;
//	cout << "Culoare: " << this->culoare << endl;
//	cout << "Pret: " << this->pret << endl;
//}
//
//void Bicicleta::adaugaTaxa(int procent) {
//	if (procent > 0 && procent <= 100) {
//		this->pret *= (1 + procent / 100);
//	}
//	else {
//		this->pret *= 1.08;
//	}
//}
//
//float Bicicleta::pretM() {
//	return this->getPret();
//}
//
//Garaj::Garaj(unsigned int v_nr_vehicule,
//	Vehicul** v_vehicule) {
//	this->nr_vehicule = v_nr_vehicule;
//	if (v_vehicule != NULL && this->nr_vehicule > 0) {
//		this->vehicule = new Vehicul*[this->nr_vehicule];
//		for (int i = 0; i < this->nr_vehicule; i++) {
//			this->vehicule[i] = v_vehicule[i];
//		}
//	}
//}
//
//Garaj::Garaj(const Garaj& copie) {
//	this->vehicule = copie.vehicule;
//	if (copie.vehicule != NULL && this->nr_vehicule > 0) {
//		this->vehicule = new Vehicul*[this->nr_vehicule];
//		for (int i = 0; i < this->nr_vehicule; i++) {
//			this->vehicule[i] = copie.vehicule[i];
//		}
//	}
//}
//
//Garaj::~Garaj() {
//	if (this->vehicule != NULL && this->nr_vehicule > 0) {
//		delete[] this->vehicule;
//	}
//}
//
//ostream& operator<<(ostream& out, Garaj g) {
//	out << "Afisare garaj" << endl;
//	if (g.vehicule != NULL && g.nr_vehicule > 0) {
//		for (int i = 0; i < g.nr_vehicule; i++) {
//			g.vehicule[i]->afisare();
//		}
//	}
//
//	return out;
//}