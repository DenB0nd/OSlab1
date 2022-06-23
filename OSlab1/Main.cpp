#include <cstdio>
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <codecvt>
#include <locale>
using std::string;

void startProcess(string process, string argument)
{
	STARTUPINFO si;
	PROCESS_INFORMATION piApp;
	si.cb = sizeof(STARTUPINFO);

	ZeroMemory(&si, sizeof(STARTUPINFO));

	CreateProcess(NULL,
		(LPWSTR)std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(argument).c_str(),
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&piApp);
	WaitForSingleObject(piApp.hThread, INFINITE);
	CloseHandle(piApp.hThread);
	CloseHandle(piApp.hProcess);
};

void printReport(string report)
{
	std::ifstream in(report);

	string line;
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
}

int main(int argc, char* args[])
{
	string binaryFileName;
	std::cout << "Input binary file name.\n";
	getline(std::cin, binaryFileName);

	string number;
	std::cout << "Input number of records.\n";
	getline(std::cin, binaryFileName);

	string argument = "\0code" +
		binaryFileName +
		" " +
		number;

	startProcess("Creator.exe", argument);

	string fileName;
	std::cout << "Input file name.\n";
	getline(std::cin, fileName);

	string salary;
	std::cout << "Input salary.\n";
	getline(std::cin, salary);

	argument = "\0code" +
		string(args[1]) +
		" " +
		fileName + 
		" " +
		salary;

	startProcess("Reporter.exe", argument);
	printReport(fileName);

	return 0;
}