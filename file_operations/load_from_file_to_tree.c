#include "../avl_tree/avl_tree.h"

/**
 * @brief Loads book data from the `books.txt` file into the AVL tree.
 *
 * @return Node* Returns the pointer to the root of the AVL tree loaded from the file.
 */
Node *load_from_file_to_tree() {
  Node *root = NULL;
  FILE *file = fopen("books.txt", "r");

  if (file == NULL) {
    printf("Error opening the file.\n");
    return NULL;
  }

  Book book;

  while (fread(&book, sizeof(Book), 1, file)) {
    root = insert(root, book);
  }

  fclose(file);

  return root;
}
