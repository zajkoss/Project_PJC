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


	deleteSpaces(mNumber);

	//Czy dodatnia?
	if (mNumber[0] == '-') {
		isPositive = false;
	}
	else {
		isPositive = true;
	}

	cout << "LOG.i(DuzaLiczba.cpp, Konstruktor char, " << mNumber << " , " << isPositive << endl;
};

DuzaLiczba::DuzaLiczba(DuzaLiczba &copy) : mNumber(copy.mNumber),mLenght(copy.mLenght),isPositive(copy.isPositive) {

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


	/*cout << "DeleteSpaces1 , " << cstr << endl;
	const int a = mLenght;
	char* output = cstr;
	for (int i = 0; i < mLenght; i++) {
		if (cstr[i] != ' ') {
			*output++ = *cstr;
		}
		cstr++;
		
	}*/
	cout << "DeleteSpaces2 , " << output << endl;
	return cstr;


}

//DuzaLiczba DuzaLiczba::add(const DuzaLiczba& addNumber) {
//
//	
//
//	/*if (this->mLenght >= addNumber.mLenght) {
//		DuzaLiczba& longerNum = *this;
//		DuzaLiczba shorterNum = addNumber;
//	}
//	else  if (this->mLenght < addNumber.mLenght) {
//		DuzaLiczba& longerNum = addNumber;
//		DuzaLiczba shorterNum = *this;
//	}*/
//
//	char* longerNum = "19999";
//		char* shorterNum = "2222";
//		bool ct_one = false;
//
//		int k = strlen(longerNum);
//		for (int i = strlen(shorterNum); i >= shorterNum[0]; i--) {
//
//
//			
//			//Konwersja
//			int a = shorterNum[i] - '0';
//			int b = longerNum[k] - '0';
//
//			cout << "Liczby : " << a << " " << b << endl;
//			if (ct_one == true) {
//				b += 1;
//				ct_one = false;
//			}
//
//			int sum = a + b;
//			cout << "Suma " << sum << endl;
//			if (sum >= 10) {
//				ct_one = true;
//				sum -= 10;
//			}
//			cout << "Suma po weryfikacji " << sum;
//			longerNum[k] = sum + '0';
//			k--;
//			
//			cout << "Pojedyncza czesc liczby " << longerNum[k] << endl;
//		}
//		cout << longerNum;
//		
//		return NULL;
//
//
//}