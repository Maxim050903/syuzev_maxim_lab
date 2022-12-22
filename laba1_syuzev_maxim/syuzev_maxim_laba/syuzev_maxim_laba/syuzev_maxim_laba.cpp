#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Cpipe.h"
#include "CS.h"
#include "Utilits.h"
#include "GRAPH.h"
#include <map>
#include <unordered_map>

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
bool checkdiameter(const pipe& p, int param)
{
	return p.diameter == param;
}
bool noUSED(unordered_map<int, GRAPH>& gr, int par)
{	
	auto prov = gr.find(par);
		if (prov != gr.end())
		{
			return false;
		}
		else
		{
			return true;
		}
	
}

void getend(unordered_map<int, GRAPH> gr, vector<int>& otv)
{
	vector<int> prov1;
	if (gr.size() != 0)
	{
		unordered_map<int, GRAPH> dr;
		dr = gr;
		for (auto& [k, v] : dr)
		{
			bool exist2 = false;
			for (auto& [k2, v2] : dr)
			{
				if (v.idvh == v2.idvih)
				{
					exist2 = true;
				}
			}
			if (!exist2)
			{
				for (int i = 0;i < gr.size();i++)
				{
					prov1.push_back(v.idvh);
					
				}
			}
		}
	}
	else
	{
		return;
	}
	for (int i = 0;i < prov1.size();i++)
		otv.push_back(prov1[i]);
}

