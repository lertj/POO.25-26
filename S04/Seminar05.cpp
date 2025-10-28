#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;

//struct Test {
//	int x;
//};

float calculeazaMedia(int* note, int n) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		avg += note[i];
	}

	avg /= n;

	return avg;
}

class Carte {
//private: // by default
private:
	char* title = nullptr;
	char* author = nullptr;
	int year;
	int* note = nullptr;
	int nrNote = 0;


public:

	float calculeazaMedia(int notaMinima) {
		float avg = 0;
		for (int i = 0; i < this->nrNote; i++) {
			avg += this->note[i];
		}

		avg /= this->nrNote;

		return avg;
	}

	Carte() {
		cout << "Acesta este constructorul default" << endl;
		title = new char[50];
		strcpy(this->title, "-");

		this->author = new char[50];
		strcpy(this->author, "-");

		this->year = -1;
	}

	Carte(const char* title, const char* author, const int year) {
		//title = new char[strlen(title) + 1]; // shadowing
		this->title = new char[strlen(title)+1]; // shadowing
		strcpy(this->title, title);

		this->author = new char[strlen(author)+1];
		strcpy(this->author, author);

		this->year = year;
	}

	void display() {
		cout << "Titlu: " << this->title << endl;
		cout << "Autor: " << this->author << endl;
		cout << "An: " << this->year << endl;
	}

	char* getTitle() {
		// return this->title; // shallow copy // NU
		if (this->title == nullptr) {
			return nullptr;
		}

		char* copie = new char[strlen(this->title) + 1];
		strcpy(copie, this->title);
		return copie; // deep copy
	}

	void setTitle(char* title) {
		// this->title = title; shallow copy // NU

		if (this->title != nullptr) {
			delete[] this->title;
		}

		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}

	int getYear() {
		return this->year;
	}
};

int main()
{

	Carte c1;

	c1.display();

	/*Test* y;
	y->x;*/

	Carte c2("Ion", "Liviu Rebreanu", 1930);
	c2.display();

	cout << c2.getTitle() << endl;
	char* titluCarte = c2.getTitle();
	titluCarte[0] = 'K';
	cout << c2.getTitle() << endl;

	char* titlu = new char[50];
	strcpy(titlu, "Un titlu");
	c2.setTitle(titlu);
	c2.display();
	titlu[0] = '0';
	c2.display();

	cout << "\n************************\n\n";

	c2.display();
	int anul = c2.getYear();
	anul = 100;
	c2.display();
	return 0;
}