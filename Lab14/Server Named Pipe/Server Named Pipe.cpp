// Server Named Pipe.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "stdafx.h"
#include "Windows.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	HANDLE hPipe; // ���������� ������
	DWORD cbRead;
	DWORD cbWritten;
	char rbuf[50];
	LPCWSTR p = L"\\\\.\\pipe\\pipename";

	try
	{
		if ((hPipe = CreateNamedPipe(p,
			PIPE_ACCESS_DUPLEX,           //���������� ����� 
			PIPE_TYPE_MESSAGE | PIPE_WAIT,  // ���������|����������
			1, NULL, NULL,                 // �������� 1 ���������
			INFINITE, NULL)) == INVALID_HANDLE_VALUE)
			throw("create:", GetLastError());

		if (!ConnectNamedPipe(hPipe, NULL))           // ������� �������   
			throw("connect:", GetLastError());

		char wbuf[40] = "Hello from server Named Pipe";

		ReadFile(hPipe, rbuf, strlen(rbuf) + 5, &cbRead, NULL);
		cout << rbuf << endl;
		WriteFile(hPipe, wbuf, strlen(wbuf) + 1, &cbWritten, NULL);

		if (!DisconnectNamedPipe(hPipe))
			throw ("disconnected:", GetLastError());

		CloseHandle(hPipe);
	}
	catch (string ErrorPipeText)
	{
		cout << endl << ErrorPipeText;
	}

	return 0;
}
