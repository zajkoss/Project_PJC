#pragma once
#include "Liczba.h"

class ElementListy {
	Liczba *liczba;
	ElementListy *nastepnyElement;
	ElementListy *poprzedniElement;
public:
	ElementListy(Liczba *);

	ElementListy* wezNastepnyElement();
	ElementListy* wezPoprzedniElement();

	void ustawNastepnyElement(ElementListy *);
	void ustawPoprzedniElement(ElementListy *);

	char* wezLiczbe();

	ElementListy& operator=(const ElementListy& );
};