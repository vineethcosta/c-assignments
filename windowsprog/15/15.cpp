#include "stdafx.h"
#include<Windows.h>
#include<iostream>
using namespace std;
DWORD WINAPI ThreadFun(LPVOID lpParam)
{
	cout << "Thread running" << endl;
	return 0;
}
int main()
{
	HANDLE thread;
	DWORD ThreadID;
	DWORD exitcodemain;
	DWORD exitcode = 420;
	thread = CreateThread(
		NULL,//sec atributes inherited by child or not
		0,//stack size of exe , if 0 uses default
		ThreadFun,//starting thread address
		NULL,//pointer to var passed ti thread
		0,//flags that control creation of thread
		&ThreadID//ThreadId address of DWORD
	);
	if (thread == NULL)
	{
		cout << "Thread failed" << GetLastError() << endl;
		return 0;
	}
	WaitForSingleObject(thread, INFINITE);

	BOOL bRet = GetExitCodeThread(thread, &exitcodemain);
	if (bRet == 0)
	{
		_tprintf(TEXT("Getexitcodethread failed with error %d\n"), GetLastError());
		getchar();
		return 0;
	}
	BOOL terminate = TerminateThread(thread, exitcode);
	if (terminate == 0)
	{
		cout << "Thread failed to terminate" << GetLastError() << endl;
		return 0;
	}
	GetExitCodeThread(thread, &exitcodemain);
	cout << "The exit code of secondary thread is:" << exitcode<<endl;
	CloseHandle(thread);
	system("pause");
	return 0;

}