#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "string.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	DWORD processID;
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	processID = CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
		NULL, NULL, &cif, &pi);

	wcout << "Running  with PID:" << pi.dwProcessId << '\n';

	HANDLE hProcess = GetCurrentProcess(); OpenProcess( PROCESS_QUERY_INFORMATION |
										   PROCESS_VM_READ,
										   FALSE, processID );


										   // Get the process name.
	if (NULL != hProcess)
	{
		Sleep(2000);
		BOOL result = TerminateProcess(hProcess, 0);

		CloseHandle(hProcess);
	}
	else

	{
		wcout << "Error when terminating " << '\n';
	}
	using namespace std;
}
