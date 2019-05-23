#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//----------------------------------------------------------------
    class Item {
       protected:

          string m_name;
          int m_price;
          int m_weight;
    public:
         Item (string nameI="", int priceI=0, int weightI=0):
               m_name(nameI), m_price(priceI), m_weight(weightI)
        {

          }
          string getname() const{return m_name;}
          int    getprice() const{return m_price;}
          int    getweight() const {return m_weight;}

          void print_list_item(){
                              cout<< " "<< getname() <<" "<< getprice() <<" "<< getweight() <<" "<<endl;
          }


    };
//-----------------------------------------------------------------
    class Buy : public Item {
     protected:

           int m_qnt;
      public:
           Buy (int q = 0, string nameI="", int priceI = 0, int weightI = 0):
                    Item ( nameI, priceI, weightI), m_qnt(q) 
           {         // список покупок
             }


          int getqnt() const {return m_qnt;}
          void print_list_buy(){

              cout<<"  "<< getname()<<"  "<< getprice()<<"  "<< getweight() <<" "<< getqnt()<<endl;
          }

     };
//-----------------------------------------------------------------

   class Check : public Buy {

  public:
    Check (int q=0, string nameI="", int priceI=0, int weightI=0) : Buy(q, nameI, priceI, weightI)
         {
           }
    int Sum (int *s){

     int res= 0;
     res = *s;
     res = res + (getprice() *getqnt());

    return res;
    }
     };

//----------------------------------------------------------------
int main(){
      int n = 1;
      string nm;
      int pr,wt;  
      int ex = 0;
      string ans=" ";
      int numProd, numQ;

// создаем и инициализируем список товаров
       Item itm[4] = {
       Item ("Apple",20,1),
       Item ("Pear",30,1),
       Item ("Cherry",10,1),
       Item ("Cucumber",15,1)};


       cout<<"Для покупки Выберите НОМЕР продукта из списка: ( Продукт / Цена / Вес )"<<endl;
       for (int i = 0; i < 4; i++)
            {cout<< i+1<<".";
            itm[i].print_list_item();
            }
       cout <<""<<endl;
       cin >> numProd;
       cout <<" Введите количество выбранного продукта: "<<endl;
       cin >> numQ;

       Buy *buyIt = new Buy [n];
       buyIt[n-1] = {Buy(numQ, itm[numProd-1].getname(), itm[numProd-1].getprice(), itm[numProd-1].getweight())};
       cout << "Сейчас в Вашей корзине: ( Продукт / Цена / Вес / Кол-во)"<<endl;
       for (int j = 0; j < n; j++){
           buyIt[j].print_list_buy();
       }

       while (!ex) {
            cout<< "Хотите продолжить покупки? (Y/N)"<<endl;
            cin >> ans;
            if (ans == "N") {
               ex = 1; cout <<"Заходите еще!"<<endl; break;
            }
            cout<< "Для покупки Выберите НОМЕР продукта из списка: "<<endl;
            cin >> numProd;
            cout <<"Введите количество выбранного продукта:"<<endl;
            cin >> numQ;

            n++;
            Buy *tmpIt = new Buy [n]; // динамический массив: покупки
            for (int i = 0; i < (n-1); i++){
               tmpIt[i] = buyIt[i];}
            delete[] buyIt;
            buyIt = tmpIt;
            buyIt[n-1] = {Buy(numQ, itm[numProd-1].getname(), itm[numProd-1].getprice(), itm[numProd-1].getweight())};
            for (int j =0; j<n; j++){
                buyIt[j].print_list_buy();
            };

       } ;
    Check sumCheck; // объявляем объект чек
    int sum = 0;
    int * psum = &sum;
    cout <<"Итак сегодня вы купили : ( Продукт / Цена / Вес / Кол-во)"<<endl;
    for( int k = 0; k < n; k++)
      {
       sumCheck = {Check(buyIt[k].getqnt(), buyIt[k].getname(), buyIt[k].getprice(), buyIt[k].getweight())};
       sumCheck.print_list_buy();
       sum = sumCheck.Sum(psum);

      }
     cout<<"Ваш шоппинг обошелся Вам в :"<<sum<<" руб "<<endl;
     
     delete[] buyIt;
return 0;
}
