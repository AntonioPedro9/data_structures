#include "../../file_operations/file_operations.h"
#include "../menu.h"

void save_from_tree_to_file(Node *root, FILE *file);

/**
 * @brief Removes a book from the AVL tree.
 *
 * @param root Pointer to the root node pointer of the tree.
 */
void remove_option(Node **root) {
  int isbn;

  printf("Enter ISBN to remove: ");
  scanf("%d", &isbn);

  *root = remove_node(*root, isbn);

  FILE *file = fopen("books.txt", "w");
  save_from_tree_to_file(*root, file);
  fclose(file);

  printf("Book removed.\n");
}
