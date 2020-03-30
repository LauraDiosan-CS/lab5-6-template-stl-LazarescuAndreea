#pragma once
#include <iostream>
using namespace std;

class Magazin
{
private:
	char* nume;
	int pret;
	int nr_exemplare;
public:
	Magazin();
	Magazin(char*, int, int);
	Magazin(const Magazin&);
	~Magazin();

	char* get_nume();
	int get_pret();
	int get_nr_exemplare();

	void set_nume(const char*);
	void set_pret(int);
	void set_nr_exemplare(int);

	Magazin& operator=(const Magazin&);
	bool operator==(const Magazin&);

	friend std::ostream& operator << (std::ostream&, const Magazin&);
	friend std::istream& operator>>(istream&, Magazin&);
};