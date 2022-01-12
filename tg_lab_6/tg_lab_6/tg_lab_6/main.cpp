#include"stdafx.h"
#include"func.h"

map<char, vector<string>> HashTable;
vector<vector<string>> HashVector;
vector<char> number;
int count1;


int Input()
{
	string s;
	while (true)
	{
		cout << "\n>> ";
		cin >> s;
		if (s.find_first_not_of("1234567890") != string::npos)
		{
			cout << "\nНекорректное значение! Попробуйте еще раз: ";
		}
		else
			return atoi(s.c_str());
	}
}


string InputWord()
{
	string s;
	while (true)
	{
		cout << "\n>> ";
		cin >> s;
		if (s.find_first_not_of("абвгдеёжзийклмнопрстуфхцчшщъьыэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЫЭЮЯ") != string::npos)
		{
			cout << "\nНекорректное значение! Попробуйте еще раз: ";
		}
		else
			return s;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "*********************\nТеория графов\n\Лабораторная работа №6\n*********************\n";
	cout << "Коренова Анастасия, 3630201/90002\n\n\n\n";

	RBTree tree;
	fstream f;
	string slovo;
	bool flag1 = true;
	bool flag2 = true;

	cout << "\n===============================КРАСНО-ЧЕРНОЕ ДЕРЕВО===============================\n";
	while (flag1)
	{
		char q, k, l;
		cout << "\n*********************************************\n";
		cout << "***МЕНЮ***" << endl;
		cout << "[1] - построить словарь;" << endl;
		cout << "[2] - добавить слово;" << endl;
		cout << "[3] - удалить слово;" << endl;
		cout << "[4] - найти слово;" << endl;	
		cout << "[5] - удалить словарь;" << endl;
		cout << "[6] - добавить текст из файла;" << endl;
		cout << "[7] - показать словарь;" << endl;
		cout << "[0] - выход." << endl;
		
		q = Input();


		switch (q)
		{
		case 1:
			cout << "\n***Построение словаря***\n";
			cout << "\nВыберите файл:" << endl;
			cout << "[1] - Pushkin.txt;" << endl;
			cout << "[2] - Vegetables.txt;" << endl;
			cout << "[3] - Sheakspear.txt;" << endl;
			l = Input();

			switch (l)
			{
			case 1:
				tree.clear();
				tree.read("Pushkin.txt");
				tree.outFile("Pushkin.txt");
				tree.disp();
				break;
			case 2:
				tree.clear();
				tree.read("vegetables.txt");
				tree.outFile("vegetables.txt");
				tree.disp();
				break;
			case 3:
				tree.clear();
				tree.read("Sheakspear.txt");
				tree.outFile("Sheakspear.txt");
				tree.disp();
				break;
			default:
				cout << "\nНекорректное значение! Введите еще раз!" << endl;
				break;
			}
			break;
		case 2:
			cout << "\n***Добавление слова***\n";
			cout << "\nВведите слово";
			slovo = InputWord();

			cout << "\nСлово: " << slovo;
			tree.insert(slovo);
			tree.printInsert(slovo);
			cout << "Выберите действие:" << endl;
			cout << "[1] - вывести весь словарь" << endl;
			cout << "[2] - продолжить." << endl;
			k = Input();

			switch (k)
			{
			case 1:
				tree.disp();
				break;
			case 2:
				break;
			default:
				cout << "\nНекорректное значение! Введите еще раз!" << endl;
				break;
			}
			break;
		case 3:
			cout << "\n***Удаление слова***\n";
			cout << "\nВведите слово";
			slovo = InputWord();
			if (tree.deleteOrNot(slovo))
				cout << "\nСлово удалено!" << endl;
			tree.deleteE(slovo);

			cout << endl;
			cout << "Выберите действие:" << endl;
			cout << "[1] - вывести весь словарь" << endl;
			cout << "[2] - продолжить." << endl;
			k = Input();
			switch (k)
			{
			case 1:
				tree.disp();
				break;
			case 2:
				break;
			default:
				cout << "\nНекорректное значение! Введите еще раз!" << endl;
				break;
			}
			break;
		case 4:
			cout << "\n***Поиск слова***\n";
			cout << "\nВведите слово:";
			slovo = InputWord();
			tree.searchE(slovo);
			break;
		case 5:
			cout << "\n***Удаление словаря***\n";
			tree.clear();
			cout << "\nСловарь удален!" << endl;
			break;
		case 6:
			cout << "\n***Добавление текста из файла***\n";
			cout << "\nВыберите файл:" << endl;
			cout << "[1] - Pushkin.txt;" << endl;
			cout << "[2] - Vegetables.txt;" << endl;
			cout << "[3] - Sheakspear.txt;" << endl;
			l = Input();

			switch (l)
			{
			case 1:
				tree.outFile("Pushkin.txt");
				tree.disp();
				break;
			case 2:
				tree.outFile("vegetables.txt");
				tree.disp();
				break;
			case 3:
				tree.outFile("Sheakspear.txt");
				tree.disp();
				break;
			default:
				cout << "\nНекорректное значение! Введите еще раз!" << endl;
				break;
			}
			break;
		case 7:
			cout << "\n***Вывод словаря***\n";
			tree.disp();
			break;
		case 0:
			cout << "\n***Выход***\n";
			flag1 = false;
			break;
		default:
			cout << "\nНекорректное значение! Попробуйте еще раз!" << endl;
			break;
		}
	}
	cout << "\n==================================================================================\n\n";

	cout << "\n===================================ХЭШ-ТАБЛИЦА===================================\n";
	while (flag2)
	{
		char q, k, l;
		cout << "\n*********************************************\n";
		cout << "***МЕНЮ***" << endl;
		cout << "[1] - построить словарь;" << endl;
		cout << "[2] - добавить слово;" << endl;
		cout << "[3] - удалить слово;" << endl;
		cout << "[4] - найти слово;" << endl;
		cout << "[5] - показать словарь;" << endl;
		cout << "[0] - выход." << endl;

		q = Input();

		switch (q)
		{
		case 1:
			cout << "\n***Построение словаря***\n";
			cout << "\nВыберите файл:" << endl;
			cout << "[1] - products.txt;" << endl;
			cout << "[2] - murakami.txt;" << endl;
			cout << "[3] - gaiman.txt;" << endl;
			l = Input();

			switch (l)
			{
			case 1:
				HashTable.clear();
				read("products.txt");
				outFile("products.txt");
				disp();
				break;
			case 2:
				HashTable.clear();
				read("murakami.txt");
				outFile("murakami.txt");
				disp();
				break;
			case 3:
				HashTable.clear();
				read("gaiman.txt");
				outFile("gaiman.txt");
				disp();
				break;
			default:
				cout << "\nНекорректное значение! Введите еще раз!" << endl;
				break;
			}
			break;
		case 2:
			cout << "\n***Добавление слова***\n";
			cout << "\nВведите слово";
			slovo = InputWord();

			cout << "\nСлово: " << slovo << "\n\n";
			insert(slovo);

			cout << "Выберите действие:" << endl;
			cout << "[1] - вывести весь словарь" << endl;
			cout << "[2] - продолжить." << endl;
			k = Input();

			switch (k)
			{
			case 1:
				disp();
				break;
			case 2:
				break;
			default:
				cout << "\nНекорректное значение! Введите еще раз!" << endl;
				break;
			}
			break;
		case 3:
			cout << "\n***Удаление слова***\n";
			cout << "\nВведите слово";
			slovo = InputWord();
			deleteOrNot(slovo);

			cout << endl;
			cout << "Выберите действие:" << endl;
			cout << "[1] - вывести весь словарь" << endl;
			cout << "[2] - продолжить." << endl;
			k = Input();
			switch (k)
			{
			case 1:
				disp();
				break;
			case 2:
				break;
			default:
				cout << "\nНекорректное значение! Введите еще раз!" << endl;
				break;
			}
			break;
		case 4:
			cout << "\n***Поиск слова***\n";
			cout << "\nВведите слово:";
			slovo = InputWord();
			searchE(slovo);
			break;
		case 5:
			cout << "\n***Вывод словаря***\n";
			disp();
			break;
		case 0:
			cout << "\n***Выход***\n";
			flag2 = false;
			break;
		default:
			break;
		}
	}
	cout << "\n==================================================================================\n\n";
	return 0;
}













