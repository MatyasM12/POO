#ifndef Pom_H
#define Pom_H
#include <iostream>
using namespace std;
class Pom {
private:
	std::string denumire;
	int nr;

public:
	//Preconditii:-
	//Postconditii:Constructor Laca parametrii
	Pom();

	//Preconditii:Un string si un intreg
	//Postconditii:Constructori cu parametrii
	Pom(std::string name, int nrInd);

	//Preconditii:Un Pom 
	//Postconditii:Copiaza Pomul
	Pom(const Pom &m);

	//Preconditii:Un Pom
	//Postconditii: Operator de copiere a unui Pom
	Pom& operator=(const Pom &m);

	//Preconditii:-
	//Postconditii:Destructor a unui Pom
	~Pom();

	//Preconditii:culoare unui sir de caractere
	//postconditii:schimba denumire unui Pom
	void setdenumire(std::string name);

	//Preconditii: Un numar natural mai mare ca 0, reprezentand nr
	//Postconditii: Schimba nr unui Pom
	void setnr(int nrInd);

	//Preconditii:-
	//Postconditii: Returneaza denumire unui Pom
	std::string const getdenumire();

	//Preconditii:-
	//Postconditii: Returneaza nr unui Pom
	int getnr();

	//IO operators
	//Preconditii:Canalul de intrare si Pomul
	//Postconditii:Returneaza canalul de intrare
	friend istream& operator>>(istream& is, Pom &m);

	//Preconditii:Canalul de iesire si un Pom
	//Postconditii:Canalul de iesire
	friend ostream& operator<<(ostream& os, Pom &m);

	//Preconditii: Un Pom
	//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
	int operator ==(const Pom &m);
};
#endif