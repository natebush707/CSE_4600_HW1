// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 1_1
//
//
// hw1_part1_1.cpp
// Creates a chain of 10 processes and prints out their process ids and relationships.
// Each child must print out all of her ancestors identified by the process IDs

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;


// helper function to print the contents of an array of PIDs
void print_array(int (&pids)[10])
{
	for (int i = 0; i < 10; i++) {
		if (pids[i] != 0) {
			printf("%d ", pids[i]);
		}
	}
	printf("\n\n");
	return;
}	


int main()
{
	// initialize array to store pids
	int pids[10] = {0};
	
	// store and report PID from original main process
	pids[0] = getpid();
	printf("Original process: %d\n...no parent\n...no ancestors\n\n", pids[0]);
	
	for (int i = 0; i < 9; i++) {
		int current_pid = fork();
		
		// child process, store and report PID and ancestry
		if (current_pid == 0) {
			printf("Child process: %d\n...parent: %d\n...ancestors: ", getpid(), pids[i]);
			print_array(pids);
			pids[i+1] = getpid();
		}
		
		// parent process, wait for child to finish before terminating
		else {
			wait(NULL);
			exit(0);
		}
	}
	return 0;
}