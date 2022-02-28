// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 2_4
//
// pipe4a.cpp
// Modify pipe4.cpp so that it accepts a message from the keyboard and sends it to pipe5.cpp
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

int main()
{
    int data_processed;
    int file_pipes[2];
    char some_data[64];
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    std::cout << "Please enter a message to be piped to the consumer (max 64 chars): ";
    std::cin.getline(some_data, 64);

    memset(buffer, '\0', sizeof(buffer));

    if (pipe(file_pipes) == 0) {   //creates pipe
        fork_result = fork();
        if (fork_result == (pid_t)-1) {  //fork fails
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }

        if (fork_result == 0) {    //child
            sprintf(buffer, "%d", file_pipes[0]);
            (void)execl("pipe5", "pipe5", buffer, (char *)0);
            exit(EXIT_FAILURE);
        }
        else {                     //parent
            data_processed = write(file_pipes[1], some_data,
                                   strlen(some_data));
            printf("%d - wrote %d bytes\n", getpid(), data_processed);
        }
    }
    sleep(1);
    exit(EXIT_SUCCESS);
}