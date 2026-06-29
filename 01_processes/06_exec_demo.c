/*
===========================================================
Program : 06_exec_demo.c
Topic   : exec() System Call
Author  : Dheenu
Purpose : Demonstrate how exec() replaces a process.
===========================================================
*/

#include <stdio.h>     // For printf()
#include <unistd.h>    // For execl()

// Main function
int main()
{
    // This line is executed first.
    printf("Before exec()\n");

    // Replace the current process with the 'ls' program.
    // If execl() succeeds, the lines below will NEVER execute.
    execl("/bin/ls", "ls", NULL);

    // This line executes ONLY if execl() fails.
    printf("After exec()\n");

    return 0;
}
