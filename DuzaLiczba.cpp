#include "stdafx.h"
#include "DuzaLiczba.h"

#include <iostream>
#include <string>

using namespace std;


DuzaLiczba::DuzaLiczba(int number) {
	
	string s = to_string(number);
	char const* tmp_number = s.c_str();
	wartosc = copyString(tmp_number);
	
	mLenght = strlen(wartosc);
	
	if(wartosc[0] == '-'){
		isPositive = false;
	} else {
		isPositive = true;
	}
};

DuzaLiczba::DuzaLiczba(char* number) : wartosc(number),mLenght(strlen(number))  {	

	wartosc = deleteSpaces(wartosc);
	mLenght = strlen(wartosc);	

	if (wartosc[0] == '-') {
		isPositive = false;
	}else {
		isPositive = true;
	}
};

DuzaLiczba::DuzaLiczba(const DuzaLiczba &copy) : wartosc(copy.wartosc),mLenght(copy.mLenght),isPositive(copy.isPositive) {
}

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
	return output;
}

ostream& operator<<(ostream& stream, const DuzaLiczba& item) {
	stream << item.wartosc;
	return stream;
}

istream& operator>>(istream& stream, const DuzaLiczba& item) {
	stream >> item.wartosc;
	return stream;
}

DuzaLiczba::~DuzaLiczba()
{
	delete[] wartosc;
}

DuzaLiczba DuzaLiczba::add(const DuzaLiczba& addNumber) const {

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

		int a = shorterNum.wartosc[shorterNum.mLenght - 1 - i] - '0';
		int b = longerNum.wartosc[longerNum.mLenght - 1 - i] - '0';
		int c = a + b;
		cout << " 1 " <<  wartosc[longerNum.mLenght - 1 - i] <<  endl;
		longerNum.wartosc[longerNum.mLenght - 1 - i] = c + '0';
		cout << " 2 " << wartosc[longerNum.mLenght - 1 - i] << endl;
	}

	for (int i = longerNum.mLenght - 1; i >= 0; i--) {
	
		int a = longerNum.wartosc[i] - '0';
		if (a >= 10 && i != 0) {
			a -= 10;
			longerNum.wartosc[i] = a + '0';
			int b = longerNum.wartosc[i - 1] - '0';
			b += 1;
			longerNum.wartosc[i - 1] = b + '0';

		} else if (a >= 10 && i == 0) {
			char* tmp = new char[longerNum.mLenght + 2];
			tmp[0] = 1 + '0';
			tmp[longerNum.mLenght + 2 - 1] = 0;
			a -= 10;
			longerNum.wartosc[i] = a + '0';
			for (int i = 0; i <= longerNum.mLenght; i++) {
				tmp[i + 1] = longerNum.wartosc[i];
			}
			longerNum.wartosc = tmp;
			longerNum.mLenght = longerNum.mLenght + 1;
		}
	}
	return longerNum;
}

DuzaLiczba DuzaLiczba::subtract(const DuzaLiczba &substractNumber) const{

	DuzaLiczba output = *this;
	
	if (equal(substractNumber)) {
		DuzaLiczba zero(0);
		output = zero;
		return output;
	}
	if (bigger(substractNumber)) {
		cout << "LICZBA A JEST WIEKSZA   !!!" << endl;
		for (int i = 0 ; i < substractNumber.mLenght  ; i++) {
			int b = substractNumber.wartosc[substractNumber.mLenght - 1 - i] - '0';
			int a = output.wartosc[mLenght - 1 - i] - '0';
			int c = a - b;
			output.wartosc[mLenght - 1 - i] = c + '0';
		}
		for (int i = mLenght - 1 ; i >= 0 ; i--) {
			
			int a = output.wartosc[i] - '0';
			if (a < 0 ) {
				a += 10;
				output.wartosc[i] = a + '0';
				int b = output.wartosc[i - 1] - '0';
				b -= 1;
				output.wartosc[i - 1] = b + '0';
			}
		}
		
		int k = 0;
		int a = output.wartosc[k] - '0';
		while(a == 0) {
			char* tmp = new char[mLenght];
			tmp[mLenght - 1] = 0;
			for (int i = 0; i < mLenght; i++) {
				tmp[i] = output.wartosc[i + 1];
			}
			//delete[]output.mNumber;
			output.wartosc = tmp;
			output.mLenght = output.mLenght - 1;
			a = output.wartosc[k++] - '0';
		}
	}else {
		output = substractNumber.subtract(output).changeSign();
	}
	return output;
}

