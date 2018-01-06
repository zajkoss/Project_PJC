#pragma once
#include "ElementListy.h"

class ListaDuzychLiczb {
	ElementListy *pierwszy;
	ElementListy *ostatni;
	unsigned int rozmiar;
public:
	ListaDuzychLiczb();

	//meotdy wstaw
	void wstawNaPoczatek(Liczba *);
	void wstawNaKoniec(Liczba *);
	void wstawNaPozycje(Liczba *,unsigned int);

	//metody usun
	void usunPierwszyElement();
	void usunOstatniElement();
	void usunPozycje(unsigned int);
	void usunWszystkieElementy();

	void sortuj();
};
