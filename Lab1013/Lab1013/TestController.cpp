#include "Controller.h"
#include <assert.h>
void testController()
{
	//test constructor Oras parametrii
	Controller c1 = Controller();
	assert(c1.getSizeP() == 0);
	assert(c1.getSizeL() == 0);
	assert(c1.getSizePer() == 0);

	//test constructor cu parametrii
	Controller c2 = Controller("Pom.txt", "Oras.txt");
	assert(c2.getSizeP() == 4);
	assert(c2.getSizeL() == 3);
	assert(c2.getSizePer() == 0);
	assert(c2.getPom(0).getdenumire().compare("Mar") == 0);
	assert(c2.getPom(0).getnr() == 10);
	assert(c2.getPom(1).getdenumire().compare("Par") == 0);
	assert(c2.getPom(1).getnr() == 2);
	assert(c2.getPom(2).getdenumire().compare("Prun") == 0);
	assert(c2.getPom(2).getnr() == 16);
	assert(c2.getPom(3).getdenumire().compare("Visin") == 0);
	assert(c2.getPom(3).getnr() == 5);
	assert(c2.getOras(0).getDenumire().compare("Cluj-Napoca") == 0);
	assert(c2.getOras(0).getjudet().compare("Cluj") == 0);
	assert(c2.getOras(1).getDenumire().compare("Bihor") == 0);
	assert(c2.getOras(1).getjudet().compare("Oradea") == 0);
	assert(c2.getOras(2).getDenumire().compare("Hunedoara") == 0);
	assert(c2.getOras(2).getjudet().compare("Deva") == 0);

	//test adaugare Pom
	Pom m = Pom("Gutui", 12);
	c2.addPom(m);
	assert(c2.getSizeP() == 5);
	assert(c2.getPom(4).getdenumire().compare("Gutui") == 0);
	assert(c2.getPom(4).getnr() == 12);

	//test adaugare Oras
	Oras f = Oras("Salaj", "Zalau");
	c2.addOras(f);
	assert(c2.getSizeL() == 4);
	assert(c2.getOras(3).getDenumire().compare("Salaj") == 0);
	assert(c2.getOras(3).getjudet().compare("Zalau") == 0);

	//test getAllPom
	vector<Pom> vM = c2.getAllPom();
	assert(vM.size() == 5);
	assert(vM[4].getdenumire().compare("Gutui") == 0);
	assert(vM[4].getnr() == 12);

	//test getAllOras
	vector<Oras> vF = c2.getAllOras();
	assert(vF.size() == 4);
	assert(vF[3].getDenumire().compare("Salaj") == 0);
	assert(vF[3].getjudet().compare("Zalau") == 0);


	//test saveAll
	Controller c3 = Controller("Pom.txt", "Oras.txt");
	c3.saveAll("Pom.txt", "Oras.txt");
	Controller c4 = Controller("Pom.txt", "Oras.txt");
	assert(c4.getSizeP() == 4);
	assert(c4.getSizeL() == 3);
	assert(c4.getPom(0).getdenumire().compare("Mar") == 0);
	assert(c4.getPom(0).getnr() == 10);
	assert(c4.getPom(1).getdenumire().compare("Par") == 0);
	assert(c4.getPom(1).getnr() == 2);
	assert(c4.getPom(2).getdenumire().compare("Prun") == 0);
	assert(c4.getPom(2).getnr() == 16);
	assert(c4.getPom(3).getdenumire().compare("Visin") == 0);
	assert(c4.getPom(3).getnr() == 5);
	assert(c4.getOras(0).getDenumire().compare("Cluj-Napoca") == 0);
	assert(c4.getOras(0).getjudet().compare("Cluj") == 0);
	assert(c4.getOras(1).getDenumire().compare("Bihor") == 0);
	assert(c4.getOras(1).getjudet().compare("Oradea") == 0);
	assert(c4.getOras(2).getDenumire().compare("Hunedoara") == 0);
	assert(c4.getOras(2).getjudet().compare("Deva") == 0);

	//test tranzactie
	c3.addTranz("Mar", 10, "Cluj-Napoca", "Cluj");		//adaug o tranzactie in care exista si Pomul si Orasul
	assert(c3.getSizePer() == 1);
	Controller::Pereche p = c3.getP(0);
	assert(p.Pom.getdenumire().compare("Mar") == 0);
	assert(p.Pom.getnr() == 10);
	assert(p.Oras.getDenumire().compare("Cluj-Napoca") == 0);
	assert(p.Oras.getjudet().compare("Cluj") == 0);
	try
	{
		c3.addTranz("Calem", 11, "Cluj-Napoca", "Cluj");			//adaug o tranzactie in care nu exista Pom
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
	try
	{
		c3.addTranz("Mar", 10, "Cat", "Cluj");			//adaug o tranzactie in care nu exista Orasul
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}

	//test GetallPer
	vector<Controller::Pereche> vP = c3.getAllPer();
	assert(vP.size() == 1);
	assert(vP[0].Pom.getdenumire().compare("Mar") == 0);
	assert(vP[0].Pom.getnr() == 10);
	assert(vP[0].Oras.getDenumire().compare("Cluj-Napoca") == 0);
	assert(vP[0].Oras.getjudet().compare("Cluj") == 0);

	cout << "Test Controller ok!" << endl;
}