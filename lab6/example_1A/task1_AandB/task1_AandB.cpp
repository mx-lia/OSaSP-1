#include "stdafx.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
#include <tchar.h>
#include <conio.h>  
#include <stdio.h> 
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	TCHAR filesearch[] = TEXT("C:\\WINDOWS\\system32\\mspaint.exe");
	// Find the first file in the directory.
	hFind = FindFirstFile(filesearch, &FindFileData);
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	}																															
	else
	{
		wcout << "Found: " << FindFileData.cFileName << '\n';
		if (!(CreateProcess(NULL, FindFileData.cFileName, NULL, NULL, FALSE, 0,
			NULL, NULL, &cif, &pi)))
			cout << "Error " << '\n';
		// List all the other files in the directory.
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			
			wcout << "Found: " << FindFileData.cFileName << '\n';
		}
		FindClose(hFind);

	}

	system("pause");
}

