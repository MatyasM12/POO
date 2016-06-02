#ifndef Solicitare_H
#define Solicitare_H
#include <iostream>
using namespace std;
class Solicitare {
private:
	std::string denumire;
	int max;

public:
	//Preconditii:-
	//Postconditii:Constructor Laca parametrii
	Solicitare();

	//Preconditii:Un string si un intreg
	//Postconditii:Constructori cu parametrii
	Solicitare(std::string name, int maxInd);

	//Preconditii:Un Solicitare 
	//Postconditii:Copiaza Solicitareul
	Solicitare(const Solicitare &m);

	//Preconditii:Un Solicitare
	//Postconditii: Operator de copiere a unui Solicitare
	Solicitare& operator=(const Solicitare &m);

	//Preconditii:-
	//Postconditii:Destructor a unui Solicitare
	~Solicitare();

	//Preconditii:culoare unui sir de caractere
	//postconditii:schimba denumire unui Solicitare
	void setdenumire(std::string name);

	//Preconditii: Un numar natural mai mare ca 0, reprezentand max
	//Postconditii: Schimba max unui Solicitare
	void setmax(int maxInd);

	//Preconditii:-
	//Postconditii: Returneaza denumire unui Solicitare
	std::string const getdenumire();

	//Preconditii:-
	//Postconditii: Returneaza max unui Solicitare
	int getmax();

	//IO operators
	//Preconditii:Canalul de intrare si Solicitareul
	//Postconditii:Returneaza canalul de intrare
	friend istream& operator>>(istream& is, Solicitare &m);

	//Preconditii:Canalul de iesire si un Solicitare
	//Postconditii:Canalul de iesire
	friend ostream& operator<<(ostream& os, Solicitare &m);

	//Preconditii: Un Solicitare
	//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
	int operator ==(const Solicitare &m);
};
#endif