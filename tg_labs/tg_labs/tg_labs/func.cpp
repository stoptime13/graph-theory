#include"func.h"


int RandomGen() // могут получаться отрицательные числа !!! нужно что-то с этим сделать
{
	float p, c, r;
	int y;

	p = (rand() % 100) / 100.0;
	c = 1 / (log(1 - p));
	r = (rand() % 100) / 100.0;
	y = (int)(c * log(r)) + 1;

	return y;
}

int inputNumber(const char* string, const int min, const int max)
{
	int numE = 0;
	char Input[256] = { 0 };
	bool check = 1;
	while (check)
	{
		printf("%s (min = %d, max = %d): ", string, min, max);
		fgets(Input, sizeof(Input), stdin);
		while (sscanf(Input, "%d", &numE) != 1)
		{
			printf("*** Enter the correct value! Please re-enter!***\n\n");
			printf("%s (min = %d, max = %d): ", string, min, max);
			fgets(Input, sizeof(Input), stdin);
		}
		if ((numE < min) || (numE > max))
		{
			printf("***Enter the correct value! Please re-enter!***\n\n");
			continue;
		}
		else
		{
			check = false;
		}
	}
	return numE;
}

//****************************ЛАБОРАТОРНАЯ РАБОТА №1****************************

void GraphCreation()
{
	AdjacencyMatrix.clear();
	for (int i = 0; i < numberVert; i++)
		AdjacencyMatrix.push_back(vector<int>(numberVert, 0));

	for (int i = 0; i < numberVert; i++)
	{
		for (int j = i + 1; j < numberVert; j++)
		{
			if (j == i + 1) // вот здесь проверить выполняется ли связность графа
				AdjacencyMatrix.at(i).at(j) = 1;
			else
				AdjacencyMatrix.at(i).at(j) = abs(RandomGen() % 2);
		}
	}
	CostMatrix = nullptr;
	CapacityMatrix = nullptr;
	Potok = nullptr;
}

void MatrixVesCreation()
{
	MatrixVes.clear();
	for (int i = 0; i < numberVert; i++)
		MatrixVes.push_back(vector<int>(numberVert, 0));

	for (int i = 0; i < numberVert; ++i)
	{
		for (int j = i + 1; j < numberVert; j++)
		{
			MatrixVes.at(i).at(j) = 0;
		}
	}

	for (int i = 0; i < numberVert; ++i)
	{
		for (int j = i + 1; j < numberVert; j++)
		{
			if (AdjacencyMatrix[i][j] == 0)
				MatrixVes.at(i).at(j) = 0;
			else
				MatrixVes.at(i).at(j) = rand() % 9 + 1;
		}
	}
}

void MatrixNegVesCreation()
{
	MatrixNegVes.clear();
	for (int i = 0; i < numberVert; i++)
		MatrixNegVes.push_back(vector<int>(numberVert, 0));

	for (int i = 0; i < numberVert; ++i)
	{
		for (int j = i + 1; j < numberVert; j++)
		{
			MatrixNegVes.at(i).at(j) = 0;
		}
	}

	for (int i = 0; i < numberVert; ++i)
	{
		for (int j = i + 1; j < numberVert; j++)
		{
			if (AdjacencyMatrix[i][j] == 0)
				MatrixNegVes[i][j] = 0;
			else
			{
				int x = rand() % 19 - 9;
				while (x == 0)
					x = rand() % 19 - 9;
				MatrixNegVes[i][j] = x;
			}

		}
	}
}

void PrintMatrixV()
{
	printf("\n***********************************\n");
	printf("Positive length matrix:\n");
	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			//printf("%d\t", j);
			if (j != numberVert - 1)
				printf("%d\t", MatrixVes[i][j]);
			else
				printf("%d", MatrixVes[i][j]);
		}
		printf(")\n");
	}
	printf("\n***********************************\n");

	printf("\n***********************************\n");
	printf("Negative length matrix:\n");
	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			//printf("%d\t", j);
			if (j != numberVert - 1)
				printf("%d\t", MatrixNegVes[i][j]);
			else
				printf("%d", MatrixNegVes[i][j]);
		}
		printf(")\n");
	}
	printf("\n***********************************\n");

}


void PrintGraph()
{
	printf("\n***********************************\n");
	printf("Graph adjacency matrix:\n");
	for (int i =0; i < numberVert; i++)
	{
		printf("(");
		for (int j =0; j < numberVert; j++)
		{
			//printf("%d\t", j);
			if(j != numberVert-1)
				printf("%d\t", AdjacencyMatrix[i][j]);
			else
				printf("%d", AdjacencyMatrix[i][j]);
		}
		printf(")\n");
	}
	printf("\n***********************************\n");
}

void MatrixVesInfinity()
{
	AdjacencyMatrixInf = AdjacencyMatrix;
	for (int i = 0; i < numberVert; i++)
	{
		for (int j = 0; j < numberVert; j++)
		{
			if (AdjacencyMatrixInf[i][j] == 0)
				AdjacencyMatrixInf[i][j] = INFINITY;
		}
	}

	MatrixVesInf = MatrixVes;
	for (int i = 0; i < numberVert; i++)
	{
		for (int j = 0; j < numberVert; j++)
		{
			if (MatrixVesInf[i][j] == 0)
				MatrixVesInf[i][j] = INFINITY;
		}
	}
}

void PrintShimbell(vector<vector<int>> vec)
{
	printf("\n\nShimbell's matrix:\n");
	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			//printf("%d\t", j);
			if (j != numberVert - 1)
				printf("%d\t", vec[i][j]);
			else
				printf("%d", vec[i][j]);
		}
		printf(")\n");
	}
}

void Shimbell()
{
	printf("\n\n***Shimbel's method***\n\n");
	int count = 0;
	int path = 0;
	int matr = 0;
	count = inputNumber("Enter the number of verge:", 1, AdjacencyMatrix.size() - 1);
	printf("\n***MENU***\n");
	printf("Select an matrix:\n");
	printf("[1] - positive length matrix;\n");
	printf("[2] - negative length matrix.\n");
	matr = inputNumber("\nEntered value:", 1, 2);

	printf("\nSelect an action:\n");
	printf("[1] - search for maximum paths;\n");
	printf("[2] - search for minimum paths.\n");

	path = inputNumber("\nEntered value:", 1, 2);
	path -= 1;

	vector<vector<int>> buff_buff;
	if (matr == 1)
	{
		buff_buff = MatrixVes;
		for (int i = 1; i < count; i++)
		{
			Matrix(buff_buff, MatrixVes, path);
		}
	}
	else
	{
		buff_buff = MatrixNegVes;
		for (int i = 1; i < count; i++)
		{
			Matrix(buff_buff, MatrixNegVes, path);
		}
	}
	if (path == 1)
		printf("\nShortest paths with %d edges.", count);
	else
		printf("\nLongest paths with %d edges.", count);

	PrintShimbell(buff_buff);
}


