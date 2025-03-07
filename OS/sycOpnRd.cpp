#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t br;

    // Open the file in read-only mode
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    // Read from the file and display its contents
    while ((br = read(fd, buffer, BUFFER_SIZE)) > 0) {
       //
        //write(STDOUT_FILENO, buffer, br);
       printf("%s",buffer);
    }

    // Close the file
    close(fd);

    return 0;
}
