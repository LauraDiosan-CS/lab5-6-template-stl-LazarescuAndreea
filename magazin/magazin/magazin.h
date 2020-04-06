#pragma once
#include <ostream>
class Produs {
private:
	char* nume;
	double pret;
	int buc;
public:
	Produs();//constructor implicit
	Produs(char*, double, int);//constructor de initializare
	Produs(const Produs&);//constructor de copiere
	~Produs();//destructor
	//Getters
	char* get_nume();
	double get_pret();
	int get_buc();
	//Setters
	void set_nume(char*);
	void set_pret(double);
	void set_buc(int);
	//Overwrite operators '=' , "==" and "<<"
	Produs& operator =(const Produs&);
	bool operator==(const Produs&) const;
	bool operator!=(const Produs&) const;
	bool operator<(const Produs&) const;
	bool operator<=(const Produs&) const;
	bool operator>(const Produs&) const;
	bool operator>=(const Produs&) const;
	friend std::ostream& operator << (std::ostream&, const Produs);
	friend std::istream& operator >> (std::istream&, const Produs&);
};