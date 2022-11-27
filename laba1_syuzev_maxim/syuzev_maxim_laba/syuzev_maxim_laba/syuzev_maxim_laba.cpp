#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Cpipe.h"
#include "CS.h"
#include "Utilits.h"
#include <map>


using namespace std;
template <typename OB>
OB& SelectOB(map<int,OB>& g)
{
		cout << "Введите номер элемента в векторе:";
		unsigned long long int index = GetCorrectNumber(1ull, (g.size()));
		return g[index - 1];
}
bool checkCSname(const CS& p, std::string name)
{
	return p.name == name;
}
bool checkprocent(const CS& p, int procent)
{
	return procent >= (p.working_Shop * 100) / p.workshops;
}
template<typename T>
using Filter2 = bool(*)(const CS& g, T sost);
template<typename T>
vector<int>	FindCSByFilter(const map<int, CS>& p, Filter2<T> f, T param)
{
	vector <int> res;
	for (const auto& [k, v] : p)
	{
		if (f(v, param))
		{
			res.push_back(k);
		}
	}
	return res;
}
bool checkname(const pipe& p, std::string name)
{
	return p.name == name;
}
bool checkcondition(const pipe& p, bool condition)
{
	return p.condition == condition;
}
template<typename T>
using Filter = bool(*)(const pipe& p, T sost);
template<typename T>
vector<int> FindPipeByFilter(const map<int, pipe>& p, Filter<T> f, const T param)
{
	vector <int> res;
	for (const auto& [k, v] : p)
	{
		if (f(v, param))
		{
			res.push_back(k);
		}
	}
	return res;
}
template <typename T>
void showobject(const map<int,T>& p)
{
	if (p.size() == 0)
	{
		cout << "Объектов не существует."<<"\n";
	}
	else
	{
		for (const auto&[k,v]:p)
		{
			cout <<"id объекта: " << k << "\n";
			cout << v;
		}
	}
}
void save_in_file(const map <int,pipe>& p,const map <int,CS>& g)
{
	ofstream f_inf;
	f_inf.open("fileLR1.txt", ios::out);
	f_inf << p.size()<<'\n';
	for (const auto& [k, v] : p)
	{
		f_inf << k << endl;
		f_inf << v << endl;
	}
	f_inf << g.size() << '\n';
	for (const auto& [k,v] : g)
	{
		f_inf << k << "\n";
		f_inf << v << "\n";
	}
	f_inf.close();
		cout << "Данные сохранены в файл" << "\n";
	
}
void read_on_file(map<int,pipe>& p, map<int,CS>& g)
{ 
	ifstream f_inf;
	f_inf.open("fileLR1.txt", ios::in);
	//https://www.youtube.com/watch?v=aUP0eAEIxog
	if (!f_inf.is_open())
	{
		cout << "ошибка открытия файла";
	}
	else
	{
		//https://ru.stackoverflow.com/questions/1294751/%D0%9A%D0%B0%D0%BA-%D0%BF%D1%80%D0%BE%D0%B2%D0%B5%D1%80%D0%B8%D1%82%D1%8C-%D1%81%D1%83%D1%89%D0%B5%D1%81%D1%82%D0%B2%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8-%D0%B2-%D1%84%D0%B0%D0%B9%D0%BB%D0%B5
		cout << ("файл открыт") << "\n";
		int index;
		f_inf >> index;
		for (int i=0;i<index;i++)
		{
			int k;
			f_inf >> k;
			f_inf >> p[k];
		}
		f_inf >> index;
		for (int i=0;i<index;i++)
		{
			int k;
			f_inf >> k;
			f_inf >> g[k];
		}
	}
	f_inf.close();
}
void saveornotsave(const map<int,pipe>& p,const map <int,CS>& g, bool& sostsave)
{
	if (sostsave == false)
	{
		cout << "Сохранение не выполнено\n";
	}
	else
	{
		cout << "Вы заканчиваете работу не хотите сохранить изменения (1-да, 0-нет) \n";
		GetCorrectNumbers(sostsave);
		if (sostsave == true)
		{
			save_in_file(p, g);
		}
		else
		{
			cout << "Сохранение не выполнено\n";
		}
	}
}
void Deleteobject(map <int, pipe>& p, unsigned long long int idpmax, map<int, CS>& g, unsigned long long int idCSmax)
{
	bool ob;
	cout << "Выберете какой тип объекта будет удален (1-труба,0-станция)\n";
	GetCorrectNumbers(ob);
	if (ob = true)
	{
		if (p.size() != 0)
		{
			cout << "Введите номер объекта от :1 до: " << idpmax << "\n";
			int iddelete = GetCorrectNumber(1ull, idpmax) - 1;
			auto it = p.find(iddelete);
			if (it != p.end())
			{
				p.erase(iddelete);
				cout << "Объект удалён\n";
			}
			else
			{
				cout << "Объект уже был удален\n";
			}
		}
		else
		{
			cout << "Нет объектов трубы\n";
		}
	}
	else
	{
		if (g.size() != 0)
		{
			cout << "Введите номер объекта от :1 до: " << idCSmax << "\n";
			int iddelete = GetCorrectNumber(1ull, idCSmax)-1;
			auto it = p.find(iddelete);
			if (it != p.end())
			{
				g.erase(iddelete);
				cout << "Объект удалён\n";
			}
			else
			{
				cout << "Объект уже был удален\n";
			}
		}
		else
		{
			cout << "Нет объектов станции\n";
		}
	}
}
void showFilterMenu()
{
	cout << "1. Фильтр по имени труб\n"
		<< "2. Фильтр по состоянию труб\n"
		<< "3. Фильтр по имени станции\n"
		<< "4. Фильтр по проценту цехов\n";
}
void filterobject(map<int,pipe>& pipe_group,map <int,CS> cs_group)
{
showFilterMenu();
switch (GetCorrectNumber(0, 4))
	{
	case 1:
	{
		string name;
		cin.clear();
		cin.ignore();
		getline(cin, name);
		for (int i = 0;i < FindPipeByFilter(pipe_group, checkname, name).size();i++)
		{
			cout << pipe_group[FindPipeByFilter(pipe_group, checkname, name)[i]];
		}
		break;
	}
	case 2:
	{
		bool condition;
		GetCorrectNumbers(condition);
		for (int i = 0;i < FindPipeByFilter(pipe_group, checkcondition, condition).size();i++)
		{
			cout << pipe_group[FindPipeByFilter(pipe_group, checkcondition, condition)[i]];
		}
		break;
	}
	case 3:
	{
		string name;
		cin.clear();
		cin.ignore();
		getline(cin, name);
		for (int i = 0;i < FindCSByFilter(cs_group, checkCSname, name).size();i++)
		{
			cout << cs_group[FindCSByFilter(cs_group, checkCSname, name)[i]];
		}
		break;
	}
	case 4:
	{
		int procent;
		procent = GetCorrectNumber(0, 100);
		for (int i = 0;i < FindCSByFilter(cs_group, checkprocent, procent).size();i++)
		{
			cout << cs_group[FindCSByFilter(cs_group, checkprocent, procent)[i]];
		}
		break;
	}
	}
}
void menu()
{
	cout << "1.Добавить трубу\n"
		<< "2.Добавить компрессорную станцию\n"
		<< "3.Показать все объекты\n"
		<< "4.Редактировать состояние трубы\n"
		<< "5.Редактировать кол-во работающих цехов станции\n"
		<< "6.Сохранить\n"
		<< "7.Загрузить данные\n"
		<< "8.Удаление объекта\n"
		<< "9.Фильтр объектов\n"
		<<"10.Редактирование объектов с использованием фильтра\n"
		<< "0.Выход\n"
		<< "\n"
		<< "Выберите пункт меню: ";
}
int main()
{
	map<int,pipe> pipe_group;
	map<int, CS> cs_group;
	int idP=0;
	int idCS = 0;
	bool save = true;
	setlocale(LC_ALL, "Russian");//https://code-live.ru/post/cpp-russian-locale-for-windows-cmd/
	while (1)
	{
		menu();
		switch (GetCorrectNumber(0, 10))
		{
			case 1:
			{
				pipe p;
				cin >> p;
				pipe_group.emplace(idP,p);
				idP++;
				save = true;
				break;
			}
			case 2:
			{
				CS cs;
				cin >> cs;
				cs_group.emplace(idCS,cs);
				idCS++;
				save = true;
				break;
			}
			case 3:
			{
				showobject(pipe_group);
				showobject(cs_group);
				break;
			}
			case 4:
			{
				editPipe(SelectOB(pipe_group));
				save = true;
				break;
			}
			case 5:
			{
				SelectOB(cs_group).editStation();
				save = false;
				break;
			}
			case 6:
			{
				save_in_file(pipe_group, cs_group);
				save = false;
				break;
			}
			case 7:
			{
				read_on_file(pipe_group, cs_group);
				idCS = cs_group.size();
				idP = pipe_group.size();
				save = false;
				break;
			}
			case 8:
			{
				Deleteobject(pipe_group,idP, cs_group,idCS);
				save = true;
				break;
			}
			case 9:
			{
				filterobject(pipe_group, cs_group);
				break;
			}
			case 10:
			{
				bool condition;
				cout << "vvedite sostoianie objekta: ";
				GetCorrectNumbers(condition);
				vector <int> obj = FindPipeByFilter(pipe_group, checkcondition, condition);
				for (int i=0;i<obj.size();i++)
				{
					int k;
					cin >> k;
					if (obj[i]==k)
				}
				save = true;
				break;
			}
			case 0:
			{
				saveornotsave(pipe_group, cs_group,save);
				return 0;
				break;
			}
		}
	}
	return 0;
}