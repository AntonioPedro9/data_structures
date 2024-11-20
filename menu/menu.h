#ifndef MENU_H
#define MENU_H

#include "../avl_tree/avl_tree.h"

void insert_option(Node **root);
void search_option(Node *root);
void remove_option(Node **root);
void sort_by_isbn();
void sort_by_title();
void sort_by_year();
void menu();

#endif
