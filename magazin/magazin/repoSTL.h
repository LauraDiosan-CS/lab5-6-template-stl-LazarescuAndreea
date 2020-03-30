#pragma once
#include "magazin.h"
#include <set>
using namespace std;

class Repo
{
private:
	set<Magazin> mag;
	const char* fis;
public:
	Repo();
	Repo(const char* filmeName);
	void load_from_file(const char* fileName);
	void save_to_file();
	void add(Magazin);
	void update(Magazin, const char*, int, int);
	int find_elem(Magazin);
	int delete_elem(Magazin);
	Magazin elem_at_pos(int);
	set<Magazin> get_all();
	int get_size();
	~Repo();
};