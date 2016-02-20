#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp = popen("./scanf", "w"); 
	if (!fp) {
		perror("popen"); 
		exit(-1); 
	}

	char buf[] = "hello world!"; 
	int ret = fwrite(buf, 1, strlen(buf), fp); 
	if (ret < 0) {
		perror("fwrite"); 
		exit(-1); 
	}

	pclose(fp); 
	return 0; 
}
