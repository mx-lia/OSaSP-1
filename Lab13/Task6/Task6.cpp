// Task6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include "windows.h"
#include "iostream"


int _tmain(int argc, _TCHAR* argv[])
{

	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	FILE* fp;
	BOOL pr2 = 0;

	TCHAR stdPathA[30] = TEXT("D:\\direct1\\my_api2.txt");
	TCHAR stdPathB[30] = TEXT("D:\\direct1\\my_api3.txt");

	BOOL pr = MoveFile(stdPathA, stdPathB);
	if (pr)
	{
		printf("MOVED");
		getchar();

	}
	else
	{
		printf(" NOT MOVED");
		getchar();

	}

	hIn = CreateFile(stdPathB, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();

		return 2;
	}

	else
	{
		ReadFile(hIn, Buffer, 256, &dwNumberOfBytes, NULL);
		std::wcout << "Read: " << Buffer << '\n';
		getchar();
		CloseHandle(hIn);
	}


	return 0;
}

