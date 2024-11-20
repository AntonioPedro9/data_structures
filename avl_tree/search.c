#include "./avl_tree.h"

/**
 * @brief Searches for a book in the AVL tree by ISBN.
 *
 * @param root Pointer to the root node of the tree.
 * @param isbn ISBN of the book to be searched.
 * @return Pointer to the found node or NULL if not found.
 */
Node *search(Node *root, int isbn) {
  if (root == NULL || root->book.isbn == isbn)
    return root;

  if (isbn < root->book.isbn)
    return search(root->left, isbn);

  return search(root->right, isbn);
}
