#pragma once
#include "Liczba.h"

class ElementListy {
	Liczba *liczba;
	ElementListy *nastepnyElement;
	ElementListy *poprzedniElement;
public:
	ElementListy(Liczba *);


};