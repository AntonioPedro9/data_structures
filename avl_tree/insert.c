#include "./avl_tree.h"

/**
 * @brief Inserts a book into the AVL tree.
 *
 * @param node Pointer to the root node of the tree.
 * @param book The book structure to be inserted.
 * @return Pointer to the updated root node of the tree.
 */
Node *insert(Node *node, Book book) {
  if (node == NULL)
    return create_node(book);

  if (book.isbn < node->book.isbn)
    node->left = insert(node->left, book);
  else if (book.isbn > node->book.isbn)
    node->right = insert(node->right, book);
  else
    return node;

  node->height = 1 + max(height(node->left), height(node->right));

  int balance = get_balance(node);

  // Left Left Case
  if (balance > 1 && book.isbn < node->left->book.isbn)
    return rotate_right(node);

  // Right Right Case
  if (balance < -1 && book.isbn > node->right->book.isbn)
    return rotate_left(node);

  // Left Right Case
  if (balance > 1 && book.isbn > node->left->book.isbn) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
  }

  // Right Left Case
  if (balance < -1 && book.isbn < node->right->book.isbn) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
  }

  return node;
}
