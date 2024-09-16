#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>  // For close()

int main() {
    // Open the file for reading and create it if it does not exist
    // Use O_WRONLY or O_RDWR if you want to create the file
    int fd = open("foo.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);

    // Check if open() was successful
    if (fd == -1) {
        // Print error number and error message
        printf("Error Number: %d\n", errno);
        perror("Program");
        return 1; // Exit with failure status
    }

    // Print file descriptor
    printf("fd = %d\n", fd);

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("close");
        return 1; // Exit with failure status
    }

    return 0; // Exit with success status
}
