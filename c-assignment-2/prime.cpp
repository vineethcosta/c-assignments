// prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int isPrime(int);
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		if (isPrime(i))
			cout << i << " ";

	}
	system("pause");
    return 0;
}
int isPrime(int i)
{
	int k = 1;
	for (int j = 2; j < i; j++)
	{
		if (i%j == 0)
			k = 0;
	}
	return k;
}
