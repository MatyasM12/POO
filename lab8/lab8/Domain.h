#include <iostream>
using namespace std;
//clasa de baza


#ifndef Ferma_H
#define Ferma_H
class Ferma {
	/*
protected:
	int id;
public:
	//Preconditii:-
	//Postconditii:Constructor fara parametri
	Ferma();
	//Preconditii:Adresa unui sir de caractere(reprezentand n-denumire)si un  intreg v-nrIndivizi
	//Postconditii:Constructori cu parametri
	Ferma(int);
	//Preconditii: obiectul curent
	//Postconditii:Copiaza obiectul
	Ferma(const Ferma &);
	//Preconditii:-
	//Postconditii:destructorul unei Ferma
	~Ferma();
	//Preconditii:un numar natural i-idul Fermei curente
	//Postconditii:schimba id-ul
	void setid(int i);
	int getid();
	//Preconditii:obiectul curent
	//Postconditii:operatorul de copiere pentru o Ferma
	Ferma& operator=(const Ferma &);
	//Prec:-
	//Postc: adresa
	*/
public:
	virtual Ferma* clone() = 0;
	//Prec:-
	//Postc:Afiseaza obiectul
	virtual void print() = 0;
	//+functie noua pentru sortare
	virtual int min() { return 0; };
	virtual int comparare(Ferma*) = 0;

};
#endif

//clasa asociata
#ifndef POM_H
#define POM_H
class Pom {
public:
	int nr;
	char *denumire;

public:
	Pom();
	Pom(int, char*);
	Pom(const Pom &c);
	~Pom();
	void setNr(int);
	void setDenumire(char *);
	char *getDenumire();
	int getNr();
	Pom& operator = (const Pom&);
	int operator !=(const Pom&);
	int comparare(Ferma*);
	//Preconditii:un numar natural i-idul Fermei curente
	//Postconditii:schimba id-ul

};
#endif // POM_H

//clasa derivata
#ifndef LIVADA_H
#define LIVADA_H
int const MAX_ELEM = 100;
class Livada :public Ferma {
private:
	int nrTipuriPomi;
	int id;
	Pom *v;
public:
	Livada();
	//Livada(int, Pom*, int id = 1);
	Livada(const Livada&);
	~Livada();
	void setNrTipuriPomi(int);
	void setV(Pom, int);
	int getNrTipuriPomi();
	Pom getV(int poz);
	Livada &operator =(const Livada&d);
	int operator ==(const Livada &e);
	//Prec: -
	//Postc: afiseaza livada
	void print();
	//Prec:-
	//Postc: adresa
	Livada* clone();
	//friend istream& operator>>(istream &is, Livada&c);
	int comparare(Ferma*p);
	int min();
	void setid(int i);
	int getid();
};
#endif // LIVADA_H
//clasa de baza, clasa derivata, clasa componenta, dupa atributul din clasa de baza
//