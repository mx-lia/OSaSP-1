#include "stdafx.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
using namespace std;
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)


bool AreEqual(const TCHAR *a, const TCHAR *b)
{
	while (*a == *b)
	{
		if (*a == _TEXT('\0'))return true;
		a++; b++;
	}
	return false;
}



bool IsProcessRun()
{
	bool RUN;
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
		FindClose(hFind);
	}
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	if (AreEqual(pe.szExeFile, FindFileData.cFileName))
	{
		RUN = true;
		return RUN;
	}
	else
		RUN = false;
	while (Process32Next(hSnapshot, &pe))
	{
		if (AreEqual(pe.szExeFile, FindFileData.cFileName))
		{
			RUN = true;
			return RUN;
		}
		else
			RUN = false;
	}
	return RUN;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
		if (IsProcessRun())
		{

			std::wcout << "Running" << '\n';
		}
		else

		{
			std::wcout << "NOT Running" << '\n';
		}
	
	system("pause");
}
