// program-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, k, rem, sum = 0;
	cout << "Enter number for palindrome check";
	cin >> n;
	k = n;
	while (n > 0)
	{
		rem = n % 10;
		sum = sum * 10 + rem;
		n = n / 10;
	}
	if (sum == k)
		cout << "palindrome";
	else
		cout << " Not palindrome";
	system("pause");
	return 0;
}

