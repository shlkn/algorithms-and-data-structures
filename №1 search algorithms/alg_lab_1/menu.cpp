#include "menu.h"

void menu()
{
	int chs;
	char mas[18], key;
	while (true)
	{
		cout << "how do you want to enter a sequence of characters?\n 1 - manual\n 2 - from program\n";
		cin >> chs;
		switch(chs)
		{
		case 1:
		{
			for (int i = 0; i < 17; i++)
			{
				cin >> mas[i];
				cout << mas[i] << " ";
				break;
			}
			break;
		}
		case 2:
		{
			ifstream input("in.txt");
			for (int i = 0; i < 17; i++)
			{
				input >> mas[i];
				cout << mas[i] << " ";
			}
			break;
		}
		}
		break;
	}
	cout << endl;
	cout << "enter the key\n";
	cin >> key;
	search_s(mas, 16, key);
	cout << endl;
	search_q(mas, 16, key);
	search_t(mas, 16, key);
	cout << endl;
	search_bin(mas, 16, key);
}