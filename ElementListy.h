#pragma once
#include "Liczba.h"

class ElementListy {
	Liczba *liczba;
	ElementListy *nastepnyElement;
	ElementListy *poprzedniElement;
public:
	ElementListy(Liczba *);

	char *Wartosc();

	ElementListy* getNastepnyElement();
	ElementListy* getPoprzedniElement();
	void setNastepnyElement(ElementListy*);
	void setPoprzedniElement(ElementListy*);
	bool jestNastepnyElement();

};