#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

using namespace std;

#define MAX_MEM   30   // размер доступной памяти в Кб

// -- создаем элемент списка (страница)
 typedef struct page {

  char name[20];
  int arr[256];    // размер страницы 1 Кб
  struct page * next;
  } page_t;
//------------------------
//--параметры процесса
 typedef struct proc {

  char name[20];
  int n_start; // номер страницы в списке с которой отводится место для процесса
  int size;
  struct proc * next;
  } proc_t;

//-------------------------
  int size_list (page_t *head);     // подсчет размера комичества страниц
  int size_list_empty (page_t *head);  // подсчет размера пустых страниц памяти
  int size_list_proc (proc_t *head);    // подсчет количества загруженных в память процессов
  page_t * push_start_pg (page_t **head, char  *tname); // добавление новой пустой страницы  в голову списка
  page_t *Init_Mem (page_t *hd);  // создание списка страниц на всю выделенную память
  void inserNth (page_t ** head, int index, char *tname, int tsz);  // вставка нового процесса в найденное для него место в памяти
  void wrData( page_t ** head, char *nm, int sz);      // непосредственная запись процесса на страницы
  int findFreeSpace (page_t ** head, int size);          // процедура поиска свободного места для  добавления в память нового процесса
  void Add_Proc( page_t ** hdPage, proc_t **hdProc, int numPr); // добавление процесса в память и в список процессов, если имеется возможность
  void addToPrList (proc_t **hdProc, char *name, int start_n, int size);  // занесение в список процессов нового процесса
  int  Qst();
  void print_list_page (page_t *head);
  void print_list_proc (proc_t *head);
  void Rem_Proc (page_t **head, proc_t **hdpr);  // главная процедура очистки памяти от процесса
  int clear_name (page_t **hd, char *nm);      // очистка в памяти страниц занимаемых процессом с им. nm
  int pop_prname( proc_t **head, char *name);  // удаление из списка процессов процесса с имененя name
  void defrag (page_t ** head);               // дефрагментация свободной памяти


  typedef enum Mode { ADDPR = 1, REMOVEPR, DEFRAG, EXT} mode_m; //Режимы работы менаджера памяти (МП)

 
//---------------------------------------------------------------------------------
int main()
{

   int ex = 0;  // флаг выхода из менеджера
   int ans;
   int numProc = 0;

   //-------   создаем список страниц на всю выделенную память
        page_t *hdPg = NULL;
        proc_t *hdPr = NULL;
        hdPg = Init_Mem ( hdPg);

   //-----------  главное меню приложени
        while (!ex) {
             ans = Qst ();
             switch (ans){
                 case 1: numProc++; Add_Proc( &hdPg, &hdPr, numProc ); break;// Добавить процесс
                 case 2: Rem_Proc( &hdPg, &hdPr); break;                     // Удалить процесс
                 case 3: defrag( &hdPg); break;                              // Дефрагментация
                 case 4: ex = 1; break;                                      //завершить работу менеджера
                 default:;
             }
        }
       delete hdPg;
       delete hdPr;
return (0);
}
//-----------------------------------------------------------
void defrag (page_t ** head)
{
     if (head == NULL){
         cout <<"------------------  Page list is empty. Defragmentation is done!   -----------------"<<endl;
         cout<<" "<<endl;
         return;
     }

     int sz = size_list_empty (*head); // размер списка пустых страниц
     if (sz == MAX_MEM) {
         cout<<"----------------  Memory empty. There is no reason for defragmentation.  --------------------"<<endl; 
        return;
     }

     page_t * hdtmp = NULL; // создаем новый вспомогательый список
     page_t * tmp = NULL;
     page_t * nextnode = NULL;

     while (!(strcmp((*head)->name,""))) {
         if (!(strcmp( (*head)->name, ""))) {
             nextnode = (*head)->next;
             tmp = *head;
             tmp->next = hdtmp;
             hdtmp = tmp;
             *head = nextnode;
        }
     }

     page_t* current = *head;    //если первая страница пустая

     while (current->next!=NULL){
         if (!(strcmp( current->next->name, ""))) {// найдена отметка страницы о том что она пуста
            page_t *nextNext = current->next->next;
            tmp = current->next;
            tmp->next = hdtmp;
            hdtmp = tmp;
            current->next = nextNext;
         }
         else
             current= current->next;
     }

// после завершения цикла к основному списку добавим список пустой
     current->next = hdtmp;

     print_list_page(*head);

     return;
}

