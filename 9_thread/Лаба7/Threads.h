#pragma once
#include <windows.h>
#include <iostream>
#include "string.h" 
void mainThread();
DWORD WINAPI myThread1(void* lpParameter);
DWORD WINAPI myThread2(void* lpParameter);

DWORD WINAPI writeThread(void* lpParameter);
DWORD WINAPI readThread(void* lpParameter);

