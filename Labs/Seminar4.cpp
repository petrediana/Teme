// Seminar4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Seminar 4 POO:

variabile constante:-cuvant cheie const;
					-valoarea unei variabile este constanta si ii specifica compilatorului sa-l avertizeze pe programator in momentul in care doreste sa modifice continut acesteia.
					- in clase, toate variabilele sunt intializate in constructor.

variabile statice:- cuvant cheie static;
				  - poate fi folosita: in interiorul unei functie, atribut al clasei sau variabile globale dintr-un fisier.
				  - in functie: specifica faptul ca acea variabila este intializata o singura data in memorie si este stearsa in momentul in care programul isi termina executia.
				  - atribut al clasei: o sa se intializeze o singura zona de memorie pentru toate instantele clasei, prin urmare atunci cand o instanta modifica valoarea unei variabile statice acesta se reflecta si in celelalte instante.
				  - atributele statice se mai numesc si variabile de clasa.
				  - atributul static nu poate fi initializat in zona de declarare sau implementare a unei clasei
				  - functii statice: nu trebuie sa exista o instanta a clase pentru a putea fi folosite.se pot utiliza doar pentru alte variabile statice

constructor copiere:- aloca spatiul aferent unui obiect si il initializeaza pe acesta cu valorile unui obiect existent.
					- este folosit pentru a construi un obiect cu valorile unui alt obiect al clasei.
					- este utilizat in urmatoarele situatii : initializarea unui obiect cu val altuia de acelas tip; copiere unui obiect trimis ca si param de intrare al unei functii; copierea unui obiect la returnarea unei valori de catre o functie.

*/
#include "pch.h"
#include<iostream>
using namespace std;

class Hotel {
	//default este pus private
private:
	const int id;
	char* nume;
	char adresa[60];
	bool deschis;
	unsigned int nr_camere;
	float* preturi;
public:
	static int nr_total;
	Hotel();// constructor default
	Hotel(int v_id, char* v_nume, bool v_deschis = true);//constructor cu mai multi param
	Hotel(int v_id, char* v_nume, char v_adresa[60], bool v_deschis, int v_nr_camere, float* v_preturi);
	Hotel(const Hotel& copie);
	~Hotel();//destructor
	void afisare();
	//setter si getter
	void setNume(char* v_nume);
	char* getNume();
};

int Hotel::nr_total = 0;

int main() {
	//constructor default
	//variabila normala
	Hotel h1;
	h1.afisare();
	//variabila pointer
	Hotel* h2 = new Hotel();
	h2->afisare();
	delete h2;
	//constructor mai multi param
	//variabila normala
	char* variab = new char[strlen("Constr variab normala") + 1];
	strcpy(variab, "Constr variab normala");
	Hotel h3(1, variab);
	h3.afisare();
	//pointer
	Hotel* h4 = new Hotel(2, variab, false);
	h4->afisare();
	delete h4;

	Hotel h5 = h3;
	h5.afisare();

	cout << "Numarul total de hoteluri existente: " << Hotel::nr_total << endl;

	return 0;
}

Hotel::Hotel() :id(-1) { //Hotel::Hotel(Hotel* this)- dispunere memorie
	//this->id = -1;
	this->nume = new char[strlen("Anonim") + 1];
	strcpy(this->nume, "Anonim");
	strcpy(this->adresa, "Anonim");
	this->deschis = false;
	this->nr_camere = 0;
	this->preturi = NULL;

	Hotel::nr_total++;
}

Hotel::Hotel(int v_id, char* v_nume, bool v_deschis) :id(v_id) {//Hotel::Hotel(Hotel* this, int v_id, char* v_nume);
	//this->id = v_id;
	if (v_nume != NULL) {
		this->nume = new char[strlen(v_nume) + 1];
		strcpy(this->nume, v_nume);
	}
	strcpy(this->adresa, "Anonim");
	this->deschis = v_deschis;
	this->nr_camere = 0;
	this->preturi = NULL;

	Hotel::nr_total++;
}

Hotel::Hotel(int v_id, char* v_nume, char v_adresa[60],
	bool v_deschis, int v_nr_camere, float* v_preturi) :id(v_id) {

	//this->id = v_id;
	if (v_nume != NULL) {
		this->nume = new char[strlen(v_nume) + 1];
		strcpy(this->nume, v_nume);
	}

	if (v_adresa != NULL) {
		strcpy(this->adresa, v_adresa);
	}

	this->deschis = v_deschis;
	this->nr_camere = v_nr_camere;

	if (v_preturi != NULL) {
		this->preturi = new float[this->nr_camere];
		for (int i = 0; i < this->nr_camere; i++) {
			this->preturi[i] = v_preturi[i];
		}
	}

	Hotel::nr_total++;
}

Hotel::Hotel(const Hotel& copie) :id(copie.id) { //:id(Hotel::nr_total++) {
	if (copie.nume != NULL) {
		this->nume = new char[strlen(copie.nume) + 1];
		strcpy(this->nume, copie.nume);
	}
	if (copie.adresa != NULL) {
		strcpy(this->adresa, copie.adresa);
	}

	this->deschis = copie.deschis;
	this->nr_camere = copie.nr_camere;
	if (copie.preturi != NULL) {
		this->preturi = new float[this->nr_camere];
		for (int i = 0; i < this->nr_camere; i++) {
			this->preturi[i] = copie.preturi[i];
		}
	}
}

void Hotel::afisare() {
	cout << "Afisare hotel: " << endl;
	cout << "Id: " << this->id << endl;
	cout << "Nume: " << this->nume << endl;
	cout << "Adresa: " << this->adresa << endl;
	if (this->deschis == true) {
		cout << "Deschis" << endl;
	}
	else {
		cout << "Inchis" << endl;
	}
	cout << "Numarul de camere: "
		<< this->nr_camere << endl;
	if (this->preturi != NULL) {//constructor default alocat cu NULL
		for (int i = 0; i < this->nr_camere; i++) {
			cout << "Pretul camerei "
				<< i + 1
				<< " este "
				<< this->preturi[i] << endl;
		}
	}
}

void Hotel::setNume(char* v_nume) {
	if (this->nume != NULL) {
		delete[]this->nume;
	}
	if (v_nume != NULL) {
		this->nume = new char[strlen(v_nume) + 1];
		strcpy(this->nume, v_nume);
	}
}

char* Hotel::getNume() {
	return this->nume;
}

Hotel::~Hotel() {
	cout << "Apel destructor" << endl;
	if (this->nume != NULL) {
		delete[] this->nume;
	}

	if (this->preturi != NULL) {
		delete[] this->preturi;
	}

	Hotel::nr_total--;
}