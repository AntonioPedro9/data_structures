#include "./sorting_algorithms.h"

/**
 * @brief Merges two subarrays of books in sorted order.
 * 
 * @param books Array of books to be sorted.
 * @param low The starting index of the first subarray.
 * @param mid The ending index of the first subarray and the midpoint.
 * @param high The ending index of the second subarray.
 */
void merge(Book books[], int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;
  Book left[n1], right[n2];

  for (int i = 0; i < n1; i++) {
    left[i] = books[low + i];
  }

  for (int j = 0; j < n2; j++) {
    right[j] = books[mid + 1 + j];
  }

  int i = 0, j = 0, k = low;

  while (i < n1 && j < n2) {
    if (left[i].year <= right[j].year) {
      books[k] = left[i];
      i++;
    } else {
      books[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    books[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    books[k] = right[j];
    j++;
    k++;
  }
}

/**
 * @brief Sorts an array of books using the Merge Sort algorithm.
 * 
 * @param books Array of books to be sorted.
 * @param low The starting index of the array to be sorted.
 * @param high The ending index of the array to be sorted.
 */
void merge_sort(Book books[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    merge_sort(books, low, mid);
    merge_sort(books, mid + 1, high);
    merge(books, low, mid, high);
  }
}
