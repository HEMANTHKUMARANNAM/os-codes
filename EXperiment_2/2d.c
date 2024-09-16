#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p;

    printf("before fork\n");

    // Create a new process
    p = fork();

    if (p < 0) {
        // Fork failed
        perror("fork");
        return 1;
    }

    if (p == 0) {
        // This is the child process
        printf("I am the child with PID %d\n", getpid());
        printf("My parent's PID is %d\n", getppid());
    } else {
        // This is the parent process
        // Wait for the child process to finish
        wait(NULL);
        printf("My child's PID is %d\n", p);
        printf("I am the parent with PID %d\n", getpid());
    }

    // This is executed by both parent and child
    printf("Common\n");

    return 0;
}