void Matrix(vector<vector<int>>& vec1, vector<vector<int>>& vec2, int path)
{
	vector<int> buff;
	vector<vector<int>> buff_buff;
	for (int i = 0; i < vec1.size(); i++)
	{
		buff_buff.push_back(vector<int>(vec1.size(), 0));
	}
	for (int i = 0; i < vec1.size(); i++)
	{
		for (int j = 0; j < vec1.size(); j++)
		{
			buff.clear();
			for (int l = 0; l < vec1.size(); l++)
			{
				if ((vec1[i][l]) && (vec2[l][j]))
					buff.push_back(vec1[i][l] + vec2[l][j]);
				else
					buff.push_back(0);
			}
			if (path)
			{
				int min = buff.front();

				while (buff.size() > 0)
				{
					int x = buff.front();
					if (((min == 0) && (x != 0)) || ((x < min) && (x != 0)))
						min = x;
					buff.erase(buff.begin());
				}
				buff_buff[i][j] = min;
			}
			else
			{
				int max = 0;

				while (buff.size() > 0)
				{
					int x = buff.front();
					if ((x > max) && (x <= (INFINITY - 100)))
						max = x;
					buff.erase(buff.begin());
				}
				buff_buff[i][j] = max;
			}
		}
	}
	vec1 = buff_buff;
}

bool dfs(int u, int t, vector<bool>& visited, vector<vector<int>>& arr)
{
	if (u == t) // проверяем, если вершина отправления совпадает с вершиной прибытия, то возвращаем true
		return true;

	visited.at(u) = true;
	int k = 0;
	for (auto v : arr.at(u))
	{
		if (v && !visited.at(k))
		{
			if (dfs(k, t, visited, arr))
				return true;
		}
		k++;
	}
	return false;
}

void NumberPath(int x, int y) // где x - это от какой вершины нужно считать, y - какой вершиной поиск заканчивается
{
	vector<vector<int>> buff_buff(AdjacencyMatrix);
	if (AdjacencyMatrix[x][y] == 1)
		path_exist += 1;
	for (int i = 1; i < AdjacencyMatrix.size() - 1; i++)
	{
		Matrix(buff_buff, AdjacencyMatrix, 1);
		if (buff_buff[x][y] != 0)
			path_exist += 1;
	}
}

void PathExist()
{
	printf("\n\n***Build a route***\n");
	path_exist = 0;
	int n1 = 0;
	int n2 = 0;
	n1 = inputNumber("\nEnter the number of the first vertex: ", 1, AdjacencyMatrix.size());
	n2 = inputNumber("\nEnter the number of the second vertex: ", 1, AdjacencyMatrix.size());
	vector<bool> visited(AdjacencyMatrix.size(), false);
	if (dfs(n1 - 1, n2 - 1, visited, AdjacencyMatrix))
		printf("\nA path from vertex %d to vertex %d exists", n1, n2);
	else
		printf("\nA path from vertex %d to vertex %d doesn't exists", n1, n2);

	NumberPath(n1 - 1, n2 - 1);
	printf("\n\nNumber of paths: %d\n\n", path_exist);
}

//****************************ЛАБОРАТОРНАЯ РАБОТА №2****************************
void AlgDijkstra()
{
	printf("\n\n***Dijkstra's algorithm***\n\n");
	 
	it1 = 0;
	int start_vert = 0;
	start_vert = inputNumber("Input the start vertex: ", 1, numberVert);

	vector<bool> visited(numberVert, 0);
	vector<int> Dijkstr(numberVert, 0);

	for (int i = 0; i < numberVert; i++)
	{
		Dijkstr[i] = MatrixVesInf[start_vert-1][i];
		visited.at(i) = false;
	}
	Dijkstr.at(start_vert - 1) = 0;
	visited.at(start_vert - 1) = true;

	int index = 0;
	int dop_index = 0;	
	for (int i = 0; i < numberVert; i++)
	{
		int min = INFINITY;
		for (int j = 0; j < numberVert; j++)
		{
			if (!visited.at(j) && Dijkstr.at(j) < min)
			{
				min = Dijkstr.at(j);
				index = j;
			}
			it1++;
		}
		dop_index = index;
		visited.at(dop_index) = true;

		for (int k = 0; k < numberVert; k++)
		{
			if (!visited.at(k) && MatrixVesInf.at(dop_index).at(k) != INFINITY && Dijkstr.at(dop_index) != INFINITY && (Dijkstr.at(dop_index) + MatrixVesInf.at(dop_index).at(k) < Dijkstr.at(k)))
			{
				Dijkstr.at(k) = Dijkstr.at(dop_index) + MatrixVesInf.at(dop_index).at(k);
			}
		}
	}

	// вывод результатов работы функции
	printf("\nDijkstra's algorithm: \n");
	for (int i = 0; i < numberVert; i++)
	{
		if (Dijkstr.at(i) != INFINITY)
			printf("From the vert number %d to the vert number %d = %d\n", start_vert, i + 1, Dijkstr.at(i));
		else
			printf("From the vert number %d to the vert number %d = %s\n", start_vert, i + 1, "infinity");
	}

	printf("\nNumber of iterations: %d.\n", it1);
}

void AlgBellmanFord()
{
	printf("\n\n***Bellman-Ford algorithm***\n\n");

	it2 = 0;
	int start_vert = 0; // начальная вершина
	start_vert = inputNumber("Enter the number of verge:", 1, AdjacencyMatrix.size());

	int matr = 0;
	printf("\nSelect an matrix:\n");
	printf("[1] - positive length matrix;\n");
	printf("[2] - negative length matrix.\n");
	matr = inputNumber("\nEntered value:", 1, 2);

	vector<pair<int, int>> distance(numberVert, pair<int, int>(0, INFINITY));
	if (matr == 1)
	{
		distance[start_vert - 1].first = 0;
		distance[start_vert - 1].second = 0;

		for (int i = 0; i < numberVert; i++)
		{
			for (int j = 0; j < numberVert; j++)
			{
				for (int k = 0; k < numberVert; k++)
				{
					if (MatrixVes[j][k] != 0)
					{
						if (distance[j].second + MatrixVes[j][k] < distance[k].second)
						{
							distance[k].first = j;
							if (distance[j].second < INFINITY)
								distance[k].second = distance[j].second + MatrixVes[j][k];
						}
						it2++;
					}
				}
			}
		}
	}
	if (matr == 2)
	{
		distance[start_vert - 1].first = 0;
		distance[start_vert - 1].second = 0;

		for (int i = 0; i < numberVert; i++)
		{
			for (int j = 0; j < numberVert; j++)
			{
				for (int k = 0; k < numberVert; k++)
				{
					if (MatrixNegVes[j][k] != 0)
					{
						if (distance[j].second + MatrixNegVes[j][k] < distance[k].second)
						{
							distance[k].first = j;
							if (distance[j].second < INFINITY)
								distance[k].second = distance[j].second + MatrixNegVes[j][k];
						}
						it2++;
					}
				}
			}
		}
	}

	printf("\nBellman-Ford algorithm: \n");
	for (int i = 0; i < numberVert; i++)
	{
		if(distance[i].second == 0)
			printf("To the verge number: %d - Rib weight: %d\n", i + 1, distance[i].second);
		else if (distance[i].second == INFINITY)
			printf("To the verge number: %d - Rib weight: %s\n", i + 1, "infinity");
		else 
			printf("To the verge number: %d - Rib weight: %d\n", i + 1, distance[i].second);
	}

	printf("\nNumber of iterations: %d.\n", it2);
}

