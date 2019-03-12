#include "stdafx.h"
#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI ThreadFun(LPVOID lpParam)
{
	
	for (int i = 0; i < 1000; i++)
	{
		cout << i << " ";
	}
	cout << "\n";
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
		CREATE_SUSPENDED,//flags that control creation of thread
		&ThreadID//ThreadId address of DWORD
	);
	if (thread == NULL)
	{
		cout << "Thread failed" << GetLastError() << endl;
		return 0;
	}
	char ch;
	cout << "Enter something to proceed"<<endl;

	ch = getchar();
	if (ch)
	{
		Sleep(5000);
		DWORD resume = ResumeThread(thread);
		WaitForSingleObject(thread, INFINITE);
	}
	else
	{
		cout << "Nothing entered";
	}
	system("pause");
	return 0;
}