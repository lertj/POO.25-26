#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // biblioteca pentru siruri de caractere
using namespace std;
int baza(char* s) {
	if (s == nullptr || strlen(s) == 0) // verificam daca pointerul este null
		return -1; // iesim din functie
	bool b2 = true; // presupunem ca e baza 2
	bool b4 = true; // presupunem ca e baza 4
	bool b8 = true; // presupunem ca e baza 8
	bool b10 = true; // presupunem ca e baza 10
	bool b16 = true; // presupunem ca e baza 16
	for (int i = 0; i < strlen(s); i++) { // parcurgem sir
		char c = s[i];
		if (!(c == '0' || c == '1')) // daca nu e cifra binara
			b2 = false; // nu e baza 2)
		if (!(c >= '0' && c <= '3')) // daca nu e cifra baza 4	
			b4 = false; // nu e baza 4
		if (!(c >= '0' && c <= '7')) // daca nu e cifra baza 8	
			b8 = false; // nu e baza 8
		if (!(c >= '0' && c <= '9')) // daca nu e cifra baza 10
			b10 = false; // nu e baza 10
		if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) // daca nu e cifra baza 16	
			b16 = false; // nu e baza 16
	}
	if (b2) return 2;
	if (b4) return 4;
	if (b8) return 8;
	if (b10) return 10;
	if (b16) return 16;
	return -1; // nu e niciuna din bazele de mai sus
}

int main() {
	char* nr = new char[100]; // alocam memorie pentru sir
	cout << "Introduceti un numar : ";
	cin >> nr;
	int bz = baza(nr);
	cout << "Baza numarului este: " << bz << endl;
	delete[] nr; // eliberam memoria alocata pentru sir
	return 0;
}