#pragma once
#include "DuzaLiczba.h"
#include "ElementListy.h"
#include <iostream>
using namespace std;

class ListaDuzychLiczb {
	ElementListy *pierwszy;
	ElementListy *ostatni;
	int rozmiar;
	static bool porownajLiczby(char*, char*);

public:
	ListaDuzychLiczb();

	//meotdy wstaw
	void wstawNaPoczatek(Liczba *);
	void wstawNaKoniec(Liczba *);
	void wstawNaPozycje(Liczba *,int);

	//metody usun
	void usunPierwszyElement();
	void usunOstatniElement();
	void usunPozycje( int);
	void usunWszystkieElementy();

	void sortuj();

	friend ostream& operator<<(ostream&, const ListaDuzychLiczb&);
};
