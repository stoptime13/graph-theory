#include"stdafx.h"

#define INFINITY 999

extern vector<vector<int>> AdjacencyMatrix;
extern vector<vector<int>> MatrixVes;
extern vector<vector<int>> MatrixNegVes;
extern vector<vector<int>> AdjacencyMatrixInf;
extern vector<vector<int>> MatrixVesInf;
extern vector<vector<int>> GraphEuler;
extern vector<vector<int>> GraphGamilton;
extern vector<vector<int>> GraphGamiltonVes;
extern vector<pair<int, int>> path;
extern vector<int> deg;
extern int** CapacityMatrix;
extern int** CostMatrix;
extern int** Potok;
extern vector<set<int>>* MinOstov;
extern vector<int> PruferCode;
extern int numberVert;
extern int path_exist;
extern int it1, it2, it3, itP, itK, m;
extern bool FFl;


//************************������������ ������ �1************************

int RandomGen(); // �������������� ������������� 2 (������������� �����)
int inputNumber(const char* string, const int min, const int max); // ���� �����

//==============������� ���������, ������� �����==============
void GraphCreation(); // ��������� ����� �� ������ ��������� ������������� (������������� �����)
void PrintGraph(); // ������ ������� ��������� ����� �� �������
void MatrixVesCreation(); // ��������� ������� ������������� �����
void MatrixNegVesCreation(); // ��������� ������� ������������� �����
void PrintMatrixV(); // ������ ������ ����� 
void MatrixVesInfinity();

//==============����� ��������==============
void Shimbell(); // �������, ����������� ����� ��������
void PrintShimbell(vector<vector<int>> vec); // ����� ������� ��������
void Matrix(vector<vector<int>>& vec1, vector<vector<int>>& vec2, int path); // ������� ��������� ���� ������ ��� ������ ��������

//==============���������� ���������==============
bool dfs(int u, int t, vector<bool>& visited, vector<vector<int>>& arr); // ��������� ���� �� ������� ����� ����� ���������� ���������
void PathExist(); // �������� ������������� ��������
void NumberPath(int x, int y); // ���������� ���������� ���������

//**********************************************************************




//************************������������ ������ �2************************

void AlgDijkstra(); // �������� �������� ������ ����������� ���� ����� ����� ��������� (����� ��� ��������������)
void AlgBellmanFord(); // �������� ��������-�����
void AlgFloydWarshall(); // �������� ��������
void CompareIt(bool l); // ��������� ���������� �������� ��� ���� ����������

//**********************************************************************




//************************������������ ������ �3************************

void ChangeOr(); // ��� ��������� ������� ����� � ������� ��������� (��-�� ����, ��� ��������� ����������� �� �� ��������!)
void ChangeUnOr();
void AlgPrim(); // �������� ����� ��� ���������� ������������ ��������� ������
void AlgKruskal(); // �������� �������� ��� ���������� ������������ ��������� ������
void ThMatrixKirchhoff(); // ��������� ������� �������� ��� ���������� �������� ��������
int findMinor(vector<vector<int>> buffer, int x, int y, int size); // ����� ������ ��� ��������� ������� ��������
void EnPrufer(); // ����������� � ������� ���� �������
void DePrufer(); // ������������� ���� �������

//**********************************************************************



//************************������������ ������ �4************************

struct edge
{
	int a;
	int b;
	int cost;
};
void MatrixCost(); // ��������� ������� ���������
void MatrixCapacity(); // ��������� ������� ���������� ������������
int FordFulkerson(int s, int t); // �������� �����-����������
bool bfs(int** rGraph, int s, int t, int parent[]);
vector<int> BellmanFordPath(int**); // �������� ������ ������ ����������� ��������� �� ������ ��������� ��������-�����
void MinCostMaxFlow(int b);

//**********************************************************************



//************************������������ ������ �5************************

//==============������� ����==============
void EulerGraph();
int IsItEuler(vector<vector<int>> graph);
void EulerCycle();

//==============����������� ����==============
void GamiltonGraph();
bool IsItGamilton(vector<vector<int>> graph);
void GamiltonCycle();

//==============������ ������������==============
void TSP();

//**********************************************************************