void AlgFloydWarshall()
{
	printf("\n\n***Floyd-Warshall algorithm***\n\n");

	it3 = 0;
	int matr = 0;
	printf("Select an matrix:\n");
	printf("[1] - positive length matrix;\n");
	printf("[2] - negative length matrix.\n");
	matr = inputNumber("\nEntered value:", 1, 2);

	vector<vector<int>> dopMatrix;
	if (matr == 1)
		dopMatrix = MatrixVes;
	else if (matr == 2)
		dopMatrix = MatrixNegVes;

	for (int i = 0; i < numberVert; i++)
	{
		for (int j = 0; j < numberVert; j++)
		{
			if (dopMatrix[i][j] == 0 && i != j)
				dopMatrix[i][j] = INFINITY;
		}
	}

	for (int i = 0; i < numberVert; i++)
	{
		for (int j = 0; j < numberVert; j++)
		{
			for (int k = 0; k < numberVert; k++)
			{
				if (dopMatrix[i][k] + dopMatrix[k][j] < dopMatrix[i][j])
					dopMatrix[i][j] = dopMatrix[i][k] + dopMatrix[k][j];
				it3++;
			}
		}
	}

	printf("\nFloyd-Warshall algorithm: \n");
	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			if (j != numberVert)
			{
				if (dopMatrix[i][j] >= 900)
					printf("%d\t", 0);
				else
					printf("%d\t", dopMatrix[i][j]);
			}
			else
			{
				if (dopMatrix[i][j] >= 900)
					printf("%d", 0);
				else
					printf("%d", dopMatrix[i][j]);
			}
		}
		printf(")\n");
	}

	printf("\nNumber of iterations: %d.\n", it3);
}

void CompareIt(bool l)
{
	printf("\n\n***Compare iterations***\n\n");
	if (l == true)
	{
		printf("Number of iterations for Dijkstra's algorithm: %d", it1);
		printf("\nNumber of iterations for Bellman-Ford algorithm: %d", it2);
		printf("\nNumber of iterations for Floyd-Warshall algorithm: %d", it3);

		if (it1 < it2 && it1 < it3)
			printf("\n\n> Dijkstra's algorithm is most efficient.\n");
		else if (it2 < it1 && it2 < it3)
			printf("\n\n> Bellman-Ford algorithm is most efficient.\n");
		else if (it3 < it1 && it3 > it2)
			printf("\n\n> Floyd-Warshall algorithm is most efficient.\n");
	}
	else
	{
		printf("Number of iterations for Prim's algorithm: %d", itP);
		printf("\nNumber of iterations for Kruskal's algorithm: %d", itK);

		if (itP < itK)
			printf("\n\n> Prim's algorithm is most efficient.\n");
		else if (itK < itP)
			printf("\n\n> Kruskal's algorithm is most efficient.\n");
		
	}
}


//****************************ЛАБОРАТОРНАЯ РАБОТА №3****************************

void ChangeOr()
{
	for (int i = 0; i < numberVert; i++) // дополняем матрицу бесконечностями (то есть возращаем матрице исходный вид)
	{
		for (int j = 0; j <= i; j++)
		{
			AdjacencyMatrixInf[i][j] = INFINITY;
			MatrixVesInf[i][j] = INFINITY;
			MatrixVes[i][j] = 0;
		}
	}
}

void ChangeUnOr() // делаем матрицу симметричной
{
	for (int i = 0; i < numberVert; i++)
	{
		for (int j = 0; j < numberVert; j++)
		{
			AdjacencyMatrixInf[j][i] = AdjacencyMatrixInf[i][j];
			MatrixVesInf[j][i] = MatrixVesInf[i][j];
			MatrixVes[j][i] = MatrixVes[i][j];
		}
	}
}


void AlgPrim()
{
	printf("\n\n***Prim's algorithm***\n\n");

	itP = 0;
	if (MinOstov != nullptr) // для не первого запуска очищаем MinOstov
		if (!MinOstov->empty())
			MinOstov->clear();
	// алгоритм делает numberVert шагов, на каждом из которых выбирает вершину с наименьшей меткой min_e,
	// помечает ее, как used, а затем просматривает все ребра из вершины

	int cost = 0;
	vector<bool> used(numberVert);
	vector<int> min_e(numberVert, INFINITY); // вес наименьшего допустимого ребра из вершины
	vector<int> sel_e(numberVert, -1); // конец этого наименьшего ребра

	min_e[0] = 0;
	MinOstov = new vector<set<int>>(numberVert);
	for (int i = 0; i < numberVert; ++i)
	{
		int v = -1;
		for (int j = 0; j < numberVert; ++j)
		{
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		}
		if (min_e[i] == INFINITY)
		{
			printf("\nNo minimum spanning tree!\n");
			break;
		}

		used[v] = true; // означает, что вершина включена в остов

		for (int to = 0; to < numberVert; ++to)
		{
			if (MatrixVesInf[v][to] < min_e[to])
			{
				min_e[to] = MatrixVesInf[v][to];
				sel_e[to] = v;
			}
			itP++;
		}

		if (sel_e[v] != -1)
		{
			MinOstov->at(sel_e[v]).insert(v);
			MinOstov->at(v).insert(sel_e[v]);
			if ((sel_e[v] + 1) > (v + 1))
				printf("%d -> %d, weight: %d\n", v + 1, sel_e[v]+1, MatrixVes[sel_e[v]][v]);
			else
				printf("%d -> %d, weight: %d\n", sel_e[v]+1, v+1, MatrixVes[sel_e[v]][v]);
			cost += MatrixVesInf[sel_e[v]][v];
		}
	}

	printf("\nMinimum spanning tree cost: %d\n", cost);
	printf("\nNumber of iterations: %d\n", itP);
}

