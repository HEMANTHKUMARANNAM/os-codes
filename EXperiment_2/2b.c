#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("PID of example.c = %d\n", getpid());
    
    
    // Execute the 'hello' program using execv
    char *args[] = {"Hello", "C", "Programming", NULL};
    
    execlp("date","date", NULL);
    execv("./hello", args);
    
    // This line will not be executed unless execlp/execv fails
    printf("Back to example.c\n");

    return 0;
}
