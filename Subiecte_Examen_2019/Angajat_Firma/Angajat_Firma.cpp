// Angajat_Firma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class Angajat {
private:
	const int marca;
	char *nume;
	char functia[20];
	double salariul;
public:
	static int nr_ang_gen;
	
	~Angajat() {
		if (this->nume != NULL)
			delete[] this->nume;
	}

	void set_Functie(const char f[20]) {
		if (f != NULL)
			strcpy(this->functia, f);
	}

	char *get_Functia() {
		return this->functia;
	}

	double get_salariul() {
		return this->salariul;
	}

	int get_Marca() {
		return this->marca;
	}

	Angajat() :marca(Angajat::nr_ang_gen++) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");

		strcpy(this->functia, "Anonim");
		this->salariul = 0;
	}

	Angajat(const char *v_nume, const char v_functia[20], double v_salariul) :marca(Angajat::nr_ang_gen++) {
		if (v_nume != NULL) {
			this->nume = new char[strlen(v_nume) + 1];
			strcpy(this->nume, v_nume);
		}

		if (v_functia != NULL)
			strcpy(this->functia, v_functia);

		if (v_salariul > 0)
			this->salariul = v_salariul;
	}

	Angajat(const Angajat &copie) :marca(Angajat::nr_ang_gen++) {
		if (copie.nume != NULL) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy(this->nume, copie.nume);
		}

		if (copie.functia != NULL)
			strcpy(this->functia, copie.functia);

		if (copie.salariul > 0)
			this->salariul = copie.salariul;
	}

	friend istream &operator>>(istream &in, Angajat &ang) {
		cout << "\n\n\tCitire obiect de la tastatura: ";

		char buf[50];
		cout << "\nNumele: "; in.getline(buf, 50);
		if (buf != NULL) {
			ang.nume = new char[strlen(buf) + 1];
			strcpy(ang.nume, buf);
		}

		cout << "Functia: "; in.getline(ang.functia, 20);
		cout << "Salariul: "; in >> ang.salariul;
		return in;
	}

	friend ostream &operator<<(ostream &out, Angajat &ang) {
		out << "\n\n\tAfisare obiect angajat: ";
		out << "\nMarca: " << ang.marca;
		out << "\nNumele: " << ang.nume;
		out << "\nFunctia: " << ang.functia;
		out << "\nSalariul: " << ang.salariul;

		return out;
	}

	Angajat &operator=(const Angajat &copie) {
		if (copie.nume != NULL) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy(this->nume, copie.nume);
		}

		if (copie.functia != NULL)
			strcpy(this->functia, copie.functia);

		if (copie.salariul > 0)
			this->salariul = copie.salariul;

		return *this;
	}


};

class Firma {
private:
	Angajat *angajati;
	int nr_angajati;
	char *denumire;
	double CA;
public:

	int nr_programatori() {
		int count = 0;
		for (int i = 0; i < this->nr_angajati; i++) {
			if (strcmp(this->angajati[i].get_Functia(), "Programator"))
				count++;		}
		return count;
	}
	
	Firma() {
		this->angajati = NULL;
		this->nr_angajati = 0;
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->CA = 0;
	}

	Firma(Angajat *v_ang, int v_nr_ang, const char *v_denumire, double v_CA) {
		if (v_nr_ang > 0)
			this->nr_angajati = v_nr_ang;

		if (v_denumire != NULL) {
			this->denumire = new char[strlen(v_denumire) + 1];
			strcpy(this->denumire, v_denumire);
		}

		if (v_CA > 0)
			this->CA = v_CA;

		if (v_ang != NULL) {
			this->angajati = new Angajat[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++)
				this->angajati[i] = v_ang[i];
		}

	}

	Firma(const Firma &copie) {
		if (copie.nr_angajati > 0)
			this->nr_angajati = copie.nr_angajati;

		if (copie.denumire != NULL) {
			this->denumire = new char[strlen(copie.denumire) + 1];
			strcpy(this->denumire, copie.denumire);
		}

		if (copie.CA > 0)
			this->CA = copie.CA;

		if (copie.angajati != NULL) {
			this->angajati = new Angajat[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++)
				this->angajati[i] = copie.angajati[i];
		}
	}

