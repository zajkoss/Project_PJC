#include "stdafx.h"
#include "DuzaLiczba.h"
#include "DuzaLiczbaZespolona.h"
#include <iostream>

using namespace std;

DuzaLiczbaZespolona::DuzaLiczbaZespolona(int r, int img) {
	real = new DuzaLiczba(r);
	imagine = new DuzaLiczba(img);
	cout << "KONSTRUKTOR INT " << *(this->real) << " "  << *(this->imagine) << endl;
	
}

DuzaLiczbaZespolona::DuzaLiczbaZespolona(char* real, char * img ) {
	this->real = new DuzaLiczba(real);
	this->imagine = new DuzaLiczba(img);
	cout << "KONSTRUKTOR CHAR " << *(this->real) << " " << *(this->imagine) << endl;
}

DuzaLiczbaZespolona::DuzaLiczbaZespolona(const DuzaLiczbaZespolona& copy) {
	this->real = copy.real;
	this->imagine = copy.imagine;
	cout << "KONSTRUKTOR COPY " << *(this->real) << " " << *(this->imagine) << endl;
}




ostream& operator<<(ostream& stream, const DuzaLiczbaZespolona& item) {
	stream << *(item.real) << "," << *(item.imagine) << endl;;
	return stream;
}

istream& operator>>(istream& stream, const DuzaLiczbaZespolona& item) {
	stream >> *(item.real);
	stream >> *(item.imagine);
	return stream;
}

DuzaLiczbaZespolona& DuzaLiczbaZespolona::operator=(const DuzaLiczbaZespolona& value) {
	this->real = new DuzaLiczba(*(value.real));
	this->imagine = new DuzaLiczba(*(value.imagine));
	return *this;
}

DuzaLiczbaZespolona& DuzaLiczbaZespolona::operator=(const DuzaLiczba& value) {
	this->real = new DuzaLiczba(value);
	return *this;
}

// DELETE STARE WARTOSCI??/
DuzaLiczbaZespolona DuzaLiczbaZespolona::operator+(const DuzaLiczbaZespolona& value) {
	DuzaLiczbaZespolona output;
	output.imagine = new DuzaLiczba(*(this->imagine)+(*(value.imagine)));
	output.real = new DuzaLiczba(*(this->real)+ (*(value.real)));
	return output;

}

DuzaLiczbaZespolona operator-(const DuzaLiczbaZespolona & a) {
	DuzaLiczbaZespolona output;
	*output.real = *a.real * *a.minus;
	*output.imagine = *a.imagine * * a.minus;
	return output;
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator-(const DuzaLiczbaZespolona& value) {
	DuzaLiczbaZespolona output;
	output.imagine = new DuzaLiczba(*(this->imagine) - (*(value.imagine)));
	output.real = new DuzaLiczba(*(this->real) - (*(value.real)));
	return output;
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator*(const DuzaLiczbaZespolona& value) {
	DuzaLiczbaZespolona output;
	output.real = new DuzaLiczba((*(this->real) * (*(value.real))) - (*this->imagine) * (*(value.imagine)));
	output.imagine = new DuzaLiczba( ((*this->imagine)*(*(value.real)))   + (*(this->real) * (*(value.imagine))));

	return output;
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator/(const DuzaLiczbaZespolona& value) {
	DuzaLiczbaZespolona output;
	output.real = new DuzaLiczba((((*(this->real)) * (*(value.real))) + ((*(this->imagine))*(*(value.imagine)))) / (((*(value.real))*(*(value.real))) + ((*(value.imagine))*(*(value.imagine)))));
	output.imagine = new DuzaLiczba((((*(this->imagine))*(*(value.real))) - ((*(this->real))* (*(value.imagine)))) / (((*(value.real))*(*(value.real))) + ((*(value.imagine))*(*(value.imagine)))));
	return output;
}

DuzaLiczbaZespolona & DuzaLiczbaZespolona::operator+=(const DuzaLiczbaZespolona& value) {
	this->imagine = new DuzaLiczba(*(this->imagine) + (*(value.imagine)));
	this->real = new DuzaLiczba(*(this->real) + (*(value.real)));
	return *this;
}

DuzaLiczbaZespolona & DuzaLiczbaZespolona::operator-=(const DuzaLiczbaZespolona& value) {
	this->imagine = new DuzaLiczba(*(this->imagine) - (*(value.imagine)));
	this->real = new DuzaLiczba(*(this->real) - (*(value.real)));
	return *this;

}

DuzaLiczbaZespolona & DuzaLiczbaZespolona::operator*=(const DuzaLiczbaZespolona& value) {
	this->real = new DuzaLiczba((*(this->real) * (*(value.real))) - (*this->imagine) * (*(value.imagine)));
	this->imagine = new DuzaLiczba(((*this->imagine)*(*(value.real))) + (*(this->real) * (*(value.imagine))));
	return *this;

}

DuzaLiczbaZespolona & DuzaLiczbaZespolona::operator/=(const DuzaLiczbaZespolona& value) {
	this->real = new DuzaLiczba((((*(this->real)) * (*(value.real))) + ((*(this->imagine))*(*(value.imagine)))) / (((*(value.real))*(*(value.real))) + ((*(value.imagine))*(*(value.imagine)))));
	this->imagine = new DuzaLiczba((((*(this->imagine))*(*(value.real))) - ((*(this->real))* (*(value.imagine)))) / (((*(value.real))*(*(value.real))) + ((*(value.imagine))*(*(value.imagine)))));
	return *this;

}

bool operator==(const DuzaLiczbaZespolona &a, const DuzaLiczbaZespolona &b){
	if (*a.real == *b.real && *a.imagine == *b.imagine)
		return true;
	else
		return false;

}

bool operator!=(const DuzaLiczbaZespolona &a, const DuzaLiczbaZespolona &b) {
	if (*a.real != *b.real || *a.imagine != *b.imagine)
		return true;
	else
		return false;
}

bool operator>=(const DuzaLiczbaZespolona &a, const DuzaLiczba &b) {
	if (*a.real >= b)
		return true;
	else
		return false;
}

bool operator<(const DuzaLiczbaZespolona &a, const DuzaLiczba &b) {
	if (*a.real < b)
		return true;
	else
		return false;
}
