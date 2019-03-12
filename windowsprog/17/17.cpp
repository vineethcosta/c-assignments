// 17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<windows.h>
using namespace std;
 int c=0;
DWORD WINAPI Thread1(LPVOID param)
{
	c++;
	return 0;
}
DWORD WINAPI Thread2(LPVOID param)
{
	c++;
	return 0;
}
int main()
{
	DWORD thread1addr, thread2addr;
	HANDLE hThread1, hThread2;
	HANDLE arrh[2];
	while (1)
	{
		c = 0;
		hThread1 = CreateThread(
			NULL,
			0,
			Thread1,
			NULL,
			0,
			&thread1addr
		);
		if (hThread1 == NULL)
		{
			cout << "Cannot create the thread";
			return 0;
		}
		hThread2 = CreateThread(
			NULL,
			0,
			Thread2,
			NULL,
			0,
			&thread2addr
		);
		if (hThread2 == NULL)
		{
			cout << "Cannot create the thread";
			return 0;
		}
		arrh[0] = hThread1;
		arrh[1] = hThread2;
		WaitForMultipleObjects(2, arrh, TRUE, INFINITE);
		CloseHandle(hThread1);
		CloseHandle(hThread2);
		printf("g_x value is %ld\n", c);
		if (c == 1)
		{
			break;
		}
	}
	printf("Enter anything to quit\n");
	getchar();
	return 0;
}