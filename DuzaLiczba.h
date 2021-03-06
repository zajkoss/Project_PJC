#pragma once

#include <iostream>
#include "Liczba.h"
using namespace std;

class DuzaLiczba : public Liczba {
private: 
	bool dodatnia;
	char* wartosc;
	int mLenght;

	char* copyString(const char* cstr);
	char* deleteSpaces(char* cstr);
	
	DuzaLiczba add(const DuzaLiczba &addNumber) const;
	DuzaLiczba subtract(const DuzaLiczba &addNumber) const;
	DuzaLiczba multiply(const DuzaLiczba &addNumber) const;
	DuzaLiczba divide(const DuzaLiczba &addNumber) const;
	bool bigger(const DuzaLiczba& compare) const;
	bool equal(const DuzaLiczba &compare) const;
	DuzaLiczba changeSign() const;

public:
	DuzaLiczba(int number);
	DuzaLiczba(char* number = "0");
	DuzaLiczba(const DuzaLiczba &copy);

	//virtual ~DuzaLiczba();
	
	friend istream& operator>>(istream&, const DuzaLiczba&);
	friend ostream& operator<<(ostream&, const DuzaLiczba&);

	DuzaLiczba operator+(const DuzaLiczba&) ;
	DuzaLiczba operator-(const DuzaLiczba&) ;
	DuzaLiczba operator*(const DuzaLiczba&) ;
	DuzaLiczba operator/(const DuzaLiczba&) ;

	DuzaLiczba & operator+=(const DuzaLiczba& value);
	DuzaLiczba & operator-=(const DuzaLiczba& value);
	DuzaLiczba & operator*=(const DuzaLiczba& value);
	DuzaLiczba & operator/=(const DuzaLiczba& value);

	friend bool operator!=(const DuzaLiczba &a, const DuzaLiczba &b);
	friend bool operator==(const DuzaLiczba &a , const DuzaLiczba &b);
	friend bool operator>=(const DuzaLiczba &a , const DuzaLiczba &b);
	friend bool operator<(const DuzaLiczba &a , const DuzaLiczba &b);
	friend DuzaLiczba operator!(const DuzaLiczba & a);
	friend DuzaLiczba operator-(const DuzaLiczba & a);

	DuzaLiczba& operator=(const DuzaLiczba& value);

	virtual char* Wartosc();
};