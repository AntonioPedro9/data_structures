#include "./menu.h"
#include "../book/book.h"
#include "../file_operations/file_operations.h"
#include "../sorting_algorithms/sorting_algorithms.h"

Node *load_from_file_to_tree();

/**
 * @brief Displays the main application menu.
 */
void menu() {
  Node *root = load_from_file_to_tree();
  int option;

  do {
    printf("\n---- Menu ----\n");
    printf("1. Insert book\n");
    printf("2. Search book\n");
    printf("3. Remove book\n");
    printf("4. Display books\n");
    printf("5. Sort by ISBN (QuickSort)\n");
    printf("6. Sort by title (HeapSort)\n");
    printf("7. Sort by year (MergeSort)\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      insert_option(&root);
      break;
    case 2:
      search_option(root);
      break;
    case 3:
      remove_option(&root);
      break;
    case 4:
      printf("Displaying all books:\n");
      in_order(root);
      // pre_order(root);
      // post_order(root);
      break;
    case 5: {
      sort_by_isbn();
      break;
    }
    case 6: {
      sort_by_title();
      break;
    }
    case 7: {
      sort_by_year();
      break;
    }
    case 8:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid option, please try again.\n");
    }
  } while (option != 8);

  free_tree(root);
}
