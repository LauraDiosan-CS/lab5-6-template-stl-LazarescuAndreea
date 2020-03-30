#include "repoSTL.h"
#include <fstream>
#include <string>
using namespace std;

Repo::Repo()
{

}

Repo::Repo(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	int pret, nr_exemplare;
	while (!f.eof())
	{
		f >> nume >> pret >> nr_exemplare;
		if (nume != "")
		{
			Magazin m(nume, pret, nr_exemplare);
			mag.insert(m);
		}
	}
	f.close();
}

/*void Repo::load_from_file(const char* fileName)
{
	mag.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	int pret,nr_exemplare;
	while (!f.eof()) {
		f >> nume >> pret>>nr_exemplare;
		if (strcmp(nume, "") != 0) {
			Magazin m(nume, pret,nr_exemplare);
			mag.insert(m);
		}
	}
	f.close();
}*/

void Repo::add(Magazin m)
{
	mag.insert(m);
}

/*void Repo::update(Magazin m, const char* nume_nou, int pret_nou, int nr_exemplar_nou)
{
	set<Magazin>::iterator it;
	it = find(mag.begin(), mag.end(), m);
	if (it != mag.end())
	{
		(*it).set_nume(nume_nou);
		(*it).set_pret(pret_nou);
		(*it).set_nr_exemplare(nr_exemplar_nou);
	}
}*/

/*int Repo::find_elem(Magazin m)
{
	set<Magazin>::iterator it;
	it = find(mag.begin(), mag.end(), m);
	if (it != mag.end())
	{
		return distance(mag.begin(), it);
	}
	return -1;
}

int Repo::delete_elem(Magazin m)
{
	set<Magazin>::iterator it;
	it = find(mag.begin(), mag.end(), m);
	if (it != mag.end())
	{
		mag.erase(it);
		return 0;
	}
	return -1;
}
*/
set<Magazin> Repo::get_all()
{
	return mag;
}

int Repo::get_size()
{
	return mag.size();
}
/*
void Repo::save_to_file()
{
	ofstream f(fis);
	for (size_t i = 0; i < mag.size(); i++) {
		f << mag[i];
	}
	f.close();
}*/

Repo::~Repo()
{

}
