#include "stdafx.h" 
#include "Win32Project3.h" 
#include <string.h> 
#include <stdio.h> 
#include "Resource.h" 

#define ID_MY_BUTTON 123
#define IDC_MYICON 2 
#define IDD_WINCW_DIALOG 102 
#define IDD_ABOUTBOX 103 
#define IDS_APP_TITLE 103 
#define IDM_ABOUT 104 
#define IDM_EXIT 105 
#define IDS_HELLO 106 
#define IDI_WINCW 107 
#define IDI_SMALL 108 
#define IDC_WINCW 109 
#define IDC_WMCHAR 110 
#define IDR_MAINFRAME 128 
#define IDC_STATIC -1 

// Next default values for new objects 
// 
#ifdef APSTUDIO_INVOKED 
#ifndef APSTUDIO_READONLY_SYMBOLS 
#define _APS_NEXT_RESOURCE_VALUE 129 
#define _APS_NEXT_COMMAND_VALUE 32771 
#define _APS_NEXT_CONTROL_VALUE 1000 
#define _APS_NEXT_SYMED_VALUE 110 
#endif 
#endif 


#define MAX_LOADSTRING 100 

// Global Variables: 
HINSTANCE hInst; // current instance 
TCHAR szTitle[MAX_LOADSTRING]; // The title bar text 
TCHAR szWindowClass[MAX_LOADSTRING]; // the main window class name 
int colmn = 1, abc = 1;

// Forward declarations of functions included in this code module: 
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc1(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK myF(HWND, UINT, WPARAM, LPARAM); //объявим диалоговую процедуру в программе:myF
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hWnd1, hWnd2;
bool flag = false;

int APIENTRY _tWinMain( //Одной из первых задач функции _tWinMain является вызов метода регистрации оконного класса-MyRegisterClass(hInstance);                                            
	HINSTANCE hInstance,  // создаём дескриптор окна
    HINSTANCE hPrevInstance,  // описываем класс окна
	LPTSTR lpCmdLine,	
	int nCmdShow)  // возвращаем значение при неудаче или при выходе
				   //Параметр LPSTR  lpCmdLine, есть указатель на строку, содержащую аргументы, переданные программе при ее запуске из командной
	                                                                     //строки. Параметр          int nCmdShow  задает способ отображения окна.
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here. 
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings 
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT3, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT3));

	// Main message loop: 
	while (GetMessage(&msg, NULL, 0, 0))//В данном цикле считывается сообщение из очереди сообщений GetMessage.
	{   //Затем вызов TranslateAccelerator осуществляет трансляцию клавиш, нажатых на клавиатуре и отправляет сообщение msg в оконную процедуру 
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))                                                   //посредством DispatchMessage.
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



// 
// FUNCTION: MyRegisterClass() 
// 
// PURPOSE: Registers the window class. 
// 
// COMMENTS: 
// 
// This function and its usage are only necessary if you want this code 
// to be compatible with Win32 systems prior to the 'RegisterClassEx' 
// function that was added to Windows 95. It is important to call this function 
// so that the application will get 'well formed' small icons associated 
// with it. 
// 
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW; 
	wcex.lpfnWndProc = WndProc; 
	wcex.cbClsExtra = 0; 
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; 
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT3));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2); 
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT3);
	wcex.lpszClassName = szWindowClass; 
	//wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); 

	return RegisterClassEx(&wcex);
}

// 
// FUNCTION: InitInstance(HINSTANCE, int) 
// 
// PURPOSE: Saves instance handle and creates main window 
// 
// COMMENTS: 
// 
// In this function, we save the instance handle in a global variable and 
// create and display the main program window. 
// 
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) //осуществляет инициализацию приложения и формирует дескриптор приложения hInstance.
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable 

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, //Данная процедура  в свою очередь создает окно приложения путем вызова CreateWindow.
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// 
// FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM) 
// 
//

