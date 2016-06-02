#include "Repo.h"
#include "Pom.h"
#include "Oras.h"
#include "Undo.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
public:
	class Pereche
	{
	public:
		Pom Pom;
		Oras Oras;
	};
private:
	Repo<Pom> repoP;
	Repo<Oras> repoL;
	Repo<Pereche> repoPer;
	vector <UndoOper*> undoAction;
public:

	//Preconditii: Doua siruri
	//Postconditii: Citeste din fisier
	void citire_fisier(string fis1, string fis2);

	//Preconditii:-
	//Postconditii: Contructor Orasa parametrii
	Controller();

	//Preconditii:-
	//Postconditii:Constructor cu paramentrii
	Controller(string fis1, string fis2);

	//Preconditii: Un Pom
	//Postconditii: Adaugarea Pomului
	void addPom(Pom m);
	void delPom();
	void delOras();
	void delTranz();
	//Preconditii: O Oras
	//Postconditii: Adaugarea Orasi
	void addOras(Oras f);

	//Preconditii: Un numar intreg reprezentand pozitia unui Pom
	//Postconditii: Returneaza Pomul de pe pozitia respectiva
	Pom getPom(int poz);

	//Preconditii: Un numar intreg reprezentand pozitia unuei Orasmacii
	//Postconditii: Returneaza Orasmacia de pe pozitia respectiva
	Oras getOras(int poz);

	//Preconditii: Un numar intreg reprezentand pozitia unuei perechi
	//Postconditii: Returneaza perechea de pe pozitia respectiva
	Pereche getP(int poz);

	//Preconditii:-
	//Postconditii: Returneaza vector cu toate Pomele
	vector<Pom> getAllPom();

	//Preconditii:-
	//Postconditii: Returneaza vector cu toate Pomele
	vector<Oras> getAllOras();

	//Preconditii:-
	//Postconditii:Returneaza vector cu toate perechiile
	vector<Pereche> getAllPer();

	//Preconditii:-
	//Postconditii: Returneaza size-ul repozitory-ului de Pome
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