#include"stdafx.h"
#include"func.h"

#define MAX 100
#define MIN 2

vector<vector<int>> AdjacencyMatrix; // ��������� ������������ ������, � ������� �������� ������� ���������
vector<vector<int>> MatrixVes; // ��������� ������������ ������, � ������� �������� ������� �����
vector<vector<int>> MatrixNegVes; // ��������� ������������ ������, � ������� �������� ������� ������������� �����
vector<vector<int>> AdjacencyMatrixInf; // ������� ���������, �� � ��������������� ������ ����� 
vector<vector<int>> MatrixVesInf; // ������� � �������������� ������, �� � ��������������� �����
vector<vector<int>> GraphEuler; // ���������� �� �������� �����
vector<vector<int>> GraphGamilton; // ���������� �� ������������ �����
vector<vector<int>> GraphGamiltonVes; // ����������� ����, �� � ������
vector<pair<int, int>> path;
vector<int> deg; // ������� ��� ������
int** CapacityMatrix = nullptr; // ������� ���������� ������������
int** CostMatrix = nullptr; // ������� ���������
int** Potok; // ������������ �����
vector<set<int>>* MinOstov = nullptr; // ����������� �����
vector<int> PruferCode; // ������ ��� ���� �������
int numberVert; // ���������� ������
int path_exist; // ���������� ���������
int it1, it2, it3, itP, itK, m = 0; // ��� ��������� ���������� ��������
bool FFl = true;


int main()
{
	srand(time(NULL));
	printf("*********************\nGRAPH THEORY\n\LAB 1-5\n*********************\n");
	printf("Korenova Anastasia, 3630201/90002\n\n\n\n");

	int inputMenu = 0;
	bool checkMenu = true;

	while (checkMenu)
	{
		printf("\n***MENU***\n");
		printf("Select an action:\n");
		printf("[1] - generate a new graph;\n");
		printf("[2] - Shimbel's method;\n");
		printf("[3] - build a route;\n");
		printf("[4] - Dijkstra's algorithm;\n");
		printf("[5] - Bellman-Ford algorithm;\n");
		printf("[6] - Floyd-Warshall algorithm;\n");
		printf("[7] - compare iterations;\n");
		printf("[8] - Prim's algorithm;\n");
		printf("[9] - Kruskal's algorithm;\n");
		printf("[a] - compare iterations for Prim's and Kruskal's algorithms;\n");
		printf("[b] - Kirchhoff's matrix theorem;\n");
		printf("[c] - Prufer encoding;\n");
		printf("[d] - Prufer decoding;\n");
		printf("[e] - generate cost matrix and capacity matrix;\n");
		printf("[f] - Ford-Fulkerson's algorithm;\n");
		printf("[j] - minimum value stream;\n");
		printf("[h] - is the original graph Eulerian or Hamiltonian;\n");
		printf("[i] - complete the graph to an Euler graph and construct an Euler cycle;\n");
		printf("[g] - complete the graph to an Gamiltonian graph;\n");
		printf("[k] - travelling salesman problem (TSP);\n");
		printf("[0] - exit.\n");
		printf("\n\nEntered value:\n> ");
		inputMenu = _getche();
		switch (inputMenu)
		{
		case'1':
		{
			printf("\n\n***Generate a new graph***");
			numberVert = inputNumber("\n\nEnter the number of vertices in the graph:", MIN, MAX); // ���� ���������� ������ �����
			GraphCreation();
			MatrixVesCreation();
			MatrixNegVesCreation();
			PrintGraph();
			PrintMatrixV();
			MatrixVesInfinity();
			break;
		}
		case'2':
			Shimbell();
			break;
		case'3':
			PathExist();
			break;
		case'4':
			AlgDijkstra();
			break;
		case'5':
			AlgBellmanFord();
			break;
		case'6':
			AlgFloydWarshall();
			break;
		case'7':
			CompareIt(true);
			break;
		case'8':
			ChangeUnOr();
			AlgPrim();
			ChangeOr();
			break;
		case'9':
			ChangeUnOr();
			AlgKruskal();
			ChangeOr();
			break;
		case'a':
			CompareIt(false);
			break;
		case'b':
			ChangeUnOr();
			ThMatrixKirchhoff();
			ChangeOr();
			break;
		case'c':
			EnPrufer();
			break;
		case'd':
			DePrufer();
			break;
		case'e':
			MatrixCost();
			MatrixCapacity();
			break;
		case'f':
			printf("\n\n***Ford-Falkerson's algorithm***\n");
			if (FordFulkerson(0, numberVert - 1) != 0)
				printf("\nMaximum flow: %d\n", FordFulkerson(0, numberVert - 1));
			break;
		case'j':
			printf("\n\n***Minimum value stream***\n");
			FFl = true;
			MinCostMaxFlow(2 * FordFulkerson(0, numberVert - 1) / 3);
			break;
		case'h':
			printf("\n\n***Is the original graph Eulerian or Hamiltonian?***\n");
			PrintGraph();
			EulerGraph();
			GamiltonGraph();
			break;
		case'i':
			printf("\n\n***Complete the graph to an Euler graph and construct an Euler cycle***\n");
			PrintGraph();
			EulerCycle();
			break;
		case'g':
			printf("\n\n***Complete the graph to an Gamiltonian graph***\n");
			PrintGraph();
			GamiltonCycle();
			break;
		case'k':
			TSP();
			break;
		case'0':
			checkMenu = false;
			break;
		default:
			printf_s("\n***Invalid input!***\n");
			break;
		}
	}
}