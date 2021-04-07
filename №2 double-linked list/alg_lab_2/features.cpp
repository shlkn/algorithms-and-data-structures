#include "features.h"

struct list* init(char a)  // �- �������� ������� ����
{
	struct list* lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = NULL; // ��������� �� ��������� ����
	lst->prev = NULL; // ��������� �� ���������� ����
	return(lst);
}

struct list* push(list* lst, int value)
{
	struct list* temp;
	temp = (struct list*)malloc(sizeof(list));
	temp->field = value; // ���������� ���� ������ ������������ ����
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
			printf("%c %d \n", p->field, cnt); // ����� �������� �������� p
			cnt++;
			p = p->next; // ������� � ���������� ����
		} while (p != NULL); // ������� ��������� ������
	}
}

struct list* pop(list* root)
{
	if (root == NULL)
		return 0;
	struct list* temp;
	temp = root->next;
	temp->prev = NULL;
	free(root);   // ������������ ������ �������� �����
	return(temp); // ����� ������ ������
}

struct list* delete_list(struct list* root)
{
	while (root != NULL) // ������� ��������� ������
	{
		if (root->next == NULL)
		{
			free(root);
			root = NULL;
			break;
		}
		root = pop(root);
		root = root->next; // ������� � ���������� ����
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
		root = root->next; // ������� � ���������� ����
	} while (root != NULL); // ������� ��������� ������
	cout << "max element is " << char(max_element) << endl;
	root = temp;
	do
	{
		if (root->field == max_element)
			return cnt; // ����������� ������� �������������� ��������
		cnt++;
		root = root->next; // ������� � ���������� ����
	} while (root != NULL); // ������� ��������� ������
	root = temp; 
}