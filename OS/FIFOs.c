#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256

int main()
{
    const char *fifo_file = "myfifo";
    int fd;
    char buffer[BUFFER_SIZE];

    // Create the FIFO file
    if (mkfifo(fifo_file, 0666) == -1) {
        perror("Error creating FIFO file");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        fd = open(fifo_file, O_WRONLY);
        if (fd == -1) {
            perror("Error opening FIFO file for writing");
            exit(EXIT_FAILURE);
        }

        // Write data to the FIFO
        char message[] = "Hello, child process!";
        write(fd, message, sizeof(message));
        close(fd);
    } else {
        // Child process
        fd = open(fifo_file, O_RDONLY);
        if (fd == -1) {
            perror("Error opening FIFO file for reading");
            exit(EXIT_FAILURE);
        }

        // Read data from the FIFO
        ssize_t num_bytes = read(fd, buffer, BUFFER_SIZE);
        printf("Child received: %.*s\n", (int)num_bytes, buffer);
        close(fd);
    }

    // Remove the FIFO file
    unlink(fifo_file);

    return 0;
}
