//Home Work #7
//Baturina Yelena
// PhoneBook realisation

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>

#define NMAX 30  // число символов в  строке поля


 typedef struct phrecus {

	wchar_t fam [NMAX];
	wchar_t name [NMAX];
	wchar_t sername [NMAX];
	wchar_t phnum [NMAX];

 } phrec;

//-------------------------------------------------------------------------------------------------------
   int AddRec (phrec * rec); // добавление новой записи в файл

   int ViewRec (phrec *pr, int numr); // просмотр данных из файла в отсортировнном виде

   int SearchRec ( phrec *pr, int numr);  // поиск записи в  данных из файла

   int CountRec ();			// подсчет числа записей в файле

   phrec * ReadRec (phrec *pr, int numr);   //считывание записей из файла в дин массив

   phrec * SortRec (phrec *pr, int numr); // сортировка массива записей из файла

   int Sch (phrec *pr, int num, int mod);   // поиск в режиме (Фамилия, имя, отчество, телефон

//--------------------------------------------------------------------------------------------------------

int main (){

   phrec rru;
   phrec * recR = &rru;
   enum Mode { ADD=1, VIEW, SEARCH, EXT}; //Режим работы справочника
   enum Mode mod;
   int ext_m = 0;
   unsigned int BIG;  //количество  записей в файле

   setlocale(LC_ALL, "ru_RU.utf8");

   do {

	BIG = CountRec();  //вычисляем количество дин структур в массиве

        size_t n = BIG * sizeof (phrec); // размер дин массива в байтах

        phrec *precR = (phrec*) malloc(n); // создание динам массива структур

	precR = ReadRec ( precR, BIG);

	precR = SortRec ( precR, BIG);

	printf ("\n");
	printf ("Выберите режим работы Телефонного справочника\n");
	printf ("\n");
 	printf ("1 - Режим ввода новых данных;\n");
 	printf ("2 - Вывод всех записей справочника на экран;\n");
 	printf ("3 - Режим поиска;\n");
 	printf ("4 - Выход;\n");
	printf ("\n");

 	scanf ("%d", &mod);

	switch (mod){

 	case (ADD): AddRec(recR); break;

	case (VIEW): ViewRec(precR, BIG); break;

	case (SEARCH): SearchRec(precR, BIG); break;

	case (EXT): printf("До встречи !\n"); ext_m = 1; break;

	default : printf("Выбранный режим работы не реализован!\n"); break;
 	};

	free (precR);

    } while (!ext_m);

return 0;
}
//------------------------------------------------------------------

