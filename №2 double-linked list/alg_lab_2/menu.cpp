#include "menu.h"

void menu()
{
	char fs_vl, value;
	struct list* p = NULL, * temp;
	int ex_flg = 0, cnt = 0, i;
	int chs = 0;
	p = init('A');
	for (i = 0; i < 20; i++)
		p = push(p, 'B' + i);
	while (ex_flg == 0)
	{
		chs = action_req(p);
		switch (chs)
		{
		case 1: // инициализация нового списка
		{
			if (p == NULL)
			{
				cout << "deleting an existing one:\n";
				p = delete_list(p);
			}
			cout << "enter value for the first element\n";
			cin >> fs_vl;
			p = init(fs_vl);
			break;
		}
		case 2: // добавление первого элемента 
		{
			cout << "enter value for the element\n";
			cin >> value;
			p = push(p, value);
			break;
		}
		case 3: // удаление первого элемента 
		{
			p = pop(p);
			break;
		}
		case 4: // вывод списка на экран
		{
			list_print(p);
			break;
		}
		case 5: // поиск
		{
			cout<<"max element index - "<<search(p)<<endl;
			break;
		}
		case 6: // удаление списка
		{
			p = delete_list(p);
			break;
		}
		case 7: // выход
		{
			ex_flg = 1;
			break;
		}
		}
		chs = 0;
	}
}

int action_req(struct list* p)
{
	int chs;
	if (p == NULL)
		cout << "list empty or not exist\n";
	cout << "choose neded action:\n 1 - create list\n 2 - add element in the head of list\n 3 - delete head of list\n 4 - print the list\n 5 - find element in the list\n 6 - delete list\n 7 - exit\n";
	cin >> chs;
	return chs;
}