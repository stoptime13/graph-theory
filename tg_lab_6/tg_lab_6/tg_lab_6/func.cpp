#include"func.h"

FILE* pFile;
fstream f;

//====================���� ������====================

Node* Node::uncle()
{
	if (parent == NULL || parent->parent == NULL)
		return NULL;

	if (parent->onLeft())
		return parent->parent->right;
	else
		return parent->parent->left;
}

Node* Node::subling()
{
	if (parent == NULL)
		return NULL;

	if (onLeft())
		return parent->right;

	return parent->left;
}

void Node::moveDown(Node* nParent)
{
	if (parent != NULL)
	{
		if (onLeft())
			parent->left = nParent;
		else
			parent->right = nParent;
	}

	nParent->parent = parent;
	parent = nParent;
}

bool Node::redChild()
{
	return ((left != NULL && left->color == RED) || (right != NULL && right->color == RED));
}


//====================������====================

void RBTree::leftR(Node* x)
{
	Node* parent = x->right;
	if (x == root)
		root = parent;

	x->moveDown(parent);

	x->right = parent->left;
	if (parent->left != NULL)
		parent->left->parent = x;

	parent->left = x;
}

void RBTree::rightR(Node* x)
{
	Node* parent = x->left;
	if (x == root)
		root = parent;

	x->moveDown(parent);

	x->left = parent->right;
	if (parent->right != NULL)
		parent->right->parent = x;

	parent->right = x;
}

void RBTree::chColor(Node* x1, Node* x2)
{
	COLOR cl;
	cl = x1->color;
	x1->color = x2->color;
	x2->color = cl;
}

void RBTree::chValue(Node* x1, Node* x2)
{
	string str;
	str = x1->value;
	x1->value = x2->value;
	x2->value = str;
}

void RBTree::fixRed(Node* x)
{
	if (x == root)
	{
		x->color = BLACK;
		return;
	}

	Node* parent = x->parent;
	Node* grandparent = parent->parent;
	Node* uncle = x->uncle();

	if (parent->color != BLACK)
	{
		if (uncle != NULL && uncle->color == RED)
		{
			parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			fixRed(grandparent);
		}
		else
		{
			if (parent->onLeft())
			{
				if (x->onLeft())
					chColor(parent, grandparent);
				else
				{
					leftR(parent);
					chColor(x, grandparent);
				}
				rightR(grandparent);
			}
			else
			{
				if (x->onLeft())
				{
					rightR(parent);
					chColor(x, grandparent);
				}
				else
					chColor(parent, grandparent);
				leftR(grandparent);
			}
		}
	}
}

void RBTree::deleteNode(Node* x)
{
	Node* y = BSTreeplace(x);
	Node* parent = x->parent;

	bool xyBlack = ((y == NULL || y->color == BLACK) && (x->color == BLACK));

	if (y == NULL)
	{
		if (x == root)
			root = NULL;
		else
		{
			if (xyBlack)
				fixDBlack(x);
			else
			{
				if (x->subling() != NULL)
					x->subling()->color = RED;
			}

			if (x->onLeft()) 
				parent->left = NULL;
			else 
				parent->right = NULL;
		}
		delete x;
		return;
	}

	if (x->left == NULL || x->right == NULL)
	{
		if (x == root)
		{
			x->value = y->value;
			x->left = x->right = NULL;
			delete y;
		}
		else
		{
			if (x->onLeft())
			{
				parent->left = y;
				parent->place = 0;
			}
			else
			{
				parent->right = y;
				parent->place = 1;
			}
			delete x;

			y->parent = parent;
			if (xyBlack)
				fixDBlack(y);
			else
				y->color = BLACK;
		}
		return;
	}
	chValue(y, x);
	deleteNode(y);
}

void RBTree::fixDBlack(Node* x)
{
	if (x == root)
		return;

	Node* subling = x->subling();
	Node* parent = x->parent;

	if (subling == NULL)
	{
		fixDBlack(parent);
	}
	else
	{
		if (subling->color == RED)
		{
			parent->color = RED;
			subling->color = BLACK;
			if (subling->onLeft())
				rightR(parent);
			else
				leftR(parent);
			fixDBlack(x);
		}
		else
		{
			if (subling->redChild())
			{
				if (subling->left != NULL and subling->left->color == RED) {
					if (subling->onLeft()) 
					{
						subling->left->color = subling->color;
						subling->color = parent->color;
						rightR(parent);
					}
					else
					{
						subling->left->color = parent->color;
						rightR(subling);
						leftR(parent);
					}
				}
				else 
				{
					if (subling->onLeft())
					{
						subling->right->color = parent->color;
						leftR(subling);
						rightR(parent);
					}
					else 
					{
						subling->right->color = subling->color;
						subling->color = parent->color;
						leftR(parent);
					}
				}
				parent->color = BLACK;
			}
			else
			{
				subling->color = RED;
				if (parent->color == BLACK)
					fixDBlack(parent);
				else
					parent->color = BLACK;
			}
		}
	}
}

