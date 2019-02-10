// spaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int replace(char*);
int main()
{
	char* cat = "this is cat";
	int n = replace(cat);
	cout << n;
	system("pause");
    return 0;
}

int replace(char* cat)
{
	int k=0;
	int len = strlen(cat);
	for (int i = 0; i < len; i++)
	{
		if (cat[i] == ' ')
		{
			cat[i] = '-';
			k++;
		}
	}
	return k;
}
