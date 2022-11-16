#pragma once
#include <string>
#include <iostream>
class CS
{
public:
	std::string name;
	int workshops, working_Shop, efficiency;
	friend std::istream& operator >> (std::istream& in, CS& cs);
	friend std::ostream& operator <<(std::ostream& out, const CS& cs);
};

