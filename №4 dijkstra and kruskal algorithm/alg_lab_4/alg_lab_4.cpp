#include "alg_lab_4.h"
#include "data_performance.h"
#include "algorithms.h"

int a[SIZE][SIZE]; // матрица связей "a"
int b[SIZE][SIZE]; // матрица сделанная на основе матрицы а

int main()
{
	data_in(); // ввод матрицы связей из файла
	transform_to_not_orientied(); // преобразование ориентированного графа в неориентированный граф
	Dijkstras_alg(); // алгоритм Дейкстры
	Kruskal_alg(); // алгоритм Краскала
	return 0;
}