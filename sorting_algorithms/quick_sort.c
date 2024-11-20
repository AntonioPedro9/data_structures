#include "./sorting_algorithms.h"

/**
 * @brief Partitions the array of books for the Quick Sort algorithm.
 * 
 * @param books Array of books to be partitioned.
 * @param low The starting index of the array to be partitioned.
 * @param high The ending index of the array to be partitioned.
 * @return The index of the pivot element after partitioning.
 */
int partition(Book books[], int low, int high) {
  int pivot = books[high].isbn;
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (books[j].isbn < pivot) {
      i++;
      swap(&books[i], &books[j]);
    }
  }

  swap(&books[i + 1], &books[high]);

  return (i + 1);
}

/**
 * @brief Sorts an array of books using the Quick Sort algorithm.
 * 
 * @param books Array of books to be sorted.
 * @param low The starting index of the array to be sorted.
 * @param high The ending index of the array to be sorted.
 */
void quick_sort(Book books[], int low, int high) {
  if (low < high) {
    int pi = partition(books, low, high);
    quick_sort(books, low, pi - 1);
    quick_sort(books, pi + 1, high);
  }
}
