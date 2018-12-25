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
	DWORD wb;                       

	try
	{
		if ((hM = CreateFile(TEXT("\\\\.\\mailslot\\Box"),
			GENERIC_WRITE, //������ ��� ������
			FILE_SHARE_READ, //����� ����������� �������������
			NULL, //�������� ������������
			OPEN_EXISTING, //���� ��������
			NULL, //����� � ��������
			NULL // �������������� ��������
		)) == INVALID_HANDLE_VALUE)
		{
			if (GetLastError() == 2)
			{
				throw std::string("�������� ������ �� ������!");
			}
			else
			{
				throw SetMaislotError("CreateFileError: ", GetLastError());
			}
		}
		clock_t start = clock();
		for (int i = 0; i < 1000; i++)
		{
			char wbuf[30];
			_itoa_s(i, wbuf, 10);
			if (!WriteFile(hM, wbuf, sizeof(wbuf), &wb, NULL))
			{
				throw SetMaislotError("ReadFileError: ", GetLastError());
			}
		}
		clock_t finish = clock();
		std::cout << std::endl << "����������� ����� �� ��������: " << finish - start;

		CloseHandle(hM);
	}
	catch (std::string messageError)
	{
		std::cout << std::endl << messageError;
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}