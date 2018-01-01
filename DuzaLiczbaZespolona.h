#pragma once

#include "DuzaLiczba.h"
#include <iostream>
using namespace std;

class DuzaLiczbaZespolona {
	DuzaLiczba *real;
	DuzaLiczba *imagine;


public:
	//TO-PRIVATE
	DuzaLiczbaZespolona(int, int);
	DuzaLiczbaZespolona(int);
	DuzaLiczbaZespolona(char* = "0", char * = "0");
	DuzaLiczbaZespolona(char*);
	DuzaLiczbaZespolona(const DuzaLiczbaZespolona& copy);

};