void AlgKruskal()
{
	printf("\n\n***Kruskal's algorithm***\n\n");

	itK = 0;
	int m = 0;
	if (MinOstov != nullptr)
		if (!MinOstov->empty())
			MinOstov->clear();
	int count = 0;
	
	for (int i = 0; i < numberVert; i++) // считаем кол-во ребер
		for (int j = 0; j < numberVert; j++)
		{
			if (AdjacencyMatrixInf[i][j] > 0 && AdjacencyMatrixInf[i][j] < (INFINITY / 2))
				m++;
		}
	m = m / 2;

	vector<pair<int, pair<int, int>>> g(m); // вес- вершина 1 - вершина 2
	for (int i = 0; i < numberVert; i++)
	{
		for (int j = i; j < numberVert; j++)
		{
			if (MatrixVesInf[i][j] < 500)
			{
				g.at(count).first = MatrixVesInf[i][j];
				g.at(count).second.first = i;
				g.at(count).second.second = j;
				count++;
			}
		}
	}

	int cost = 0;
	vector<pair<int, int>> res;

	sort(g.begin(), g.end()); // сортируем ребра

	vector<int> tree_id(numberVert); // вектор, в котором хранится номер дерева, которому принадлежит веришина
	for (int i = 0; i < numberVert; i++)
	{
		tree_id[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a = g[i].second.first;
		int b = g[i].second.second;
		int l = g[i].first;
		if (tree_id[a] != tree_id[b]) // для каждого ребра проверяем принадлежат ли его концы разынм деревьям
		{
			cost += l;
			res.push_back(make_pair(a, b));

			int old_id = tree_id[a];
			int new_id = tree_id[b];

			for (int j = 0; j < numberVert; j++) 
			{
				if (tree_id[j] == old_id)
					tree_id[j] = new_id;
				itK++;
			}
		}
	}

	MinOstov = new vector<set<int>>(numberVert);
	for_each(res.begin(), res.end(), [](pair<int, int> x)
		{
			MinOstov->at(x.first).insert(x.second);
			MinOstov->at(x.second).insert(x.first);
			if (x.first > x.second)
				printf("%d -> %d, weight: %d\n", x.second + 1, x.first + 1, MatrixVes[x.first][x.second]);
			else
				printf("%d -> %d, weight: %d\n", x.first + 1, x.second + 1, MatrixVes[x.first][x.second]);
		});

	printf("\nMinimum spanning tree cost: %d\n", cost);
	printf("\nNumber of iterations: %d\n", itK);

}

void ThMatrixKirchhoff()
{
	printf("\n\n***Kirchhoff's matrix theorem***\n\n");

	if (numberVert > 13)
		printf("Execution time is too long!\n");

	int count = 0;
	vector<vector<int>> buffer(numberVert);
	for (int i = 0; i < numberVert; i++)
	{
		buffer[i] = vector<int>(numberVert);
		for (int j = 0; j < numberVert; j++)
		{
			if (AdjacencyMatrixInf[i][j] == INFINITY)
				buffer[i][j] = 0;
			else
			{
				buffer[i][j] = -AdjacencyMatrixInf[i][j];
				count++;
			}
		}
		buffer[i][i] = count;
		count = 0;
	}

	printf("Kirchhoff matrix:\n");
	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			if(j != numberVert)
				printf("%d\t", buffer[i][j]);
			else 
				printf("%d", buffer[i][j]);
		}
		printf(")\n");
	}

	int minor = 1;
	vector<vector<int>> arr(numberVert - 1);
	for (int i = 0; i < numberVert - 1; i++)
	{
		arr[i] = vector<int>(numberVert - 1);
	}

	for (int i = 1; i < numberVert; i++)
	{
		for (int j = 1; j < numberVert; j++)
		{
			arr[i - 1][j - 1] = buffer[i][j];
		}
	}

	for (int i = 0; i < numberVert - 1; i++)
		minor += arr[0][i] * pow(-1, (1 + i + 1)) * findMinor(arr, 0, i, numberVert - 1);

	if (numberVert != 2)
	{
		minor -= 1;
	}
	printf("\nThe number of spanning trees by Kirchhoff's theorem: %d\n", abs(minor));

}

int findMinor(vector<vector<int>> buffer, int x, int y, int size)
{
	int minor = 0;

	vector<vector<int>> arr(size - 1);
	for (int i = 0; i < size - 1; i++)
		arr[i] = vector<int>(size - 1);

	int k = 0, f = 0;
	for (int i = 0; i < size; i++)
	{
		f = 0;
		for (int j = 0; j < size; j++)
		{
			if ((i != x) && (j != y))
			{
				arr[k][f] = buffer[i][j];
				f++;
			}
		}
		if (i != x)
			k++;
	}

	if ((size - 1) == 1)
	{
		minor = arr[0][0];
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			minor += arr[0][i] * pow(-1, (1 + i + 1)) * findMinor(arr, 0, i, size - 1);
		}
	}
	return minor;
}

void EnPrufer()
{
	printf("\n\n***Prufer encoding***\n\n");

	if (MinOstov == nullptr)
		printf("Error! No minimum spanning tree found! Search for a spanning tree!\n");

	if (MinOstov->size() == 2)
	{
		printf("The graph has two vertices. Prufer's code is not possible!\n");
		printf("Code: %d\n\n", 0);
	}


	if (MinOstov->size() != 2)
	{
		if (PruferCode.size() == (numberVert - 2))
		{
			printf("Code: ");
			for (int i = 0; i < numberVert - 2; i++)
			{
				printf("%d ", PruferCode.at(i) + 1);
			}
			printf("\n");
		}
	}

	vector<bool> visited(numberVert);

	while (PruferCode.size() != numberVert - 2)
	{
		for (int i = 0; i < numberVert; i++)
		{
			if (!visited[i])
			{
				if (MinOstov->at(i).size() == 1)
				{
					visited[i] = true;
					for (int j = 0; j < numberVert; j++)
					{
						MinOstov->at(i).clear();
						auto iter = MinOstov->at(j).find(i);
						if (iter != MinOstov->at(j).end())
						{
							MinOstov->at(j).erase(*iter);
							PruferCode.push_back(j);
							break;
						}
					}
					break;
				}
			}
		}
	}

	if (MinOstov->size() != 2)
	{
		printf("Code: ");
		for (int i = 0; i < numberVert - 2; i++)
		{
			printf("%d ", PruferCode.at(i) + 1);
		}
		printf("\n");
	}
}

void DePrufer()
{
	printf("\n\n***Prufer decoding***\n\n");

	if (MinOstov == nullptr)
		printf("Error! No minimum spanning tree found! Search for a spanning tree!\n");

	if (MinOstov->size() == 2)
		printf("Decode:\n%d -> %d\n", 1,2);

	if (PruferCode.size() < (numberVert - 2))
		printf("Error! Make Prufer coding!\n");

	if (MinOstov->size() != 2)
	{
		deque<int> v;
		bool b = false;

		printf("Decode:\n");

		for (int i = 0; i < numberVert; i++)
		{
			v.push_back(i);
		}

		int index = 0;
		while (v.size() != 2)
		{
			bool b = false;
			for (int i = 0; i < PruferCode.size(); i++)
			{
				if (PruferCode.at(i) == v.at(index))
					b = true;
			}
			if (b)
			{
				index++;
				b = false;
			}
			else
			{
				auto iter = v.begin() + index;
				printf("%d -> %d\n", v.at(index) + 1, PruferCode.at(0) + 1);
				v.erase(iter);
				PruferCode.erase(PruferCode.begin());
				index = 0;
				b = false;
			}
		}
		printf("%d -> %d\n", v.at(0) + 1, v.at(1) + 1);
	}
}




