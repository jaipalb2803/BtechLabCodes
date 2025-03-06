#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHARED_MEMORY_SIZE 1024

int main()
{
    key_t key;
    int shmid;
    char *shared_memory;

    // Generate a unique key
    if ((key = ftok("shared_memory_key", 'A')) == -1) {
        perror("Error generating key");
        exit(EXIT_FAILURE);
    }

    // Create a shared memory segment
    if ((shmid = shmget(key, SHARED_MEMORY_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("Error creating shared memory segment");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("Error attaching to shared memory segment");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        // Write data to the shared memory
        strcpy(shared_memory, "Hello, child process!");

        // Wait for the child to read the data
        sleep(1);

        // Detach from the shared memory segment
        if (shmdt(shared_memory) == -1) {
            perror("Error detaching from shared memory segment");
            exit(EXIT_FAILURE);
        }

        // Remove the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("Error removing shared memory segment");
            exit(EXIT_FAILURE);
        }
    } else {
        // Child process
        // Read data from the shared memory
        printf("Child received: %s\n", shared_memory);

        // Detach from the shared memory segment
        if (shmdt(shared_memory) == -1) {
            perror("Error detaching from shared memory segment");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
