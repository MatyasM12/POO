#include "UI.h"

UI::UI()
{
}
//Preconditii:-
//POstconditii:Afiseaza meniul
void UI::print_menu()
{
	cout << "Meniu:" << endl;
	cout << "1.Afisare" << endl;
	cout << "2.Adaugare" << endl;
	cout << "3.Tranzactie" << endl;
	cout << "4. Undo" << endl;
	cout << "0. Exit" << endl;
	cout << "--------------------------------" << endl;
}
//-------------------------------------------------------------------
//Preconditii:-
//Postconditii: Apeleaza functii
void UI::menu()
{
	int op = 1;
	c = Controller("sPom.txt", "sOras.txt");
	while (op != 0)
	{
		print_menu();
		cout << "Alegeti optiunea:";
		cin >> op;
		if (op == 1)
			afiseazaTot();
		if (op == 2) {
			adauga();
		}
		if (op == 3) {
			addTranz();
		}
		if (op == 4) {
			UndoE();
		}
		if (op == 0)
		{
			cout << "------------" << endl;
			c.saveAll("sPom.txt", "sOras.txt");
			system("pause");
		}

	}
}

Pom UI::exAdauga()
{
	Pom n = Pom("Gutui", 20);
	c.addPom(n);
	return n;
}
//-------------------------------------------------------------------
//Preconditii:-
//Postconditii:Adauga un element
int UI::adauga()
{
	int op;
	cout << "11. Pom" << endl;
	cout << "12. Oras" << endl;
	cout << "---------------" << endl;
	cout << "Ce doriti sa introduceti?" << endl;
	cin >> op;
	if (op == 11)
	{

		Pom m = citire_pom();
		c.addPom(m);
		Oras f = citire_oras();
		c.addOras(f);
	}
	if (op == 12)
	{
		Oras f = citire_oras();
		c.addOras(f);
	}
	cout << "Ati adaugat cu succes!" << endl << endl;
	return op;

}


//-------------------------------------------------------------------
//Preconditii:-
//Postconditii:Afiseaza elementele
void UI::afiseazaTot()
{
	vector <Oras> vF = c.getAllOras();
	vector<Pom> vM = c.getAllPom();
	vector<Controller::Pereche> vP = c.getAllPer();
	int i, sizeM = vM.size(), sizeF = vF.size(), sizeP = vP.size();
	cout << endl << "Pomi - Numar:" << endl;
	if (sizeM == 0)
		cout << "-" << endl;
	else
	{
		for (i = 0; i < sizeM; i++)
			cout << vM[i];
	}
	cout << endl << "Orase - Judete:" << endl;
	if (sizeF == 0)
		cout << "-" << endl;
	else
	{
		for (i = 0; i < sizeF; i++)
			cout << vF[i];
	}
	cout << endl << "Perechi:" << endl;
	if (sizeP == 0)
		cout << "-" << endl;
	else
	{
		for (i = 0; i < sizeP; i++)
		{
			cout << "Orasul: " << vP[i].Oras;
			cout << "Pom: " << vP[i].Pom;
			cout << endl;
		}
	}

}
//---------------------------------------------------------------
//Preconditii:
//Postconditii: Un Pom
Pom UI::citire_pom()
{
	char denumire[30];
	int nr;
	int ok = 0;
	while (!ok)
	{
		cout << "Dati denumirea pomului:";
		cin >> denumire;
		if (strlen(denumire) < 3)
		{
			cout << "Denumirea trebuie sa aiba cel putin 3 caractere" << endl;
			ok = 0;
		}
		else
			ok = 1;
	}
	ok = 0;
	while (!ok)
	{
		cout << "Dati nr:";
		cin >> nr;
		if (nr <= 0)
		{
			cout << "Nr trebuie sa fie un numar natural" << endl;
			ok = 0;
		}
		else
			ok = 1;
	}
	Pom m = Pom(denumire, nr);
	return m;
}/*
void UI::undo()
{
	vector <Oras> vF = c.getAllOras();
	vector<Pom> vM = c.getAllPom();
	vector<Controller::Pereche> vP = c.getAllPer();
	vF.pop_back();
}*/
//-----------------------------------------------------------------------------
//Preconditii:
//Postconditii: un Oras
Oras UI::citire_oras()
{
	char denumire[30], judet[30];
	int ok = 0;
	while (!ok)
	{
		cout << "Dati denumirea orasului:";
		cin >> denumire;
		if (strlen(denumire) < 3)
		{
			cout << "denumirea trebuie sa aiba cel putin 3 caractere" << endl;
			ok = 0;
		}
		else
			ok = 1;
	}
	ok = 0;
	while (!ok)
	{
		cout << "Dati judetul orasului:";
		cin >> judet;
		if (strlen(judet) < 3)
		{
			cout << "judetul trebuie sa aiba cel putin 3 caractere" << endl;
			ok = 0;
		}
		else
			ok = 1;
	}
	Oras f = Oras(denumire, judet);
	return f;
}
//-----------------------------------------------------------------------------
//Preconditii:-
//Postconditii:Adauga o pereche
void UI::addTranz()
{
	Pom m = citire_pom();
	Oras f = citire_oras();
	try
	{
		c.addTranz(m.getdenumire(), m.getnr(), f.getDenumire(), f.getjudet());
		cout << "Perechea a fost adaugata cu succes!" << endl;
	}
	catch (char ex[30])
	{
		cout << ex << endl;
	}
}

//Preconditii:
//Postconditii:
void UI::UndoE()
{
	try
	{
		c.undo();
	}
	catch (char ex[30])
	{
		cout << ex << endl;
	}

}