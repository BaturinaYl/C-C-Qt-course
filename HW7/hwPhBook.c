//Home Work #7
//Baturina Yelena
// PhoneBook realisation

#include <stdlib.h>
#include <stdio.h>

struct  PhRec {

	char fam [30];
	char name [30];
	char sername [30];

	char phnum [7];

};


int AddRec (struct PhRec  * recordAdd); //прототип функции

int ViewRec(); // прототип функции

int main (){

struct PhRec  r;
struct PhRec * rec1 = &r;
enum Mode {ADD=1, VIEW, SEARCH}; //Режим работы справочника
enum Mode mod;

printf ("Выберите режим работы Телефонного справочника:\n");
printf ("1 - Режим ввода новых данных;\n");
printf ("2 - Вывод всех записей справочника на экран;\n");
printf ("3 - Режим поиска;\n");

scanf ("%d", &mod);

switch (mod){

case (ADD): printf("Add\n"); AddRec(rec1); break;
case (VIEW): printf("View\n"); ViewRec(); break;
case (SEARCH):printf("Search\n"); /*SearchRec();*/ break;
default : printf("Выбранный режим работы не реализован!\n"); break;

};

return 0;
}
//------------------------------------------------------------------

int AddRec(struct PhRec * recordAdd)
{
	FILE *f;

	printf ("Введите фамилию:  ");
	scanf ("%s", recordAdd->fam);

	printf ("Введите имя:  ");
	scanf ("%s", recordAdd->name);

	printf ("Введите отчество:  ");
	scanf ("%s", recordAdd->sername );

	printf ("Введите номер телефона:  ");
	scanf ("%s", recordAdd->phnum);

	if (!(f=fopen("PhoneBook.txt","a+t")))
  	return 1;


	fprintf(f,"\n %s %s %s ; %s", recordAdd->fam, recordAdd->name, recordAdd->sername, recordAdd->phnum);
//	printf ("\n Вносится значение : %s %s %s ; %s", recordAdd->fam, recordAdd->name, recordAdd->sername, recordAdd->phnum);
	fclose(f);
return 0;
}
//--------------------------------------------------------------------
int ViewRec()
{
	FILE *ff;
	char  st[101];
	char *recordView=&st[0];

	if (!(ff = fopen("PhoneBook.txt","r+t"))) return 1;

	printf("Телефонный справочник: \n");
	do
	   {
	    for (int i=0; i<5; i++)
	     { 
              fscanf(ff,"%s", recordView);
              printf(" %s", st);
	     }
            printf(" \n");
            }
	while(!(feof(ff)));

        fclose(ff);
return 0;
}
//------------------------------------------------------------------
