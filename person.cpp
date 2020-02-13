#include "person.h";
#include <iostream>
using namespace std;

void Person::Print() {
	cout << "Last Name '" << p.Lastname << "'\n"
		<< "First Name '" << p.Firstname << "'\n"
		<< "Address '" << p.Address << "'\n"
		<< "City '" << p.City << "'\n"
		<< "State '" << p.State << "'\n"
		<< "Zip Code '" << p.ZipCode << "'\n"
		<< flush;
}

Person::Person() {
	p.Lastname[0] = 0;
	p.Firstname[0] = 0;
	p.Address[0] = 0;
	p.City[0] = 0;
	p.State[0] = 0;
	p.ZipCode[0] = 0;
}