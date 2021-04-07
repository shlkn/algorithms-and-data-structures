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

struct list* push(list* lst, char value)
{
    struct list* temp;
    temp = (struct list*)malloc(sizeof(list));
    temp->field = value; // ���������� ���� ������ ������������ ����
    temp->next = lst;
    lst->prev = temp;
    temp->prev = NULL;
    return(temp);
}

void push_back(list* lst, char value)
{
    list* p = lst;
    do
    {
        if (p->next != NULL)
            p = p->next;
        else break;
    } while (p->next != NULL); // ������� ��������� ������
    list* temp;
    temp = (struct list*)malloc(sizeof(list));
    temp->field = value;
    temp->next = NULL;
    temp->prev = p;
    p->next = temp;
}

void list_print(list* lst)
{
    if (lst == NULL)
        cout << "list dosen`t exist\n";
    else
    {
        struct list* p;
        p = lst;
        int cnt = 1;
        do {
            printf("%c %d \n", p->field, cnt); // ����� �������� �������� p
            cnt++;
            p = p->next; // ������� � ���������� ����
        } while (p != NULL); // ������� ��������� ������
    }
}

struct list* pop(list* root)
{
    struct list* temp;
    temp = root->next;
    temp->prev = NULL;
    printf("your element: %c \n", root->field);
    free(root);   // ������������ ������ �������� �����
    return(temp); // ����� ������ ������
}
void pop_back(list* lst)
{
    list* p = lst;
    do
    {
        if (p->next != NULL)
            p = p->next;
        else break;
    } while (p->next->next != NULL);
    printf("your element: %c \n", p->next->field);
    free(p->next);
    p->next = NULL;
}

struct list* delete_list(list* p)
{
    struct list* temp;
    while (1) // ������� ��������� ������
    {
        temp = p->next;
        printf("deleting element: %c \n", p->field);
        free(p);   // ������������ ������ �������� �����
        p = temp;
        if (p->next == NULL)
        {
            printf("deleting element: %c \n", p->field);
            free(p);
            p = NULL;
            break;
        }
    }
    return p;
}
