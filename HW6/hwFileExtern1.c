//HomeWork #6
//Baturina Yelena
//Using Externs

#include <stdio.h>
#include <stdlib.h>

typedef int I;
I x;


void func1(void)
{
      
	x = x+2;
	printf("Значение х func1 = %d \n",x);
}


int main(void)
{

	x = 1;
	printf("Значение х main = %d \n",x);

	func1();

	func2();
	printf("Значение х снова в main = %d \n",x);

	return 0;
}

