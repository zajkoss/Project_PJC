#include "stdafx.h"
#include "DuzaLiczba.h"
#include "DuzaLiczbaZespolona.h"
#include <iostream>

using namespace std;

DuzaLiczbaZespolona::DuzaLiczbaZespolona(int real, int img) {
	this->real = new DuzaLiczba(real);
	this->imagine = new DuzaLiczba(img);

}
DuzaLiczbaZespolona::DuzaLiczbaZespolona(int real) {
	this->real = new DuzaLiczba(real);
	this->imagine = new DuzaLiczba("0");
}
DuzaLiczbaZespolona::DuzaLiczbaZespolona(char* real, char * img ) {
	this->real = new DuzaLiczba(real);
	this->imagine = new DuzaLiczba(img);
}
DuzaLiczbaZespolona::DuzaLiczbaZespolona(char*) {
	this->real = new DuzaLiczba(real);
	this->imagine = new DuzaLiczba("0");
}
DuzaLiczbaZespolona::DuzaLiczbaZespolona(const DuzaLiczbaZespolona& copy) {
	this->real = copy.real;
	this->imagine = copy.imagine;
}
