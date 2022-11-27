#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Utilits.h"
class CS
{
	std::string name;
	int idCS, workshops, working_Shop, efficiency;
	friend bool checkCSname(const CS& p, std::string name);
	friend bool checkprocent(const CS& p, int procent);
public:
	void editStation();
	friend std::ifstream& operator >> (std::ifstream& in,CS& cs);
	friend std::ofstream& operator << (std::ofstream& out,const CS& cs);
	friend std::istream& operator >> (std::istream& in, CS& cs);
	friend std::ostream& operator << (std::ostream& out, const CS& cs);
};


