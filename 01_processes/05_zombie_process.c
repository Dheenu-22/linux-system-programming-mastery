#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID : %d\n", getpid());

        printf("Child exiting...\n");
        exit(0);
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID : %d\n", getpid());

        printf("Parent sleeping for 20 seconds...\n");
        sleep(20);

        printf("Parent finished.\n");
    }

    return 0;
}
