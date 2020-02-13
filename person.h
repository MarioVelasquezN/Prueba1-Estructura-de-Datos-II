#include <iostream>
#include <fstream>

using namespace std;


struct Persona {
	char Lastname[99];
	char Firstname[99];
	char Address[99];
	char City[99];
	char State[99];
	char ZipCode[99];
	//77 bytes
};

class Person {
public:
	Person();
	//Person(const char*);
	void Print();
	void Pack();
	//void unPack(char *);

	//para read reg fijo
	Persona p;
	fstream fs;
	void readFile();
	void writeFile();
};
