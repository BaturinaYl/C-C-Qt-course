#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <ncurses.h>
//#include <wchar.h>
#include <unistd.h>
#include <string.h>

using namespace std;
#define MTSK_RAND 6
#define MAX_MEM   512

// -- создаем элемент списка (задание)
 typedef struct task {

  char name[30];
  int time;
  int prior;
  int arr[256];
  int size;
  struct task * next;
  } task_t;
//------------------------

  int size_list (task_t *head);
  void print_list (task_t *head); //вывод списка задач на экран
 task_t * push_start (task_t **head, char  *tname, int ttime, int tprior, int tsize); // добавление  нового элемента в голову списка
 void pop_prior_Q (task_t ** hd, int num);    // удаление элемента по  номеру для Очереди
 int    get_priorQ (task_t *head, int tprior);

  task_t *Init_Tsk (task_t *hd);
  task_t *Run_TskQ (task_t **head);
  void Ed_Rand(task_t ** head); // редактирование списка в автоматическом режиме
  int Qst();

 typedef enum Mode { ADDRUN = 1, ONLYRUN, EXT} mode_m; //Режимы работы менаджера задач (МЗ)

//---------------------------------------------------------------------------------
int main(){
     
  //      initscr();
   //     start_color();
    //    init_pair(1, COLOR_GREEN, COLOR_BLACK);
     //   init_pair(2, COLOR_RED, COLOR_BLACK);
        int sz_mem = 0;
   //------- создаем список задач, если список создать невозможно работа ПО завершается
        task_t *head = NULL;
        head = Init_Tsk ( head);
        sz_mem = head->size;
       printf ("sz_mem = %d \n", sz_mem);
      //-------------------------------------
        while (sz_mem < MAX_MEM/32){
            Ed_Rand( &head);
            sz_mem = size_list (head);
            sleep(5);
            printf("sz_mem = %d \n",sz_mem);
        }
      //----------------------------форматированный вывод в с++---------
//        print_list (head);
        head = Run_TskQ( &head);
       //endwin();
return (0);
}

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
task_t *Init_Tsk( task_t *hd){
    srand(time(NULL));
    hd = new task_t;
    if (hd == NULL){
       printf( "File list creating is impossible! \n");
    }
    else {
      strcpy(hd->name, "File_0");
      hd->time = 10;
      hd->prior = 10;
      hd->size = 1 + rand() % 10;
      hd->next = NULL;
      for (int i = 0; i < 256; i++)
        hd->arr[i] = 1 + rand() %100;
    }
      for (int i = 1; i < hd->size; i++)
          hd = push_start( &hd, hd->name, hd->time, hd->prior, hd->size);


return (hd);
}

//-----------------------------------------------------------------------------------
void Ed_Rand(task_t ** head)
{
       char str[10];
       int sz_list = 0;
       srand(time(NULL));
       char nm[30] = "File_";
       int symbol = 0 + rand() %100;
       sprintf( str, "%i", symbol);

       strcat( nm, str);
       int tm = 5 + rand() %10;
       int pr = 1 + rand() % MTSK_RAND;
       int sz = 1 + rand() % 5;
       // прежде чем пытаться создать еще одно задание , выясним сколько свободного места осталась
       sz_list = size_list( *head);
       if ((MAX_MEM - sz_list) > sz) {
           for (int i=0; i < sz; i++)
           *head = push_start ( &(*head), nm, tm, pr, sz);
        }
        else
            printf("Come in tomorrow! \n");  // можно объяснить причину : мало места !!!
       print_list ( *head);
 return ;
}
//-------------------------------------------------------------
task_t *push_start (task_t **head, char  *tname, int ttime, int tprior, int tsize)
{
     task_t* new_task = new task_t;

     strcpy( new_task->name, tname);
     new_task->time = ttime;
     new_task->prior = tprior;
     new_task->next = *head;
     new_task->size = tsize;
     for (int i = 0; i < 256; i++)
        new_task->arr[i] = 1 + rand() % 100;
     *head = new_task;
 return (new_task);
}
//----------------------------------------------------------------------
//-----------------------------------------------------------------------
task_t * Run_TskQ (task_t **head)
{
   int n = -1;
   int prior = 1;
   int ans; 

   while (prior < MTSK_RAND + 1){
       n = get_priorQ (*head, prior);
       printf("prior = %d ,n=%d\n",prior, n);
       if (n > -1){
         print_list (*head);
         pop_prior_Q (&(*head), n);
         ans = Qst ();
         switch (ans){
               case 1: Ed_Rand(&(*head)); prior =1; break;//Добавить задачу
               case 2:  break;// Продолжить работу не добавляя задач
               case 3: return(*head); //закончить работу менеджера
              default:;
        }
        
       }
      else
         prior++;

   }

   print_list (*head);
   return (*head);
}
//----------------------------------------------------------------------
int Qst()
{
        mode_m mod;  //  режим работы МП
        printf ("\n");
        printf ("Choose the regime of Memory Manager running: \n");
        printf ("\n");
        printf ("1 - Add File and Run ;\n");
        printf ("2 - Runnig without add ;\n");
        printf ("3 - Exit ;\n");
        printf ("\n");

        scanf ("%d", (int*) &mod);

        switch (mod){

               case(ADDRUN): return 1;

               case(ONLYRUN):return 2;
               case(EXT): return 3;

               default : printf ("Chosen mode is not realized!\n"); return -1;
        };

}

