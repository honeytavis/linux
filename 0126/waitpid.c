#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork(); 
	if (!pid) {
		printf("I am child!\n"); 
		exit(0); 
	} else {
		int status; 
		if (waitpid(pid, &status, 0) < 0) {
			perror("waitpid"); 
			exit(-1); 
		}
		if (WIFEXITED(status))
			printf("WEXITSTATUS is %d\n", WEXITSTATUS(status)); 
		}
	return 0; 
}
