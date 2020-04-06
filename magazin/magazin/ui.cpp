#include "ui.h"
#include "verifyy.h"
#include "repoSTL.h"
#include <iostream>
#include <string>
#include <ctime>

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
    double pret;
    int buc;
    char* newNume = new char[0];
    double newPret;
    int newBuc;

    cout << "Dati nume produs: ";
    nume = allocate_memory();

    cout << "Dati pret: ";
    cin >> pret;
    //cout << endl;

    cout << "Dati numar exemplare produs: ";
    cin >> buc;
    cout << endl;

    cout << "Dati un nume produs dupa update: ";
    newNume = allocate_memory();

    cout << "Dati pret: ";
    cin >> newPret;
    // cout << endl;

    cout << "Dati numar exemplare produs: ";
    cin >> newBuc;
    cout << endl;

    service.updateS(nume, pret, buc, newNume, newPret, newBuc);
    cout << "------Produs modificat cu succes------" << endl;
}

void UI::deleteS()
{
    char* nume = new char[0];
    double pret;
    int buc;

    cout << "Dati un nume produs pentru stergere: ";
    nume = allocate_memory();

    cout << "Dati pret: ";
    cin >> pret;
    //cout << endl;

    cout << "Dati numar exemplare produs: ";
    cin >> buc;
    cout << endl;

    service.delS(nume, pret, buc);
    cout << "------Produs sters------" << endl << endl;
}

void UI::print() {

    //int n = this->service.get_len();
    set<Produs> all_elem = service.get_all();
    for (Produs b : all_elem)
        cout << b << endl;
}

void UI::cumparareProdus()
{
    char* nume = new char[0];
    int buc;
    cout << "Dati numele produsului pe care vreti sa il cumparati: ";
    cin >> nume;
    cout << "Dati numarul de exemplare pe care vreti sa le cumparati: ";
    cin >> buc;
    if (service.cumparare(nume, buc) == 0) cout << "Cumparare efectuata cu succes!";
    else cout << "Nu exista in stoc atatea exemplare!";
}

void UI::run() {

    string opt;
    bool ok = true;
    //Shop* undo_array = new Shop[0];

    do {
        cout << endl << "Alege o optiune: " << endl;
        menu();
        cout << "Optiunea este: ";
        cin >> opt;

        if (opt.size() == 1)
        {
            if (opt[0] == '1')
            {
                this->add();
            }
            else
                if (opt[0] == '2')
                {
                    this->print();
                }
                else
                    if (opt[0] == '3')
                    {
                        this->update();
                    }
                    else
                        if (opt[0] == '4')
                        {
                            this->deleteS();
                        }
                        else
                            if (opt[0] == '5')
                            {
                                this->cumparareProdus();
                            }
                            if (opt[0] == 'x')
                            {
                                ok = false;
                            }
                            else
                                cout << endl << "Invalid option!" << endl;

        }
        else
            cout << endl << "Invalid option!" << endl;
    } while (ok);
}