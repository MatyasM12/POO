#include"Domain.h"
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;
//TODO: TEST COMPARARE EOF
/*
void testBaza()
{
	Ferma e1;
	//Constructor implicit
	e1 = Ferma();
	assert(e1.getid() == 0);

	//Constructor cu parametri
	Ferma e2 = Ferma(12);
	assert(e2.getid() == 12);

	//Constructor de copiere
	Ferma e3 = Ferma(e2);					//Copiere a unui obiect cu parametri
	assert(e3.getid() == 12);

	Ferma e4 = Ferma(e1);					//Copiere a unui obiect fara parametri
	assert(e4.getid() == 0);

	//testare set
	e3.setid(13);
	assert(e3.getid() == 13);

	//Operator de atribuire
	Ferma e5;								//Copeirea a unui obiect cu parametri
	e5 = e2;
	assert(e5.getid() == 12);
	Ferma e6;								//Copiere a unui obiect fara parametri
	e6 = e1;
	assert(e6.getid() == 0);

	cout << "Teste Clasa de baza OK" << endl;
	//system("pause");

}*/

void testAsociata()
{
	Pom e1;
	//Constructor implicit
	e1 = Pom();
	assert(e1.getDenumire() == NULL);
	assert(e1.getNr() == 0);

	//Constructor cu parametri
	Pom e2 = Pom(12, "mar");
	assert(strcmp(e2.getDenumire(), "mar") == 0);
	assert(e2.getNr() == 12);
	//std::cout << e2.getNr();


	//Constructor de copiere
	Pom e3 = Pom(e2);					//Copiere a unui obiect cu parametri
	assert(strcmp(e3.getDenumire(), "mar") == 0);
	assert(e3.getNr() == 12);
	Pom e4 = Pom(e1);					//Copiere a unui obiect fara parametri
	assert(e4.getDenumire() == NULL);
	assert(e4.getNr() == 0);

	//testare set
	e3.setDenumire("par");
	assert(strcmp(e3.getDenumire(), "par") == 0);
	e3.setNr(13);
	assert(e3.getNr() == 13);

	//Operator de atribuire
	Pom e5;								//Copiere a unui obiect cu parametri
	e5 = e2;
	assert(strcmp(e5.getDenumire(), "mar") == 0);
	assert(e5.getNr() == 12);
	Pom e6;								//Copiere a unui obiect fara parametri
	e6 = e1;
	assert(e6.getDenumire() == NULL);
	assert(e6.getNr() == 0);

	cout << "Teste Clasa asociata OK! " << endl;

}

//clasa derivata

void testDerivata()
{
	//test constructor implicit
	Livada d1;
	assert(d1.getNrTipuriPomi() == 0);
	assert(d1.getid() == 0);
	//test set
	Livada d2;
	d2.setid(2);
	assert(d2.getid() == 2);
	Pom c1 = Pom(0, "mar");
	Pom c2 = Pom(12, "par");
	Pom c3 = Pom(16, "prun");
	d2.setNrTipuriPomi(3);
	d2.setV(c1, 0);
	d2.setV(c2, 1);
	d2.setV(c3, 2);
	assert(d2.getNrTipuriPomi() == 3);
	assert(strcmp(d2.getV(0).getDenumire(), "mar") == 0);
	assert(d2.getV(0).getNr() == 0);
	assert(strcmp(d2.getV(1).getDenumire(), "par") == 0);
	assert(d2.getV(1).getNr() == 12);
	assert(strcmp(d2.getV(2).getDenumire(), "prun") == 0);
	assert(d2.getV(2).getNr() == 16);

	//test constructor de copiere

	Livada d3 = Livada(d2);
	assert(d3.getid() == 2);
	assert(d3.getNrTipuriPomi() == 3);
	assert(strcmp(d3.getV(0).getDenumire(), "mar") == 0);
	assert(d3.getV(0).getNr() == 0);
	assert(strcmp(d3.getV(1).getDenumire(), "par") == 0);
	assert(d3.getV(1).getNr() == 12);
	assert(strcmp(d3.getV(2).getDenumire(), "prun") == 0);
	assert(d3.getV(2).getNr() == 16);

	//operator=
	Livada d4;
	d4 = d3;
	assert(d4.getid() == 2);
	assert(d4.getNrTipuriPomi() == 3);
	assert(strcmp(d4.getV(0).getDenumire(), "mar") == 0);
	assert(d4.getV(0).getNr() == 0);
	assert(strcmp(d4.getV(1).getDenumire(), "par") == 0);
	assert(d4.getV(1).getNr() == 12);
	assert(strcmp(d4.getV(2).getDenumire(), "prun") == 0);
	assert(d4.getV(2).getNr() == 16);

	//functia minim
	Livada m1 = Livada();
	m1.setid(1);
	m1.setNrTipuriPomi(2);
	m1.setV(Pom(1, "prun"), 0);
	m1.setV(Pom(2, "mar"), 1);
	Livada *Liv = new  Livada(m1);

	Livada m2 = Livada();
	m2.setid(2);
	m2.setNrTipuriPomi(2);
	m2.setV(Pom(4, "gutui"), 0);
	m2.setV(Pom(5, "piersic"), 1);
	m2.setV(Pom(2, "cais"), 1);
	Livada *Liv2 = new Livada(m2);

	Livada m3 = Livada();
	m3.setid(2);
	m3.setNrTipuriPomi(2);
	m3.setV(Pom(0, "gutui"), 0);
	m3.setV(Pom(5, "piersic"), 1);
	m3.setV(Pom(2, "cais"), 1);
	Livada *Liv3 = new Livada(m3);

	assert(Liv->min() == 1);
	assert(Liv2->min() == 2);
	assert(Liv3->min() == 0);

	//TODO: TEST COMPARARE
	
	Livada d5;
	d5.setid(2);
	Pom mm1 = Pom(1, "Gutui"), mm2 = Pom(5, "Mar");
	d5.setNrTipuriPomi(2);
	d5.setV(mm1, 0);
	d5.setV(mm2, 1);
	Livada *pd6 = new Livada(d5);
	assert(d5.comparare(pd6) == 0);			//primul este egal cu al doilea
	
	Livada d7;
	Pom m4 = Pom(1, "Par");
	d7.setNrTipuriPomi(1);
	d7.setV(m4, 0);
	Livada *pd7 = new Livada(d7);
	assert(d5.comparare(pd7) == 0);			//primul are mai multe Pome
	assert(d7.comparare(pd6) == 1);			//primul are mai putine Pome
	
	Livada d8;
	Pom m5 = Pom(1, "Visin");
	d8.setNrTipuriPomi(1);
	d8.setV(m5, 0);
	Livada *pd8 = new Livada(d8);
	assert(d8.comparare(pd7) == 0);	//egale		
	assert(d7.comparare(pd8) == 1);		//egale
	
	cout << "Test clasa derivata ok!" << endl;
	//2 livezi, nrtipuri pomi primul>aldoilea return 1, = dupa denumire, in rest e fals


	
}