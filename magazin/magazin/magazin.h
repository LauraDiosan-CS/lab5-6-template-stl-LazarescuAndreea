#pragma once
#include <ostream>
class Produs 
{
private:
	char* nume;
	double pret;
	int buc;
public:
	Produs();
	Produs(char*, double, int);
	Produs(const Produs&);
	~Produs();
	
	char* get_nume();
	double get_pret();
	int get_buc();
	
	void set_nume(char*);
	void set_pret(double);
	void set_buc(int);
	
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