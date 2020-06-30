#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include <tchar.h>
#include "string.h"

typedef BOOL(WINAPI* SETCONSOLEFONT)(HANDLE, DWORD);     // прототип недокументированый функции
SETCONSOLEFONT SetConsoleFont;

const WORD colors[] =
{
0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};

int _tmain(int argc, _TCHAR* argv[])
{

	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	// Tell the user how to stop
	SetConsoleTextAttribute(hstdout, 0xEC);
	std::cout << "Press any key to quit.\n";


	while (index < 13)
	{
		SetConsoleTextAttribute(hstdout, colors[index]);
		std::cout << "\t\t\t\t Hello World \t\t\t\t" << std::endl;
		if (++index > sizeof(colors) / sizeof(colors[0]))
			break;
	}
	FlushConsoleInputBuffer(hstdin);


	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	getchar();
	return 0;
}