//****************************ЛАБОРАТОРНАЯ РАБОТА №4****************************

void MatrixCost()
{
	printf("\n\n***Cost matrix***\n\n");

	if (CostMatrix != nullptr)
	{
		return;
	}

	CostMatrix = new int* [numberVert];
	for (int i = 0; i < numberVert; i++)
	{
		CostMatrix[i] = new int[numberVert];
		for (int j = 0; j < numberVert; j++)
		{
			if (MatrixVesInf[i][j] < (INFINITY / 2))
				CostMatrix[i][j] = rand() % 11 + 2;
			else
				CostMatrix[i][j] = INFINITY;
		}
	}


	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			if (j != numberVert-1)
			{
				if (CostMatrix[i][j] == INFINITY)
					printf("%d\t", 0);
				else
					printf("%d\t", CostMatrix[i][j]);
			}
			else
			{
				if (CostMatrix[i][j] == INFINITY)
					printf("%d", 0);
				else
					printf("%d", CostMatrix[i][j]);
			}
		}
		printf(")\n");
	}
}

void MatrixCapacity()
{
	FFl = true;
	printf("\n\n***Capacity matrix***\n\n");

	if (CapacityMatrix != nullptr)
	{
		return;
	}

	CapacityMatrix = new int* [numberVert];
	for (int i = 0; i < numberVert; i++)
	{
		CapacityMatrix[i] = new int[numberVert];
		for (int j = 0; j < numberVert; j++)
		{
			if (AdjacencyMatrixInf[i][j] < (INFINITY / 2))
				CapacityMatrix[i][j] = rand() % 11 + 2;
			else
				CapacityMatrix[i][j] = 0;
		}
	}

	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			if (j != numberVert-1)
			{
				if (CapacityMatrix[i][j] == INFINITY)
					printf("%d\t", 0);
				else
					printf("%d\t", CapacityMatrix[i][j]);
			}
			else
			{
				if (CapacityMatrix[i][j] == INFINITY)
					printf("%d", 0);
				else
					printf("%d", CapacityMatrix[i][j]);
			}
		}
		printf(")\n");
	}
}

bool bfs(int** rGraph, int s, int t, int parent[])
{
	vector<bool> visited(numberVert);

	for (int i = 0; i < numberVert; i++)
	{
		visited[i] = false;
	}

	deque<int> q;
	q.push_back(s);
	visited[s] = true;
	parent[s] = -1;

	while (!(q.empty()))
	{
		int u = q.front();
		q.pop_front();

		for (int v = 0; v < numberVert; v++)
		{
			if (visited[v] == false && rGraph[u][v] > 0)
			{
				q.push_back(v);
				parent[v] = u;
				visited[v] = true;	
			}
		}
	}

	bool res = (visited[t] == true);

	return res;
}

int FordFulkerson(int s, int t)
{
	if ((CostMatrix == nullptr) || (CapacityMatrix == nullptr)) {
		printf("No capacity and cost matrices have been created!\n");
		return 0;
	}
	else {
		int u, v;

		Potok = new int* [numberVert];

		for (u = 0; u < numberVert; u++) {
			Potok[u] = new int[numberVert];
			for (v = 0; v < numberVert; v++) {
				Potok[u][v] = 0;
			}
		}


		int** rGraph = new int* [numberVert];

		for (u = 0; u < numberVert; u++) {
			rGraph[u] = new int[numberVert];
			for (v = 0; v < numberVert; v++) {
				if (CapacityMatrix[u][v] > (INFINITY / 2)) {
					rGraph[u][v] = 0;
				}
				else {
					rGraph[u][v] = CapacityMatrix[u][v];
				}
			}
		}

		int* parent = new int[numberVert];

		int max_flow = 0;

		while (bfs(rGraph, s, t, parent))
		{

			int path_flow = INT_MAX;
			for (v = t; v != s; v = parent[v])
			{
				u = parent[v];
				path_flow = min(path_flow, rGraph[u][v]);

			}

			for (v = t; v != s; v = parent[v])
			{
				u = parent[v];
				rGraph[u][v] -= path_flow;
				rGraph[v][u] += path_flow;
				if (Potok[u][v] != 0)
					Potok[u][v] += path_flow;
				else
					Potok[u][v] = path_flow;
			}

			max_flow += path_flow;
		}


		if (FFl)
		{
			printf("\nFlow matrix\n");
			for (int i = 0; i < numberVert; i++)
			{
				printf("(");
				for (int j = 0; j < numberVert; j++)
				{
					if(j != numberVert -1)
						printf("%d\t", Potok[i][j]);
					else
						printf("%d", Potok[i][j]);
				}
				printf(")\n");
			}
		}

		FFl = false;

		for (int i = 0; i < numberVert; i++) {
			delete[] rGraph[i];
			delete[] Potok[i];
		}
		delete[] rGraph;
		delete[] Potok;
		delete[] parent;

		return max_flow;
	}
}

vector<int> BellmanFordPath(int** costArr)
{
	vector<edge> e(numberVert * numberVert);
	vector<int> d(numberVert, INFINITY);
	vector<int> p(numberVert, -1);
	int count = 0;


	for (int i = 0; i < numberVert; i++)
		for (int j = 0; j < numberVert; j++)
		{
			if (costArr[i][j] < INFINITY)
			{
				e.at(count).a = i;
				e.at(count).b = j;
				e.at(count).cost = costArr[i][j];
				count++;

			}
		}

	d[0] = 0;
	for (int i = 0; i < numberVert - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[e[j].a] < (INFINITY - 100)) {
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = d[e[j].a] + e[j].cost;
					p[e[j].b] = e[j].a;
				}
			}
		}
	}
	vector<int> path;
	for (int cur = numberVert - 1; cur != -1; cur = p[cur])
		path.push_back(cur);
	reverse(path.begin(), path.end());

	return path;
}

