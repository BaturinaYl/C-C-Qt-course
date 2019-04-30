//Home Work #5
//Baturina Yelena
// Analysation of Symbol Frequancy 

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
FILE *f;
char *flname;
char  buff;
int arrch[70]={0}; //общее кол-во символов в ASCI таблице, за искл. первых 32 непечатных символов, 26 прописные
int chcode;  //код символа 
int  n = 0;
//	printf ("Введите имя файла : \n");
//	scanf ("%p\n", &flname);

 	if (!(f = fopen("MyFILE.txt", "r+t")))
	{
	   printf("Невозможно открыть файл или он не существует!\n");
	}
	else{
	while(!feof(f)) {
			fscanf(f, "%c", &buff);
			chcode = (int) buff;
			if ((chcode > 96) && (chcode < 123)) //если символ - прописная лат. буква
				 chcode  = (chcode -32) - 32; //делаем из нее заглавную лат. букву
			else  chcode = chcode - 32;
			arrch[chcode]+=1;
			}
	   }

	fclose(f);

	printf("Анализ частотности символов ASCI для файла %s: \n", flname);
	for (int i=0; i<65; i++)
	   {
             n = arrch[i];
	    if (n!=0) 
  	       printf ("Символ : %c встретился %d раз; \n", (char)(i+32), n);
	    }
	for (int i=65;i<70; i++)
		{
		n = arrch[i];
		if (n!=0)
		printf ("Символ : %c встретился %d раз; \n", (char)(i+58), n);
		}
	printf ("Вот так !!!\n");
return 0;
}
