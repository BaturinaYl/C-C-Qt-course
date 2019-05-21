#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <locale.h>
//#include <wchar.h>
#include <unistd.h>
#include <string.h>

#define MTSK_RAND 10

// -- создаем элемент списка (задание)
 typedef struct task {

  char name[30];
  int time;
  int prior;
  struct task * next;
  } task_t;
//------------------------
 
 void print_list (task_t *head); //вывод списка задач на экран
 task_t * push_start (task_t **head, char  *tname, int ttime, int tprior); // добавление  нового элемента в голову списка
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
           printf( "Creating of tasks' list is impossible!");
           return 1;
         }
  //-----------------------------------------------------
  // --инициализация  списка
    strcpy( head->name ,"Task0");
    head->time = 10;
    head->prior= 10;
    head->next = NULL;
 //------------------------------------------------------
    do {
	printf ("\n");
	printf ("Choose the regime of Task Manager running: \n");
	printf ("\n");
 	printf ("1 - Tasks' creating;\n");
 	printf ("2 - Runnig (STACK);\n");
        printf ("3 - Runnig (QUEUE);\n");
 	printf ("4 - Exit;\n");
	printf ("\n");

 	scanf ("%d", (int*) &mod);
        int n =-1;
        int k = 1;
	switch (mod){

 	       case(EDIT):head = Edit_Tsk( head); break;

	       case(RUNSTACK):  head = Run_TskS( &head); break;
               case(RUNQUEUE): head = Run_TskQ( &head); break;
   	       case(EXT): printf ("See you late !\n"); ext_main = 1; break;

	       default : printf ("Chosen mode is not realized!\n"); break;
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
	printf ("\n");
	printf ("Choose  creating regime: \n");
	printf ("\n");

	printf ("1 - Manual creating;\n");
        printf ("2 - Random creating;\n");
	printf ("3 - Exit;\n");
	printf ("\n");

        scanf ("%d",(int*) &mod);

        switch (mod){

            case (MANL):head = Ed_Man (head); break;
 	    case (RAND):head = Ed_Rand (head); break;
 	    case (EX): ext_ed = 1; break;
 	    default : printf ("\n Chosen regime is not realized!\n"); break;
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
  char ans[4];
  char nm[30];
  int tm ;
  int pr ; 

  printf ("\n");
  print_list ( head);  // сначала выводим список задач которые уже имеются в стеке

  do {
	printf ("Set task's name:  ");
	scanf ("%s", &nm[30]);

	printf ("Set running time (s):  ");
	scanf ("%d", &tm );

	printf ("Set priority:  ");
	scanf ("%d", &pr );


	printf ("\n");
	printf ("The task will be crated with following parameters: \n");
	printf ("NAME : %s\n", &nm[30]);
	printf ("Running time : %d (сек)\n", tm );
	printf ("PRIORITY : %d\n", pr );
	printf ("\n");

	printf ("Are you agree ? (Да/Нет)\n");

	for (;;) {
            scanf ("%s", &ans[4]);
	    if (strcmp (ans, "Yes")==0) {
		wrt = 1; break;
	     }
            else if (strcmp (ans,"No")==0) {
                  wrt = 0; break;
             }
            else  printf ("Please, repeat your answer. (Yes/No)? ");
         }

	if (wrt){
              head = push_start ( &head, nm, tm, pr);
              printf ("Task is created !\n");
	      printf ("\n");
              print_list ( head);
        }

	printf ("Would you continue task's creating ? (Yes/No)\n");
        for (;;) {
	   scanf ("%s",&ans[4]);
	   if (strcmp(ans, "Yes")==0) {
              ext_man = 1; break;
	    }
           else if (strcmp(ans, "No") ==0) {
               ext_man = 0; break;
            }
	   else  printf ("Please, repeat your answer. (Yes/No)? ");
          }

    } while (ext_man);


  return  (head);
}
//-------------------------------------------------------------
task_t * Ed_Rand(task_t * head)
{
       char str[10];
       srand(time(NULL));
       char nm[30] = "Task";
       int symbol = 0+rand() %100;
       sprintf( str, "%i", symbol);

       strcat( nm, str);
       int tm = 5 + rand() %10;
       int pr = 1 + rand() %MTSK_RAND;
       head = push_start ( &head, nm, tm, pr);
       print_list ( head);
 return (head);
}
//-------------------------------------------------------------
task_t *push_start (task_t **head, char  *tname, int ttime, int tprior)
{
     task_t* new_task;
     new_task = malloc(sizeof(task_t));
     strcpy( new_task->name, tname);
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
         printf ("Task %s with priority %d is running \n", cur->name, cur->prior);
         sleep (cur->time);

         free(cur);
         return;
      }

  task_t *tmp = cur->next;
     while(tmp){
        if (tmp->prior == tprior){
            cur->next = tmp->next;
            printf( "Task %s with priority %d is running \n", tmp->name, tmp->prior);
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
         printf("Task %s with priority %d is running \n",current->name, current->prior);
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
    printf ("Task %s with priority %d is running \n", tmp->name, tmp->prior);
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
      printf ("Tasks' list is empty !\n");
   else {
          printf( "Tasks' list  for running: [#]  [  name   ] [   Running time.(s)  ] [  Priority  ]   \n");
          while (current !=NULL){
                 n++;
                 printf( "Task :              [%d]  [   %s   ] [           %d          ] [     %d      ]    \n", n, current->name, current->time, current->prior);
                 current = current->next;
          }
  }
}
//----------------------------------------------------------------