void MinCostMaxFlow(int b)
{
	

	int** matrPotok = new int* [numberVert];
	for (int i = 0; i < numberVert; i++)
	{
		matrPotok[i] = new int[numberVert];
		for (int j = 0; j < numberVert; j++)
		{
			matrPotok[i][j] = 0;
		}
	}

	if ((CostMatrix == nullptr) || (CapacityMatrix == nullptr))
	{
		printf("No capacity and cost matrices have been created!\n");
		return;
	}
	else
	{
		int maxFlow = 0;
		int flow = 0;
		int sigma = INFINITY;
		int result = 0;
		int** modifiedCostArr;

		map<int, pair<vector<int>, int>> tempMap;
		map<vector<int>, pair<int, int>> temporary;
		set<pair<int, int>> resultVert;
		vector<vector<int>> f(numberVert);
		vector<int> k;

		for (int i = 0; i < numberVert; i++)
		{
			for (int j = 0; j < numberVert; j++)
			{
				if (AdjacencyMatrixInf[i][j] > 0 && AdjacencyMatrixInf[i][j] < (INFINITY / 2))
					m++;
			}
		}

		modifiedCostArr = new int* [numberVert];
		for (int i = 0; i < numberVert; i++)
		{
			modifiedCostArr[i] = new int[numberVert];
			for (int j = 0; j < numberVert; j++)
			{
				f.at(i).push_back(0);
				modifiedCostArr[i][j] = CostMatrix[i][j];
			}
		}

		while (maxFlow < b)
		{
			vector<int> path = BellmanFordPath(modifiedCostArr);
			for (int i = 0; i < path.size() - 1; i++)
			{
				sigma = min(sigma, CapacityMatrix[path.at(i)][path.at(i + 1)]);
				if (resultVert.find(pair<int, int>(path.at(i), path.at(i + 1))) == resultVert.end())
				{
					resultVert.insert(pair<int, int>(path.at(i), path.at(i + 1)));
				}
			}

			flow = min(sigma, (b - maxFlow));
			k.push_back(flow);
			int tempCost = 0;

			for (int i = 0; i < path.size() - 1; i++)
			{
				tempCost += CostMatrix[path.at(i)][path.at(i + 1)];
			}

			if (temporary.find(path) == temporary.end())
			{
				temporary[path] = pair<int, int>(flow, tempCost);
			}
			else
			{
				temporary[path].first += flow;
			}

			for (int i = 0; i < path.size() - 1; i++)
			{
				f.at(path[i]).at(path[i + 1]) += flow;
				if (f.at(path[i]).at(path[i + 1]) == CapacityMatrix[path[i]][path[i + 1]])
				{
					modifiedCostArr[path[i]][path[i + 1]] = INFINITY;
					modifiedCostArr[path[i + 1]][path[i]] = INFINITY;
				}
				else
				{
					if (f.at(path[i]).at(path[i + 1]) >= 0) 
					{
						modifiedCostArr[path[i]][path[i + 1]] = CostMatrix[path[i]][path[i + 1]];
						modifiedCostArr[path[i + 1]][path[i]] = -modifiedCostArr[path[i]][path[i + 1]];
					}
				}
			}
			maxFlow += flow;
		}
		int min = INFINITY;
		vector<pair<int, pair<vector<int>, int>>> tempVect;

		for (auto i = temporary.begin(); i != temporary.end(); i++)
		{
			tempVect.push_back(pair<int, pair<vector<int>, int>>(i->second.second, pair<vector<int>, int>(i->first, i->second.first)));
		}

		for (int i = 0; i < tempVect.size() - 1; i++)
		{
			for (int j = 0; j < tempVect.size() - 1; j++)
			{
				if (tempVect[j].first > tempVect[j + 1].first)
					swap(tempVect[j], tempVect[j + 1]);
			}
		}

		vector<int> vecPotok;
		vector<int> vecMatr;
		int ur = 0;

		for (int i = 0; i < tempVect.size(); i++)
		{
		//	printf("\n\nFlow path: ");
			for (int j = 0; j < tempVect[i].second.first.size() - 1; j++)
			{
				//printf("%d - ", tempVect[i].second.first[j] + 1);
				vecMatr.push_back(tempVect[i].second.first[j]);
			}

			//printf("%d", tempVect[i].second.first[tempVect[i].second.first.size() - 1] + 1);
			vecMatr.push_back(tempVect[i].second.first[tempVect[i].second.first.size() - 1]);

			//printf("\n\nFlow throught the path found: %d\n", tempVect[i].second.second);
			for (int l = 0; l < vecMatr.size() - 1; l++)
			{
				if (vecMatr[l] < vecMatr[l + 1] && matrPotok[vecMatr[l]][vecMatr[l + 1]] == 0)
					matrPotok[vecMatr[l]][vecMatr[l + 1]] = tempVect[i].second.second;
			}
			vecPotok.push_back(tempVect[i].second.second);
		}

		for_each(resultVert.begin(), resultVert.end(), [&result, &f](pair<int, int>x) {result += f.at(x.first).at(x.second) * CostMatrix[x.first][x.second]; });

		printf("\n\nGiven flow: %d", b);
		printf("\n\nMinimum cost of a given stream: %d", result);
		printf("\n\nCost matrix:\n");

		for (int i = 0; i < numberVert; i++)
		{
			printf("(");
			for (int j = 0; j < numberVert; j++)
			{
				if (j != numberVert - 1)
				{
					if(CostMatrix[i][j] == INFINITY)
						printf("%d\t", 0);
					else
						printf("%d\t", CostMatrix[i][j]);
				}
				else
				{
					if (CostMatrix[i][j] == INFINITY)
						printf("%d", 0);
					else
						printf("%d", CostMatrix[i][j]);
				}
			}
			printf(")\n");
		}

		printf("\n\nFlow matrix:\n");
		for (int i = 0; i < numberVert; i++)
		{
			printf("(");
			for (int j = 0; j < numberVert; j++)
			{
				if (j != numberVert - 1)
					printf("%d\t", matrPotok[i][j]);
					//printf("%d\t", vecPotok[i][j])
				else
					printf("%d", matrPotok[i][j]);
			}
			printf(")\n");
		}


		for (int i = 0; i < numberVert; i++) {
			delete[] modifiedCostArr[i];
			delete[] matrPotok[i];
		}
		delete[] modifiedCostArr;
		delete[] matrPotok;
	}
}



//****************************ЛАБОРАТОРНАЯ РАБОТА №5****************************

void EulerGraph()
{
	int vert = numberVert;
	
	if (vert == 2)
	{
		printf("There are two vertices in the graph! Euler graph is impossible!\n");
		return;
	}

	GraphEuler = vector<vector<int>>(vert, vector<int>(vert, 0));

	for (int i = 0; i < vert; i++)
	{
		for (int j = i; j < vert; j++)
		{
			GraphEuler[i][j] = GraphEuler[j][i] = AdjacencyMatrix[i][j];
		}
	}
	
	int eG = IsItEuler(GraphEuler);
	bool flag = false;

	if (eG == 0)
		printf("\n>The original graph is not eulerian!\n\n");
	else
		printf("\n\n>The original graph is eulerian!\n\n");
}

