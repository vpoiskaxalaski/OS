// Example_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#pragma warning (disable: 4996)
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

int  main()
{
	int i, n, *massiv;    //объявление указателя на массив

	system("mode con cols=60 lines=10");
	system("title String");
	setlocale(LC_ALL, "RUS");
	system("cls");
	SetConsoleTextAttribute(H, 11);

	cout << "Введите размер массива\n";
	cin >> n;//ввод размера массива

	massiv = (int*)malloc(n * sizeof(int)); //выделение динам.памяти

	if (!massiv)                              //проверка факта выделения памяти

	{
		cout << "\nНедостаточно памяти";

		cout << "\nНажмите любую клавишу для завершения программы ...\n";
		getch();

		return 0;
	}

	cout << "Введите (целочисленный) массив, нажимая ENTER после каждого элемента\n";

	for (i = 0; i<n; i++)

		cin >> massiv[i];       //ввод массива


	cout << "\n massiv\n";
	for (i = 0; i<n; i++)cout << ' ' << massiv[i];       //вывод массива

	free(massiv);
	cout << "\nДо свидания!\n\n";
	getch();
	return 0;
	//освобождение памяти
}
