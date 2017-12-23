#pragma once

#include <iostream>
using namespace std;

class DuzaLiczba {
private: 
	bool isPositive;
	char* mNumber;
	int mLenght;

	bool valid(char* cstr);
	char* copyString(const char* cstr);
	char* deleteSpaces(char* cstr);
	//DuzaLiczba add(const DuzaLiczba &addNumber);

public:
	DuzaLiczba(int number);
	DuzaLiczba(char* number = "0");
	DuzaLiczba(DuzaLiczba &copy);
	
	friend istream& operator>>(istream&, const DuzaLiczba&);
	friend ostream& operator<<(ostream&, const DuzaLiczba&);


};