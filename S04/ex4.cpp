#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void frecventaLitere(char* s) {
	int* fr = new int[27]();
	for (int i = 0; i < strlen(s); i++) {
		if (strchr("abcdefghijklmnopqrstuvwxyz", s[i])) {
			fr[s[i] - 'a']++;
		}
	}
	for (int i = 0; i < 27; i++) {
		if (fr[i] > 0) {
			cout << char('a' + i) << ": ";
			while (fr[i]) {
				cout << "*";
				fr[i]--;
			}
			cout << endl;
		}
	}
}


int main() {
	int n;
	/*char buffer[100];
	strcpy(buffer, "ana are mere");
	char* s1 = new char[strlen(buffer) + 1];
	strcpy(s1, buffer);*/

	cout << "lungime sir: ";
	cin >> n;
	cin.ignore();
	char* s = new char[n + 1];
	cout << "sirul: ";
	cin.get(s, n + 1);
	frecventaLitere(s);

	delete[] s;
	return 0;
}