#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>
#include <unistd.h>


typedef struct task {

  wchar_t name[20];
  int time;
  int prior;
  struct task * next;
  } task_t;

 void print_list (task_t *head); //вывод списка задач на экран
 task_t * push_start (task_t **head, wchar_t  *tname, int ttime, int tprior); // добавление  нового элемента в голову списка

 task_t *Edit_Tsk (task_t *head);
 int Run_Tsk (task_t *head);
  task_t *Ed_Man( task_t *head);  // редактирование списка в ручном режиме


 typedef enum Mode { EDIT = 1, RUN, EXT} mode_m; //Режимы работы менаджера задач (МЗ)
 typedef enum ModeE {MANL = 1, RAND, EX} mode_e; //Режим редактирования стека\списка  
task_t *head = NULL;


int main(){

   mode_m mod;  //  режим работы МЗ
   int ext_main = 0; // флаг выхода из главного меню

                    // создаем список задач, если список создать невозможно работа ПО завершается
//  task_t *head = NULL;
       head = (task_t*)malloc( sizeof(task_t));
    if (head == NULL) {
       wprintf( L"Создание списка задач невозможно!");
       return 1;
    }

 	setlocale(LC_ALL, "ru_RU.utf8");
    do {
	wprintf (L"\n");
	wprintf (L"Выберите режим работы Менеджера задач\n");
	wprintf (L"\n");
 	wprintf (L"1 - Редактирование;\n");
 	wprintf (L"2 - Выполнение;\n");
 	wprintf (L"3 - Выход;\n");
	wprintf (L"\n");

 	wscanf (L"%d", &mod);

	switch (mod){

 	       case(EDIT):head = Edit_Tsk( head); break;

	       case(RUN): Run_Tsk( head); break;

   	       case(EXT): wprintf (L"До встречи !\n"); ext_main = 1; break;

	       default : wprintf (L"Выбранный режим работы не реализован!\n"); break;
        };
    } while (!ext_main);
return (0);
}

//----------------------------------------------------------------------
task_t * Edit_Tsk (task_t *head)
{
  mode_e mod;  // режимы редактирования
 int  ext_ed = 0; // флаг выхода из меню редактирования

  do {
	wprintf (L"\n");
	wprintf (L"Выберите режим редактирования. \n");
	wprintf (L"\n");

	wprintf (L"1 - Создание задачи вручную;\n");
        wprintf (L"2 - Создание задачи случайным образом;\n");
	wprintf (L"3 - Выход;\n");
	wprintf (L"\n");

        wscanf (L"%d", &mod);

        switch (mod){

            case (MANL):head = Ed_Man (head); break;
 	    case (RAND): /*Ed_Rand ();*/ break;
 	    case (EX): ext_ed = 1; break;
 	    default : wprintf (L"\n Выбранный режим не реализован!\n"); break;
         };

      } while (!ext_ed);

  return (head);
}
//------------------------------------------------------------
int Run_Tsk( task_t *head)
{
     print_list ( head);



return (0);
}
//-------------------------------------------------------------
task_t * Ed_Man( task_t *head)
{

  int wrt = 0; // флаг  для  записи введенных пользователем данных в список задач 0-нет, 1-да
  int ext_man = 0; // флаг для выхода из цикла  ввода данных в список задач
  wchar_t ans[4];
  wchar_t nm[20];
  int tm ;
  int pr ; 

  wprintf (L"\n");
  print_list ( head);  // сначала выводим список задач которые уже имеются в стеке

  do {
	wprintf (L"Введите имя новой задачи:  ");
	wscanf (L"%ls", &nm);

	wprintf (L"Введите время выполнения задачи (сек):  ");
	wscanf (L"%d", &tm );

	wprintf (L"Назначте приоритет задаче:  ");
	wscanf (L"%d", &pr );


	wprintf (L"\n");
	wprintf (L"Согласно введенным Вами данным будет сформирована задача. \n");
	wprintf (L"Имя : %ls\n", nm);
	wprintf (L"Время выполнения : %d (сек)\n", tm );
	wprintf (L"Приоритет : %d\n", pr );
	wprintf (L"\n");

	wprintf (L"Вы согласны ? (Да/Нет)\n");

	for (;;) {
            wscanf (L"%ls", &ans);
	    if (wcscmp (ans, L"Да")==0) {
		wrt = 1; break;
	     }
            else if (wcscmp (ans,L"Нет")==0) {
                  wrt = 0; break;
             }
            else  wprintf (L"Ваш ответ не понятен. (Да/Нет)? ");
         }

	if (wrt){
              head = push_start ( &head, nm, tm, pr);
              wprintf (L"Задача сформирована !\n");
	      wprintf (L"\n");
              print_list ( head);
        }

	wprintf (L"Хотите продолжить формировать задачи ? (Да/Нет)\n");
        for (;;) {
	   wscanf (L"%ls",&ans);
	   if (wcscmp(ans, L"Да")==0) {
              ext_man = 1; break;
	    }
           else if (wcscmp(ans, L"Нет") ==0) {
               ext_man = 0; break;
            }
	   else  wprintf (L"Ваш ответ не понятен. (Да/Нет)? ");
          }

    } while (ext_man);


  return  (head);
}
//-------------------------------------------------------------
/*int Ed_Rand()
{


}*/
//-------------------------------------------------------------
/*task_t * create( wchar_t *tname, int ttime, int tprior)
{

       task_t *head = NULL;
       head = (task_t*)malloc( sizeof(tast_t));
       if
       head->name = tname;
       tmp->time = ttime;
       tmp->prior = tprior;
       tmp->next = NULL;
   return (tmp);
}
*/
//-------------------------------------------------------------
task_t *push_start (task_t **head, wchar_t  *tname, int ttime, int tprior)
{
     task_t* new_task;
     new_task = malloc(sizeof(task_t));
     //wcsncpy( ch2, pr[i].fam, k);
     wcscpy( new_task->name, tname);
     new_task->time = ttime;
     new_task->prior = tprior;
     new_task->next = *head;
     *head = new_task;
 return (new_task);
}
//-------------------------------------------------------
/*task_t* get_prior_pre( task_t *head, int tprior){
 task_t * pre =

}*/
//-------------------------------------------------------
/*task_t* get_prior( task_t* head, int tprior) {

    while (head->prior != tprior && head) {
        head = head->next;
    }
    return head;
}*/
//--------------------------------------------------------
/*int run_prior( task_t **head, int tprior) {


        task_t *prev = getNth(*head, n-1);
        task_t *elm  = prev->next;
        wprintf( L"Выполняется задача %ls с приоритетом %d \n",elm->name, elm->prior);
	sleep (elm->time);
        prev->next = elm->next;
        free(elm);
        return ;

}*/
//----------------------------------------------------------
void print_list (task_t *head)
{

   task_t *current = head;
   int n = 0;
   if ((head !=NULL) && (head->time==NULL))
      wprintf(L"Стек задач пуст !\n");
   else {
          wprintf( L"Стек задач для выполнения: [#]  [  Имя   ] [   Время выполн.(сек)  ] [  Приоритет  ]   \n");
          while (current !=NULL){
                 n++;
                 wprintf( L"Задача :              [%d]  [   %ls   ] [           %d          ] [     %d      ]    \n", n, current->name, current->time, current->prior);
                 current = current->next;
          }
  }
}
//----------------------------------------------------------------
