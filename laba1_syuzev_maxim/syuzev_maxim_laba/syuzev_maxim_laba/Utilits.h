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
		std::cout << "Ошибка ввода данных (повторите): ";
	}
	return x;
}
template <typename V>
void GetCorrectNumbers(V& x)
{
	while (((std::cin >> x).fail())/*||( x < 0)*/)
	{
		std::cout << "Ошибка ввода данных (повторите): ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}
template <typename T>
T CorrectVertex(T min,T max,T x)
{
	int otv;
	while (((std::cin >> otv).fail()) || (otv == x)||(otv>max)||(otv<min))
	{
		std::cout << "Ошибка ввода данных (повторите): ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	return otv;
}
