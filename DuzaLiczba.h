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
	

public:
	DuzaLiczba(int number);
	DuzaLiczba(char* number = "0");
	DuzaLiczba(const DuzaLiczba &copy);
	
	friend istream& operator>>(istream&, const DuzaLiczba&);
	friend ostream& operator<<(ostream&, const DuzaLiczba&);


	//TO-PRIVATE
	DuzaLiczba add(const DuzaLiczba &addNumber);
	DuzaLiczba subtract(const DuzaLiczba addNumber);
	bool bigger(const DuzaLiczba compare);
	bool equal(const DuzaLiczba compare);
	DuzaLiczba changeSign();

};