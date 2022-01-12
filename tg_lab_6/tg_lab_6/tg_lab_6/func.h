#pragma once
#include"stdafx.h"

extern map<char, vector<string>> HashTable;
extern vector<vector<string>> HashVector;
extern vector<char> number;
extern int count1;

enum COLOR
{
	RED,
	BLACK
};

//====================УЗЕЛ ДЕРЕВА====================
class Node
{
public:
	string value;
	COLOR color;
	Node* left;
	Node* right;
	Node* parent;
	int place;

	Node(string value) :
		value(value)
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		color = RED;
	}

	Node* uncle();
	Node* subling();

	bool onLeft()
	{
		return (this == parent->left);
	}

	bool redChild();
	void moveDown(Node*	nParent);
};


//====================ДЕРЕВО====================
class RBTree
{
	Node* root;
	void leftR(Node* x); // левый поворот дерева
	void rightR(Node* x); // правый поворот дерева

	void chColor(Node* x1, Node* x2); // смена цвета
	void chValue(Node* x1, Node* x2); // смена значений при смене цвета

	void fixRed(Node* x);
	void deleteNode(Node* x);
	void fixDBlack(Node* x);
	void levelOrder(Node* x);
	void inorder(Node* x);

	Node* success(Node* x);
	Node* BSTreeplace(Node* x);

public:
	RBTree()
	{
		root = NULL;
	}
	
	Node* getRoot()
	{
		return root;
	}

	Node* search(string str);

	void insert(string str);
	void insertF(string str); // включение в словарь для первого раза, чтобы не было множественного выведения: слово уже прис...
	void deleteE(string str);
	void searchE(string str);
	void clear();
	bool deleteOrNot(string str);
	void outFile(string str);
	void display(Node* x);
	void disp();
	void printInsert(string str);
	void read(string str);
};

//**********************ХЭШ-ТАБЛИЦА**************************
void read(string str);
void outFile(string str);
void insertF(string str);
void disp();
void insert(string str);
void deleteOrNot(string str);
void searchE(string str);