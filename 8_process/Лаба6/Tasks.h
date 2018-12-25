#pragma once
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)

void Task1(); //ПОИСК ФАЙЛА (-ОВ) ПО ИМЕНИ

void Task2(); //Следующая небольшая программа запускает внешнее приложение через CREATEPROCESS (ЗАПУСКАЕМ mspaint.exe).

void Task3(); //НАЙТИ ФАЙЛ EXE И ЗАПУСТИТЬ ЕГО НА ВЫПОЛНЕНИЕ.

void Task4(); //Запуск процесса с выводом на консоль его системного номера (заголовка) с удалением консольного окна через 5 секунды.

void Task5(); //ВЫВОД ИМЕН ВСЕХ ЗАПУЩЕННЫХ ПРОЦЕССОВ

void Task6(); //ПРОВЕРЯЕТ, ВЫПОЛНЯЕТСЯ ЛИ ПРОЦЕСС
bool AreEqual(const TCHAR *a, const TCHAR *b);
bool IsProcessRun();