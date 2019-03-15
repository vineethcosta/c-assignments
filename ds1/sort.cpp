#include "stdafx.h"
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
class sort {
public:
	void bubblesort(int *a,int n)
	{
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0; j < n-i-1; j++)
			{
				if (a[j+1] < a[j])
					swap(a[j+1], a[j]);
			}
		}
	}
	void insertionsort(int *a,int n)
	{
		int j,temp;
		for (int i = 1; i < n; i++)
		{
			j = i - 1;
			temp = a[i];
			while (j >= 0 && a[j] > a[i])
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
		}
	}
	void selectionsort(int *a,int n)
	{ 
		int min;
		for (int i = 0; i < n-1; i++)
		{
			min = a[i];
			for (int j = i + 1; j < n; j++)
			{
				if (min > a[j])
					min = a[j];
			}
			swap(a[i], min);
		}
	}

};

int main()
{
	sort s;
	int n;
	cout << "Enter size for bubblesort array";
	cin >> n;
	int *a = (int*)malloc(sizeof(int)*n);
	cout << "Enter the array";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	s.bubblesort(a,n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	cout << "\n";
	int n1;
	cout << "Enter size for insertion array";
	cin >> n1;
	int *a1 = (int*)malloc(sizeof(int)*n1);
	cout << "Enter the array";
	for (int i = 0; i < n1; i++)
	{
		cin >> a1[i];
	}
	s.bubblesort(a1, n1);
	for (int i = 0; i < n1; i++)
	{
		cout << a1[i] << " ";
	}
	cout << "\n";
	int n2;
	cout << "Enter size for selection array";
	cin >> n2;
	int *a2 = (int*)malloc(sizeof(int)*n2);
	cout << "Enter the array";
	for (int i = 0; i < n2; i++)
	{
		cin >> a2[i];
	}
	s.bubblesort(a2, n2);
	for (int i = 0; i < n2; i++)
	{
		cout << a2[i] << " ";
	}

	system("pause");

}