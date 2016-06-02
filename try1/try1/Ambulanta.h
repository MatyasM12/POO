#ifndef Ambulanta_H
#define Ambulanta_H
#include <iostream>
using namespace std;
class Ambulanta {
private:
	std::string denumire;
	int nr;

public:
	//Preconditii:-
	//Postconditii:Constructor Laca parametrii
	Ambulanta();

	//Preconditii:Un string si un intreg
	//Postconditii:Constructori cu parametrii
	Ambulanta(std::string name, int nrInd);

	//Preconditii:Un Ambulanta 
	//Postconditii:Copiaza Ambulantaul
	Ambulanta(const Ambulanta &m);

	//Preconditii:Un Ambulanta
	//Postconditii: Operator de copiere a unui Ambulanta
	Ambulanta& operator=(const Ambulanta &m);

	//Preconditii:-
	//Postconditii:Destructor a unui Ambulanta
	~Ambulanta();

	//Preconditii:culoare unui sir de caractere
	//postconditii:schimba denumire unui Ambulanta
	void setdenumire(std::string name);

	//Preconditii: Un numar natural mai mare ca 0, reprezentand nr
	//Postconditii: Schimba nr unui Ambulanta
	void setnr(int nrInd);

	//Preconditii:-
	//Postconditii: Returneaza denumire unui Ambulanta
	std::string const getdenumire();

	//Preconditii:-
	//Postconditii: Returneaza nr unui Ambulanta
	int getnr();

	//IO operators
	//Preconditii:Canalul de intrare si Ambulantaul
	//Postconditii:Returneaza canalul de intrare
	friend istream& operator>>(istream& is, Ambulanta &m);

	//Preconditii:Canalul de iesire si un Ambulanta
	//Postconditii:Canalul de iesire
	friend ostream& operator<<(ostream& os, Ambulanta &m);

	//Preconditii: Un Ambulanta
	//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
	int operator ==(const Ambulanta &m);
};
#endif