#pragma once
#include "repoSTL.h"
#include <set>
using namespace std;
class Service {
private:
	Repo<Produs> repo;
public:
	Service() {}
	~Service() {}
	void insert_service(char*, double, int);
	int get_len();
	//void updateS(Carte& s, char* nume, double pret, int buc);
	void updateS(char* nume, double pret, int buc, char* nume1, double pret1, int buc1);
	void delS(char* nume, double pret, int buc);
	int cumparare(char* nume, int buc);
	std::set<Produs> get_all();
};