// rotations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	char *ch="vineeth";
	char temp;
	int n = strlen(ch);
	for (int i = 0; i < strlen(ch); i++)
	{
		temp = ch[i+1 ];
		ch[i+1] = ch[i];
	}

    return 0;
}

