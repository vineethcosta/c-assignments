// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define STACK_SIZE 55
template<class T> //Template T declaration
class Stack
{
	int top;
	T stck_array[STACK_SIZE];
public:
	Stack()
	{
		top = -1;
	}
	int size()
	{
		return (top + 1);
	}
	int pop()
	{
		try
		{
			if (top == -1)
			{
				cout << "Stack empty";
				throw "nothing to pop";
			}
			else
			{
				return stck_array[top--];

			}

		}
		catch (char* msg)
		{
			cout << msg << endl;
		}
	}
	void push(T ele)
	{
		try
		{
			if (top == STACK_SIZE - 1)//if stack is full
			{
				cout << "The stack is already full";
				throw "cant push anything further into the stack";
			}
			else
			{
				stck_array[++top] = ele;
			}
		}
		catch (char *msg)
		{
			cout << msg << endl;
		}

	}
	~Stack()
	{

	}
};
int main()
{
	Stack <int> st;
	int temp;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << "size:" << st.size() << endl;
	temp = st.pop();
	cout << "popped element:" << temp << endl;
	system("pause");
	return 0;
}

