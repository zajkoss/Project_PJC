#pragma once

#include "DuzaLiczba.h"
#include <iostream>
using namespace std;

class DuzaLiczbaZespolona {
	DuzaLiczba *real;
	DuzaLiczba *imagine;
	DuzaLiczba * minus = new DuzaLiczba("-1");

public:
	//TO-PRIVATE
	DuzaLiczbaZespolona(int, int = 0);
	DuzaLiczbaZespolona(char* = "0", char * = "0");
	DuzaLiczbaZespolona(const DuzaLiczbaZespolona& copy);
	//


	friend istream& operator>>(istream&, const DuzaLiczbaZespolona&);
	friend ostream& operator<<(ostream&, const DuzaLiczbaZespolona&);

	DuzaLiczbaZespolona operator+(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona operator-(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona operator*(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona operator/(const DuzaLiczbaZespolona&);
	DuzaLiczbaZespolona& operator=(const DuzaLiczbaZespolona& value);


	DuzaLiczbaZespolona & operator+=(const DuzaLiczbaZespolona& value);
	DuzaLiczbaZespolona & operator-=(const DuzaLiczbaZespolona& value);
	DuzaLiczbaZespolona & operator*=(const DuzaLiczbaZespolona& value);
	DuzaLiczbaZespolona & operator/=(const DuzaLiczbaZespolona& value);

};
