
#include <stdio.h>

extern int x;

void func2(void)
	{
	x = x+5;
	printf("Значение х func2 = %d \n",x);
	}

