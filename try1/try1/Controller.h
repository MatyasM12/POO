#include "Repo.h"
#include "Ambulanta.h"
#include "Solicitare.h"
//#include "Undo.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
public:
	class Pereche
	{
	public:
		Ambulanta Ambulanta;
		Solicitare Solicitare;
	};
private:
	Repo<Ambulanta> repoP;
	Repo<Solicitare> repoL;
	Repo<Pereche> repoPer;
	//vector <UndoOper*> undoAction;
public:

	//Preconditii: Doua siruri
	//Postconditii: Citeste din fisier
	void citire_fisier(string fis1, string fis2);

	//Preconditii:-
	//Postconditii: Contructor Solicitarea parametrii
	Controller();

	//Preconditii:-
	//Postconditii:Constructor cu paramentrii
	Controller(string fis1, string fis2);

	//Preconditii: Un Ambulanta
	//Postconditii: Adaugarea Ambulantaului
	void addAmbulanta(Ambulanta m);
	void delAmbulanta();
	void delSolicitare();
	void delTranz();
	//Preconditii: O Solicitare
	//Postconditii: Adaugarea Solicitarei
	void addSolicitare(Solicitare f);

	//Preconditii: Un numar intreg reprezentand pozitia unui Ambulanta
	//Postconditii: Returneaza Ambulantaul de pe pozitia respectiva
	Ambulanta getAmbulanta(int poz);

	//Preconditii: Un numar intreg reprezentand pozitia unuei Solicitaremacii
	//Postconditii: Returneaza Solicitaremacia de pe pozitia respectiva
	Solicitare getSolicitare(int poz);

	//Preconditii: Un numar intreg reprezentand pozitia unuei perechi
	//Postconditii: Returneaza perechea de pe pozitia respectiva
	Pereche getP(int poz);

	//Preconditii:-
	//Postconditii: Returneaza vector cu toate Ambulantaele
	vector<Ambulanta> getAllAmbulanta();

	//Preconditii:-
	//Postconditii: Returneaza vector cu toate Ambulantaele
	vector<Solicitare> getAllSolicitare();

	void addToate(Ambulanta m, Solicitare s);

	//Preconditii:-
	//Postconditii:Returneaza vector cu toate perechiile
	vector<Pereche> getAllPer();

	//Preconditii:-
	//Postconditii: Returneaza size-ul repozitory-ului de Ambulantae
	int getSizeP();

	//Preconditii:-
	//Postconditii: Returneaza size-ul repozitory-ului de Lacmacii
	int getSizeL();

	//Preconditii:-
	//Postconditii:  Returneaza size-ul repozitory-ului de perechi
	int getSizePer();

	//Preconditii:-
	//Postconditii: Salveaza tot in fisier
	void saveAll(string fis1, string fis2);

	//Preconditii: 3 stringuri si un intreg
	//Postconditii: Creaza o tranzactie
	void addTranz(string n, int p, string den, string ad);

	void undo();
};

#endif