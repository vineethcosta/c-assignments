// calci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int add(int, int);
int sub(int, int);
int res=0;
int main()
{
	int m,n,x;
	cout << "Welcome to calci.Please enter two numbers";
	cin >> m;
	cin >> n;
	cout << "enter 1 for addition and 2 for subtrction";
	cin >> x;
	switch (x)
	{
	case 1:
		cout << add(m, n)<<"\n";
	case 2:
		cout << sub(m, n)<<"\n";
	}
	system("pause");
    return 0;
}

