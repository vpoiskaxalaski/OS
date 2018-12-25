// Лаба6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tasks.h"

bool IsProcessRun(WCHAR* buf)
{
	bool RUN;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);
	if (AreEqual(pe.szExeFile, buf))
	{
		RUN = true;
		return RUN;
	}
	else
		RUN = false;
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

int _tmain(int argc, _TCHAR* argv[])
{
	//Task1();
	//Task2();
	//Task3();
	//Task4();
	//Task5();
	//Task6();

	
	//отыскивает exe-файл по части имени
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	TCHAR directory[] = TEXT("E:\\University\\3k1s\\OS\\lab04\\4\\ConsoleApplication1\\Debug");
	TCHAR filesearch[] = TEXT("E:\\University\\3k1s\\OS\\lab04\\4\\ConsoleApplication1\\Debug\\Console*.exe");
	
	// Find the first file in the directory.
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
		
		//запускает его на выполнение
		STARTUPINFO cif;
		ZeroMemory(&cif, sizeof(STARTUPINFO));
		PROCESS_INFORMATION pi;

		if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
			std::wcout << "Error " << '\n';
		FindClose(hFind);
	}

	WCHAR param[260] = L"";
	wcscat(param, FindFileData.cFileName);

	//проверяет, выполняется ли он
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	if (IsProcessRun(param))
	{
		std::wcout << "Running" << '\n';
	}
	else
	{
		std::wcout << "NOT Running" << '\n';
	}
	HANDLE hProcess = GetCurrentProcess(); //получаем pID консольного приложен.
										   // Get the process name.
	if (NULL != hProcess)
	{
		Sleep(2000);
		BOOL result = TerminateProcess(hProcess, 0);
		CloseHandle(hProcess);
	}
	else
	{
		std::wcout << "Error when terminating " << '\n';
	}
	
	getchar();
}

