#include "menu.h"

void menu()
{
    char fs_vl, value;
    struct list* p = NULL, * temp;
    int ex_flg = 0, i;
    int chs, chs_1;
    p = init('A');
    for (i = 0; i < 20; i++) // создание списка
        p = push(p, 'B' + i);
    while (ex_flg == 0)
    {
        chs = action_req(p);
        switch (chs)
        {
        case 1:
        {
            if (p != NULL)
            {
                cout << "deleting an existing one:\n";
                delete_list(p);
            }
            cout << "enter value for the first element\n";
            cin >> fs_vl;
            p = init(fs_vl);
            break;
        }
        case 2:
        {
            cout << "please choose action:\n 1 - add element to the head of title\n 2 - add element to the end of title\n";
            cin >> chs_1;
            cout << "enter value for the element\n";
            cin >> value;
            if (chs_1 == 49)
                p = push(p, value);
            if (chs_1 == 50)
                push_back(p, value);
            break;
        }
        case 3:
        {
            cout << "please choose action: 1 - delete first element 2 - delete last element\n";
            cin >> chs_1;
            if (chs_1 == 1 && p != NULL)
                p = pop(p);
            else continue;
            if (chs_1 == 2 && p != NULL)
                pop_back(p);
            else continue;
            break;
        }
        case 4:
        {
            list_print(p);
            break;
        }
        case 5:
        {
            p = delete_list(p);
            break;
        }
        case 6:
        {
            ex_flg = 1;
            break;
        }
        }
        chs = 0;
    }
}

char action_req(struct list* p) // запрос действия от пользователя
{
    int chs;
    if (p == NULL)
        cout << "list empty or not exist\n";
    cout << "choose neded action:\n 1 - create list\n 2 - add element to the list\n 3 - delete element of the list\n 4 - print the list\n 5 - delete list\n 6 - exit\n";
    cin >> chs;
    return chs;
}