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

	//cout << "LOG.i(DuzaLiczba.cpp, Konstruktor int, " << mNumber << " , " << isPositive << endl;
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

	//cout << "LOG.i(DuzaLiczba.cpp, Konstruktor char, " << mNumber << " , " << isPositive <<"," << mLenght << endl;
};

DuzaLiczba::DuzaLiczba(const DuzaLiczba &copy) : mNumber(copy.mNumber),mLenght(copy.mLenght),isPositive(copy.isPositive) {

	//cout << "LOG.i(DuzaLiczba.cpp, Konstruktor copy, " << mNumber << " , " << isPositive << endl;

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


	//cout << "deletespaces1 , " << cstr << endl;
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
	//cout << "deletespaces2 , " << output << endl;
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


	for (int i = 0; i < shorterNum.mLenght; i++) {

		int a = shorterNum.mNumber[shorterNum.mLenght - 1 - i] - '0';
		int b = longerNum.mNumber[longerNum.mLenght - 1 - i] - '0';
		int c = a + b;
		longerNum.mNumber[longerNum.mLenght - 1 - i] = c + '0';
	}

	for (int i = longerNum.mLenght - 1; i >= 0; i--) {

		int a = longerNum.mNumber[i] - '0';
		if (a >= 10 && i != 0) {
			a -= 10;
			longerNum.mNumber[i] = a + '0';
			int b = longerNum.mNumber[i - 1] - '0';
			b += 1;
			longerNum.mNumber[i - 1] = b + '0';

		} else if (a >= 10 && i == 0) {
			char* tmp = new char[longerNum.mLenght + 2];
			tmp[0] = 1 + '0';
			tmp[longerNum.mLenght + 2] = 0;
			a -= 10;
			longerNum.mNumber[i] = a + '0';
			for (int i = 0; i <= longerNum.mLenght; i++) {
				tmp[i + 1] = longerNum.mNumber[i];
			}
			longerNum.mNumber = tmp;
			longerNum.mLenght = longerNum.mLenght + 1;
		}
	}
	cout << "MNOZENIE" << longerNum.mNumber << endl;
	*this = longerNum;
	return *this;
}

DuzaLiczba DuzaLiczba::subtract(DuzaLiczba &substractNumber){

	DuzaLiczba output = *this;
	
	cout << "ODEJMOWANIA " << endl;
	if (equal(substractNumber)) {
		DuzaLiczba zero("0");
		output = zero;
	}
	// Zak³adam, ¿e zawsze wieksza jest tego samego znaku
	if (bigger(substractNumber)) {
		cout << "LICZBA A JEST WIEKSZA   !!!" << endl;
		for (int i = 0 ; i < substractNumber.mLenght  ; i++) {
			int b = substractNumber.mNumber[substractNumber.mLenght - 1 - i] - '0';
			int a = output.mNumber[mLenght - 1 - i] - '0';
			int c = a - b;
			output.mNumber[mLenght - 1 - i] = c + '0';
			cout << "Dzia³anie " << a << " - " << b << endl;
			cout << "Faza1 : " << c << endl;
		}
		for (int i = mLenght - 1 ; i >= 0 ; i--) {
			
			int a = output.mNumber[i] - '0';
			if (a < 0 ) {
				a += 10;
				output.mNumber[i] = a + '0';
				int b = output.mNumber[i - 1] - '0';
				b -= 1;
				output.mNumber[i - 1] = b + '0';
				
			}
		}
		
			int a = output.mNumber[0] - '0';
			if (a == 0) {
				//Nowy c-string bez pierwszego znaku
				char* tmp = new char[mLenght];
				tmp[mLenght] = 0;
				for (int i = 0; i < mLenght; i++) {
					tmp[i] = output.mNumber[i + 1];
				}
				//delete[]output.mNumber;
				output.mNumber = tmp;
				output.mLenght = output.mLenght - 1;
				cout << "WYNIKA ODEJMOWANIA: " << output.mNumber << endl;
		}
	}else {
		substractNumber.subtract(output).changeSign();
	}

	cout << "WYNIKA ODEJMOWANIA: " << output.mNumber << endl;




	//*this = output;
	return output;
}

DuzaLiczba DuzaLiczba::multiply(const DuzaLiczba &multiplyNumber) {
	

	DuzaLiczba output("0");
	DuzaLiczba multiper = multiplyNumber;
	DuzaLiczba counter("0");
	DuzaLiczba count("1");

	while (!multiper.equal(counter)) {
		cout << output << endl;
		cout << " + " << endl;
		cout << *this << endl;
		
		output.add(*this);
		cout << "DODAWANIE " << counter.mNumber << "  WYNIK " << output << endl;
		counter.add(count);
	}

	cout << "WYNIK MNOZENA: " <<  endl;
	cout << output << endl;
	return *this;
}


DuzaLiczba DuzaLiczba::divide(const DuzaLiczba &addNumber) {

	DuzaLiczba counter("0");
	DuzaLiczba count("1");
	DuzaLiczba divide(*this);
	DuzaLiczba divider = addNumber;

	while (divide.bigger(divider)) {
		cout << "DZIELENIE: " << divide.mNumber << " // " << divider.mNumber << endl;
		divide.subtract(divider);
		counter.add(count);

	}

	cout << counter.mNumber << " TO JEST WYNIK" << endl;
	return counter;
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

