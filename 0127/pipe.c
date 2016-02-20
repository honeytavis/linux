#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <string.h>

#include <unistd.h>

#define BUFSIZE 20
int main()
{
	int 	fd[2]; 
	pid_t	pid; 
	char	buf[BUFSIZE] = {0}; 
	
	if (pipe(fd) < 0) {
		perror("pipe"); 
		exit(-1); 
	}
	if ((pid = fork()) < 0) {
		perror("fork"); 
		exit(-1); 
	} else if (pid > 0) {
		close(fd[0]); 
		write(fd[1], "hello world!", sizeof("hello world!")); 
	} else {
		close(fd[1]); 
		read(fd[0], buf, BUFSIZE); 
		write(STDIN_FILENO, buf, strlen(buf)); 
	}

	return 0; 
}
