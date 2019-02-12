// exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	FILE* fp1;
	fopen_s(&fp1,"one.txt", "r");
	char str[100];
	if (fp1 == NULL)
		cout << "Cannot open file";
	fgets(str, 100, fp1);
	int a=0, d=0, s=0, sc=0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (isalpha(str[i]))
			a++;
		else if (isdigit(str[i]))
			d++;
		else if (str[i]==' ')
			s++;
		else
			sc++;

	}
	cout << "No of alphabets" << a << "\n";
	cout << "no of digits" << d << "\n";
	cout << "No of spaces" << s << "\n";
	cout << "No of special characters" << sc<< "\n";
	fclose(fp1);

	FILE* fp2;
	FILE* fp22;
	fopen_s(&fp2, "two.txt", "r");
	fopen_s(&fp22, "two2.txt", "w");
	char ch=fgetc(fp2);
	while (1)
	{

		if (ch == '#')
		{
			while (ch != '\n')
			ch = fgetc(fp2);
		}
		else if (ch == EOF)
			break;
		else {
			fputc(ch, fp22);
			ch = fgetc(fp2);

		}
	}
	
	fclose(fp2);
	fclose(fp22);
	cout << "HEYYYY";
	FILE *fp4;
	FILE* fp44;
	fopen_s(&fp4,"four.txt", "r");
	fopen_s(&fp44,"four4.txt", "w");
	char chf;
		chf=fgetc(fp4);
	while (chf != EOF)
	{

		if (chf == '	')
		{
			putc('\\', fp44);
			putc('t', fp44);
		}
		else
			putc(chf, fp44);
			chf = fgetc(fp4);
	
	}
	
	fclose(fp4);
	fclose(fp44);
	FILE *fp3;
	FILE *fp33;
	fopen_s(&fp3, "three.txt", "r+");
	fopen_s(&fp33, "three3.txt", "w");
	char ss[100];
	char s1[8];
	char temp;
	int flag;
	while (feof(fp3))
	{
		fgets(ss, 100, fp3);
		for (int i = 0; i < strlen(ss); i++)
		{
			flag = 0;
			if (ss[i] == 'V')
			{
				for (int j = 0; j < strlen("Vineeth"); j++)
				{
					s1[j] = ss[i + j];
				}
				if (strcmp(s1, "Vineeth") == 0)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				for (int j = i, k = i + 6; j < strlen("Vineeth") && j < k; j++, k--)
				{
					temp = ss[j];
					ss[j] = ss[k];
					ss[k] = temp;
				}

			}
			else
				continue;
		}
		fputs(ss,fp33);
	}

	
	system("pause");
    return 0;
}

