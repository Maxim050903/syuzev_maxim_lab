#include "GRAPH.h"
#include <map>
using namespace std;

ostream& operator << (ostream& out, const GRAPH& gr)
{
	cout << gr.idvih << "-->" << gr.idvh << "\n";
	return out;
}
std::ofstream operator<<(std::ofstream& out, const GRAPH& gr)
{
	out << gr.idvih << "\n";
	out << gr.idvh << "\n";
	return std::ofstream();
}

std::ifstream operator >> (std::ifstream& in, GRAPH& gr)
{
	in >> gr.idvh;
	in >> gr.idvih;
	return std::ifstream();
}

