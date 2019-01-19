// Avocat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <list>

using namespace std;

class Avocat {
private:
	const int cod;
	char *nume;
	float onorariu;
	int nr_procese;
	float *valori_procese;

public:

	char *getNume() {
		return this->nume;
	}

	int getCod() {
		return this->cod;
	}

	float *getVectorProcese() {
		return this->valori_procese;
	}

	float getOnorariu() {
		return this->onorariu;
	}

	void setVectorProcese(float *vector, int dimensiune) {
		if (this->valori_procese != NULL)
			delete[] this->valori_procese;

		if (vector != NULL && dimensiune > 0) {
			this->valori_procese = new float[dimensiune];
			for (int i = 0; i < dimensiune; i++)
				this->valori_procese[i] = vector[i];
		}
	}

	void setNume(const char *alt_nume) {
		if (this->nume != NULL)
			delete[] this->nume;

		if (alt_nume != NULL) {
			this->nume = new char[strlen(alt_nume) + 1];
			strcpy(this->nume, alt_nume);
		}
	}

	Avocat():cod(0) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");

		this->onorariu = 0;
		this->nr_procese = 0;
		this->valori_procese = NULL;
	}

	Avocat(int v_cod, const char *v_nume, float v_onorariu, int v_nr_procese, float *v_valori_procese) :cod(v_cod) {
		if (v_nume != NULL) {
			this->nume = new char[strlen(v_nume) + 1];
			strcpy(this->nume, v_nume);
		}
		else {
			this->nume = new char[strlen("Anonim") + 1];
			strcpy(this->nume, "Anonim");
		}
		
		if (v_onorariu > 0)
			this->onorariu = v_onorariu;
		else
			this->onorariu = 0;

		if (v_nr_procese > 0)
			this->nr_procese = v_nr_procese;
		else
			this->nr_procese = 0;

		if (v_valori_procese != NULL) {
			this->valori_procese = new float[this->nr_procese];
			for (int i = 0; i < this->nr_procese; i++)
				this->valori_procese[i] = v_valori_procese[i];
		}
	}

	Avocat(const Avocat &copie):cod(copie.cod) {
		if (copie.nume != NULL) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy(this->nume, copie.nume);
		}

		if (copie.onorariu > 0)
			this->onorariu = copie.onorariu;

		if (copie.nr_procese > 0)
			this->nr_procese = copie.nr_procese;

		if (copie.valori_procese != NULL) {
			this->valori_procese = new float[this->nr_procese];
			for (int i = 0; i < this->nr_procese; i++)
				this->valori_procese[i] = copie.valori_procese[i];
		}
	}

	Avocat &operator=(const Avocat &copie) {
		if (this != &copie) {
			if (this->nume != NULL)
				delete[] this->nume;

			if (copie.nume != NULL) {
				this->nume = new char[strlen(copie.nume) + 1];
				strcpy(this->nume, copie.nume);
			}

			if (copie.onorariu > 0)
				this->onorariu = copie.onorariu;

			if (copie.nr_procese > 0)
				this->nr_procese = copie.nr_procese;

			if (this->valori_procese != NULL)
				delete[] this->valori_procese;

			if (copie.valori_procese != NULL) {
				this->valori_procese = new float[this->nr_procese];
				for (int i = 0; i < this->nr_procese; i++)
					this->valori_procese[i] = copie.valori_procese[i];
			}
		}

		return *this;
	}

	friend ostream &operator<<(ostream &out, Avocat &avocat) {
		out << endl;
		out << "\nIdentificator: " << avocat.cod;

		if (avocat.nume != NULL)
			out << "\nNume: " << avocat.nume;

		out << "\nOnorariu: " << avocat.onorariu;
		out << "\nNr procese: " << avocat.nr_procese;

		if (avocat.valori_procese != NULL) {
			out << "\nValori procese: ";

			for (int i = 0; i < avocat.nr_procese; i++)
				cout << avocat.valori_procese[i] << " ";
		}
		out << endl;
		return out;
	}

	Avocat &operator+(float proces_nou) {
		this->nr_procese++;

		float *aux; int i;
		aux = new float[this->nr_procese];

		if (this->valori_procese != NULL) {
			for (i = 0; i < this->nr_procese - 1; i++)
				aux[i] = this->valori_procese[i];
			aux[i++] = proces_nou;
		}

		delete[] this->valori_procese;

		this->valori_procese = new float[this->nr_procese];
		for (i = 0; i < this->nr_procese; i++)
			this->valori_procese[i] = aux[i];

		delete[] aux;

		return *this;
	}

	Avocat &operator-=(float diminuare) {
		this->onorariu -= diminuare;

		return *this;
	}

	bool operator>(Avocat &a) {
		return (this->nr_procese > a.nr_procese);
	}

	bool operator<(Avocat &a) {
		return (this->nr_procese < a.nr_procese);
	}

	bool operator==(Avocat &a) {
		return (this->nr_procese == a.nr_procese);
	}

	friend ofstream &operator<<(ofstream &fout, Avocat &avocat) {
		fout << avocat.cod << " ";
		fout << avocat.nume << " ";
		fout << avocat.onorariu << " ";
		fout << avocat.nr_procese << " ";
		
		for (int i = 0; i < avocat.nr_procese; i++)
			fout << avocat.valori_procese[i] << " ";
		
		return fout;
	}

	friend ifstream &operator>>(ifstream &fin, Avocat &avocat) {
		char buf[60];
		//fin.get();
		fin.getline(buf, 60);
		avocat.setNume(buf);

		fin >> avocat.onorariu;
		fin >> avocat.nr_procese;

		float v[60];
		for (int i = 0; i < avocat.nr_procese; i++)
			fin >> v[i];
		avocat.setVectorProcese(v, avocat.nr_procese);

		return fin;
	}

	float &operator[](int index) {
		if (this->valori_procese != NULL && index > 0 && index < this->nr_procese)
			return this ->valori_procese[index];
		else
			throw string("\nNu se poate");
	}

};

