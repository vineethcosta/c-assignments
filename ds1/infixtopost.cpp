// infixtopost.cpp : Defines the entry point for the console application.
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
	int precedence(char ch)
	{
		if (ch == '+' || ch == '-')
			return 1;
		else if (ch == '[' || ch == '{' || ch == '(')
			return 0;
		else
			return 2;
	}

	

};
void inpo(char *ch)
{
	stackc s;
	s.setSize(10);
	int n = strlen(ch);
	char *ch2 = new char[n];
	int i;
	int x=0;
	for (i = 0; i < strlen(ch); i++)
	{
		if (isalpha(ch[i]))
		{
			ch2[x++] = ch[i];
		}
		else
		{
			if (s.isEmpty())
				s.push(ch[i]);
			else if (ch[i] == '[' || ch[i] == '{' || ch[i] == '(')
				s.push(ch[i]);
			

			else if (ch[i] == ']' || ch[i] == '}' || ch[i] == ')')
			{
				s.push(ch[i]);
				if (s.top() == ')')
				{
					s.pop();
					while (s.top() != '(')
					{
						ch2[x++] = s.top();
						s.pop();
					}
				}
				else if (s.top() == '}')
				{
					s.pop();
					while (s.top() != '{')
					{
						ch2[x++] = s.top();
						s.pop();
					}
				}
				else if (s.top() == ']')
				{
					s.pop();
					while (s.top() != '[')
					{
						ch2[x++] = s.top();
						s.pop();
					}
				}
				s.pop();
			}
			else if (s.precedence(ch[i]) > s.precedence(s.top()))
				s.push(ch[i]);
			else if (s.precedence(ch[i]) <= s.precedence(s.top()))
			{
				while (!s.isEmpty() && (s.top() != '[' || s.top() != '{' || s.top() != '('))
				{
					ch2[x++] = s.top();
					s.pop();
					if (!(s.precedence(ch[i]) < s.precedence(s.top())))
						break;
				}
				s.push(ch[i]);

			}
			

		}

	}
	while (!s.isEmpty())
	{
		ch2[x++] = s.top();
		s.pop();
	}
	ch2[x] = '\0';
	for (int i = 0; i < strlen(ch2); i++)
	{
		if ((ch2[i] == '[' || ch2[i] == '{' || ch2[i] == '('))
			continue;
		else
			cout << ch2[i];

	}
		
}
int main()
{
	char ch[10];
	cin >> ch;
	
	inpo(ch);
	//s.display();
	system("pause");
    return 0;
}

