#pragma once
#include <iostream>
using namespace std;

struct list
{
	int field; // ���� ������
	struct list* next; // ��������� �� ��������� �������
	struct list* prev; // ��������� �� ���������� �������
}; 
