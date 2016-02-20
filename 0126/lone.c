#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	if (!fork()) {
		printf("hello world!\n");
		while(1); 
	} else {
		exit(0); 
	}

	return 0; 
}
