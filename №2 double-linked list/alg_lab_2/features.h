#pragma once
#include "alg_lab_2.h"

struct list* init(char a);
struct list* push(list* lst, int value);
void list_print(list* lst);
struct list* pop(list* root);
struct list* delete_list(struct list* root);
int search(struct list* root);