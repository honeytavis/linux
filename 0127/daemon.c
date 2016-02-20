#include <sys/types.h>
#include <sys/stat.h>

#include <sys/time.h>
#include <sys/resource.h>

#include <stdlib.h>
#include <errno.h>

#include <unistd.h>

int main()
{
	umask(0); 

	struct rlimit rl; 
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
		perror("getrlimit"); 
		exit(-1); 
	}

	pid_t pid = fork(); 
	if (pid < 0) {
		perror("fork"); 
		exit(-1); 
	} else if (pid != 0)
		exit(0); 
	
	setsid(); 

	chdir("/");
	if (chdir("/") < 0) {
		perror("chdir"); 
		exit(-1); 
	}
	
	if (rl.rlim_max == RLIM_INFINITY) {
		rl.rlim_max = 1024; 
	}
	int i; 
	for (i = 0; i < rl.rlim_max; i++) {
		close(i); 
	}

	while(1); 

	return 0; 
}
