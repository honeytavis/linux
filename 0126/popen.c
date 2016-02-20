#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp = popen("ls -l", "r"); 
	if (!fp) {
		perror("popen"); 
		exit(-1); 
	}

	char buf[512]; 
	memset(buf, 0, sizeof(buf)); 
	int ret = fread(buf, sizeof(char), 512, fp); 
	if (ret > 0) {
		printf("%s\n", buf); 
	}

	pclose(fp); 
	return 0; 
}
