 #include <iostream>
using namespace std;

void ex2(char* s)
{
    int i = 0;
    int j = 0;
    int c = 1;
    bool EXISTA = false;
    while (s[i] != '\0')
    {
        if (s[i] != '.')
        {
            s[j] = s[i];
            j++;
            if (s[i] != ' ')
                EXISTA = true;
            else if (s[i] == ' ' && EXISTA == true || s[i] == '.' && EXISTA == true) {
                c++;
                EXISTA = false;
            }
        }
        else
        {
            s[j] = '\0';
            cout << s << ". " << c << endl;
            c = 1;
            j = 0;
        }
        i++;
    }
}

int main() {
    char s[200];
    cin.getline(s, 200);
    ex2(s);
    return 0;
}
