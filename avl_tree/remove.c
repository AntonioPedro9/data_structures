#include "./avl_tree.h"

/**
 * @brief Removes a book from the AVL tree by ISBN.
 *
 * @param root Pointer to the root node of the tree.
 * @param isbn ISBN of the book to be removed.
 * @return Pointer to the updated root node of the tree.
 */
Node *remove_node(Node *root, int isbn) {
  if (root == NULL)
    return root;

  // Traverse the tree to find the node to be removed
  if (isbn < root->book.isbn)
    root->left = remove_node(root->left, isbn);
  else if (isbn > root->book.isbn)
    root->right = remove_node(root->right, isbn);
  else {
    // Node to be removed found

    // Node with only one child or no child
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;

      // No child case
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }

      free(temp);
    } else {
      // Node with two children, get the inorder successor (smallest in the right subtree)
      Node *temp = min_value_node(root->right);

      // Copy the inorder successor's content to this node
      root->book = temp->book;

      // Delete the inorder successor
      root->right = remove_node(root->right, temp->book.isbn);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = get_balance(root);

  // Left Left Case
  if (balance > 1 && get_balance(root->left) >= 0)
    return rotate_right(root);

  // Left Right Case
  if (balance > 1 && get_balance(root->left) < 0) {
    root->left = rotate_left(root->left);
    return rotate_right(root);
  }

  // Right Right Case
  if (balance < -1 && get_balance(root->right) <= 0)
    return rotate_left(root);

  // Right Left Case
  if (balance < -1 && get_balance(root->right) > 0) {
    root->right = rotate_right(root->right);
    return rotate_left(root);
  }

  return root;
}
