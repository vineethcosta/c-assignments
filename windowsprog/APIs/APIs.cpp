#include "stdafx.h"
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	WCHAR c1[] = L"ABCD";//initialize wchar
	
	int s1 = wcslen(c1);
	
	CHAR c2[] = "ABCD";//initialize char
	
	int s2 = strlen(c2);
	
	bool b1 = IsTextUnicode(c1, s1*sizeof(WCHAR), NULL);//check whether unicode
	
	bool b2 = IsTextUnicode(c2, s2*sizeof(CHAR), NULL);
	
	cout << s1 << " " << s2;
	if (b1 == 0)
		cout << "c1 is not unicode\n";
	else
		cout << "c1 is unicode\n";
	if (b2 == 0)
		cout << "c2 is not unicode\n";
	else
		cout << "c2 is unicode\n";
	
	WCHAR c3[] = L"VINE";
	char c4[] = "VISH";


	//convert widechar to multibyte
	int s3 = WideCharToMultiByte(CP_UTF8, 0, c3, -1, NULL, 0,NULL,NULL);
	char *c33 = new char[s3];
	WideCharToMultiByte(CP_UTF8, 0, c3, -1, c33, s3,NULL,NULL);
	cout << "Converted wide to multibyte:" << c33 << "\n";

	//convert multibyte to widechar 
	int s4 = MultiByteToWideChar(CP_UTF8, 0, c4, -1, NULL, 0);
	WCHAR *c44 = new WCHAR[s4];
	MultiByteToWideChar(CP_UTF8, 0, c4, -1, c44, s4);
	printf( "Converted multibyte to wide:%S", c44);
	cout << "\n";

	//printing the size
	cout << sizeof(char) << "\n";
	cout << sizeof(WCHAR) << "\n";

	system("pause");

}