#pragma once
#include "repoSTL.h"
template <class T>
class RepoFile:
	public Repo<T>
{
private:
	const char* fis;
public:
	RepoFile() {};
	RepoFile(const char* fis);
	~RepoFile();
	void loadFromFile();
	void setFileNameIn(const char* fis);
	void saveToFile();
	void addElement(T elem);
	void updateS(T elem, T newElem);
	void delS(T elem);
};

template <class T>
RepoFile<T>::RepoFile(const char* fileName)
{
	this->fis = new char[strlen(fis) + 1];
	strcpy_s(this->fis, strlen(fis) + 1, fis);
	this->loadFromFile();
}

template <class T>
RepoFile<T>::~RepoFile()
{
	this->elem.clear();
}

template <class T>
void RepoFile<T>::setFileNameIn(const char* fis)
{
	if (this->fis != NULL)
	{
		delete[]this->fis;
	}
	this->fis = new char[strlen(fis) + 1];
	strcpy_s(this->fis, strlen(fis) + 1, fis);
}

template <class T>
void RepoFile<T>::loadFromFile()
{
	if (this->fis != NULL)
	{
		this->elem.clear();
		ifstream f(this->fis);
		T elem;
		while (f >> elem)
		{
			this->addElem(elem);
		}
		f.close();
	}
}

template <class T>
void RepoFile<T>::saveToFile()
{
	if (this->fis != NULL)
	{
		ofstream f(this->fis);
		for (size_t i = 0; i < this->elements.size(); i++)
		{
			f << this->elements[i] << endl;
		}
		f.close();
	}
}

template <class T>
void RepoFile<T>::addElement(T elem) {
	Repo::insert(elem);
	this->saveToFile();
}

template <class T>
void RepoFile<T>::delS(T elem) {
	Repo::delS(elem);
	this->saveToFile();
}
template <class T>
void RepoFile<T>::updateS(T elem,T newElem) {
	Repo::updateS(elem,newElem);
	this->saveToFile();
}