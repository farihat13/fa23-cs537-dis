#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wrong num. arguments\n");
        return 0;
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("error opening file\n");
        return 1;
    }

    char buf[80];
    while (fgets(buf, 80, fp) != NULL) {
        printf("%s", buf);
    }
    fclose(fp);
    return 0;
}