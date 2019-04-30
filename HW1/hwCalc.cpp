//Homework #1
//Baturina Yelena
// simple calculater


#include <iostream>
using namespace std;
int main()
{

float a,b,result;
int prizn =1;
char deistv;

do
  {

   cout<<"\n Введите число А , знак операции, число В:";
   cin>>a>>deistv>>b;

    } while ((b==0) && ((deistv=='/') || (deistv ==':')));

switch (deistv)
   {
     case '+':        result=a+b;     break;
     case '-':        result=a-b;     break;
     case '*':        result=a*b;     break;
     case '/':
     case ':':        result=a/b;     break;
     default: cout<<"\n Действие не определено   \n  ";
              prizn=0 ;               break;
  
    }
if  (prizn)   cout<<"\n Результат: "<< result<<"\n";
 return 0;

}

