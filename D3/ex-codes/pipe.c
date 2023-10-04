
#include <stdio.h>
#include <unistd.h>

int main()
{
    int p[2];
	if (pipe(p) < 0)
		return 1;
    // write to pipe
	write(p[1], "hello", 5);
    // read from pipe
    char inbuf[100];
    read(p[0], inbuf, 100);
    // print
    printf("%s\n", inbuf);
	return 0;
}
