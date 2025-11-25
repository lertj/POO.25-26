#include <iostream>
using namespace std;

enum TipProdus
{
    FRUCTE, LEGUME, LACTATE, BACANIE
};

class Produs {
    const int id = 0;
    string nume = "";
    float* istoricPreturi = nullptr;
    int nrPreturi = 0;
    bool eExpirat = false;
    TipProdus categorie = BACANIE;
    static int PRET_MIN;
    static int NR_PRODUSE;

public:
    Produs() :id(NR_PRODUSE) {
        nume = "null";
        istoricPreturi = nullptr;
        nrPreturi = 0;
        eExpirat = false;
        NR_PRODUSE++;
    }

    Produs(const int id, string nume, float* istoricPreturi, int nrPreturi, bool eExpirat) : id(NR_PRODUSE)
    {
        if (!nume.empty())
            this->nume = nume;
        this->nrPreturi = nrPreturi;
        if (nrPreturi > 0)
        {
            this->istoricPreturi = new float[nrPreturi];
            for (int i = 0; i < nrPreturi; i++)
                this->istoricPreturi[i] = istoricPreturi[i];
        }
        this->eExpirat = eExpirat;
        NR_PRODUSE++;
    }

    Produs(string nume, float* istoricPreturi, int nrPreturi, bool eExpirat, TipProdus categorie) : id(NR_PRODUSE)
    {
        if (!nume.empty())
            this->nume = nume;
        this->nrPreturi = nrPreturi;
        if (nrPreturi > 0)
        {
            this->istoricPreturi = new float[nrPreturi];
            for (int i = 0; i < nrPreturi; i++)
                this->istoricPreturi[i] = istoricPreturi[i];
        }
        this->eExpirat = eExpirat;
        this->categorie = categorie;
        NR_PRODUSE++;
    }

    Produs(const Produs& copie): id(NR_PRODUSE) {
        this->nume = copie.nume;
        this->categorie = copie.categorie;
        this->eExpirat = copie.eExpirat;
        NR_PRODUSE++;
        this->nrPreturi = copie.nrPreturi;
        if (this->istoricPreturi != nullptr) {
            delete[] this->istoricPreturi;
        }
        this->istoricPreturi = new float[this->nrPreturi];
        for (int i = 0; i < this->nrPreturi; i++) {
            this->istoricPreturi[i] = copie.istoricPreturi[i];
        }

        cout << "Copy c-tor\n";
    }

    void display()
    {
        cout << "Id: " << this->id << endl;
        cout << "Nume: " << this->nume << endl;
        cout << "NrPreturi: " << this->nrPreturi << endl;
        if (this->nrPreturi > 0)
        {
            for (int i = 0; i < this->nrPreturi; i++)
                cout << "istoricPreturi[" << i << "] = " << this->istoricPreturi[i] << endl;
        }
        cout << ((this->eExpirat == true) ? "E expirat.\n" : "Nu e expirat.\n");
        switch (this->categorie)
        {

        case BACANIE:
            cout << "BACANIE";
            break;
        case FRUCTE:
            cout << "FRUCTE";
            break;
        case LEGUME:
            cout << "LEGUME";
            break;
        case LACTATE:
            cout << "LACTATE";
            break;

        }
        cout << endl;
    }
    void setIstoricPreturi(float* _istoricPreturi, int _nrPreturi)
    {
        this->nrPreturi = _nrPreturi;
        if (_nrPreturi > 0 && _istoricPreturi != nullptr)
        {
            delete[] this->istoricPreturi;
            this->istoricPreturi = new float[nrPreturi];
            for (int i = 0; i < this->nrPreturi; i++)
            {
                if (_istoricPreturi[i] < PRET_MIN)
                {
                    throw "pret invalid";
                }
                else
                    this->istoricPreturi[i] = _istoricPreturi[i];
            }
        }
    }

    void operator=(const Produs& destinatie) {
        if (this == &destinatie) {
            return;
        }
        cout << "Operator =\n";
        this->nume = destinatie.nume;
        this->categorie = destinatie.categorie;
        this->eExpirat = destinatie.eExpirat;
        this->nrPreturi = destinatie.nrPreturi;
        if (this != &destinatie) {
            if (this->istoricPreturi != nullptr) {
                delete[] this->istoricPreturi;
            }
            this->istoricPreturi = new float[this->nrPreturi];
            for (int i = 0; i < this->nrPreturi; i++) {
                this->istoricPreturi[i] = destinatie.istoricPreturi[i];
            }
        }
        
    }

    void operator=(const Produs* destinatie) {
        if (this == destinatie) {
            return;
        }
        cout << "Operator =\n";
        this->nume = destinatie->nume;
        this->categorie = destinatie->categorie;
        this->eExpirat = destinatie->eExpirat;
        this->nrPreturi = destinatie->nrPreturi;
        if (this != destinatie) {
            if (this->istoricPreturi != nullptr) {
                delete[] this->istoricPreturi;
            }
            this->istoricPreturi = new float[this->nrPreturi];
            for (int i = 0; i < this->nrPreturi; i++) {
                this->istoricPreturi[i] = destinatie->istoricPreturi[i];
            }
        }

    }

    ~Produs() {
        if (this->istoricPreturi != nullptr) {
            delete[] this->istoricPreturi;
            this->istoricPreturi = nullptr;
        }
    }
};
int Produs::PRET_MIN = 2;
int Produs::NR_PRODUSE = 0;

void adunare(int x, int y) {
    cout << "Rezultatul este " << x + y << endl;
}

void adunare(char x, char y) {
    cout << "Rezultatul este " << x << y <<endl;
}

int adunare(int x, char y) {
    cout << "Rezultatul este " << x << y << endl;
    return 0;
}


int main() {
    Produs a;
    a.display();
    Produs b(123, "Lapte", new float[3] {5, 10, 15}, 3, false);
    b.setIstoricPreturi(new float[3] {5, 10, 100}, 3);
    b.display();
    Produs a1;
    a1.display();

    Produs copie(b);
    copie.display();

    cout << "***********************\n\n";
    adunare(5, 10);
    adunare('a', 'c');
    Produs c = copie; // copy c-tor
    c = copie; // op =
    copie = copie;
    copie.display();
    return 0;
}