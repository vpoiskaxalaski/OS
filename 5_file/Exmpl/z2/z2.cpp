#include "pch.h"
#include <iostream>
#include <direct.h>
#include "windows.h"

void isCreate(int r) {
	if (r == 0)
		printf("Каталог создан\n");
	else
		printf("Не могу создать каталог\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int result;
	result = _mkdir("E:\\University\\3k1s\\OS\\lab04\\cat1");
	isCreate(result);
	
	result = _mkdir("E:\\University\\3k1s\\OS\\lab04\\cat2");
	isCreate(result);

	return 0;

}


