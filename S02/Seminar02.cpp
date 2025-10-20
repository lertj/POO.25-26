#include <iostream>

using namespace std;

int main() {
	int x = 3; // modificare, initalizare
	x = 4;
	const int cx = 3; // initializare
	//cx = 4; // X
	int* p = 0; // modificare, initalizare
	p = &x;
	const int* cp = &cx; // modificare, initalizare a adresei pointerului
	cp = &x;
	int* const pc = &x; // initalizare a adresei pointerului
	//pc = 0; // X
	const int* const cpc = &cx; // initializare 
	// cpc = 0; // X

	cout << "x= " << x <<endl;
	*p = 5;
	cout << "x= " << x <<endl;
	//*cp = 7; // X
	cout << "x= " << x << endl;
	*pc = 9;
	cout << "x= " << x << endl;

	return 0;
}