// ServerNP.cpp: определяет точку входа для консольного приложения.
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
	HANDLE hPipe; 
	try
	{
		if ((hPipe = CreateNamedPipe(L"\\\\.\\pipe\\Tube",
			PIPE_ACCESS_DUPLEX,           
			PIPE_TYPE_MESSAGE| PIPE_WAIT,
			1, NULL, NULL,                
			INFINITE, NULL)) == INVALID_HANDLE_VALUE)
			throw SetPipeError("create:", GetLastError());

		for (;;) {
			if (!ConnectNamedPipe(hPipe, NULL))             
				throw SetPipeError("connect:", GetLastError());		
			cout << "Клиент подключён" << endl;
			char ibuf[50];                
			DWORD libuf = 0, lobuf = 0;              
			clock_t start = clock();
			for (;;) {
				if (!ReadFile(hPipe, ibuf, sizeof(ibuf),&libuf, NULL))
					throw  SetPipeError("read:", GetLastError());
				if (libuf == 1) break;
				cout << ibuf << endl;
				if (!WriteFile(hPipe, ibuf, strlen(ibuf) + 1,&lobuf, NULL))
					throw  SetPipeError("write:", GetLastError());
			}
			clock_t finish = clock();
			cout << "Затраченное время: " << ((float)(finish - start)) / CLOCKS_PER_SEC << " секунд" << endl;
			if (!DisconnectNamedPipe(hPipe))
				throw SetPipeError("Disconnect:", GetLastError());
		}

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

