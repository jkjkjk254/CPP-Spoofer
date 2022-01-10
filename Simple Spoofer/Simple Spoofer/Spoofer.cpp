#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <urlmon.h>
#include "XorStr.hpp"
#pragma comment (lib, "urlmon.lib")

using namespace std;

// Pasted
std::string RandomString(const size_t length)
{
	std::string r;
	static const char bet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxyzZ1234567890" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}

DWORD Nigger(LPVOID in) {
	while (1)
	{
		Sleep(850);
		SetConsoleTitle(RandomString(16).c_str());
	}
}

void Clean()
{
	// Cleaner Download Link										// Download Path
	URLDownloadToFile(NULL, "Your Discord Download Link Goes Here", "C/Windows/System32/YourCleaner.exe", 0, NULL);
	system(XorString("YourCleaner.exe")); // If you are using with a Batch file (.bat) just add " >nul 2>&1" after the file name to have it not show files being deleted
	DeleteFile(XorString("C:/Windows/System32/YourCleaner.exe")); // Delete the Mapper
	MessageBox(0, "Done Cleaning", "Spoofer", MB_OK | MB_ICONASTERISK);
}

void Spoof()
{
	// Mapper Download Link											// Download Path
	URLDownloadToFile(NULL, "Your Discord Download Link Goes Here", "C:/Windows/System32/Penis.exe", 0, NULL);
	// Driver Download Link											// Download Path
	URLDownloadToFile(NULL, "Your Discord Download Link Goes Here", "C:/Windows/System32/Penis.sys", 0, NULL);
	system(XorString("YourMapper.exe YourDriver.sys >nul 2>&1")); // You can remove the ">nul 2>&1" to show the driver loading
	Sleep(750);
	DeleteFile(XorString("C:/Windows/System32/Penis.exe")); // Delete the Mapper
	DeleteFile(XorString("C:/Windows/System32/Penis.sys")); // Delete the Driver
	MessageBox(0, "Done Spoofing", "Spoofer", MB_OK | MB_ICONASTERISK);
}

int main()
{
	CreateThread(NULL, NULL, Nigger, NULL, NULL, NULL);
	A:
	system(XorString("cls"));

	std::cout << XorString("\n\n   [1] Clean\n   [2] Spoof\n   [3] Serials\n   [4] Discord\n\n   Option - ");

	int option;

	std::cin >> option;
	switch (option)
	{
	case 1:
		Clean();
		goto A;
		break;
	case 2:
		Spoof();
		goto A;
		break;
	case 3:
		system(XorString("cls"));
		printf(XorString("\n\nDiskdrive\n"));
		system(XorString("wmic diskdrive get serialnumber"));
		printf(XorString("\n\nBIOS\n"));
		system(XorString("wmic bios get serialnumber"));
		printf(XorString("\n\nBaseboard\n"));
		system(XorString("wmic baseboard get serialnumber"));
		printf(XorString("\n"));
		system(XorString("pause"));
		goto A;
		break;
	case 4:
		system(XorString("start Your Discord Link"));
		goto A;
		break;
	}
}

// You can change the EXE name by going to Properties > Target Name