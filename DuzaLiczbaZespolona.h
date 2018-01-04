#pragma once

#include "Liczba.h"
#include "DuzaLiczba.h"
#include <iostream>

using namespace std;

class DuzaLiczbaZespolona  {
	DuzaLiczba *real;
	DuzaLiczba *imagine;
	DuzaLiczba * minus = new DuzaLiczba("-1");

public:
	DuzaLiczbaZespolona(int, int = 0);
	DuzaLiczbaZespolona(char* = "0", char * = "0");
	DuzaLiczbaZespolona(const DuzaLiczbaZespolona& copy);

	//virtual ~DuzaLiczbaZespolona();

	friend istream& operator>>(istream&, const DuzaLiczbaZespolona&);
	friend ostream& operator<<(ostream&, const DuzaLiczbaZespolona&);

	DuzaLiczbaZespolona operator+(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona operator-(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona operator*(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona operator/(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona& operator=(const DuzaLiczbaZespolona& value);
	DuzaLiczbaZespolona& operator=(const DuzaLiczba& value);
	friend DuzaLiczbaZespolona operator-(const DuzaLiczbaZespolona & a);

	DuzaLiczbaZespolona & operator+=(const DuzaLiczbaZespolona& value);
	DuzaLiczbaZespolona & operator-=(const DuzaLiczbaZespolona& value);
	DuzaLiczbaZespolona & operator*=(const DuzaLiczbaZespolona& value);
	DuzaLiczbaZespolona & operator/=(const DuzaLiczbaZespolona& value);

	friend bool operator!=(const DuzaLiczbaZespolona &a, const DuzaLiczbaZespolona &b);
	friend bool operator==(const DuzaLiczbaZespolona &a, const DuzaLiczbaZespolona &b);
	friend bool operator>=(const DuzaLiczbaZespolona &a, const DuzaLiczba &b);
	friend bool operator<(const DuzaLiczbaZespolona &a, const DuzaLiczba &b);

	virtual char* Wartosc();

};
