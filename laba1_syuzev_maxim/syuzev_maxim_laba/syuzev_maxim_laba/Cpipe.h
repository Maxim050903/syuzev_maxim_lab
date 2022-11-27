#pragma once
#include <string>
#include <iostream>
#include <fstream>
class pipe
{
	std::string name;
	int idPipe;
	int length;
	int diameter;
	bool condition;
	
	friend void editPipe(pipe& P1);
	friend bool checkname(const pipe& p, std::string name);
	friend bool checkcondition(const pipe& p, bool condition);

	friend std::ifstream& operator >> (std::ifstream& in, pipe& p);
	friend std::ofstream& operator << (std::ofstream& out, const pipe& p);
	friend std::ostream& operator << (std::ostream& out, const pipe& p);
	friend std::istream& operator >> (std::istream& in, pipe& p);
};
