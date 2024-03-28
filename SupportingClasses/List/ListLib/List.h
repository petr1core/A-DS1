#pragma once
//TODO change unicode or translate comments (╯°□°)╯︵ ┻━┻
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	template <class T>
	struct TNode // cell
	{
		T value;
		TNode<T>* pNext;
	};

	TNode<T>* pFirst;			// First cell
	TNode<T>* pLast;			// Last cell
	TNode<T>* pCurrent;			// Current cell
	TNode<T>* pPrevious;		// Previous cell
	TNode<T>* pStop;			// Value saying abt end of the list
	int length;					// Size

public:
	TList();
	~TList();
	int GetLength() const;		// +
	bool IsEmpty();				// +

	// вставка звеньев
	void InsertFirst(T item); // перед первым
	void InsertCurrent(T item); // перед текущим 
	void InsertNextCurrent(T item); // после текущего                           //TODO
	void InsertLast(T item);  // вставить последним 


	// удаление звеньев
	int DeleteFirst(); // удалить первое звено 
	int DeleteCurrent(); // удалить текущее звено



	void GoNext(); // сдвиг вправо текущего звена
	//(=1 после применения GoNext для последнего звена списка)

	void Reset(); // установить на начало списка
	bool IsEnd();  // список завершен ?

	T GetCurrentItem();
	int SetCurrentItem(T item);
	//TNode<T>* GetCurrentItemPointer();
	//void SetCurrentAt(int ind);
	/*TList<T>& operator=(const TList<T>& other);
	bool operator==(const TList<T>& other);
	bool operator!=(const TList<T>& other);*/
};

template<class T>
TList<T>::TList() {
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pLast = nullptr;
	pStop = nullptr;
	length = 0;
}

template<class T>
TList<T>::~TList()
{
	while (!IsEmpty()) {
		DeleteFirst();
	}
}

template<class T>
int TList<T>::GetLength() const
{
	return this->length;
}

template<class T>
bool TList<T>::IsEmpty()
{
	return pFirst == nullptr;
}

template<class T>
void TList<T>::InsertFirst(T item)
{
	TNode<T>* n = new TNode<T>{ item, pFirst };
	pFirst = n;
	if (IsEmpty()) 
		pLast = pFirst;
	length++;
}

template<class T>
void TList<T>::InsertCurrent(T item)
{
	if (pCurrent == pFirst || pCurrent == nullptr) {
		this->InsertFirst(item);
		return;
	}
	TNode<T>* n = new TNode<T>{ item, pCurrent };
	pPrevious->pNext = n;
	length++;
}

template<class T>
void TList<T>::InsertNextCurrent(T item)
{
	return;
}

template<class T>
void TList<T>::InsertLast(T item)
{
	TNode<T>* n = new TNode<T>{ item, nullptr };
	if (IsEmpty()) {
		pLast = n;
		pFirst = pLast;
	}
	else {
		pLast->pNext = n;
		pLast = n;
	}
	length++;
}

template<class T>
int TList<T>::DeleteFirst()
{
	if (IsEmpty()) return -1;
	TNode<T>* n = pFirst;
	pFirst = pFirst->pNext;
	if (pFirst == nullptr)
		pLast = nullptr;
	delete n;
	length--;
}

template<class T>
int TList<T>::DeleteCurrent()
{
	if (pCurrent == nullptr) 
		return -1;
	if (pCurrent == pFirst) {
		this->DeleteFirst();
		return 0;
	}
	if (pCurrent == pLast) {
		delete pCurrent;
		pPrevious->pNext = nullptr;
		pLast = pPrevious;
		pCurrent = nullptr;
	}
	else {
		pPrevious->pNext = pCurrent->pNext;
		delete pCurrent;
		pCurrent = pPrevious->pNext;
	}
}

template<class T>
void TList<T>::GoNext()
{
	pPrevious = pCurrent;
	pCurrent = pCurrent->pNext;
	if (pCurrent == pStop || pCurrent == nullptr)
		pLast = pPrevious;
}

template<class T>
void TList<T>::Reset()
{
	pCurrent = pFirst;
	pPrevious = nullptr;
}

template<class T>
bool TList<T>::IsEnd()
{
	return pCurrent == pStop;
}

