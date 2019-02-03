// Videoclip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

class Exceptie_NRV : public exception {
public:
	string mesaj() {
		return "\nNumar de videoclipuri invalid!";
	}
};

class Exceptie_DV : public exception {
public:
	string mesaj() {
		return "\nVector de timp invalid!";
	}
};

class Exceptie_C : public exception {
public:
	string mesaj() {
		return "\nCategorie invalida";
	}
};

class VideoClip {
protected:
	const int id;
	static int generator_id;
	int nr_videoclipuri;
	float *durata_videoclip;
	string categorie;

public:
	int getNrV() {
		return this->nr_videoclipuri;
	}

	float *getDV() {
		return this->durata_videoclip;
	}

	VideoClip():id(generator_id++) {
		this->nr_videoclipuri = 0;
		this->durata_videoclip = NULL;
		this->categorie = "Anonim";
	}

	VideoClip(int v_nr_videoclipuri, float *v_durata, string v_categorie):id(generator_id++) {
		if (v_nr_videoclipuri > 0)
			this->nr_videoclipuri = v_nr_videoclipuri;
		else
			this->nr_videoclipuri = 0;

		if (v_durata != NULL) {
			this->durata_videoclip = new float[this->nr_videoclipuri];
			for (int i = 0; i < this->nr_videoclipuri; i++)
				this->durata_videoclip[i] = v_durata[i];
		}

		if (v_categorie.length() > 0)
			this->categorie = v_categorie;
		else
			this->categorie = "Anonim";
	}

	VideoClip(const VideoClip &copie) :id(generator_id++) {
		if (copie.nr_videoclipuri > 0)
			this->nr_videoclipuri = copie.nr_videoclipuri;
		else
			this->nr_videoclipuri = 0;
			
		this->durata_videoclip = new float[this->nr_videoclipuri];
		if (copie.durata_videoclip != NULL) {
			
			for (int i = 0; i < this->nr_videoclipuri; i++)
				this->durata_videoclip[i] = copie.durata_videoclip[i];
		}

		if (copie.categorie.length() > 0)
			this->categorie = copie.categorie;
		else
			this->categorie = "Anonim";
	}
	~VideoClip() {
		if (this->durata_videoclip != NULL)
			delete[] this->durata_videoclip;
	}

	int getID() {
		return this->id;
	}

	string getCategorie() {
		return this->categorie;
	}

	void setCategorie(string nume) {
		if (nume.length() > 0)
			this->categorie = nume;
	}

	void setNr_videoclipuri(int nr) {
		if (nr > 0)
			this->nr_videoclipuri = nr;
	}

	float medie_minute_video() {
		float m = 0;
		if (this->durata_videoclip != NULL && this ->nr_videoclipuri >0) {
			for (int i = 0; i < this->nr_videoclipuri; i++)
				m += this->durata_videoclip[i];
		}

		return (m / this->nr_videoclipuri);
	}

	float mare_video() {
		float max = 0.0;
		if (this->durata_videoclip != NULL && this->nr_videoclipuri > 0) {
			for (int i = 0; i < this->nr_videoclipuri; i++)
				if (max < this->durata_videoclip[i])
					max = durata_videoclip[i];
		}

		return max;
	}

	VideoClip &operator=(const VideoClip &copie) {
		if (this != &copie) {
			
			if (copie.nr_videoclipuri > 0)
				this->nr_videoclipuri = copie.nr_videoclipuri;
			else
				this->nr_videoclipuri = 0;

			if (copie.categorie.length() > 0)
				this->categorie = copie.categorie;
			else
				this->categorie = "Anonim";

			if (this->durata_videoclip != NULL)
				delete[] this->durata_videoclip;

			if (copie.durata_videoclip != NULL) {
				this->durata_videoclip = new float[this->nr_videoclipuri];
				for (int i = 0; i < this->nr_videoclipuri; i++)
					this->durata_videoclip[i] = copie.durata_videoclip[i];
			}
		}
		return *this;
	}

