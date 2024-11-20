#include "../../file_operations/file_operations.h"
#include "../../sorting_algorithms/sorting_algorithms.h"
#include "../menu.h"

void sort_by_year() {
  Book *books = NULL;
  int size = 0;

  if (load_from_file_to_array(&books, &size)) {
    merge_sort(books, 0, size - 1);

    printf("Books sorted by year:\n");

    for (int i = 0; i < size; i++) {
      printf("ISBN: %d, Title: %s, Author: %s, Year: %d, Quantity: %d\n",
             books[i].isbn, books[i].title, books[i].author, books[i].year,
             books[i].quantity);
    }

    free(books);
  }
}
