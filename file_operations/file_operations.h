#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "../avl_tree/avl_tree.h"

void save_from_tree_to_file(Node *root, FILE *file);
Node *load_from_file_to_tree();
int load_from_file_to_array(Book **books, int *size);

#endif
