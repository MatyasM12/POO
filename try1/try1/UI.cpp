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
	//cout << "3.Tranzactie" << endl;
	//cout << "4. Undo" << endl;
	cout << "0. Exit" << endl;
	cout << "--------------------------------" << endl;
}
//-------------------------------------------------------------------
//Preconditii:-
//Postconditii: Apeleaza functii
void UI::menu()
{
	int op = 1;
	c = Controller("sAmbulanta.txt", "sSolicitare.txt");
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
		//if (op == 3) {
		//	addTranz();
		//}
		//if (op == 4) {
		//	UndoE();
		//}
		if (op == 0)
		{
			cout << "------------" << endl;
			c.saveAll("sAmbulanta.txt", "sSolicitare.txt");
			system("pause");
		}

	}
}
/*
Ambulanta UI::exAdauga()
{
	Ambulanta n = Ambulanta("Gutui", 20);
	c.addAmbulanta(n);
	return n;
}*/
//-------------------------------------------------------------------
//Preconditii:-
//Postconditii:Adauga un element
int UI::adauga()
{
	int op;
	cout << "11. Ambulanta" << endl;
	cout << "12. Solicitare" << endl;
	cout << "13. Ambele" << endl;
	cout << "---------------" << endl;
	cout << "Ce doriti sa introduceti?" << endl;
	cin >> op;
	if (op == 11)
	{

		//Ambulanta m = citire_Ambulanta();
		//c.addAmbulanta(m);
		//Solicitare f = citire_Solicitare();
		//c.addSolicitare(f);
		Solicitare f = citire_Solicitare();
		c.addSolicitare(f);
		//c.addToate(m, f);
	}
	if (op == 12)
	{
		Solicitare f = citire_Solicitare();
		c.addSolicitare(f);
	}

	if (op == 13)
	{
		Ambulanta m = citire_Ambulanta();
		Solicitare f = citire_Solicitare();
		//c.addSolicitare(f);
		c.addToate(m, f);
	}
	cout << "Ati adaugat cu succes!" << endl << endl;
	return op;

}


//-------------------------------------------------------------------
//Preconditii:-
//Postconditii:Afiseaza elementele
void UI::afiseazaTot()
{
	vector <Solicitare> vF = c.getAllSolicitare();
	vector<Ambulanta> vM = c.getAllAmbulanta();
	vector<Controller::Pereche> vP = c.getAllPer();
	int i, sizeM = vM.size(), sizeF = vF.size(), sizeP = vP.size();
	cout << endl << "Ambulantai - Numar:" << endl;
	if (sizeM == 0)
		cout << "-" << endl;
	else
	{
		for (i = 0; i < sizeM; i++)
			cout << vM[i];
	}
	cout << endl << "Solicitaree - Judete:" << endl;
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
			cout << "Solicitareul: " << vP[i].Solicitare;
			cout << "Ambulanta: " << vP[i].Ambulanta;
			cout << endl;
		}
	}

}
//---------------------------------------------------------------
//Preconditii:
//Postconditii: Un Ambulanta
Ambulanta UI::citire_Ambulanta()
{
	char denumire[30];
	int nr;
	int ok = 0;
	while (!ok)
	{
		cout << "Dati denumirea Ambulantei:";
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
	Ambulanta m = Ambulanta(denumire, nr);
	return m;
}/*
 void UI::undo()
 {
 vector <Solicitare> vF = c.getAllSolicitare();
 vector<Ambulanta> vM = c.getAllAmbulanta();
 vector<Controller::Pereche> vP = c.getAllPer();
 vF.pop_back();
 }*/
 //-----------------------------------------------------------------------------
 //Preconditii:
 //Postconditii: un Solicitare
Solicitare UI::citire_Solicitare()
{
	char denumire[30];
	int nr;
	int ok = 0;
	while (!ok)
	{
		cout << "Dati denumirea Solicitarii:";
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
		cout << "Dati nr Solicitarii:";
		cin >> nr;
		ok = 1;
		/*if (strlen(judet) < 3)
		{
			cout << "judetul trebuie sa aiba cel putin 3 caractere" << endl;
			ok = 0;
		}
		else
			ok = 1;*/
	}
	Solicitare f = Solicitare(denumire, nr);
	return f;
}
//-----------------------------------------------------------------------------
//Preconditii:-
//Postconditii:Adauga o pereche
/*
void UI::addTranz()
{
	Ambulanta m = citire_Ambulanta();
	Solicitare f = citire_Solicitare();
	try
	{
		c.addTranz(m.getdenumire(), m.getnr(), f.getDenumire(), f.getjudet());
		cout << "Perechea a fost adaugata cu succes!" << endl;
	}
	catch (char ex[30])
	{
		cout << ex << endl;
	}
}*/

//Preconditii:
//Postconditii:
/*
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

}*/