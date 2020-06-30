#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include <tchar.h>
#include "string.h"

const WORD colors[] =
{
0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE consoleOutput;
	COORD cursorPos;

	// Получаем хэндл консоли 
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleOutput, &csbi);

	// Задаем координаты курсора и перемещаем курсор
	cursorPos.X = 30;
	cursorPos.Y = 3;

	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			SetConsoleCursorPosition(consoleOutput, cursorPos);
			SetConsoleTextAttribute(consoleOutput, colors[1]);
			printf(" ");
			cursorPos.X += 1;
		}
		cursorPos.X = 30;
		cursorPos.Y += 1;
	}

	getchar();

	return 0;
}