DuzaLiczba DuzaLiczba::multiply(const DuzaLiczba &multiplyNumber) const {
	
	DuzaLiczba output("0");
	DuzaLiczba multiper = multiplyNumber;
	DuzaLiczba counter("0");
	DuzaLiczba count("1");

	while (!multiper.equal(counter)) {
		cout << output << endl;
		cout << " + " << endl;
		cout << *this << endl;
	
		output = output.add(*this);
		counter = counter.add(count);
	}
	return output;
}

DuzaLiczba DuzaLiczba::divide(const DuzaLiczba &addNumber) const {

	DuzaLiczba counter("0");
	DuzaLiczba count("1");
	DuzaLiczba divide = *this;
	DuzaLiczba divider = addNumber;

	while (divide.bigger(divider)) {
		divide = divide.subtract(divider);
		counter = counter.add(count);
	}
	return counter;
}

DuzaLiczba DuzaLiczba::changeSign() const {

	 DuzaLiczba output = *this;

	if (output.isPositive) {
		char *temporary = new char[output.mLenght + 2];
		temporary[0] = '-';
		for (int i = 0; i < output.mLenght; i++) {
			temporary[i + 1] = output.wartosc[i];
		}
		temporary[output.mLenght + 2 - 1] = 0;
		//delete[] output.mNumber;
		output.wartosc = temporary;
		output.mLenght = strlen(output.wartosc);
		output.isPositive = false;

	}
	else if(!output.isPositive){
		char *temporary = new char[output.mLenght];
		for (int i = 1; i < output.mLenght; i++) {
			temporary[i-1] = output.wartosc[i];
		}
		temporary[output.mLenght - 1] = 0;
		//delete[] output.mNumber;
		output.wartosc = temporary;
		output.mLenght = strlen(output.wartosc);
		output.isPositive = true;
	}
	return output;
}

bool DuzaLiczba::bigger(const DuzaLiczba& compare) const {

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
				if (wartosc[i] > compare.wartosc[i])
					return true;
				else if (wartosc[i] < compare.wartosc[i])
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
					if (wartosc[i] > compare.wartosc[i])
						return false;
					else if (wartosc[i] < compare.wartosc[i])
						return true;
				}
			}
		}
	}

bool DuzaLiczba::equal(const DuzaLiczba& compare) const {

	if ((isPositive && compare.isPositive) || (!isPositive && !compare.isPositive)) {
		for (int i = 0; i < mLenght; i++) {
			if (wartosc[i] != compare.wartosc[i])
				return false;
		}
		return true;
	}
	else {
		return false;
	}

}

//========= OPERATORY =============
DuzaLiczba DuzaLiczba::operator+(const DuzaLiczba& value)  {

	DuzaLiczba output;

	if (this->isPositive && value.isPositive)
		output = add(value);
	else if (this->isPositive && !value.isPositive) {
		output = subtract(value.changeSign());
	}
	else if (!this->isPositive && value.isPositive) {
		output = value.subtract(changeSign());
	}
	else if (!this->isPositive && !value.isPositive) {
		output = changeSign().add(value.changeSign());
	}
	return output;
}

DuzaLiczba& DuzaLiczba::operator=(const DuzaLiczba& value) {
	
	wartosc = copyString(value.wartosc);
	mLenght = value.mLenght;
	isPositive = value.isPositive;

	return *this;
}

DuzaLiczba DuzaLiczba::operator-(const DuzaLiczba& value)  {

	DuzaLiczba output;

	if (this->isPositive && value.isPositive)
		output = subtract(value);
	else if (this->isPositive && !value.isPositive) {
		output = add(value.changeSign());
	}
	else if (!this->isPositive && value.isPositive) {
		output = changeSign().add(value);
		output = output.changeSign();
	}
	else if (!this->isPositive && !value.isPositive) {
		output = value.changeSign().subtract(changeSign());
	}
	return output;

}

