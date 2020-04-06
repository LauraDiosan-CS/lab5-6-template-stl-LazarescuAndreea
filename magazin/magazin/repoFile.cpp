#include "repoFile.h"

template <typename T>
void RepoFile<T>::loadFromFile(const char* fileName)
{
	array.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	double pret;
	int buc;
	while (!f.eof()) {
		f >> nume >> pret >> buc;
		if (strcmp(nume, "") != 0) {
			Produs s(nume, pret,buc);
			array.push_back(s);
		}
	}
	delete[] nume;
	f.close();
}