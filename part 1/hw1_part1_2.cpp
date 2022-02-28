// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 1_2
//
//
// hw1_part1_2.cpp
// modify test_exec (original provided by Dr. Bilal Khan)
// so that the function execl is used instead of using execlp

#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	cout << "Running ps with execl\n";
	execl ("/bin/ps", "ps", "-ax", NULL);
	
	cout << "The program is exiting!\n";
}