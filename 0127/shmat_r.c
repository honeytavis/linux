#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PROJ_ID 1
#define SHM_SIZE 4096

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
	int shmid = shmget(skey, SHM_SIZE, IPC_CREAT | 0600); 
	if (shmid < 0) {
		perror("shmget"); 
		exit(-1); 
	}
	printf("shmid: %d\n", shmid); 
	char *shmptr = shmat(shmid, 0, 0); 
	if (shmptr == (void *)-1) {
		perror("shmat") ;
		exit(-1); 
	}
	printf("share memory attach form %p to %p\n", (void *)shmptr, (void *)shmptr+SHM_SIZE); 

	//while(1); 
	printf("%c\n", *shmptr); 
	return 0; 
}

