#include "magazin.h"
#include "repoSTL.h"
#include "service.h"
#include "teste.h"
#include <assert.h>
#include "ui.h"
#include <iostream>

TestServiceTemplate::TestServiceTemplate()
{
}

void TestServiceTemplate::runTests()
{
	UI ui;
	Service serv;

	char* nume1 = new char[10];
	double pret1 = 5;
	int nr_exemplare1 = 10;
	strcpy_s(nume1, sizeof  "mere", "mere");
	Produs p1(nume1, pret1, nr_exemplare1);
	serv.insert_service(nume1, pret1, nr_exemplare1);
	assert(serv.get_len() == 1);

	char* nume2 = new char[10];
	double pret2 = 10;
	int nr_exemplare2 = 15;
	strcpy_s(nume2, sizeof  "capsuni", "capsuni");
	Produs p2(nume2, pret2, nr_exemplare2);
	serv.insert_service(nume2, pret2, nr_exemplare2);
	assert(serv.get_len() == 2);

	serv.delS(nume2, pret2, nr_exemplare2);
	assert(serv.get_len() == 1);

	char* nume = new char[10];
	strcpy_s(nume, sizeof  "capsuni", "capsuni");
	int nr_exemplare = 10;
	Produs prod[10], results[10];
	int buc = 1;
	int len = 0;
	int ok_prod[10];
	/*serv.cumparare(buc, prod, len, results, ok_prod);*/
	std::cout << "Testele au fost terminate cu succes! " << endl;
}


TestServiceTemplate::~TestServiceTemplate()
{
}
