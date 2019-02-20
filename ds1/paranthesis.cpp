// paranthesis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct stackss {
	char *p;
	int size;
	int top;

}stacks;
class stackc
{

public:
	void setSize(int n)
	{
		stacks.top = -1;
		stacks.size = n;
		stacks.p = new char[n];
	}
	int isFull()
	{
		if (stacks.top == stacks.size)
			return 1;
		else
			return 0;
	}
	int isEmpty()
	{
		if (stacks.top == -1)
			return 1;
		else
			return 0;
	}

	void push(char x)
	{
		if (!isFull())
			stacks.p[++(stacks.top)] = x;
		else
			cout << "Stack is already full,cannot push x=" << x;
		return;

	}
	void pop()
	{
		if (!isEmpty())
			stacks.top--;
		else
			cout << "Stack is empty";
		return;
	}
	int peek()
	{
		return stacks.top;
	}
	void display()
	{
		cout << "the elements of the stack are:";
		for (int i = 0; i < stacks.top; i++)
		{
			cout << stacks.p[i] << "\n";
		}

	}
	char top()
	{
		return stacks.p[stacks.top];
	}
	char* check( char *ch,stackc s)
	{
		int flag = 0;

		for (int i = 0; i < strlen(ch); i++)
		{
			switch (ch[i])
			{
			case '(':
			case '{':
			case '[':
				s.push(ch[i]);
				break;

			case '}':
			case ')':
			case ']':
				if ((ch[i] == '}' && s.top() == '{') || (ch[i] == '}' && s.top() == '[') || (ch[i] == ')' && s.top() == '('))
					s.pop();
				else
					flag = 1;
				break;
			}
			if (flag == 1)
				break;

		}
		if (flag == 0 && s.isEmpty())
			return "balanced";
		else
			return "unbalanced";
	}

};

int main()
{
	stackc s;

	char ch[10];
	cin >> ch;
	int n = strlen(ch);
	s.setSize(n);
	cout<<s.check(ch,s);
	system("pause");
    return 0;
}

