#include "stdafx.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	TCHAR directorySearch[] = TEXT("C:\\WINDOWS\\system32\\*");
	TCHAR filesearch[] = TEXT("C:\\WINDOWS\\system32\\*.txt");
	// Find the first file in the directory.
	hFind = FindFirstFile(directorySearch, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	}
	else
	{
		wcout << "Found: " << FindFileData.cFileName << '\n';

		// List all the other files in the directory.
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			wcout << "Found: " << FindFileData.cFileName << '\n';
		}
		FindClose(hFind);

	}
	system("pause");
}

