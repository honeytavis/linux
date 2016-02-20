#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>

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
	printf("skey: %ld\n", skey); 

	return 0; 
}
