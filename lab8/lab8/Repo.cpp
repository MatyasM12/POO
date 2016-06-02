#include <iostream>
#include "Repo.h"
#include "Domain.h"
#include <string.h>
#include <fstream>
using namespace std;


typedef Ferma*pd;

void Vector::realloc()
{
	pd*aux = new pd[2 * capacitate];
	for (int i = 0; i < size; i++)
		aux[i] = elem[i];
	delete[]elem;
	elem = aux;
	capacitate = capacitate * 2;
}
//prec:
//post:constr implicit

Vector::Vector()
{
	capacitate = 10;
	size = 0;
	elem = new pd[capacitate];

}
//prec:ob curent de tip vector
//post:constr de copiere
Vector::Vector(const Vector&v)
{
	size = v.size;
	elem = new pd[size];
	for (int i = 0; i < size; i++)
		elem[i] = v.elem[i];
}
//prec:-
//post:destructor
Vector::~Vector()
{
	if (elem != NULL)
	{
		delete[]elem;
		elem = NULL;
	}
	size = 0;
}

//prec:un ob de tip vector
//post:op de atribuire
Vector&Vector::operator=(const Vector&v)
{
	if (elem != NULL)
	{
		delete[] elem;
		elem = NULL;
	}
	size = v.size;

	elem = new pd[size];
	for (int i = 0; i < size; i++)
		elem[i] = v.elem[i];
	return *this;

}
//prec:-
//post:returneaza un intreg
int Vector::getSize()
{
	return size;
}

//prec:un nr intreg
//post:modif un nr intreg
void Vector::setSize(int s)
{
	size = s;
}

//prec:pos-nr natural
//post:returneaza elementul de pe pozitia pos
Ferma*Vector::getElem(int pos)
{
	return elem[pos];
}

void Vector::setElem(Ferma * f, int j)
{
	elem[j] = f->clone();
}

//prec:adresa unui ob de tip derivata
//post:-
void Vector::addElem(Ferma*d)
{
	if (size == capacitate)
		realloc();
	elem[size++] = d->clone();
}

//Preconditii: Numele unui fisier
//Postconditii:-
void Vector::citireFisier(char* numeFisier)
{
	int id, valoare, nrMed, s;
	char denumire[30];
	/*ofstream x("x.txt");
	x.close();*/
	ifstream f("Livada.txt");
	f >> s;
	elem = new pd[s];
	for (int i = 0; i < s; i++)
	{
		f >> id;
		f >> nrMed;
		Livada p;
		p.setid(id);
		p.setNrTipuriPomi(nrMed);
		for (int j = 0; j < nrMed; j++)
		{
			f >> denumire;
			f >> valoare;
			p.setV(Pom(valoare, denumire), j);
		}
		Livada *pp = new Livada(p);
		addElem(pp);
	}
}
Vector Vector::selectid(int n)
{
	Vector aux;
	for (int i = 0; i < size; i++)
		if (((Livada*)elem[i])->getid() == n)
			aux.addElem(elem[i]);
	return aux;

}
void Vector::print()
{
	cout << "Vectorul are " << size << " elemente, care sunt:" << endl;
	for (int i = 0; i < size; i++)
	{
		elem[i]->print();
		cout << endl;
	}
}