SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
INCL	= includes
TARGET	= libft.a
ARCH	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	@echo "Compiling $< to .o file..."
	${CC} ${CFLAGS} -c -I ${INCL} $< -o $@

${TARGET}: ${OBJS}
	@echo "Creating the static library ${TARGET}..."
	${LIBC} ${TARGET} ${OBJS}
	${LIBR} ${TARGET}
	@echo "Library ${TARGET} created successfully!"

all: ${TARGET}

clean:
	@echo "Cleaning up .o files..."
	${RM} ${OBJS}
	@echo ".o files removed!"

re: fclean all

.PHONY: all clean fclean re
