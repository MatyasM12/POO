#include <iostream>
#include "Pom.h"
#include <string>
using namespace std;
//Preconditii:-
//Postconditii:Constructor Laca parametrii
Pom::Pom()
{
	denumire = "";
	nr = 0;
}
//--------------------------------------------------------------------------
//Preconditii:Un sir de caractere si un intreg
//Postconditii:Constructori cu parametrii
Pom::Pom(std::string name, int nrInd)
{
	denumire = name;
	nr = nrInd;
}
//--------------------------------------------------------------------------
//Preconditii:Un Pom 
//Postconditii:Copiaza Pomul
Pom::Pom(const Pom &m)
{
	denumire = m.denumire;
	nr = m.nr;
}
//--------------------------------------------------------------------------
//Preconditii:Un Pom
//Postconditii: Operator de copiere a unui Pom
Pom& Pom::operator=(const Pom &m)
{
	if (this != &m)
	{
		denumire = m.denumire;
		nr = m.nr;
	}

	return *this;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii:Destructor a unui Pom
Pom::~Pom()
{
	denumire = "";
	nr = 0;
}
//--------------------------------------------------------------------------
//Preconditii:culoare unui sir de caractere
//postconditii:schimba denumire unui Pom
void Pom::setdenumire(std::string name)
{
	denumire = name;
}
//--------------------------------------------------------------------------
//Preconditii: Un numar natural mai mare ca 0, reprezentand nr
//Postconditii: Schimba nr unui Pom
void Pom::setnr(int nrInd)
{
	nr = nrInd;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza denumire unui Pom
std::string const Pom::getdenumire()
{
	return denumire;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza nr unui Pom
int Pom::getnr()
{
	return nr;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de intrare si Pomul
//Postconditii:Returneaza canalul de intrare
istream& operator>>(istream& is, Pom &m)
{
	is >> m.denumire >> m.nr;
	return is;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de iesire si un Pom
//Postconditii:Canalul de iesire
ostream& operator<<(ostream& os, Pom &a)
{
	os << a.denumire << " " << a.nr << endl;
	return os;
}
//----------------------------------------------------------------------------
//Preconditii: Un Pom
//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
int Pom::operator ==(const Pom &m)
{
	if (denumire.compare(m.denumire) != 0)
		return 0;
	if (nr != m.nr)
		return 0;
	return 1;
}