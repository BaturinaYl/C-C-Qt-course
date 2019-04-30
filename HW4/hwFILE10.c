// HomeWork #4
//Baturina Yelena
// Write 1000 numbers in 10 files

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{

        FILE *f;
	char str[10];
	char name[10]="";
	char s[10]="HWFILE";
	int  k;

	srand(time(NULL));
	for (int num=1; num<11; num++){	

        	printf ("Попытка создания файла № %d :\n", num);
		sprintf(str,"%i",num);
		sprintf(name,"%s",s);
		strcat(name,str);


	        if(!(f = fopen(strcat(name,".txt"), "w+t")))
 	       {
                printf("Невозможно создать файл %d\n",num); return 0;
        	}
		for (int i=0; i<1000; i++){

			k = 0+rand()%20;
		        fprintf(f,"%d, ",k);
	           }

        fclose(f);
}
return 0;

}

