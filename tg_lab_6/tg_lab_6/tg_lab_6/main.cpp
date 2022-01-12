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
			cout << "\n������������ ��������! ���������� ��� ���: ";
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
		if (s.find_first_not_of("�������������������������������������Ũ��������������������������") != string::npos)
		{
			cout << "\n������������ ��������! ���������� ��� ���: ";
		}
		else
			return s;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "*********************\n������ ������\n\������������ ������ �6\n*********************\n";
	cout << "�������� ���������, 3630201/90002\n\n\n\n";

	RBTree tree;
	fstream f;
	string slovo;
	bool flag1 = true;
	bool flag2 = true;

	cout << "\n===============================������-������ ������===============================\n";
	while (flag1)
	{
		char q, k, l;
		cout << "\n*********************************************\n";
		cout << "***����***" << endl;
		cout << "[1] - ��������� �������;" << endl;
		cout << "[2] - �������� �����;" << endl;
		cout << "[3] - ������� �����;" << endl;
		cout << "[4] - ����� �����;" << endl;	
		cout << "[5] - ������� �������;" << endl;
		cout << "[6] - �������� ����� �� �����;" << endl;
		cout << "[7] - �������� �������;" << endl;
		cout << "[0] - �����." << endl;
		
		q = Input();


		switch (q)
		{
		case 1:
			cout << "\n***���������� �������***\n";
			cout << "\n�������� ����:" << endl;
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
				cout << "\n������������ ��������! ������� ��� ���!" << endl;
				break;
			}
			break;
		case 2:
			cout << "\n***���������� �����***\n";
			cout << "\n������� �����";
			slovo = InputWord();

			cout << "\n�����: " << slovo;
			tree.insert(slovo);
			tree.printInsert(slovo);
			cout << "�������� ��������:" << endl;
			cout << "[1] - ������� ���� �������" << endl;
			cout << "[2] - ����������." << endl;
			k = Input();

			switch (k)
			{
			case 1:
				tree.disp();
				break;
			case 2:
				break;
			default:
				cout << "\n������������ ��������! ������� ��� ���!" << endl;
				break;
			}
			break;
		case 3:
			cout << "\n***�������� �����***\n";
			cout << "\n������� �����";
			slovo = InputWord();
			if (tree.deleteOrNot(slovo))
				cout << "\n����� �������!" << endl;
			tree.deleteE(slovo);

			cout << endl;
			cout << "�������� ��������:" << endl;
			cout << "[1] - ������� ���� �������" << endl;
			cout << "[2] - ����������." << endl;
			k = Input();
			switch (k)
			{
			case 1:
				tree.disp();
				break;
			case 2:
				break;
			default:
				cout << "\n������������ ��������! ������� ��� ���!" << endl;
				break;
			}
			break;
		case 4:
			cout << "\n***����� �����***\n";
			cout << "\n������� �����:";
			slovo = InputWord();
			tree.searchE(slovo);
			break;
		case 5:
			cout << "\n***�������� �������***\n";
			tree.clear();
			cout << "\n������� ������!" << endl;
			break;
		case 6:
			cout << "\n***���������� ������ �� �����***\n";
			cout << "\n�������� ����:" << endl;
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
				cout << "\n������������ ��������! ������� ��� ���!" << endl;
				break;
			}
			break;
		case 7:
			cout << "\n***����� �������***\n";
			tree.disp();
			break;
		case 0:
			cout << "\n***�����***\n";
			flag1 = false;
			break;
		default:
			cout << "\n������������ ��������! ���������� ��� ���!" << endl;
			break;
		}
	}
	cout << "\n==================================================================================\n\n";

	cout << "\n===================================���-�������===================================\n";
	while (flag2)
	{
		char q, k, l;
		cout << "\n*********************************************\n";
		cout << "***����***" << endl;
		cout << "[1] - ��������� �������;" << endl;
		cout << "[2] - �������� �����;" << endl;
		cout << "[3] - ������� �����;" << endl;
		cout << "[4] - ����� �����;" << endl;
		cout << "[5] - �������� �������;" << endl;
		cout << "[0] - �����." << endl;

		q = Input();

		switch (q)
		{
		case 1:
			cout << "\n***���������� �������***\n";
			cout << "\n�������� ����:" << endl;
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
				cout << "\n������������ ��������! ������� ��� ���!" << endl;
				break;
			}
			break;
		case 2:
			cout << "\n***���������� �����***\n";
			cout << "\n������� �����";
			slovo = InputWord();

			cout << "\n�����: " << slovo << "\n\n";
			insert(slovo);

			cout << "�������� ��������:" << endl;
			cout << "[1] - ������� ���� �������" << endl;
			cout << "[2] - ����������." << endl;
			k = Input();

			switch (k)
			{
			case 1:
				disp();
				break;
			case 2:
				break;
			default:
				cout << "\n������������ ��������! ������� ��� ���!" << endl;
				break;
			}
			break;
		case 3:
			cout << "\n***�������� �����***\n";
			cout << "\n������� �����";
			slovo = InputWord();
			deleteOrNot(slovo);

			cout << endl;
			cout << "�������� ��������:" << endl;
			cout << "[1] - ������� ���� �������" << endl;
			cout << "[2] - ����������." << endl;
			k = Input();
			switch (k)
			{
			case 1:
				disp();
				break;
			case 2:
				break;
			default:
				cout << "\n������������ ��������! ������� ��� ���!" << endl;
				break;
			}
			break;
		case 4:
			cout << "\n***����� �����***\n";
			cout << "\n������� �����:";
			slovo = InputWord();
			searchE(slovo);
			break;
		case 5:
			cout << "\n***����� �������***\n";
			disp();
			break;
		case 0:
			cout << "\n***�����***\n";
			flag2 = false;
			break;
		default:
			break;
		}
	}
	cout << "\n==================================================================================\n\n";
	return 0;
}













