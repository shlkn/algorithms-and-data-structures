#pragma once
#include <iostream>

struct list
{
    char field; // поле данных
    struct list* next; // указатель на следующий элемент
    struct list* prev; // указатель на предыдущий элемент
};