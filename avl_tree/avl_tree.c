#include "./avl_tree.h"

/**
 * @brief Creates a new AVL node with a book.
 *
 * @param book The book structure to be stored in the node.
 * @return Pointer to the newly created node.
 */
Node *create_node(Book book) {
  Node *node = (Node *)malloc(sizeof(Node));

  node->book = book;
  node->left = node->right = NULL;
  node->height = 1;

  return node;
}

/**
 * @brief Performs a right rotation on the subtree.
 *
 * @param y The root node of the subtree.
 * @return The new root node after the rotation.
 */
Node *rotate_right(Node *y) {
  Node *x = y->left;
  Node *temp = x->right;

  x->right = y;
  y->left = temp;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

/**
 * @brief Performs a left rotation on the subtree.
 *
 * @param x The root node of the subtree.
 * @return The new root node after the rotation.
 */
Node *rotate_left(Node *x) {
  Node *y = x->right;
  Node *temp = y->left;

  y->left = x;
  x->right = temp;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

/**
 * @brief Frees all memory allocated for the AVL tree.
 *
 * @param node Pointer to the root node of the tree.
 */
void free_tree(Node *node) {
  if (node != NULL) {
    free_tree(node->left);
    free_tree(node->right);
    free(node);
  }
}
