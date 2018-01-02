#pragma once

#include "DuzaLiczba.h"
#include <iostream>
using namespace std;

class DuzaLiczbaZespolona {
	DuzaLiczba *real;
	DuzaLiczba *imagine;


public:
	//TO-PRIVATE
	DuzaLiczbaZespolona(int, int = 0);
	DuzaLiczbaZespolona(char* = "0", char * = "0");
	DuzaLiczbaZespolona(const DuzaLiczbaZespolona& copy);

};
