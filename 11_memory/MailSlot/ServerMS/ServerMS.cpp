#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
	

std::string SetMaislotError(std::string msgText, int code)
{
	char intStr[20];
	_itoa_s(code, intStr, 10);
	std::string str = std::string(intStr);

	return msgText + " " + str;
};

int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");

	HANDLE hM;						
	DWORD rb;                       
	char rbuf[100];                 
	try
	{
		if ((hM = CreateMailslot(TEXT("\\\\.\\mailslot\\Box"),
				500, //максимальная длина сообщения
				180 * 1000,//интервалы ожидания
				NULL //атрибуты безопасности
		)) == INVALID_HANDLE_VALUE)
		{
			throw SetMaislotError("CreateMailslotError: ", GetLastError());
		}			

		for (;;)
		{
			if (!ReadFile(hM, rbuf, sizeof(rbuf), &rb, NULL))
			{
				if (GetLastError() == 121)
				{
					throw std::string("Время ожидания сервера истекло!");
				}
				else
				{
					throw  SetMaislotError("ReadFileError: ", GetLastError());
				}
			}
			std::cout << std::endl << "Принятое сообщение: " << rbuf;
		}

		CloseHandle(hM);
	}
	catch(std::string messageError)
	{
		std::cout << std::endl << messageError;
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}