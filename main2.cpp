#include "stdafx.h"
#include "DuzaLiczba.h" 
#include "DuzaLiczbaZespolona.h" 


int main() {
	
<<<<<<< HEAD

	DuzaLiczba p = DuzaLiczba("11111112");
	cout << p << endl;


	//=====================================================
	/*ListaDuzychLiczb *lista = new ListaDuzychLiczb();
	lista->wstawNaPoczatek(new DuzaLiczba("9129081391"));
	cout << lista;*/
=======
	// Wszystkie obiekty od l1 do l6 s� obiektami statycznymi, 
	// tzn. istniej� od pocz�tku do ko�ca dzia�ania funkcji main 
	// natomiast obiekt wskazywany przez wska�nik l7 jest obiektem
	// dynamicznym, tzn. mo�e by� usuni�ty przez wywo�anie operatora delete.
	// przedefiniowany operator >>
	cin >> l1;
	// przedefiniowany operator <<              
	cout << l1 << l2 << l3 << l4 << l5 << l6 << *l7;
	cout << l2a << l3a;
	// usuni�cie obiektu wskazywanego przez l7
	//delete l7;

	// przedefiniowany operator =
	l1 = l2;
	cout << l1;   */
	// przedefiniowane operatory +-* /  dzielenie ca�kowite       

	//MAJNE TESTY
	//DuzaLiczbaZespolona p1(2, 2);
	DuzaLiczba*l7 = new DuzaLiczba("-172839023498234792834798237494");
	delete l7;
	//DuzaLiczbaZespolona p3;
	
	//if (p1 < "2") {
	//	cout << "ELO";
	//}
	/*DuzaLiczba p01(50);
	DuzaLiczba p02("-1");
	DuzaLiczba p03;
	p03 = p01 * p02;
	cout << p03;*/




	/*l1 = l1 + l2 - l3 * l4 / l5;

	// przedefiniowany operator += - zwi�kszenie sk�adowej rzeczywistej liczby l1 o 23
	l1 += 23;
	// przedefiniowany operator +=
	l1 += l4;
	// przedefiniowany operator -=
	l2 -= l3;
	// przedefiniowany operator *=
	l3 *= l4;

	// przedefiniowany operator ==
	if (l4 == "23424")
		// przedefiniowany operator /=  dzielenie ca�kowite        
		l4 /= l5;

	// przedefiniowany operator ==
	if (l4 == l5)
		// przedefiniowany operator /=  dzielenie ca�kowite          
		l4 /= l5;

	// przedefiniowany operator !=
	if (l5 != l4) {
		// przedefiniowany operator � zmiana warto�ci sk�adowych na przeciwne          
		l5 = -l5;
		cout << l5;
	}

	// przedefiniowany operator =
	l2 = "1221";
	// przedefiniowane operatory >=  <
	if (l2 >= 0 && l2 < "1223") {
		cout << "ok";
	}
	*/
>>>>>>> parent of bba746f... problem part3
	system("pause");
	return 0; 
}