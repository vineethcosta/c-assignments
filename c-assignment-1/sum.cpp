// Program3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	cout << "Enter number for sum with changes";
	cin >> n;
	while (n > 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	cout << sum << "\n";
	system("pause");
    return 0;
}