int AddRec (phrec * rec)
{
  FILE *f;
  int wrt = 0; // переменная  для  записи введенных пользователем данных в телефонную книгу 0-нет, 1-да
  int ext_a = 0; // переменная для выхода из цикла  ввода данных в телефонную книгу
  char ans[4] = {'0'};

  if (!(f = fopen("PhoneBook.txt","a+t")))  return 1;
  printf ("\n");

  do {
	printf ("Введите фамилию:  ");
	scanf ("%s", rec->fam);

	printf ("Введите имя:  ");
	scanf ("%s", rec->name);

	printf ("Введите отчество:  ");
	scanf ("%s", rec->sername );

	printf ("Введите номер телефона:  ");
	scanf ("%s", rec->phnum);

	printf ("\n");
	printf ("Введенные Вами данные будут внесены в Телефонную книгу. \n");
	printf ("Фамилия : %s\n",rec->fam);
	printf ("Имя : %s\n", rec->name);
	printf ("Отчество : %s\n", rec->sername);
	printf ("Телефон : %s\n", rec->phnum);
	printf ("\n");

	printf ("Вы согласны с записью данных ? (Да/Нет)\n");

	for (;;)
          {
            scanf("%s", &ans);
	    if (strcmp (ans, "Да")==0) {wrt = 1; break;}
            else if (strcmp (ans,"Нет")==0) {wrt = 0; break;}
            else  printf ("Ваш ответ не понятен. (Да/Нет)? ");
            }

	if (wrt)
	    {
              fprintf(f,"\n %s %s %s ; %s", rec->fam, rec->name, rec->sername, rec->phnum);
	      printf ("Данные записаны !\n");
	      printf ("\n");
        	}

	printf ("Хотите продолжить вводить данные ? (Да/Нет)\n");
        for (;;)
	  {
	   scanf ("%s",&ans);
	   if (strcmp(ans, "Да")==0) {ext_a = 1; break;}
           else if (strcmp(ans, "Нет") ==0) {ext_a = 0; break;}
	   else  printf ("Ваш ответ не понятен. (Да/Нет)? ");
          }

    } while (ext_a);

  fclose(f);
  return 0;
}
//--------------------------------------------------------------------
int SearchRec ( phrec *pr, int numr)  // поиск записи в массиве
{
  enum Schmod {FM=1, NM=2, SN=3, PH=4, EX=5};  // Режимы поиска данных
  enum Schmod  modsch;
  int  ext_s = 0;

  do {
	printf ("\n");
	printf ("Выберите режим поиска. \n");
	printf ("\n");

	printf ("1 - Режим поиска по Фамилии;\n");
        printf ("2 - Режим поиска по Имени;\n");
        printf ("3 - Режим поиска по Отчеству;\n");
        printf ("4 - Режим поиска по Номеру Телефона;\n");
	printf ("5 - Выход;\n");
	printf ("\n");

        scanf ("%d", &modsch);

        switch (modsch){

 	case (FM): Sch (pr, numr,1); break;
 	case (NM): Sch (pr, numr,2); break;
 	case (SN): Sch (pr, numr,3); break;
 	case (PH): Sch (pr, numr,4); break;
 	case (EX): ext_s = 1; break;
 	default : printf("\n Выбранный режим поиска не реализован!\n"); break;
         };

      } while (!ext_s);

  return 0;
}
//--------------------------------------------------------------------
int Sch (phrec *pr, int num, int mod)
{
  wchar_t expl[NMAX]; // образец для поиска
  int k = 0;       // количество символов в образце
  wchar_t ch1[NMAX];
  wchar_t ch2[NMAX];
  int cmp ;
  int  ext_s = 1; // переменная для выхода из цикла  поиска
  char ans[4] = {'0'};

  do {
	printf ("\n");
	printf ("Введите Образец для поиска (Строку или часть строки). Но не более %d символов !\n", NMAX);
	printf ("\n");

	scanf ("%s",expl);
	k = strlen (expl);
	printf ("\n");
	printf("Результат поиска :\n");
        for (int i = 0; i < num; i++)
          {
           for (int l = 0; l < k; l++)
             {
              ch1[l] = toupper (expl[l]);
              switch (mod){
                                       //переводим сиволы в верхний регист для сравнения
                     case (1) :ch2[l] = toupper (pr[i].fam[l]); break;
                     case (2): ch2[l] = toupper (pr[i].name[l]); break;
 	             case (3): ch2[l] = toupper (pr[i].sername[l]); break;
                     case (4): ch2[l] = toupper (pr[i].phnum[l]); break;
                     }
              } // for l
             printf ("\n");
             cmp = strncmp (ch1, ch2, k);  // сравниваем первые К символов в образце для поска и считанной подстроке
            if ( cmp == 0)  // сравниваемые элементы совпали
             {
              printf("\n-- %s %s %s %s --\n", pr[i].fam, pr[i].name, pr[i].sername, pr[i].phnum);
	      }   // if cmp
           }   // for i

	printf ("\n");
	printf ("Хотите продолжить поиск в выбранном Вами режиме? (Да/Нет)\n");
        for (;;)
          {
           scanf ("%s",&ans);
           if (strcmp(ans, "Да")==0) {ext_s = 1; break;}
           else if (strcmp(ans, "Нет") ==0) {ext_s = 0; break;}
           else  printf ("Ваш ответ не понятен. (Да/Нет)? ");
          }
  } while (ext_s); 
  return 0;
}
//-------------------------------------------------------------------
int ViewRec(phrec *pr, int numr)
{
  int k; 

	printf ("\n");
	printf("Телефонный справочник: \n");

	for (int i=0; i<numr; i++)
	   {
              printf("\n %d.  %s %s %s  тел: %s \n", k=i+1, pr[i].fam, pr[i].name, pr[i].sername, pr[i].phnum);
	    }

	printf(" \n");
	printf ("В телефонном справочнике %d записей. \n", CountRec());
	printf ("\n");
  return (0);
}
//--------------------------------------------------------------------
phrec * ReadRec (phrec *pr, int numr)
{
  FILE *f;
  wchar_t  st[NMAX];

	if (!(f = fopen("PhoneBook.txt","r+t"))) return 1;

        for (int i=0; i<numr; i++)
        {
           fscanf (f, "%s", &pr[i].fam);

           fscanf (f, "%s", &pr[i].name);

           fscanf (f, "%s", &pr[i].sername);

           fscanf (f, "%s", &st);

           fscanf (f, "%s", &pr[i].phnum);
        }
        fclose(f);
  return (pr);

}

//------------------------------------------------------------------
int  CountRec()
{
  FILE * fl; 
  int n = 0;
  wchar_t s[NMAX];

	if (!(fl = fopen("PhoneBook.txt","r+t"))) return -1;

        while(!(feof(fl)))
        {
          for (int i=0; i<5; i++)
           { 
             fscanf(fl,"%s", s);
            }
  	  n++;
         }

        fclose(fl);
  return n;

}
//-----------------------------------------------------------------
phrec * SortRec (phrec *pr, int numr)
{
  wchar_t ch1[NMAX];
  wchar_t ch2[NMAX];
  int cmp ;

  phrec stmp;
  phrec * tmp = &stmp;

	for (int k=1; k < NMAX-2; k++)
          {
	   for (int i=0; i<numr-1; i++)
	     {
              for (int l=0; l<k; l++)
		{
                  ch1[l] = toupper (pr[i].fam[l]);
	          ch2[l] = toupper (pr[i+1].fam[l]);
		}
	      cmp = strncmp (ch1, ch2, k);
              if ( cmp > 0)
	        {
	         for(int j=0; j < NMAX;j++)
	           {
			tmp->fam[j]=pr[i].fam[j];
			pr[i].fam[j] = pr[i+1].fam[j];
			pr[i+1].fam[j] = tmp->fam[j];

			tmp->name[j]=pr[i].name[j];
              		pr[i].name[j] = pr[i+1].name[j];
              		pr[i+1].name[j] = tmp->name[j];

	      		tmp->sername[j]=pr[i].sername[j];
              		pr[i].sername[j] = pr[i+1].sername[j];
        		 pr[i+1].sername[j] = tmp->sername[j];

	      		tmp->phnum[j]=pr[i].phnum[j];
              		pr[i].phnum[j] = pr[i+1].phnum[j];
             		pr[i+1].phnum[j] = tmp->phnum[j];

         	      }  // end for j
      	        }   // if cmp
             }   // for i
	}   // for k
  return (pr);

}
//-----------   F I N A L   ----------------------------------------------------------

