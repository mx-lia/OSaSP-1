// Task4.cpp: определяет точку входа для консольного приложения.

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
return 0;
}
