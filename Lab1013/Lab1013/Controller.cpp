#include "Controller.h"

//Preconditii: Numele a doua fisiere
//Postconditii: Citeste din fisier
void Controller::citire_fisier(string fis1, string fis2)
{
	repoP.setFileName(fis1);
	repoL.setFileName(fis2);
	repoP.loadFromFile();
	repoL.loadFromFile();
}
//-------------------------------------------------------------------
//Preconditii: -
//Postconditii: Contrustor Orasa parametrii
Controller::Controller()
{
	repoP = Repo<Pom>();
	repoL = Repo<Oras>();
	repoPer = Repo<Pereche>();
}
//--------------------------------------------------------------------
//Preconditii: Doua fisiere
//Postconditii:Constructor cu parametrii
Controller::Controller(string fis1, string fis2)
{
	citire_fisier(fis1, fis2);
}
//----------------------------------------------------------------------------------------
//Preconditii: Un Pom
//Postconditii: Adaugarea Pomului
void Controller::addPom(Pom m)
{
	repoP.addElem(m);
	undoAction.push_back(new UndoAdd<Pom>(repoP));
}

void Controller::delPom()
{
	repoP.delElem();
}

void Controller::delOras()
{
	repoL.delElem();
}

void Controller::delTranz()
{
	repoPer.delElem();
}
//----------------------------------------------------------------------------------------
//Preconditii: O Oras
//Postconditii: Adaugarea Orasi
void Controller::addOras(Oras f)
{
	repoL.addElem(f);
	undoAction.push_back(new UndoAdd<Oras>(repoL));
}
//----------------------------------------------------------------------------------------
//Preconditii: Un numar intreg reprezentand pozitia unui Pom
//Postconditii: Returneaza Pomul de pe pozitia respectiva
Pom Controller::getPom(int poz)
{
	return repoP.getElem(poz);
}
//----------------------------------------------------------------------------------------
//Preconditii: Un numar intreg reprezentand pozitia unuei Orasmacii
//Postconditii: Returneaza Orasmacia de pe pozitia respectiva
Oras Controller::getOras(int poz)
{
	return repoL.getElem(poz);
}
//----------------------------------------------------------------------------------------
//Preconditii: Un numar intreg reprezentand pozitia unuei perechi
//Postconditii: Returneaza perechea de pe pozitia respectiva
Controller::Pereche Controller::getP(int poz)
{
	return repoPer.getElem(poz);
}
//----------------------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza repository cu toate Pomele
vector<Pom> Controller::getAllPom()
{
	return repoP.getAll();
}
//----------------------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza vector cu toate Pomele
vector<Oras> Controller::getAllOras()
{
	return repoL.getAll();
}
//---------------------------------------------------------------------
//Preconditii:-
//Postconditii:Returneaza vector cu toate perechiile
vector<Controller::Pereche> Controller::getAllPer()
{
	return repoPer.getAll();
}
//---------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza size-ul repozitory-ului de Pesti
int Controller::getSizeP()
{
	return repoP.getSize();
}
//-----------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza size-ul repozitory-ului de Orasuri
int Controller::getSizeL()
{
	return repoL.getSize();
}
//--------------------------------------------------------------------
//Preconditii:-
//Postconditii:  Returneaza size-ul repozitory-ului de perechi
int Controller::getSizePer()
{
	return repoPer.getSize();
}
//--------------------------------------------------------------------
//Preconditii:-
//Postconditii: Salveaza tot in fisier
void Controller::saveAll(string fis1, string fis2)
{

	repoP.saveInFile();
	repoL.saveInFile();
}
//--------------------------------------------------------------------
//Preconditii: 3 stringuri si un intreg
//Postconditii: Creaza o tranzactie
void Controller::addTranz(string n, int p, string den, string ad)
{
	int okP, okL;
	Pom m = Pom(n, p);
	Oras f = Oras(den, ad);
	okP = repoP.searchElem(m);
	okL = repoL.searchElem(f);
	if (okP == -1)
		throw("Acest Pom nu exista!");
	if (okL == -1)
		throw("Aceasta Oras nu exista!");
	Pereche pereche;
	pereche.Pom = m;
	pereche.Oras = f;
	repoPer.addElem(pereche);
	undoAction.push_back(new UndoTranz<Pereche>(repoPer));
}

void Controller::undo()
{
	if (undoAction.empty())
		throw("Nu mai exista operatii");
	else
	{
		UndoOper* act = undoAction.back();
		act->executeUndo();
		undoAction.pop_back();
		delete act;
	}

}