#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>
#include <unistd.h>


#define MTSK_RAND 10

// -- создаем элемент списка (задание)
 typedef struct task {

  wchar_t name[30];
  int time;
  int prior;
  struct task * next;
  } task_t;
//------------------------
 
 void print_list (task_t *head); //вывод списка задач на экран
 task_t * push_start (task_t **head, wchar_t  *tname, int ttime, int tprior); // добавление  нового элемента в голову списка
 void pop_prior_S (task_t **hd, int tprior);  // удаление элемента по приоритету для Стека
 void pop_prior_Q (task_t ** hd, int num);    // удаление элемента по  номеру для Очереди
 int    get_priorS (task_t *head, int tprior);
 int    get_priorQ (task_t *head, int tprior);

  task_t *Edit_Tsk (task_t *head);
  task_t *Run_TskS (task_t **head);
  task_t *Run_TskQ (task_t **head);
  task_t *Ed_Man( task_t *head);  // редактирование списка в ручном режиме
  task_t *Ed_Rand(task_t * head); // редактирование списка в автоматическом режиме

 typedef enum Mode { EDIT = 1, RUNSTACK, RUNQUEUE, EXT} mode_m; //Режимы работы менаджера задач (МЗ)
 typedef enum ModeE {MANL = 1, RAND, EX} mode_e; //Режим редактирования стека\списка  


int main(){

        mode_m mod;  //  режим работы МЗ
        int ext_main = 0; // флаг выхода из главного меню

   //------- создаем список задач, если список создать невозможно работа ПО завершается
        task_t *head = NULL;
        head = (task_t*)malloc( sizeof(task_t));
        if (head == NULL) {
           wprintf( L"Создание списка задач невозможно!");
           return 1;
         }
  //-----------------------------------------------------
  // --инициализация  списка
    wcscpy( head->name ,L"Задача0");
    head->time = 10;
    head->prior= 10;
    head->next = NULL;
 //------------------------------------------------------
	setlocale(LC_ALL, "ru_RU.utf8");
//        print_list (head);
    do {
	wprintf (L"\n");
	wprintf (L"Выберите режим работы Менеджера задач\n");
	wprintf (L"\n");
 	wprintf (L"1 - Редактирование;\n");
 	wprintf (L"2 - Выполнение (СТЕК);\n");
        wprintf (L"3 - Выполнение (ОЧЕРЕДЬ);\n");
 	wprintf (L"4 - Выход;\n");
	wprintf (L"\n");

 	wscanf (L"%d", &mod);
        int n =-1;
        int k = 1;
	switch (mod){

 	       case(EDIT):head = Edit_Tsk( head); break;

	       case(RUNSTACK):  head = Run_TskS( &head); break;
               case( RUNQUEUE): head = Run_TskQ( &head); break;
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
 	    case (RAND):head = Ed_Rand (head); break;
 	    case (EX): ext_ed = 1; break;
 	    default : wprintf (L"\n Выбранный режим не реализован!\n"); break;
         };

      } while (!ext_ed);

  return (head);
}
//------------------------------------------------------------
task_t * Run_TskQ (task_t **head)
{
   int n = -1;
   int k = 1;
   while (k < MTSK_RAND + 1){
       n = get_priorQ (*head, k);
      if (n != -1){
         print_list (*head);
         pop_prior_Q (&(*head), n);
       }
      else  k++;
   }

   print_list (*head);
   return (*head);
}
//------------------------------------------------------------
task_t * Run_TskS( task_t **head)
{
    int n = -1;
    int k = 1;

    while (k < MTSK_RAND+1){
          n = get_priorS( *head, k); // имеется ли хотя бы 1 задача с k приоритетом
          if (n != -1) {
            print_list (*head);
            pop_prior_S (&(*head), k);
          }
          else k++;
    }
   print_list (*head);

return (*head);
}
//-------------------------------------------------------------
task_t * Ed_Man( task_t *head)
{

  int wrt = 0; // флаг  для  записи введенных пользователем данных в список задач 0-нет, 1-да
  int ext_man = 0; // флаг для выхода из цикла  ввода данных в список задач
  wchar_t ans[4];
  wchar_t nm[30];
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
task_t * Ed_Rand(task_t * head)
{
       wchar_t str[10];
       srand(time(NULL));
       wchar_t nm[30] = L"Задача";
       int symbol = 0+rand() %100;
       swprintf( str, 3, L"%i", symbol);

       wcscat( nm, str);
       int tm = 5 + rand() %10;
       int pr = 1 + rand() %MTSK_RAND;
       head = push_start ( &head, nm, tm, pr);
       print_list ( head);
 return (head);
}
//-------------------------------------------------------------
task_t *push_start (task_t **head, wchar_t  *tname, int ttime, int tprior)
{
     task_t* new_task;
     new_task = malloc(sizeof(task_t));
     wcscpy( new_task->name, tname);
     new_task->time = ttime;
     new_task->prior = tprior;
     new_task->next = *head;
     *head = new_task;
 return (new_task);
}
//--------------------------------------------------------
void pop_prior_S (task_t **hd, int tprior){

     if (*hd == 0){ return;}
  task_t *cur = *hd;
     if (cur->prior ==tprior){
        *hd = cur ->next;
         wprintf( L"Выполняется задача %ls с приоритетом %d \n", cur->name, cur->prior);
         sleep (cur->time);

         free(cur);
         return;
      }

  task_t *tmp = cur->next;
     while(tmp){
        if (tmp->prior == tprior){
            cur->next = tmp->next;
            wprintf( L"Выполняется задача %ls с приоритетом %d \n", tmp->name, tmp->prior);
            sleep (tmp->time);

            free(tmp);
            return;
         }
        cur = tmp;
        tmp = tmp->next;
    }
}
//-------------------------------------------------------
void pop_prior_Q (task_t **hd, int num){
    int i = 0;

    if (*hd == 0){return;}

    task_t * current =*hd;
    task_t * tmp = NULL;
    if (num == 1) {
        *hd = current->next;
         wprintf(L"Выполняется задача %ls с приоритетом %d  \n",current->name, current->prior);
         sleep (current->time);
         free(current);
         return;
    }
    tmp = current->next;
    for (int i = 1; i< num -1 ; i++){
        if (current->next == NULL){
            return ;
         }
         current = current->next;
    }
    tmp = current->next;
    current ->next = tmp ->next;
    wprintf (L"Выполняется задача %ls с приоритетом %d \n", tmp->name, tmp->prior);
    sleep(tmp->time);
    free (tmp);
    return;
}
//--------------------------------------------------------
int get_priorQ (task_t *head, int tprior)
{
   int n = -1;
   int count = 1;
   task_t *curr = head;
   task_t *p = head;
   if (p == NULL){
      return (n);
    }
   while (p){
      if(p->prior == tprior){
         n = count;
        }
       p = p->next;
       count++;
   }
   return (n);
}
//-------------------------------------------------------
int get_priorS (task_t *head, int tprior){

  int n = -1;
  task_t *current = head;
  task_t *p = head;
  if (p == NULL){
      n = -1;
      return (n);
   }
   while (p){
      if(p->prior == tprior) {
          n = 2;
          return n;
      }
          p = p->next;
   }

  return (n);

}
//----------------------------------------------------------
void print_list (task_t *head)
{

   task_t *current = head;
   int n = 0;
   if (head == NULL) 
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
