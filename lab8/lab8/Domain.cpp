#include"Repo.h"
#include "Domain.h"
#include <string.h>
#include <iostream>
using namespace std;
/*
//clasa de baza
//--------------------------------------------------------------

//Preconditii:-
//Postconditii:Constructor fara parametri
Ferma::Ferma()
{
	id = 0;

}
//---------------------------------------------------------------------------
//Preconditii:Adresa unui sir de caractere(reprezentand n-denumire)si un  intreg v-nrIndivizi
//Postconditii:Constructori cu parametri

Ferma::Ferma(int i)
{
	id = i;
}
//---------------------------------------------------------------------------
//Preconditii: Ferma curent
//Postconditii:Copiaza Ferma
Ferma::Ferma(const Ferma &b)
{
	id = b.id;
}
//---------------------------------------------------------------------------
//Preconditii:-
//Postconditii:destructorul unui obiect
Ferma::~Ferma()
{
	id = 0;
}

//---------------------------------------------------------------------------
//Preconditii:un nustiuca intreg i-id Ferma curenta
//Postconditii:schimba id
void Ferma::setid(int i)
{
	id = i;
}
//---------------------------------------------------------------------------
//Preconditii:obiectul curent
//Postconditii:returneaza id Ferma curent
int Ferma::getid()
{
	return id;
}
//---------------------------------------------------------------------------
//Preconditii:obiectul curent
//Postconditii:operatorul de copiere a unei Ferma
Ferma& Ferma::operator=(const Ferma &c)
{
	id = c.id;
	return *this;
}

Ferma * Ferma::clone()
{
	Ferma* newFerma = new Ferma();
	newFerma->setid(id);
	return newFerma;
}

void Ferma::print()
{
	cout << "id-ul este: " << id << endl;
}
*/
//----clasa asociata-----
Pom::Pom()
{
	denumire = NULL;
	nr = 0;
}

Pom::Pom(int v, char* n)
{
	if (n == NULL)
		denumire = NULL;
	else
	{
		if (strcmp(n, "") == 0)
			denumire = new char[2];
		else
			denumire = new char[strlen(n) + 1];
		strcpy_s(denumire, strlen(n) + 1, n);
	}
	nr = v;
}

Pom::~Pom()
{
	if (denumire != NULL)
	{
		delete[] denumire;
		denumire = NULL;
	}
	nr = 0;

}

Pom::Pom(const Pom &c)
{
	if (c.denumire == NULL)
		denumire = NULL;
	else
	{
		if (strcmp(c.denumire, "") == 0)
			denumire = new char[2];
		else
			denumire = new char[strlen(c.denumire) + 1];
		strcpy_s(denumire, strlen(c.denumire) + 1, c.denumire);

	}
	nr = c.nr;
}

void Pom::setNr(int v)
{
	nr = v;
}

void Pom::setDenumire(char *n)
{
	if (n == NULL)
		denumire = NULL;
	else
	{
		if (strcmp(n, "") == 0)
			denumire = new char[2];
		else
			denumire = new char[strlen(n) + 1];
		strcpy_s(denumire, strlen(n) + 1, n);
	}
}

char* Pom::getDenumire()
{
	return denumire;
}

int Pom::getNr()
{
	return nr;
}

Pom & Pom::operator=(const Pom &c)
{
	if (c.denumire == NULL)
		denumire = NULL;
	else
	{
		delete[] denumire;
		if (strcmp(c.denumire, "") == 0)
			denumire = new char[2];
		else
			denumire = new char[strlen(c.denumire) + 1];
		strcpy_s(denumire, strlen(c.denumire) + 1, c.denumire);
	}
	nr = c.nr;
	return *this;
}

int Pom::operator!=(const Pom &e)
{
	if (nr != e.nr)
		return 1;
	if (strcmp(denumire, e.denumire) != 0)
		return 1;

	return 0;
}

//-----clasa derivata-----

Livada::Livada() :Ferma()
{
	nrTipuriPomi = 0;
	id = 0;
	v = new Pom[MAX_ELEM];
}
/*
Livada::Livada(int numar, Pom * p, int id)
{
	this->id = id;
	nrTipuriPomi = numar;
	if (v != NULL)
	{
		delete[]v;
		v = NULL;
	}
	v = new Pom[numar];
	for (int i = 1; i < numar; i++)
		v[i] = p[i];
}
*/
Livada::Livada(const Livada &c)
{
	nrTipuriPomi = c.nrTipuriPomi;
	id = c.id;
	v = new Pom[nrTipuriPomi];
	for (int i = 0; i < nrTipuriPomi; i++)
	{
		v[i] = c.v[i];
	}
}

Livada::~Livada()
{
	nrTipuriPomi = 0;
	id = 0;
	if (v != NULL)
	{
		delete[]v;
		v = NULL;
	}
}

void Livada::setNrTipuriPomi(int numar)
{
	nrTipuriPomi = numar;
}

void Livada::setV(Pom p, int poz)
{
	v[poz] = p;
}

int Livada::getNrTipuriPomi()
{
	return nrTipuriPomi;
}

Pom Livada::getV(int poz)
{
	return v[poz];
}

int Livada::comparare(Ferma*p)
{
	Livada*j = (Livada*)p;
	if (nrTipuriPomi < j->nrTipuriPomi)
		return 1;
	else
	{
		if (nrTipuriPomi>j->nrTipuriPomi)
			return 0;
		else
		{
			if (strcmp(v[0].denumire, j->v[0].denumire) == -1)//<
				return 1;
			else
				return 0;
		}
	}

}



Livada & Livada::operator=(const Livada &d)
{
	id = d.id;
	nrTipuriPomi = d.nrTipuriPomi;
	v = new Pom[nrTipuriPomi];
	for (int i = 0; i < nrTipuriPomi; i++)
	{
		v[i] = d.v[i];

	}
	return *this;
}

int Livada::operator==(const Livada & e)
{
	if (nrTipuriPomi != e.nrTipuriPomi || id != e.id)
		return 0;
	for (int i = 0; i < nrTipuriPomi; i++)
		if (v[i] != e.v[i])
			return 0;
	return 1;
}

void Livada::print()
{
	cout << "Id: " << id << endl;
	cout << "Numar pomi: " << nrTipuriPomi << endl;
	cout << "Pomi, numar pomi: " << endl;
	for (int i = 0; i < nrTipuriPomi; i++) {
		cout << v[i].getDenumire() << "," << v[i].getNr()<<endl;
	}
}

Livada * Livada::clone()
{
	Livada* newLivada = new Livada();
	newLivada->setid(id);
	newLivada->setNrTipuriPomi(nrTipuriPomi);
	for (int i = 0; i < nrTipuriPomi; i++)
		newLivada->setV(v[i], i);
	return newLivada;
}

int Livada::min()
{
	int i, min = 5000;
	for (i = 0; i < nrTipuriPomi; i++)
		if (min>v[i].getNr())
			min = v[i].getNr();
	return min;
}

int Livada::getid()
{
	return id;
}
void Livada::setid(int i)
{
	id = i;
}
//Operator de extractie
//istream & operator >>(istream &is, Livada&c)
//{

//	c.denumire = new char[10];
	//is >> c.nrTipuriPomi >> c.;
	//return is;
//}
/*
//Operator de insertie
ostream & operator << (ostream&os, Livada&c)
{
	// write out individual members of c with a space between each one
	os << c.banca << " " << c.nume << " " << c.suma << " " << c.durata << "\n";
	return os;
}*/
