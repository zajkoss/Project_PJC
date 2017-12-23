#include "stdafx.h"
#include "DuzaLiczba.h"

#include <iostream>
#include <string>

using namespace std;


DuzaLiczba::DuzaLiczba(int number) {


	//Konwersja Integer na C-String 
	string s = to_string(number);
	char const* tmp_number = s.c_str();
	mNumber = copyString(tmp_number);
	
	
	//D�ugo�� podanej warto�ci
	mLenght = strlen(mNumber);

	//Czy dodatnia?
	if(mNumber[0] == '-'){
		isPositive = false;
	} else {
		isPositive = true;
	}

	cout << "LOG.i(DuzaLiczba.cpp, Konstruktor int, " << mNumber << " , " << isPositive << endl;
};

DuzaLiczba::DuzaLiczba(char* number) : mNumber(number),mLenght(strlen(number))  {	

	//Ewentulane spacje
	mNumber = deleteSpaces(mNumber);
	mLenght = strlen(mNumber);

	//Check 
	

	//Czy dodatnia?
	if (mNumber[0] == '-') {
		isPositive = false;
	}
	else {
		isPositive = true;
	}

	cout << "LOG.i(DuzaLiczba.cpp, Konstruktor char, " << mNumber << " , " << isPositive << endl;
};

DuzaLiczba::DuzaLiczba(const DuzaLiczba &copy) : mNumber(copy.mNumber),mLenght(copy.mLenght),isPositive(copy.isPositive) {

	cout << "LOG.i(DuzaLiczba.cpp, Konstruktor copy, " << mNumber << " , " << isPositive << endl;

}

//Walidacja c-stringa 
bool DuzaLiczba::valid(char* cstr) {

	if (cstr[0] = '-' || isdigit(cstr[0])) {
		cstr++;
		while (*cstr != 0) {
			if (!isdigit(*cstr)) {
				cout << "LOG.i(DuzaLiczba.cpp, Walidacja negatywna, " << endl;
				return false;
			}
			cstr++;
		}
	}
	else {
		cout << "LOG.i(DuzaLiczba.cpp, Walidacja negatywna, " << endl;
		return false;
	}

	cout << "LOG.i(DuzaLiczba.cpp, Walidacja pozytywna, " << endl;
	return true;
	
}

char* DuzaLiczba::copyString(const char* cstr) {
	int length = strlen(cstr);
	char * justCstr = new char[length + 1];
	strcpy_s(justCstr, length + 1, cstr );
	return justCstr;
}

char* DuzaLiczba::deleteSpaces(char* cstr) {


	cout << "deletespaces1 , " << cstr << endl;
	int length = 0;
	for (int i = 0; i < mLenght; i++) {
		if (cstr[i] != ' ') {
			length++;
		}
	}

	char* output = new char[length+1];

	int k = 0;
	for (int i = 0; i < mLenght; i++) {
		if (cstr[i] != ' ') {
			output[k++] = cstr[i];
		}
	}

	output[k] = 0;
	cout << "deletespaces2 , " << output << endl;
	return output;


}

//=============== OPERATORY IN/OUT ==================

ostream& operator<<(ostream& stream, const DuzaLiczba& item) {
	stream << item.mNumber;
	return stream;
}

istream& operator>>(istream& stream, const DuzaLiczba& item) {
	stream >> item.mNumber;
	return stream;
}

DuzaLiczba DuzaLiczba::add(const DuzaLiczba& addNumber) {

	DuzaLiczba longerNum;
	DuzaLiczba shorterNum;


	if (this->mLenght >= addNumber.mLenght) {
		 longerNum = *this;
		 shorterNum = addNumber;
	}
	else  if (this->mLenght < addNumber.mLenght) {
		 longerNum = addNumber;
		 shorterNum = *this;
	}

	int j = longerNum.mLenght - 1;
	bool ct_one = false;
	for (int i = shorterNum.mLenght-1; i >=0 ; i--) {

		int a = shorterNum.mNumber[i] - '0';
		int b = longerNum.mNumber[j] - '0';
		int c = a + b;
		//cout << c << "=" << a << "+" << b << endl;
	
		if (ct_one == true) {
			c += 1;
			ct_one = false;
		}
		//cout << c << endl;

		if (c >= 10) {
			ct_one = true;
			c -= 10;
		}
		cout << c  ;
	
		longerNum.mNumber[j--] = c + '0';
		
	}

	
	if (ct_one == true) {
		int b = longerNum.mNumber[j] - '0';
		b += 1;
		if (b >= 10) {
			b -= 10;
			//zrzut
			longerNum.mNumber[j] = b + '0';
			int x = longerNum.mNumber[j-1] - '0';
			x += 1;
			//zrzut
			longerNum.mNumber[j-1] = x + '0';
		}
		else {
			longerNum.mNumber[j] = b + '0';
		}

		
	}
	cout << endl;
	cout << longerNum;
	//cout << endl;
	//cout << shorterNum;
	cout << endl;

	return *this;
}

DuzaLiczba DuzaLiczba::subtract(const DuzaLiczba substractNumber) {

	DuzaLiczba longerNum;
	DuzaLiczba shorterNum;

	if (this->mLenght >= substractNumber.mLenght) {
		longerNum = *this;
		shorterNum = substractNumber;
	}
	else  if (this->mLenght < substractNumber.mLenght) {
		longerNum = substractNumber;
		shorterNum = *this;
	}

	int j = longerNum.mLenght - 1;
	bool ct_one = false;
	for (int i = shorterNum.mLenght - 1; i >= 0; i--) {




		int a = shorterNum.mNumber[i] - '0';
		int b = longerNum.mNumber[j] - '0';

		if (ct_one == true) {
			b -= 1;
			ct_one = false;
		}

		if (b < a) {
			b += 10;
			ct_one = true;

		}
		int c = b - a;

		

		
		longerNum.mNumber[j--] =  c + '0';
	}

	/*if (ct_one == true) {
		int b = longerNum.mNumber[j] - '0';
		b += 1;
		if (b >= 10) {
			b -= 10;
			longerNum.mNumber[j] = b + '0';
			int x = longerNum.mNumber[j - 1] - '0';
			x += 1;
			longerNum.mNumber[j - 1] = x + '0';
		}
		else {
			longerNum.mNumber[j] = b + '0';
		}
	}*/
	cout << longerNum;
	cout << endl;
	return longerNum;
}