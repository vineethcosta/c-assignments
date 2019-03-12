

#include "stdafx.h"
#include<Windows.h>
#include<iostream>
using namespace std;
//create file takes 7 arguments
//This is write file

int main()
{
	HANDLE hFile;
	BOOL write;
	char buf[] = "I Love Football.Testing Write and read yooo!!";
	DWORD bytestoWrite = strlen(buf);
	DWORD bytesWritten = 0;
	BOOL read;
	DWORD bytestoRead = strlen(buf);
	DWORD bytesRead = 0;
	hFile = CreateFile(
		L"writereadfile.txt",//PATH
		GENERIC_READ|GENERIC_WRITE,//access mode
		FILE_SHARE_READ,//share mode
		NULL,//SECURITY ATTRIBUTE
		CREATE_NEW,//CREATION DESPOSITION
		FILE_ATTRIBUTE_NORMAL,
		NULL);//HANDLE Htemplate File

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "File creation failed" << GetLastError() << endl;
	}
	cout << "Success";
	
	write = WriteFile(
		hFile,//handle file
		buf,//lpbuffer pointer to buffer
		bytestoWrite,//maxbytes to be write
		&bytestoWrite,//lpNumberofByteWrite (set it to null)
		NULL//pointer to overlapped
		);
	if (write == FALSE)
	{
		cout << "write Failed" << GetLastError()<<endl;
	}
	//read file
	read = ReadFile(
		hFile,//handle file
		buf,//lpbuffer pointer to buffer
		bytestoRead,//maxbytes to be read
		&bytestoRead,//lpNumberofByteRead(set it to null)
		NULL//pointer to overlapped
	);

	if (read == FALSE)
	{
		cout << "read Failed" << GetLastError() << endl;
	}
	cout << "The read data is:" << buf;
	CloseHandle(hFile);
	system("pause");

    return 0;
}






