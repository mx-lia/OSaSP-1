#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "string.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
		NULL, NULL, &cif, &pi)))
		wcout << "Error " << '\n';
	system("pause");
}
