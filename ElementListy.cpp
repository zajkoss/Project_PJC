#include "stdafx.h"
#include "ElementListy.h"
#include <iostream>

ElementListy::ElementListy(Liczba  *value) : liczba(value){
	//cout << "Konstruktor element listy" << endl;
}

ElementListy* ElementListy::wezNastepnyElement() {
		return this->nastepnyElement;
}

ElementListy* ElementListy::wezPoprzedniElement() {
	return this->poprzedniElement;
}

void ElementListy::ustawNastepnyElement(ElementListy * value) {

		this->nastepnyElement = value;

}

void ElementListy::ustawPoprzedniElement(ElementListy * value) {
	this->poprzedniElement = value;
}

char* ElementListy::wezLiczbe() {
	return  this->liczba->Wartosc();

}


ElementListy& ElementListy::operator=(const ElementListy& element) {
	this->liczba = element.liczba;
	this->nastepnyElement = element.nastepnyElement;
	this->poprzedniElement = element.poprzedniElement;
	return *this;
}