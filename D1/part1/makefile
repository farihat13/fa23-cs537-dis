SRCS = myprog.c fn.c
TARG = myprog

CC = gcc
OPTS = -Wall -O
LIBS = -lm

OBJS = $(SRCS:.c=.o)


$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)

# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(TARG) 

# https://blog.wplauncher.com/what-is-in-linux/


