// HomeWork #2
//Baturina Yelena
// Write in file

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	setlocale (LC_ALL,"ru_RU.utf8");
	wchar_t fam[20];
        wchar_t name[20];
	wchar_t sername[20];

	FILE *f;

	wprintf (L"Введите ваши фамилию, имя, отчество :\n");

	wscanf (L"%ls%ls%ls",&fam, &name, &sername);

	wprintf (L"ФИО: %ls,%ls,%ls\n", fam, name, sername);

	if(!(f = fopen("HWFILE.txt", "w+t")))
	{
		printf("Невозможно создать файл\n"); return 0;
	}

	fwprintf(f,L"%ls\n",&fam);
	fwprintf(f, L"%ls\n",&name);
	fwprintf(f, L"%ls\n",&sername);

	fclose(f);
return 0;

}
