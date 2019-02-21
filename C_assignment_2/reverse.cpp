// reverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int rem=0;
	while (n > 0)
	{
		rem += n % 10;
		rem = rem * 10;
		n = n / 10;
	}
	cout << rem;
	system("pause");
    return 0;
}