template<class T>
T TList<T>::GetCurrentItem()
{
	return (pCurrent != nullptr) ? pCurrent->value : throw runtime_error("List is empty");
}

template<class T>
int TList<T>::SetCurrentItem(T item)
{
	if (pCurrent == nullptr)
		return -1;
	else {
		pCurrent->value = item;
	}
	return 0;
}

//
//template <class T>
//TList<T>::TList()
//{
//	pFirst = nullptr;
//	pLast = nullptr;
//	pCurrent = nullptr;
//	pPrevious = nullptr;
//	pStop = nullptr;
//	length = 0;
//}
//
//template <class T>
//TList<T>::~TList()
//{
//
//	while
//	/*while (pFirst != nullptr) {
//		TNode<T>* t = pFirst;
//		pFirst = pFirst->GetPointer();
//		delete t;
//	}*/
//}
//
////template<class T>
////inline TList<T>::TList(const TList<T>& other)
////{
////	TNode<T>* otherptr = other.pFirst;
////	if (other.pFirst != nullptr) {
////		pFirst = new TNode<T>(other);
////		TNode<T>* nextptr = pFirst;
////		while (otherptr->pNext != nullptr) {
////			TNode<T>* t = new TNode<T>(otherptr->pNext);
////			nextptr->SetPointer(t);
////			otherptr = otherptr->pNext;
////			nextptr = nextptr->pNext;
////		}
////	}
////	else { this->pFirst = other.pFirst }
////	this->length = other.length;
////	this->pCurrent = other.pCurrent;
////	this->pLast = other.pLast;
////	this->pPrevious = other.pPrevious;
////	this->pStop = other.pStop;
////}
//
//template<class T>
//TList<T>& TList<T>::operator=(const TList<T>& other)
//{
//	//if (this == other) return *this;
//	TNode<T>* otherptr = other.pFirst;
//	if (other.pFirst != nullptr) {
//		pFirst = new TNode<T>(other);
//		TNode<T>* nextptr = pFirst;
//		while (otherptr->pNext != nullptr) {
//			TNode<T>* t = new TNode<T>(otherptr->pNext);
//			nextptr->SetPointer(t);
//			otherptr = otherptr->pNext;
//			nextptr = nextptr->pNext;
//		}
//	}
//	else { this->pFirst = other.pFirst; }
//	this->length = other.length;
//	this->pCurrent = other.pCurrent;
//	this->pLast = other.pLast;
//	this->pPrevious = other.pPrevious;
//	this->pStop = other.pStop;
//
//	return *this;
//}
//
//template<class T>
//bool TList<T>::operator==(const TList<T>& other)
//{
//	if (this->length != other.length || this->pCurrent != other.pCurrent || this->pLast != other.pLast || this->pPrevious != other.pPrevious
//		|| this->pStop != other.pStop || this->pFirst || other.pFirst) return false;
//
//	TNode<T>* ptr1 = this->pFirst;
//	TNode<T>* ptr2 = other.pFirst;
//
//	while (ptr1 != nullptr && ptr2 != nullptr)
//	{
//		if (ptr1->value != ptr2->value()) return false;
//		ptr1 = ptr1->pNext;
//		ptr2 = ptr2->pNext;
//	}
//	return true;
//}
//
//template<class T>
//bool TList<T>::operator!=(const TList<T>& other)
//{
//	if (this->length != other.length || this->pCurrent != other.pCurrent || this->pLast != other.pLast || this->pPrevious != other.pPrevious
//		|| this->pStop != other.pStop || this->pFirst || other.pFirst) return true;
//
//	TNode<T>* ptr1 = this->pFirst;
//	TNode<T>* ptr2 = other.pFirst;
//
//	while (ptr1 != nullptr && ptr2 != nullptr)
//	{
//		if (ptr1->value != ptr2->value()) return true;
//		ptr1 = ptr1->pNext;
//		ptr2 = ptr2->pNext;
//	}
//	return false;
//}
//
//template <class T>
//void TList<T>::InsertFirst(T item)
//{
//	TNode<T>* newNode = new TNode<T>(item);
//	if (pFirst == nullptr) { // Если список пуст, новое звено становится первым и последним
//		pStop = new TNode<T>;
//		pFirst = newNode;
//		pLast = newNode;
//		pCurrent = newNode;
//	}
//	else {
//		//Вставляем новое звено перед первым
//		newNode->SetPointer(pFirst);
//		pFirst = newNode;
//	}
//	length++;
//}
//
//template <class T>
//void TList<T>::InsertLast(T item)
//{
//	TNode<T>* newNode = new TNode<T>(item);
//
//	if (pFirst == nullptr) {
//		pStop = new TNode<T>;
//		pFirst = newNode;
//		pCurrent = newNode;
//	}
//	else {
//		pLast->SetPointer(newNode);
//	}
//	pLast = newNode;
//	length++;
//}
//
//template <class T>
//void TList<T>::InsertCurrent(T item)
//{
//	TNode<T>* newNode = new TNode<T>(item);
//
//	if (pFirst == pCurrent) {
//		newNode->SetPointer(pFirst);
//		pFirst = newNode;
//		pPrevious = newNode;
//	}
//	else {
//		pPrevious->SetPointer(newNode);
//		newNode->SetPointer(pCurrent);
//	}
//	length++;
//}
//
//template <class T>
//void TList<T>::InsertNextCurrent(T item)
//{
//	TNode<T>* newNode = new TNode<T>(item);
//
//	if (pLast == pCurrent) {
//		pLast->SetPointer(newNode);
//		pLast = newNode;
//	}
//	else {
//		newNode->SetPointer(pCurrent->GetPointer());
//		pCurrent->SetPointer(newNode);
//	}
//	length++;
//}
//
//template <class T>
//void TList<T>::DeleteFirst()
//{
//	if (pFirst == nullptr) {
//		// Если список пуст, ничего не делаем
//		return;
//	}
//	if (pFirst == pCurrent) {
//		pCurrent = pCurrent->GetPointer();
//	}
//	TNode<T>* temp = pFirst;
//	pFirst = pFirst->GetPointer();
//	delete temp; // Освобождаем память звена
//	if (pFirst == nullptr) {
//		// Если после удаления первого звена список становится пустым, обновляем указатели на последнее и конечное звено
//		pStop = nullptr;
//		pLast = nullptr;
//	}
//
//	length--;
//}
//
//template <class T>
//void TList<T>::DeleteCurrent()
//{
//	if (pCurrent == nullptr || pFirst == nullptr) {
//		// Если текущее звено не установлено или список пуст ничего не делаем
//		return;
//	}
//
//	if (pCurrent == pFirst) {
//		// Если текущее звено является первым, удаляем первое звено
//		DeleteFirst();
//	}
//	else {
//		pPrevious->SetPointer(pCurrent->GetPointer());
//		pCurrent = pCurrent->GetPointer();
//		length--;
//	}
//	if (pCurrent == pStop) pStop = pPrevious;
//	if (pCurrent == pLast) pLast = pPrevious;
//}
//
//template <class T>
//T TList<T>::GetCurrentItem()
//{
//	if (pCurrent == nullptr)
//		throw "current element is Null";
//	if (pFirst == nullptr)
//		throw "the list is empty";
//	return *pCurrent->GetValue();
//}
//
//template <class T>
//TNode<T>* TList<T>::GetCurrentItemPointer()
//{
//	if (pCurrent == nullptr)
//		throw "current element is Null";
//	if (pFirst == nullptr)
//		throw "the list is empty";
//	return pCurrent;
//}
//
//template <class T>
//void TList<T>::Reset()
//{
//	if (pCurrent == pFirst) return;
//	pCurrent = pFirst;
//	pPrevious = nullptr;
//}
//
//template <class T>
//void TList<T>::GoNext()
//{
//	if (IsEmpty()) throw "SimplyList is empty";
//	if (IsEnd()) throw "There is no elements to go to";
//	pPrevious = pCurrent;
//	pCurrent = pCurrent->GetPointer();
//}
//
//template <class T>
//bool TList<T>::IsEnd()
//{
//	return pCurrent->GetPointer() == pStop;
//}
//
//template <class T>
//void TList<T>::SetCurrentAt(int ind) {
//	if (ind < 0 || ind >= length) throw "wrong index";
//	this->Reset();
//	for (size_t i = 0; i < ind; i++) GoNext();
//}