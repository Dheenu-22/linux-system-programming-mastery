#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    fork();

    wait(NULL);

    printf("Process PID = %d\n", getpid());

    return 0;
}
