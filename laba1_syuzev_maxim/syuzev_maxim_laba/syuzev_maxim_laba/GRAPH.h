#pragma once
#include <iostream>
#include <fstream>
#include <map>
class GRAPH
{
public:
	int idvh;
	int idvih;
	friend std::ostream& operator << (std::ostream& out, const GRAPH& gr);
	friend std::ofstream operator << (std::ofstream& out, const GRAPH& gr);
	friend std::ifstream operator >> (std::ifstream& in,GRAPH& gr);
};

