// Lab 14 Files.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include "windows.h"
#include "iostream"


int _tmain(int argc, _TCHAR* argv[])
{

	TCHAR Buffer[256];
	TCHAR Buffer2[] = TEXT("D:\\direct");
	TCHAR Buffer3[] = TEXT("D:\\direct1");

	if (CreateDirectory(Buffer2, NULL) && CreateDirectory(Buffer3,NULL))
		std::wcout << "directory create" << '\n';
	else
		std::wcout << "error create directory" << '\n';
	getchar();

	return 0;
}

