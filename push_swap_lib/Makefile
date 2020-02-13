LIBNAME		= push_swap_lib
FLAGS		= -Wall -Wextra -Werror -pedantic -g
CC			= clang

CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -I ../utilities_lib
LDFLAGS=
SOURCES=error.c \
        game_wrapper.c \
        game_wrapper2.c \
        game_wrapper3.c \
        game_wrapper4.c \
        game_wrapper5.c \
        parse_argv.c \
        pstack.c \

HEADERS=pstack.h

OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(LIBNAME)

$(LIBNAME): $(OBJECTS) $(HEADERS)
	@ar rc $(LIBNAME)  $(OBJECTS)
	@echo "push_swap_lib Compiled!"

.c.o:
	@$(CC) $(CFLAGS) $< -o $@

allcl: all clean

clean:
	@rm -rf $(OBJECTS)
	@echo "Object files removed"

fclean: clean
	@rm  -f ${LIBNAME}
	@echo ${LIBNAME} removed

re: fclean all