#pragma once

#include "List.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;  // заголовок, pFirst - звено за pHead
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item); // вставка звеньев после заголовка
	void DeleteFirst(); // удалить первое звено
};

template<class T>
THeadList<T>::THeadList()
{
	this->pHead = new TNode<T>();
	this->pLast = this->pHead;
	this->pHead->pNext = this->pFirst;
	
	/*this->pFirst = this->pHead->GetPointer();
	this->pCurrent = this->pFirst;
	this->pStop = new TNode<T>();
	this->pLast = this->pStop;
	this->length = 0;*/
}

template<class T>
THeadList<T>::~THeadList()
{
	delete this->pHead;
}

template <class T>
void THeadList<T>::InsertFirst(T item)
{
	TNode<T>* n = new TNode<T>{item, nullptr};
	n->pNext = this->pHead->pNext;
	if (this->IsEmpty())
		this->pLast = n;
	this->pHead->pNext = n;

	/*n->SetPointer(pFirst);
	this->pFirst = n;
	this->length++;*/
}

template <class T>
void THeadList<T>::DeleteFirst()
{
	if (this->pFirst == nullptr) 
		throw "You are trying to delete element from an empty list";
	TNode<T>* n = this->pFirst;
	this->pFirst = this->pFirst->pNext;
	if (this->pFirst == nullptr)
		this->pLast = nullptr;
	if (pCurrent == n) {
		this->pCurrent = this->pFirst;
		this->pPrevious = nullptr;
	}

	delete n; // Освобождаем память звена
	this->length--;
} 