int IsItEuler(vector<vector<int>> graph)
{
	int sG = graph.size();

	for (int i = 0; i < sG; i++)
	{
		for (int j = 0; j < sG; j++)
		{
			graph[j][i] = graph[i][j];
		}
	}

	vector<int> degree;

	for (int i = 0; i < sG; i++)
	{
		int sst = 0;
		for (int j = 0; j < sG; j++)
		{
			if (graph[i][j] != 0)
				sst++;
		}
		degree.push_back(sst);
	}

	int count = 0;
	
	for (int i = 0; i < sG; i++)
	{
		if (degree[i] == 0)
		{
			count = 1;
			deg.clear();
			for (int i = 0; i < sG; i++)
			{
				deg.push_back(i);
			}
			break;
		}

		if (degree[i] % 2 != 0)
		{
			count++;
			deg.push_back(i);
		}
	}

	if (count > 0)
		return 0;
	
	int min = 100;
	int ind = 0;

	for (int i = 0; i < sG; i++)
	{
		if (min > degree[i])
		{
			min = degree[i];
			ind = i;
		}
	}

	vector<int> res;
	stack<int> s;

	s.push(ind);

	while (!s.empty())
	{
		int i = s.top();
		if (degree[i] == 0)
		{
			s.pop();
			res.push_back(i);
		}
		else
		{
			for (int j = 0; j < sG; j++) 
			{
				if (graph[i][j] != 0) 
				{
					graph[i][j] = 0;
					graph[j][i] = 0;
					degree[i] -= 1;
					degree[j] -= 1;
					s.push(j);
					break;
				}
			}
		}
	}

	if (res.size() != 0)
	{
		printf("\nEuler cycle: ");
		for (size_t i = res.size() - 1; i != 0; i--)
		{
			printf("%d - ", res[i]+1);
		}
		printf("%d", res[0]+1);
	}

	return res.size();
}

void GamiltonGraph()
{
	GraphGamilton = vector<vector<int>>(numberVert, vector<int>(numberVert, 0));
	if (numberVert == 2)
	{
		printf("\nThere can be no Hamiltonian cycle for two vertices!");
		return;
	}

	for (int i = 0; i < numberVert; i++)
	{
		for (int j = i; j < numberVert; j++)
		{
			GraphGamilton[i][j] = GraphGamilton[j][i] = AdjacencyMatrix[i][j];
		}

	}

	if (IsItGamilton(GraphGamilton))
		printf("\n>The original graph is gamiltonian!\n\n");
	else
		printf("\n>The original graph is not gamiltonian!\n\n");
}

bool IsItGamilton(vector<vector<int>> graph)
{
	int vert = numberVert;
	int ok = 0;

	path = vector<pair<int, int>>(numberVert);
	for (int i = 0; i < numberVert; i++)
	{
		path[i].first = i;
		for (int j = 0; j < numberVert; j++)
		{
			if (graph[i][j] == 1)
				ok++;
		}
		path[i].second = ok;
		ok = 0;
	}

	for (int i = 0; i < numberVert; i++)
	{
		if (path[i].second < ((numberVert / 2)))
			return false;
	}

	return true;
}

void EulerCycle()
{
	int vert = numberVert;
	
	if (vert == 2)
	{
		printf("There are two vertices in the graph! Euler cycle is impossible!\n");
		return;
	}

	GraphEuler = vector<vector<int>>(vert, vector<int>(vert, 0));

	for (int i = 0; i < vert; i++)
	{
		for (int j = i; j < vert; j++)
		{
			GraphEuler[i][j] = GraphEuler[j][i] = AdjacencyMatrix[i][j];
		}
	}

	int eU = IsItEuler(GraphEuler);

	bool flag = 0;
	
	while (!eU)
	{
		flag = 1;
		vector<int> degree1;
		for (int i = 0; i < numberVert; i++)
		{
			int sst = 0;
			for (int j = 0; j < numberVert; j++)
			{
				if (GraphEuler[i][j] != 0)
					sst++;
			}
			degree1.push_back(sst);
		}

		srand(time(NULL));

		bool isChanged = false;

		for (int i = 0; i < deg.size(); i++)
		{
			for (int j = i + 1; j < deg.size(); j++)
			{
				if (GraphEuler[deg[i]][deg[j]] == 0)
				{
					GraphEuler[deg[i]][deg[j]] = 1;
					GraphEuler[deg[j]][deg[i]] = 1;
					printf("Add a rib: %d - %d\n", deg[i]+1, deg[j]+1);
					isChanged = true;
					break;
				}

				if (GraphEuler[deg[i]][deg[j]] == 1)
				{
					GraphEuler[deg[i]][deg[j]] = 0;
					GraphEuler[deg[j]][deg[i]] = 0;

					printf("Remove a rib: %d - %d\n", deg[i]+1, deg[j]+1);

					if (degree1[deg[i]] == 1 && degree1[deg[j]] % 2 != 0 && degree1[deg[j]] != 1)
					{
						if (deg[i] != numberVert - 1)
						{
							GraphEuler[deg[i]][numberVert - 1] = 1;
							GraphEuler[numberVert - 1][deg[i]] = 1;
							printf("Add a rib: %d - %d\n", deg[i]+1, numberVert - 1+1);
						}
						else
						{
							GraphEuler[deg[i]][0] = 1;
							GraphEuler[0][deg[i]] = 1;
							printf("Add a rib: %d - %d\n", 0+1, deg[i]+1);
						}

						if (deg[i] != numberVert - 2)
						{
							GraphEuler[deg[i]][numberVert - 2] = 1;
							GraphEuler[numberVert - 2][deg[i]] = 1;
							printf("Add a rib: %d - %d\n", deg[i]+1, numberVert - 2+1);
						}
						else
						{
							GraphEuler[deg[i]][0] = 1;
							GraphEuler[0][deg[i]] = 1;
							printf("Add a rib: %d - %d\n", 0+1, deg[i]+1);
						}

					}

					if (degree1[deg[j]] == 1 && degree1[deg[i]] % 2 != 0 && degree1[deg[i]] != 1)
					{
						if (deg[j] != numberVert - 1 && GraphEuler[deg[i]][deg[j]] == 0)
						{
							GraphEuler[deg[j]][numberVert - 1] = 1;
							GraphEuler[numberVert - 1][deg[i]] = 1;
							printf("Add a rib: %d - %d\n", deg[j]+1, numberVert - 1+1);
						}
						else
						{
							GraphEuler[deg[j]][0] = 1;
							GraphEuler[0][deg[j]] = 1;
							printf("Add a rib: %d - %d\n", 0+1, deg[j]+1);
						}

						if (deg[j] != numberVert - 2 && GraphEuler[deg[i]][deg[j]] == 0)
						{
							GraphEuler[deg[j]][numberVert - 2] = 1;
							GraphEuler[numberVert - 2][deg[j]] = 1;
							printf("Add a rib: %d - %d\n", deg[j]+1, numberVert - 2+1);
						}
						else
						{
							GraphEuler[deg[j]][0] = 1;
							GraphEuler[0][deg[j]] = 1;
							printf("Add a rib: %d - %d\n", 0+1, deg[j]+1);
						}
					}
					isChanged = true;
					break;
				}
			}
			if (isChanged)
				break;
		}
		deg.clear();

		eU = IsItEuler(GraphEuler);
	}

	if (flag) 
	{
		printf("\n\nChanged adjacency matrix:\n");

		for (int i = 0; i < vert; i++)
		{
			printf("(");
			for (int j = 0; j < vert; j++) 
			{
				if (j != vert - 1)
					printf("%d\t", GraphEuler[i][j]);
				else
					printf("%d", GraphEuler[i][j]);
			}
			printf(")\n");
		}
	}

	deg.clear();
}

