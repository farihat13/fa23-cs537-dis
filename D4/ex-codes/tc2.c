/* CELEBT10

   This example changes the PGID.

 */
#define _POSIX_SOURCE
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("original foreground process group id of stdout was %d\n", tcgetpgrp(STDOUT_FILENO));

        printf("now setting to %d\n", (int)getpid());
        setpgid(getpid(), 0);
        if (tcsetpgrp(STDOUT_FILENO, getpid()) != 0)
            perror("tcsetpgrp() error");
        else
            printf("new foreground process group id of stdout is %d\n",
                   (int)pid);
        printf("sleeping for 5 seconds\n");
        sleep(10);
    }
    else {
        sleep(5);
        printf("parent exiting\n");
        int status=-1;
        wait(&status);
    }
}