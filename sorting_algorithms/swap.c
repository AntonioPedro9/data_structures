#include "./sorting_algorithms.h"

/**
 * @brief Swaps two books in the array.
 * 
 * @param a Pointer to the first book to be swapped.
 * @param b Pointer to the second book to be swapped.
 */
void swap(Book *a, Book *b) {
  Book temp = *a;
  *a = *b;
  *b = temp;
}
