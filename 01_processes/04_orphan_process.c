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
        sleep(5);

        printf("\nCHILD PROCESS\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
    }
    else
    {
        printf("PARENT PROCESS\n");
        printf("Parent PID : %d\n", getpid());

        printf("Parent exiting...\n");
        exit(0);
    }

    return 0;
}
