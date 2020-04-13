#include "ui.h"
#include "repoSTL.h"
#include <iostream>
#include <string>
#include <ctime>
#include "teste.h"

using namespace std;

char* allocate_memory()
{
    char* name = new char[0];
    string string_name;

    cin >> string_name;
    name = new char[string_name.size() + 1];
    strcpy_s(name, 1 + string_name.size(), string_name.c_str());

    return name;
}



void UI::add() {

    char* name = new char[0];
    double price;
    int buc;
    cout << "Dati nume produs: ";
    name = allocate_memory();

    cout << "Dati pret: ";
    cin >> price;

    cout << "Dati numar exemplare: ";
    cin >> buc;
    cout << endl;

    this->service.insert_service(name, price, buc);
}

void UI::update()
{
    char* nume = new char[0];
    char* newNume = new char[0];
    double newPret;
    int newBuc;

    cout << "Dati numele produsului de modificat: ";
    nume = allocate_memory();
    double pret = 0;
    int buc = 0;

    cout << "Dati un nume produs dupa update: ";
    newNume = allocate_memory();
    cout << "Dati noul pret: ";
    cin >> newPret;
    cout << "Dati noul numar de exemplare: ";
    cin >> newBuc;
    cout << endl;

    service.updateS(nume, pret, buc, newNume, newPret, newBuc);
    cout << "Produs modificat cu succes!" << endl;
}

void UI::deleteS()
{
    char* nume = new char[0];
    double pret = 0;
    int buc = 0;

    cout << "Dati numele produsului de sters: ";
    nume = allocate_memory();

    service.delS(nume, pret, buc);
    cout << "Produs sters!" << endl;
}

void UI::print()
{
    set<Produs> all_elem = service.get_all();
    for (Produs b : all_elem)
        cout << b;
    cout << endl;
}

void UI::cumparareProdus()
{
    int number_of_products, i, price = 0, number, len = 0, ok_product[100];
    char* nume = new char[0];
    Produs products[100], results[100];
    cout << " Cate produse vreti sa cumparati? ";
    cin >> number_of_products;
    for (i = 0; i < number_of_products; i++)
    {
        cout << endl << " Dati numele produsului: ";
        nume = allocate_memory();
        cout << " Cate bucati vreti sa cumparati? ";
        cin >> number;
        Produs product(nume, price, number);
        products[i] = product;
    }
    service.cumparare(number_of_products, products, len, results, ok_product);
    for (i = 0; i < len; i++)
    {
        Produs curentProduct = results[i];
        if (curentProduct.get_pret() == 0)
        {
            if (ok_product[i] == 0)
            {
                cout << endl << " Produsul nu a fost cumparat! " << endl;
            }
        }
        else
        {
            if (ok_product[i] == 1)
            {
                cout << "Produsul a fost cumparat!" << endl;
            }
        }
    }

}

void UI::returnareProdus()
{
    int number_of_products, i, price = 0, number, lenght = 0, ok_product[100], ok_name[100];
    char* name = new char[20];
    Produs products[100], results[100];
    cout << " Cate produse vreti sa returnati? ";
    cin >> number_of_products;
    for (i = 0; i < number_of_products; i++)
    {
        cout << endl << " Dati numele: ";
        cin >> name;
        cout << " Dati numarul de bucati: ";
        cin >> number;
        Produs product(name, price, number);
        products[i] = product;
    }

    service.returnElem(number_of_products, products, lenght, results, ok_product, ok_name);
    for (i = 0; i < lenght; i++)
    {
        Produs curentProduct = results[i];
        if (curentProduct.get_pret() == 0)
        {
            if (ok_product[i] == 0)
            {
                cout << endl << " Produsul nu a fost returnat! " << endl;
            }
        }
        else
        {
            if (ok_product[i] == 1)
            {
                cout << endl << " Produsul a fost returnat! " << endl;
            }
        }
    }
}

void UI::run() 
{
    TestServiceTemplate test;
    test.runTests();
    string op;
    bool ok = true;
    while (ok)
    {
        cout << "Alege o optiune: " << endl;
        std::cout << "x. Exit" << std::endl;
        std::cout << "1. Adaugare" << std::endl;
        std::cout << "2. Afisare" << std::endl;
        std::cout << "3. Modificare" << std::endl;
        std::cout << "4. Stergere" << std::endl;
        std::cout << "5. Cumparare produs" << std::endl;
        std::cout << "6. Returnare produs produs" << std::endl;
        cout << "Optiunea este: ";
        cin >> op;
        if (op.size() == 1)
        {
            if (op[0] == '1') this->add();
            else if (op[0] == '2') this->print();
            else if (op[0] == '3') this->update();
            else if (op[0] == '4') this->deleteS();
            else if (op[0] == '5') this->cumparareProdus();
            else if (op[0]=='6') this->returnareProdus();
            else if (op[0] == 'x') ok = false;
            else cout << "Invalid option!" << endl;
        }
        else
            cout << "Invalid option!" << endl;
    }
}