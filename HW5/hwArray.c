//Home Work # 5
//Baturina Yelena
// Array of 1000 char realization

#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int main (void){

char symbol [1000];

char *pch = symbol;

srand(time(NULL));

printf("\n Выводим массив из 1000 символов, заданных случайным образом: \n");

for (int i=0; i<1000; i++)
	{
	symbol[i]=(char)((0+rand()%26)+65);
	printf ("%c , ",symbol[i]);
	}
printf("\n  Конец !\n");

printf("\n А теперь то же массив выводим с помощью указателя: \n");

for (int i=0; i<1000; i++)
        {
        pch=&symbol[i]; // получаем адрес i-го элемента массива
        printf ("%c , ",*pch); // выводим в консоль значение , находящееся по адресу, хранящееся в pch
        }
printf("\n  Конец !\n");


return 0;
}
