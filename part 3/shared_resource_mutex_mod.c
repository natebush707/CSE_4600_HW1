// Nathan Bush
// CSE 4600 Spring 2022
// Homework 1, Part 4_2
//
// shared_resource_mutex_mod.cpp
// Modify share_resource_mutex.cpp so that it implements a mutex lock on the shared resource
// Resulting shared resource should always be 0 after running

#include <stdio.h>
#include <pthread.h>

#define iterations 300000000
long long shared_resource = 0;

pthread_mutex_t mutex;

// Thread function to modify shared resource
void* inc_dec_resource(void* arg){
	//get the pointer from main thread and derefernce it to put the value in resource_value
	int resource_value = *(int *)arg;
	pthread_mutex_lock(&mutex);
	for(int i = 0; i < iterations; i++){
		shared_resource += resource_value;
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(void){

	//Thread 1 to increment shared resource
	pthread_t tid1, tid2;
	int value1 = 1;
	pthread_create(&tid1, NULL, inc_dec_resource, &value1);

	//Thread 2 to decrement shared resource
	int value2 = -1;
	pthread_create(&tid2, NULL, inc_dec_resource, &value2);
	pthread_join(tid2, NULL);
	pthread_join(tid1, NULL);
	printf("Shared resource value: %lld\n", shared_resource);

	return 0;
}