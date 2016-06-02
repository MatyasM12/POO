#include "Repo.h"
#include "Controller.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H


Vector cauta(int n, Vector v)
{
	Vector x;
	x = v.selectid(n);
	return x;
}

void sortare(Vector &v)
{
	int i, j, s;
	int val1, val2;
	s = v.getSize();
	for (i = 0; i <s - 1; i++)
	{
		for (j = i + 1; j<s; j++)
		{
			val1 = v.getElem(i)->min();
			val2 = v.getElem(j)->min();
			if (val1 > val2)
			{
				Ferma* p1 = v.getElem(i);
				Ferma* p2 = v.getElem(j);
				v.setElem(p1, j);
				v.setElem(p2, i);
			}
		}
	}
}

void sortare2(Vector &v)
{
	int i, j, s;
	s = v.getSize();
	for (i = 0; i <s - 1; i++)
	{
		for (j = i + 1; j < s; j++)
		{
			if (v.getElem(j)->comparare(v.getElem(i)))
			{
				Ferma* p1 = v.getElem(i);
				Ferma* p2 = v.getElem(j);
				v.setElem(p1, j);
				v.setElem(p2, i);
			}
		}
	}

}
/*
void sortare2(Vector &v)
{
	int i, j, s;
	s = v.getSize();
	for (j = 0; j <s - 1; --j)
	{
		for (i = 0; i < j; ++i)
		{
			if (v.getElem(i)->comparare(v.getElem(i+1)))
			{
				Ferma* p1 = v.getElem(i);
				Ferma* p2 = v.getElem(i+1);
				v.setElem(p2, j);
				v.setElem(p1, i);
			}
		}
	}

}
*/
#endif // !CONTROLLER_H