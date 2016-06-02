#include "Repo.h"
#include "Controller.h"
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

void testR()
{//constructor implicit
	Vector q1 = Vector();
	assert(q1.getSize() == 0);
	
 //constructor de copiere
	Vector v1, v2;

	/*Pom *c1 = new Pom[3];
	c1[0] = Pom(0, "par");
	c1[1] = Pom(12, "mar");
	c1[2] = Pom(16, "prun");
	*/
	Livada p1 =  Livada();
	p1.setid(1);
	p1.setNrTipuriPomi(5);
	p1.setV(Pom(10,"Par"), 0);
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
	//std::cout << ((Livada*)v1.getElem(3))->getid() << endl;
	assert(((Livada*)v1.getElem(3))->getid() == 2);
	assert(((Livada*)v1.getElem(2))->getid() == 3);
	assert(((Livada*)v1.getElem(1))->getid() == 3);
	assert(((Livada*)v1.getElem(0))->getid() == 1);
	assert(v1.getSize() == 4);
	//copiere
	Vector v3 = Vector(v1);
	assert(((Livada*)v3.getElem(3))->getid() == 2);
	assert(((Livada*)v3.getElem(2))->getid() == 3);
	assert(((Livada*)v3.getElem(1))->getid() == 3);
	assert(((Livada*)v3.getElem(0))->getid() == 1);
	assert(v1.getSize() == 4);

	//atribuire
	Vector v4;
	v4 = v1;
	assert(((Livada*)v4.getElem(0))->getid() == 1);
	assert(((Livada*)v4.getElem(1))->getid() == 3);
	assert(((Livada*)v4.getElem(2))->getid() == 3);
	assert(((Livada*)v4.getElem(3))->getid() == 2);
	assert(v4.getSize() == 4);

	//selectid
	Vector aux;
	aux = v4.selectid(3);
	assert(((Livada*)aux.getElem(0))->getid() == 3);



	cout << "Teste Repository ok!" << endl;
	//system("pause");
}