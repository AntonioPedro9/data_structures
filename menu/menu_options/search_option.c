#include "../menu.h"

/**
 * @brief Searches for a book in the AVL tree.
 *
 * @param root Pointer to the root node of the tree.
 */
void search_option(Node *root) {
  int isbn;

  printf("Enter ISBN to search: ");
  scanf("%d", &isbn);

  Node *found = search(root, isbn);

  if (found != NULL) {
    printf("Book found: ISBN: %d, Title: %s, Author: %s, Year: %d, "
           "Quantity: %d\n",
           found->book.isbn, found->book.title, found->book.author,
           found->book.year, found->book.quantity);
  } else {
    printf("Book with ISBN %d not found.\n", isbn);
  }
}
