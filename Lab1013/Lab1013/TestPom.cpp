#include <assert.h>
#include "Pom.h"
#include "TestPom.h"
#include <string>
using namespace std;


void testPom()
{


	//testare constructor Laca parametrii
	Pom a1 = Pom();
	assert(a1.getdenumire().compare("") == 0);
	assert(a1.getnr() == 0);

	Pom a2 = Pom("Mar", 10);
	assert(a2.getdenumire().compare("Mar") == 0);
	assert(a2.getnr() == 10);


	//constructor de copiere
	Pom a3 = Pom(a2);
	assert(a3.getdenumire().compare("Mar") == 0);
	assert(a3.getnr() == 10);


	//testare set
	a3.setdenumire("Par");
	assert(a3.getdenumire().compare("Par") == 0);
	a3.setnr(20);
	assert(a3.getnr() == 20);

	//Operator atribuire
	Pom a5;
	a5 = a2;
	assert(a5.getdenumire().compare("Mar") == 0);
	assert(a5.getnr() == 10);

	//operator ==
	assert((a1 == a2) == 0);
	assert(a5 == a2);

	cout << "Test Pom OK!" << endl;
}
