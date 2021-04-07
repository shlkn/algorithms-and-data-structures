#include "alg.h"

void q_sort(int* arr, int size)
{
    int l = 0, r = size - 1;
    int piv = arr[(l + r) / 2];
    while (l <= r)
    {
        while (arr[l] < piv)
            l++;
        while (arr[r] > piv)
            r--;
        if (l <= r)
            swap(arr[l++], arr[r--]);
    }
    if (r > 0)
        q_sort(arr, r + 1);
    if (l < size)
        q_sort(&arr[l], size - l);
}

void shake_sort(int* mas)
{
    int l = 0, r = SIZE - 1; //left & right array border
    int flg = 1;
    while ((l < r) && flg > 0)
    {
        flg = 0;
        for (int i = l; i < r; i++)
            if (mas[i] > mas[i + 1])
            {
                swap(mas[i], mas[i + 1]);
                flg = 1;
            }
        r--;
        for (int i = r; i > l; i--)
            if (mas[i - 1] > mas[i])
            {
                swap(mas[i - 1], mas[i]);
                flg = 1;
            }
        l++;
    }
}