#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "../book/book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  Book book;
  struct Node *left;
  struct Node *right;
  int height;
} Node;

Node *create_node(Book book);
int max(int a, int b);
int height(Node *node);
int get_balance(Node *node);
Node *rotate_right(Node *y);
Node *rotate_left(Node *x);
Node *insert(Node *node, Book book);
Node *search(Node *root, int isbn);
void pre_order(Node *root);
void in_order(Node *root);
void post_order(Node *root);
Node *min_value_node(Node *node);
Node *remove_node(Node *root, int isbn);
void free_tree(Node *node);

#endif
