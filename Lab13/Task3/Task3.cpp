// Task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include "windows.h"
#include "iostream"


int main()
{
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	FILE* fp;


	TCHAR stdPath[30] = TEXT("D:\\direct\\my_api2.txt");

	hIn = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();

		return 2;
	}

	else
	{
		WriteFile(hIn, stdPath, 44, &dwNumberOfBytes, NULL);
		
		getchar();
		CloseHandle(hIn);
	}
	return 0;
}

