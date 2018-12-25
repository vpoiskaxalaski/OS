// Task_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "string.h"

DWORD WINAPI myThread(void* lpPar)
{
	TCHAR* b = new TCHAR();
	b = (TCHAR*)lpPar;

	HANDLE hOut;
	DWORD dwBytes;
	FILE *fp;

	TCHAR stdPath[50] = TEXT("E:\\University\\3k1s\\OS\\Lab_8\\myfile.txt");
	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("ERROR WRITING FILE");
		return 2;
	}
	else
	{
		WriteFile(hOut, b, 256, &dwBytes, NULL);
		printf("Thread Written");
		CloseHandle(hOut);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int z = 0;

	DWORD myThreadID;
	TCHAR Buff[256] = TEXT("HELLO! Students");
	HANDLE myHandle = CreateThread(0, 0, myThread, (void*)Buff, CREATE_SUSPENDED, &myThreadID);
	BOOL b = SetThreadPriorityBoost(myHandle, false); 

	if (b)
	{
		SetThreadPriority(myHandle, THREAD_PRIORITY_HIGHEST);
	}
	ResumeThread(myHandle);
	Sleep(2000);
	printf("\n Main Process");

	TerminateThread(myHandle, 0);

	getchar();
	return 0;
}