void RBTree::levelOrder(Node* x)
{
	if (x == NULL)
		return;

	queue<Node*> q;
	Node* cur;

	q.push(x);

	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		cout << cur->value << " ";

		if (cur->left != NULL)
			q.push(cur->left);
		if (cur->right != NULL)
			q.push(cur->right);
	}
}

void RBTree::inorder(Node* x)
{
	if (x == NULL)
		return;
	inorder(x->left);

	cout << x->value << " ";
	
	inorder(x->right);
}

Node* RBTree::success(Node* x)
{
	Node* temp = x;
	while (temp->left != NULL)
		temp = temp->left;
	
	return temp;
}

Node* RBTree::BSTreeplace(Node* x)
{
	if (x->left != NULL && x->right != NULL)
		return success(x->right);

	if (x->left == NULL && x->right == NULL)
		return NULL;

	if (x->left != NULL)
		return x->left;
	else
		return x->right;
}

Node* RBTree::search(string str)
{
	Node* tmp = root;
	while (tmp != NULL)
	{
		if (str < tmp->value)
		{
			if (tmp->left == NULL)
				break;
			else
				tmp = tmp->left;
		}
		else if (str == tmp->value)
			break;
		else
		{
			if (tmp->right == NULL)
				break;
			else
				tmp = tmp->right;
		}
	}

	return tmp;
}


void RBTree::insert(string str)
{
	Node* newNode = new Node(str);

	if (root == NULL)
	{
		newNode->color = BLACK;
		root = newNode;
	}
	else
	{
		Node* tmp = search(str);
		if (tmp->value == str)
		{
			cout << "����� ��� ������������ � �������!" << endl;
			cout << "������������: " << endl;
			return;
		}
		newNode->parent = tmp;

		if (str < tmp->value)
			tmp->left = newNode;
		else
			tmp->right = newNode;

		fixRed(newNode);
	}
}

void RBTree::insertF(string str)
{
	Node* newNode = new Node(str);

	if (root == NULL)
	{
		newNode->color = BLACK;
		root = newNode;
	}
	else
	{
		Node* tmp = search(str);
		if (tmp->value == str)
		{
			return;
		}
		newNode->parent = tmp;

		if (str < tmp->value)
			tmp->left = newNode;
		else
			tmp->right = newNode;

		fixRed(newNode);
	}
}

void RBTree::deleteE(string str)
{
	if (root == NULL)
		return;

	Node* node = search(str);

	if (node->value != str)
	{
		cout << "����� " << str << " �� ���� ������� � �������!" << endl;
		return;
	}
	deleteNode(node);
}

bool RBTree::deleteOrNot(string str)
{
	
	Node* node = search(str);

	if (node == NULL)
	{
		cout << "\n\n������� ������!" << endl;
		return false;
	}
	if (node->value == str)
		return true;
	else
		return false;
}

void RBTree::searchE(string str)
{
	Node* node = search(str);
	
	if (node->value == str)
	{
		cout << "\n����� '" << str << "' ���� � �������!" << endl;
		cout << endl << "����: ";
		if (node->color == BLACK)
			cout << "������." << endl;
		else
			cout << "�������." << endl;
		if (node->parent != NULL)
			cout << "��������: " << node->parent->value << ".";
		else
			cout << "�������� ������.";
		if (node->right != NULL)
			cout << endl << "������: " << node->right->value << ".";
		else
			cout << endl << "������: NIL Leaves\n ����: ������.\n" << "��������: NULL.";
		if (node->left != NULL)
			cout << "\n�����: " << node->left->value;
		else
			cout << endl << "�����: NIL Leaves\n ����: ������.\n" << " ��������: NULL.";
		cout << endl;
	}
	else
	{
		cout << "\n����� '" << str << "' ��� � �������!" << endl;
	}
}

void RBTree::clear()
{
	while (root != NULL)
	{
		deleteE(root->value);
	}
}

void RBTree::read(string str)
{
	string s;	
	ifstream file(str);

	while (getline(file, s))
	{
		cout << "\n����� �����:\n";
		cout << s << endl;
	}
	
	file.close();
}

void RBTree::outFile(string str)
{
	string s1, s2;
	ifstream file(str);
	string f_element(""", .; :!? )(\ / ");

	while (getline(file, s1, ' '))
	{
		s2 = s1;
		if (s2.find_first_of(""", .; :!? )(\ /") != string::npos)
			s1.erase(s1.end() - 1);
		
		insertF(s1);
	}

	file.close();
}

void RBTree::disp()
{
	display(root);
}

