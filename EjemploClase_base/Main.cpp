#include <iostream>
using namespace std;

#include "Pixel.h"
#include "Clock.h"

int main()
{
	/*// ---------- EXERCICE 1 -------------------------------
	Pixel blue(0, 0, 255), black;

	Pixel red(255, 0, 0);

	Pixel m;

	m = red.mix(blue);

	cout << black.red() << " " << black.green() << " " << black.blue()

		<< endl;

	cout << m.red() << " " << m.green() << " " << m.blue() << endl;*/

	/*// ---------- EXERCICE 2 -------------------------------
	Clock clock1(21, 0, 0);
	Clock clock2;
	clock2.setHour(21, 23, 5);
	if (clock1 == clock2)
	{
		cout << "Equal!" << endl;
	}
	else if (clock1 < clock2)
	{
		cout << "Lower!" << endl;
	}
	else
	{
		cout << "Greater!" << endl;
	}
	clock2.printHour();*/

	// ----------EXERCICE 3 --------------------------------
	Matricula m1(1234, "ABC"), m2(5588, "KXM");

	Matricula m3(m1), m4;

	Char* s = m4.to_string();

	cout << "m4 val: " << s << endl;

	cout << "m2 val: " << m2.to_string() << endl;

	cout << "m1 is equal to m3?? ";

	if (m1.is_equal(m3)) {

		cout << "yes" << endl;

	}
	else {

		cout << "no" << endl;

	}

	cout << "Finished" << endl;

    system("pause");

    return 0;
}