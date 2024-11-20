#include "../avl_tree/avl_tree.h"

/**
 * @brief Saves all the nodes of the AVL tree to the `books.txt` file.
 *
 * @param root Pointer to the root node of the AVL tree.
 * @param file Pointer to the file opened in write mode, where the data will be saved.
 */
void save_from_tree_to_file(Node *root, FILE *file) {
  if (root != NULL) {
    fwrite(&(root->book), sizeof(Book), 1, file);
    save_from_tree_to_file(root->left, file);
    save_from_tree_to_file(root->right, file);
  }
}