void tosort2(unordered_map<int, GRAPH> gr,vector<int>& otv)
{
	vector<int> prov1;
	if (gr.size() != 0)
	{
		unordered_map<int, GRAPH> dr;
		dr = gr;
		for (auto& [k, v] : dr)
		{
			int prov = 0;
			bool exist = false;
			bool exist2 = false;
			for (auto& [k2, v2] : dr)
			{
				if (v.idvih == v2.idvh)
				{
					exist = true;
				}
				else
				{
					prov = v.idvih;
				}
				if (v.idvh == v2.idvih)
				{
					exist2 = true;
				}
			}
			if (!exist) 
			{
				for (auto& [k1, v2] : dr)
				{
					if (v2.idvih == prov)
					{
						gr.erase(k1);
					}
				}
			 otv.push_back(v.idvih);
			 break;
			}	
		}
		tosort2(gr, otv);
	}
	else
	{	
		return;
	}
getend(gr, otv);
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
int FindPipe(const map<int, pipe>& p, Filter <T> f, const T param,unordered_map <int,GRAPH>& gr)
{
	for (auto& [k, v] : p)
	{
		if (f(v, param) && checkcondition(v,false) && noUSED(gr,k))
		{
			return k;
			break;
		}
	}
	return -1;
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


void deleteGraphVertex(unordered_map<int, GRAPH>& gr, int iddelete)
{
	unordered_map<int, GRAPH> gp;
	gp = gr;
	for (auto& [k, v] : gp)
	{
		if ((v.idvh == iddelete) || (v.idvih == iddelete))
			gr.erase(k);
	}
}

void Deleteobject(map <int, pipe>& p, unsigned long long int idpmax, map<int, CS>& g, unsigned long long int idCSmax,unordered_map<int,GRAPH>& gr)
{
	bool ob;
	cout << "Выберете какой тип объекта будет удален (1-труба,0-станция)\n";
	GetCorrectNumbers(ob);
	if (ob == true)
	{
		if (p.size() != 0)
		{
			cout << "Введите номер объекта от :0 до: " << idpmax-1 << "\n";
			int iddelete = GetCorrectNumber(0ull, idpmax-1);
			auto it = p.find(iddelete);
			if (it != p.end())
			{
				p.erase(iddelete);
				if (gr.size() != 0)
				{
					gr.erase(iddelete);
				}
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
	if (ob == false)
	{
		if (g.size() != 0)
		{
			cout << "Введите номер объекта от :0 до: " << idCSmax-1 << "\n";
			int iddelete = GetCorrectNumber(0ull, idCSmax-1);
			auto it = g.find(iddelete);
			if (it != g.end())
			{
				g.erase(iddelete);
				if (gr.size() != 0)
				{
					deleteGraphVertex(gr,iddelete);
				}
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


void saveGRAPH(unordered_map<int,GRAPH> gr)
{
	ofstream f_inf;
	f_inf.open("LR1.txt", ios::out);
	f_inf << gr.size() << '\n';
	for (const auto& [k, v] : gr)
	{
		f_inf << k << endl;
		f_inf << v << endl;
	}
	f_inf.close();
	cout << "Данные сохранены в файл" << "\n";

}
void readGraphInfile(unordered_map<int, GRAPH>& gr)
{
	ifstream f_inf;
	f_inf.open("LR1.txt", ios::in);
	int kol;
	f_inf >> kol;
	for (int i = 0;i < kol;i++)
	{
		int key;
		f_inf >> key;
		f_inf >> gr[key];
	}
	f_inf.close();
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

int makepipe(map <int, pipe>& pipe_group,int& idP)
{
	pipe p;
	cout << "Создайте трубу с нужным диаметром\n";
	cin >> p;
	pipe_group.emplace(idP, p);
	return idP;
}

void makeGRAPH(unordered_map <int, GRAPH>& graph, map<int,pipe>& pipe_group,const map<int, CS>& cs_group,int& idP)
{
	vector <int> neighbours;
	unordered_map <int,vector<int>> to_sort;
	int idout;
	cout << "Ввелите id выхода\n";
	int kol = cs_group.size();
	idout = GetCorrectNumber(0, kol);
	int idin;
	cout << "Введите id входа\n";
	idin = CorrectVertex(0,kol,idout);
	int diameter;
	cout << "Введите диаметр \n";
	cin >> diameter;
	int idpipe;
	idpipe = FindPipe(pipe_group, checkdiameter, diameter,graph);
	GRAPH gr;
	gr.idvh = idin;
	gr.idvih = idout;
	neighbours.push_back(gr.idvh);
	to_sort.emplace(gr.idvih, neighbours);
	if (idpipe != -1)
	{
		graph.emplace(idpipe, gr);
	}
	else
	{
		cout << "Труба не найдена. Создайте трубу\n";
		graph.emplace(makepipe(pipe_group,idP), gr);
		idP++;
	}
}

void printGRAPH(unordered_map <int, GRAPH> gr)
{
	for (auto& [k, v] : gr)
	{
		cout << k << " ";
		cout << gr[k];
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
		<< "10.Редактирование объектов с использованием фильтра\n"
		<< "11.Соединене КС\n"
		<< "12.Вывести граф\n"
		<< "0.Выход\n"
		<< "\n"
		<< "Выберите пункт меню: ";
}
int main()
{
	unordered_map<int, GRAPH> graph;
	map<int,pipe> pipe_group;
	map<int, CS> cs_group;
	int idP=0;
	int idCS = 0;
	bool save = false;
	setlocale(LC_ALL, "Russian");//https://code-live.ru/post/cpp-russian-locale-for-windows-cmd/
	while (1)
	{
		menu();
		switch (GetCorrectNumber(0, 15))
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
				Deleteobject(pipe_group,idP, cs_group,idCS,graph);
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
				save = true;
				break;
			}
			case 11:
			{
				makeGRAPH(graph,pipe_group,cs_group,idP);
				break;
			}
			case 12:
			{
				printGRAPH(graph);
				break;
			}
			case 13: 
			{
				vector<int> otv;
				tosort2(graph,otv);
				for (int i = 0;i < otv.size();i++)
					cout << otv[i]<<"-->";
				break;
			}
			case 14:
			{
				saveGRAPH(graph);
				break;
			}
			case 15:
			{
				readGraphInfile(graph);
				break;
			}
			case 0:
			{
				saveornotsave(pipe_group, cs_group,save);
				return 0;
				exit(0);
			}
		}
	}
	return 0;
}