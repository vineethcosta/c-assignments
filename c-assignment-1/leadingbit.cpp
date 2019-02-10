// leading bit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x = 1;
	int rem;
	int final=0;

	for (int i = 0; i < 32; i++)
	{
		rem = n&x;
		final = final + pow(10, i)*rem;
		n = n >> 1;
	}
	cout << final;
	system("pause");
    return 0;
}

