#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;


struct CS
{
	string name;
	int workshops=0,working_Shop,efficiency;
};

void inputStation(CS& cs1)
{
	if (cs1.workshops > 0)
	{
		cout << "station sushestvuet" << "\n";
	}
	else
	{
			cout << "name station: ";
			cin.clear();
			cin.ignore();
			getline(cin, cs1.name);
			cout << "amount workshops: ";
			cin >> cs1.workshops;
			cout << "amount of working shops: ";
			cin >> cs1.working_Shop;
			cs1.efficiency = (cs1.working_Shop * 100) / cs1.workshops;
	}
};

void checkCS(CS& cs1)
{
	while (cs1.workshops < 0)
	{
		cout << "amount workshops again: ";
		cin >> cs1.workshops;
	}
	while ((cs1.working_Shop > cs1.workshops) || (cs1.working_Shop < 0))
	{
		cout << "amount of working shops again: ";
		cin >> cs1.working_Shop;
		cs1.efficiency = (cs1.working_Shop * 100) / cs1.workshops;
	}
}

void OutputStation(CS& station)
{
	if (station.workshops > 0)
	{
		cout << "name station: " << station.name << "\n";
		cout << "amount workshops: " << station.workshops << "\n";
		cout << "amount of working shops: " << station.working_Shop << "\n";
		cout << "efficiency of prуcent: " << station.efficiency << "%" << "\n";
	}
	else
	{
		cout << "cs ne sozdana";
	}
};

void editStation(CS& cs1)
{
	if (cs1.workshops > 0)
	{
		cout << "amount of working shops: ";
		cin >> cs1.working_Shop;
		cs1.efficiency = (cs1.working_Shop * 100) / cs1.workshops;
	}
	else
	{
		cout << "staition ne sushestvuet";
	}
}



struct pipe
{
	double length=0;
	float diameter;
	bool condition;
};

void inputPipe(pipe& P1)
{
	if (P1.length > 0)
	{
		cout << "pipe sushestvuet" << "\n";
	}
	else
	{
		cout << "length pipe: ";
		cin >> P1.length;
		cout << "diameter pipe: ";
		cin >> P1.diameter;
		cout << "condition pipe: ";
		cin >> P1.condition;
	}
		
};

void checkPIPE(pipe& p)
{
	while (p.length <= 0)
	{
		cout << "length pipe: ";
		cin >> p.length;
	}
	while (p.diameter <= 0)
	{
		cout << "diameter pipe: ";
		cin >> p.diameter;
	}
}

void editpipe(pipe& P1)
{
	if (P1.length > 0)
	{
		cout << "condition pipe";
		cin >> P1.condition;
	}
	else
		cout << "truba ne sozdana"<<"\n";
}

void OutputPipe(pipe& p)
{
	if (p.length > 0) 
	{
		cout << "length pipe: " << p.length << "\n"
			<< "diametr pipe: " << p.diameter << "\n"
			<< "condition pipe: " << p.condition << "\n";
	}
	else
	{
		cout << "truba ne sozdana"<<"\n";
	}
	
};



void menu()
{
	cout << "1.add pipe\n"
		<< "2.add cs\n"
		<< "3.view all objects\n"
		<< "4.edit pipe\n"
		<< "5.edit cs\n"
		<< "6.save\n"
		<< "7.download\n"
		<< "8.exit\n"
		<< "\n";
}



void showALLobjects(pipe& p1,CS& cs1)
{
	OutputPipe(p1);
	OutputStation(cs1);
}



void save_in_file(const pipe& p1,const CS& cs1)
{
	ofstream f_inf;
	f_inf.open("fileLR1.txt", ios::out);
	f_inf << p1.length << "\n"
		<< p1.diameter << "\n"
		<< p1.condition << "\n"
		<< cs1.name << "\n"
		<< cs1.working_Shop << "\n"
		<< cs1.workshops << "\n"
		<< cs1.efficiency << "\n";
	f_inf.close();
}

void read_on_file(pipe& p1, CS& cs1)
{ 
	ifstream f_inf;
	f_inf.open("fileLR1.txt", ios::in);
	
	//https://www.youtube.com/watch?v=aUP0eAEIxog
	if (!f_inf.is_open())
	{
		cout << "error";
	}
	else
	{
		cout<<("file is open")<<"\n";
		f_inf >> p1.length
			>> p1.diameter
			>> p1.condition;
		f_inf.ignore();
		getline(f_inf,cs1.name);
		f_inf	>> cs1.working_Shop 
				>> cs1.workshops 
				>> cs1.efficiency ;

	}
	f_inf.close();
	system("pause");
}


int main()
{
	pipe P;
	CS cs1;
	int id;
	do
	{
		system("cls");
		menu();
		cout << "choose an action: ";
		cin.clear();
		cin >> id;
			switch (id)
			{
				case 1:
					inputPipe(P);
					checkPIPE(P);
					OutputPipe(P);
					system("pause");
					break;
				case 2:
					inputStation(cs1);
					checkCS(cs1);
					OutputStation(cs1);
					system("pause");
					break;
				case 3:
					showALLobjects(P, cs1);
					system("pause");
					break;
				case 4:
					editpipe(P);
					OutputPipe(P);
					system("pause");
					break;
				case 5:
					editStation(cs1);
					OutputStation(cs1);
					system("pause");
				case 6:
					save_in_file(P, cs1);
					break;
				case 7:
					read_on_file(P, cs1);
					break;
				case 8:
					id = 8;
					break;
			}
	} while (id != 8);
	return 0;
}