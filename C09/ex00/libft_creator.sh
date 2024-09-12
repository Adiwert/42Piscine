#!/bin/sh

# Remove any existing library file
rm -f libft.a

# Find all .c files and compile them into object files (.o)
find . -name "*.c" -type f -exec gcc -Wall -Werror -Wextra -c {} \;

# Create the static library libft.a from the .o files
ar rc libft.a *.o

# Delete all .o files after the library is created
find . -name "*.o" -type f -delete
