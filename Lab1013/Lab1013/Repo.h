#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#ifndef REPO_H
#define REPO_H

template <class T, int cap = 100> class Repo {
private:
	vector<T> elem;
	int size;
	string fileName;

public:
	//Preconditii:-
	//Postconditii:Constructor Laca parametrii
	Repo();

	//Preconditii:
	//Postconditii:
	Repo(const Repo<T, cap>& r);

	//preconditii:
	//Postconditii:
	~Repo();

	//Preconditii:
	//Postconditii:
	void loadFromFile();

	//Preconditii:
	//Postconditii:
	void saveInFile();

	//Preconditii:
	//Postconditii:
	void addElem(T elem);

	void delElem();

	//Preconditii:
	//Postconditii:
	int searchElem(T elem);

	//Preconditii:
	//Postconditii:
	int getSize();

	//Preconditii:
	//Postconditii:
	T getElem(int poz);

	//Preconditii:
	//Postconditii:
	vector<T>  getAll();

	//Preconditii:
	//Postconditii:
	void setFileName(string name);

};
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> Repo <T, cap>::Repo()
{
	size = 0;
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:

template <class T, int cap> Repo <T, cap>::Repo(const Repo<T, cap>& r)
{
	elem = r.elem;
	size = r.size;
	fileName = r.fileName;
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> Repo <T, cap>::~Repo()
{
	size = 0;
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> void Repo<T, cap>::loadFromFile()
{
	ifstream fin;
	T obj;
	fin.open(fileName);
	while (fin >> obj)
	{
		elem.push_back(obj);
		size++;
	}
}
//--------------------------------------------------------------------
//Preconditii:
//POstconditii:
template <class T, int cap> void Repo<T, cap>::saveInFile()
{
	ofstream fout;
	fout.open(fileName);
	for (int i = 0; i < size; i++)
		fout << elem[i] << " ";
	fout.close();
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> void Repo<T, cap>::addElem(T el)
{
	elem.push_back(el);
	size++;
}

template <class T, int cap> void Repo<T, cap>::delElem()
{
	if (size != 0)
	{
		elem.pop_back();
		size--;
	}
	else
	{
		throw("Nu mai sunt elemente de sters");
	}
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> int Repo<T, cap>::searchElem(T el)
{
	for (int i = 0; i < size; i++)
	{
		if (elem[i] == el)
			return i;
	}
	return -1;
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> int Repo<T, cap>::getSize()
{
	return size;
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> T Repo<T, cap>::getElem(int pos)
{
	if ((pos<0) || (pos>size - 1))
		throw ("Pozitie incorecta");
	return elem[pos];
}
//--------------------------------------------------------------------
//Preconditii:
//Postconditii:
template <class T, int cap> vector<T> Repo<T, cap>::getAll()
{
	return elem;
}
//Preconditii:
//Postconditii:
template <class T, int cap> void Repo<T, cap>::setFileName(string name)
{
	fileName = name;
}
#endif