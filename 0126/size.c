#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char b[200] = {}; 

int main(int argc, char **argv)
{
	char a[200] = "hello world!\n"; 
	printf("%s", a); 
	return 0; 
}
