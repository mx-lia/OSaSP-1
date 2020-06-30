#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include <tchar.h>
#include "string.h"
#include <string>

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

	cursorPos.X = 0;
	cursorPos.Y = 0;

	std::string table[5][2] = { {"__________________________", "_________________"}, {"SURNAME", "GROUP"}, {"__________________________", "_________________"}, {"Maximchikova", "6"}, {"______________________", "_________________"} };

	for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		for (int j = 0; j < sizeof(table[0]) / sizeof(table [0][0]); j++)
		{
			SetConsoleCursorPosition(consoleOutput, cursorPos);
			printf(table[i][j].c_str());
			cursorPos.X += 20;
		}
		cursorPos.X = 0;
		cursorPos.Y += 1;
	}
	getchar();
	return 0;
}