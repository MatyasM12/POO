#include "Controller.h"

#ifndef UI_H
#define UI_H
class UI
{
public:
	Controller c;
public:
	//Precoditii:-
	//Postconditii: Constructor oras parametrii
	UI();

	//Preconditii:-
	//POstconditii:Afiseaza meniul
	void print_menu();

	//Preconditii:-
	//Postconditii: Apeleaza functii
	void menu();

	//Preconditii:-
	//Postconditii:Adauga un element
	int adauga();

	//Preconditii:-
	//Postconditii:Afiseaza elementele
	void afiseazaTot();
	Pom exAdauga();
	//Preconditii:
	//Postconditii: Un pom
	Pom citire_pom();

	//Prec: - 
	//Postc: Undo
	void UndoE();

	//Preconditii:
	//Postconditii: O oras
	Oras citire_oras();

	//Preconditii:-
	//Postconditii:Adauga o pereche
	void addTranz();
};

#endif