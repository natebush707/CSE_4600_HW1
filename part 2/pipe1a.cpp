// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 2_2
//
// pipe1a.cpp
// modify pipe1.cpp (original provided by Dr. Bilal Khan) so that it accepts a command:
//    1. (e.g. "ls -l") from the keyboard. For example, when you execute "./pipe1a ps -auxw"
//       it should give you the same output as pipe1.cpp.
//    2. Your main function should be like: int main(int argc, char *argv[])

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  char command[50];

  for (int i = 1; i < argc; ++i) {
    strcat(command, argv[i]);
    strcat(command, " ");
  }

  FILE *fpi;				//for reading a pipe
 
  char buffer[BUFSIZ+1];		//BUFSIZ defined in <stdio.h>
  
  int chars_read;
  memset (buffer, 0,sizeof(buffer));	//clear buffer
  fpi = popen (command, "r");	//pipe to command "ps -auxw"
  if (fpi != NULL) {
    //read data from pipe into buffer
    chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi);  
    if (chars_read > 0) 
     cout << "Output from pipe: " << buffer << endl;
    pclose (fpi); 			//close the pipe
    return 0; 
  }

  return 1;
}