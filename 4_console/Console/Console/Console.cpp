
#include "pch.h"
#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h> 




const WORD colors[] =
{
	0x4F, 0xCF, 0xEF, 0xAF, 0xBF, 0x9E, 0x5F, 0x0F
};

std::string rainbow[] = { "каждый", "охотник", "желает", "знать", "где", "сидит", "фазан" };

int main()
{
	setlocale(LC_ALL, "rus");

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	DWORD l;
	COORD pos = { 0, 0 };
	COORD pos1 = { 0, 0 };
	WORD   index = 0;

	
	while (index < 7)
	{
		FillConsoleOutputAttribute(hstdout, colors[index], 80, pos1, &l);
		SetConsoleTextAttribute(hstdout, colors[index]);
		SetConsoleCursorPosition(hstdout, pos);		
		
		std::cout << rainbow[index]<< std::endl;
	
		const char *p1 =  rainbow[index].c_str();
		int slen = strlen(p1);

		pos.X += slen;
		pos.Y += 1;

		pos1.Y += 1;

		index++;
	}
	SetConsoleTextAttribute(hstdout, colors[index]);
	system("pause");
}