//-----------------------------------------------------------------------------------

page_t *Init_Mem( page_t *hd){

   hd = new page_t;
   if (hd == NULL){
      printf( "---------------  Page list creating is impossible!  -----------------\n");
      cout<<" "<<endl;
    }
    else {
      strcpy(hd->name, "");
      hd->next = NULL;
    }
    for (int i = 1; i < MAX_MEM; i++)
        hd = push_start_pg( &hd, hd->name);

    return (hd);
}
//-------------------------------------------------------------
page_t *push_start_pg (page_t **head, char  *tname)
{
     page_t* new_task = new page_t;

     strcpy( new_task->name, tname);
     new_task->next = *head;
     for (int i = 0; i < 256; i++)
        new_task->arr[i] = -1;
     *head = new_task;
     return (new_task);
}

//-----------------------------------------------------------------------------------
void Add_Proc( page_t ** hdPage, proc_t ** hdProc, int numPr)
{
       char str[10];
       int sz_list = 0;
       int ch_m = -1; // для проверки свободной памяти -1-нельзя добавить, >-1 - номер элемента списка куда добавляем
       char nm[30] = "Process_";

       srand(time(NULL));
       sprintf( str, "%i", numPr);
       strcat( nm, str); // имя процесса (номер по порядку)
       int sz = 1 + rand() % 9;//MAX_MEM; // размер процесса (случ. величина)
          // проверяем страничную память , можно ли туда добавить сформированный процесс
        ch_m = findFreeSpace ( &(*hdPage), sz);
        if (ch_m > -1) {
           inserNth ( &(*hdPage), ch_m, nm, sz);
              // заносим процесс в страничную память
           addToPrList (&(*hdProc), nm, ch_m, sz);  // заносим новый записанный процесс в список действующих процессов
           print_list_page ( *hdPage);
         }

        else {
           printf("----------------   No more FREE SPACE! REMOVE smth. And TRY AGAIN.  ----------------- \n    ");
        }
 return ;
}
//------------------------------------------------------------
void print_list_page (page_t *head)
{
   page_t *current = head;
   int n = 0;

   if (head == NULL){
      cout<<"-------------------  Page' list is empty !  ----------------\n"<<endl;
      cout<<""<<endl;
   }
   else {
      cout<< "------------------  List of pages:  ------------------\n"<<endl;
      cout<<""<<endl;
      cout.width(5);
      cout<<" [#] ";
      cout.width(15);
      cout<<" [   name   ] ";
      cout<< "_________________________________________________ "<<endl;
      while (current !=NULL){
                 n++;
         //         attron (COLOR_PAIR(1));
                  cout.width(3);
                  cout<<n;
                  cout.width(13);
                  cout<< current->name;
                  cout.width(12);
                  cout<<"  - - - - - - - - - - - - - - - - - - - - - - - - - - - -     "<<endl;
                  current = current->next;
          }
  }
   return;
}

