# Discussion 03

## Summary
- go through the project description
    CTRL C, CTRL Z
- makefiles
- some linux commands
- ideas for creating a simple shell


## makefiles

- $ `make -f makefile2`
- $ `make clean -f makefile2`

## Some linux commands

- $ `echo hello`
- $ `cd ..`
- $ `cd D3`
- $ `sleep 10`

## IO redirection

- $ `echo helloworld > hello.txt`

How is IO redirection in shell implemented?
- $ `echo hello > output`
- Redirect stdout to file “hello”

## Piping
  
- $ `cat helloworld | echo`

## Background processes
- $ `sleep 2`
- $ `sleep 20 &`
- $ `jobs`

- $ `sleep 20` 
    - `CTRL + Z` suspended/stopped
- $ `bg %1`
- $ `fg %1`

- $ `sleep 10`
    - `CTRL + Z` # Stopped / Suspended
    - `CTRL + C` # Kill a process
- $ `jobs`

- $ `fg %1` # bring the job [pid] back to foreground

A simple shell is basically a `while` loop with `fork` and `exec`


# ideas for creating a simple shell


* `fork`
* `forksleep`
* `forkwait`
* `forkexec`
* `execdemo`
* `parse`
* `pipeexec`
    - sharing-pipe-with-example
    
    * pipe
        - pipe-with-example
    * dup2
        - dup2-with-example

    * How is pipe in shell implemented?
        - cmd1 | cmd2
        - The stdout of cmd1 is sent to the stdin of cmd2
    * what is a file descriptor? 
        ```c
        int fd = open(“filename”, MODE);
        _ = read(fd, buf, count);
        ```
        
        - Special fd:
        • `stdin`: 0
        • `stdout`: 1
        • `stderr`: 2

* `signals` with example


The C fork() function is a primary method of process creation of an operating 
system like Unix. 
Forking is the process of creating of duplicate process from an existing process.
The fork() is used for creating a new copy of the calling function. 
The newly created process is known as the Child process and the process 
from which the child process is created is known as the parent process.
child process make an exact copy of the parent process at the moment of fork.


Pipes are useful for communication between related processes(inter-process communication).
Pipe is one-way communication only i.e we can use a pipe such that 
One process write to the pipe, and the other process reads from the pipe. 

If a process tries to read before something is written to the pipe, 
the process is suspended until something is written.
The pipe system call finds the first two available positions 
in the process’s open file table and allocates them for the read and write ends of the pipe.
