CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=gnu18 -g

# Get a list of all .c files in the current directory
SRC_FILES = $(wildcard *.c)

# Generate corresponding executable names
TARGS = $(patsubst %.c, %, $(SRC_FILES))

# The default target, which builds all executables
all: $(TARGS)

# Rule to build each executable from a .c file
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean up generated executables
clean:
	rm -f $(TARGS) *.o *.out

.PHONY: all clean
