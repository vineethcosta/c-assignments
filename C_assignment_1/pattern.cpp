// pattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the size of pattern";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			cout << " ";
		for (int k = i+1; k>0; k--)
			cout << k;
		for (int l = 2; l <= i+1; l++)
			cout << l;
		cout << "\n";

	}
	system("pause");
    return 0;
}

