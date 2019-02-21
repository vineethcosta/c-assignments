// rotate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int rem;
	int s = 1 + floor(log(n) / log(10));
	int k;
	cin >> k;
	if (s < k)
	{
		k = k%s;
	}
	int p = pow(10, k);
	rem = n%p;


	rem = rem*pow(10, s - k) + n / p;
	cout << rem;
	system("pause");
    return 0;
}