DuzaLiczba DuzaLiczba::operator*(const DuzaLiczba& value)  {
	
	DuzaLiczba output;

	if (isPositive && value.isPositive) {
		output = multiply(value);
	}
	else if (!isPositive && !value.isPositive) {
		output = changeSign().multiply(value.changeSign());
	}
	else if (!isPositive && value.isPositive) {
		output = changeSign().multiply(value);
		output = output.changeSign();
	}
	else if (isPositive && !value.isPositive) {
		output = multiply(value.changeSign());
		output = output.changeSign();
	}


	return output;
} 

DuzaLiczba DuzaLiczba::operator/(const DuzaLiczba& value)  {

	DuzaLiczba output;

	if (isPositive && value.isPositive) {
		output = divide(value);
	}
	else if (!isPositive && !value.isPositive) {
		output = changeSign().divide(value.changeSign());
	}
	else if (!isPositive && value.isPositive) {
		output = changeSign().divide(value);
		output = output.changeSign();
	}
	else if (isPositive && !value.isPositive) {
		output = divide(value.changeSign());
		output = output.changeSign();
	}


	return output;
}

DuzaLiczba & DuzaLiczba::operator+=(const DuzaLiczba& value) {
	

	if (this->isPositive && value.isPositive)
		*this = add(value);
	else if (this->isPositive && !value.isPositive) {
		*this = subtract(value.changeSign());
	}
	else if (!this->isPositive && value.isPositive) {
		*this = value.subtract(changeSign());
	}
	else if (!this->isPositive && !value.isPositive) {
		*this = changeSign().add(value.changeSign());
	}
	return *this;
	
}

DuzaLiczba & DuzaLiczba::operator-=(const DuzaLiczba& value) {

	if (this->isPositive && value.isPositive)
		*this = subtract(value);
	else if (this->isPositive && !value.isPositive) {
		*this = add(value.changeSign());
	}
	else if (!this->isPositive && value.isPositive) {
		*this = changeSign().add(value);
		*this = changeSign();
	}
	else if (!this->isPositive && !value.isPositive) {
		*this = value.changeSign().subtract(changeSign());
	}
	return *this;

}

DuzaLiczba & DuzaLiczba::operator*=(const DuzaLiczba& value) {
	
	if (isPositive && value.isPositive) {
		*this = multiply(value);
	}
	else if (!isPositive && !value.isPositive) {
		*this = changeSign().multiply(value.changeSign());
	}
	else if (!isPositive && value.isPositive) {
		*this = changeSign().multiply(value);
		*this = changeSign();
	}
	else if (isPositive && !value.isPositive) {
		*this = multiply(value.changeSign());
		*this = changeSign();
	}

	return *this;
}

DuzaLiczba & DuzaLiczba::operator/=(const DuzaLiczba& value) {

	if (isPositive && value.isPositive) {
		*this = divide(value);
	}
	else if (!isPositive && !value.isPositive) {
		*this = changeSign().divide(value.changeSign());
	}
	else if (!isPositive && value.isPositive) {
		*this = changeSign().divide(value);
	    *this = changeSign();
	}
	else if (isPositive && !value.isPositive) {
		*this = divide(value.changeSign());
		*this = changeSign();
	}

	return *this;
}

bool operator>=(const DuzaLiczba & a , const DuzaLiczba &b) {

	if (a.bigger(b) || a.equal(b))
		return true;
	else
		return false;
}

bool operator<(const DuzaLiczba & a, const DuzaLiczba & b) {

	if (a.bigger(b))
		return false;
	else
		return true;
 }

bool operator==(const DuzaLiczba & a, const DuzaLiczba & b) { 
	return a.equal(b);
}

bool operator!=(const DuzaLiczba & a, const DuzaLiczba & b) {
	return !a.equal(b);
}

DuzaLiczba operator-(const DuzaLiczba & a) {

	return a.changeSign();
}

DuzaLiczba operator!(const DuzaLiczba & a) {

	DuzaLiczba output("1");

	// n >= 1
	DuzaLiczba zero(0);
	if (!a.isPositive || a.equal(zero)) {
		output = zero;
	}
	else {
		DuzaLiczba count("1");
		DuzaLiczba counter("1");

		while (counter.equal(a) || a.bigger(counter)) {
			output = output.multiply(counter);
			counter = counter.add(count);
		}
	}
	return output;

}