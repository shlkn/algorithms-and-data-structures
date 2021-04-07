#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 15 //размерность матрицы 

struct edge {
	int x, y, w; //вершины
	edge() {}
	edge(int a, int b, int c) {
		x = a;
		y = b;
		w = c;
	}
};

using namespace std;