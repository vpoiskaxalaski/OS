
#include "pch.h"
#include <iostream>
#include <fstream>
#include "windows.h"

//5.	Удалить файл из первого каталога.
int main()
{
	if (remove("E:\\University\\3k1s\\OS\\lab04\\cat1\\hello.txt")) {
		printf("Error removing file");
		return 1;
	}
	else return 0;
}

