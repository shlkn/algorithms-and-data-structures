#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 24 // ���-�� ��������� � ������
using namespace std;

struct bin_tr // ��������� �������� ��������� ������
{
    struct bin_tr* left; //��������� �� ����� ����
    int data; //���� � ���� ������
    struct bin_tr* right; //��������� �� ������ ����
}typedef tree_elm;