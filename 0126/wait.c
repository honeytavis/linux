#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	if (!fork()) {
		printf("I am child!\n"); 
		exit(0); 
	} else {
		int status; 
		if (wait(&status) < 0) {
			perror("wait"); 
			exit(-1); 
		}
		if (WIFEXITED(status))
			printf("WEXITSTATUS is %d\n", WEXITSTATUS(status)); 
		}
	return 0; 
}
