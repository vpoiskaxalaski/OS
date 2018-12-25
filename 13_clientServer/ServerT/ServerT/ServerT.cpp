#include "stdafx.h"
#include "Winsock2.h"
#include <iostream>
#include <string>
#include <time.h>
#pragma comment (lib, "WS2_32.lib")

using namespace std;

string GetErrorMsgText(int code)
{
	string msgText;
	switch (code)
	{
	case WSAEINTR:				msgText = "Работа функции прервана";						break;
	case WSAEACCES:				msgText = "Разрешение отвергнуто";							break;
	case WSAEFAULT:				msgText = "Ошибочный адресс";								break;
	case WSAEINVAL:				msgText = "Ошибка в аргументе";								break;
	case WSAEMFILE:				msgText = "Слишком много файлов открыто";					break;
	case WSAEWOULDBLOCK:		msgText = "Ресурс временно недоступен";						break;
	case WSAEINPROGRESS:		msgText = "Операция в процессе развития";					break;
	case WSAEALREADY:			msgText = "Операция уже выполняется";						break;
	case WSAENOTSOCK:			msgText = "Сокет задан неправильно";						break;
	case WSAEDESTADDRREQ:		msgText = "Требуется адрес расположения";					break;
	case WSAEMSGSIZE:			msgText = "Сообщение слишком длинное";						break;
	case WSAEPROTOTYPE:			msgText = "Неправильный тип протокола для сокета";			break;
	case WSAENOPROTOOPT:		msgText = "Ошибка в опции протокола";						break;
	case WSAEPROTONOSUPPORT:	msgText = "Протокол не поддерживается";						break;
	case WSAESOCKTNOSUPPORT:	msgText = "Тип сокета не поддерживается";					break;
	case WSAEOPNOTSUPP:			msgText = "Операция не поддерживается";						break;
	case WSAEPFNOSUPPORT:		msgText = "Тип протоколов не поддерживается";				break;
	case WSAEAFNOSUPPORT:		msgText = "Тип адресов не поддерживается протоколом";		break;
	case WSAEADDRINUSE:			msgText = "Адрес уже используется";							break;
	case WSAEADDRNOTAVAIL:		msgText = "Запрошенный адрес не может быть использован";	break;
	case WSAENETDOWN:			msgText = "Сеть отключена";									break;
	case WSAENETUNREACH:		msgText = "Сеть недостяжима";								break;
	case WSAENETRESET:			msgText = "Сеть разорвала соединение";						break;
	case WSAECONNABORTED:		msgText = "Программный оказ связи";							break;
	case WSAECONNRESET:			msgText = "Связь востановлена";								break;
	case WSAENOBUFS:			msgText = "Не хватает памяти для буферов";					break;
	case WSAEISCONN:			msgText = "Сокет уже подключен";							break;
	case WSAENOTCONN:			msgText = "Сокет не подключен";								break;
	case WSAESHUTDOWN:			msgText = "Нельзя вылонить send() сокет завершил работу";	break;
	case WSAETIMEDOUT:			msgText = "Закончился отведённый интервал времени";			break;
	case WSAECONNREFUSED:		msgText = "Соединение отклонено";							break;
	case WSAEHOSTDOWN:			msgText = "Хост в неработоспособном состаянии";				break;
	case WSAEHOSTUNREACH:		msgText = "Нет маршрута для хоста";							break;
	case WSAEPROCLIM:			msgText = "Слишком много процессов";						break;
	case WSASYSNOTREADY:		msgText = "Сеть не досткпна";								break;
	case WSAVERNOTSUPPORTED:	msgText = "Данная версия не доступна";						break;
	case WSANOTINITIALISED:		msgText = "Не выполнена инициализация WS2_32.DLL";			break;
	case WSAEDISCON:			msgText = "Выполняется отключение";							break;
	case WSATYPE_NOT_FOUND:		msgText = "Класс не найден";								break;
	case WSAHOST_NOT_FOUND:		msgText = "Хост не найден";									break;
	case WSATRY_AGAIN:			msgText = "Неавторизованный хост не найден";				break;
	case WSANO_RECOVERY:		msgText = "Неопределённая ошибка";							break;
	case WSANO_DATA:			msgText = "Нет записи запрошенного типа";					break;
	case WSA_INVALID_HANDLE:	msgText = "Указанный дискриптор события с ошибкой";			break;
	case WSA_INVALID_PARAMETER:	msgText = "Один или более параметров с ошибкой";			break;
	case WSA_IO_INCOMPLETE:		msgText = "Обьект ввода-вывода не в сигнальном состоянии";	break;
	case WSA_IO_PENDING:		msgText = "Операция завершиться позже";						break;
	case WSA_NOT_ENOUGH_MEMORY: msgText = "Не достаточно памяти";							break;
	case WSA_OPERATION_ABORTED: msgText = "Операция отвергнута";							break;
	case WSAEINVALIDPROCTABLE:	msgText = "Ошибочный сервис";								break;
	case WSAEINVALIDPROVIDER:	msgText = "Ошибка в версии сервиса";						break;
	case WSAEPROVIDERFAILEDINIT:msgText = "Невозможно инициализировать сервис";				break;
	case WSASYSCALLFAILURE:		msgText = "Аварийное завершение системного вызова";			break;
	default:					msgText = "***ERROR***";									break;
	}
	return msgText;
}

