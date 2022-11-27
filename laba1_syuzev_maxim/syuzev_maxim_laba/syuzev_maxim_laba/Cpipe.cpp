#include "Cpipe.h"
#include "Utilits.h"
#include <string>
#include <fstream>
using namespace std;
ostream& operator << (ostream& out, const pipe& p)
{
	out << "��� �����: " << p.name << '\n'
		<< "����� �����: " << p.length << "\n"
		<< "������� �����: " << p.diameter << "\n"
		<< "��������� �����: ";
	if (p.condition == true)
	{
		out << "����� � �������" << "\n";
	}
	else
	{
		out << "����� � ������" << "\n";
	}
	return out;
}
istream& operator >> (istream& in, pipe& p)
{
	do
	{
		in.clear();
		in.ignore(10000, '\n');
		cout << "������� ��� �����: ";
		cin.clear();
		cin.ignore();
		getline(cin, p.name);
		cout << "������ ����� � ������: ";
		GetCorrectNumbers(p.length);
		cout << "������� ����� � ������: ";
		GetCorrectNumbers(p.diameter);
		cout << "��������� ����� (0 ����� � ������;������ �������� ����� � �������) : ";
		GetCorrectNumbers(p.condition);
	} while (cin.fail());
	return in;
}
ifstream& operator >> (ifstream& in, pipe& p)
{
	in >> p.name;
	in >> p.length;
	in >> p.diameter;
	in >> p.condition;
	return in;
}
ofstream& operator << (ofstream& out, const pipe& p)
{
	out << p.name<<"\n";
	out << p.length<<"\n";
	out << p.diameter<<"\n";
	out << p.condition;
	return out;
}
void editPipe(pipe& P1)
{
		if (P1.condition == 0)
		{
			P1.condition = true;
		}
		else
		{
			P1.condition = false;
		}
		std::cout << "��������� ����� ������� ��������" << "\n";
}



