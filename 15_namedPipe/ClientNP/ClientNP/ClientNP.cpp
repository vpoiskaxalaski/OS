// ClientNP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>



using namespace std;

string  GetErrorMsgText(int code)    // error text 
{
	char intStr[20];
	_itoa(code, intStr, 10);
	string str = string(intStr);
	return "**ERROR**Code: "+str;
};
string  SetPipeError(string msgText, int code)
{
	return  msgText + GetErrorMsgText(code);
};


int main()
{
	setlocale(0, "");
	HANDLE hPipe; // дескриптор канала
	try
	{
		if ((hPipe = CreateFile(L"\\\\.\\pipe\\Tube", 
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE, 
			NULL, OPEN_EXISTING, NULL, NULL)) == INVALID_HANDLE_VALUE)
			throw SetPipeError("create:", GetLastError());
		
		char ibuf[50], obuf[50] = "Hello from Client ";  //буфер вывода
		DWORD lobuf = 0, libuf = 0;                    //количество отправленных байт
		int n = 0, k = 0, c = 0;
		cout << "Введите количество сообщений ";
		cin >> n;

		while (k != n) {
			k = c + 1;
			_itoa(k, obuf + sizeof("Hello from Client ") - 1, 10);
			cout << obuf << endl;
			if (!WriteFile(hPipe, obuf, strlen(obuf) + 1, &lobuf, NULL))
				throw  SetPipeError("write:", GetLastError());

			if (!ReadFile(hPipe, ibuf, sizeof(ibuf), &libuf, NULL))
				throw  SetPipeError("read:", GetLastError());
			c = atoi(ibuf + sizeof("Hello from Client ") - 1);
		}
		if (!WriteFile(hPipe, " ", strlen(" "), &lobuf, NULL))
			throw  SetPipeError("write:", GetLastError());
		
		if (!CloseHandle(hPipe))
			throw SetPipeError("close:", GetLastError());

	}
	catch (string ErrorPipeText)
	{
		cout << endl << ErrorPipeText<<endl;
	}
	system("pause");
    return 0;
}

