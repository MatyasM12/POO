#ifndef Oras_H
#define Oras_H
#include <iostream>
using namespace std;
class Oras {
private:
	string denumire;
	string judet;
public:
	//Preconditii:-
	//Postconditii:Constructor Orasa parametrii
	Oras();

	//Preconditii:Doua siruri de caractere
	//Postconditii:Constructori cu parametrii
	Oras(string denumire, string judet);

	//Preconditii:Un Oras 
	//Postconditii:Copiaza Orasul
	Oras(const Oras &f);

	//Preconditii:Un Oras
	//Postconditii: Operator de copiere a unui Oras
	Oras& operator=(const Oras &p);

	//Preconditii:-
	//Postconditii:Destructor a unui Oras
	~Oras();

	//Preconditii: Un numar natural mai mare ca 0, reprezentand denumire
	//Postconditii: Schimba denumire unui Oras
	void setDenumire(string denumire_noua);

	//Preconditii: Un numar natural mai mare ca 0, reprezentand denumire
	//Postconditii: Schimba judetul unui Oras
	void Oras::setjudet(string judet_noua);

	//Preconditii:-
	//Postconditii: Returneaza denumire unui Oras
	string getDenumire();

	//Preconditii:-
	//Postconditii: Returneaza judetul unui Oras
	string getjudet();

	//IO operators
	//Preconditii:Canalul de intrare si Orasul
	//Postconditii:Returneaza canalul de intrare
	friend istream& operator>>(istream& is, Oras &f);

	//Preconditii:Canalul de iesire si un Oras
	//Postconditii:Canalul de iesire
	friend ostream& operator<<(ostream& os, Oras &f);

	//Preconditii: Un Oras
	//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
	int operator ==(const Oras &f);
};

#endif