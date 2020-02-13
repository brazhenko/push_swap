NAME1		= push_swap
NAME2		= checker
FLAGS		= -Wall -Wextra -Werror -pedantic -g
CC			= clang
BUILD_DIR   = build

LDFLAGS=
PUSH_SWAP_DIR=push
CHECKER_DIR=check
PUSH_SWAP_LIB_DIR=push_swap_lib
UTILITIES_LIB_DIR=utilities_lib

#INCLUDE=$(PUSH_SWAP_LIB_DIR) $(UTILITIES_LIB_DIR)
PUSH_SWAP_CFLAGS=-c -Wall -Wextra  -I $(PUSH_SWAP_LIB_DIR) -I $(UTILITIES_LIB_DIR)

PUSH_SWAP_SOURCES=	$(PUSH_SWAP_DIR)/accessories.c \
					$(PUSH_SWAP_DIR)/calc_shortest_way_len.c \
					$(PUSH_SWAP_DIR)/fill_one.c \
					$(PUSH_SWAP_DIR)/main.c \
					$(PUSH_SWAP_DIR)/process_put.c \
					$(PUSH_SWAP_DIR)/sort.c \


PUSH_SWAP_HEADERS= $(PUSH_SWAP_DIR)/sorter.h

PUSH_SWAP_OBJECTS=$(PUSH_SWAP_SOURCES:.c=.o)

CHECKER_CFLAGS=-c -Wall -Wextra  -I $(PUSH_SWAP_LIB_DIR) -I $(UTILITIES_LIB_DIR)

CHECKER_SOURCES=$(CHECKER_DIR)/error.c \
                $(CHECKER_DIR)/main.c

CHECKER_HEADERS=$(CHECKER_DIR)/checker.h

CHECKER_OBJECTS=$(CHECKER_SOURCES:.c=.o)


all: $(NAME1) #$(NAME2)

push_swap_lib:
	make --directory $(PUSH_SWAP_LIB_DIR)

$(NAME1): push_swap_lib $(PUSH_SWAP_OBJECTS)
	@$(CC) $(PUSH_SWAP_OBJECTS) ${PUSH_SWAP_LIB_DIR}/push_swap_lib.a ${UTILITIES_LIB_DIR}/libutils.a -o $(NAME1)
	@echo $(NAME1) "Compiled!"

$(CHECKER_OBJECTS):


$(NAME2): push_swap_lib $(CHECKER_OBJECTS)
	@$(CC) $(CHECKER_OBJECTS) ${PUSH_SWAP_LIB_DIR}/push_swap_lib.a ${UTILITIES_LIB_DIR}/libutils.a -o $(NAME2)
	@echo $(NAME2) "Compiled!"

.c.o:
	@$(CC) $(PUSH_SWAP_CFLAGS)  $< -o $@



allcl: all clean

clean:
	@rm -rf $(PUSH_SWAP_OBJECTS)
	@echo "Object files removed"

fclean: clean
	@rm  -f ${NAME1} ${NAME2}
	@echo ${PROJECT} removed

re: fclean all