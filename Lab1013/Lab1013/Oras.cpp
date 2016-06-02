#include <iostream>
#include "Oras.h"
#include <string>
using namespace std;
//Preconditii:-
//Postconditii:Constructor Orasa parametrii
Oras::Oras()
{
	denumire = "";
	judet = "";
}
//--------------------------------------------------------------------------
//Preconditii:Doi stringregi
//Postconditii:Constructori cu parametrii
Oras::Oras(string denumire_noua, string judet_noua)
{

	denumire = denumire_noua;
	judet = judet_noua;
}
//--------------------------------------------------------------------------
//Preconditii:Un Oras 
//Postconditii:Copiaza Orasul
Oras::Oras(const Oras &at)
{
	denumire = at.denumire;
	judet = at.judet;
}
//--------------------------------------------------------------------------
//Preconditii:Un Oras
//Postconditii: Operator de copiere a unui Oras
Oras& Oras::operator=(const Oras &p)
{
	if (this != &p)
	{
		denumire = p.denumire;
		judet = p.judet;
	}
	return *this;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii:Destructor a unui Oras
Oras::~Oras()
{}

//--------------------------------------------------------------------------
//Preconditii: Un numar natural mai mare ca 0, reprezentand denumire
//Postconditii: Schimba denumire unui Oras
void Oras::setDenumire(string denumire_noua)
{
	denumire = denumire_noua;
}
//--------------------------------------------------------------------------
//Preconditii: Un numar natural mai mare ca 0, reprezentand denumire
//Postconditii: Schimba judetul unui Oras
void Oras::setjudet(string value)
{
	judet = value;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza denumire unui Oras
string Oras::getDenumire()
{
	return denumire;
}
//--------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza judetul unui Oras
string Oras::getjudet()
{
	return judet;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de stringrare si Orasul
//Postconditii:Returneaza canalul de stringrare
istream& operator>>(istream& is, Oras &a)
{
	is >> a.denumire >> a.judet;
	return is;
}
//--------------------------------------------------------------------------
//Preconditii:Canalul de iesire si un Oras
//Postconditii:Canalul de iesire
ostream& operator<<(ostream& os, Oras &a)
{

	os << a.denumire << " " << a.judet << endl;
	return os;
}
//----------------------------------------------------------------------------
//Preconditii: Un Oras
//Postconditii: Returneaza 1 daca adevarat si 0 in caz contrar
int Oras::operator ==(const Oras &a)
{
	string ok;
	if (a.denumire.compare(denumire) != 0)
		return 0;
	if (a.judet.compare(judet) != 0)
		return 0;
	return 1;

}