#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//функции станции
struct CS
{
	string name;
	int workshops=0,working_Shop=0,efficiency=0;
};
struct pipe
{
	int length = 0;
	int diameter = 0;
	bool condition = 0;
};
template <typename T>
T GetCorrectNumber(T min, T max)
{
	T x;
	while ((cin >> x).fail() || x<min || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "oshibka";
	}
	return x;
}
template <typename V>
void GetCorrectNumbers(V& x)
{
	while ((cin >> x).fail()|| x<0)
	{
		cout << "oshibka vvoda dannih";
		cin.clear();
		cin.ignore(10000, '\n');
	}
}
template <typename OB>
OB& SelectOB(vector<OB>& g)
{
	cout << "ddtlbnt byltrc ";
	unsigned long long int index = GetCorrectNumber(1ull, (g.size()));
	return g[index-1];
}
istream& operator >> (istream& in, CS& cs)
{
	if (cs.workshops > 0)
	{
		cout << "Станция уже существует" << "\n";
	}
	else
	{
		cout << "Название станции: ";
		cin.clear();
		cin.ignore();
		getline(cin, cs.name);
		cout << "Кол-во цехов: ";
		GetCorrectNumbers(cs.working_Shop);
		cout << "Кол-во цехов в работе: ";
		cs.workshops = GetCorrectNumber(0, cs.working_Shop);
		cout << "Введите значение эффективности станции от 0 до 100";
		cs.efficiency = GetCorrectNumber(0, 100);
	}
	return in;
}
ostream& operator <<(ostream& out, const pipe& p)
{
	if (p.length > 0)
	{
		out << "длинна трубы: " << p.length << "\n"
			<< "диаметр трубы: " << p.diameter << "\n"
			<< "Состояние трубы: ";
		if (p.condition == true)
		{
			out << "труба в ремонте" << "\n";
		}
		else
		{
			out << "труба в работе" << "\n";
		}
	}
	else
	{
		out << "Труба не создана" << "\n";
	}
	return out;
}
istream& operator >> (istream& in, pipe& p)
{
	if (p.length > 0)
	{
		cout << "Труба уже создана" << "\n";
	}
	else
	{
		do
		{
			in.clear();
			in.ignore(10000, '\n');
			cout << "Длинна трубы в метрах: ";
			GetCorrectNumbers(p.length);
			cout << "Диаметр трубы в метрах: ";
			GetCorrectNumbers(p.diameter);
			cout << "Состояние трубы (0 труба в работе;другое значение труба в ремонте) : ";
			GetCorrectNumbers(p.condition);
		} while (cin.fail());
	}
	return in;
}
ostream& operator <<(ostream& out, const CS& cs)
{
	if (cs.workshops > 0)
	{
		cout << "Название станции: " << cs.name << "\n";
		cout << "К-во цехов: " << cs.workshops << "\n";
		cout << "К-во работающих цехов: " << cs.working_Shop << "\n";
		cout << "Эффектичность работы станции: " << cs.efficiency << "%" << "\n";
	}
	else
	{
		cout << "Компрессорная станция не создана" << "\n";
	}
	return out;
}
void editStation(CS& cs)
{
	if (cs.workshops > 0)
	{
		cout << "vvedite novoe kolvo cehov";
		cs.working_Shop=GetCorrectNumber(0, cs.workshops);
	}
}
void editPipe(pipe& P1)
{
	if (P1.length > 0)
	{
		if (P1.condition == 0)
		{
			P1.condition = true;
		}
		else
		{
			P1.condition = false;
		}
		cout << "Состояние трубы успешно изменено" << "\n";
	}
	
}
void showALLobjects(const vector<pipe>& p, const vector<CS>& g)
{
	unsigned long long int i;
	for (i = 0; i < p.size(); i++)
	{
		if (p[i].length > 0)
		{
			cout << "index:" << i + 1 << '\n' << p[i];
		}
		else
		{
			cout << "truba yt cjplfyf kb,j elfktyf";
		}
	}
	cout << "\n";
	for (i = 0;i < g.size();i++)
	{
		if (g[i].working_Shop > 0)
		{
			cout << "index:" << i + 1 << '\n' << g[i];
		}
		else
		{
			cout << "station not found";
		}
	}
	cout << "\n";
}


