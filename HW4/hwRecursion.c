// Home Work #4
//Barurina Yelena
// Recurcion inllustration

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>


int Sum (int num, int count)
{
int n;
float d;


if(count<0) return 0;

d =pow (10,count); // делитель для осуществления целочисленного деления и деления с остатком даты рождения  
n = num % ((int) d); // остаток от  целоч деления даты 
	printf("numIn = %d, d = %d\n", num, (int) d); // вывод основных величин для контроля работы функции
num = num / ((int)d);  // целочисл деление , данная величина является цифрой для сложения
 printf(" count = %d , n = %d, num = %d \n", count, n, num);
return num + Sum (n, count-1);
};


int main (void)
 {
	int year, month, day, number;
	int res=0;
	setlocale(LC_ALL, "ru_RU.utf8");
	printf ("Введите ваш год рождения: \n");
	scanf ("%d",&year);
	printf ("Введите месяц вашего рождения: \n");
        scanf ("%d",&month);
        printf ("Введите день вашего : \n");
        scanf ("%d",&day);
	number = (((year*100)+month)*100)+day;
	printf ("number = %d \n",number);
	res = Sum (number, 7); // цифра 7 это число 10000000, с которого начинается деление числа ггггммдд
	printf ("Сумма чисел вашей даты рождения = %d \n", res);

return 0;

}
