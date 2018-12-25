#include "pch.h"
#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include "windows.h"
#include <iostream>
using namespace std;


int main()
{
	TCHAR CatalogName[] = TEXT("E:\\Test1");
	TCHAR CatalogName1[] = TEXT("Catalog1");
	TCHAR CatalogName2[] = TEXT("Catalog2");
	TCHAR Buffer[256] = TEXT("Glad to hear from You\n");

	BOOL b = SetCurrentDirectory(CatalogName);
	CreateDirectory(CatalogName1, NULL);
	CreateDirectory(CatalogName2, NULL);
	//generic write - тип доступа к объекту
	//0 - режим разделяемого доступа к об, обознач что об не может быть исп неск программами
	//null - дескриптор безоп
	//созд нов файл иначе перезапис
	//file att - нет особенностей, -- archive,  encropted, hiden
	//
	HANDLE hOut = CreateFile(TEXT("E:\\Test1\\Catalog1\\file.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hOut, Buffer, 256, NULL, NULL);
	CloseHandle(hOut);

	//это если файл сущ будет заменён
	BOOL pr2 = 0;
	CopyFile(TEXT("E:\\Test1\\Catalog1\\file.txt"), TEXT("E:\\Test1\\Catalog2\\file.txt"), pr2);
	DeleteFile(TEXT("E:\\Test1\\Catalog1\\file.txt"));
	
	//переименовыв файл
	MoveFile(TEXT("E:\\Test1\\Catalog2\\file.txt"), TEXT("E:\\Test1\\Catalog2\\filenew.txt"));
	
	//открыть и прочесть
	auto hIn = CreateFile(TEXT("E:\\Test1\\Catalog2\\filenew.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	TCHAR Buffer2[256];
	DWORD dwNumberOfBytes;
	ReadFile(hIn, Buffer2, 256, &dwNumberOfBytes, NULL);
	wcout << "Read: " << Buffer2 << '\n';

	getchar();

	return 0;
}