#pragma once

#include "List/ListLib/HeadList.h"
#include "PolinomLib/TMonom.h"
#include "PolinomLib/TDynamicVector.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int nonDisplayedZeros = 4;
const int precision = 4;

class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	//TPolinom(TDynamicVector<TMonom> vec);
	TPolinom(string str);
	TPolinom& operator=(TPolinom& other);
	TPolinom& operator+(TPolinom& q);


	void AddMonom(TMonom newMonom);
	TPolinom MultMonom(TMonom monom);
	TPolinom& operator*(double coef);
	bool operator==(TPolinom& other); 
	bool operator!=(TPolinom& other); 
	string ToString();
};

TPolinom::TPolinom() : THeadList<TMonom>::THeadList() { }//

TPolinom::TPolinom(TPolinom& other)//
{
	pHead = new TNode<TMonom>;
	TNode<TMonom>* h = other.pHead->pNext;
	while (h != other.pStop) {
		this->AddMonom(h->value);
		h = h->pNext;
	}
	//int size = other.GetLength();
	//this->length = size;
	//other.Reset();
	//TMonom first = other.GetCurrentItem();
	//this->InsertFirst(first);
	//other.GoNext();
	//for (size_t i = 1; i < size; i++) {
	//	TMonom newm = other.GetCurrentItem();
	//	this->InsertLast(newm);
	//	//this->GoNext();
	//	if (i != size - 1) other.GoNext();
	//}
	//pStop = nullptr;
}

//TPolinom::TPolinom(TDynamicVector<TMonom> vec)
//{
//	int vector_size = vec.size();
//	this->InsertFirst(vec[0]);
//	SetCurrentAt(0);
//	TMonom currm = GetCurrentItem();
//	int prevPow, nextPow, counter = 1, poliSize = 1;
//	if (vector_size > 1) {
//		for (int i = 1; i < vector_size; i++) {
//			nextPow = vec[i].GetIndex();
//			prevPow = GetCurrentItem().GetIndex();
//			if (nextPow > prevPow) {
//				TMonom newM;
//				newM.SetCoef(vec[i].GetCoef());
//				newM.SetIndex(vec[i].GetIndex());
//				InsertFirst(newM);
//				poliSize++;
//			}
//			else
//			{
//				while (nextPow < prevPow) {
//					if (counter < poliSize) {
//						GoNext();
//						counter++;
//						currm = GetCurrentItem();
//						prevPow = currm.GetIndex();
//					}
//					else {
//						TMonom newM;
//						newM.SetCoef(vec[i].GetCoef());
//						newM.SetIndex(vec[i].GetIndex());
//						InsertLast(newM);
//						poliSize++;
//						return;
//					}
//				}
//
//				if (nextPow == prevPow) {
//					if (counter == 1) {
//						currm.SetCoef(currm.GetCoef() + vec[i].GetCoef());
//						InsertFirst(currm);
//						Reset();
//						for (size_t i = 0; i < counter + 1; i++) GoNext();
//						DeleteCurrent();
//					}
//					else
//					{
//						currm.SetCoef(currm.GetCoef() + vec[i].GetCoef());
//						DeleteCurrent();
//						InsertCurrent(currm);
//					}
//				}
//				else
//				{
//					TMonom newM;
//					newM.SetCoef(vec[i].GetCoef());
//					newM.SetIndex(vec[i].GetIndex());
//					InsertCurrent(newM);
//					poliSize++;
//				}
//			}
//			counter = 1;
//		}
//	}
//	Reset();
//	pStop = nullptr;
//}

TPolinom::TPolinom(string str)//
{
	size_t pos = 0;
	while (pos < str.length()) {
		double coef = 0.0;
		int degX = 0, degY = 0, degZ = 0;
		char var;
		if (isdigit(str[pos]) || str[pos] == '-' || str[pos] == '+') {
			size_t nextPos;
			coef = stod(str.substr(pos), &nextPos);
			pos += nextPos;
		}
		while (pos < str.length() && (str[pos] == 'x' || str[pos] == 'X' ||
			str[pos] == 'y' || str[pos] == 'Y' ||
			str[pos] == 'z' || str[pos] == 'Z')) {
			var = tolower(str[pos]);
			pos++;
			if (pos < str.length() && str[pos] == '^') {
				pos++;
				size_t nextPos;
				int deg = stoi(str.substr(pos), &nextPos);
				pos += nextPos;
				switch (var) {
				case 'x': degX = deg; break;
				case 'y': degY = deg; break;
				case 'z': degZ = deg; break;
				}
			}
			else {
				switch (var) {
				case 'x': degX = 1; break;
				case 'y': degY = 1; break;
				case 'z': degZ = 1; break;
				}
			}
		}
		this->AddMonom(TMonom(coef, degX, degY, degZ));
	}
}

