#include "CS.h"
#include "Utilits.h"
#include <string>
#include <fstream>
using namespace std;
ostream& operator << (ostream& out, const CS& cs)
{
	cout << "Название станции: " << cs.name << "\n";
	cout << "К-во цехов: " << cs.working_Shop << "\n";
	cout << "К-во работающих цехов: " << cs.workshops << "\n";
	cout << "Эффектичность работы станции: " << cs.efficiency << "%" << "\n";
	return out;
}
istream& operator >> (istream& in, CS& cs)
{
	{
		cout << "Название станции: ";
		cin.clear();
		cin.ignore();
		getline(cin, cs.name);
		cout << "Кол-во цехов: ";
		GetCorrectNumbers(cs.working_Shop);
		cout << "Кол-во цехов в работе: ";
		cs.workshops = GetCorrectNumber(0, cs.working_Shop);
		cout << "Введите значение эффективности станции от 0 до 100: ";
		cs.efficiency = GetCorrectNumber(0, 100);
	}
	return in;
}
void CS::editStation()
{
	std::cout << "Введите новое число работающих цехов (от :0 до :" << working_Shop << ")";
	working_Shop = GetCorrectNumber(0, workshops);
}

ofstream& operator << (ofstream& out,const CS& cs)
{
	out << cs.name<<"\n";
	out << cs.working_Shop<<"\n";
	out << cs.workshops<<"\n";
	out << cs.efficiency;
	return out;
}

ifstream& operator >> (ifstream& in,CS& cs)
{
	in >> cs.name;
	in >> cs.working_Shop;
	in >> cs.workshops;
	in >> cs.efficiency;
	return in;
}
