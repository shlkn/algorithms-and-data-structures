#pragma once
#include <iostream>

struct list
{
    char field; // ���� ������
    struct list* next; // ��������� �� ��������� �������
    struct list* prev; // ��������� �� ���������� �������
};