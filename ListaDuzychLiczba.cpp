#include "stdafx.h"
#include "ListaDuzychLiczb.h"

ListaDuzychLiczb::ListaDuzychLiczb() {
	this->rozmiarList = 0;
}

ostream& operator<<(ostream& stream, const ListaDuzychLiczb& value) {

		ElementListy *element = value.pierwszy;
		while (element->jestNastepnyElement()) {
			stream << element->Wartosc();
		}
	
	return stream;


}

bool ListaDuzychLiczb::jestPierwszy() {
	if (this->pierwszy)
		return true;
	else
		return false;
}

bool ListaDuzychLiczb::jestOstatni() {
	if (this->ostatni)
		return true;
	else
		return false;
}

void ListaDuzychLiczb::wstawNaPoczatek(Liczba *value) {

	ElementListy *element = new ElementListy(value);

	if (!jestOstatni()) {
		this->ostatni = element;
	}
	if (!jestPierwszy()) {
		this->pierwszy = element;
	}else {
		ElementListy *tmp = pierwszy;
		delete pierwszy;

		pierwszy = element;
		pierwszy->setNastepnyElement(tmp);

		tmp->setPoprzedniElement(pierwszy);
	}

}

