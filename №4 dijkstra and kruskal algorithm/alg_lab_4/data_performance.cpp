#include "data_performance.h"

void data_in()
{
	int i, j;
	ifstream input("matrix.txt");
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			input >> a[i][j];
}

void transform_to_not_orientied()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			b[i][j] = a[i][j];

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (b[i][j] != 0)
				b[j][i] = b[i][j];
}