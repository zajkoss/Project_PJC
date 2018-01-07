#include "stdafx.h"
#include "ListaDuzychLiczb.h"
#include "DuzaLiczba.h"
#include <iostream>
using namespace std;

ListaDuzychLiczb::ListaDuzychLiczb() {
	this->rozmiar = 0;
}

void ListaDuzychLiczb::wstawNaPoczatek(Liczba * liczba) {
	ElementListy *element = new ElementListy(liczba);

	if (!pierwszy){
	pierwszy = element;
	cout << "Dodano na 1" << endl;
	cout << pierwszy->wezLiczbe() << endl;
	}else {
		cout << "Wchodze przestawic" << endl;
		ElementListy *tmp;
		tmp = pierwszy;
		pierwszy = element;
		tmp->ustawPoprzedniElement(pierwszy);
		pierwszy->ustawNastepnyElement(tmp);
		cout << "Dodano na 1" << endl;
		cout << pierwszy->wezLiczbe() << endl;
		cout << "Dodano na 2" << endl;
		cout << tmp->wezLiczbe() << endl;
	}

	if (!ostatni){
		ostatni = element;
		cout << "Dodano na ostatnia" << endl;
		cout <<ostatni->wezLiczbe() << endl;
	}
	cout << "Wychodze z ustawNaPoczatek" << endl;
	rozmiar++;
}

void ListaDuzychLiczb::wstawNaKoniec(Liczba * liczba) {
	ElementListy *element = new ElementListy(liczba);

	if (!ostatni) {
		ostatni = element;
		cout << "Dodano na ostatnia" << endl;
		cout << ostatni->wezLiczbe() << endl;
	}
	else {
		cout << "Wchodze przestawic" << endl;
		ElementListy *tmp;
		tmp = ostatni;
		ostatni = element;
		ostatni->ustawNastepnyElement(0);
		tmp->ustawNastepnyElement(ostatni);
		ostatni->ustawPoprzedniElement(tmp);
		cout << "Dodano na ostatnia" << endl;
		cout << ostatni->wezLiczbe() << endl;
		cout << "Dodano na przedostatnia" << endl;
		cout << tmp->wezLiczbe() << endl;
	}
	if (!pierwszy) {
		pierwszy = element;
		cout << "Dodano na 1" << endl;
		cout << pierwszy->wezLiczbe() << endl;
	}
	cout << "Wychodze z ustawNaKoniec" << endl;
	rozmiar++;
}

void ListaDuzychLiczb::wstawNaPozycje(Liczba * liczba, int pozycja) {
	unsigned int count = 1;
	//TODO Dodac if-a dla pozycij pierw/ost
	if (pozycja <= 0 || pozycja == 1) {
		wstawNaPoczatek(liczba);
	}
	else if (pozycja >= rozmiar) {
		wstawNaKoniec(liczba);
	}
	else {
		ElementListy *element = pierwszy;
		for (int i = 1; i < pozycja; i++) {
			element = element->wezNastepnyElement();
		}
		cout << pozycja << " . " << element->wezLiczbe();

		//Podmiana 
		ElementListy *tmp = new ElementListy(liczba);
		tmp->ustawNastepnyElement(element);
		tmp->ustawPoprzedniElement(element->wezPoprzedniElement());
		tmp->wezPoprzedniElement()->ustawNastepnyElement(tmp);
		element->ustawPoprzedniElement(tmp);
		rozmiar++;
	}
}

ostream& operator<<(ostream& stream, const ListaDuzychLiczb& lista) {
	stream << "Lista:" << endl;
	int count = 1;
	ElementListy *element = lista.pierwszy;
	while (element) {
		stream << count++ << ". " << element->wezLiczbe() << endl;
		element = element->wezNastepnyElement();
	}
	return stream;
}

void ListaDuzychLiczb::usunPierwszyElement(){
	if (rozmiar > 0) {
		if (rozmiar == 1) {
			delete pierwszy;
			pierwszy = 0;
			ostatni = 0;
			rozmiar = 0;
		}
		else {

			ElementListy *tmp = pierwszy->wezNastepnyElement();
			tmp->ustawPoprzedniElement(0);
			pierwszy->ustawNastepnyElement(0);
			delete pierwszy;
			pierwszy = tmp;
			rozmiar--;
		}
	}
}

void ListaDuzychLiczb::usunOstatniElement() {
	if (rozmiar > 0) {
		if (rozmiar == 1) {
			delete pierwszy;
			pierwszy = 0;
			ostatni = 0;
			rozmiar = 0;
		}
		else {

			ElementListy *tmp = ostatni->wezPoprzedniElement();
			tmp->ustawNastepnyElement(0);
			ostatni->ustawPoprzedniElement(0);
			delete ostatni;
			ostatni = tmp;
			rozmiar--;
		}
	}

}

void ListaDuzychLiczb::usunPozycje(int pozycja) {
	if (rozmiar > 0 && pozycja > 0 && pozycja <= rozmiar) {
		if (pozycja == 1) {
			usunPierwszyElement();
		}
		else if (pozycja == rozmiar) {
			usunOstatniElement();
		}
		else {
			ElementListy *element = pierwszy;
			for (int i = 1; i < pozycja; i++) {
				element = element->wezNastepnyElement();
			}
			ElementListy *tmp = element->wezNastepnyElement();
			tmp->ustawPoprzedniElement(element->wezPoprzedniElement());
			tmp = element->wezPoprzedniElement();
			tmp->ustawNastepnyElement(element->wezNastepnyElement());
			element->ustawNastepnyElement(0);
			element->ustawPoprzedniElement(0);
			delete element;
			rozmiar--;
		}
	}

}

void ListaDuzychLiczb::usunWszystkieElementy() {
	if (rozmiar > 0) {
		ElementListy *element = pierwszy;
		while (element) {
			usunPierwszyElement();
			element = pierwszy;
		}
	}

}

void ListaDuzychLiczb::sortuj() {
	
	ListaDuzychLiczb *posortowanaLista = new ListaDuzychLiczb();
	ElementListy *element = pierwszy;
	ElementListy *najMniejszy = pierwszy;
	int pozycja_najMniejszy = 1;

	while (rozmiar > 0) {
		int count = 1;
		while (element) {
			if (porownajLiczby(element->wezLiczbe() , najMniejszy->wezLiczbe())) {
				najMniejszy = element;
				pozycja_najMniejszy = count;
				cout << "Najmniejszy " << najMniejszy->wezLiczbe() << " | " << count << endl;
			}
			element = element->wezNastepnyElement();
			count++;
		}
		posortowanaLista->wstawNaKoniec(new DuzaLiczba(najMniejszy->wezLiczbe()));
		usunPozycje(pozycja_najMniejszy);
		element = pierwszy;
		najMniejszy = pierwszy;
	}
	cout << *posortowanaLista;
}

bool ListaDuzychLiczb::porownajLiczby(char* a, char* b) {
	DuzaLiczba *aa = new DuzaLiczba(a);
	DuzaLiczba *bb = new DuzaLiczba(b);
	if (*aa < *bb || *aa == *bb) {
		delete aa;
		delete bb;
		return true;
	}
	else {
		delete aa;
		delete bb;
		return false;

	}


}


