#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//функции станции
struct CS
{
	string name;
	int workshops=0,working_Shop=0,efficiency=0;
};

int efficiency(int kol_r, int kol)
{
	return (kol_r * 100) / kol;
}

int input_validation() //https://www.cyberforum.ru/cpp-beginners/thread2532252.html
{
	int id;
	while (!(cin >> id) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода повторите ввод;" << endl;
	}
	return id;
}

void inputStation(CS& cs1)
{
	if (cs1.workshops > 0)
	{
		cout << "Станция уже существует" << "\n";
	}
	else
	{
			cout << "Название станции: ";
			cin.clear();
			cin.ignore();
			getline(cin, cs1.name);
			cout << "Кол-во цехов: ";
			cs1.workshops= input_validation();
			cout << "Кол-во цехов в работе: ";
			cs1.working_Shop= input_validation();
			cs1.efficiency = efficiency(cs1.working_Shop, cs1.workshops);
	}
};
void checkCS(CS& cs1)
{
	while (cs1.workshops < 0) 
	{
		cout << "Кол-во цехов не может быть отрицательным: "<<"\n";
		cs1.workshops= input_validation();
	}
	while ((cs1.working_Shop > cs1.workshops) || (cs1.working_Shop < 0))
	{
		cout << "Кол-во рабочих цехов не может быть отрицательным: ";
		cs1.working_Shop= input_validation();
		cs1.efficiency = efficiency(cs1.working_Shop, cs1.workshops);
	}
}
void OutputStation(CS& cs1)
{
	//inputStation(cs1);
	//checkCS(cs1);
	if (cs1.workshops > 0)
	{
		cout << "Название станции: " << cs1.name << "\n";
		cout << "К-во цехов: " << cs1.workshops << "\n";
		cout << "К-во работающих цехов: " << cs1.working_Shop << "\n";
		cout << "Эффектичность работы станции: " << cs1.efficiency << "%" << "\n";
	}
	else
	{
		cout << "Компрессорная станция не создана"<<"\n";
	}
	system("pause");
};
void editStation(CS& cs1)
{
	if (cs1.workshops > 0)
	{
		cout << "Введите к-во рабочих цехов: ";
		cs1.working_Shop= input_validation();
		cs1.efficiency = efficiency(cs1.working_Shop,cs1.workshops);
	}
}


//функции трубы
struct pipe
{
	int length=0;
    int diameter=0;
	bool condition;
};

void inputPipe(pipe& P1)
{
	if (P1.length > 0)
	{
		cout << "Труба уже создана" << "\n";
	}
	else
	{
		cout << "Длинна трубы в метрах: ";
		P1.length= input_validation();
		cout << "Диаметр трубы в метрах: ";
		P1.diameter= input_validation();
		cout << "Состояние трубы: ";
		P1.condition= input_validation();
	}
		
};
void checkPipe(pipe& p)
{
	while (p.length <= 0)
	{
		cout << "Повторите ввод длинны трубы так как значение отрицательное: ";
		p.length= input_validation();
	}
	while (p.diameter <= 0)
	{
		cout << "Повторите ввод диаметра трубы так, как значение отрицательное: ";
		p.diameter= input_validation();
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
void OutputPipe(pipe& p)
{
	if (p.length > 0) 
	{	
		cout << "длинна трубы: " << p.length << "\n"
			<< "диаметр трубы: " << p.diameter << "\n"
			<< "Состояние трубы: ";
		if (p.condition == true)
		{
			cout << "труба в ремонте" << "\n";
		}
		else
		{
			cout << "труба в работе" << "\n";
		}
	}
	else
	{
		cout << "Труба не создана"<<"\n";
	}
	system("pause");
};


//меню
void menu()
{
	cout << "1.Добавить трубу\n"
		<< "2.Добавить компрессорную станцию\n"
		<< "3.Показать все объекты\n"
		<< "4.Редактировать состояние трубы\n"
		<< "5.Редактировать кол-во работающих цехов станции\n"
		<< "6.Сохранить\n"
		<< "7.Загрузить данные\n"
		<< "0.Выход\n"
		<< "\n";
}


//вывод всех объектов
void showALLobjects(pipe& p1,CS& cs1)
{
	OutputPipe(p1);
	OutputStation(cs1);
}


//работа с файлом
void save_in_file(const pipe& p1,const CS& cs1)
{
	if ((p1.length > 0)||(cs1.workshops>0))
	{
		ofstream f_inf;
		f_inf.open("fileLR1.txt", ios::out);
		f_inf << p1.length << "\n"
			<< p1.diameter << "\n"
			<< p1.condition << "\n"
			<< cs1.name << "\n"
			<< cs1.workshops << "\n"
			<< cs1.working_Shop << "\n"
			<< cs1.efficiency << "\n";
		f_inf.close();
		cout << "Данные сохранены в файл" << "\n";
	}
	else
	{
		cout << "Создайте объект";
	}
	system("pause");
}
void read_on_file(pipe& p1, CS& cs1)
{ 
	string none,noneinfile;
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
			f_inf >> p1.length
				>> p1.diameter
				>> p1.condition;
			f_inf.ignore();
			getline(f_inf, cs1.name);
			f_inf >> cs1.working_Shop
				>> cs1.workshops
				>> cs1.efficiency;
	}
	f_inf.close();
	system("pause");
}

void exitANDsave_in_file(const pipe& p1, const CS& cs1)
{
	bool yes_or_no;
	cout << "Вы выходите из программы не хотите сохранить введенные данные?";
	cin >> yes_or_no;
	if (yes_or_no == true)
	{
		save_in_file(p1, cs1);
	}
	else
	{
		cout << "Фаил остался без изменений";
	}
}

void saveornotsave(const pipe& p1, const CS& cs1, bool sostsave)
{
	if (sostsave == true)
	{
		cout << "Файл уже содержит эти данные сохранение не нужно";
	}
	else
	{
		save_in_file(p1, cs1);
	}
}

void exitandsaveornosave(const pipe& p1, const CS& cs1, bool sostsave)
{
	if (sostsave == false)
	{
		exitANDsave_in_file(p1, cs1);
	}
}



int main()
{
	pipe P;
	CS cs1;
	int id;
	bool save = true;
	//https://code-live.ru/post/cpp-russian-locale-for-windows-cmd/
	setlocale(LC_ALL, "Russian");
	do
	{
		system("cls");
		menu();
		cout << "Выберите пункт меню: ";
		id= input_validation();
			switch (id)
			{
				case 1:
					inputPipe(P);
					checkPipe(P);
					OutputPipe(P);
					save = false;
					break;
				case 2:
					inputStation(cs1);
					checkCS(cs1);
					OutputStation(cs1);
					save = false;
					break;
				case 3:
					showALLobjects(P, cs1);
					break;
				case 4:
					editPipe(P);
					OutputPipe(P);
					save = false;
					break;
				case 5:
					editStation(cs1);
					checkCS(cs1);
					OutputStation(cs1);
					save = false;
					break;
				case 6:
					saveornotsave(P, cs1,save);
					save = true;
					break;
				case 7:
					read_on_file(P, cs1);
					save = true;
					break;
				case 0:
					exitandsaveornosave(P, cs1, save);
					break;
			}
	} while (id != 0);
	return 0;
}