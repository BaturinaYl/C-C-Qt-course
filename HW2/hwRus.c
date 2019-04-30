//Home Work #2
//Baturina Yelena
// Russian Locale and numerical view

#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <stdio.h>

int main(void){
setlocale (LC_ALL, "ru_RU.utf8");
  wchar_t fam, name, sername;
wprintf(L"Введите Ваши инициалы ФИО:\n");
wscanf(L"%lc%lc%lc",&fam, &name, &sername);

wprintf(L"Буква русского языка: %lc имеет код: %ld \n", fam, (int)fam);
wprintf(L"Буква русского языка: %lc имеет код: %ld \n", name, (int)name);
wprintf(L"Буква русского языка: %lc имеет код: %ld \n", sername, (int)sername);
return  0;
}

