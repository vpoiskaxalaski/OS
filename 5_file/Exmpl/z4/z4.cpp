#include "pch.h"
#include <iostream>
#include <fstream>
#include "windows.h"

using std::ios_base;

const static int BUF_SIZE = 4096;

//4.	Скопировать созданный файл из первого каталога во второй.
int main()
{
	std::ifstream in("E:\\University\\3k1s\\OS\\lab04\\cat1\\hello.txt");// , ios_base::in | ios_base::binary);
	std::ofstream out("E:\\University\\3k1s\\OS\\lab04\\cat2\\hello.txt");// , ios_base::out | ios_base::binary);

	char buf[BUF_SIZE];

	do {
		in.read(&buf[0], BUF_SIZE);      // Считать максимум n байт в буфер,
		out.write(&buf[0], in.gcount()); // затем записать содержимое буфера
	} while (in.gcount() > 0);        // в поток вывода.

	in.close();
	out.close();
}

