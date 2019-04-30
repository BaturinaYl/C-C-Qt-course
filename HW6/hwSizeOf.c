//Home Work #6
//Baturina Yelena
// SizeOf operator realization

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main ()
{

        FILE *f;
	char buff;
	long tmp=0;
	long fl;
	int   fn;


        if(!(f = fopen("MyFILE.txt", "r+t")))
        {
                printf("Невозможно открыть файл\n"); return 0;
        }
	fseek(f,0, SEEK_END);
        fn= ftell(f);
	fseek (f, 0, SEEK_SET);
	while(1)
	{
	fscanf(f, "%c", &buff);
	printf("%c , ",buff);

	if (feof(f)) break;
	tmp++;
        }

        fclose(f);

	printf ("sizeof(char) = %lu \n ", sizeof(buff));

	printf ( "Размер файла : %u \n" , fn);
	printf ("Размер считанных из файла данных : %lu \n", sizeof(buff)*tmp);
return 0;

}
