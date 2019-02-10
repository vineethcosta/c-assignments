// sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int *a;
	int n,k;
	cout<< "Enter size of the array";
	cin >> n;
	cout << "Enter sum required";
	cin >> k;
	a = (int*)malloc(sizeof(int)*n);
	for (int p = 0; p < n; p++)
		cin >> a[p];
	int l = 0;
	int x=0;
	int sum = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		
		
		while (sum > k)
		{
			sum = sum - a[l];
			l++;
			if (sum == k)
			{
				x = 1;
				break;
			}
		}
		if (x != 1)
		{
			sum = sum + a[i];
		}

		else
			break;
	}
	if (x == 1)
		cout << "found at" << l + 1 << "to" << i + 1;
	else
		cout << "Not found";
	system("pause");
    return 0;
}

