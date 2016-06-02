#include "Controller.h"

#ifndef UI_H
#define UI_H
class UI
{
public:
	Controller c;
public:
	//Precoditii:-
	//Postconditii: Constructor Solicitare parametrii
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
	Ambulanta exAdauga();
	//Preconditii:
	//Postconditii: Un Ambulanta
	Ambulanta citire_Ambulanta();

	//Prec: - 
	//Postc: Undo
	//void UndoE();

	//Preconditii:
	//Postconditii: O Solicitare
	Solicitare citire_Solicitare();

	//Preconditii:-
	//Postconditii:Adauga o pereche
	//void addTranz();
};

#endif