void GamiltonCycle()
{
	int vert = numberVert;
	int c = 0;
	bool flagG = true;
	bool flag = false;
	bool add = false;
	bool first = 1;
	bool f = false;
	vector<int> v0;

	GraphGamilton = vector<vector<int>>(vert, vector<int>(vert, 0));

	if (numberVert < 3)
	{
		printf("The graph cannot be made Hamiltonian! Less than three vertices!\n");
		return;
	}

	for (int i = 0; i < vert; i++)
	{
		for (int j = i; j < vert; j++)
		{
			GraphGamilton[i][j] = GraphGamilton[j][i] = AdjacencyMatrixInf[i][j];
		}
	}

	while (flagG)
	{

		if (IsItGamilton(GraphGamilton))
		{
			printf("\nThe graph is hamiltonian!\n");
			flagG = false;
			flag = true;
			break;
		}
		else
		{
			printf("\nIt's necessary to complete the graph!\n");
			add = false;
			while (!flag)
			{
				for (int i = 0; i < numberVert; i++)
				{
					if (path[i].second < numberVert / 2 && !add)
					{
						v0.push_back(path[i].first);
					}
				}

				for (int i = 0; i < v0.size(); i++)
				{
					for (int j = 0; j < numberVert; j++)
					{
						if (!add)
						{
							if (GraphGamilton[v0[i]][j] == 999 && v0[i] != j)
							{
								if (v0.size() == 2 && GraphGamilton[v0[i]][v0[i + 1]] == INFINITY)
								{
									GraphGamilton[v0[i]][v0[i + 1]] = 1;
									GraphGamilton[v0[i + 1]][v0[i]] = 1;
									if (v0[i] + 1 < v0[i + 1] + 1)
										printf("\nAdd a rib: %d - %d\n", v0[i] + 1, v0[i + 1] + 1);
									else
										printf("\nAdd a rib: %d - %d\n", v0[i+1] + 1, v0[i] + 1);
									add = true;
									f = true;
								}
								else 
								{
									GraphGamilton[v0[i]][j] = 1;
									GraphGamilton[j][v0[i]] = 1;
									if (v0[i] + 1 < j + 1)
										printf("\nAdd a rib: %d - %d\n", v0[i] + 1, j + 1);
									else
										printf("\nAdd a rib: %d - %d\n", j + 1, v0[i] + 1);
									add = true;
									f = true;
								}
							}
						}
					}
				}

				flag = IsItGamilton(GraphGamilton);
				add = false;
				v0.clear();
			}
		}
	}

	if (f)
	{
		printf("\n\nChanged adjacency matrix:\n");

		for (int i = 0; i < vert; i++)
		{
			printf("(");
			for (int j = 0; j < vert; j++)
			{
				if (j != vert - 1)
				{ 
					if(GraphGamilton[i][j] == 999)
						printf("%d\t", 0);
					else
						printf("%d\t", GraphGamilton[i][j]);
				}
				else
				{
					if (GraphGamilton[i][j] == 999)
						printf("%d", 0);
					else
						printf("%d", GraphGamilton[i][j]);
				}
			}
			printf(")\n");
		}
	}
}


void TSP()
{
	printf("\n\n***Travelling salesman problem (TSP)***\n");
	GraphGamiltonVes = vector<vector<int>>(numberVert, vector<int>(numberVert, 0));
	for (int i = 0; i < numberVert; i++)
	{
		for (int j = i + 1; j < numberVert; j++)
		{
			if (GraphGamilton[i][j] = 0)
			{
				GraphGamiltonVes[i][j] = 0;
				GraphGamiltonVes[j][i] = 0;
			}
			else
			{
				GraphGamiltonVes[i][j] = rand() % 9 + 1;
				GraphGamiltonVes[j][i] = rand() % 8 + 1;
			}
		}
	}

	ofstream f;
	f.open("Gamilton.txt", std::ofstream::out | std::ofstream::trunc);
	f.close();
	
	printf("\nAdjacency matrix of a hamiltonian graph:\n");
	for (int i = 0; i < numberVert; i++)
	{
		printf("(");
		for (int j = 0; j < numberVert; j++)
		{
			if (j != numberVert - 1)
				printf("%d\t", GraphGamiltonVes[i][j]);
			else
				printf("%d", GraphGamiltonVes[i][j]);
		}
		printf(")\n");
	}

	if (numberVert < 3)
	{
		printf("Less than 3 vertex! It's impossible to solve the TSP!\n");
		return;
	}

	if (numberVert > 12)
	{
		printf("Solving the TSP will take too much time!\n");
		return;
	}

	int cost = 0;
	int minCost = INFINITY * numberVert;
	deque<int> que;
	deque<int> res;
	//ofstream f;

	f.open("Gamilton.txt", ofstream::out);

	bool isGamiltonC = true;
	for (int i = 0; i < numberVert; i++)
	{
		que.push_back(i);
	}

	do 
	{
		isGamiltonC = true;
		cost = 0;
		if (GraphGamilton[que.at(numberVert - 1)][que.at(0)] > (INFINITY / 2)) 
		{
			isGamiltonC = false;
		}
		else 
		{
			for (int i = 0; i < numberVert - 1; i++) 
			{
				if (GraphGamilton[que.at(i)][que.at(i + 1)] > (INFINITY / 2)) 
				{
					isGamiltonC = false;
				}
				else 
				{
					cost += GraphGamiltonVes[que.at(i)][que.at(i + 1)];
				}
			}
		}

		if (isGamiltonC)
		{
			cost += GraphGamiltonVes[que.at(numberVert - 1)][que.at(0)];
			f << "Hamiltonian cycle:" << endl;
			f << que.at(0) + 1;
			for (int i = 1; i < que.size(); i++)
			{
				f << " - " << que.at(i) + 1;
			}

			f << " - " << que.at(0) + 1;
			f << "\n";
			f << "\n\nWeight: " << cost << endl << endl;
			if (cost < minCost)
			{
				res.clear();
				res.resize(que.size());
				copy(que.begin(), que.end(), res.begin());
				minCost = cost;
			}
		}
	} while (next_permutation(que.begin(), que.end()));

	f.close();

	printf("\nMinimum Hamiltonian cycle: ");
	printf("%d", res.at(0) + 1);
	for (int i = 1; i < res.size(); i++)
	{
		printf(" - %d", res.at(i) + 1);
	}
	printf(" - %d", res.at(0) + 1);
	printf("\n\nWeight: %d\n\n", minCost);
}