string SetErrorMsgText(string msgText, int code)
{
	return msgText + GetErrorMsgText(code);
}

int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	cout << "ServerT" << endl;

	SOCKET sS;
	WSADATA wsaData;	

GoTo:
	try
	{
		//Инициализировать
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		{
			throw SetErrorMsgText("Startup:", WSAGetLastError());
		}
		// (формат адреса, тип сокета, протокол)
		if ((sS = socket(AF_INET, SOCK_STREAM, NULL)) == INVALID_SOCKET)														
		{																	
			throw SetErrorMsgText("Socket_serv:", WSAGetLastError());
		}

		SOCKADDR_IN serv;													
		serv.sin_family = AF_INET; 
		serv.sin_port = htons(2000);
		serv.sin_addr.s_addr = inet_addr("127.0.0.1"); //INADDR_ANY;

		if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)		
		{
			throw SetErrorMsgText("Bind_serv: ", WSAGetLastError());
		}

		if (listen(sS, SOMAXCONN) == SOCKET_ERROR)							
		{
			throw SetErrorMsgText("Listen_serv: ", WSAGetLastError());
		}

		char ibuf[50],											
			obuf[50] = "server: принято ";						
		int libuf = 0,											
			lobuf = 0;											

		SOCKET cS;
		SOCKADDR_IN clnt;													
		memset(&clnt, 0, sizeof(clnt));										//очищаем параметры сокета
		int lclnt = sizeof(clnt);											//размер SOCKADDR_IN

		while (true)
		{
			int port = htons(clnt.sin_port); 

			if ((cS = accept(sS, (sockaddr*)&clnt, &lclnt)) == INVALID_SOCKET)
			{
				throw SetErrorMsgText("Accept: ", WSAGetLastError());
			}

			while (true)
			{
				if (recv(cS, ibuf, sizeof(ibuf), NULL) == SOCKET_ERROR)
				{
					throw SetErrorMsgText("Recv: ", WSAGetLastError());
				}

				if (!strcmp(ibuf, "Dispose")) 
					break;

				if (send(cS, ibuf, strlen(ibuf) + 1, NULL) == SOCKET_ERROR)
				{
					throw SetErrorMsgText("Send: ", WSAGetLastError());
				}
				cout << "Client (" << inet_ntoa(clnt.sin_addr) << ": " << port << "): " << ibuf << endl; //преобразование  в нормальноый ip from tcp/ip
			}
		}


		if (closesocket(cS) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("Close socket:", WSAGetLastError());
		}

		if (closesocket(sS) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("Close socket_serv:", WSAGetLastError());
		}

		if (WSACleanup() == SOCKET_ERROR)
		{
			throw SetErrorMsgText("Cleanup: ", WSAGetLastError());
		}
	}
	catch (string errorMsgText)
	{
		cout << endl << errorMsgText;

		if (closesocket(sS) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("closesocket:", WSAGetLastError());
		}
		goto GoTo;
	}
	return 0;
}

