// negpos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void swap(int*, int*);
int main()
{
	int n;
	cout << "Enter size of array";
	cin >> n;
	int *a = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int f = 0;
	int l = n - 1;
	while(f<l)
	{
		if (a[f] < 0)
			f++;
		else if (a[f] > 0 && a[l] < 0)
			swap(&a[f], &a[l]);
		else if (a[l] > 0)
			l--;
		else 
			continue;
	}
	for (int i = 0; i < n; i++)
	{
		cout<< a[i]<<" ";
	}

	system("pause");
    return 0;
}
void swap(int *a, int *b)
{
	*b = *a + *b - (*b = *a);
//	int t;
//	t = *a;
	//*a = *b;
	//*b = t;
}
