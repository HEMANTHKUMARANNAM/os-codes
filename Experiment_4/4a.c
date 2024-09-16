#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

int main() {
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }

    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    // shmat to attach to shared memory
    char *str = (char *) shmat(shmid, (void *)0, 0);
    if (str == (char *) -1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    printf("Write Data: ");
    if (fgets(str, 1024, stdin) == NULL) {
        perror("fgets failed");
        shmdt(str);
        exit(EXIT_FAILURE);
    }

    // Remove the newline character if fgets reads it
    str[strcspn(str, "\n")] = '\0';

    printf("Data written in memory: %s\n", str);

    // Detach from shared memory
    if (shmdt(str) == -1) {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
