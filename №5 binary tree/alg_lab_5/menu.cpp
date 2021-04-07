#include "menu.h"
void menu()
{
    int res, chs, flg = 1;
    tree_elm* root = NULL;
    while (flg != 0)
    {
        cout << "please choose action:\n 1 - create binary tree\n 2 - find element with key\n 3 - add new element\n 4 - direct bypass the tree\n 5 - find max element in the tree\n 6 - delete element from tree\n 7 - print tree\n 8- exit\n";
        cin >> chs;
        switch (chs)
        {
        case 1: // создание бинарного дерева
        {
            if (root != NULL)
                delete(root);
            root = create_tree(root);
            cout << "tree sucsessfuly created\n";
            break;
        }
        case 2: // поиск элемента 
        {
            if (root == NULL)
                cout << "Error. Tree isn`t exist\n";
            else
            {
                cout << "please enter key which you want to find\n";
                cin >> res;
                res = search_element(res, root);
                cout << res << endl;
            }
            break;
        }
        case 3: // добавление элемента
        {
            if (root == NULL)
                cout << "Error. Tree isn`t exist\n";
            else
            {
                cout << "please enter key for new element\n";
                cin >> res;
                add_element(res, root);
            }
            break;
        }
        case 4: // прямой обход дерева
        {
            if (root == NULL)
                cout << "Error. Tree isn`t exist\n";
            else
            {
                direct_bypass(root);
                cout << endl;
            }
            break;
        }
        case 5: // поиск максимального элемента
        {
            if (root == NULL)
                cout << "Error. Tree isn`t exist\n";
            else
            {
                res = search_max_element(root);
                cout << "max element is - " << res << endl;
            }
            break;
        }
        case 6: // удаление элемента 
        {
            if (root == NULL)
                cout << "Error. Tree isn`t exist\n";
            else
            {
                cout << "please enter key for delete element\n";
                cin >> res;
                root = delete_element(res, root);
            }
            break;
        }
        case 7: // вывод дерева в консоль
        {
            int p = 0;
            if (root == NULL)
                cout << "Error. Tree isn`t exist\n";
            else
            {
                printf("\n\n\n\n\n\nTree:\n");
                printTree(root, p);
            }
            break;
        }
        case 8: // выход из программы
        {
            flg = 0;
            break;
        }
        }
    }
}