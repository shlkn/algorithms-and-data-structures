#pragma once
#include "alg_lab_5.h"

tree_elm* create_tree(tree_elm* root);
void direct_bypass(tree_elm* root);
int search_max_element(tree_elm* root);
int search_element(int key, tree_elm* root);
int add_element(int key, tree_elm* root);
tree_elm* delete_element(int key, tree_elm* root);
void printTree(tree_elm* treePtr, int p);
void delete_tree(tree_elm* root);