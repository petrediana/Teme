// Auto_Pers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;

class Auto {
private:
	int id_auto;
	char marca[30];
	float pret;
public:

	int getId() {
		return this->id_auto;
	}

	float getPret() {
		return this->pret;
	}

	char *getMarca() {
		return this->marca;
	}

	Auto() {
		this->id_auto = 1000;
		strcpy(this->marca, "Dacia");
		this->pret = 3000.0;
	}

	Auto(int v_id, const char v_marca[], float v_pret) {
		if (v_id > 0)
			this->id_auto = v_id;

		if (v_marca != NULL) {
			strcpy(this->marca, v_marca);
		}
		else
			strcpy(this->marca, "Anonim");

		if (v_pret > 0)
			this->pret = v_pret;
		else
			this->pret = 0;
	}

	Auto(const Auto &copie) {
		if (copie.id_auto > 0)
			this->id_auto = copie.id_auto;

		if (copie.marca != NULL)
			strcpy(this->marca, copie.marca);

		if (copie.pret > 0)
			this->pret = copie.pret;
	}

	friend ostream &operator<<(ostream &out, Auto &a) {
		out << "\n\tMasina";
		out << "\nId: " << a.id_auto;
		out << "\nMarca: " << a.marca;
		out << "\nPret $: " << a.pret;

		return out;
	}

	friend ofstream &operator<<(ofstream &fout, Auto &a) {
		fout << a.id_auto << " ";
		fout << a.marca << " ";
		fout << a.pret << " ";
		fout << "\n";
		return fout;
	}

	friend ifstream &operator>>(ifstream &fin, Auto &a) {
		fin >> a.id_auto;
		fin.ignore();
		fin.getline(a.marca, 30);
		fin >> a.pret;

		return fin;
	}
	

};


class Pers {
private:
	int id;
	char nume[30];
	Auto *pAuto;
	int id_auto;

public:
	char *getNume() {
		return this->nume;
	}
	int getID_Auto() {
		return this->id_auto;
	}

	Auto getp() {
		return *this -> pAuto;
	}

	Pers() {
		this->id = 100;
		strcpy(this->nume, "Anonim");
		this->pAuto = NULL;
		this->id_auto = 0;
	}

	Pers(int v_id, const char v_nume[]) {
		if (v_id > 0)
			this->id = v_id;
		else
			this->id = 0;

		if (v_nume != NULL) {
			strcpy(this->nume, v_nume);
		}
		else
			strcpy(this->nume, "Anonim");
	}

	Pers &operator<<(Auto &a) {
		this->id_auto = a.getId();
		this->pAuto = new Auto(a);

		return *this;
	}

	friend ostream &operator<<(ostream &out, Pers &p) {
		out << "\n\tPersoana";
		out << "\nId pers: " << p.id;
		out << "\nNume pers: " << p.nume;
		out << "\nId masina: " << p.id_auto;
		if (p.pAuto != NULL)
			out << *p.pAuto;
		else
			cout << "\nNu are masina inca:(";

		return out;
	}

	bool operator>(Auto &a) {
		return(this->pAuto->getPret() > a.getPret());
	}

	bool operator>(Pers &p) {
		return(this->pAuto->getPret() > p.pAuto->getPret());
	}

	friend ofstream &operator<<(ofstream &fout, Pers &p) {
		fout << p.id << " ";
		fout << p.nume << " ";
		//fout << p.id_auto << " ";
		if (p.pAuto != NULL)
			fout << *p.pAuto << " ";
		else
			fout << "Nu are masina";

		return fout;
	}

	friend ifstream &operator>>(ifstream &fin, Pers &p) {
		Auto copie;

		fin >> p.id;
		fin.ignore();
		fin.getline(p.nume, 30);
		fin >> copie;
		p.pAuto = new Auto(copie);
		p.id_auto = p.pAuto->getId();

		return fin;
	}
};

int main()
{
	Pers p1(1234, "popescu"), p2, p3, p4;
	Auto a1(10001, "Fiat", 6000), a2, a3, a4;

	cout << p1 << endl;
	cout << a1 << endl;

	p1 << a1;//cumpara masina
	p2 << a2;//cumpara masina

	cout << p1 << endl;
	cout << p2 << endl;

	cout << endl;
	if (p1 > a2)
		cout << p1.getNume() << " are o masina mai scumpa decat o " << a2.getMarca();
	else
		cout << p1.getNume() << " are o masina mai ieftina decat o " << a2.getMarca();

	cout << endl;
	if (p1 > p2)
		cout << p1.getNume() << "are o masina mai scumpa decat: " << p2.getNume();
	else
		cout << p1.getNume() << "are o masina mai ieftina decat: " << p2.getNume();

	ofstream autoOUT;
	autoOUT.open("Auto.txt", ofstream::out);

	if (autoOUT.is_open()) {
		autoOUT << a1;
		autoOUT << a2;
	} autoOUT.close();

	ofstream persOUT;
	persOUT.open("Pers.txt", ofstream::out);
	
	if (persOUT.is_open()) {
		persOUT << p1;
		persOUT << p2;
	} persOUT.close();

	ifstream autoIN;
	autoIN.open("Citire Auto.txt", ifstream::in);

	if (autoIN.is_open()) {
		autoIN >> a3;
		autoIN >> a4;
	} autoIN.close();

	cout << a3; cout << a4;

	map <int, Auto> parcAuto;
	parcAuto.insert(pair <int, Auto>(a3.getId(), a3));
	parcAuto.insert(pair <int, Auto>(a4.getId(), a4));

	map<int, Auto>::iterator it;

	ifstream persIN;
	persIN.open("Citire pers.txt", ifstream::in);

	if (persIN.is_open()) {
		persIN >> p3;
		persIN >> p4;
	}persIN.close();

	cout << p3;

	it  = parcAuto.find(p3.getID_Auto());
	p3.getp() = (it->second);
	
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
