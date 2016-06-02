#include <assert.h>
#include "TestOras.h"
#include "Oras.h"
#include <iostream>
using namespace std;


void testOras()
{
	//testare constructor Orasa parametrii
	Oras a1 = Oras();
	assert(a1.getDenumire().compare("") == 0);
	assert(a1.getjudet().compare("") == 0);

	//constructor cu parametrii
	Oras a2 = Oras("Cluj-Napoca", "Cluj");
	assert(a2.getDenumire().compare("Cluj-Napoca") == 0);
	assert(a2.getjudet().compare("Cluj") == 0);

	//constructor de copiere
	Oras a3 = Oras(a2);
	assert(a3.getDenumire().compare("Cluj-Napoca") == 0);
	assert(a3.getjudet().compare("Cluj") == 0);



	//testare set
	a3.setDenumire("Bihor");
	assert(a3.getDenumire().compare("Bihor") == 0);
	a3.setjudet("Oradea");
	assert(a3.getjudet().compare("Oradea") == 0);


	//Operator atribuire
	Oras a5;
	a5 = a3;
	assert(a5.getDenumire().compare("Bihor") == 0);
	assert(a5.getjudet().compare("Oradea") == 0);

	//operator ==
	assert((a1 == a2) == 0);
	assert(a5 == a3);

	cout << "Test Oras OK!" << endl;
}
