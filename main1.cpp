#include "stdafx.h"

#include "DuzaLiczba.h" 
#include <iostream>

int main() {
	
	// konstruktor bezargumentowy inicjalizuje obiekt warto�ci� 0
	DuzaLiczba l1;
	// konstruktor z argumentem typu int inicjalizuje obiekt warto�ci� sta�o-liczbow�
	DuzaLiczba l2(9999);
	// konstruktor z argumentem typu char* inicjalizuje obiekt podan� warto�ci�
	DuzaLiczba l3("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
	////// konstruktor kopiuj�cy g��boko
	DuzaLiczba l4(l3);
	////// te� konstruktor kopiuj�cy g��boko
	DuzaLiczba l5 = l4;
	DuzaLiczba l6(-987654);

	DuzaLiczba *l7 = new DuzaLiczba(" - 999999999999999999999999999999");

	//TEST
	/*DuzaLiczba t1("12");
	DuzaLiczba t2("4");
	t1.add(t2);
	cout << t1;
	cout << endl;

	DuzaLiczba tt("4");
	t1.add(tt);
	cout << t1;
	cout << endl;*/


	/*DuzaLiczba t3("200");
	DuzaLiczba t4("50");
	t3.add(t4);
	cout << t3;
*/
/*
	DuzaLiczba t5("1000");
	DuzaLiczba t6("120");
	t5.subtract(t6);
	*/

	
	//DuzaLiczba t7("100");
	//DuzaLiczba t8("10");
	//t7.subtract(t8);
	//t7.subtract(t8);


	DuzaLiczba tt("10");
	DuzaLiczba ttt("5");

	tt.add(ttt);
	tt.add(ttt);
	cout << tt;
	//tt.multiply(ttt);

	//// Wszystkie obiekty od l1 do l6 s� obiektami statycznymi, 
	//// tzn. istniej� od pocz�tku do ko�ca dzia�ania funkcji main 
	//// natomiast obiekt wskazywany przez wska�nik l7 jest 
	//// obiektem dynamicznym, tzn. mo�e by� usuni�ty przez wywo�anie 
	//// operatora delete.


	//// przedefiniowany operator >> 
	//cin >> l1;
	//// przedefiniowany operator <<
	//cout << l1 << l2 << l3 << l4 << l5 << l6 << *l7;
	//cout << l1 << l2 << l3 << l4 << l5 << l6;
	//// usuni�cie obiektu wskazywanego przez l7
	//delete l7;

	//// przedefiniowany operator =
	//l1 = l2;
	//// przedefiniowane operatory +-*/ dzielenie ca�kowite
	//l1 = l1 + l2 - l3 * l4 / l5;

	//// przedefiniowany operator +=
	//l1 += 23;
	//// przedefiniowany operator += 
	//l1 += l4;
	//// przedefiniowany operator -=
	//l2 -= l3;
	//// przedefiniowany operator *=
	//l3 *= l4;

	//// przedefiniowany operator ==
	//if (l4 == "23424")
	//	// przedefiniowany operator /= dzielenie ca�kowite
	//	l4 /= l5;

	//// przedefiniowany operator !=
	//if (l5 != l4) {
	//	// przedefiniowany jednoargumentowy operator -
	//	l5 = -l5;
	//	cout << l5;
	//}

	//// przedefiniowany operator =
	//l2 = "1221";

	//DuzaLiczba silnia = 0;
	//// przedefiniowane operatory >= <
	//if (l2 >= 0 && l2 < "1223")
	//{
	//	// przedefiniowany operator !
	//	silnia = !l2;
	//	cout << silnia;
	//}
	system("pause");
	return 0;
}