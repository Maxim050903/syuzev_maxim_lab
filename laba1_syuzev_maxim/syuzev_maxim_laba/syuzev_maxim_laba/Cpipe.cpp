#include "Cpipe.h"
#include "Utilits.h"
using namespace std;
ostream& operator <<(ostream& out, const pipe& p)
{
	out << "Имя трубы: " << p.name << '\n'
		<< "длинна трубы: " << p.length << "\n"
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