//------------------------------------------------------------
void inserNth (page_t ** head, int index, char *tname, int tsz) // вставка данных  в нужный элемент списка (страницу)
{
   int count = 0;
   if (index == 0) {
      count++;
      cout<<"Add process: "<<tname <<", size: "<<tsz<<endl;
      cout<<""<<endl;
      wrData( &(*head), tname, tsz);
   }
   else{
      page_t * current = *head;
      for (int i = 0; i<index-1; i++) {
         count++;
         current = current->next;
      }
      cout<<"Add process: "<<tname <<", size: "<<tsz<<endl;
      cout<<""<<endl;
      wrData( &(current->next), tname, tsz);
   }
  return;
}
//------------------------------------------------------------
void wrData( page_t ** head, char *nm, int sz)
{
   page_t * current = *head;

   for (int j = 0; j<sz ; j++){
       strcpy( current->name, nm);
       for (int i = 0; i < 256; i++)
          current->arr[i] = 1;
       current = current->next;
   }
   return;
}
//------------------------------------------------------------
int findFreeSpace (page_t ** head, int size) // возвращаем номер  страницы для начала записи
{
   int num =-1;
   int tmp = -1;
   char nm[30] ="";
   int count = 0;  // подсчет пустых страниц в блоке
   page_t *current = *head;
   if (current == NULL) return (num);

   do {
        tmp++;
        if (!strcmp(current->name, nm)){ // если встретилась пустая страница
           count = 0;      // начинаем считать пустые страницы идущие подряд
           num = tmp;  // номер первой пустой страницы в блоке с нужным числом пустых страниц
           while ((!strcmp(current->name, nm))&& (current->next !=NULL)){
              current = current->next;
              tmp++; //!
              count++;
            }
        }
        if (count > size + 1) {  // если найденный блок пустых страниц больше нужного размера
   //        cout <<"Free blocks: "<< count<<"/ Process Size : "<<size<<endl;
   //        cout<<""<<endl;
           return (num);
        }
       current = current->next;
   } while (current !=NULL);
 //   cout <<"Quantity of free pages:"<< tmp<<endl;
 //  cout<<""<<endl;
   return (-1);  // если пустого места нужного размера не найдено, а список пустых старниц закончился
}
//-------------------------------------------------------------
void addToPrList (proc_t **hdProc, char *name, int start_n, int size)
{
      int numsz = 0;
      numsz = size_list_proc (*hdProc);
      if (numsz == 0) {
         *hdProc = new proc_t;
         if (*hdProc == NULL){
             printf( "----------------  Process list creating is impossible!  ------------------\n");
             cout <<" "<<endl;
             return;
          }
         strcpy( (*hdProc)->name, name);
         (*hdProc)->n_start = start_n;
         (*hdProc)->size = size;
       }
      else {
           proc_t* new_proc = new proc_t;
           strcpy( new_proc->name, name);
           new_proc->next = *hdProc;
           new_proc->n_start = start_n;
           new_proc->size = size;
           *hdProc = new_proc;
      }
     return;
}
//-------------------------------------------------------------
void Rem_Proc (page_t **head, proc_t **hdpr)
{

      int sz = 0; //количество очищенных страниц
      int num_list = 0;

      num_list = size_list_proc (*hdpr); //количество загруженных в память процессов
      if (num_list == 0){
           cout <<"----------------  There are not any loading processes ! -----------------" <<endl;
           return;
      }
      else {

           print_list_proc (*hdpr);
           cout << "----------------   Choose the process for removing and write its name.  -----------------" << endl;
           cout<<""<<endl;
           cout<<"->";
           char nmrem [30];
           cin >> nmrem;
           sz = clear_name( &(*head), nmrem);  // возвращает число очищенных старниц
           if (sz == 0) {
              cout <<"----------------  Chosen process doesn't find!  -----------------"<<endl; 
              cout<<""<<endl;
              return;
           }
           int n = pop_prname( &(*hdpr), nmrem); // размер удаленного процесса
           cout<< "---------------  Prosess with size: "<<nmrem<< " size: "<<n<< "  is removed!  ----------------"<<endl;
           cout<<""<<endl;
           print_list_page (*head);
           return ;
    }
}
//----------------------------------------------------------------------
int Qst()
{
        mode_m mod;  //  режим работы МП
        printf ("\n");
        printf ("----------------  Choose the regime of Memory Manager running:  ---------------- \n");
        printf ("\n");
        printf ("1 - ADD new process ;  ");
        printf ("2 - REMOVE running process ;  ");
        printf ("3 - DEFRAGMENTATION ;   ");
        printf ("4 - EXIT.");
        printf ("\n");
        printf ("-> ");

        scanf ("%d", (int*) &mod);

        switch (mod){

               case(ADDPR): return 1;

               case(REMOVEPR): return 2;
               case(DEFRAG): return 3;
               case(EXT): return 4;

               default : printf ("----------------  Chosen mode is not realized!  ----------------\n"); return -1;
        };
}

