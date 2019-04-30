//Home Work #7
//Baturina Yelena
// PhoneBook realisation

#include <stdlib.h>
#include <stdio.h>

struct  PhRec {

	char * Pfam;
	char * Pname;
	char * Psername;

	char * Pphnum;

};

struct PhRec * rec1;

int AddRec (struct PhRec * recordAdd); //прототип функции

int main (){

enum Mode {ADD=1, VIEW, SEARCH}; //Режим работы справочника
enum Mode mod;

printf ("Выберите режим работы Телефонного справочника\n");
printf ("1 - Режим ввода новых данных;\n");
printf ("2 - Вывод всех записей справочника на экран;\n");
printf ("3 - Режим поиска;\n");

scanf ("%d", &mod);

switch (mod){

case (ADD): printf("Add\n"); AddRec(rec1); break;
case (VIEW): printf("View\n");/*ViewRec();*/ break;
case (SEARCH):printf("Search\n"); /*SearchRec();*/ break;
default : printf("Выбранный режим работы не реализован!\n"); break;

};

return 0;
}

int AddRec(struct PhRec * recordAdd)
{
FILE *f;

printf ("Введите фамилию:  ");
scanf ("%c", recordAdd->Pfam);

printf ("Введите имя:  ");
scanf ("%c", recordAdd->Pname);

printf ("Введите отчество:  ");
scanf ("%c", recordAdd->Psername );

printf ("Введите номер телефона:  ");
scanf ("%c", recordAdd->Pphnum);

if (!(f=fopen("PhoneBook.txt","a+t")))
  return 1;

fprintf(f,"%pp %pp %pp ; %pp", recordAdd->Pfam, recordAdd->Pname, recordAdd->Psername, recordAdd->Pphnum);

fclose(f);
return 0;
}
