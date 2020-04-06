#include "service.h"
#include "magazin.h"
#include <cstring>
#include <set>
using namespace std;
void Service::insert_service(char* nume, double pret, int buc)
{
	Produs shop(nume, pret, buc);
	repo.insert(shop);
}
std::set<Produs> Service::get_all()
{
	return this->repo.get_all();
}
int Service::get_len()
{
	return this->repo.get_len();
}
void Service::updateS(char* nume, double pret, int buc, char* nume1, double pret1, int buc1)
{
	Produs s(nume, pret, buc);
	Produs s1(nume1, pret1, buc1);
	repo.updateS(s, s1);
}
void Service::delS(char* nume, double pret, int buc)
{
	Produs s(nume, pret, buc);
	repo.delS(s);
}

int Service::cumparare(char* nume, int buc)
{
	Produs s(nume, 0, buc);
	if (repo.cumparare(s) == 0)
	{
		return 0;
	}
	return -1;
}