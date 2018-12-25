// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


int  main()
{
	setlocale(LC_CTYPE, "");
	int a, b, c, result, i = 0;
	std::cout << "Введите 3 числа: ";
	std::cin >> a >> b >> c;

	_asm {
		mov eax, a
		mov ebx, b
		beg :
		cmp eax, ebx
			je end				//je - равны
			jg gr				//jg - больше
			sub ebx, eax
			jmp beg				 
			gr :
		sub eax, ebx
			jmp beg
			end :
		mov result, eax
	}

	i++;

	if (i == 1) {
		printf("НОД для первых двух чисел: %d\n", result);
		int z = result;

		_asm {
			mov eax, c
			mov ebx, z

			jmp beg
		}
	}
	else
		if (i == 2) {
			printf("НОД для трех чисел: %d\n", result);
			getchar();
		}
		else
			printf("3 бит справа - %d\n", result);

	printf("Введите 0 для прекращения ввода");
	printf("Введите число для проверки 3 разряда справа: ");
	int t;
	std::cin >> t;
	if (t != 0) {
		__asm {
			mov eax, t

			shr	eax, 11b	//сдвиг вправо
			jnb zer			// если cf == 0
			jb one			//если cf == 1
			zer :
			mov eax, 0
				jmp end
			one :
			mov eax, 1
				jmp end
		}
	}
	return 0;
}

