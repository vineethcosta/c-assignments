// noofbits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int n,c=0;
	cin >> n;
	for (int i = 1; i <=8; i++)
	{
		if (n&1 == 1)
			c++;
		n = n >> 1;
	}
	cout << c;
	system("pause");
    return 0;
}

