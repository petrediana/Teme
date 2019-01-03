#include "Gradinazoo.h"
#include <iostream>
#include <map>
#include <list>

using namespace std;

int main(){

    /*Lup lup;
    Urs urs;
    string *rase;

    unsigned int i, nr_lupi, nr_ursi;
    cout << "\nCati lupi?: "; cin >> nr_lupi;
    cout << "Cati ursi?: "; cin >> nr_ursi;
    rase = new string[nr_lupi + nr_ursi + 1];

    GradinaZoo gradina((nr_lupi + nr_ursi), "Test gradina {}");
    for(i = 0; i < nr_lupi; i++) {
        cout << "\nIntroduceti un lup:";
        cin >> lup;

        Animal *pa = new Lup(lup.getDenumire(), lup.getPutere(), lup.getExista(), lup.getTipp());
        gradina.pushback(pa);
        rase[i] = lup.getDenumire();
    }

    for(i = nr_lupi; i < nr_lupi + nr_ursi; i++){
        cout << "\nIntroduceti un urs:";
        cin >> urs;

        Animal *pa = new Urs(urs.getDenumire(), urs.getGreutate(), urs.getPutere(), urs.getExista(), urs.getTipp());
        gradina.pushback(pa);
        rase[i] = urs.getDenumire();
    }

    gradina.afisare_date_gradina();
    cout << "\nAu fost adaugate " << nr_lupi + nr_ursi << " rase de animale: ";
    for(i = 0; i < nr_lupi + nr_lupi; i++)
        cout << rase[i] << " ";
        delete rase;*/

    Animal *pa3 = new Lup("Arctic", 10, 1, PUI);
    Animal *pa4 = new Urs("Brun", 150, 80, 1, MATUR);
    Animal *pa5 = new Lup("Arctic", 10, 1, PUI), *pa6 = new Urs("Brun", 150, 80, 1, MATUR);

    if(compara<Animal*>(pa3, pa4))
        cout << "\nLup mai puternic";
    else
        cout << "\nUrs mai puternic";

    Urs u1 = Urs("Panda", 50, 1, 1, MATUR);
    Urs u2 = Urs("Polar", 350, 70, 1, BATRAN);

    cout << "\n";
    if(compara<Urs>(u1, u2))
        cout << u1.getDenumire() << " mai puternic decat " << u2.getDenumire();
    else
        cout << u2.getDenumire() << " mai puternic decat " << u1.getDenumire();

   list<Urs> alti_ursi;
    alti_ursi.push_back(u1);
    alti_ursi.push_back(u2);

    list<Urs>::iterator it_urs;
    for(it_urs = alti_ursi.begin(); it_urs != alti_ursi.end(); it_urs++)
        cout << *it_urs;

    //GradinaZoo g1(2, "Prima gradina");
    //GradinaZoo g2(2, "A doua gradina");


   // g1.pushback(pa3); g2.pushback(pa5);
    //g1.pushback(pa4); g2.pushback(pa6);//cand iese din functie le sterge!



    //delete pa3;
    //delete pa4;
    return 0;
}


/*Animal *pa1 = new Lup("Arctic", 10, 1, PUI);
Animal *pa2 = new Urs("Brun", 150, 80, 1, MATUR);

GradinaZoo g1(2, "G zoo");
g1.pushback(pa1);
g1.pushback(pa2);

g1.afisare_date_gradina();

 *
 * Lup l1("Arctic", 10, 1, PUI);
    Lup l2 ("Cenusiu", 25, 1, MATUR);
    Urs u1("Brun", 150, 80, 1, MATUR);

  Lup l1("Arctic", 10, 1, PUI);
l1.descriere();

Animal *pa = new Lup("Cenusiu", 25, 1, MATUR);
pa -> descriere();

cout << endl;
cout << pa ->getTip() << endl;
cout << pa ->getPutere() << endl;*/

//Lup l2;
//cin >> l2;
//l2.descriere();

/*Lup *lupi;
unsigned int nr_lupi;
Animal *panimale;

cout << "\nCati lupi?: "; cin >> nr_lupi;
lupi = new Lup[nr_lupi];
panimale = new Lup[nr_lupi];

for(unsigned int i = 0; i < nr_lupi; i++){
    cin >> lupi[i];
    lupi[i].descriere();
}

delete lupi;
delete panimale;*/

//Urs u2("Brun", 250, 90, 1, MATUR);
//u2.descriere();