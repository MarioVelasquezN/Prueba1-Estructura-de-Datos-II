#define _CRT_SECURE_NO_WARNINGS
#include "person.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#pragma warning(disable:C4267)

void Person::writeFile() {
	ofstream pOut("personas.dat", ios::app);


	printf("Ingresa Apellido: ");
	scanf("%s", p.Lastname);

	printf("Ingresa Nombre: ");
	scanf("%s", p.Firstname);

	printf("Ingresa Direccion: ");
	scanf("%s", p.Address);

	printf("Ingresa  Ciudad: ");
	scanf("%s", p.City);

	printf("Ingresa Estado: ");
	scanf("%s",p.State);

	printf("Ingresa ZipCode: ");
	scanf("%s",p.ZipCode);

	char buffer[99];
	_itoa(strlen(p.Lastname), buffer, 10);
	pOut << setw(2) << setfill('0') << buffer << p.Lastname;

	char buffer2[99];
	_itoa(strlen(p.Firstname), buffer2, 10);
	pOut << setw(2) << setfill('0') << buffer2 << p.Firstname;

	char buffer3[99];
	_itoa(strlen(p.Address), buffer3, 10);
	pOut << setw(2) << setfill('0') << buffer3 << p.Address;

	char buffer4[99];
	_itoa(strlen(p.City), buffer4, 10);
	pOut << setw(2) << setfill('0') << buffer4 << p.City;

	char buffer5[99];
	_itoa(strlen(p.State), buffer5, 10);
	pOut << setw(2) << setfill('0') << buffer5 << p.State;

	char buffer6[99];
	_itoa(strlen(p.ZipCode), buffer6, 10);
	pOut << setw(2) << setfill('0') << buffer6 << p.ZipCode << "|";

	pOut.close();

}

void Person::readFile() {
	ifstream personIn("personas.dat", ios::in);

	if (!personIn) {
		cout << "error al abrir el archivo!!!";
		return;
	}

	string palabra="0";
	
	cout << "**********************Consulta de personas**********************\n\n";
	
	while (getline(personIn, palabra, '|')) {
		cout << palabra<<"\n";
		cout << p.Lastname<<"\t"<< p.Firstname <<"\t"<<p.Address <<"\t"<<p.City <<"\t"<< p.State <<"\t"<< p.ZipCode<<"\n";
	}

	personIn.close();
}

void Person::Pack() {
	char* Pack = reinterpret_cast<char*>(&p);

	char Copia1[99];
	char buffer1[99];
	memcpy(&Copia1, Pack, strlen(p.Lastname));
	Copia1[strlen(p.Lastname)] = '\0';
	_itoa(strlen(p.Lastname), buffer1, 10);
	fs << setw(2) << setfill('0') << buffer1 << Copia1;

	char Copia2[99];
	char buffer2[99];
	memcpy(&Copia2, Pack + 99, strlen(p.Firstname));
	Copia2[strlen(p.Firstname)] = '\0';
	_itoa(strlen(p.Firstname), buffer2, 10);
	fs << setw(2) << setfill('0') << buffer2 << Copia2;


	char Copia3[99];
	char buffer3[99];
	memcpy(&Copia3, Pack + 198, strlen(p.Address));
	Copia3[strlen(p.Address)] = '\0';
	_itoa(strlen(p.Address), buffer3, 10);
	fs << setw(2) << setfill('0') << buffer3 << Copia3;

	char Copia4[99];
	char buffer4[99];
	memcpy(&Copia4, Pack + 297, strlen(p.City));
	Copia4[strlen(p.City)] = '\0';
	_itoa(strlen(p.City), buffer4, 10);
	fs << setw(2) << setfill('0') << buffer4 << Copia4;

	char Copia5[99];
	char buffer5[99];
	memcpy(&Copia5, Pack + 396, strlen(p.State));
	Copia5[strlen(p.State)] = '\0';
	_itoa(strlen(p.State), buffer5, 10);
	fs << setw(2) << setfill('0') << buffer5 << Copia5;

	char Copia6[99];
	char buffer6[99];
	memcpy(&Copia6, Pack + 495, strlen(p.ZipCode));
	Copia6[strlen(p.ZipCode)] = '\0';
	_itoa(strlen(p.ZipCode), buffer6, 10);
	fs << setw(2) << setfill('0') << buffer6 << Copia6 << "|";

	fs.close();
}

