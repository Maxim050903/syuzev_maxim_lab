#include "Cpipe.h"
#include "Utilits.h"
#include <string>
#include <fstream>
using namespace std;
ostream& operator << (ostream& out, const pipe& p)
{
	out << "Имя трубы: " << p.name << '\n'
		<< "длина трубы: " << p.length << "\n"
		<< "диаметр трубы: " << p.diameter << "\n"
		<< "Состояние трубы: ";
	if (p.condition == true)
	{
		out << "труба в ремонте" << "\n";
	}
	else
	{
		out << "труба в работе" << "\n";
	}
	return out;
}
istream& operator >> (istream& in, pipe& p)
{
	do
	{
		in.clear();
		in.ignore(10000, '\n');
		cout << "Введите имя трубы: ";
		cin.clear();
		cin.ignore();
		getline(cin, p.name);
		cout << "Длинна трубы в метрах: ";
		GetCorrectNumbers(p.length);
		cout << "Диаметр трубы в метрах: ";
		GetCorrectNumbers(p.diameter);
		cout << "Состояние трубы (0 труба в работе;другое значение труба в ремонте) : ";
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
		std::cout << "Состояние трубы успешно изменено" << "\n";
}



