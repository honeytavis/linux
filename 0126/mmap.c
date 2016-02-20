#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/mman.h>

#include <string.h>

typedef struct stu {
	char ID[10]; 
	char Name[10]; 
	int Mark; 
}stu_t; 

int main(int argc, char ** argv)
{
	int fd = open("hello", O_RDWR); 
	if (fd < 0) {
		perror("open"); 
		exit(-1); 
	}

	void *p = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
	if (p == MAP_FAILED) {
		perror("mmap"); 
		exit(-1); 
	}
	close(fd); 
	
	stu_t new = {"1234", "tengwei", 99}; 
	memcpy(p, &new, sizeof(stu_t)); 

//	int munmap_ret = munmap(p, 100); 
//	if (munmap_ret < 0) {
//		perror("munmap"); 
//		exit(-1); 
//	}

	return 0; 
}