//void Person::unPack(char * buffer) {
//	for (size_t i = 0; i < sizeof(buffer); i += sizeof(Person))
//	{
//		char inicio[2];
//		inicio[0] = buffer[0];
//		inicio[1] = buffer[1];
//		int pos = 0;
//		int tmp;
//		int size = sizeof(buffer);
//		string temp = "";
//		for (size_t i = 0; i < atoi(inicio); i++)
//		{
//			char as[2];
//			as[0] = buffer[i];
//			as[1] = buffer[i + 1];
//			if (atoi(as) > 0)
//			{
//				tmp = atoi(as);
//				for (int i = 0; i < temp.size(); i++) {
//					LastName[i] = temp.at(i);
//				}
//				LastName[temp.size()] = '\0';
//				temp = "";
//				pos += 1;
//				break;
//			}
//			temp += buffer[i];
//			pos += 1;
//		}
//		for (size_t i = pos; i < tmp; i++)
//		{
//			char as[2];
//			as[0] = buffer[i];
//			as[1] = buffer[i + 1];
//			if (atoi(as) > 0)
//			{
//				tmp = atoi(as);
//				for (int i = 0; i < temp.size(); i++) {
//					FirstName[i] = temp.at(i);
//				}
//				FirstName[temp.size()] = '\0';
//				temp = "";
//				pos += 1;
//				break;
//			}
//			temp += buffer[i];
//			pos += 1;
//		}
//		for (size_t i = pos; i < tmp; i++)
//		{
//			char as[2];
//			as[0] = buffer[i];
//			as[1] = buffer[i + 1];
//			if (atoi(as) > 0)
//			{
//				tmp = atoi(as);
//				for (int i = 0; i < temp.size(); i++) {
//					Address[i] = temp.at(i);
//				}
//				Address[temp.size()] = '\0';
//				temp = "";
//				pos += 1;
//				break;
//			}
//			temp += buffer[i];
//			pos += 1;
//		}
//		for (size_t i = pos; i < tmp; i++)
//		{
//			char as[2];
//			as[0] = buffer[i];
//			as[1] = buffer[i + 1];
//			if (atoi(as) > 0)
//			{
//				tmp = atoi(as);
//				for (int i = 0; i < temp.size(); i++) {
//					City[i] = temp.at(i);
//				}
//				City[temp.size()] = '\0';
//				temp = "";
//				pos += 1;
//				break;
//			}
//			temp += buffer[i];
//			pos += 1;
//		}
//		for (size_t i = pos; i < tmp; i++)
//		{
//			char as[2];
//			as[0] = buffer[i];
//			as[1] = buffer[i + 1];
//			if (atoi(as) > 0)
//			{
//				tmp = atoi(as);
//				for (int i = 0; i < temp.size(); i++) {
//					State[i] = temp.at(i);
//				}
//				State[temp.size()] = '\0';
//				temp = "";
//				pos += 1;
//				break;
//			}
//			temp += buffer[i];
//			pos += 1;
//		}
//		for (size_t i = pos; i < size; i++)
//		{
//			if (buffer[i] == '|')
//			{
//				for (int i = 0; i < temp.size(); i++) {
//					ZipCode[i] = temp.at(i);
//				}
//				ZipCode[temp.size()] = '\0';
//				temp = "";
//				pos += 1;
//				break;
//			}
//			temp += buffer[i];
//			pos += 1;
//		}
//	}
//
//
//
//}