#include "./sorting_algorithms.h"
#include <string.h>

/**
 * @brief Rearranges a portion of the array to satisfy the heap property.
 * 
 * @param books Array of books to be sorted.
 * @param n Total number of books in the array.
 * @param i Index of the node to be heapified.
 */
void heapify(Book books[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && strcmp(books[left].title, books[largest].title) > 0) {
    largest = left;
  }

  if (right < n && strcmp(books[right].title, books[largest].title) > 0) {
    largest = right;
  }

  if (largest != i) {
    swap(&books[i], &books[largest]);
    heapify(books, n, largest);
  }
}

/**
 * @brief Sorts an array of books using the Heap Sort algorithm.
 *
 * @param books Array of books to be sorted.
 * @param n Total number of books in the array.
 */
void heap_sort(Book books[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(books, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(&books[0], &books[i]);
    heapify(books, i, 0);
  }
}
