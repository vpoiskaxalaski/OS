#include "stdafx.h"
#include "Tasks.h"
#include <iostream>
#include <conio.h>

void Task1()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	TCHAR filesearch[] = TEXT("E:\\University\\3k1s\\OS\\lab01\\Лаб1*.doc");

	hFind = FindFirstFile(filesearch, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	}
	else
	{
		std::wcout << "Found: " << FindFileData.cFileName << '\n';

		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			std::wcout << "Found: " << FindFileData.cFileName << '\n';
		}
		FindClose(hFind);
	}
	getchar();
}

void Task2()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	printf("mspaint.exe");

	if (!(CreateProcess(NULL,  // имя исполняемого модуля
						buf, // Командная строка
						NULL, // Указатель на структуру SECURITY_ATTRIBUTES для нового приложения
						NULL, // Указатель на структуру SECURITY_ATTRIBUTES для первого потока созданного приложением
						FALSE,  // Флаг наследования текущего процесса
						0, // Флаги способов создания процесса
						NULL, // Указатель на блок среды
						NULL, // Текущий диск или каталог
						&cif, // Указатель нас структуру STARTUPINFO
						&pi// Указатель нас структуру PROCESS_INFORMATION 
	)))
		std::wcout << "Error " << '\n';
	getchar();
}

void Task3()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	TCHAR directory[] = TEXT("E:\\University\\3k1s\\OS\\lab06\\Win32Project3\\Debug\\");
	TCHAR filesearch[] = TEXT("E:\\University\\3k1s\\OS\\lab06\\Win32Project3\\Debug\\Win32Project3.exe");
	
	hFind = FindFirstFile(filesearch, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	}
	else
	{
		WCHAR buf[260] = L"";
		wcscat(buf, directory);
		wcscat(buf, FindFileData.cFileName);
		std::wcout << "Found: " << FindFileData.cFileName << '\n';
		STARTUPINFO cif;
		ZeroMemory(&cif, sizeof(STARTUPINFO));
		PROCESS_INFORMATION pi;
		if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
			std::wcout << "Error " << '\n';
		FindClose(hFind);
	}
	getchar();
}

void Task4()
{
	DWORD processID;
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	processID = CreateProcess(NULL, buf, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi);
	std::wcout << "Running  with PID:" << pi.dwProcessId << '\n';
	HANDLE hProcess = GetCurrentProcess(); //получаем pID консольного приложен.
     // Get the process name.
	if (NULL != hProcess)
	{
		Sleep(5000);
		BOOL result = TerminateProcess(hProcess, 0);
		CloseHandle(hProcess);
	}
	else
	{
		std::wcout << "Error when terminating " << '\n';
	}
	getchar();
}

void Task5()
{
	//Возвращает дескриптор указанного стандарта устройства
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	//Делает снимок указанных процессов, а также кучи модулей и потоков, используемых для этих процессов.
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, //Includes all processes in the system in the snapshot
		0 //The process identifier of the process to be included in the snapshot.
	);

	if (hSnapshot) {
		//This structure describes the processes residing in the system address space when a snapshot was taken.
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnapshot, &pe32)) {
			do {
				std::wcout << "Running  ProcName :" << pe32.szExeFile << '\n';
			} while (Process32Next(hSnapshot, &pe32));
		}
		CloseHandle(hSnapshot);
	}
	getchar();
}

bool AreEqual(const TCHAR *a, const TCHAR *b)
{
	while (*a == *b)
	{
		if (*a == _TEXT('\0'))return true;
		a++; b++;
	}
	return false;
}

bool IsProcessRun()
{
	bool RUN;
	TCHAR buf[] = TEXT("Лаба6.exe");
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);

	while (Process32Next(hSnapshot, &pe))
	{
		if (AreEqual(pe.szExeFile, buf))
		{
			RUN = true;
			return RUN;
		}
		else
			RUN = false;
	}
	return RUN;
}

void Task6()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	if (IsProcessRun())
	{
		std::wcout << "Running" << '\n';
	}
	else
	{
		std::wcout << "NOT Running" << '\n';
	}
	getchar();
}

