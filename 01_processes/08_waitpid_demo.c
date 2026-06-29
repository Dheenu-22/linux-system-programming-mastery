/*
===========================================================
Program : 08_waitpid_demo.c
Topic   : waitpid() System Call
Author  : Dheenu
Purpose : Demonstrate how waitpid() waits for a specific
          child process and retrieves its exit status.
===========================================================
*/

#include <stdio.h>      // printf()
#include <unistd.h>     // fork(), sleep(), getpid()
#include <sys/wait.h>   // waitpid(), WEXITSTATUS()
#include <stdlib.h>     // exit()

int main()
{
    int pid;            // Stores the child PID
    int status;         // Stores child's exit status

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
        printf("Child PID : %d\n", getpid());

        printf("Child is working for 5 seconds...\n");

        // Simulate some work
        sleep(5);

        printf("Child completed its work.\n");

        // Exit with status code 25
        exit(25);
    }

    // Parent Process
    else
    {
        printf("\n===== PARENT PROCESS =====\n");
        printf("Parent PID : %d\n", getpid());
        printf("Waiting for Child PID : %d\n", pid);

        // Wait only for this specific child
        waitpid(pid, &status, 0);

        printf("\nChild process has terminated.\n");

        // Check whether child exited normally
        if (WIFEXITED(status))
        {
            printf("Exit Status : %d\n", WEXITSTATUS(status));
        }

        printf("Parent continues execution.\n");
    }

    return 0;
}
