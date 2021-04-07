#include "features.h"

struct list* init(char a)  // а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = NULL; // указатель на следующий узел
	lst->prev = NULL; // указатель на предыдущий узел
	return(lst);
}

struct list* push(list* lst, int value)
{
	struct list* temp;
	temp = (struct list*)malloc(sizeof(list));
	temp->field = value; // сохранение поля данных добавляемого узла
	temp->next = lst;
	lst->prev = temp;
	temp->prev = NULL;
	return(temp);
}

void list_print(list* lst)
{
	if (lst != NULL)
	{
		struct list* p;
		p = lst;
		int cnt = 0;
		do 
		{
			printf("%c %d \n", p->field, cnt); // вывод значения элемента p
			cnt++;
			p = p->next; // переход к следующему узлу
		} while (p != NULL); // условие окончания обхода
	}
}

struct list* pop(list* root)
{
	if (root == NULL)
		return 0;
	struct list* temp;
	temp = root->next;
	temp->prev = NULL;
	free(root);   // освобождение памяти текущего корня
	return(temp); // новый корень списка
}

struct list* delete_list(struct list* root)
{
	while (root != NULL) // условие окончания обхода
	{
		if (root->next == NULL)
		{
			free(root);
			root = NULL;
			break;
		}
		root = pop(root);
		root = root->next; // переход к следующему узлу
	}
	return NULL;
}

int search(struct list* root)
{
	struct list* temp = root;
	int max_element = -32768, cnt = 0;
	do
	{
		if (root->field > max_element)
			max_element = root->field;
		root = root->next; // переход к следующему узлу
	} while (root != NULL); // условие окончания обхода
	cout << "max element is " << char(max_element) << endl;
	root = temp;
	do
	{
		if (root->field == max_element)
			return cnt; // возвращение индекса максисмального элемента
		cnt++;
		root = root->next; // переход к следующему узлу
	} while (root != NULL); // условие окончания обхода
	root = temp; 
}