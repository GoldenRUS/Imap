// PORT++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>
using namespace std;

HANDLE hSerial;

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		for(int i = 1; i<255; i++)
		{
			char tmp[4];
			char PortName[6];
			itoa(i, tmp, 10);
			snprintf(PortName, sizeof PortName, "%s%s", "COM", tmp);
			
			LPCTSTR sPortName = (LPCTSTR)PortName;
			hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
			if (hSerial != INVALID_HANDLE_VALUE)
			{
				DCB dcbSerialParams = { 0 };
				dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

				dcbSerialParams.BaudRate = CBR_9600;
				dcbSerialParams.ByteSize = 8;
				dcbSerialParams.StopBits = ONESTOPBIT;
				dcbSerialParams.Parity = NOPARITY;
				if (!SetCommState(hSerial, &dcbSerialParams))
				{
					//cout << "error setting serial port state\n";
				}
				char *tmp = argv[1];
				//cout << sPortName;
				//char *tmp = "4";
				DWORD dwSize = 1;
				DWORD dwBytesWritten;
				BOOL iRet = WriteFile(hSerial, tmp, dwSize, &dwBytesWritten, NULL);
				//cout << dwSize << " Bytes in string. " << dwBytesWritten << " Bytes sended. " << endl;
				CloseHandle(hSerial);
			}
		}
		cout << argv[1];
	}
	return 0;
}


