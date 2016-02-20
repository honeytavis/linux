#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PROJ_ID 1

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("error args!\n"); 
		exit(0); 
	}

	key_t skey = ftok(argv[1], PROJ_ID); 
	if (skey < 0) {
		perror("ftok"); 
		exit(-1); 
	}
	printf("skey: %#x\n", skey); 
	//ipcs
	//ipcrm -m shmid
	int shmid = shmget(skey, 1 << 12, IPC_CREAT | 0600); 
	if (shmid < 0) {
		perror("shmget"); 
		exit(-1); 
	}
	printf("shmid: %d\n", shmid); 

	return 0; 
}

