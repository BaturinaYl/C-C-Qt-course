//Home Work #7
//Baturina Yelena
// PhoneBook realisation

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <wctype.h>
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
   enum Mode { ADD = 1, VIEW, SEARCH, EXT}; //Режим работы справочника
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

	wprintf (L"\n");
	wprintf (L"Выберите режим работы Телефонного справочника\n");
	wprintf (L"\n");
 	wprintf (L"1 - Режим ввода новых данных;\n");
 	wprintf (L"2 - Вывод всех записей справочника на экран;\n");
 	wprintf (L"3 - Режим поиска;\n");
 	wprintf (L"4 - Выход;\n");
	wprintf (L"\n");

 	wscanf (L"%d", &mod);

	switch (mod){

 	case(ADD): AddRec(recR); break;

	case(VIEW): ViewRec(precR, BIG); break;

	case(SEARCH): SearchRec(precR, BIG); break;

	case(EXT): wprintf (L"До встречи !\n"); ext_m = 1; break;

	default : wprintf (L"Выбранный режим работы не реализован!\n"); break;
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
  wchar_t ans[4];

  if (!(f = fopen("PhoneBook.txt","a+t")))  return (1);
  wprintf (L"\n");

  do {
	wprintf (L"Введите фамилию:  ");
	wscanf (L"%ls", rec->fam);

	wprintf (L"Введите имя:  ");
	wscanf (L"%ls", rec->name);

	wprintf (L"Введите отчество:  ");
	wscanf (L"%ls", rec->sername );

	wprintf (L"Введите номер телефона:  ");
	wscanf (L"%ls", rec->phnum);

	wprintf (L"\n");
	wprintf (L"Введенные Вами данные будут внесены в Телефонную книгу. \n");
	wprintf (L"Фамилия : %ls\n",rec->fam);
	wprintf (L"Имя : %ls\n", rec->name);
	wprintf (L"Отчество : %ls\n", rec->sername);
	wprintf (L"Телефон : %ls\n", rec->phnum);
	wprintf (L"\n");

	wprintf (L"Вы согласны с записью данных ? (Да/Нет)\n");

	for (;;)
          {
            wscanf (L"%ls", &ans);
	    if (wcscmp (ans, L"Да")==0) {wrt = 1; break;}
            else if (wcscmp (ans,L"Нет")==0) {wrt = 0; break;}
            else  wprintf (L"Ваш ответ не понятен. (Да/Нет)? ");
            }

	if (wrt)
	    {
              fwprintf(f,L"\n %ls %ls %ls ; %ls", rec->fam, rec->name, rec->sername, rec->phnum);
	      wprintf (L"Данные записаны !\n");
	      wprintf (L"\n");
        	}

	wprintf (L"Хотите продолжить вводить данные ? (Да/Нет)\n");
        for (;;)
	  {
	   wscanf (L"%ls",&ans);
	   if (wcscmp(ans, L"Да")==0) {ext_a = 1; break;}
           else if (wcscmp(ans, L"Нет") ==0) {ext_a = 0; break;}
	   else  wprintf (L"Ваш ответ не понятен. (Да/Нет)? ");
          }

    } while (ext_a);

  fclose(f);
  return 0;
}
//--------------------------------------------------------------------
int SearchRec ( phrec *pr, int numr)  // поиск записи в массиве
{
  enum Schmod {FM = 1, NM, SN, PH, EX};  // Режимы поиска данных
  enum Schmod  modsch;
  int  ext_s = 0;

  do {
	wprintf (L"\n");
	wprintf (L"Выберите режим поиска. \n");
	wprintf (L"\n");

	wprintf (L"1 - Режим поиска по Фамилии;\n");
        wprintf (L"2 - Режим поиска по Имени;\n");
        wprintf (L"3 - Режим поиска по Отчеству;\n");
        wprintf (L"4 - Режим поиска по Номеру Телефона;\n");
	wprintf (L"5 - Выход;\n");
	wprintf (L"\n");

        wscanf (L"%d", &modsch);

        switch (modsch){

 	case (FM): Sch (pr, numr,1); break;
 	case (NM): Sch (pr, numr,2); break;
 	case (SN): Sch (pr, numr,3); break;
 	case (PH): Sch (pr, numr,4); break;
 	case (EX): ext_s = 1; break;
 	default : wprintf (L"\n Выбранный режим поиска не реализован!\n"); break;
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
  wchar_t *p1, *p2 ;
  int cmp ;
  int  ext_s = 1; // переменная для выхода из цикла  поиска
  wchar_t ans[4];
  int   tst = 0;
  do {
	wprintf (L"\n");
	wprintf (L"Введите Образец для поиска (Строку или часть строки). Но не более %d символов !\n", NMAX);
	wprintf (L"\n");

	wscanf (L"%ls",&expl);
	size_t k = wcslen (expl);
	wprintf (L"\n");
	wprintf (L"Результат поиска  :\n");

	for (int i = 0; i < num; i++)
          {
	    switch (mod){
                                        //переводим сиволы в верхний регист для сравнения
                   case (1): wcsncpy( ch2, pr[i].fam, k);  break;
                   case (2): wcsncpy( ch2, pr[i].name, k); break;
                   case (3): wcsncpy( ch2, pr[i].sername, k); break;
                   case (4): wcsncpy( ch2, pr[i].phnum, k); break;
                   }
	    p2 = ch2;
	    for (p1 = expl; *p1!= L'\0'; p1++ , p2++)
             {
               *p1 = (wchar_t) towupper(*p1);

               *p2 = (wchar_t) towupper (*p2);
              } // for p1
	 wprintf(L" \n");
         cmp = wcsncmp (expl, ch2, k);  // сравниваем первые К символов в образце для поска и считанной подстроке
             if ( cmp == 0)  // сравниваемые элементы совпали
             {
              wprintf( L"\n-- %ls %ls %ls %ls --\n", pr[i].fam, pr[i].name, pr[i].sername, pr[i].phnum);
	      }   // if cmp
           }   // for i

	wprintf( L"\n");
	wprintf( L"Хотите продолжить поиск в выбранном Вами режиме? (Да/Нет)\n");
        for (;;)
          {
           wscanf (L"%ls",&ans);
           if (wcscmp(ans, L"Да")==0) {ext_s = 1; break;}
           else if (wcscmp(ans, L"Нет") ==0) {ext_s = 0; break;}
           else  wprintf (L"Ваш ответ не понятен. (Да/Нет)? ");
          }
     } while (ext_s); 
  return 0;
}
//-------------------------------------------------------------------
int ViewRec( phrec *pr, int numr)
{
  int k;

	wprintf (L"\n");
	wprintf (L"Телефонный справочник: \n");

	for (int i = 0; i < numr; i++)
	   {
              wprintf (L"\n %d.  %ls %ls %ls  тел: %ls \n", k=i+1, pr[i].fam, pr[i].name, pr[i].sername, pr[i].phnum);
	    }

	wprintf (L" \n");
	wprintf (L"В телефонном справочнике %d записей. \n", CountRec());
	wprintf (L"\n");
  return (0);
}
//--------------------------------------------------------------------
phrec * ReadRec (phrec *pr, int numr)
{
  FILE *f;
  wchar_t  st[NMAX];

	if (!(f = fopen("PhoneBook.txt","r+t"))) return 0;

        for (int i = 0; i < numr; i++)
         {
           fwscanf (f, L"%ls", &pr[i].fam);

           fwscanf (f, L"%ls", &pr[i].name);

           fwscanf (f, L"%ls", &pr[i].sername);

           fwscanf (f, L"%ls", &st);

           fwscanf (f, L"%ls", &pr[i].phnum);
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
          for (int i = 0; i < 5; i++)
           {
             fwscanf( fl, L"%ls", s);
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

	for (int k = 1; k < NMAX-2; k++)
          {
	   for (int i = 0; i < numr-1; i++)
	     {
              for (int l = 0; l < k; l++)
		{
                  ch1[l] = (pr[i].fam[l]);
	          ch2[l] = (pr[i+1].fam[l]);
		}
	      cmp = wcsncasecmp (ch1, ch2, k);
              if ( cmp > 0)
	        {
	         for(int j = 0; j < NMAX;j++)
	           {
			tmp->fam[j] = pr[i].fam[j];
			pr[i].fam[j] = pr[i+1].fam[j];
			pr[i+1].fam[j] = tmp->fam[j];

			tmp->name[j] = pr[i].name[j];
              		pr[i].name[j] = pr[i+1].name[j];
              		pr[i+1].name[j] = tmp->name[j];

	      		tmp->sername[j] = pr[i].sername[j];
              		pr[i].sername[j] = pr[i+1].sername[j];
        		 pr[i+1].sername[j] = tmp->sername[j];

	      		tmp->phnum[j] = pr[i].phnum[j];
              		pr[i].phnum[j] = pr[i+1].phnum[j];
             		pr[i+1].phnum[j] = tmp->phnum[j];

         	      }  // end for j
      	        }   // if cmp
             }   // for i
	}   // for k
  return (pr);

}
//-----------   F I N A L   ----------------------------------------------------------