//работа с файлом
void save_in_file(const vector<pipe>& p,const vector<CS>& g)
{
	ofstream f_inf;
	f_inf.open("fileLR1.txt", ios::out);
	f_inf << p.size()<<'\n';
	unsigned long long int i;
	for (i = 0; i < p.size(); i++)
	{
		f_inf << p[i].length << "\n"
			<< p[i].diameter << "\n"
			<< p[i].condition << "\n";
	}
	f_inf << g.size() << '\n';
	for (i = 0; i < g.size(); i++)
	{
		f_inf<< g[i].name << "\n"
			<< g[i].workshops << "\n"
			<< g[i].working_Shop << "\n"
			<< g[i].efficiency << "\n";
	}
	f_inf.close();
		cout << "Данные сохранены в файл" << "\n";
	
}
void read_on_file(vector<pipe>& p, vector<CS>& g)
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
		unsigned long long int i;
		int index;
		f_inf >> index;
		p.resize(index); //https://bestprogrammer.ru/programmirovanie-i-razrabotka/kak-rasshirit-vektor-v-c
		for (i = 0;i < index;i++)
		{
			f_inf >> p[i].length
				>> p[i].diameter
				>> p[i].condition;
		}
		f_inf >> index;
		g.resize(index); //https://bestprogrammer.ru/programmirovanie-i-razrabotka/kak-rasshirit-vektor-v-c
		for (i = 0;i < index;i++)
		{
			f_inf.ignore();
			getline(f_inf, g[i].name);
			f_inf >> g[i].working_Shop
				>> g[i].workshops
				>> g[i].efficiency;
		}
	}
	f_inf.close();
}
void saveornotsave(vector<pipe>& p, vector<CS>& g, bool sostsave)
{
	if (sostsave == true)
	{
		cout << "Сохранение не выполнено";
	}
	else
	{
		save_in_file(p, g);
	}
}
void Deleteobject(vector<pipe>& p, vector<CS>& g)
{
	bool ob;
	cout << "viberete kakoi tip obecta budet udalen";
	GetCorrectNumbers(ob);
	if (ob = true)
	{
		cout << "vvedite index elementa";
		int iddelete = GetCorrectNumber(0ull, p.size());
		for (int i = iddelete;i < p.size()-1;i++)
		{
			p[i].length = p[i + 1].length;
			p[i].diameter = p[i + 1].diameter;
			p[i].condition = p[i + 1].condition;
		}
		p.resize(p.size() - 1);
	}
	else
	{
		cout << "vvedite index elementa";
		int iddelete = GetCorrectNumber(0ull, g.size());
		for (int i = iddelete;i < g.size() - 1;i++)
		{
			g[i].name = g[i + 1].name;
			g[i].workshops = g[i + 1].workshops;
			g[i].working_Shop = g[i + 1].working_Shop;
		}
		g.resize(g.size() - 1);
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
		<< "0.Выход\n"
		<< "\n"
		<< "Выберите пункт меню: ";
}

int main()
{
	vector <pipe> pipe_group;
	vector <CS> cs_group;
	bool save = true;
	setlocale(LC_ALL, "Russian");//https://code-live.ru/post/cpp-russian-locale-for-windows-cmd/
	while (1)
	{
		menu();
		
		switch (GetCorrectNumber(0, 9))
		{
			case 1:
			{
				pipe p;
				cin >> p;
				cout << p;
				pipe_group.push_back(p);
				save = false;
				break;
			}
			case 2:
			{
				CS cs;
				cin >> cs;
				cout << cs;
				cs_group.push_back(cs);
				save = false;
				break;
			}
			case 3:
			{
				showALLobjects(pipe_group,cs_group);
				break;
			}
			case 4:
			{
				editPipe(SelectOB(pipe_group));
				save = false;
				break;
			}
			case 5:
			{
				editStation(SelectOB(cs_group));
				save = false;
				break;
			}
			case 6:
			{
				save_in_file(pipe_group, cs_group);
				save = true;
				break;
			}
			case 7:
			{
				read_on_file(pipe_group, cs_group);
				save = true;
				break;
			}
			case 8:
			{
				Deleteobject(pipe_group,cs_group);
				save = false;
				break;
			}
			case 9:
			{
				//cout << Object_Search(pipe_group, cs_group);
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