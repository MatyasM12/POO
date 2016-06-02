#include "Repo.h"

#ifndef UNDO_H
#define UNDO_H
class UndoOper {
public:
	virtual void executeUndo() = 0;
	~UndoOper() {};
};
#endif;


#ifndef UNDOADD_H
#define UNDOADD_H
template<class T> class UndoAdd :public UndoOper
{
private:
	Repo<T> &repo;
public:
	UndoAdd(Repo<T>& r) :repo{ r } {};
	void executeUndo();
};

//template <class T> UndoAdd<T>::UndoAdd(Repo<T>& r)
//	{repo = r;
//	}

template <class T> void UndoAdd<T>::executeUndo()
{
	repo.delElem();
}
#endif;


#ifndef UndoTRANZ_H
#define UndoTRANZ_H
template<class T> class UndoTranz :public UndoOper
{
private:
	Repo<T> &repo;
public:
	UndoTranz(Repo<T>& r) : repo{ r } {}
	void executeUndo();
};

template <class T> void UndoTranz<T>::executeUndo()
{
	repo.delElem();
}
#endif;