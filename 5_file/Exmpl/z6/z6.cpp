

#include "pch.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include <string>

//6.	Переименовать файл во втором каталоге и прочитать его содержимое.
int main()
{
	if (rename("E:\\University\\3k1s\\OS\\lab04\\cat2\\hello.txt", "E:\\University\\3k1s\\OS\\lab04\\cat2\\Myhello.txt") != 0)	{
		printf("Rename Error");
	}
	else {
		std::ifstream file("E:\\University\\3k1s\\OS\\lab04\\cat2\\Myhello.txt");
		std::string str;
		while (getline(file, str)) //getline(istream & is, string &s,char c='\n'),читает из потока is, в строку s пока 
		{
			std::cout << str << std::endl;
		}
	}
		
	return 0;
}

