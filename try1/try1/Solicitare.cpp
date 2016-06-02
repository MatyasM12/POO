#include <iostream>
#include "Solicitare.h"
#include <string>
using namespace std;
//Preconditii:-
//Postconditii:Constructor Laca parametrii
Solicitare::Solicitare()
{
	denumire = "";
	max = 0;
}
//--------------------------------------------------------------------------
//Preconditii:Un sir de caractere si un intreg
//Postconditii:Constructori cu parametrii
Solicitare::Solicitare(std::string name, int maxInd)
{
	denumire = name;
	max = maxInd;
}
//--------------------------------------------------------------------------
//Preconditii:Un Solicitare 
//Postconditii:Copiaza Solicitareul
Solicitare::Solicitare(const Solicitare &m)
{
	denumire = m.denumire;
	max = m.max;
}
//--------------------------------------------------------------------------
//Preconditii:Un Solicitare
//Postconditii: Operator de copiere a unui Solicitare
Solicitare& Solicitare::operator=(const Solicitare &m)
{
	if (this != &m)
	{
		denumire = m.denumire;
		max = m.max;
	}

	return *this;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii:Destructor a unui Solicitare
Solicitare::~Solicitare()
{
	denumire = "";
	max = 0;
}
//--------------------------------------------------------------------------
//Preconditii:culoare unui sir de caractere
//postconditii:schimba denumire unui Solicitare
void Solicitare::setdenumire(std::string name)
{
	denumire = name;
}
//--------------------------------------------------------------------------
//Preconditii: Un numar natural mai mare ca 0, reprezentand max
//Postconditii: Schimba max unui Solicitare
void Solicitare::setmax(int maxInd)
{
	max = maxInd;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza denumire unui Solicitare
std::string const Solicitare::getdenumire()
{
	return denumire;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza max unui Solicitare
int Solicitare::getmax()
{
	return max;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de intrare si Solicitareul
//Postconditii:Returneaza canalul de intrare
istream& operator>>(istream& is, Solicitare &m)
{
	is >> m.denumire >> m.max;
	return is;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de iesire si un Solicitare
//Postconditii:Canalul de iesire
ostream& operator<<(ostream& os, Solicitare &a)
{
	os << a.denumire << " " << a.max << endl;
	return os;
}
//----------------------------------------------------------------------------
//Preconditii: Un Solicitare
//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
int Solicitare::operator ==(const Solicitare &m)
{
	if (denumire.compare(m.denumire) != 0)
		return 0;
	if (max != m.max)
		return 0;
	return 1;
}