#ifndef VECTOR_H
#define VECTOR_H
#include "Domain.h"

class Vector {
private:
	int size, capacitate;
	Ferma**elem; //vector de adrese

	void realloc();
public:	
	//prec:
	//post:constr fara somnm:
	Vector();

	//prec:obiect curent de tip vector
	//post:constructor de copiere
	Vector(const Vector &v);

	//prec:-
	//post:destructor
	~Vector();

	//prec:un ob de tip vector
	//post:op de atribuire
	Vector&operator=(const Vector&v);

	//prec:-
	//post:returneaza un intreg
	int getSize();

	//prec:un nr intreg
	//post:modif un nr intreg
	void setSize(int s);

	//prec:o pozitie
	//post:un obiect de tip FermaPiscicola
	Ferma* getElem(int pos);

	//Prec: Adresa si un intreg
	//Postc:-
	void setElem(Ferma *f, int j);

	//prec:adresa unui ob de tip derivata
	//post:-
	void addElem(Ferma*d);

	void citireFisier(char* numeFisier);
	//Preconditii:Un obiect 
	//Postconditii: Afiseaza obiectul
	void print();
	Vector selectid(int n);
};
#endif //VECTOR_H