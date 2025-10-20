#include <iostream>

using namespace std;

void func(char* s, int n, char*& aux)
{
    int count = 0;
    int i = 0;
    while (s[i] != NULL)
    {
        if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
            count++;
        i++;
    }
    aux = new char[n - count + 1];
    i = 0;
    int j = 0;
    while (s[i] != NULL)
    {
        if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
            i++;
        else
        {
            aux[j] = s[i];
            i++;
            j++;
        }
    }
    aux[j] = '\0';
}

int main()
{
    int n;
    cout << "Introduceti dimensiunea sirului de caractere: ";
    cin >> n;
    cin.get();
    char* s = new char[n + 1];
    char* aux = nullptr;
    cout << "Introduceti s:  ";
    cin.getline(s, n + 1);
    cout << "s = " << s << endl;
    func(s, n, aux);
    cout << "aux = " << aux << endl;
    delete[] s;
    delete[] aux;
    return 0;
}