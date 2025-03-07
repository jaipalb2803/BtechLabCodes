#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main()
{
    int fd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        close(fd[0]); // Close the read end of the pipe

        // Write data to the pipe
        char message[] = "Hello, child process!";
        write(fd[1], message, sizeof(message));
        close(fd[1]); // Close the write end of the pipe
    } else {
        // Child process
        close(fd[1]); // Close the write end of the pipe

        // Read data from the pipe
        ssize_t num_bytes = read(fd[0], buffer, BUFFER_SIZE);
        printf("Child received: %.*s\n", (int)num_bytes, buffer);
        close(fd[0]); // Close the read end of the pipe
    }

    return 0;
}
