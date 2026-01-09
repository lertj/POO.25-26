#include <iostream>
#include <fstream>
 
using namespace std;
 
class Persoana {
public:
    string cnp;
    int varsta;
    string nume;
 
    Persoana(string cnp, int varsta, string nume) {
        this->cnp = cnp;
        this->varsta = varsta;
        this->nume = nume;
    }
 
    void display() {
        cout << cnp << endl;
        cout << varsta << endl;
        cout << nume << endl;
    }
};
 
class Angajat : public Persoana {
public:
    int salariu;
 
    Angajat(string cnp, int varsta, string nume, int salariu) : Persoana(cnp, varsta, nume){
        this->salariu = salariu;
    }
};
 
 
int main()
{
    char* x= new char[5000];
    ifstream fin("In.txt");
    while (fin.getline(x, 5000)) {
        cout << x;
    }
 
    fstream fout("out.txt", ios::trunc | ios::binary);
    fout << "Ana are pere";
    fout << 4;
    int y = 10;
    fout.write((char*) &y, sizeof(int));
    fin.close();
    fout.close();
    delete[] x;
 
    Persoana p("125371", 31, "Andrei");
    p.display();
    
    Angajat a("125371", 31, "Andrei2", 5000);
    a.display();
    
    return 0;
}