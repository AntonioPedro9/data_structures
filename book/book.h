#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
  int isbn;
  char title[100];
  char author[50];
  int year;
  int quantity;
} Book;

#endif
