#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{

	//int shmid = shmget(IPC_PRIVATE, 1 << 12, IPC_CREAT | 0600); 
	int shmid = shmget((key_t)1234, 1 << 12, IPC_CREAT | 0600); 
	if (shmid < 0) {
		perror("shmget"); 
		exit(-1); 
	}
	printf("shmid: %d\n", shmid); 

	return 0; 
}

