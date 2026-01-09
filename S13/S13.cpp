#include <iostream>

using namespace std;

class Animal {

protected:
    int x = 0;

public:
    string nume;
    float masa;

    Animal(string nume, float masa) {
        this->nume = nume;
        this->masa = masa;
    }

    void printInfo() {
        cout << "Nume: " << this->nume << endl;
        cout << "Masa: " << this->masa << endl;
    }

};

class Mamifer : public Animal { 
public:
    int capacitateLapte;

    Mamifer() : Animal("-", 0) {
        this->capacitateLapte = 0;
        this->x; // e OK
    }

    Mamifer(string nume, float masa, int capacitateLapte) : Animal(nume, masa) {
        this->capacitateLapte = capacitateLapte;
    }

    void printInfo() {
        this->Animal::printInfo();
        cout << "Lapte: " << this->capacitateLapte << endl;
    }
};



int main() 
{
    Mamifer m;
    Animal somon("somon", 4);
    Mamifer pisica("pisica", 1.5f, 1);
    somon.printInfo();
    //a.x; // NU e ok
    pisica.printInfo();

    // Mamifer leu = somon; // NU 
    Animal somn = pisica; // merge by default
}
