/*
===========================================================
Program : 07_fork_exec.c
Topic   : fork() + exec() + wait()
Author  : Dheenu
Purpose : Demonstrate how a parent process creates a child,
          the child executes another program using exec(),
          and the parent waits for the child to finish.
===========================================================
*/

#include <stdio.h>      // printf()
#include <unistd.h>     // fork(), execl()
#include <sys/wait.h>   // wait()
#include <stdlib.h>     // exit()

int main()
{
    int pid;

    // Create a child process
    pid = fork();

    // Check whether fork() failed
    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    // Child Process
    else if (pid == 0)
    {
        printf("\n===== CHILD PROCESS =====\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n\n", getppid());

        printf("Child is executing 'ls' using exec()...\n\n");

        // Replace the child process with the ls program
        execl("/bin/ls", "ls", NULL);

        // This executes ONLY if exec() fails
        printf("exec() failed!\n");
        exit(1);
    }

    // Parent Process
    else
    {
        printf("\n===== PARENT PROCESS =====\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n\n", pid);

        printf("Parent is waiting for child to finish...\n\n");

        // Wait for child process
        wait(NULL);

        printf("\nChild has completed execution.\n");
        printf("Parent continues its execution.\n");
    }

    return 0;
}
