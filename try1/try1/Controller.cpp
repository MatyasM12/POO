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
//Postconditii: Contrustor Solicitarea parametrii
Controller::Controller()
{
	repoP = Repo<Ambulanta>();
	repoL = Repo<Solicitare>();
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
//Preconditii: Un Ambulanta
//Postconditii: Adaugarea Ambulantaului
void Controller::addAmbulanta(Ambulanta m)
{
	repoP.addElem(m);
	//undoAction.push_back(new UndoAdd<Ambulanta>(repoP));
}

void Controller::addToate(Ambulanta m, Solicitare s)
{
	repoP.addElem(m);
	repoL.addElem(s);
}

void Controller::delAmbulanta()
{
	repoP.delElem();
}

void Controller::delSolicitare()
{
	repoL.delElem();
}

void Controller::delTranz()
{
	repoPer.delElem();
}
//----------------------------------------------------------------------------------------
//Preconditii: O Solicitare
//Postconditii: Adaugarea Solicitarei
void Controller::addSolicitare(Solicitare f)
{
	repoL.addElem(f);
	//undoAction.push_back(new UndoAdd<Solicitare>(repoL));
}
//----------------------------------------------------------------------------------------
//Preconditii: Un numar intreg reprezentand pozitia unui Ambulanta
//Postconditii: Returneaza Ambulantaul de pe pozitia respectiva
Ambulanta Controller::getAmbulanta(int poz)
{
	return repoP.getElem(poz);
}
//----------------------------------------------------------------------------------------
//Preconditii: Un numar intreg reprezentand pozitia unuei Solicitaremacii
//Postconditii: Returneaza Solicitaremacia de pe pozitia respectiva
Solicitare Controller::getSolicitare(int poz)
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
//Postconditii: Returneaza repository cu toate Ambulantaele
vector<Ambulanta> Controller::getAllAmbulanta()
{
	return repoP.getAll();
}
//----------------------------------------------------------------------------------------
//Preconditii:-
//Postconditii: Returneaza vector cu toate Ambulantaele
vector<Solicitare> Controller::getAllSolicitare()
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
//Postconditii: Returneaza size-ul repozitory-ului de Solicitareuri
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
/*
void Controller::addTranz(string n, int p, string den, int ad)
{
	int okP, okL;
	Ambulanta m = Ambulanta(n, p);
	Solicitare f = Solicitare(den, ad);
	okP = repoP.searchElem(m);
	okL = repoL.searchElem(f);
	if (okP == -1)
		throw("Acest Ambulanta nu exista!");
	if (okL == -1)
		throw("Aceasta Solicitare nu exista!");
	Pereche pereche;
	pereche.Ambulanta = m;
	pereche.Solicitare = f;
	repoPer.addElem(pereche);
	undoAction.push_back(new UndoTranz<Pereche>(repoPer));
}
*/
/*
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

}*/