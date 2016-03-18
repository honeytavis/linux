#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>

void printids(const char* s)
{
	pid_t pid; 
	pthread_t tid; 

	pid = getpid(); 
	tid = pthread_self(); 
	printf("%s pid = %lu tid = %lu (0x%lx)\n", s, (unsigned long)pid,
	  (unsigned long)tid, (unsigned long)tid); 
}

void* thr_fn(void* arg)
{
	printids("new thread:"); 
	return ((void*)0); // <=> return (NULL); 
}
	

int main()
{
	pthread_t ntid; 
	int err = pthread_create(&ntid, NULL, thr_fn, NULL); 
	if (err != 0) {
		perror("pthread_create(): "); 
		exit(0); 
	}

	printids("main thread:"); 
	sleep(1); 

	return 0; 
}
