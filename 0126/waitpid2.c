#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid; 
	pid = fork(); 
	if (pid == 0) {
		printf("I am child!\n"); 
		while(1); 
	} else {
		int status; 
		int ret = waitpid(pid, &status, WNOHANG); 
		printf("ret is %d\n", ret); 
		if (ret < 0) {
			perror("waitpid"); 
			exit(-1); 
		}
		if (WIFEXITED(status))
			printf("WEXITSTATUS is %d\n", WEXITSTATUS(status)); 
		}
	return 0; 
}
