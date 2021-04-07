#include "file_in.h"

void data_in(int* key_list, int* key_list_2)
{
    ifstream input("data.txt");
    for (int i = 0; i < SIZE; i++)
    {
        input >> key_list[i];
        key_list_2[i] = key_list[i];
        cout << key_list[i] << "    ";
    }
    cout << endl;
}