void RBTree::display(Node* x)
{
	if (root == NULL)
	{
		cout << "\n\n������� ������!";
		return;
	}
	if (x != NULL)
	{
		cout << "\n�����: " << x->value;
		cout << "\n����: ";
		if (x->color == BLACK)
			cout << "������.";
		else
			cout << "�������.";
		if (x->parent != NULL)
			cout << "\n��������: " << x->parent->value << ".";
		else
			cout << "\n�������� ������.";
		if (x->right != NULL)
			cout << "\n������: " << x->right->value;
		else
			cout << "\n������: NIL Leaves\n ����: ������.\n" << " ��������: NULL.";
		if (x->left != NULL)
			cout << "\n�����: " << x->left->value;
		else
			cout << "\n�����:  NIL Leaves\n ����: ������.\n" << " ��������: NULL.";
		cout << endl;
		if (x->left)
		{
			cout << "\n\n����:\n";
			display(x->left);
		}

		if (x->right)
		{
			cout << "\n\n�����:\n";
			display(x->right);
		}
	}
}

void RBTree::printInsert(string str)
{
	Node* node = search(str);

	cout << "\n����: ";
	if (node->color == BLACK)
		cout << "������.";
	else
		cout << "�������.";
	if (node->parent != NULL)
		cout << "\n��������: " << node->parent->value << ".";
	else
		cout << "\n�������� ������.";
	if (node->right != NULL)
		cout << "\n������: " << node->right->value;
	else
		cout << "\n����: ������.\n" << "��������: NULL.";
	if (node->left != NULL)
		cout << "\n�����: " << node->left->value;
	else
		cout << "\n����: ������.\n" << "��������: NULL.\n";
	cout << endl;
}


//**********************���-�������**************************
void read(string str)
{
	string s;
	ifstream file(str);

	while (getline(file, s))
	{
		cout << "\n����� �����:\n";
		cout << s << endl;
	}

	file.close();
}

void outFile(string str)
{
	string s1, s2;
	ifstream file(str);
	string f_element(""", .; :!? )(\ / ");

	while (getline(file, s1, ' '))
	{
		s2 = s1;
		if (s2.find_first_of(""", .; :!? )(\ /") != string::npos)
			s1.erase(s1.end() - 1);

		//insert(s1);
		insertF(s1);

	}

	file.close();
}

void insertF(string str)
{
	HashVector.push_back(vector<string>());
	if (HashTable.find(str[0]) == HashTable.end())
	{
		HashVector[count1].push_back(str);
		HashTable[str[0]] = HashVector[count1];
		number.push_back(str[0]);
		count1 += 1;
	}
	else
	{
		for (int i = 0; i < number.size(); i++)
		{
			if (number[i] == str[0])
			{
				HashVector[i].push_back(str);
				HashTable[str[0]] = HashVector[i];
			}
		}
	}
}

void disp()
{
	cout << "\n\n";
	cout << "***�������***\n";
	auto it = HashTable.begin();
	for (it = HashTable.begin(); it != HashTable.end(); it++)
	{
		cout << it->first << ": ";
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
}

void insert(string str)
{
	HashVector.push_back(vector<string>());
	if (HashTable.find(str[0]) == HashTable.end())
	{
		HashVector[count1].push_back(str);
		HashTable[str[0]] = HashVector[count1];
		number.push_back(str[0]);
		count1 += 1;
	}
	else
	{
		for (int i = 0; i < number.size(); i++)
		{
			if (number[i] == str[0])
			{
				if (find(HashVector[i].begin(), HashVector[i].end(), str) == HashVector[i].end())
				{
					HashVector[i].push_back(str);
					HashTable[str[0]] = HashVector[i];
				}
				else
				{
					cout << "����� '" << str << "' ��� ������������ � �������!" << endl;
					return;
				}
			}
		}
	}
}

void deleteOrNot(string str)
{
	HashVector.push_back(vector<string>());
	if (HashTable.find(str[0]) == HashTable.end())
	{
		cout << "\n����� '" << str << "' ����������� � �������!" << endl;
	}
	else
	{
		for (int i = 0; i < number.size(); i++)
		{
			if (number[i] == str[0])
			{
				auto it = find(HashVector[i].begin(), HashVector[i].end(), str);
				if (it == HashVector[i].end())
				{
					cout << "����� '" << str << "' ����������� � �������!" << endl;
				}
				else
				{
					HashVector[i].erase(it);
					HashTable[str[0]] = HashVector[i];
					cout << "\n����� �������!" << endl;
				}
				if (HashVector[i].size() == 0)
					HashTable.erase(str[0]);
			}
		}
	}
}

void searchE(string str)
{
	HashVector.push_back(vector<string>());
	if (HashTable.find(str[0]) == HashTable.end())
	{
		cout << "\n����� '" << str << "' ����������� � �������!" << endl;
	}
	else
	{
		for (int i = 0; i < number.size(); i++)
		{
			if (number[i] == str[0])
			{
				auto it = find(HashVector[i].begin(), HashVector[i].end(), str);
				if (it == HashVector[i].end())
				{
					cout << "\n����� '" << str << "' ����������� � �������!" << endl;
				}
				else
				{
					cout << "\n����� �������!" << endl << endl;
					auto itt = HashTable.find(str[0]);
					cout << (*itt).first << ": ";
					for (int i = 0; i < itt->second.size(); i++)
					{
						cout << itt->second[i] << " ";
					}
					cout << endl;
				}
			}
		}
	}
}