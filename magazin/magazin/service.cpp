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

void Service::cumparare(int& n, Produs products[], int& len, Produs results[], int ok_product[])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		Produs p = products[i];
		double price = 0;
		int ok = 0;
		for (j = 0; j < get_len(); j++)
		{
			Produs crtProduct = repo.elemAtPos(j);
			if ((strcmp(crtProduct.get_nume(), p.get_nume()) == 0) && (crtProduct.get_buc() >= p.get_buc()))
			{
				ok_product[i] = 1;
				price = crtProduct.get_pret();
				ok = 1;
				crtProduct.set_buc(crtProduct.get_buc() - p.get_buc());
				Produs newProduct(crtProduct.get_nume(), crtProduct.get_pret(), crtProduct.get_buc());
				repo.updateS(crtProduct, newProduct);
				break;
			}

			if ((strcmp(crtProduct.get_nume(), p.get_nume()) == 0) && (crtProduct.get_buc() < p.get_buc()))
			{
				ok_product[i] = 0;
				price = 0;
				ok = -1;
				break;
			}
		}
		if (ok == 1)
		{
			Produs yesProduct(p.get_nume(), price, p.get_buc());
			results[len++] = yesProduct;
		}

		if (ok == -1)
		{
			Produs notProduct(p.get_nume(), 0, p.get_buc());
			results[len++] = notProduct;
		}

		if (ok == 0)
		{
			Produs notProduct(p.get_nume(), 0, p.get_buc());
			results[len++] = notProduct;
			ok_product[i] = 0;
		}
	}
}

void Service::returnElem(int& n, Produs products[], int& len, Produs results[], int ok_product[], int ok_name[])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		Produs curentProduct = products[i];
		double price = 0;
		bool ok = 0;
		for (j = 0; j < get_len(); j++)
		{
			Produs crtProduct = repo.elemAtPos(j);

			if ((strcmp(crtProduct.get_nume(), curentProduct.get_nume()) == 0))
			{
				ok_product[i] = 1;
				ok_name[i] = 1;
				price = crtProduct.get_pret();
				ok = 1;
				crtProduct.set_buc(crtProduct.get_buc() + curentProduct.get_buc());
				Produs newProduct(crtProduct.get_nume(), crtProduct.get_pret(), crtProduct.get_buc());
				repo.updateS(crtProduct, newProduct);
				break;
			}
		}

		if (ok == 1)
		{

			Produs yesProduct(curentProduct.get_nume(), price, curentProduct.get_buc());
			results[len++] = yesProduct;
		}

		if (ok == 0)
		{
			Produs notProduct(curentProduct.get_nume(), 0, curentProduct.get_buc());
			results[len++] = notProduct;
			ok_product[i] = 0;
			ok_name[i] = 0;
		}
	}
}