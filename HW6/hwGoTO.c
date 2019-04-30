//HomeWork #6
//Baturina Yelena
// GoTo operator realization

#include <stdio.h>
#include <stdlib.h>

int main ()
{
           int n=1;
           printf("Выводим в консоль цифры от 1 до 100 : \n");

           printf(" %d ",n);

   print : n++; printf(", %d ",n);

          if (n>99) goto ext;
          else goto print;


   ext : return 0;
}
