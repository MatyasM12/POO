#include "IO.h"
#include "Domain.h"
#include "Repo.h"
#include "Controller.h"

void print_menu()
{
	cout << "1.Afiseaza obiecte\n";
	cout << "2.Cauta obiect\n";
	cout << "3.Sorteaza\n";
	cout << "4. Sortare 2\n";
	cout << "5.Exit\n";
}

void menu()
{
	int op = 0, n;
	Vector v, x;
	v.citireFisier("Livada.txt");
	while (op != 5)
	{
		print_menu();
		cout << "Dati optiunea: ";
		cin >> op;
		cout << endl;
		if (op == 1)
			v.print();
		if (op == 2)
		{
			n = citire_intreg();
			x = cauta(n, v);
			x.print();
		}
		if (op == 3)
		{
			sortare(v);
			v.print();
		}
		if (op == 4)
		{
			sortare2(v);
			v.print();
		}

	}
}
int citire_intreg()
{
	int n;
	cout << "dati numar intreg: ";
	cin >> n;
	cout << endl;
	return n;
}

