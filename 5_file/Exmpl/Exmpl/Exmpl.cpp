
#include "pch.h"





int main()
{
	//===========ЧТЕНИЕ============
	FILE* fp;
	char str[80];
	if ((fp = fopen("E:\\University\\3k1s\\OS\\lab01\\studentList.txt", "rt")) == NULL)
	{
		puts("Opening failed");
		getchar();
	}
	else
	{
		fgets(str, 79, fp);
		printf("read: %s", str);
		int z = fclose(fp);
		getchar();
	}

	//===============запись с последующим чтением из текстового файла=========
	FILE* fp;
	char str[80] = "glad to hear from you";
	if ((fp = fopen("E:\\University\\3k1s\\OS\\lab04\\studentList.txt", "wt")) == NULL)
	{
		puts("Opening failed");
		getchar();
	}
	else
	{
		fputs(str, fp);
		int z = fclose(fp);

		fp = fopen("E:\\University\\3k1s\\OS\\lab04\\studentList.txt", "rt");
		fgets(str, 79, fp);
		puts(str);
		z = fclose(fp);
		getchar();
	}

	//============Создание файла средствами API WINDOWS==============
	TCHAR Buffer[256] = TEXT("Glad to hear from You");
	DWORD nLenCurDir;
	HANDLE hOut;

	FILE* fp;


	TCHAR stdPath[30] = TEXT("E:\\University\\my_api2.txt");

	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();

		return 2;
	}

	else
	{
		//nLenCurDir = GetCurrentDirectory(256, Buffer);
		// WriteFile(hOut, Buffer, 256, NULL, NULL );
		printf("Created");
		getchar();
		CloseHandle(hOut);
	}

	//=======создание файла средствами API+ запись в файл текста из буфера======
	TCHAR Buffer[256] = TEXT("Glad to hear from You\n");
	HANDLE hOut;
	DWORD dwNumberOfBytes;




	FILE* fp;


	TCHAR stdPath[30] = TEXT("e:\\University\\my_api2.txt");
	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();

		return 2;
	}

	else
	{
		WriteFile(hOut, Buffer, 256, &dwNumberOfBytes, NULL);
		printf("Created and Written!");
		getchar();
		CloseHandle(hOut);
	}

	//=======чтение ранее созданного файла средствами API+========
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	FILE* fp;


	TCHAR stdPath[30] = TEXT("e:\\University\\my_api2.txt");

	hIn = CreateFile(stdPath, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();

		return 2;
	}

	else
	{
		ReadFile(hIn, Buffer, 256, &dwNumberOfBytes, NULL);
		std::wcout << "Read: " << Buffer << '\n';
		getchar();
		CloseHandle(hIn);

	}

	//============КОПИРОВАНИЕ ФАЙЛА=============
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	FILE* fp;
	BOOL pr2 = 0;

	TCHAR stdPathA[30] = TEXT("e:\\University\\my_api2.txt");
	TCHAR stdPathB[30] = TEXT("e:\\University\\my_api3.txt");

	BOOL pr = CopyFile(stdPathA, stdPathB, pr2);
	if (pr)
	{
		printf("COPIED");
		getchar();

	}
	else
	{
		printf(" NOT COPIED");
		getchar();

	}

	//==============ПЕРЕМЕЩЕНИЕ ФАЙЛА==============
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	FILE* fp;
	BOOL pr2 = 0;

	TCHAR stdPathA[30] = TEXT("e:\\University\\my_api2.txt");
	TCHAR stdPathB[30] = TEXT("e:\\University\\my_api3.txt");

	BOOL pr = MoveFile(stdPathA, stdPathB);
	if (pr)
	{
		printf("MOVED");
		getchar();

	}
	else
	{
		printf(" NOT MOVED");
		getchar();

	}

	//=======================УДАЛЕНИЕ ФАЙЛА==========
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;

	TCHAR stdPathA[30] = TEXT("e:\\University\\my_api3.txt");


	BOOL pr = DeleteFile(stdPathA);
	if (pr)
	{
		printf("DELETED");
		getchar();

	}
	else
	{
		printf(" NOT DELETED");
		getchar();

	}

	//=============ОПРЕДЕЛЕНИЕ ТЕКУЩЕГО КАТАЛОГА===========
	TCHAR Buffer[256];
	DWORD dwResult = GetCurrentDirectory(256, Buffer);
	std::wcout << "Dir: " << Buffer << '\n';
	getchar();

	//==========СМЕНА КАТАЛОГА==============
	TCHAR Buffer[256];
	TCHAR Buffer2[] = TEXT("e:\\University");
	DWORD dwResult = GetCurrentDirectory(256, Buffer);
	std::wcout << "Dir: " << Buffer << '\n';


	BOOL b = SetCurrentDirectory(Buffer2);

	dwResult = GetCurrentDirectory(256, Buffer);
	std::wcout << "Dir: " << Buffer << '\n';
	getchar();

	//==============СОЗДАНИЕ КАТАЛОГА=========
	TCHAR Buffer[256];
	TCHAR Buffer2[] = TEXT("e:\\University");
	TCHAR Buffer3[] = TEXT("e:\\University");

	DWORD dwResult = GetCurrentDirectory(256, Buffer);
	std::wcout << "Dir: " << Buffer << '\n';


	BOOL b = SetCurrentDirectory(Buffer2);

	dwResult = GetCurrentDirectory(256, Buffer);
	std::wcout << "Dir: " << Buffer << '\n';



	if (CreateDirectory(Buffer3, NULL))
		std::wcout << "directory create" << '\n';
	else
		std::wcout << "error create directory" << '\n';
	getchar();


	return 0;

}