TPolinom& TPolinom::operator=(TPolinom& other)//
{
	/*other.Reset();
	this->Reset();
	TMonom m;
	for (size_t i = 0; i < other.GetLength(); i++) {
		m = other.GetCurrentItem();
		this->InsertCurrent(m);
		this->GoNext();
		other.GoNext();
	}
	this->pStop = nullptr;
	this->Reset();
	other.Reset();
	return *this;*/

	if (this != &other) {
		while (!this->IsEmpty()) {
			this->DeleteFirst();
		}
		TNode<TMonom>* current = other.pHead->pNext;
		while (current != nullptr) {
			this->AddMonom(current->value);
			current = current->pNext;
		}
	}
	return *this;
}

void TPolinom::AddMonom(TMonom otherMon)//
{
	/*int	size = this->GetLength();
	this->Reset();
	int i, j;
	for (size_t ii = 0; ii < size; ii++) {
		TMonom thisMon = this->GetCurrentItem();
		i = thisMon.GetIndex();
		j = otherMon.GetIndex();
		if (i == j) {
			TMonom newm;
			newm.SetCoef(thisMon.GetCoef() + otherMon.GetCoef());
			newm.SetIndex(i);
			this->pCurrent->SetValue(newm);
			return;
		}
		if (ii != size - 1)
			GoNext();
	}
	this->InsertNextCurrent(otherMon);
	this->Reset();*/

	if (otherMon.coef == 0) throw invalid_argument("Cannot add monom with zero coefficient");
	this->Reset();
	bool isadd = false;
	while (!this->IsEnd()) {
		if (this->pCurrent->value.ind == otherMon.ind) {
			this->pCurrent->value.coef += otherMon.coef;
			if (fabs(this->pCurrent->value.coef) < 1e-6) {
				this->DeleteCurrent();
			}
			isadd = true;
			break;
		}
		this->GoNext();
	}
	if (!isadd) this->InsertLast(otherMon);
	pHead->pNext = this->pFirst;
}

TPolinom TPolinom::MultMonom(TMonom monom)//
{
	TPolinom res(*this);
	TNode<TMonom>* current = res.pHead->pNext;
	while (current != nullptr) {
		current->value.coef *= monom.coef;
		current->value.ind += monom.ind;
		current = current->pNext;
	}
	return res;
}

TPolinom& TPolinom::operator+(TPolinom& other)//
{
	if (other.IsEmpty()) throw invalid_argument("Cannot add an empty polynomial");
	TNode<TMonom>* current = other.pHead->pNext;
	while (current != nullptr) {
		this->AddMonom(current->value);
		current = current->pNext;
	}
	return *this;
}

//TPolinom TPolinom::AddPolinom(TPolinom& other)
//{
//	TPolinom res(*this);
//	other.Reset();
//	this->Reset();
//	for (size_t i = 0; i < other.GetLength(); i++) {
//		TMonom m = other.GetCurrentItem();
//		res.AddMonom(m);
//		if (i != other.GetLength() - 1) other.GoNext();
//	}
//	return res;
//}

TPolinom& TPolinom::operator*(double _coef)//
{
	if (this->IsEmpty()) throw invalid_argument("Cannot multiply an empty polynomial");
	TNode<TMonom>* current = this->pHead->pNext;
	while (current != nullptr) {
		current->value.coef *= _coef;
		if (current->pNext == nullptr) break;
		current = current->pNext;
	}
	return *this;
}

bool TPolinom::operator==(TPolinom& other)//
{
	/*if (this->GetLength() != other.GetLength()) return false;
	this->Reset();
	other.Reset();
	for (int i = 0; i < this->GetLength(); i++) {
		TMonom f = this->GetCurrentItem();
		TMonom s = other.GetCurrentItem();
		if (f != s) return false;
		this->GoNext();
		other.GoNext();
	}
	return true;*/

	if (this->GetLength() != other.GetLength()) return false;
	TNode<TMonom>* thisCurrent = this->pHead->pNext;
	TNode<TMonom>* otherCurrent = other.pHead->pNext;
	while (thisCurrent != nullptr && otherCurrent != nullptr) {
		if (!(thisCurrent->value == otherCurrent->value)) { return false; }
		thisCurrent = thisCurrent->pNext;
		otherCurrent = otherCurrent->pNext;
	}
	return thisCurrent == otherCurrent;
}

bool TPolinom::operator!=(TPolinom& other)
{
	if (this->GetLength() != other.GetLength()) return true;
	this->Reset();
	other.Reset();
	for (int i = 0; i < this->GetLength(); i++) {
		TMonom f = this->GetCurrentItem();
		TMonom s = other.GetCurrentItem();
		if (f != s) return true;
		this->GoNext();
		other.GoNext();
	}
	return false;
}

string TPolinom::ToString()//
{
	string res;
	this->Reset();
	int size = this->GetLength();
	for (size_t i = 0; i < size; i++)
	{
		TMonom m = this->GetCurrentItem();
		double d = m.GetCoef();
		int ind = m.GetIndex();
		std::ostringstream output;
		output << setprecision(precision) << d;
		res += output.str() + "x" + to_string((ind - ind % 100) / 100);
		res += "y" + to_string(((ind % 100) - (ind % 10)) / 10);
		res += "z" + to_string(ind % 10);
		if (i != size - 1) {
			res += " + ";
			this->GoNext();
		}
	}
	this->Reset();
	return res;
}