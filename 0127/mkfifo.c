#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		printf("error args!\n"); 
		exit(0); 
	}

	int ret = mkfifo(argv[1], 0666); 
	if (ret < 0) {
		perror("mkfifo"); 
		exit(-1); 
	}

	ret  = unlink(argv[1]); 
	if (ret < 0) {
		perror("unlink"); 
		exit(-1); 
	}

	return 0; 
}
