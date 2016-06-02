#include "TestRepo.h"
#include "Repo.h"
#include "Pom.h"
#include "Oras.h"
#include <assert.h>
#include <iostream>

void testrepoPom()
{
	//Test Repo Oras parametrii
	Repo<Pom, 0> r0 = Repo<Pom, 0>();
	assert(r0.getSize() == 0);

	//Test loadFromFile
	Repo<Pom, 10> r1;
	r1.setFileName("Pom.txt");
	r1.loadFromFile();
	assert(r1.getSize() == 4);
	assert(r1.getElem(0).getdenumire().compare("Mar") == 0);
	assert(r1.getElem(0).getnr() == 10);
	assert(r1.getElem(1).getdenumire().compare("Par") == 0);
	assert(r1.getElem(1).getnr() == 2);
	assert(r1.getElem(2).getdenumire().compare("Prun") == 0);
	assert(r1.getElem(2).getnr() == 16);
	assert(r1.getElem(3).getdenumire().compare("Visin") == 0);
	assert(r1.getElem(3).getnr() == 5);

	//Test constructor copiere
	Repo<Pom, 10> r2 = Repo<Pom, 10>(r1);
	assert(r2.getSize() == 4);
	assert(r2.getElem(0).getdenumire().compare("Mar") == 0);
	assert(r2.getElem(0).getnr() == 10);
	assert(r2.getElem(1).getdenumire().compare("Par") == 0);
	assert(r2.getElem(1).getnr() == 2);
	assert(r2.getElem(2).getdenumire().compare("Prun") == 0);
	assert(r2.getElem(2).getnr() == 16);
	assert(r2.getElem(3).getdenumire().compare("Visin") == 0);
	assert(r2.getElem(3).getnr() == 5);

	//Test addElem
	Pom m = Pom("Cires", 10);
	r1.addElem(m);
	assert(r1.getSize() == 5);
	assert(r1.getElem(4).getdenumire().compare("Cires") == 0);
	assert(r1.getElem(4).getnr() == 10);

	//Test searchElem
	assert(r1.searchElem(m) == 4);
	assert(r1.searchElem(Pom("", 0)) == -1);


	//Test pentru pozitie incorecta
	try
	{
		Pom m = r1.getElem(10);
		assert(false);
	}
	catch (...) {
		assert(true);
	}

	//Test GetALL
	std::vector<Pom> v;
	v = r1.getAll();
	assert(v[0].getdenumire().compare("Mar") == 0);
	assert(v[0].getnr() == 10);
	assert(v[1].getdenumire().compare("Par") == 0);
	assert(v[1].getnr() == 2);
	assert(v[2].getdenumire().compare("Prun") == 0);
	assert(v[2].getnr() == 16);
	assert(v[3].getdenumire().compare("Visin") == 0);
	assert(v[3].getnr() == 5);
	assert(v[4].getdenumire().compare("Cires") == 0);
	assert(v[4].getnr() == 10);

	//Test scriereFisier
	r2.saveInFile();
	Repo<Pom, 10> r3;
	r3.setFileName("sPom.txt");
	r3.loadFromFile();
	assert(r3.getSize() == 4);
	assert(r3.getElem(1).getdenumire().compare("Mar") == 0);
	assert(r3.getElem(1).getnr() == 10);
	assert(r3.getElem(0).getdenumire().compare("Par") == 0);
	assert(r3.getElem(0).getnr() == 2);
	assert(r3.getElem(2).getdenumire().compare("Prun") == 0);
	assert(r3.getElem(2).getnr() == 16);
	assert(r3.getElem(3).getdenumire().compare("Visin") == 0);
	assert(r3.getElem(3).getnr() == 5);


}
void testRepoIntreg()
{
	//Test Repo Oras parametrii
	Repo<int, 0> r0 = Repo<int, 0>();
	assert(r0.getSize() == 0);

	//Test loadFromFile
	Repo<int, 10> r1;
	r1.setFileName("Intreg.txt");
	r1.loadFromFile();
	assert(r1.getSize() == 5);
	assert(r1.getElem(0) == 5);
	assert(r1.getElem(1) == 6);
	assert(r1.getElem(2) == 7);
	assert(r1.getElem(3) == 8);
	assert(r1.getElem(4) == 9);


	//Test constructor copiere
	Repo<int, 10> r2 = Repo<int, 10>(r1);
	assert(r2.getSize() == 5);
	assert(r2.getElem(0) == 5);
	assert(r2.getElem(1) == 6);
	assert(r2.getElem(2) == 7);
	assert(r2.getElem(3) == 8);
	assert(r2.getElem(4) == 9);

	//Test addElem
	r1.addElem(7);
	assert(r1.getSize() == 6);
	assert(r1.getElem(5) == 7);

	//Test searchElem
	assert(r1.searchElem(5) == 0);
	assert(r1.searchElem(12) == -1);


	//Test pentru pozitie incorecta
	try
	{
		int m = r1.getElem(10);
		assert(false);
	}
	catch (...) {
		assert(true);
	}

	//Test GetALL
	std::vector<int> v;
	v = r1.getAll();
	assert(v[0] == 5);
	assert(v[1] == 6);
	assert(v[2] == 7);
	assert(v[3] == 8);
	assert(v[4] == 9);
	assert(v[5] == 7);


	//Test scriereFisier
	r2.saveInFile();
	Repo<int, 10> r3;
	r3.setFileName("Intreg.txt");
	r3.loadFromFile();
	assert(r3.getSize() == 5);
	assert(r3.getSize() == 5);
	assert(r3.getElem(0) == 5);
	assert(r3.getElem(1) == 6);
	assert(r3.getElem(2) == 7);
	assert(r3.getElem(3) == 8);
	assert(r3.getElem(4) == 9);


}

