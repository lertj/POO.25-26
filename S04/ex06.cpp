#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
using namespace std;

void abreviere(int n, char** m)
{
	char abrev[256];
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		char* cuv = strtok(m[i], " ");
		while (cuv != NULL)
		{
			abrev[cnt] = cuv[0];
			cnt++;
			cuv = strtok(NULL, " ");
		}
		abrev[cnt] = ' ';
		cnt++;
	}
	abrev[cnt] = '\0';

	for (int i = 0; i < cnt; i++)
		if (abrev[i] == ' ')
			cout << endl;
		else
			cout << abrev[i];

}

int main()
{
	int n;

	cin >> n;

	cin.ignore();


	char** m = new char* [n];

	for (int i = 0; i < n; i++)
	{
		m[i] = new char[256];
		cin.getline(m[i], 256);
	}

	abreviere(n, m);

	return 0;
}