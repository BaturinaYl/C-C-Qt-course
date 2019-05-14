#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARR_MAX 10000  // размер массива
#define TEST_MAX 10   // количество испытаний

int    Min_sort( double *, int ); // поиск мин. результата
int    Max_sort( double *, int );  // поиск макс. результата
double Bubble_sort ( int *, int); // метод Пузырька
double MinSel_sort ( int *, int);  // метод мин.элемента
double Insert_sort ( int *, int); // метод вставка
double Hoare_sort (int *, int, int);  // метод Хора (qsort)

int main()
{
 clock_t time_start, time_end;

 int brrS[ARR_MAX];
 int mrrS[ARR_MAX];
 int irrS[ARR_MAX];
 int hrrS[ARR_MAX];

 double arrRes [4][TEST_MAX]; // массив результатов измерений времени работы методов
 double Res [4]; 
 double *pRes = Res;

 double bAVR = 0.0;
 double mAVR = 0.0;
 double iAVR = 0.0;
 double hAVR = 0.0;

 char st[20] = " ";
 char st1[20] =" ";
 int k, h;

   // создаем 4 идентичных массива 
for (int t = 0; t < TEST_MAX; t++){

      srand (time(NULL));
      for (int i = 0; i < ARR_MAX; i++){
	    brrS[i] = (0 + rand() % 100);
	    mrrS[i] = brrS[i];
	    irrS[i] = brrS[i];
	    hrrS[i] = brrS[i];
      }

  // вызываем методы, результаты заносим в массив, 
  //  подсчитываем суммарное время для рассчета среднего значения
	arrRes[0][t] = Bubble_sort (brrS, ARR_MAX); bAVR += arrRes[0][t]; 
	arrRes[1][t] = MinSel_sort (mrrS, ARR_MAX); mAVR += arrRes[1][t];
	arrRes[2][t] = Insert_sort (irrS, ARR_MAX); iAVR += arrRes[2][t];
	arrRes[3][t] = Hoare_sort (hrrS, 0, ARR_MAX-1); hAVR += arrRes[3][t];

 }

   // ноходим среднее значение для каждого метода, результат помещаем в массив 
	Res[0] = bAVR / TEST_MAX;
        Res[1] = mAVR / TEST_MAX;
        Res[2] = iAVR / TEST_MAX;
        Res[3] = hAVR / TEST_MAX;
	printf ("-------Результаты -----------\n");
        printf (" Cp.Вр. сортировки Bubble Sort : %f  сек. \n", Res[0]);
	printf (" Ср.Вр. сортировки Select Sort : %f  сек. \n", Res[1]);
	printf (" Ср.Вр. сортировки Insert Sort : %f  сек. \n", Res[2]);
	printf (" Ср.Вр. сортировки Hoar Sort : %f  сек. \n", Res[3]);
	printf ("\n");

	switch (Min_sort(pRes, 4))
        {
	        case(0): strcat(st, "Bubble Sort"); k = 0; break;
        	case(1): strcat(st, "Select Sort"); k = 1; break;
        	case(2): strcat(st, "Insert Sort "); k = 2; break;
        	case(3): strcat(st,"Hoar Sort ");    k = 3; break;
        }

	printf ("--Мин. время сортировки (cек.) : %s   %f \n", st, Res[k]);

	switch (Max_sort(pRes, 4))
        {
	        case(0): strcat(st1, "Bubble Sort"); h = 0; break;
        	case(1): strcat(st1, "Select Sort"); h = 1; break;
        	case(2): strcat(st1, "Insert Sort "); h = 2; break;
        	case(3): strcat(st1, "Hoar Sort ");    h = 3; break;
        }

	printf ("--Макс. время сортировки (cек.) : %s   %f \n", st1, Res[h]);
	printf ("\n");

return (0);
}
//--------------------------------------------
int Min_sort( double *arr, int n)
{

	double min = arr[0];
	int k = 0;
	for (int i = 1; i < n; i++)
	{
	  if (arr[i] < min) {
		min = arr[i];
		k = i;
	   }
	}
return (k);
}
//--------------------------------------------
int Max_sort( double *arr, int n)
{
 double max = arr[0];
        int k = 0;
        for (int i = 1; i < n; i++)
        {
          if (arr[i] > max) {
                max = arr[i];
                k = i;
           }
        }
return (k);
}
//--------------------------------------------
double Bubble_sort (int *arr, int n)
{
  int tmp;
   clock_t time_start, time_end; 
   time_start = clock();

	for (int i = 0; i < n; i++)

	    for (int j = 0; j < n-i-1; j++)

		if ( arr[j] > arr[j+1] )
		   {
		     tmp = arr[j];
		     arr[j] = arr[j+1];
		     arr[j+1] = tmp;
		     }
  time_end = clock() - time_start;
return ((double)time_end/CLOCKS_PER_SEC);
}
//----------------------------------------------
double MinSel_sort (int *arr, int n)
{
  clock_t time_start, time_end;  
  int k, tmp;
  int fl = 0;  // флаг  о том что  найден мин элемент и необх поменять его с первым элем
  time_start = clock();

	for (int i=0; i < n-1; i++) {
	    fl = 0;
	    k = i;	   // номер гипотетически мин элемента на первом шаге
	    tmp = arr[i];   // гипотетический мин элемент на первом шаге

	    for (int j = i+1; j < n; j++) {
		   if (arr[j] < tmp) {    // если найден другой мин элемент, то
			fl = 1;         // требуется перестановка
			k = j;           // номер нового мин элемента
			tmp = arr[j];     // меньший найденный элемент становится эталонлным для дальнейшего сравнения
		     }
		}
	    if (fl){ // флаг перестановки поднят
		arr[k] = arr[i]; // выполняем перестановку
		arr[i] = tmp ;
               }
	   }

time_end = clock() - time_start;
return ((double)time_end/CLOCKS_PER_SEC);

}
//----------------------------------------------
double Insert_sort (int *arr, int n)
{
  int tmp = 0;
  int key = 0;
  clock_t time_start, time_end;  
   time_start = clock();

	for (int i = 0; i < n-1; i++){
	    key = i + 1;
	    tmp = arr[key];
	    for (int j = i+1; j>0; j--) {
		if (tmp < arr[j-1]) {
			arr[j] = arr[j-1];
			key = j - 1;
		}
	    }
	    arr[key] = tmp;
 	  }

 time_end = clock() - time_start;
return ((double)time_end/CLOCKS_PER_SEC);

}
//------------------------------------------------
double Hoare_sort (int *arr, int left, int right)
{
  int tmp;
  clock_t time_start, time_end;  
  time_start = clock();
  int avr = arr[(left + right)/2];   // средний элемент 
  int i = left;
  int j = right;

	do {

		while (arr[i] < avr) i++;

		while (arr[j] > avr) j--;

		if (i <= j) {
		  tmp = arr[i];
		  arr[i] = arr[j];
		  arr[j] = tmp;
		  i++;
		  j--;
		  }
	    } while (i <= j);

	if (i < right)
	   Hoare_sort (arr, i, right);

	if (j > left)
	  Hoare_sort (arr, left, j);

 time_end = clock() - time_start;
return ((double)time_end/CLOCKS_PER_SEC);

}
//---------------------------------------------------------