	friend ostream &operator<<(ostream &out, VideoClip &v) {
		out << "\n\tAfisare obiect VideoClip";
		out << "\nId: " << v.id;
		out << "\nCategorie: " << v.categorie;
		out << "\nNr videoclipuri: " << v.nr_videoclipuri;
		out << "\nDurata fiecarui videoclip: ";
		if(v.durata_videoclip != NULL)
		for (int i = 0; i < v.nr_videoclipuri; i++)
			out << v.durata_videoclip[i] << " ";

		return out;
	}

	float operator() () { //suma minutelor 
		float m = 0;
		if (this->durata_videoclip != NULL && this->nr_videoclipuri > 0) {
			for (int i = 0; i < this->nr_videoclipuri; i++)
				m += this->durata_videoclip[i];
		}

		return m;
	}

	bool operator!() {
		if (this->durata_videoclip == NULL)
			return true;
		else
			return false;
	}

	friend istream &operator>>(istream &in, VideoClip &v) {
		cout << "\n\tCitire obiect videoclip";
		bool ok = true;
		do {
			try {
				cout << "\nCategorie: "; getline(in, v.categorie);
				if (v.categorie.length() < 3)
					throw Exceptie_C();
				else
					break;
			}
			catch (Exceptie_C &e) {
				cout << e.mesaj();
				ok = false;
			}
		} while (!ok);
		
		ok = true;
		do {
			try {
				cout << "\nNumar videoclipuri: "; in >> v.nr_videoclipuri;
				if (v.nr_videoclipuri < 0)
					throw Exceptie_NRV();
				else
					break;
			}
			catch (Exceptie_NRV  &e) {
				cout << e.mesaj();
				ok = false;
			}
		} while (!ok);
		
		v.durata_videoclip = new float[v.nr_videoclipuri];
		ok = true; int count = 0;
		do {
			try {
				cout << "\nDurata pentru fiecare videoclip: ";

				for (int i = 0; i < v.nr_videoclipuri; i++) {
					in >> v.durata_videoclip[i];
					if (v.durata_videoclip[i] < 0)
						throw Exceptie_DV();
					else count++;
				}
				if (count == v.nr_videoclipuri)
					break;
			}
			catch (Exceptie_DV &e) {
				cout << e.mesaj();
				ok = false;
			}
		} while (!ok);
		
		return in;
	}

	friend ofstream &operator<<(ofstream &out, VideoClip &v) {
		out << v.id << " ";
		out << v.categorie << " ";
		out << v.nr_videoclipuri << " ";
		if(v.durata_videoclip != NULL)
		for (int i = 0; i < v.nr_videoclipuri; i++)
			out << v.durata_videoclip[i] << " ";
		out << endl;

		return out;
	}
};

class Video_VR : public VideoClip {
private:
	bool disponibilitate;
public:
	Video_VR() :VideoClip() {
		this->disponibilitate = false;
	}

	Video_VR(bool v_disp, int v_nr_videoclipuri, float *v_durata, string v_categorie) :VideoClip(v_nr_videoclipuri,
		v_durata, v_categorie) {
		this->disponibilitate = v_disp;
	}

	Video_VR(const Video_VR &copie) :VideoClip(copie) {
		this->disponibilitate = copie.disponibilitate;
	}

	friend ostream &operator<<(ostream &out, Video_VR &vr) {
		out << "\nEste disponibil in varianta VR?: " << vr.disponibilitate;
		
		out << "\nId: " << vr.id;
		out << "\nCategorie: " << vr.categorie;
		out << "\nNr videoclipuri: " << vr.nr_videoclipuri;
		out << "\nDurata fiecarui videoclip: ";
		if (vr.durata_videoclip != NULL)
			for (int i = 0; i < vr.nr_videoclipuri; i++)
				out << vr.durata_videoclip[i] << " ";

		return out;		
	}
};

