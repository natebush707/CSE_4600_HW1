// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 1_4
//
// hw1_part1_4.cpp
// modify test_wait (original provided by Dr. Bilal Khan) so:
//		1. Child process creates another child and waits for it.
//		2. Grandchild prints out the IDs of itself, its parent, and grandparent.


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	pid_t pid, child_pid, grandchild_pid;			//process_id
	const char *message;
	int n;
	int exit_code;
	int pid_array[3];


	cout << "fork program staring \n";
	pid_array[0] = getpid();
	pid = fork();
	switch (pid) {
		case -1:
			cout <<"Fork failure!\n";
			return 1;
		case 0:
			message = "This is the child\n";
			n = 5;
			exit_code = 9;
			pid_array[1] = getpid();
			child_pid = fork();
			switch(child_pid) {		//nested switch to handle second fork
				case -1:
					cout <<"Fork failure!\n";
					return 1;
				case 0:
					pid_array[2] = getpid();
					grandchild_pid = getpid();
					message = "This is the grandchild\n";
					n = 7;
					exit_code = 7;
				default:
					break;
			}
			break;
		default:
			message = "This is the parent\n";
			n = 3;
			exit_code = 0;
			break;
	}

	//console output identifying process
	for (int i = 0; i < n; ++i){
		cout << message;
		sleep(1);
	}

	//waiting for child to finish
	if (pid != 0) {				//parent
		int stat_val;
		pid_t child_pid;

		child_pid = wait (&stat_val);	//wait for child
		cout << "\nChild finished: PID = " << child_pid << endl;
		if (WIFEXITED(stat_val))
			cout << "child exited with code " << WEXITSTATUS (stat_val) << endl;
		else
			cout << "child terminated abnormally!" << endl;
	}

	//waiting for grandchild to finish
	else if (child_pid != 0) {	//child
		int stat_val2;
		pid_t grandchild_pid;

		grandchild_pid = wait (&stat_val2); 	//wait for grandchild
		cout <<"\nGrandchild finished: PID = " << grandchild_pid << endl;
		if (WIFEXITED(stat_val2))
			cout << "grandchild exited with code " << WEXITSTATUS (stat_val2) << endl;
		else
			cout << "grandchild terminated abnormally!" << endl;
	}

	//grandchild, report PIDs
	else if (child_pid == 0) {
		cout << "\nGrandchild nearly finished, reporting PIDs:\n"
		     << "My(grandchild) PID = " << pid_array[2] << endl
		     << "My parent's PID = " << pid_array[1] << endl
		     << "My grandparent's PID = " << pid_array[0] << endl
		     << "... all done, grandchild finishing up now.\n";
	}

	exit (exit_code);
}