#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MESSAGE_SIZE 256

struct message {
    long type;
    char text[MESSAGE_SIZE];
};

int main()
{
    key_t key;
    int msqid;
    struct message msg;

    // Generate a unique key
    if ((key = ftok("message_queue_key", 'A')) == -1) {
        perror("Error generating key");
        exit(EXIT_FAILURE);
    }

    // Create a message queue
    if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        // Prepare the message
        msg.type = 1;
        strcpy(msg.text, "Hello, child process!");

        // Send the message to the queue
        if (msgsnd(msqid, &msg, sizeof(struct message) - sizeof(long), 0) == -1) {
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }
    } else {
        // Child process
        // Receive the message from the queue
        if (msgrcv(msqid, &msg, sizeof(struct message) - sizeof(long), 1, 0) == -1) {
            perror("Error receiving message");
            exit(EXIT_FAILURE);
        }

        printf("Child received: %s\n", msg.text);
    }

    // Remove the message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("Error removing message queue");
        exit(EXIT_FAILURE);
    }

    return 0;
}
