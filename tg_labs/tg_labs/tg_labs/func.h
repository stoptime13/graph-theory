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


//************************ЛАБОРАТОРНАЯ РАБОТА №1************************

int RandomGen(); // геометрическое распределение 2 (распределение Фарри)
int inputNumber(const char* string, const int min, const int max); // ввод числа

//==============МАТРИЦА СМЕЖНОСТИ, МАТРИЦЫ ВЕСОВ==============
void GraphCreation(); // генерация графа на основе заданного распределения (распределение Фарри)
void PrintGraph(); // печать матрицы смежности графа на консоль
void MatrixVesCreation(); // генерация матрицы положительных весов
void MatrixNegVesCreation(); // генерация матрицы отрицательных весов
void PrintMatrixV(); // печать матриц весов 
void MatrixVesInfinity();

//==============МЕТОД ШИМБЕЛЛА==============
void Shimbell(); // функция, реализующая метод Шимбелла
void PrintShimbell(vector<vector<int>> vec); // вывод матрицы Шимбелла
void Matrix(vector<vector<int>>& vec1, vector<vector<int>>& vec2, int path); // функция умножения двух матриц для метода Шимбелла

//==============ПОСТРОЕНИЕ МАРШРУТОВ==============
bool dfs(int u, int t, vector<bool>& visited, vector<vector<int>>& arr); // проверяем есть ли маршрут между двумя указанными вершинами
void PathExist(); // проверка существования маршрута
void NumberPath(int x, int y); // нахождение количества маршрутов

//**********************************************************************




//************************ЛАБОРАТОРНАЯ РАБОТА №2************************

void AlgDijkstra(); // алгоритм Дейкстры поиска кратчайшего пути между двумя вершинами (длины дуг неотрицательны)
void AlgBellmanFord(); // алгоритм Беллмана-Форда
void AlgFloydWarshall(); // алгоритм Уоршалла
void CompareIt(bool l); // сравнение количества итераций для трех алгоритмов

//**********************************************************************




//************************ЛАБОРАТОРНАЯ РАБОТА №3************************

void ChangeOr(); // для изменения матрицы весов и матрицы смежности (из-за того, что алгоритмы выполняются на не орграфах!)
void ChangeUnOr();
void AlgPrim(); // алгоритм Прима для нахождения минимального остовного дерева
void AlgKruskal(); // алгоритм Краскала для нахождения минимального остовного дерева
void ThMatrixKirchhoff(); // матричная теорема Кирхгофа для нахождения остовных деревьев
int findMinor(vector<vector<int>> buffer, int x, int y, int size); // поиск минора для матричной теоремы Кирхгофа
void EnPrufer(); // кодирование с помощью кода Прюфера
void DePrufer(); // декодирование кода Прюфера

//**********************************************************************



//************************ЛАБОРАТОРНАЯ РАБОТА №4************************

struct edge
{
	int a;
	int b;
	int cost;
};
void MatrixCost(); // генерация матрицы стоимости
void MatrixCapacity(); // генерация матрицы пропускных способностей
int FordFulkerson(int s, int t); // алгоритм Форда-Фалкерсона
bool bfs(int** rGraph, int s, int t, int parent[]);
vector<int> BellmanFordPath(int**); // алгоритм поиска потока минимальной стоимости на основе алгоритма Беллмана-Форда
void MinCostMaxFlow(int b);

//**********************************************************************



//************************ЛАБОРАТОРНАЯ РАБОТА №5************************

//==============ЭЙЛЕРОВ ГРАФ==============
void EulerGraph();
int IsItEuler(vector<vector<int>> graph);
void EulerCycle();

//==============ГАМИЛЬТОНОВ ГРАФ==============
void GamiltonGraph();
bool IsItGamilton(vector<vector<int>> graph);
void GamiltonCycle();

//==============ЗАДАЧА КОММИВОЯЖЕРА==============
void TSP();

//**********************************************************************
