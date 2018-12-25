// Лаба7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Threads.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	int x = 0, y = 20;
	DWORD myThreadID1;
	DWORD myThreadID2;

	HANDLE myHandle2 = CreateThread(0, 0, myThread1, (void*)&x, 0, &myThreadID2);
	HANDLE myHandle = CreateThread(0, 0, myThread2, (void*)&y, 0, &myThreadID1);


	Sleep(15000);
	printf("\n Main Process sagt");
	TerminateThread(myHandle2, 0);
	TerminateThread(myHandle, 0);
	*/
	
	int x = 0;
	DWORD myThreadID1;
	HANDLE myHandle;
	DWORD myThreadID2;
	myHandle = CreateThread(0, //может ли создаваемый поток быть унаследован дочерним процессом
							0, //размер стека в байтах. Если передать 0, то будет использоваться значение по-умолчанию (1 мегабайт).
							readThread,//адрес функции, которая будет выполняться потоком
							(void*)&x,//указатель на переменную, которая будет передана в поток.
							CREATE_SUSPENDED, // 0 or CREATE_SUSPENDED or STACK_SIZE_PARAM_IS_A_RESERVATION
							&myThreadID1 //указатель на переменную, куда будет сохранён идентификатор потока. Нам идентификатор не нужен, передаём NULL.
	);
	HANDLE myHandle2 = CreateThread(0, 0, writeThread, (void*)&myHandle, 0, &myThreadID2);	


	Sleep(15000);
	printf("\n Main Process sagt");
	TerminateThread(myHandle2, 0);
	TerminateThread(myHandle, 0);
	


	getchar();

	return 0;
}