template <typename T>
class Generic {
private:
	vector <T> chestii;
	bool valabil;
	string nume;
public:
	Generic(vector <T> stuff, bool val, string v_nume) {
		if (stuff.size() > 0)
			this->chestii = stuff;

		this->valabil = val;
		if (v_nume.length() > 0)
			this->nume = v_nume;
	}

	void afisare() {
		cout << "\nMetoda afisare clasa generic";
		cout << "\nEste valabil?: " << this->valabil;
		cout << "\nDenumire: " << this->nume;
		cout << "Contine: ";
		for (int i = 0; i < chestii.size(); i++)
			cout << chestii[i];
	}
};


int VideoClip::generator_id = 1;
int main()
{
	float v_durata[] = { 11.0, 12.0, 13.0, 14.0, 15.0 };
	VideoClip v1;
	VideoClip v2(3, v_durata, "Animatie");
	VideoClip v3(v2);

	cout << "\nId-ul v2: " << v2.getID() << " categoria: " << v2.getCategorie();
	v1.setCategorie("Horror");
	v1.setNr_videoclipuri(3);
	cout << "\nPentru v2 clipurile au in medie: " << v2.medie_minute_video()
					<< " minute " << " cel mai lung video fiind de: " << v2.mare_video();

	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;

	VideoClip v4;
	v4 = v2;
	cout << v4 << endl;
	cout << "\nV4 contine videouri cu durata de: " << v4();

	if (!v1)
		cout << "\nV1 nu contine videoclipuri cu durata";
	else
		cout << "\nV1 contine videoclipuri cu durata";

	VideoClip v6;
	cin >> v6;

	vector <VideoClip> vc(3);
	vc.push_back(v1);
	vc.push_back(v2);
	vc.push_back(v3);
	vc.push_back(v4);


	string numefisier;
	cout << "\nIntroduceti numele fisierului: "; 
	getline(cin, numefisier);

	ofstream file;
	file.open(numefisier, ofstream::out);
	if (file.is_open()) {
		for (auto i = vc.begin(); i != vc.end(); i++) {
			if (i->getID() % 2 == 0) //filtru: idul sa fie par
				file << *i;
		}
	} file.close();

	Video_VR vr1(true, 3, v_durata, "Comedie");
	cout << vr1;

	VideoClip vv1, vv2;
	vector <VideoClip> vec;
		vec.push_back(vv1);
	 vec.push_back(vv2);	
	 Generic<VideoClip> gv(vec, 1, "Videoclipuri normale");

	 gv.afisare();

	 map<int, VideoClip> mpVideo;
	 mpVideo.insert(pair <int, VideoClip>(v2.getID(), v2));
	 mpVideo.insert(pair <int, VideoClip>(v3.getID(), v3));
	 mpVideo.insert(pair <int, VideoClip>(v4.getID(), v4));

	 cout << "\n\n";
	 for (auto i = mpVideo.begin(); i != mpVideo.end(); i++) {
		 cout << i->first;
		 cout << endl;
		 cout << i->second;
	 }
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


/*VideoClip v5;
	bool ok = true;
	cin >> v5;
	do {
		try {
			cin >> v5;
			if (v5.getCategorie().length() >= 3)
				cout << "\nCategorie valida!";
			else
				throw Exceptie_C();

			if (v5.getNrV() > 0)
				cout << "\nNr de videoclipuri valid";
			else
				throw Exceptie_NRV();

			if (v5.getDV() != NULL)
				cout << "\nDurata valida";
			else
				throw Exceptie_DV();
		}
		catch (Exceptie_C &ec) {
			cout << ec.mesaj();
			ok = false;
		}
		catch (Exceptie_NRV &enrv) {
			cout << enrv.mesaj();
			ok = false;
		}
		catch (Exceptie_DV &edv) {
			cout << edv.mesaj();
			ok = false;
		}

	} while (!ok);*/