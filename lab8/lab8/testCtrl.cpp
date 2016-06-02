#include "Repo.h"
#include "Controller.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include "testCtrl.h"
using namespace std;

void testC()
{
	Vector v1, v2;
	Livada p1 = Livada();
	p1.setid(1);
	p1.setNrTipuriPomi(5);
	p1.setV(Pom(10, "Par"), 0);
	p1.setV(Pom(5, "Prun"), 1);
	Livada *pp1 = new Livada(p1);

	Livada p2 = Livada();
	p2.setid(3);
	p2.setNrTipuriPomi(1);
	p2.setV(Pom(15, "Visin"), 0);
	Livada *pp2 = new Livada(p2);

	Livada p3 = Livada();
	p3.setid(2);
	p3.setNrTipuriPomi(3);
	p3.setV(Pom(10, "Nuc"), 0);
	p3.setV(Pom(5, "Gutui"), 1);
	p3.setV(Pom(12, "Cires"), 2);
	Livada *pp3 = new Livada(p3);
	v1.addElem(pp1);
	v1.addElem(pp2);
	v1.addElem(pp2);
	v1.addElem(pp3);

	//cauta
	Vector v6;
	v6 = cauta(3, v1);
	assert(v6.getSize() == 2);
	//cout << ((Livada*)v6.getElem(0))->getid();
	assert(((Livada*)v6.getElem(0))->getid() == 3);
	assert(((Livada*)v6.getElem(1))->getid() == 3);
	v6 = cauta(1, v1);
	assert(((Livada*)v6.getElem(0))->getid() == 1);

	Vector w2 = Vector();
	Livada d1 = Livada();
	d1.setid(1);
	d1.setNrTipuriPomi(2);
	d1.setV(Pom(1, "prun"), 0);
	d1.setV(Pom(2, "mar"), 1);
	Livada *Liv = new  Livada(d1);

	Livada d2 = Livada();
	d2.setid(2);
	d2.setNrTipuriPomi(2);
	d2.setV(Pom(4, "gutui"), 0);
	d2.setV(Pom(5, "piersic"), 1);
	Livada *Liv2 = new Livada(d2);

	Livada d3 = Livada();
	d3.setid(3);
	d3.setNrTipuriPomi(1);
	d3.setV(Pom(0, "cires"), 0);
	Livada *Liv3 = new Livada(d3);

	Livada d4 = Livada();
	d4.setid(4);
	d4.setNrTipuriPomi(1);
	d4.setV(Pom(3, "visin"), 0);
	Livada *Liv4 = new Livada(d4);

	w2.addElem(Liv);
	w2.addElem(Liv2);
	w2.addElem(Liv3);
	w2.addElem(Liv4);

	assert(((Livada*)w2.getElem(0))->getid() == 1);
	assert(((Livada*)w2.getElem(1))->getid() == 2);
	assert(((Livada*)w2.getElem(2))->getid() == 3);
	assert(((Livada*)w2.getElem(3))->getid() == 4);
	sortare(w2);
	assert(((Livada*)w2.getElem(0))->getid() == 3);
	assert(((Livada*)w2.getElem(1))->getid() == 1);
	assert(((Livada*)w2.getElem(2))->getid() == 4);
	assert(((Livada*)w2.getElem(3))->getid() == 2);

	//TODO: test sortare2
	Vector w3;
	w3.addElem(Liv);
	w3.addElem(Liv2);
	w3.addElem(Liv3);
	w3.addElem(Liv4);
	assert(((Livada*)w3.getElem(0))->getid() == 1);
	assert(((Livada*)w3.getElem(1))->getid() == 2);
	assert(((Livada*)w3.getElem(2))->getid() == 3);
	assert(((Livada*)w3.getElem(3))->getid() == 4);
	sortare2(w3);
	//crescator
	assert(((Livada*)w3.getElem(0))->getid() == 3);
	assert(((Livada*)w3.getElem(1))->getid() == 4);
	assert(((Livada*)w3.getElem(2))->getid() == 2);
	assert(((Livada*)w3.getElem(3))->getid() == 1);
	//descrescator
	/*
	assert(((Livada*)w3.getElem(0))->getid() == 1);
	assert(((Livada*)w3.getElem(1))->getid() == 2);
	assert(((Livada*)w3.getElem(2))->getid() == 4);
	assert(((Livada*)w3.getElem(3))->getid() == 3);
	*/

	cout << "Teste Controller OK!" << endl;
	cout << "----" << endl;
}