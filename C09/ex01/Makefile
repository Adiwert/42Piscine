# The list of source files (.c files) located in the srcs directory.
SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
# The list of .c source files defined in SRCS will convert into a list of object files (.o files).
OBJS	= ${SRCS:.c=.o}
# This points to the directory where the header files are located.
INCL	= includes
# This is the name of the final static library that you want to create.
TARGET	= libft.a
# This holds the command for creating a static library.
# "ar" command is used to create, modify, and extract from archives.
# "r": Replace or add files to the archive, "c": Create the archive if it does not exist.
ARCH	= ar rc
# This runs the ranlib command to index the archive.
LIBR	= ranlib
# This specifies the compiler to be used.
CC		= gcc
# This variable holds the rm -f command used for removing files without prompting for confirmation.
RM		= rm -f
# These are the flags passed to gcc during compilation.
CFLAGS	= -Wall -Wextra -Werror

# This is an implicit rule that tells make how to convert .c files into .o files
# "$<" refers to the current .c file being compiled.
# "$@" refers to the output file (the corresponding .o file).
# The "-c" flag tells the compiler to compile the source file into an object file.
# The "-I" flag specifies an include directory for the compiler to look for header files.
%.o: %.c
	@echo "Compiling $< to .o file..."
	${CC} ${CFLAGS} -c -I ${INCL} $< -o $@

# This rule specifies that to create libft.a, you need all the .o files listed in OBJS for prerequisite.
# The command "${ARCH} ${TARGET} ${OBJS}" uses ar rc to create the static library by archiving all object files (.o).
# The command "${LIBR} ${TARGET}" uses ranlib to index the library for faster linking.
${TARGET}: ${OBJS}
	@echo "Creating the static library ${TARGET}..."
	${ARCH} ${TARGET} ${OBJS}
	${LIBR} ${TARGET}
	@echo "Library ${TARGET} created successfully!"

# This rule specifies that the default action when running "make" is to create the TARGET.
all: ${TARGET}

# The command "${RM} ${OBJS}" deletes those unnecessary files.
clean:
	@echo "Cleaning up .o files..."
	${RM} ${OBJS}
	@echo ".o files removed!"

# The command "${RM} ${TARGET}" deletes the created library.
fclean: clean
	${RM} ${TARGET}
	@echo "Library ${TARGET} removed!"

# This rule runs fclean to delete everything (both object files and the library), then re-runs all to rebuild everything to force a complete recompilation.
re: fclean all

# This tells make that all, clean, fclean, and re are phony targets. This prevents make from being confused if files named all, clean, fclean, or re happen to exist in the directory.
.PHONY: all clean fclean re
