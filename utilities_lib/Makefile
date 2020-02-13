LIBNAME		= libutils.a
FLAGS		= -Wall -Wextra -Werror -pedantic -g
CC			= clang

CC			= gcc
CFLAGS		= -c -Wall -Wextra -Werror -I ../utilities_lib
LDFLAGS=
SOURCES=charptrptrdel.c \
        ft_atoi.c \
        ft_itoa.c \
        max.c \
        memcpy.c \
        memset.c \
        strcmp.c \
        strncmp.c \
        strncpy.c \
        strnew.c \
        strsplitchrset.c \
        strsub.c \
        xmalloc.c

HEADERS=utilities.h

OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(LIBNAME)

$(LIBNAME): $(OBJECTS) $(HEADERS)
	@ar rc $(LIBNAME)  $(OBJECTS)
	@echo $(LIBNAME) "Compiled!"

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