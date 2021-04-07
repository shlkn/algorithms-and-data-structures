#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 24 // кол-во элементов в дереве
using namespace std;

struct bin_tr // Структура элемента бинарного дерева
{
    struct bin_tr* left; //Указатель на левый узел
    int data; //Ключ в узле дерева
    struct bin_tr* right; //Указатель на правый узел
}typedef tree_elm;