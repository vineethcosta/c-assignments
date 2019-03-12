#include "stdafx.h"
#include<Windows.h>
#include<iostream>
using namespace std;
HANDLE hevent;
//createprocess program
DWORD WINAPI ThreadFun1(LPVOID lpParam)
{
	WaitForSingleObject(hevent, INFINITE);//check whether signaled
	cout << "Thread1 running" << endl;
	return 0;
}
DWORD WINAPI ThreadFun2(LPVOID lpParam)
{
	cout << "Thread2 running" << endl;
	SetEvent(hevent);//set to signaled
	return 0;
}
int main()
{

	HANDLE thread1, thread2;
	DWORD ThreadID1, ThreadID2;
	//create event
	hevent = CreateEventA(
		NULL,//security attributes
		FALSE,//auto or manual/auto event reset object-->true for manual
		FALSE,//initial state of event is signaled if true 
		"Myevent"//name of event object
	);
	if (hevent == NULL)
	{
		cout << "event creation failed" << endl;
	}
	//thread1

	thread1 = CreateThread(
		NULL,//sec atributes inherited by child or not
		0,//stack size of exe , if 0 uses default
		ThreadFun1,//starting thread address
		NULL,//pointer to var passed ti thread
		0,//flags that control creation of thread
		&ThreadID1//ThreadId address of DWORD
	);
	if (thread1 == NULL)
	{
		cout << "Thread failed" << GetLastError() << endl;
		return 0;
	}

	
	//thread2

	thread2 = CreateThread(
		NULL,//sec atributes inherited by child or not
		0,//stack size of exe , if 0 uses default
		ThreadFun2,//starting thread address
		NULL,//pointer to var passed ti thread
		0,//flags that control creation of thread
		&ThreadID2//ThreadId address of DWORD
	);
	if (thread2 == NULL)
	{
		cout << "Thread failed" << GetLastError() << endl;
		return 0;
	}
	//wait until object is in signaled state
	WaitForSingleObject(thread1, INFINITE);
	WaitForSingleObject(thread2, INFINITE);
	CloseHandle(thread1);
	CloseHandle(thread2);

	CloseHandle(hevent);
	system("pause");
	return 0;
}

