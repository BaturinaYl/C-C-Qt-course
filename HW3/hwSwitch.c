//Home Work #3
//Baturina Yelena
//Switch-case example
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main () {

	int num;
	setlocale (LC_ALL, "ru_Ru.utf8");
	printf ("Введите число от 0 до 10:\n");
        scanf ("%d",&num);
	switch (num)
	{
	case 1: printf ("O\n"); break;
	case 2:
	case 9:
	case 10: printf ("Д\n"); break;
	case 3: printf ("Т\n"); break;
	case 4: printf ("Ч\n"); break;
	case 5: printf ("П\n"); break;
	case 6: printf ("Ш\n"); break;
	case 7: printf ("С\n"); break;
	case 8: printf ("В\n"); break;

	}
	return 0;
}
