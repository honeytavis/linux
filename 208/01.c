#include <stdio.h>

int main(void)
{
	int i; 
	char a = 'a'; 

	//行缓冲区在遇到 \n 或超出 1024 byte时自动刷新
	
	//for (i = 0; i < 1025; i++) {
	for (i = 0; i < 1024; i++) {
		printf("%c", a); 
	}
	
	//printf("\n"); 
	while(1); 

	return 0; 
}
