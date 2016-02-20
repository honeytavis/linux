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
	struct shmid_ds buf; 
	int ret = shmctl(shmid, IPC_STAT, &buf); 
	if (ret < 0) {
		perror("shmctl"); 
		exit(-1); 
	}
	printf("euid: %d, cuid: %d, mode: %#o\n", buf.shm_perm.uid, buf.shm_perm.cuid, buf.shm_perm.mode); 
	// find /usr/include/ -name "*.h" | xargs grep shmatt_t
	printf("size: %d, cpid: %d, nattch: %lu\n", buf.shm_segsz, buf.shm_cpid, buf.shm_nattch); 

	return 0; 
}

