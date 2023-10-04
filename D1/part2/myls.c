// myls.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    char *d = "./";
    
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(d)) == NULL) {
        printf("error opening dir\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\t", entry->d_name);
        
        struct stat st;
        if (stat(entry->d_name, &st) < 0) {
            printf("error stating file\n");
            return 1;
        }

        if (S_ISREG(st.st_mode)) {
            printf("reg\t%ld\n", st.st_size);
        } else {
            printf("\n");
        }
    }
    return 0;
}