#include "CS.h"
#include "Utilits.h"
#include <string>
#include <fstream>
using namespace std;
ostream& operator << (ostream& out, const CS& cs)
{
	cout << "�������� �������: " << cs.name << "\n";
	cout << "�-�� �����: " << cs.working_Shop << "\n";
	cout << "�-�� ���������� �����: " << cs.workshops << "\n";
	cout << "������������� ������ �������: " << cs.efficiency << "%" << "\n";
	return out;
}
istream& operator >> (istream& in, CS& cs)
{
	{
		cout << "�������� �������: ";
		cin.clear();
		cin.ignore();
		getline(cin, cs.name);
		cout << "���-�� �����: ";
		GetCorrectNumbers(cs.working_Shop);
		cout << "���-�� ����� � ������: ";
		cs.workshops = GetCorrectNumber(0, cs.working_Shop);
		cout << "������� �������� ������������� ������� �� 0 �� 100: ";
		cs.efficiency = GetCorrectNumber(0, 100);
	}
	return in;
}
void CS::editStation()
{
	std::cout << "������� ����� ����� ���������� ����� (�� :0 �� :" << working_Shop << ")";
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
