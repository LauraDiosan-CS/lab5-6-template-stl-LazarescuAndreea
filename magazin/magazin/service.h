#pragma once
#include "repoSTL.h"
#include "repoFile.h"
#include <set>
using namespace std;

class Service 
{
private:
	Repo<Produs> repo;
public:
	Service() {}
	~Service() {}
	void insert_service(char*, double, int);
	int get_len();
	void updateS(char* nume, double pret, int buc, char* nume1, double pret1, int buc1);
	void delS(char* nume, double pret, int buc);
	void cumparare(int& n, Produs products[], int& len, Produs results[], int ok_product[]);
	void returnElem(int& n, Produs products[], int& len, Produs results[], int ok_product[], int ok_name[]);
	set<Produs> get_all();
};