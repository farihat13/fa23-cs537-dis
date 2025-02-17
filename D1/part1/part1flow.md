# Discussion 01 Part 01

## Compiling a C code

--------------------------------
    hello-world.c
--------------------------------

**Commands:**

$ `gcc hello-world.c`           # compile & create executable `a.out`

$ `ls -t`                       # show files in curr directory sorted by last 

$ `./a.out`                     # run executable `a.out`

$ `gcc -o hello hello-world.c`  # compile & create executable `hello`
$ `./hello`                     # run executable `hello`

**Flags:**

$ `gcc -o hello hello-world.c`    # -o:       provide executable name

$ `gcc -Wall hello-world.c`       # -Wall:    show better warnings

$ `gcc -Werror hello-world.c`     # -Werror:  show warnings as errors

$ `gcc -O hello-world.c`          # -O:       optimize code

$ `gcc -g hello-world.c`          # -g:       debugging using gdb



## Linking / Makefile

--------------------------------
    my-prog.c
    fn.h
    fn.c
--------------------------------

Linking is required whenever we call functions not defined in the 
files we are compiling.

In general, programs are linked against the C standard library, 
e.g. `libc'.

But what if we call functions that we have defined in other files?
  
**commands:**

$ `gcc -c myprog.c`               # compiled individually to .o file

$ `gcc -c fn.c`                   # compiled individually to .o file

$ `ls -t`                         # check 

$ `gcc -o myprog myprog.o fn.o`   # linked together  

$ `./myprog`

Easy when one or two files. But what if many other files?

Solution: `makefile` or `Makefile`

    # open and understand `makefile `
    # recommended to read remzi's lab tutorial 
        https://pages.cs.wisc.edu/~remzi/OSTEP/lab-tutorial.pdf
    # [IMPORTANT] indentations need to be tabs

**commands:**    

$ `make`
$ `make clean`




## Debugging

--------------------------------
    buggy.c
--------------------------------

**commands:**

$ `gcc -g buggy.c -o buggy`

$ `gdb buggy`

$ `run`

$ `run`                           # restart

**breakpoint**

$ `break main`                    # break in the function main

$ `run`

$ `next`                          # run this line and go to the next line of code

$ `next`                          # alternative cmd: step [lookup the diff betwn them]

$ `print p`

$ `quit`


--------------------------------
    buggyfactorial.c
--------------------------------

$ `gcc -g buggyfactorial.c -o buggyf`

$ `gdb buggyf`
$ `run`

$ `break main`

$ `break buggyfactorial.c:9`

$ `info breakpoints`

$ `run`                           # restart

$ `list`                          # shows the code lines

$ `continue`                      # go to the next breakpoint

$ `print i`

$ `print f`

$ `quit`



## `man` Command


$ `man ls`

$ `man printf`

$ `man tan`

$ `man open`

$ `man 2 open`

$ `man -k file`




