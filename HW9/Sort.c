#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARR_MAX 10000
#define TEST_MAX 10

double Bubble_sort ( int *, int);
double MinSel_sort ( int *, int);
double Insert_sort ( int *, int);
double Hoare_sort (int *, int, int);

int main()
{
 clock_t time_start, time_end;

 int brrS[ARR_MAX];
 int mrrS[ARR_MAX];
 int irrS[ARR_MAX];
 int hrrS[ARR_MAX];

 double arrRes [4][TEST_MAX + 1];

 double bAVR = 0.0;
 double mAVR = 0.0;
 double iAVR = 0.0;
 double hAVR = 0.0;

 for (int t = 0; t < TEST_MAX; t++){

      srand (time(NULL));
      for (int i = 0; i < ARR_MAX; i++){
	    brrS[i] = (0 + rand() % 100);
	    mrrS[i] = brrS[i];
	    irrS[i] = brrS[i];
	    hrrS[i] = brrS[i];
          }

	arrRes[0][t] = Bubble_sort (brrS, ARR_MAX); bAVR += arrRes[0][t]; 
	arrRes[1][t] = MinSel_sort (mrrS, ARR_MAX); mAVR += arrRes[1][t];
	arrRes[2][t] = Insert_sort (irrS, ARR_MAX); iAVR += arrRes[2][t];
	arrRes[3][t] = Hoare_sort (hrrS, 0, ARR_MAX-1); hAVR += arrRes[3][t];

   }

	arrRes[0][TEST_MAX] = bAVR / TEST_MAX;
        arrRes[1][TEST_MAX] = mAVR / TEST_MAX;
        arrRes[2][TEST_MAX] = iAVR / TEST_MAX;
        arrRes[3][TEST_MAX] = hAVR / TEST_MAX;


        printf (" Cp.Время выболнения сортировки методом Пузырька : %f  сек. \n", arrRes[0][TEST_MAX]);
	printf (" Ср.Время выболнения сортировки методом Мин.эллемента : %f  сек. \n", arrRes[1][TEST_MAX]);
	printf (" Ср.Время выболнения сортировки методом Вставки : %f  сек. \n", arrRes[2][TEST_MAX]);
	printf (" Ср.Время выболнения сортировки методом Хора : %f  сек. \n", arrRes[3][TEST_MAX]);

	
return (0);
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
