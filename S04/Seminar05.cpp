#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;

//struct Test {
//	int x;
//};

class Carte {
//private: // by default
private:
	char* title = nullptr;
	char* author = nullptr;
	int year;

public:
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
		//return this->title; // shallow copy
		char* copie = new char[strlen(this->title) + 1];
		strcpy(copie, this->title);
		return copie;
	}

	void setTitle(const char* title) {
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
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
	c2.getTitle()[0] = 'K';
	cout << c2.getTitle() << endl;

	c2.setTitle("ABCD");
	cout << c2.getTitle();
	return 0;
}