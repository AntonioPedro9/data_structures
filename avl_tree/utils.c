#include "./avl_tree.h"

/**
 * @brief Returns the maximum value between two integers.
 *
 * @param a First value.
 * @param b Second value.
 * @return The larger value between a and b.
 */
int max(int a, int b) { return (a > b) ? a : b; }

/**
 * @brief Returns the height of a node in the AVL tree.
 *
 * @param node Pointer to the node.
 * @return The height of the node or 0 if the node is NULL.
 */
int height(Node *node) { return (node == NULL) ? 0 : node->height; }

/**
 * @brief Calculates the balance factor of a node.
 *
 * @param node Pointer to the node.
 * @return The balance factor.
 */
int get_balance(Node *node) {
  return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

/**
 * @brief Finds the node with the smallest value in the AVL tree.
 *
 * @param node Pointer to the root node of the tree.
 * @return Pointer to the node with the smallest value.
 */
Node *min_value_node(Node *node) {
  Node *current = node;
  
  while (current->left != NULL)
    current = current->left;
    
  return current;
}
