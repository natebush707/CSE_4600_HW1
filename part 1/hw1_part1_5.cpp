// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 1_5
//
// hw1_part1_5.cpp
// modify signal (original provided by Dr. Bilal Khan):
//    1. use sigaction() to intercept SIGINT
//    2. replace the "for" loop with while(1)
//    3. be able to quit the program by entering "^\". (Need to intercept SIGQUIT.)

#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void func (int sig)
{
  cout << "Oops! -- I got a signal: " << sig << endl;
}

void quit (int sig)
{
  cout << "Received signal: " << sig << "...exiting program." << endl;
  exit(1);
}

int main()
{
  struct sigaction handle_signal, handle_quit;
  
  handle_signal.sa_handler = func;
  handle_quit.sa_handler = quit;

  sigemptyset(&handle_signal.sa_mask);
  sigemptyset(&handle_quit.sa_mask);

  sigaction(SIGQUIT, &handle_quit, NULL);
  sigaction(SIGINT, &handle_signal, NULL);

  while(1) {
    cout << "CSUSB CSE 4600 Operating Systems. Homework on signals" << endl;
    sleep (1); 
  }
  return 0;
}