#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	if (!fork()) {
		exit(0); 
	} else {
		while(1); 
	}

	return 0; 
}
