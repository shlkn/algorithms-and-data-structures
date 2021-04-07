#include "features.h"
tree_elm* create_tree(tree_elm* root)
{
    tree_elm* temp;
    int value;
    ifstream input("data.txt");
    input >> value;
    root = new tree_elm;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    temp = root;
    for (int i = 1; i < SIZE; i++)
    {
        root = temp;
        input >> value;
        while (true)
        {
            if ((value < root->data && root->left == NULL) || (value > root->data && root->right == NULL))
                break;
            if (root->data < value)
                root = root->right;
            else root = root->left;
        }
        if (value < root->data && root->left == NULL)
        {
            root->left = new tree_elm;
            root->left->data = value;
            root->left->left = NULL;
            root->left->right = NULL;
            continue;
        }
        if (value > root->data && root->right == NULL)
        {
            root->right = new tree_elm;
            root->right->data = value;
            root->right->left = NULL;
            root->right->right = NULL;
            continue;
        }
    }
    return temp;
}

void direct_bypass(tree_elm* root)
{
    cout << root->data << "   ";
    if (root->left != NULL)
        direct_bypass(root->left);
    if (root->right != NULL)
        direct_bypass(root->right);
}

int search_max_element(tree_elm* root)
{
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int search_element(int key, tree_elm* root)
{
    while (root->data != key)
    {
        if (key > root->data)
            root = root->right;
        else root = root->left;
        if ((key > root->data && root->right == NULL) || (key < root->data && root->left == NULL))
        {
            cout << "key is not exsist in this tree\n";
            return -1;
        }
    }
    return root->data;
}

int add_element(int key, tree_elm* root)
{
    tree_elm* temp;
    temp = root;
    while (true)
    {
        root = temp;
        while (true)
        {
            if ((key < root->data && root->left == NULL) || (key > root->data && root->right == NULL))
            {
                break;
            }
            if (root->data == key)
            {
                cout << "this element alredy exist, try again\n";
                return -1;
            }
            if (root->data < key)
                root = root->right;
            else root = root->left;
        }
        if (key < root->data && root->left == NULL)
        {
            root->left = new tree_elm;
            root->left->data = key;
            root->left->left = NULL;
            root->left->right = NULL;
            break;
        }
        if (key > root->data && root->right == NULL)
        {
            root->right = new tree_elm;
            root->right->data = key;
            root->right->left = NULL;
            root->right->right = NULL;
            break;
        }
    }
}

tree_elm* delete_element(int key, tree_elm* root)
{
    tree_elm* main_root = root;
    tree_elm* del_ptr, * temp, * temp_right;
    int temp_int;
    while (root->data != key)
    {
        if (key > root->data)
            root = root->right;
        else root = root->left;
        if ((key > root->data && root->right == NULL) || (key < root->data && root->left == NULL))
            cout << "key is not exsist in this tree\n";
    }
    del_ptr = root;//root указывает на удаляемый элемент
    root = root->right;
    if (root->left == NULL)
    {
        temp_int = root->data;
        del_ptr->data = temp_int;
        del_ptr->right = root->right;
        delete(root);
    }//root указывает на правого потомка удаляемого элемента
    else
        while (true)
        {
            if (root->left == NULL)
            {
                if (root->right == NULL)//если правый потомок удаляемого элемента не имеет правого потомока
                {
                    temp_int = root->data;
                    del_ptr->data = temp_int;
                    temp_right = del_ptr->right;
                    while (temp_right->left != root)
                        temp_right = temp_right->left;
                    temp_right->left = NULL;
                    delete(root);
                }
                else
                {
                    temp_right = del_ptr->right;
                    while (temp_right->left != root)
                    {
                        if (temp_right->left != NULL)
                            temp_right = temp_right->left;
                        else break;
                        temp_right = temp_right->left;
                    }
                    temp_right->left = root->right;
                    del_ptr->data = root->data;
                    delete(root);
                }
                break;
            }
            root = root->left;
        }
    return main_root;
}

void printTree(tree_elm* treePtr, int p)
{
    if (treePtr != NULL)
    {
        printTree(treePtr->right, p + 3);
        for (int i = 0; i < p; i++)
            printf(" ");
        printf("%3d\n", treePtr->data);
        printTree(treePtr->left, p + 3);
    }
}
void delete_tree(tree_elm* root)
{
    if (root->left != NULL)
        delete_tree(root->left);
    if (root->right != NULL)
        delete_tree(root->right);
    delete root;
}