	Firma &operator=(const Firma &copie) {
		if (copie.nr_angajati > 0)
			this->nr_angajati = copie.nr_angajati;

		if (copie.denumire != NULL) {
			this->denumire = new char[strlen(copie.denumire) + 1];
			strcpy(this->denumire, copie.denumire);
		}

		if (copie.CA > 0)
			this->CA = copie.CA;

		if (copie.angajati != NULL) {
			this->angajati = new Angajat[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++)
				this->angajati[i] = copie.angajati[i];
		}

		return *this;
	}

	friend ostream &operator<<(ostream &out, Firma &firma) {
		out << "\n\n\tAfisare obiect firma: ";
		out << "\nNr angajati: " << firma.nr_angajati;
		out << "\nDenumire: " << firma.denumire;
		out << "\nCifra afaceri: " << firma.CA;

		out << "\nAngajatii firmei sunt: ";
		for (int i = 0; i < firma.nr_angajati; i++)
			out << firma.angajati[i];

		return out;
	}

	Firma &operator +=(Angajat &ang) {
		Angajat *aux_angajat;
		aux_angajat = new Angajat[this->nr_angajati + 1];

		for (int i = 0; i < this->nr_angajati; i++)
			aux_angajat[i] = this->angajati[i];
		aux_angajat[this ->nr_angajati ++] = ang;

		delete[] this->angajati;
		this->angajati = new Angajat[this->nr_angajati];
		for (int i = 0; i < this->nr_angajati; i++)
			this->angajati[i] = aux_angajat[i];
		delete[] aux_angajat;
		
		return *this;
	}

	bool operator>(Firma &f) {
		return(this->nr_programatori() > f.nr_programatori());
	}

	bool operator<(Firma &f) {
		return(this->nr_programatori() < f.nr_programatori());
	}

	bool operator==(Firma &f) {
		return(this->nr_programatori() == f.nr_programatori());
	}

	explicit operator float() {
		double salariul_m = 0;

		if (this->angajati != NULL) {
			for (int i = 0; i < this->nr_angajati; i++) {
				salariul_m += this->angajati[i].get_salariul();
			}
		}

		return (salariul_m / this->nr_angajati);
	}

	Firma &operator -=(Angajat &ang) {
		Angajat *aux_angajati; int j = 0;
		aux_angajati = new Angajat[this->nr_angajati];

		for (int i = 0; i < this->nr_angajati; i++) {
			if (this->angajati[i].get_Marca() != ang.get_Marca()) {
				aux_angajati[j++] = this->angajati[i];
			}
							
		}

		delete[] this->angajati;
		this->nr_angajati = j;

		for (int i = 0; i < this->nr_angajati; i++)
			this->angajati[i] = aux_angajati[i];
		delete[]aux_angajati; 

		return *this;

	}
};

int Angajat::nr_ang_gen = 1;

int main()
{
	Angajat a1;
	Angajat a2("Gigel Ionescu", "Programator", 1500);
	Angajat a3 = a1;
	Angajat a4;
	//cin >> a4;
	a4.set_Functie("consultant");
	a1 = a4;
	cout << a1 << a2 << a3 << a4;

	/*Angajat vect[4] = { a1, a2, a3, a4 };
	

	Firma f1;
	Firma f2(vect, 4, "SC FIRMA MEA SRL", 12000);
	Firma f3 = f2;
	f1 = f3;
	cout << f1 << f2 << f3;

	Angajat a5("Marin georgescu", "contabil", 1520);
	f1 += a5;
	cout << f1;
	cout << "\nNr de programatori din firma f1: " << f1.nr_programatori();

	if (f1 > f3)
		cout << "\nF1 are mai multi programatori ca f3";
	if (f1 < f3)
		cout << "\nF1 are mai putini programatori ca f3";
	if (f1 == f3)
		cout << "\nF1 si f3 au acelasi nr de programatori";

	cout << "\nSalariul mediu pt firma f2: " << (float)f2;


	cout << f3;

	//f3 -= a2;
	//cout << f3;*/

	map<int, Angajat> mpAngajat;
	mpAngajat.insert(pair <int, Angajat>(a1.get_Marca(), a1));
	mpAngajat.insert(pair <int, Angajat>(a2.get_Marca(), a2));
	mpAngajat.insert(pair <int, Angajat>(a3.get_Marca(), a3));

	map<int, Angajat> ::iterator it;
	cout << "\nAfisare continuit mpangajat:\n";
	for (it = mpAngajat.begin(); it != mpAngajat.end(); it++)
		cout << it->first << it->second;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
