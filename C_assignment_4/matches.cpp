// matches.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<string.h>

using namespace std;
int any(char**);
int main()
{
	char *s1[2];
	scanf("%[^\n]s",s1[0]);
	scanf("%[^\n]s", s1[1]);
	s1[0] = (char*)malloc(sizeof(char) * 10);

	s1[1] = (char*)malloc(sizeof(char) * 10);
	cout << any(s1);
	system("pause");
    return 0;
}
int any(char**s1)
{
	int i = 0;
	char *token1 = strtok(s1[0], " " );
	char *token2 = strtok(s1[1], " ");
	while (token1 != NULL)
	{
		i++;
		while (token2 != NULL)
		{
		
			if (strcmp(token1, token2) == 0)
			{
				return i;
			}
			token2 = strtok(0, " ");
		}
		token1 = strtok(0, " ");
	}
	return - 1;
}
