#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
	int i; 
	for (i = 0; i < 2; i++) {
		if (!fork()) {
			printf("* ppid = %d, pid = %d, i = %d * ", getppid(), getpid(), i); 
		} else {
			printf("# ppid = %d, pid = %d, i = %d # ", getppid(), getpid(), i); 
			sleep(5); 
		}
	}

	return 0; 
}
