#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        printf("CHILD process\n");
        printf("Child PID = %d\n", getpid());
    }
    else
    {
        printf("PARENT process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID (from fork) = %d\n", pid);
    }

    return 0;
}
