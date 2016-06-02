#include <iostream>
#include "Ambulanta.h"
#include <string>
using namespace std;
//Preconditii:-
//Postconditii:Constructor Laca parametrii
Ambulanta::Ambulanta()
{
	denumire = "";
	nr = 0;
}
//--------------------------------------------------------------------------
//Preconditii:Un sir de caractere si un intreg
//Postconditii:Constructori cu parametrii
Ambulanta::Ambulanta(std::string name, int nrInd)
{
	denumire = name;
	nr = nrInd;
}
//--------------------------------------------------------------------------
//Preconditii:Un Ambulanta 
//Postconditii:Copiaza Ambulantaul
Ambulanta::Ambulanta(const Ambulanta &m)
{
	denumire = m.denumire;
	nr = m.nr;
}
//--------------------------------------------------------------------------
//Preconditii:Un Ambulanta
//Postconditii: Operator de copiere a unui Ambulanta
Ambulanta& Ambulanta::operator=(const Ambulanta &m)
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
//Postconditii:Destructor a unui Ambulanta
Ambulanta::~Ambulanta()
{
	denumire = "";
	nr = 0;
}
//--------------------------------------------------------------------------
//Preconditii:culoare unui sir de caractere
//postconditii:schimba denumire unui Ambulanta
void Ambulanta::setdenumire(std::string name)
{
	denumire = name;
}
//--------------------------------------------------------------------------
//Preconditii: Un numar natural mai mare ca 0, reprezentand nr
//Postconditii: Schimba nr unui Ambulanta
void Ambulanta::setnr(int nrInd)
{
	nr = nrInd;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza denumire unui Ambulanta
std::string const Ambulanta::getdenumire()
{
	return denumire;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza nr unui Ambulanta
int Ambulanta::getnr()
{
	return nr;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de intrare si Ambulantaul
//Postconditii:Returneaza canalul de intrare
istream& operator>>(istream& is, Ambulanta &m)
{
	is >> m.denumire >> m.nr;
	return is;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de iesire si un Ambulanta
//Postconditii:Canalul de iesire
ostream& operator<<(ostream& os, Ambulanta &a)
{
	os << a.denumire << " " << a.nr << endl;
	return os;
}
//----------------------------------------------------------------------------
//Preconditii: Un Ambulanta
//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
int Ambulanta::operator ==(const Ambulanta &m)
{
	if (denumire.compare(m.denumire) != 0)
		return 0;
	if (nr != m.nr)
		return 0;
	return 1;
}