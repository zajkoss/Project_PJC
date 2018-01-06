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

};