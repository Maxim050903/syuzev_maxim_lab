#pragma once
#include <iostream>
template <typename T>
T GetCorrectNumber(T min, T max)
{
	T x;
	while ((std::cin >> x).fail() || x<min || x>max)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "������ ����� ������ (���������): ";
	}
	return x;
}
template <typename V>
void GetCorrectNumbers(V& x)
{
	while (((std::cin >> x).fail())/*||( x < 0)*/)
	{
		std::cout << "������ ����� ������ (���������): ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}
