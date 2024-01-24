# Discussion 01 Part 02


## FILE I/O



### Opening a directory

--------------------------------
    myls.c
--------------------------------
    
notice the functions: `opendir', `readdir', `stat`, `S_ISREG`

$ `man stat`

$ `man 2 stat`


### Opening and reading files

--------------------------------
    mycat.c
--------------------------------

notice the functions: `fopen`, `fclose`


### String manipulation

--------------------------------
    myls.c
--------------------------------

print some string in var `buf` bold


```c
printf("\033[1m");
printf("%s", buf);
printf("\033[0m");
```

All ANSI codes <https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_codes>
    
Always terminate with `\033[0m'. 
    
`4m` is underline, `1m` is bold, `3m` is italic.


### Practice problems

1) Make every other line of `mycat' print bold. Assume, a line is atmost 80 chars long.
   
2) Print lines as bold only if they contain the text "printf" .
