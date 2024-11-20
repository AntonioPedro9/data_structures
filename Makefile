# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror -std=c99

# Diretórios
SRC_DIR = .
AVL_DIR = ./avl_tree
FILE_OP_DIR = ./file_operations
MENU_DIR = ./menu
MENU_OPT_DIR = ./menu/menu_options
SORT_DIR = ./sorting_algorithms
BOOK_DIR = ./book

# Arquivos de cabeçalho
INCLUDES = -I$(AVL_DIR) -I$(FILE_OP_DIR) -I$(MENU_DIR) -I$(SORT_DIR) -I$(BOOK_DIR)

# Arquivos fonte
SRCS = $(SRC_DIR)/main.c \
       $(AVL_DIR)/avl_tree.c \
       $(AVL_DIR)/exibition_orders.c \
       $(AVL_DIR)/insert.c \
       $(AVL_DIR)/remove.c \
       $(AVL_DIR)/search.c \
       $(AVL_DIR)/utils.c \
       $(FILE_OP_DIR)/load_from_file_to_array.c \
       $(FILE_OP_DIR)/load_from_file_to_tree.c \
       $(FILE_OP_DIR)/save_from_tree_to_file.c \
       $(MENU_DIR)/menu.c \
       $(MENU_OPT_DIR)/insert_option.c \
       $(MENU_OPT_DIR)/remove_option.c \
       $(MENU_OPT_DIR)/search_option.c \
       $(MENU_OPT_DIR)/sort_by_isbn.c \
       $(MENU_OPT_DIR)/sort_by_title.c \
       $(MENU_OPT_DIR)/sort_by_year.c \
       $(SORT_DIR)/heap_sort.c \
       $(SORT_DIR)/merge_sort.c \
       $(SORT_DIR)/quick_sort.c \
       $(SORT_DIR)/swap.c

# Arquivos objeto gerados
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(TARGET)

# Linkagem do executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

# Compilação de cada arquivo .c para .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

# impeza dos arquivos gerados
run:
	./main

# Regra para limpar e recompilar
rebuild: clean all
