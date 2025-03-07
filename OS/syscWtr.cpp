#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

#define N 1024

int main()
{
    int fd;
    char data[N];
    ssize_t bw;

    // Open the file in write-only mode, create it if it doesn't exist
    fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd== -1) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }
    
    // Write data to the file
    do
    {
        fgets(data,N,stdin);
        bw = write(fd, data, strlen(data)); 
    }while (data[strlen(data)-2]!='\t');

    if(bw==-1)
    {    
        perror("Error writing to the file");
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    printf("Data written to the file.\n");

    return 0;
}
