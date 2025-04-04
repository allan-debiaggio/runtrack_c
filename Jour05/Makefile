# This Makefile compiles the music program and provides utility commands

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = music.exe

# Source files
SRC = music.c

# Object files
OBJ = $(SRC:.c=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Clean object files
clean:
	rm -f $(OBJ)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Compile and run
run: all
	./$(NAME)

# Recompile everything
re: fclean all