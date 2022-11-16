#include "Cpipe.h"
#include "Utilits.h"
using namespace std;
ostream& operator <<(ostream& out, const pipe& p)
{
	out << "��� �����: " << p.name << '\n'
		<< "������ �����: " << p.length << "\n"
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



