// Client Named Pipe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Windows.h"               
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	HANDLE hPipe; // дескриптор канала
	DWORD cbRead;
	DWORD cbWritten;
	try
	{
		if ((hPipe = CreateFile(
			L"\\\\.\\pipe\\pipename",
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL, OPEN_EXISTING, NULL,
			NULL)) == INVALID_HANDLE_VALUE)
			throw("createfile:", GetLastError());

			char rbuf[512];
			char wbuf[40] = "Hello from client Named Pipe";
			WriteFile(hPipe, wbuf, strlen(wbuf) + 1, &cbWritten, NULL);

			ReadFile(hPipe, rbuf, 512, &cbRead, NULL);
			cout << rbuf << endl;
		
		CloseHandle(hPipe);
	}
	catch (string ErrorPipeText)
	{
		cout << endl << ErrorPipeText;
	}

	return 0;
}