// 
// WM_COMMAND - process the application menu 
// WM_PAINT - Paint the main window 
// WM_DESTROY - post a quit message and return 
// 
// 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	int x=0, y=0;
	static int cx, cy;

	switch (message)
	{
	case WM_CREATE:
		hWnd1 = CreateWindowEx(NULL, L"BUTTON",	L"Butto1",	WS_TABSTOP | WS_VISIBLE |	WS_CHILD | BS_DEFPUSHBUTTON, 100, 100,
			100, 24,hWnd, HMENU(IDC_MyButton),	hInst,	NULL);
		ShowWindow(hWnd2, 1);

		hWnd2 = CreateWindowEx(NULL, L"BUTTON",	L"Button2",	WS_TABSTOP | WS_VISIBLE |	WS_CHILD | BS_DEFPUSHBUTTON,300, 300,
			100,24,	hWnd, HMENU(IDC_MyButton),	hInst,	NULL);
		ShowWindow(hWnd2, 1);
		break;
	case WM_MOUSEMOVE:
	{
		if (flag == false) {
			cx = LOWORD(lParam);
			cy = HIWORD(lParam);

			x = rand() % cx - 25;
			y = rand() % cy - 20;
			if (x > 0 && y > 0 && x<GetSystemMetrics(SM_CXSCREEN) && y < GetSystemMetrics(SM_CYSCREEN)) {
				MoveWindow(hWnd1, x, y, 100, 24, TRUE);
			}
		}
		
		break;
	}


	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		if (LOWORD(wParam) == IDC_MyButton &&
			HIWORD(wParam) == BN_CLICKED &&
			(HWND)lParam == hWnd2)
		{
			flag = true;
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, About);
		}


		return 0;
		break;

	case WM_DESTROY:
	{
		PostQuitMessage(0); return 0;
	}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

	}
}

LRESULT CALLBACK myF(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK )

		{
			flag = true;
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}

		break;
	}

	return FALSE;
}


LRESULT CALLBACK WndProc1(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static short x = 100, y = 150;
	static short widthSCR, heightSCR;
	static short widthW, heightW;
	static int direct = rand() % 8 + 1; // 8 направлений движения
	switch (msg)
	{

	case WM_CREATE:
	{
		widthSCR = GetSystemMetrics(SM_CXSCREEN);
		heightSCR = GetSystemMetrics(SM_CYSCREEN);
		widthW = widthSCR / 4;
		heightW = heightSCR / 4;
		return 0;
	}
	case WM_MOUSEMOVE:
	{

		switch (direct)
		{
		case 1:
		{
			if (((x + widthW + 5) <= widthSCR))
			{
				MoveWindow(hWnd, x + 50, y, widthW, heightW, TRUE);
				x += 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		case 2:
		{
			if (((y + heightW + 5) <= heightSCR))
			{
				MoveWindow(hWnd, x, y + 50, widthW, heightW, TRUE);
				y += 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		case 3:
		{
			if (((y + heightW + 5) <= heightSCR) && ((x + widthW + 5) <= widthSCR))
			{
				MoveWindow(hWnd, x + 50, y + 50, widthW, heightW, TRUE);
				y += 5;
				x += 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		case 4:
		{
			if (((y + heightW + 5) <= heightSCR) && ((x - 5) >= 0))
			{
				MoveWindow(hWnd, x - 50, y + 50, widthW, heightW, TRUE);
				y += 5;
				x -= 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		case 5:
		{
			if (((y - 5) >= 0) && ((x + widthW + 5) <= widthSCR))
			{
				MoveWindow(hWnd, x - 50, y + 50, widthW, heightW, TRUE);
				y -= 5;
				x += 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		case 6:
		{
			if ((y - 5) >= 0)
			{
				MoveWindow(hWnd, x, y - 50, widthW, heightW, TRUE);
				y -= 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		case 7:
		{
			if ((y - 5) >= 0 && (x - 5) >= 0)
			{
				MoveWindow(hWnd, x - 50, y - 50, widthW, heightW, TRUE);
				y -= 5;
				x -= 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		case 8:
		{
			if ((x - 5) >= 0)
			{
				MoveWindow(hWnd, x - 100, y, widthW, heightW, TRUE);

				x -= 5;
			}
			else
				direct = rand() % 8 + 1;

			break;
		}
		}
		return 0;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0); return 0;
	}
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);

	}

}


// Message handler for about box. 
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

