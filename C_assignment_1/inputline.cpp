// inputline.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ch;
	cout << "Enter a string to evaluate";
	getline(cin, ch);
	int a = 0, d = 0, t = 0, s = 0;
	for (int i = 0; i < ch.length(); i++)
	{
		if (isalpha(ch[i]))
			a++;
		else if (isdigit(ch[i]))
			d++;
		else if (ch[i] == ' ')
			s++;
		else if (ch[i] == '\t')
			t++;
		else
			cout << "not a valid input";
	}
	cout << "alphabets:" << a << "\n" << "digits" << d << "\n" << "spaces" << s << "\n" << "tab spaces" << t << "\n";
	system("pause");
    return 0;
}

