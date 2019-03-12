// dumpexpand.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<windows.h>
void DumpEnvStrings(PTSTR xEnvBlock[]) {
	int currentptr = 0;
	PTSTR *xElement = (PTSTR *)xEnvBlock;
	PTSTR *xCurrent = NULL;

	while (xElement != NULL)
	{
		xCurrent = (PTSTR*)(*xElement);
		if (xCurrent == NULL) {
			xElement = NULL;
		}
		else
		{
			_tprintf(TEXT("[%u] %s \n"), currentptr, xCurrent);
			xCurrent++;
			currentptr++;
		}
		xElement++;
	}

}
int _tmain(int argc , TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env); 
	system("pause"); 
    return 0;
}

