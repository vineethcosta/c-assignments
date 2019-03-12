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
	cout << "Success"<<endl;
	cout << "ThreadID:" << ThreadID <<endl;
	CloseHandle(thread);
	system("pause");
	return 0;

}