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
enum Mode {ADD=1, VIEW, SEARCH, EXT}; //Режим работы справочника
enum Mode mod;
int et = 0;

do {

 printf ("Выберите режим работы Телефонного справочника:\n");
 printf ("1 - Режим ввода новых данных;\n");
 printf ("2 - Вывод всех записей справочника на экран;\n");
 printf ("3 - Режим поиска;\n");
 printf ("4 - Выход;\n");

 scanf ("%d", &mod);

 switch (mod){

 case (ADD): printf("Add\n"); AddRec(rec1); break;
 case (VIEW): printf("View\n"); ViewRec(); break;
 case (SEARCH): printf("Search\n"); /*SearchRec();*/ break;
 case (EXT): printf("Exit\n"); et = 1; break;
 default : printf("Выбранный режим работы не реализован!\n"); break;
 };
} while (!et);

return 0;
}
//------------------------------------------------------------------

int AddRec(struct PhRec * recordAdd)
{
	FILE *f;
	int wrt=0; // переменная  для  записи введенных пользователем данных в телефонную книгу 0-нет, 1-да
	int  ext = 0; // переменная для выхода из цикла  ввода данных в телефонную книгу
	char ans[3]={'0'};

	if (!(f=fopen("PhoneBook.txt","a+t")))
        return 1;

	do {
	printf ("Введите фамилию:  ");
	scanf ("%s", recordAdd->fam);

	printf ("Введите имя:  ");
	scanf ("%s", recordAdd->name);

	printf ("Введите отчество:  ");
	scanf ("%s", recordAdd->sername );

	printf ("Введите номер телефона:  ");
	scanf ("%s", recordAdd->phnum);
	printf ("Введенные Вами данные будут внесены в Телефонную книгу. \n");
	printf ("Фамилия : %s\n",recordAdd->fam);
	printf ("Имя : %s\n", recordAdd->name);
	printf ("Отчество : %s\n", recordAdd->sername);
	printf ("Телефон : %s\n", recordAdd->phnum);

	printf ("Вы согласны с записью данных ? (Yes/No)\n");

   an1 : scanf ("%s",ans);
	if (ans[0] == 'Y') wrt = 1;
	else if(ans[0] == 'N') wrt = 0;
	else { printf ("Ваш ответ не понятен. (Yes/No)? ");
	       goto an1;}
  
	if (wrt) 
	    {
              fprintf(f,"\n %s %s %s ; %s", recordAdd->fam, recordAdd->name, recordAdd->sername, recordAdd->phnum);

	      printf ("Данные записаны !\n");
		}
	printf ("Хотите продолжить вводить данные ? (Yes/No)\n");
  an2:	scanf ("%s",ans);
	if (ans[0] == 'Y') ext = 1;
        else if (ans[0] == 'N') ext = 0;
	else { printf ("Ваш ответ не понятен. (Yes/No)? ");
               goto an2;}

}
	while (ext);

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
