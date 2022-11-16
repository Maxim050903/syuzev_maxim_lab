#pragma once
#include <string>
class pipe
{
public:
	std::string name;
	int length;
	int diameter;
	bool condition;
	friend std::ostream& operator <<(std::ostream& out, const pipe& p);
	friend std::istream& operator >> (std::istream& in, pipe& p);
	
};

