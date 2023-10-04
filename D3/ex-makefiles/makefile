myprog1: myprog.o fn.o
	gcc -o myprog1 myprog.o fn.o

myprog.o: myprog.c
	gcc -O -Wall -c myprog.c

fn.o: fn.c
	gcc -O -Wall -c fn.c

clean:
	rm -f myprog.o fn.o myprog1

# Makefiles are whitespace sensitive 
# target: prerequisite1 prerequisite2 ...
    # command1 # must put 1 tab before command / spaces wont work
    # command2
    # ...