// Program1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n,k,rem,sum=0;
	cout << "Enter the number to find armstrong";
	cin >> n;
	k = n;
	while (n > 0) {
		rem = n % 10;
		sum += rem*rem*rem;
		n = n / 10;
	}
	if (k == sum)
		cout << "It is armstrong";
	else
		cout << "not armstrong";
	system("pause");
    return 0;
}

