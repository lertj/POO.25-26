#include <iostream>

using namespace std;

class Angajat {
	
	char* functie;
	int* istoricSalariu;
	int nrSchimbariSalariu;
	const int id = 0;

public:
	string nume;
	static int SALARIU_MINIM;
	Angajat() : nume("Odobasian"), functie(nullptr), istoricSalariu(nullptr), nrSchimbariSalariu(0), id(0) {
		//this->nume = "Odobasian";
		//this->functie = nullptr;
		//this->istoricSalariu = nullptr;
		//// this->id = 0; // eroare
		//this->nrSchimbariSalariu = 0;
	}

	Angajat(string nume, const char* functie, int* istoricSalariu, int nrSchimbariSalariu, int _id) :id(_id) //functie(new char[strlen(functie)+1])
	{
		this->nume = nume;
		this->functie = new char[strlen(functie)+1];
		strcpy_s(this->functie, strlen(functie)+1, functie);

		this->nrSchimbariSalariu = nrSchimbariSalariu;
		this->istoricSalariu = new int[nrSchimbariSalariu];
		for (int i = 0; i < nrSchimbariSalariu; i++) {
			this->istoricSalariu[i] = istoricSalariu[i];
		}

		// this->id = id; // eroare
	}

	Angajat(const Angajat& a) :nume(a.nume), nrSchimbariSalariu(a.nrSchimbariSalariu), id(a.id) {
		this->functie = new char[strlen(a.functie) + 1];
		strcpy_s(this->functie, strlen(a.functie) + 1, a.functie);

		this->istoricSalariu = new int[a.nrSchimbariSalariu];
		for (int i = 0; i < a.nrSchimbariSalariu; i++) {
			this->istoricSalariu[i] = a.istoricSalariu[i];
		}

	}

	void curata() {
		delete[] this->functie;
		this->functie = nullptr;
		delete[] this->istoricSalariu;
		this->istoricSalariu = nullptr;
	}

	~Angajat() {

		if (this->functie != nullptr) {
			delete[] this->functie;
			this->functie = nullptr;
		}

		if (this->istoricSalariu != nullptr) {
			delete[] this->istoricSalariu;
			this->istoricSalariu = nullptr;
		}
		
	}

	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "Functie: " << this->functie << endl;
		cout << "Nr schimbari salariu: " << this->nrSchimbariSalariu << endl;
		for (int i = 0; i < this->nrSchimbariSalariu; i++) {
			cout<< this->istoricSalariu[i] << ' ';
		}
		cout << endl;
		cout << "ID: " << this->id << endl;
	}

	int* getIstoricSalariu() {
		//return this->istoricSalariu; // shallow copy
		int* copie = new int[this->nrSchimbariSalariu];
		for (int i = 0; i < this->nrSchimbariSalariu; i++) {
			copie[i] = this->istoricSalariu[i];
		}

		return copie;
	}

	void setIstoricSalariu(int* istoricSalariu, int nrSchimbariSalariu) {
		if (istoricSalariu == nullptr || nrSchimbariSalariu < 1) {
			return;
		}

		this->nrSchimbariSalariu = nrSchimbariSalariu;

		if (this->istoricSalariu != nullptr) {
			delete[] this->istoricSalariu;
			this->istoricSalariu = nullptr;
		}

		this->istoricSalariu = new int[nrSchimbariSalariu];
		for (int i = 0; i < this->nrSchimbariSalariu; i++) {
			this->istoricSalariu[i] = istoricSalariu[i];
		}

	}
};

int Angajat::SALARIU_MINIM = 2500;

int main() {
	Angajat a1("Balaurentiu", "Developer", new int[3] {2500, 3000, 3500}, 3, 1);
	a1.afisare();

	a1.setIstoricSalariu(new int[4] {2500, 3000, 3500, 4000}, 4);
	a1.afisare();

	cout << "SALARIU MINIM: " << Angajat::SALARIU_MINIM << endl;

	int* copie = a1.getIstoricSalariu();
	a1.afisare();
	//a1.curata();

	int x = 3.55f;
	cout << x;

	delete[] copie;

	Angajat a2(a1);
	a2.nume = "1234";

	a2.afisare();
	return 0;
}