// 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<iostream>
using namespace std;
//createprocess program

int main()
{
	
	HANDLE thread;
	DWORD ThreadID;
	HANDLE hProcess = NULL;
	HANDLE hThread = NULL;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwProcessId = 0;
	DWORD dwThreadId = 0;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	BOOL createproc = NULL;
	createproc = CreateProcess(
		L"C:\\Program Files\\Windows Media Player\\wmplayer.exe",//NAME OF APP
		NULL,//Command line
		NULL,//Security attribute
		NULL,//thread attribute
		FALSE,//inherit
		0,//creation flag
		NULL,//environment
		NULL,//current dir
		&si,//startupinfo
		&pi//process info
	);
	if (createproc == FALSE)
	{
		cout << "process creation failed" << GetLastError() << endl;
	}
	cout << "Create process success";
	cout << "process id:" << pi.dwProcessId << endl;
	cout << "Thread Id:" << pi.dwThreadId << endl;
	cout << "Get process Id" << GetProcessId(pi.hProcess) << endl;
	cout << "Get Thread Id" << GetThreadId(pi.hThread) << endl;
	cout << "Get Thread Id" << GetCurrentThreadId() << endl;
	cout << "Process Id of Thread" << GetProcessIdOfThread(pi.hThread) << endl;
	WaitForSingleObject(
		pi.hProcess,//process
		INFINITE//Time
	);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	system("pause");

	return 0;
}

