/*
Program pentru rezolvarea problemei de m masini si n operatii
Structuri de Date si Algoritmi
2016
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

#define PARENT(i) (i>>1)
#define LEFT(i) (i<<1)
#define RIGHT(i) ((i<<1) + 1)

typedef struct nodeO {
	int timp;
	int index;
} *operatii;

typedef struct nodeM {
	int timpTotal;
	queue<operatii> op;
} *machines;

//Functia va lua un array de tip operatii si o va transforma in max-heap 
//Prec: A - array de tip operatii - pointer la nodeO, n - marime array, i - pozitia de start
void MaxHeapify(operatii A[], int n, int i)
{
	int largest;
	int l = LEFT(i);
	int r = RIGHT(i);
	if (l <= n && A[l]->timp > A[i]->timp)
		largest = l;
	else largest = i;
	if (r <= n && A[r]->timp > A[largest]->timp)
		largest = r;
	if (largest != i)
	{
		operatii aux = A[i];
		A[i] = A[largest];
		A[largest] = aux;
		MaxHeapify(A, n, largest);
	}
}
//Construieste max heap-ul BOTTOMUP
//Prec: A - array de tip operatii - pointer la nodeO, n - marime array
void Build_MaxHeap_btup(operatii A[], int n)
{
	for (int i = n / 2; i >= 1; --i)
		MaxHeapify(A, n, i);
}

//Functia va lua un array de tip machines si o va transforma in min-heap 
//Prec: B - array de tip machines - pointer la nodeM, n - marime array, i - pozitia de start
void MinHeapify(machines B[], int n, int i)
{
	int smallest;
	int l = LEFT(i);
	int r = RIGHT(i);
	if (l <= n && B[l]->timpTotal < B[i]->timpTotal)
		smallest = l;
	else smallest = i;
	if (r <= n && B[r]->timpTotal < B[smallest]->timpTotal)
		smallest = r;
	if (smallest != i)
	{
		machines aux = B[i];
		B[i] = B[smallest];
		B[smallest] = aux;
		MinHeapify(B, n, smallest);
	}
}

//Construieste min heap-ul BOTTOMUP
//Prec: B - array de tip machines - pointer la nodeM, n - marime array
void Build_MinHeap_btup(machines B[], int n)
{
	for (int i = n / 2; i >= 1; --i)
		MinHeapify(B, n, i);
}

//Functia va returna cel mai mare timp total in care o masina va functiona
//Prec: B - array de tip machines - pointer la nodeM, n - marime array
//Postc: max - numar natural reprezentand timpul total maxim
int maxim(machines B[], int n)
{
	int max = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		if (B[i]->timpTotal > max)
			max = B[i]->timpTotal;
	}
	return max;
}

int main()
{
	int size_o, size_m; //definim marimea pentru lista de operatii si cea de masini
	cout << "Numarul de operatii: " << endl;
	cin >> size_o;
	operatii *A = new operatii[size_o]; //se creaza un array te tip operatii de marimea ceruta
	//citim timpul pentru fiecare operatie
	for (int i = 1; i <= size_o; i++)
	{
		cout << "Timpul pentru operatia " << i << " : " << endl;
		operatii m = new nodeO;
		cin >> m->timp;
		m->index = i;
		A[i] = m;
	}
	cout << "Numarul de masini: " << endl;
	cin >> size_m;
	machines *B = new machines[size_m];
	for (int i = 1; i <= size_m; i++)
	{
		machines p = new nodeM;
		p->timpTotal = 0;
		B[i] = p;
	}

	Build_MaxHeap_btup(A, size_o);
	cout << endl;

	while (size_o > 0)
	{
		B[1]->timpTotal += A[1]->timp;
		B[1]->op.push(A[1]);
		A[1] = A[size_o--];
		MinHeapify(B, size_m, 1);
		MaxHeapify(A, size_o, 1);
	}
	cout << "\n";
	cout << "Timp total  -  Index\n";
	for (int i = 1; i <= size_m; i++)
	{

		cout << B[i]->timpTotal << " ";
		while (!B[i]->op.empty()) {
			cout << B[i]->op.front()->index << " ";
			B[i]->op.pop();
		}
		cout << '\n';
	}

	cout << "Timpul minim este: " << maxim(B, size_m) << endl;
	return 0;
}