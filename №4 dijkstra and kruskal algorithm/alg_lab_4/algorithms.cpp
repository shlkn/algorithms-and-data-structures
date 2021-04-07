#include "algorithms.h"
void Dijkstras_alg()
{
	int chs;
	cout << "please enter first vertex\n";
	cin >> chs;
	int d[SIZE]; // минимальное рассто€ние
	int v[SIZE]; // посещенные вершины
	int temp, minindex, min;
	int begin_index = chs;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
	//»нициализаци€ вершин и рассто€ний
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}
	d[begin_index] = 0;
	// Ўаг алгоритма
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{ // ≈сли вершину ещЄ не обошли и вес меньше min
			if ((v[i] == 1) && (d[i] < min))
			{ // ѕереприсваиваем значени€
				min = d[i];
				minindex = i;
			}
		}
		// ƒобавл€ем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minindex != 10000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < d[i])
						d[i] = temp;
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	// ¬ывод кратчайших рассто€ний до вершин
	printf("\nShortest distances to vertices:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%5d ", i);
	cout << endl;
	for (int i = 0; i < SIZE; i++)
		printf("%5d ", d[i]);


	// ¬осстановление пути
	cout << endl;
	cout << "please enter destination vertex\n";
	cin >> chs;
	int ver[SIZE]; // массив посещенных вершин
	int end = chs; // индекс конечной вершины = 5 - 1
	ver[0] = end + 1; // начальный элемент - конечна€ вершина
	int k = 1; // индекс предыдущей вершины
	int weight = d[end]; // вес конечной вершины

	while (end != begin_index) // пока не дошли до начальной вершины
	{
		for (int i = 0; i < SIZE; i++) // просматриваем все вершины
			if (b[end][i] != 0)   // если св€зь есть
			{
				int temp = weight - b[end][i]; // определ€ем вес пути из предыдущей вершины
				if (temp == d[i]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight = temp; // сохран€ем новый вес
					end = i;       // сохран€ем предыдущую вершину
					ver[k] = i + 1; // и записываем ее в массив
					k++;
				}
			}
	}
	// ¬ывод пути (начальна€ вершина оказалась в конце массива из k элементов)
	printf("\nshortest path\n");
	for (int i = k - 1; i >= 0; i--)
		printf("%3d ", ver[i]);
	cout << endl;
}

void Kruskal_alg()
{
	int m = 27;//кол-во рЄбер

	vector <edge> graph(m); //ребра исходного графа
	vector <edge> graph_sorted(m); //ребра исходного графа
	vector <edge> tree; //ребра дерева
	vector <int> variety(SIZE); //множество вершин

	for (int i = 0; i < SIZE; i++)
		variety[i] = i;

	int i, j, cnt = 0, min = 32768, k = 0, minindex = 0;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			if (a[i][j] != 0)
			{
				graph[cnt].x = i;
				graph[cnt].y = j;
				graph[cnt].w = a[i][j];
				cnt++;
			}
	i = 0;
	for (i = 0; i < cnt; i++)
	{
		for (j = 0; j < cnt; j++)
			if (graph[j].w < min)
			{
				min = graph[j].w;
				minindex = j;
			}
		graph_sorted[i].w = graph[minindex].w;
		graph_sorted[i].x = graph[minindex].x;
		graph_sorted[i].y = graph[minindex].y;
		graph[minindex].w = 32768;
		min = 32768;
	}
	cout << "Spanning tree result:\n";
	for (int i = 0; i < m; i++) {
		int a = graph_sorted[i].x;
		int b = graph_sorted[i].y;
		if (variety[a] != variety[b])
		{
			tree.push_back(graph_sorted[i]);
			int old_variety = variety[b], new_variety = variety[a];
			for (int j = 0; j < SIZE; j++) 
				if (variety[j] == old_variety)
					variety[j] = new_variety;
		}
	}
	for (int i = 0; i < SIZE - 1; i++) //по принципу построени€ дерева, оно содержит n-1 ребро
	{ 
		cout << tree[i].x + 1 << " " << tree[i].y + 1 << " " << tree[i].w;
		if (i != SIZE - 2)
			cout << endl;
	}
}