#include "./avl_tree.h"

/**
 * @brief Performs a pre-order traversal on the AVL tree.
 *
 * @param root Pointer to the root node of the tree.
 */
void pre_order(Node *root) {
  if (root != NULL) {
    printf("ISBN: %d, Title: %s, Author: %s, Year: %d, Quantity: %d\n",
           root->book.isbn, root->book.title, root->book.author,
           root->book.year, root->book.quantity);
    pre_order(root->left);
    pre_order(root->right);
  }
}

/**
 * @brief Performs an in-order traversal on the AVL tree.
 *
 * @param root Pointer to the root node of the tree.
 */
void in_order(Node *root) {
  if (root != NULL) {
    in_order(root->left);
    printf("ISBN: %d, Title: %s, Author: %s, Year: %d, Quantity: %d\n",
           root->book.isbn, root->book.title, root->book.author,
           root->book.year, root->book.quantity);
    in_order(root->right);
  }
}

/**
 * @brief Performs a post-order traversal on the AVL tree.
 *
 * @param root Pointer to the root node of the tree.
 */
void post_order(Node *root) {
  if (root != NULL) {
    post_order(root->left);
    post_order(root->right);
    printf("ISBN: %d, Title: %s, Author: %s, Year: %d, Quantity: %d\n",
           root->book.isbn, root->book.title, root->book.author,
           root->book.year, root->book.quantity);
  }
}
