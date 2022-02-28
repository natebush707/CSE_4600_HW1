// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 3_1
//
// pthreads_mod.cpp
// modify pthreads_demo.cpp (original provided by Dr. Bilal Khan) so:
//    1. 3 threads are run instead of 2
//    2. Each thread runs its own function, displaying a different message

#include <pthread.h>
#include <stdio.h>

using namespace std;

// first thread function
void * thread_func1 (void *data)
{
	char *tname = (char *) data;

	printf("First thread, reporting in: my thread identifier is %s.\n", tname);

	pthread_exit (0);
}

// second thread function
void * thread_func2 (void *data)
{
	char *tname = (char *) data;

	printf("Second thread, reporting in: my thread identifier is %s.\n", tname);

	pthread_exit (0);
}

// third thread function
void * thread_func3 (void *data)
{
	char *tname = (char *) data;

	printf("Third thread, reporting in: my thread identifier is %s.\n", tname);

	pthread_exit (0);
}

int main ()
{
	pthread_t id1, id2, id3;				//thread identifiers
	pthread_attr_t attr1, attr2, attr3;	//set of thread attributes
	char tnames[3][10] = { "Thread 1", "Thread 2", "Thread 3" };	//names of threads
	//get the default attributes
	pthread_attr_init (&attr1);
	pthread_attr_init (&attr2);
	pthread_attr_init (&attr3);

	//create the threads
	pthread_create (&id1, &attr1, thread_func1, tnames[0]);
	pthread_create (&id2, &attr2, thread_func2, tnames[1]);
	pthread_create (&id3, &attr3, thread_func3, tnames[2]);

	//wait for the threads to exit
	pthread_join (id1, NULL);
	pthread_join (id2, NULL);
	pthread_join (id3, NULL);

	return 0;
}