class AvocatOficiu : public Avocat {
private:
	char *client;
	int durata_proces;
public:

	AvocatOficiu(const char *v_client, int v_durata_proces, int cod, const char *v_nume,
		float v_onorariu, int v_nr_procese, float *v_vector_bani) : Avocat(cod, v_nume, v_onorariu,
																		   v_nr_procese, v_vector_bani) {
		
		if (v_client != NULL) {
			this->client = new char[strlen(v_client) + 1];
			strcpy(this->client, v_client);
		}
		else {
			this->client = new char[strlen("anonim") + 1];
			strcpy(this->client, "anonim");
		}

		if (v_durata_proces > 0)
			this->durata_proces = v_durata_proces;
		else
			this->durata_proces = 0;
	}

	AvocatOficiu(const AvocatOficiu &copie) : Avocat(copie) {
		if (copie.client != NULL) {
			this->client = new char[strlen(copie.client) + 1];
			strcpy(this->client, copie.client);
		}

		if (copie.durata_proces > 0)
			this->durata_proces = copie.durata_proces;
	}

	friend ostream &operator<<(ostream &out, AvocatOficiu &avo) {
		out << "\nClient: " << avo.client;
		out << "\nDurata p: " << avo.durata_proces;
		out << "\nCod: " << avo.getCod();
		//etc

		return out;
	}
};


int main()
{	
	float vectProc1[] = { 11.0, 12.0, 13.0, 14.0, 15.0 };
	float vectProc2[] = { 16.0, 17.0, 18.0, 19.0, 20.0 };
	Avocat a1;
	Avocat a2(123, "Georgescu Vasile", 120.0, 3, vectProc1);

	cout << a2.getNume() << endl;
	a2.setNume("Paraschivescu Gigel");
	cout << a2.getNume() << endl;

	cout << a1.getCod() << endl;
	cout << a2.getVectorProcese() << endl;
	a2.setVectorProcese(vectProc2, 4);
	cout << a2.getVectorProcese();

	Avocat a3 = a2;
	Avocat a4;
	a4 = a3;

	cout << endl;
	cout << a1 << a2 << a3 << a4;

	a3 = a3 + 2000;
	cout << "\nAdaugare de proces nou: ";
	for (int i = 0; i < 4; i++)
		cout << a3.getVectorProcese()[i] << " ";

	cout << "\nOnorariu a2: " << a2.getOnorariu();
	a2 -= 30;
	cout << "\nOnorariu diminuat: " << a2.getOnorariu();

	cout << endl;
	if (a3 > a2)
		cout << "\na3 are mai multe procese ca a2";
	else
		if (a3 < a2)
			cout << "\na3 are mai putine procese ca a2";
		else
			if (a3 == a2)
				cout << "\nacelasi nr de procese";

	ofstream FisierOUT;
	FisierOUT.open("afisare.txt", ofstream::out);
	
	if (FisierOUT.is_open())
		FisierOUT << a4;
	else
		cout << "\nFisierul nu este deschis";

	FisierOUT.close();

	ifstream FisierIN;
	FisierIN.open("citire.txt", ifstream::in);

	if (FisierIN.is_open()) {
		FisierIN >> a4;
		cout << a4;
	}
	else
		cout << "\nNu e deschis";

	cout << "\n" << a2[2];

	AvocatOficiu ao1("Popescu Ioan", 4, 123, "Georgescu Vasile", 120.0, 3, vectProc1);
	cout << endl;
	cout << ao1;

	list<Avocat> barou;
	barou.push_back(a1);
	barou.push_back(a2);
	barou.push_back(a3);
	barou.push_back(a4);

	barou.sort();

	list<Avocat> ::iterator it;
	for (it = barou.begin(); it != barou.end(); it++)
		cout << *it;

  
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
