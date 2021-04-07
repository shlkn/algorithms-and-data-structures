#include "search_alg.h"
int search_s(char* k, int n, char key)
{
	int i;
	cout << "Algoritm S: ";
	for (i = 0; i < n; i++)
	{
		if (*(k + i) == key)
			cout << i << " ";
	}
	return i;
}

int search_q(char* k, int n, char key)
{
	cout << "Algoritm Q: ";
	k[n + 1] = key;
	int i = 0, rez = 0;

	for (i = 0;; i++)
	{
		if (k[i] == key)
		{
			rez = i;
			break;
		}
	}
	cout<<i<<endl;
	return i;
}

int search_t(char* k, int n, char key)
{
	cout << "Algoritm T: ";
	int i, cnt_1 = 0;
	char temp;
	for (i = 1; i < 17; i++)
		for (int j = 0; j < (17 - i); j++)
			if (k[j] < k[j + 1])
			{
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
	k[n + 1] = key;
	int rez = 0;

	for (i = 0;; i++)
	{
		if (k[i] == key)
		{
			rez = i;
			break;
		}
	}
	if (rez < 17)
		cout << i<<endl;
	cout << "Sort mass: ";
	for (i = 0; i < 17; i++)
		cout << k[i] << " ";
	return i;
}

int search_bin(char* k, int n, char key) //поиск делением по полам
{
	cout << "Algoritm Bin: ";
	int i;
	char temp;
	for (i = 1; i < 17; i++)
		for (int j = 0; j < (17 - i); j++)
			if (k[j] < k[j + 1])
			{
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}

	bool flag = false;
	int l = 0; // левая граница
	int r = 17; // правая граница
	int mid;

	while ((l <= r) && (flag != true))
	{
		mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
		if (k[mid] == key)
		{
			flag = true;
		}//проверяем ключ со серединным элементом
		if (k[mid] < key) {
			r = mid - 1;
		}// проверяем, какую часть нужно отбросить
		else
		{
			l = mid + 1;
		}
	}

	if (flag)
		cout << mid << endl;
	else cout << "sorry but key not found";
	cout << "Sort mass: ";
	for (i = 0; i < 17; i++)
		cout << k[i] << " ";
	return i;
}