#include "stdafx.h"
#include "DuzaLiczba.h" 
#include "DuzaLiczbaZespolona.h" 
#include "ElementListy.h"
#include "ListaDuzychLiczb.h"


int main() {

	DuzaLiczbaZespolona a("50","-10");
	a = -a;
	cout << a;
	
	/*
	DuzaLiczba p = DuzaLiczba("1212");
	cout << p.Wartosc() << endl;

	DuzaLiczbaZespolona z1 = DuzaLiczbaZespolona("100", "200");
	cout << z1;
	cout << endl;
	cout << z1.Wartosc();
	*/

  /*  ListaDuzychLiczb *lista = new ListaDuzychLiczb();

	lista->wstawNaPoczatek(new DuzaLiczbaZespolona("11","15"));
	lista->wstawNaPoczatek(new DuzaLiczba("0"));
	lista->wstawNaPoczatek(new DuzaLiczba("-2"));
	lista->wstawNaPoczatek(new DuzaLiczba("44"));
	
	cout << *lista;
  
	lista->sortuj();
	
	cout << *lista;
	*/

	system("pause");
	return 0; 
}