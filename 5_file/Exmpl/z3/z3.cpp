// z3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "windows.h"


//3.	В первом каталоге создать текстовый файл и записать в него текст.
int main()
{
	std::ofstream out; 
	out.open("E:\\University\\3k1s\\OS\\lab04\\cat1\\hello.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out << "Hello World!" << std::endl;
	}

	std::cout << "End of program" << std::endl;
}
