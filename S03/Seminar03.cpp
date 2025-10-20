#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // biblioteca pentru siruri de caractere


using namespace std;

struct Student {
	char* nume = nullptr;
	char* facultate = nullptr;
	string cnp = "";
	float medie = 0;
};

class StudentC {
	
public:
	char* nume = nullptr;
	char* facultate = nullptr;
	string cnp = "";
	float* note = nullptr;
	int nrNote = 0;

	void afisare() {
		cout << "Student: \n\n";
		cout << this->nume << endl << this->facultate << endl << this->cnp << endl;
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
			
		}
	}
};


int main() {

	/*char numeStudent1[100];
	char facultateStudent1[10];
	float medieStudent1;

	char numeStudent2[100];
	char facultateStudent2[10];
	float medieStudent2;

	char numeStudenti[100][100];
	char facultateStudents[100][10];
	float medieStudent1[100];*/

	Student s1;
	Student ssV[100];
	char nume[] = "Esteban Julio Ricardo Montoya de la Rosa Ramirez al treilea";
	s1.nume = new char[strlen(nume)+1];
	strcpy(s1.nume, nume);
	s1.facultate = new char[strlen("CSIE")+1];
	strcpy(s1.facultate, "CSIE");
	s1.medie = 9.55;
	s1.cnp = "123456789";

	cout << s1.nume << endl << s1.facultate << endl << s1.medie << endl << s1.cnp <<endl << endl;

	StudentC s2;
	char* nume2 = new char[100];
	strcpy(nume2, "Jr. ");
	strcat(nume2, nume);
	s2.nume = new char[strlen(nume2) + 1];
	strcpy(s2.nume, nume2);
	s2.facultate = new char[strlen("CSIE") + 1];
	strcpy(s2.facultate, "CSIE");
	s2.note = new float[5];
	s2.note[0] = 10;
	s2.note[1] = 7;
	s2.note[2] = 8;
	s2.nrNote = 3;
	s2.cnp = "123456789";

	s2.afisare();

	return 0;
}