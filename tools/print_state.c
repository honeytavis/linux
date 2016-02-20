#include <stdio.h>

#define SECOND 3000

void Print_Symbol(char c) 
{
	int i; 
	for (i = 0; i < SECOND; i++) {
		putchar(c); 
		printf("\b"); 
	}
}

void Print_State(void)
{
	for (;;) {
		Print_Symbol('-'); 
		Print_Symbol('\\'); 
		Print_Symbol('|'); 
		Print_Symbol('/'); 
	}
}