void testrepoOras()
{
	//Test Repo Oras parametrii
	Repo<Oras, 0> r0 = Repo<Oras, 0>();
	assert(r0.getSize() == 0);

	//Test loadFromFile
	Repo<Oras, 10> r1;
	r1.setFileName("Oras.txt");
	r1.loadFromFile();
	assert(r1.getSize() == 3);
	assert(r1.getElem(0).getDenumire().compare("Cluj-Napoca") == 0);
	assert(r1.getElem(0).getjudet().compare("Cluj") == 0);
	assert(r1.getElem(1).getDenumire().compare("Bihor") == 0);
	assert(r1.getElem(1).getjudet().compare("Oradea") == 0);
	assert(r1.getElem(2).getDenumire().compare("Hunedoara") == 0);
	assert(r1.getElem(2).getjudet().compare("Deva") == 0);

	//Test constructor copiere
	Repo<Oras, 10> r2 = Repo<Oras, 10>(r1);
	assert(r2.getSize() == 3);
	assert(r2.getElem(0).getDenumire().compare("Cluj-Napoca") == 0);
	assert(r2.getElem(0).getjudet().compare("Cluj") == 0);
	assert(r2.getElem(1).getDenumire().compare("Bihor") == 0);
	assert(r2.getElem(1).getjudet().compare("Oradea") == 0);
	assert(r2.getElem(2).getDenumire().compare("Hunedoara") == 0);
	assert(r2.getElem(2).getjudet().compare("Deva") == 0);

	//Test addElem
	Oras m = Oras("Baia-Mare", "Maramures");
	r1.addElem(m);
	assert(r1.getSize() == 4);
	assert(r1.getElem(3).getDenumire().compare("Baia-Mare") == 0);
	assert(r1.getElem(3).getjudet().compare("Maramures") == 0);

	//Test searchElem
	assert(r1.searchElem(m) == 3);
	assert(r1.searchElem(Oras("", "")) == -1);

	//Test pentru pozitie incorecta
	try
	{
		Oras m = r1.getElem(10);
		assert(false);
	}
	catch (...) {
		assert(true);
	}

	//Test GetALL
	std::vector<Oras> v;
	v = r1.getAll();
	assert(v[0].getDenumire().compare("Cluj-Napoca") == 0);
	assert(v[0].getjudet().compare("Cluj") == 0);
	assert(v[1].getDenumire().compare("Bihor") == 0);
	assert(v[1].getjudet().compare("Oradea") == 0);
	assert(v[2].getDenumire().compare("Hunedoara") == 0);
	assert(v[2].getjudet().compare("Deva") == 0);
	assert(v[3].getDenumire().compare("Baia-Mare") == 0);
	assert(v[3].getjudet().compare("Maramures") == 0);

	//Test scriereFisier
	r2.saveInFile();
	Repo<Oras, 10> r3;
	r3.setFileName("sOras.txt");
	r3.loadFromFile();
	assert(r3.getSize() == 3);
	assert(r3.getElem(1).getDenumire().compare("Cluj-Napoca") == 0);
	assert(r3.getElem(1).getjudet().compare("Cluj") == 0);
	assert(r3.getElem(0).getDenumire().compare("Bihor") == 0);
	assert(r3.getElem(0).getjudet().compare("Oradea") == 0);
	assert(r3.getElem(2).getDenumire().compare("Hunedoara") == 0);
	assert(r3.getElem(2).getjudet().compare("Deva") == 0);


	cout << "Test Repo OK!" << endl;

}