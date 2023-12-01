# Discussion Notes (Project 07)

## Superblocks

It sets the `magic` field to `WFS_MAGIC`, a constant that presumably identifies the file system as "wfs", and the `head` field to the size of the superblock.

Next, it creates an inode for the root directory of the file system. An inode is a data structure that represents a file (or in this case, a directory). The inode is set up with various fields, such as the inode number, the user and group IDs, the access times, and the number of links.

A log entry is then created for the root directory, and this log entry is copied into the memory map of the disk file. The `head` field of the superblock is then updated to point to the end of the log entry.

Finally, the program prints some information about the newly created file system, unmaps the memory map, and closes the disk file.

`xxd -e -g 4 disk | less`
The command you provided uses the xxd tool to generate a human-readable hex dump of the contents of the file named "disk" and then pipes the output to the less command for easier navigation.

`strace -o output.txt stat /file/path`


1. write `get_inode`

2. for directories, logentry data contains list of dentries
for 




printing the disk

// 1. after `making filesystem and superblock`
// `log entry 0: inode 0 (root): [root inode, no data, size 0]`
        start: 8 8
        inode: 0
get_data: 0 0
get_dentries: 0 0


// 2. after calling `mkdir mnt/a`
// `log entry 1: inode 0 (root): [root inode, with one dentry for /a, size 40 ]`
        start: 52 34
        inode: 0
get_data: 0 40
get_dentries: 0 40
        dentry: a
                a

// `log entry 2: inode 1 (/a): [inode for "\a", size 0 for now]`
        start: 136 88
        inode: 1
get_data: 1 0
get_dentries: 1 0


// 3. after calling `mkdir mnt/b`
// `log entry 3: inode 0 (root): [root inode]`
        start: 180 b4
        inode: 0
get_data: 0 80
get_dentries: 0 80
        dentry: a
                a
                b

// `log entry 4: inode 2 (/b): []`
        start: 304 130
        inode: 2
get_data: 2 0
get_dentries: 2 0


// 3. after calling `mkdir mnt/c`
// `log entry 5: inode 0 (root): []`
        start: 348 15c
        inode: 0
get_data: 0 120
get_dentries: 0 120
        dentry: a
                a
                b
                c

// `log entry 6: inode 3 (/b): []`
        start: 512 200
        inode: 3
get_data: 3 0
get_dentries: 3 0

// 4. after calling `touch file.txt`
// `log entry 7: inode 0 (root): []`
        start: 556 22c
        inode: 0
get_data: 0 160
get_dentries: 0 160
        dentry: a
                a
                b
                c
                file.txt

// `log entry 8: inode 1 (/b): []`
        start: 760 2f8
        inode: 1
get_data: 1 0
get_dentries: 1 0

        start: 804 324
        inode: 0
get_data: 0 200
get_dentries: 0 200
        dentry: a
                a
                b
                c
                file.txt
                x

        start: 1048 418
        inode: 1
get_data: 1 0
get_dentries: 1 0

        start: 1092 444
        inode: 1
get_data: 1 5
        data: asdf

get_dentries: 1 5
printing the disk done

















## log entries


// 1. after calling `mkfs`
printing the disk

        start: 8 8
        inode: 0
get_data: 0 0
get_dentries: 0 0

        start: 52 34
        inode: 0
get_data: 0 40
get_dentries: 0 40
        dentry: a
                a

        start: 136 88
        inode: 1
get_data: 1 0
get_dentries: 1 0

        start: 180 b4
        inode: 0
get_data: 0 80
get_dentries: 0 80
        dentry: a
                a
                b

        start: 304 130
        inode: 2
get_data: 2 0
get_dentries: 2 0

        start: 348 15c
        inode: 0
get_data: 0 120
get_dentries: 0 120
        dentry: a
                a
                b
                file1.txt

        start: 512 200
        inode: 3
get_data: 3 0
get_dentries: 3 0

        start: 556 22c
        inode: 3
get_data: 3 1
        data: 

get_dentries: 3 1

        start: 601 259
        inode: 0
get_data: 0 160
get_dentries: 0 160
        dentry: a
                a
                b
                file1.txt
                file2.txt

        start: 805 325
        inode: 4
get_data: 4 0
get_dentries: 4 0

        start: 849 351
        inode: 4
get_data: 4 6
        data: hello

get_dentries: 4 6
printing the disk done