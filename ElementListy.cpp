#include "stdafx.h"
#include "ElementListy.h"

ElementListy::ElementListy(Liczba * value) : liczba(value) {
		

}

char* ElementListy::Wartosc() {
	return this->liczba->Wartosc();
}

ElementListy* ElementListy::getNastepnyElement() {
	return this->nastepnyElement;
}

ElementListy* ElementListy::getPoprzedniElement() {
	return this->poprzedniElement;
}
 
void ElementListy::setNastepnyElement(ElementListy* value) {
	this->nastepnyElement = value;
}

void ElementListy::setPoprzedniElement(ElementListy* value) {
	this->poprzedniElement = value;
}

bool ElementListy::jestNastepnyElement() {
	if (this->nastepnyElement)
		return true;
	else
		return false;
}