//--------------------------------------------------------
void pop_prior_Q (task_t **hd, int num){
    int sz_t = 0;

    if (*hd == 0){return;} // если список пуст

    task_t * current =*hd;
    task_t * tmp = NULL;
    sz_t = current->size;

    if ((num == 1) && (sz_t==1)) {  // если список не пуст, есть 1 элем. длина его 1Кб
        *hd = current->next;
         printf("%s with priority %d is running \n",current->name, current->prior);
         sleep ((current->time/current->size));
         delete current;
         return;
    }

    if ((num == 1) && (sz_t != 1)){  // список имеет файл под номером 1 в списке и диной не 1Кб
        *hd = current->next;
        for (int j = 1; j < sz_t; j++){
         printf("%s with priority %d is running \n",current->name, current->prior);
         sleep ((current->time/current->size));
         delete current;
         current = *hd;
         *hd = current->next;
       }
         printf("%s with priority %d is running \n",current->name, current->prior);
         sleep ((current->time/current->size));
         delete current;
   return;
   }
    tmp = current->next;
    for (int i = 1; i < num -1 ; i++){
        if (current->next == NULL){
            return ;
         }
         current = current->next;
    }
    tmp = current->next;
    sz_t = tmp->size;
//    printf( "Task %s with priority %d is running \n", tmp->name, tmp->prior);

  //  sleep(tmp->time);

    for (int j = 1; j < sz_t+1 ; j++){
         tmp = current->next;
         current ->next = tmp -> next;
         printf ("%s with priority %d is running \n", tmp->name, tmp->prior);
         sleep(tmp->time/tmp->size);
         delete tmp;
         
    }
    return;
}
//--------------------------------------------------------
int get_priorQ (task_t *head, int tprior)
{
   int n = -2;
   int count = 0;
   int sz = 0;
   task_t *curr = head;
   task_t *p = head;
   
   if (p == NULL){
      return (n);
    }

   while (p){
     count++;
      if(p->prior == tprior){
         n = count;
         sz = p->size;
        }
       p = p->next;
      // count++;
   }
return ((n-sz)+1);
}
//-------------------------------------------------------
void print_list (task_t *head)
{

   task_t *current = head;
   int n = 0;
   int totaluse = 0;
   
   if (head == NULL) 
      cout<<"Files' list is empty !\n"<<endl;
   else {
          
          cout<< "Files' list  for running: \n"<<endl;
          cout<< "_________________________________________________________________  "<<endl;
          cout<< ""<<endl;
          cout.width(5);
          cout<<" [#] ";
          cout.width(15);
          cout<<" [   name   ] ";
          cout.width(15);
          cout<<"[   time.(s)   ]"; 
          cout.width(15);
          cout<<"[  Priority  ]";
          cout.width(10);
          cout<<"[  Size  ]   \n";
          cout<< "_________________________________________________________________ "<<endl;
          while (current !=NULL){
                 n++;
         //         attron (COLOR_PAIR(1)); 
                  cout<<"  - - - - - - - - - - - - - - - - - - - - - - - - - - - -     "<<endl;
                  cout.width(3);
                  cout<<n;
                  cout.width(13);
                  cout<< current->name;
                  cout.width(13);
                  cout<< current->time; 
                  cout.width(15);
                  cout<< current->prior;
                  cout.width(12);
                  cout<< current->size << endl;
                  totaluse = totaluse + current->size;
           //       attroff (COLOR_PAIR(1));
                   //printf( "Task :              [%d]  [   %s   ] [       %d      ] [     %d      ] [ %d ]    \n", n, current->name, current->time, current->prior, current->size);
                 current = current->next;
          }
       cout<< "  - - - - - - - - - - - - - - - - - - - - - - - - - - - -      "<<endl;
       cout<< "Total using memory is   ";
       cout<< totaluse << endl;
       cout<< "Free memory is   ";
       cout<< (MAX_MEM - totaluse) << endl;
  }

}
//----------------------------------------------------------------
int size_list (task_t *head)
{

   task_t *current = head;
   int n = 0;
   if (head == NULL){
      cout<<"Files' list is empty !\n"<<endl;
      n = 0;
   }
   else {
      while (current !=NULL){
           n++;
           current = current->next;
      }
   }
  return (n);
}
//------------------------------------------------------------------
