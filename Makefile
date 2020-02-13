NAME1		= push_swap
FLAGS		= -Wall -Wextra -Werror -pedantic -g
CC			= clang
BUILD_DIR   = build

CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -I include
LDFLAGS=
SOURCES=

OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(PROJECT)

$(PROJECT): $(OBJECTS)
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	@echo "Compiled!"

.c.o:
	@$(CC) $(CFLAGS) $< -o $@

allcl: all clean

clean:
	@rm -rf $(OBJECTS)
	@echo "Object files removed"

fclean: clean
	@rm  -f ${PROJECT}
	@echo ${PROJECT} removed

re: fclean all