#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[50];
    off_t offset;
    ssize_t br, bw;

    // Open the file in read-write mode
    fd = open("file.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    // Move the file offset to a specific position (e.g., byte 10)
    offset = lseek(fd, 10, SEEK_SET);
    if (offset == -1) {
        perror("Error seeking to the position");
        exit(EXIT_FAILURE);
    }

    // Read from the file at the new position
    br= read(fd, buffer, sizeof(buffer));
    if (br == -1) {
        perror("Error reading from the file");
        exit(EXIT_FAILURE);
    }

    // Display the read data
    write(STDOUT_FILENO, buffer, br);

    // Move the file offset to the end of the file
    offset = lseek(fd, 0, SEEK_END);
    if (offset == -1) {
        perror("Error seeking to the end of the file");
        exit(EXIT_FAILURE);
    }

    // Write data to the end of the file
    bw = write(fd, "Appended data", 13);
    if (bw == -1) {
        perror("Error writing to the file");
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    return 0;
}
