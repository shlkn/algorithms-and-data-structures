#pragma once
#include "alg_lab_3.h"

struct list* init(char a);
using namespace std;
struct list* push(list* lst, char value);
void push_back(list* lst, char value);
void list_print(list* lst);
struct list* pop(list* root);
void pop_back(list* lst);
struct list* delete_list(list* root);