# Discussion 07

`mmap` -- allocate memory, or map files or devices into memory

```c
#include <sys/mman.h>

void *
mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
```

## malloc using `mmap`

1. `mmap-malloc.c`
This example creates an array of N integers using mmap. 
The mmap can be similar to malloc when used with the 
MAP_ANONYMOUS and MAP_PRIVATE flags.

## file-backed mapping using `mmap`

2. `mmap-fileread.c`
This example 
    a) maps a file using mmap,
    b) and reads the file through the mmapped memory.

## mmap flags

### MAP_FIXED

3. `mmap-fixed.c`
This example creates an array of N integers at a fixed address 
using mmap with MAP_FIXED.

### MAP_PRIVATE

When we use MAP_PRIVATE, changes to mmapped file are NOT reflected in the original file.

4. `mmap-private.c`
This example 
    a) mmaps a file in MAP_PRIVATE mode,
    b) and writes to the mmapped file. 
But, the write is NOT reflected in the original file.

### MAP_SHARED

When we use MAP_SHARED, changes to mmapped file are reflected in the original file.

5. `mmap-shared.c`
This example 
    a) mmaps a file in MAP_SHARED mode,
    b) and writes to the mmapped file. 
The write is reflected in the original file.

### MAP_GROWSUP

Does not exist in original mmap.

### forking and MAP_ANON

6. `mmap-fork-anon-private.c`
This example 
    a) creates an array of N integers in the parent using mmap with MAP_PRIVATE flag
        ( 0, 10, 20, ....),
    b) and changes the first element in the child process
        (99, 10, 20, ...).
But, the parent can NOT see the change because of the MAP_PRIVATE flag.

6. `mmap-fork-anon-shared.c`
This example 
    a) creates an array of N integers in the parent using mmap with MAP_SHARED flag
        ( 0, 10, 20, ....),
    b) and changes the first element in the child process
        (99, 10, 20, ...).
The parent CAN see the change because of the MAP_SHARED flag.

### forking and file-backed mapping

7. `mmap-fork-private.c`
This example
 a) mmaps a file in MAP_PRIVATE mode in the parent,
 b) writes to the mmapped memory in the child,
 c) reads the mmapped memory in the parent.

The write by child is NOT reflected in the parent because of MAP_PRIVATE.

8. `mmap-fork-shared.c`
This example
 a) mmaps a file in MAP_SHARED mode in the parent,
 b) writes to the mmapped memory in the child,
 c) and reads the mmapped memory in the parent.
The write by child is NOT reflected in the parent because of MAP_PRIVATE.

## Implementing `mmap`

### xv6 memory management

`memlayout.h`

```c
// Memory layout
...
#define PHYSTOP 0xE000000           // Top physical memory
...
#define KERNBASE 0x80000000         // First kernel virtual address
...
// You might consider storing 0x60000000 here
#define V2P(a) (((uint) (a)) - KERNBASE)
#define P2V(a) ((void *)(((char *) (a)) + KERNBASE))
...
```

`mmu.h`
```c
#define PGSIZE          4096    // bytes mapped by a page
...
#define PGROUNDUP(sz)  (((sz)+PGSIZE-1) & ~(PGSIZE-1))
#define PGROUNDDOWN(a) (((a)) & ~(PGSIZE-1))
...
// Page table/directory entry flags.
#define PTE_P           0x001   // Present
#define PTE_W           0x002   // Writeable
#define PTE_U           0x004   // User
#define PTE_PS          0x080   // Page Size

// Address in page table or page directory entry
#define PTE_ADDR(pte)   ((uint)(pte) & ~0xFFF)
#define PTE_FLAGS(pte)  ((uint)(pte) &  0xFFF)
...
```


`vm.c`
- kalloc()
- kfree()
- mappages()
- walkpgdir()

### random things
- purpose of `defs.h`
- you may need some data structure to store information related to each mapping, which may include things like the mapped addr, len, prot, flags etc. 

### Support file-backed mapping: read or write file
`file.c`
- fileread()
- filewrite()

modify `fork()` and `exit()`
- copy mappings from parent to child across the fork() system call. 
- make sure you remove all mappings in exit().

### Support MAP_GROWSUP: handle page fault

`trap.c`
```c
  case T_PGFLT: //14  
    cprintf("\tPagefault at virtual addr %x\n", rcr2());
```