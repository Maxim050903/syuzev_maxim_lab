#include <iostream>
#include <string>
using namespace std;

struct pipe
{
	double length;
	float diameter;
	bool condition;
};

pipe inputPipe()
{
	pipe p;
	cout << "length pipe: ";
	cin >> p.length;
	cout << "diametr pipe: ";
	cin >> p.diameter;
	cout << "condition pipe: ";
	cin >> p.condition;
	return p;
	
}

void OutputPipe(pipe p)
{
	cout << "length pipe: " << p.length << "\n"
		<< "diametr pipe: " << p.diameter <<"\n"
		<< "condition pipe: " << p.condition <<"\n";

}

int main()
{
		cout << "1.add pipe\n"
			 << "2.add cs\n"
			 << "3.view all objects\n"
			 << "3.edit pipe\n"
			 << "4.edit cs\n"
			 << "5.save\n"
			 << "6.download\n"
			 << "7.exit\n"
			 << "\n"
			 << "choose an action: ";
		int id;
		cin >> id;
		switch (id)
		{
			case 1:
			{
				pipe P1 = inputPipe();
				OutputPipe(P1);
				system("pause");
			}
			case 2:
			{
				
				break;
			}
			case 3:
			{
				
				break;
			}
			case 4:
			{
				
				break;
			}
			case 5:
			{
				
				break;
			}
			case 6:
			{
				
				break;
			}
			case 7:
			{
				
				break;
			}
		}

}