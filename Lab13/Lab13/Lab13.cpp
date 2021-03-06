// Lab13.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include "windows.h"
#include "iostream"


int main()
{
	TCHAR Buffer[256];
	TCHAR Buffer2[] = TEXT("D:\\direct");
	TCHAR Buffer3[] = TEXT("D:\\direct1");

	if (CreateDirectory(Buffer2, NULL) && CreateDirectory(Buffer3, NULL))
		std::wcout << "directory create" << '\n';
	else
		std::wcout << "error create directory" << '\n';
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	FILE* fp;


	TCHAR stdPath[30] = TEXT("D:\\direct\\my_api2.txt");

	hIn = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();
		return 0;
	}

	else
	{
		WriteFile(hIn, stdPath, 44, &dwNumberOfBytes, NULL);

		getchar();
		CloseHandle(hIn);
	}

	BOOL pr2 = 0;
	TCHAR stdPathA[30] = TEXT("D:\\direct\\my_api2.txt");
	TCHAR stdPathB[30] = TEXT("D:\\direct1\\my_api2.txt");

	BOOL pr = CopyFile(stdPathA, stdPathB, pr2);
	if (pr)
	{
		printf("COPIED");
		getchar();

	}
	else
	{
		printf(" NOT COPIED");
		getchar();

	}

	BOOL pr3 = DeleteFile(stdPathA);
	if (pr3)
	{
		printf("DELETED");
		getchar();

	}
	else
	{
		printf(" NOT DELETED");
		getchar();

	}

	TCHAR stdPathD[30] = TEXT("D:\\direct1\\my_api3.txt");
	
	rename("D:\\direct1\\my_api2.txt", "D:\\direct1\\my_api3.txt");
	std::wcout << "RENAMED" << '\n';

	hIn = CreateFile(stdPathD, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hIn == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();
		return 0;
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

