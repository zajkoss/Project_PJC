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
	
	
	//D³ugoœæ podanej wartoœci
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

	cout << "LOG.i(DuzaLiczba.cpp, Konstruktor char, " << mNumber << " , " << isPositive <<"," << mLenght << endl;
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

	DuzaLiczba output = *this;
	

	if (equal(substractNumber)) {
		//zwroc zerooo
	}
	// Zak³adam, ¿e zawsze wieksza jest tego samego znaku
	if (bigger(substractNumber)) {
		for (int i = substractNumber.mLenght - 1; i >= substractNumber.mNumber[0]; i--) {
			int b = substractNumber.mNumber[i] - '0';
			int a = output.mNumber[i] - '0';
			int c = a - b;
			output.mNumber[i] = c + '0';
		}
		for (int i = mLenght - 1; i >= mNumber[0]; i--) {
			
			int a = output.mNumber[i] - '0';
			if (a < 0 && i != mNumber[0]) {
				a += 10;
				int b = output.mNumber[i - 1] - '0';
				b -= 1;
				output.mNumber[i - 1] = b + '0';
			}
		}
		{
			int a = output.mNumber[0] - '0';
			if (a == 0) {
				//Nowy c-string bez pierwszego znaku
				char* tmp = new char[mLenght];
				tmp[mLenght] = 0;
				for (int i = 1; i < mLenght; i++) {
					tmp[i - 1] = output.mNumber[i];
				}
				delete[]output.mNumber;
				output.mNumber = tmp;
			}
		}


	}else {
		//substractNumber.subtract(*this).changeSign();
	}



	return output;
}

DuzaLiczba DuzaLiczba::changeSign() {

	DuzaLiczba output = *this;

	if (output.isPositive) {
		// +2    '-' and 0
		char *temporary = new char[output.mLenght + 2];
		temporary[0] = '-';
		for (int i = 0; i < output.mLenght; i++) {
			temporary[i + 1] = output.mNumber[i];
		}
		temporary[output.mLenght + 2] = 0;
		delete[] output.mNumber;
		output.mNumber = temporary;
		output.mLenght = strlen(output.mNumber);
		output.isPositive = false;

	}
	else if(!output.isPositive){
		// '-' out
		char *temporary = new char[output.mLenght ];
		for (int i = 0; i < output.mLenght; i++) {
			temporary[i] = output.mNumber[i];
		}
		temporary[output.mLenght] = 0;
		delete[] output.mNumber;
		output.mNumber = temporary;
		output.mLenght = strlen(output.mNumber);
		output.isPositive = true;
	}

	return output;

}

bool DuzaLiczba::bigger(const DuzaLiczba compare) {

	// Dodatnia , ujemna
	if (isPositive && !compare.isPositive)
		return true;
	else if (!isPositive && compare.isPositive)
		return false;

	//Dodatnie
	if (isPositive && compare.isPositive) {
		if (mLenght > compare.mLenght)
			return true;
		else if (mLenght < compare.mLenght)
			return false;
		else if (mLenght == compare.mLenght) {
			for (int i = 0; i < mLenght; i++) {
				if (mNumber[i] > compare.mNumber[i])
					return true;
				else if (mNumber[i] < compare.mNumber[i])
					return false;
			}
		}
	}

		//Ujemne
		if (!isPositive && !compare.isPositive) {
			if (mLenght > compare.mLenght)
				return false;
			else if (mLenght < compare.mLenght)
				return true;
			else if (mLenght == compare.mLenght) {
				for (int i = 1; i < mLenght; i++) {
					if (mNumber[i] > compare.mNumber[i])
						return false;
					else if (mNumber[i] < compare.mNumber[i])
						return true;
				}
			}
		}
	}


bool DuzaLiczba::equal(const DuzaLiczba compare) {

	if ((isPositive && compare.isPositive) || (!isPositive && !compare.isPositive)) {
		for (int i = 0; i < mLenght; i++) {
			if (mNumber[i] != compare.mNumber[i])
				return false;
		}
		return true;
	}
	else {
		return false;
	}

}

