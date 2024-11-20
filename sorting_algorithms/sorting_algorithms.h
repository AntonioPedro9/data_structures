#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "../avl_tree/avl_tree.h"

void quick_sort(Book books[], int low, int high);
void heap_sort(Book books[], int n);
void merge_sort(Book books[], int low, int high);
void swap(Book *a, Book *b);

#endif
