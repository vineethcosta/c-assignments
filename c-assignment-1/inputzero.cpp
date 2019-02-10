// inputzero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int min=1000, max=-1000, p=0;
	while(n > 0)
	{
		if (n > max)
			max = n;
		else if (n < min)
			min = n;
		else
			continue;

		p++;
		cin >> n;


	}
	cout << "total number of positive numbers:" << p;
	cout << "Minimum is" << min << "Maximum is" << max;
	system("pause");

    return 0;
}

