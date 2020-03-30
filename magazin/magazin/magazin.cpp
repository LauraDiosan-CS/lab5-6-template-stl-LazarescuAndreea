#include "magazin.h"
#include <cstring>
#include <sstream>
using namespace std;

Magazin::Magazin()
{
	this->nume = NULL;
	this->pret = -1;
	this->nr_exemplare = -1;
}

Magazin::Magazin(char* nume, int pret, int nr_exemplare)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);

	this->pret = pret;
	this->nr_exemplare = nr_exemplare;
}

Magazin::Magazin(const Magazin& m)
{
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(m.nume), nume);

	this->pret = m.pret;
	this->nr_exemplare = m.nr_exemplare;
}

char* Magazin::get_nume()
{
	return nume;
}

int Magazin::get_pret()
{
	return pret;
}

int Magazin::get_nr_exemplare()
{
	return nr_exemplare;
}

void Magazin::set_nume(const char* nume)
{
	if (this->nume) delete[]nume;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

void Magazin::set_pret(int pret)
{
	this->pret = pret;
}

void Magazin::set_nr_exemplare(int nr_exemplare)
{
	this->nr_exemplare = nr_exemplare;
}

Magazin::~Magazin()
{
	if (nume) delete[]nume;
	nume = NULL;
	pret = -1;
	nr_exemplare = -1;
}

Magazin& Magazin::operator=(const Magazin& m)
{
	if (this == &m)return *this;
	if (nume) delete[]nume;
	nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(m.nume), nume);
	pret = m.pret;
	nr_exemplare = m.nr_exemplare;
	return *this;
}

bool Magazin::operator==(const Magazin& m)
{
	return(strcmp(nume, m.nume) == 0) and (pret == m.pret) and (nr_exemplare == m.nr_exemplare);
}


ostream& operator<<(ostream& os, Magazin& m) {
	os << m.get_nume() << " " << m.get_pret() << m.get_nr_exemplare() << endl;
	return os;
}

istream& operator>>(istream& is, Magazin& m)
{
	cout << "Dati numele: ";
	char* nume = new char[10];
	is >> nume;
	cout << "Dati pretul: ";
	int pret;
	cin >> pret;
	cout << "Dati numarul exemplarelor: ";
	int nr_exemplare;
	cin >> nr_exemplare;
	m.set_nume(nume);
	m.set_pret(pret);
	m.set_nr_exemplare(nr_exemplare);
	return is;
}
