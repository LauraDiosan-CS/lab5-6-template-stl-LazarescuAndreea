#pragma once
#include "magazin.h"
#include <set>
#include <iterator>

using namespace std;

template <class T>
class Repo 
{
private:
	std::set <T> array;
public:
	Repo();
	~Repo();
	void insert(T);
	int get_len();
	void updateS(T, T);
	void delS(T);
	std::set<T> get_all();
	int findElem(const T& s);
	T elemAtPos(int i);
};

template <class T>
Repo<T>::Repo() {
}
template <class T>
Repo<T>::~Repo() {
}
template <class T>
void Repo<T>::insert(T s) {
	this->array.insert(s);
}
template <class T>
int Repo<T>::get_len() {
	return this->array.size();
}
template <class T>
std::set<T> Repo<T>::get_all() {
	return this->array;
}
template <class T>
void Repo<T>::updateS(T s, T s1)
{
	array.erase(s);
	array.insert(s1);
}
template <class T>
void Repo<T>::delS(T s)
{
	array.erase(s);
}

template<class T>
int Repo<T>::findElem(const T& s)
{
	typename set<T>::iterator it = std::find(array.begin(), array.end(), s);
	if (it != array.end())
		return distance(array.begin(), it);
	return -1;
}

template<class T>
T Repo<T>::elemAtPos(int i)
{
	typename set<T>::iterator it;
	int j = 0;
	for (it = array.begin(); it != array.end(); ++it)
	{
		if (j == i)
			return *it;
		j++;
	}
}