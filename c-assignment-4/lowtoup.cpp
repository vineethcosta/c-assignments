// lowtoup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<ctype.h>
using namespace std;


int main()
{
	char ch[10];
	cin >> ch;
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (isupper(ch[i]))
			ch[i] = tolower(ch[i]);
		else
			ch[i]=toupper(ch[i]);
	}

	cout << ch;
	system("pause");

    return 0;
}

