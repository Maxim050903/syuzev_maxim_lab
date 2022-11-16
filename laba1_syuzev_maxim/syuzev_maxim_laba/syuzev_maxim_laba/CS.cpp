#include "CS.h"
#include "Utilits.h"
using namespace std;

ostream& operator <<(ostream& out, const CS& cs)
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