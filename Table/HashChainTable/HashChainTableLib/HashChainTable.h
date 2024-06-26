#pragma once
#include "TableBaseLib/TableBase.h"
#include "Polinom/PolinomLib/List.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class Key, class Value>
class HashChainTable : public Table<Key, Value>
{
	vector<TList<Row>*> vec;
	//TList<Row>* empty = new TList<Row>();
	int curs = -1;
	int count = 0; // not empty els in vec
	int itemCurs = -1;
	int HashKey(Key _key) const ;

public:

	double Getfullness(void) const ;
	int GetCount(void) const ;
	Value* Find(Key _key) override ;
	int Insert(Key _key, Value _val) override ;
	int Delete(Key _key) override ;

	void Reset(void) override ;
	bool IsTabEnded(void) const override ;
	int GoNext(void) override ;

	Key GetKey(void) const override ;
	Value* GetValuePtr(void) override ;
};

template<class Key, class Value>
double HashChainTable<Key, Value>::Getfullness(void) const 
{
	return (double)count / size;
}

template<class Key, class Value>
int HashChainTable<Key, Value>::GetCount(void) const 
{
	return this->count;
}

template<class Key, class Value>
int HashChainTable<Key, Value>::HashKey(Key _key) const 
{
	int res = 0;
	string str = to_string(_key);
	for (int i = 0; i < str.length(); i++)
		res += str[i];
	return res % this->maxsize;
}

template<class Key, class Value>
Value* HashChainTable<Key, Value>::Find(Key _key) 
{
	if (this->IsEmpty()) return nullptr;
	int t = this->HashKey(_key);
	if (vec.size() <= t) return nullptr;
	if (vec[t] == nullptr) return nullptr;
	vec[t]->Reset();
	return &(vec[t]->GetCurrentItemPtr()->value);
}

template<class Key, class Value>
int HashChainTable<Key, Value>::Insert(Key _key, Value _val) 
{
	if (this->IsFull()) return -1;
	int t = this->HashKey(_key);
	if (t >= vec.size()) {		// if vec has no space to insert in that index
		if ((t + 1) <= this->maxsize) {
			TList<Row>* newlist = new TList<Row>();
			newlist->InsertLast({ _key, _val });
			vec.resize(t,nullptr);
			vec.push_back(newlist);
			count++;
			size = vec.size();
			if (count == 1) { // if first el in whole vec, make cursor point to it
				this->Reset();
			}
			return 0;
		}
		else return -1; // reached max
	}
	if (vec[t] == nullptr) {  // if cell[t] has no TList in
		TList<Row>* newlist = new TList<Row>();
		newlist->InsertLast({ _key, _val });
		vec[t] = newlist;
		count++;
	}
	else {   // if cell [t] already has TList in
		vec[t]->InsertLast({ _key, _val });
	}
	return 0;
}

template<class Key, class Value>
int HashChainTable<Key, Value>::Delete(Key _key) 
{
	if (this->IsEmpty()) return -1;
	if (this->count > 1) {
		int t = this->HashKey(_key);
		if (vec.size() <= t) return -1;
		vec[t] = nullptr;
		count--;
		size--;
	}
	else {
		count = 0;
		vec.resize(0);
		size = 0;
	}
	itemCurs = -1;
	return 0;
}

template<class Key, class Value>
void HashChainTable<Key, Value>::Reset(void) 
{
	this->curs = (count != 0) ? 0 : -1;
	this->itemCurs = 0;
	this->GoNext();
	vec[this->curs]->Reset();
}
template<class Key, class Value>
int HashChainTable<Key, Value>::GoNext(void) 
{
	if (!(vec[curs] == nullptr) && vec[curs]->GetLength() > 1) {
		if (!vec[curs]->IsNextEnd() ) {
			vec[curs]->GoNext();
		return 0;
		}
		else {
			do {
				curs = (curs + 1) % size;

			} while (vec[curs] == nullptr);

			if (count != 0 && !(vec[curs] == nullptr))
				this->itemCurs++;
		}
	}
	else {
			do {
				curs = (curs + 1) % size;

			} while (vec[curs] == nullptr);

			if (count != 0 && !(vec[curs] == nullptr))
				this->itemCurs++;
	}
	return 0;
}

template<class Key, class Value>
bool HashChainTable<Key, Value>::IsTabEnded(void) const 
{
	return this->itemCurs == count + 1;
}


template<class Key, class Value>
Key HashChainTable<Key, Value>::GetKey(void) const  
{
	if (curs == -1) return NULL;
	return (vec[this->curs]->GetCurrentItemPtr())->key;
}
template<class Key, class Value>
Value* HashChainTable<Key, Value>::GetValuePtr(void) 
{
	if (curs == -1) return nullptr;
	if (vec[this->curs]->IsEnd()) {
		return nullptr;
	}
	else return &(vec[this->curs]->GetCurrentItemPtr()->value);
}