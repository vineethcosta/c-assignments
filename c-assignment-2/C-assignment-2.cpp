// C-assignment-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int fact(int);
int main()
{
	int n;
	cin >> n;
	cout << fact(n);
	system("pause");
    return 0;
}
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n*fact(n - 1);
}

