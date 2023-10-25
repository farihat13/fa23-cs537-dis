// https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-waitpid-wait-specific-child-process-endßß


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h> 
#include <sys/wait.h>
#include<signal.h>
#include <wait.h>


// Handler for SIGCHLD, caused by child process terminated
void my_handler_sigchld(int sig)
{
	printf("\nCaught signal sigchld %d\n", sig);
    exit(0);
}
// Handler for SIGINT, caused by Ctrl-C at keyboard
void my_handler_sigint(int sig)
{
	printf("\nCaught signal sigint %d\n", sig);
    exit(0);
}

int main()
{
    signal(SIGCHLD, my_handler_sigchld); // child process terminated
    signal(SIGINT, SIG_IGN); // Ctrl-C
    pid_t pid = fork();
    if (pid == 0) {
        char *const argv[3] = {"/bin/sleep", "5", NULL};  
        int ret = execv(argv[0], argv);
        printf("Fails to execute %s\n", argv[0]);
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        printf("I'm the Parent\n");
    }
    return 0;
}