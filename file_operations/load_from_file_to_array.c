#include "../avl_tree/avl_tree.h"

/**
 * @brief Loads books from the `books.txt` file into an array.
 *
 * @param books Pointer to the array where the books will be stored.
 * @param size Pointer to the integer where the size of the array will be stored.
 * @return int Returns 1 if the file was successfully loaded, or 0 in case of an error.
 */
int load_from_file_to_array(Book **books, int *size) {
  FILE *file = fopen("books.txt", "r");
  if (file == NULL) {
    printf("Error opening the file.\n");
    return 0;
  }

  fseek(file, 0, SEEK_END);
  *size = ftell(file) / sizeof(Book);
  rewind(file);

  *books = (Book *)malloc(*size * sizeof(Book));
  if (*books == NULL) {
    printf("Memory allocation error.\n");
    fclose(file);
    return 0;
  }

  fread(*books, sizeof(Book), *size, file);
  fclose(file);

  return 1;
}
