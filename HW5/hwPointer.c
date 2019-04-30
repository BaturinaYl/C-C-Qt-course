#include <stdio.h>
#include <stdlib.h>

int main()
{

int x, y;
printf("Введите х и у:\n");
scanf("%d %d", &x,&y);

int * p = &(x);
int * pn =&(y);
int sz;
sz = sizeof(pn);

printf ("Y:%d",*pn);

//else
printf("X:%d", *p);

printf("SZ:%d", sz);
/////////////////////////////////////
int n =99;
void *pVoid =&n;
float d =*(float*)pVoid;
printf("Surprise:%f\n",d);
/////////////////////////////////////
int Obj =4;
int * ob1 = &Obj;
int **ob2 =&ob1;
printf("Meaning of Obj = %d\n", * *ob2);
printf("Address of Obj= %p\n", ob1);
printf("Address of pointer ob1=%p\n",ob2);


return 0;

} 
