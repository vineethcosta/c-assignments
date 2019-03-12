// API2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<windows.h>
#include<iostream>
#include<shellapi.h>
using namespace std;

int __cdecl main()
{
	LPWSTR * str;
	int x;
	str = CommandLineToArgvW(GetCommandLineW(), &x);
	//write data from command prompt to console
	if (NULL == str)
	{
		cout << " error occured is: " << GetLastError();
		return 0;
	}
	else
	{
		for (int i = 0; i < x; i++)
		{
			printf("%d %ws\n", i, str[i]);
		}
	}
	system("pause");
	LocalFree(str);//free the space
    return 0;
}

