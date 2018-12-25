#include "stdafx.h"
#include "Threads.h"
int z = 0;

void mainThread()
{
	int z1 = 0;
	int z2 = 21;

	unsigned int myCounter = 0;
	DWORD myThreadID1;
	HANDLE myHandle1 = CreateThread(0, 0, myThread1, (void*)&z1, 0, &myThreadID1);
	DWORD myThreadID2;
	HANDLE myHandle2 = CreateThread(0, 0, myThread2, (void*)&z2, 0, &myThreadID2);

	Sleep(5000);
	printf("\n Main Process sagt");
	TerminateThread(myHandle1, 0);
	TerminateThread(myHandle2, 0);

	getchar();

}

DWORD WINAPI myThread1(void* lpParameter)
{

	int* counterp = new int();
	counterp = (int*)lpParameter;
	int counter = *counterp;

	while (counter<20)
	{
		Sleep(1000);
		counter++;
		printf("\n Counter= %d", counter);
	}

	return 0;
}

DWORD WINAPI myThread2(void* lpParameter)
{

	int* counterp = new int();
	counterp = (int*)lpParameter;
	int counter = *counterp;

	while (counter>0)
	{
		Sleep(200);
		counter--;
		printf("\n Counter= %d", counter);
	}

	return 0;
}

DWORD WINAPI writeThread(void * lpParameter)
{
	HANDLE* h = new HANDLE();
	h = (HANDLE*)lpParameter;
	HANDLE hh = *h;
	while (true)
	{
		z++;
		ResumeThread(hh);
		Sleep(299);
		SuspendThread(hh);
	}

	return 0;
}

DWORD WINAPI readThread(void * lpParameter)
{
	while (true)
	{
		printf("\n Counter= %d", z);
		Sleep(300);
	}
	return 0;
}

