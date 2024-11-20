#include "../../file_operations/file_operations.h"
#include "../menu.h"

void save_from_tree_to_file(Node *root, FILE *file);

/**
 * @brief Inserts a book into the AVL tree.
 *
 * @param root Pointer to the root node pointer of the tree.
 */
void insert_option(Node **root) {
  Book book;

  printf("Enter ISBN: ");
  scanf("%d", &book.isbn);

  printf("Enter title: ");
  getchar();
  fgets(book.title, sizeof(book.title), stdin);
  book.title[strcspn(book.title, "\n")] = 0;

  printf("Enter author: ");
  fgets(book.author, sizeof(book.author), stdin);
  book.author[strcspn(book.author, "\n")] = 0;

  printf("Enter year: ");
  scanf("%d", &book.year);

  printf("Enter quantity: ");
  scanf("%d", &book.quantity);

  *root = insert(*root, book);

  FILE *file = fopen("books.txt", "w");
  save_from_tree_to_file(*root, file);
  fclose(file);

  printf("Book successfully added!\n");
}
