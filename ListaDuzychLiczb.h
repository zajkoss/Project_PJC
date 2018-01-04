#pragma once
#include "ElementListy.h"
#include <iostream>

using namespace std;

class ListaDuzychLiczb {
	ElementListy *pierwszy;
	ElementListy *ostatni;
	int rozmiarList;

	bool jestPierwszy();
	bool jestOstatni();

public:
	ListaDuzychLiczb();

	//Funkcje wstaw
	void wstawNaPoczatek(Liczba *);
	void wstawNaKoniec(Liczba *);
	void wstawNaPozycje(Liczba *, int position); // i > 0
	

	//Funkcje usun
	void usunPierwszyElement();
	void usunOstatniElement();
	void usunPozycje();
	void usunWszystkieElementy();
	 
	void sortuj();

	friend ostream& operator<<(ostream&, const ListaDuzychLiczb&);


};