#include "stdafx.h"
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#include <stdio.h>
#include<iostream>
using namespace std;
int findlength(char* input)
{
	int i;
	int stringlength = 0;
	for (i = 0; i < strlen(input); i++)
	{
		stringlength++;
		if (input[i] == '-')
		{
			//in the case of a-z or 4-7

			if (input[i + 1] > input[i - 1]) 
			{
				stringlength += input[i + 1] - input[i - 1] - 1;
			}
			//if both characters are same i.e if we have a-a
			else if (input[i + 1] == input[i - 1])        
			{
				i++;
				stringlength--;
			}
			//if next character is smaller than previous character(Ex: 7-1)
			else                          
			{
				printf("The entered string might be invalid , check again\n");
				exit(0);
			}
		}

	}
	return stringlength;
}

char *expandthestring(char *input, char *result)
{
	int flag = 0;
	int i;
	int stringlength;
	stringlength = findlength(input);
	int j;
	int k = 0;
	result = (char *)malloc(stringlength * sizeof(char));
	for (i = 0; i<strlen(input); i++)
	{
		// if abcd-z then print abcd into result
		if (input[i] != '-')                 
		{
			result[k] = input[i];
			k++;
		}
		//now the character is - 
		else                                 
		{
			//in the case of 1--7
			if (input[i - 1] == '-' || input[i + 1] == '-')        
			{
				flag = 1;
				break;
			}
			else if (((i - 2) >= 0 && input[i - 2] == '-') || ((i + 2)<strlen(input) && input[i + 2] == '-')) //if it is not valid
			{
				printf("The entered string might be invalid , check again\n");
				exit(0);
			}
			//if first is number 1-
			else if (isdigit(input[i - 1])>0)            
			{
				//if next also is a number 1-100 and greater
				if (input[i + 1] >= input[i - 1] && isdigit(input[i + 1])>0)  
				{
					//1-100 result until 1 to 100 including must print
					for (j = 1; j<input[i + 1] - input[i - 1]; j++)
					{
						result[k] = input[i - 1] + j;
						k++;
					}
				}
				else
				{
					//if something is wrong make flag as 1
					flag = 1;
					break;
				}
			}
			//in the case of 5-5
			else if (input[i - 1] == input[i + 1])           
			{
				i++;
			}
			//for lower case alphabets a-z
			else if (islower(input[i - 1])>0)              
			{
				//ifz>a
				if (input[i + 1] >= input[i - 1] && islower(input[i + 1])>0)        
				{
					for (j = 1; j<input[i + 1] - input[i - 1]; j++)
					{
						result[k] = input[i - 1] + j; //print a-z including both
						k++;
					}
				}
				else
				{
					//if anything wrong set flag as 1
					flag = 1;
					break;
				}
			}
			//same as lower
			else if (isupper(input[i - 1])>0)              
			{
				if (input[i + 1] >= input[i - 1] && isupper(input[i + 1])>0)       
				{
					for (j = 1; j<input[i + 1] - input[i - 1]; j++)
					{
						result[k] = input[i - 1] + j;
						k++;
					}
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)
	{
		free(result);  //freeup the space of result
		printf("*****ERRRORRR***** something wrong with the input string .Give a proper expression\n");
		
		exit(0);
	}
	result[k] = '\0';
	return result;

}
int main()
{
	char *in, ch[100], *res;
	int a[26];
	int i;
	int j;
	printf("enter a input string \n");
	cin >> ch;
	res = NULL;
	//If the string starts or ends  with '-' terminate
	if (ch[0] == '-' || ch[strlen(ch) - 1] == '-')         
	{
		printf("The string cannot start or end with -\n");
		exit(0);
	}
	in = (char *)malloc( sizeof(char)*strlen(ch));
	strcpy(in, ch);

	//call expand function to expand the string
	res = expandthestring(in, res);
	printf("After expanding we get %s", res);

	//now free the space
	free(res);
	free(in);
	system("pause");
	return 0;

}