//--------------------------------------------------------

int clear_name (page_t **hd, char *nm)
{ // очищаем в списке страниц страницы помеченные именем  nm

    int count = 0; // количество очищенных страниц для данного процесса

    if (*hd == 0) return count;   // если список пуст, выходим
     // если список не пуст
     page_t * current =*hd;
     cout<<"Process Name:  "<<nm<<" will be delete !"<<endl;
     cout <<""<<endl;
     while (current->next != NULL){
       if (!(strcmp( current->name, nm))) { // имя процесса совпало с записью на странице current->name

          strcpy( current->name, "");
          for (int i = 0; i < 256; i++)
            current->arr[i] = -1;
          count++;
       }
        current = current->next;
    }
    return (count);
}//-----------------------------------------------------------

int pop_prname( proc_t **head, char *name)
{

    int sz = 0;
    if (*head == 0){
       return (sz);
    } // если список пуст, выходим

    proc_t * current =*head; // если список не пуст
    if (!(strcmp(current->name, name))){
       sz = current->size;
       *head = current->next;
       delete current;
       return (sz);
    }
    proc_t * tmp = current->next;
    while (tmp ){
       if (!(strcmp( tmp->name, name))) {// имя процесса совпало с записью на странице tmp->name
          current->next = tmp->next;
          sz = tmp->size;
          delete tmp;
          return (sz);
       }
       current = tmp;
       tmp = tmp->next;
    }
  return (sz); // если в списке не встретилось нужное имя
}

//-------------------------------------------------------
void print_list_proc (proc_t *head)
{

   proc_t *current = head;
   int n = 0;
   int totaluse = 0;

   if (head == NULL)
          cout<<"----------------  Process' list is empty !  ----------------\n"<<endl;
   else {
          cout<< "List of running Process: \n"<<endl;
          cout<<""<<endl;
          cout.width(5);
          cout<<" [#] ";
          cout.width(15);
          cout<<" [   name   ] ";
          cout.width(10);
          cout<<"[  Size  ]   \n";
          cout<< "_________________________________________________ "<<endl;
          while (current !=NULL){
                 n++;
                  cout<<"  - - - - - - - - - - - - -  - - - - - - - - -     "<<endl;
                  cout.width(3);
                  cout<<n;
                  cout.width(13);
                  cout<< current->name;
                  cout.width(12);
                  cout<< current->size << endl;
                  totaluse = totaluse + current->size;
                  current = current->next;
          }
          cout<< "  - - - - - - - - - - - - - - - - - - - - - - -      "<<endl;
          cout<< "Total using memory is   ";
          cout<< totaluse << endl;
          cout<< "Free memory is   ";
          cout<< (MAX_MEM - totaluse) << endl;
   }

}
//----------------------------------------------------------------
int size_list (page_t *head)
{

   page_t *current = head;
   int n = 0;
   if (head == NULL){
      cout<<"-----------------  Pages' list is empty !  --------------------"<<endl;
      n = 0;
   }
   else {
      while (current !=NULL){
           n ++;
           current = current->next;
      }
   }
  return (n);
}
//----------------------------------------------------------------
int size_list_empty (page_t *head)
{

   page_t *current = head;
   int n = 0;
   if (head == NULL){
      cout<<"--------------------   Pages' list is empty !  ----------------------"<<endl;
      n = 0;
   }
   else {
      while (current !=NULL){
           if (!(strcmp(current->name , ""))) n ++;
           current = current->next;
      }
   }
  return (n);
}

//----------------------------------------------------------------
int size_list_proc (proc_t *head)
{

   proc_t *current = head;
   int n = 0;
   if (head == NULL){
      cout<<"---------------------  Process' list is empty !  --------------------"<<endl;
      n = 0;
   }
   else {
      while (current !=NULL){
           n ++;
           current = current->next;
      }
   }
  return (n);
}

//   ________________________________F I N A L_____________________________
