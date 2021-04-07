#include "alg.h"
#include "file_in.h"

int main()
{
    int key_list[SIZE], key_list_2[SIZE]; //2 eqvivalental array`s for sort
    data_in(key_list, key_list_2);
    q_sort(key_list, SIZE);
    for (int i = 0; i < SIZE; i++)
        cout << key_list[i] << "    ";
    cout << endl;
    shake_sort(key_list_2);
    for (int i = 0; i < SIZE; i++)
        cout << key_list_2[i] << "  ";
    return 0;
}

