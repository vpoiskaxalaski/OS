#pragma once
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)

void Task1(); //����� ����� (-��) �� �����

void Task2(); //��������� ��������� ��������� ��������� ������� ���������� ����� CREATEPROCESS (��������� mspaint.exe).

void Task3(); //����� ���� EXE � ��������� ��� �� ����������.

void Task4(); //������ �������� � ������� �� ������� ��� ���������� ������ (���������) � ��������� ����������� ���� ����� 5 �������.

void Task5(); //����� ���� ���� ���������� ���������

void Task6(); //���������, ����������� �� �������
bool AreEqual(const TCHAR *a, const TCHAR *b);
bool IsProcessRun();