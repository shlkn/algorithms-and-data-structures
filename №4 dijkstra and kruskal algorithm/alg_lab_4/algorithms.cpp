#include "algorithms.h"
void Dijkstras_alg()
{
	int chs;
	cout << "please enter first vertex\n";
	cin >> chs;
	int d[SIZE]; // ����������� ����������
	int v[SIZE]; // ���������� �������
	int temp, minindex, min;
	int begin_index = chs;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
	//������������� ������ � ����������
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}
	d[begin_index] = 0;
	// ��� ���������
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{ // ���� ������� ��� �� ������ � ��� ������ min
			if ((v[i] == 1) && (d[i] < min))
			{ // ��������������� ��������
				min = d[i];
				minindex = i;
			}
		}
		// ��������� ��������� ����������� ���
		// � �������� ���� �������
		// � ���������� � ������� ����������� ����� �������
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
	// ����� ���������� ���������� �� ������
	printf("\nShortest distances to vertices:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%5d ", i);
	cout << endl;
	for (int i = 0; i < SIZE; i++)
		printf("%5d ", d[i]);


	// �������������� ����
	cout << endl;
	cout << "please enter destination vertex\n";
	cin >> chs;
	int ver[SIZE]; // ������ ���������� ������
	int end = chs; // ������ �������� ������� = 5 - 1
	ver[0] = end + 1; // ��������� ������� - �������� �������
	int k = 1; // ������ ���������� �������
	int weight = d[end]; // ��� �������� �������

	while (end != begin_index) // ���� �� ����� �� ��������� �������
	{
		for (int i = 0; i < SIZE; i++) // ������������� ��� �������
			if (b[end][i] != 0)   // ���� ����� ����
			{
				int temp = weight - b[end][i]; // ���������� ��� ���� �� ���������� �������
				if (temp == d[i]) // ���� ��� ������ � ������������
				{                 // ������ �� ���� ������� � ��� �������
					weight = temp; // ��������� ����� ���
					end = i;       // ��������� ���������� �������
					ver[k] = i + 1; // � ���������� �� � ������
					k++;
				}
			}
	}
	// ����� ���� (��������� ������� ��������� � ����� ������� �� k ���������)
	printf("\nshortest path\n");
	for (int i = k - 1; i >= 0; i--)
		printf("%3d ", ver[i]);
	cout << endl;
}

void Kruskal_alg()
{
	int m = 27;//���-�� ����

	vector <edge> graph(m); //����� ��������� �����
	vector <edge> graph_sorted(m); //����� ��������� �����
	vector <edge> tree; //����� ������
	vector <int> variety(SIZE); //��������� ������

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
	for (int i = 0; i < SIZE - 1; i++) //�� �������� ���������� ������, ��� �������� n-1 �����
	{ 
		cout << tree[i].x + 1 << " " << tree[i].y + 1 << " " << tree[i].w;
		if (i != SIZE - 2)
			cout << endl;
	}
}