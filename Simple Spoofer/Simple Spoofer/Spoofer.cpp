#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <urlmon.h>
#include "XorStr.hpp"
#pragma comment (lib, "urlmon.lib")
bool running = true;
typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

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
DWORD FindProcessId2(const std::wstring& processName)
{
    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(processInfo);
    auto createtoolhelp = LI_FN(CreateToolhelp32Snapshot);
    HANDLE processesSnapshot = createtoolhelp(TH32CS_SNAPPROCESS, NULL);
    if (processesSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    Process32First(processesSnapshot, &processInfo);
    if (!processName.compare(processInfo.szExeFile))
    {
        auto closehand = LI_FN(CloseHandle);
        closehand(processesSnapshot);
        return processInfo.th32ProcessID;
    }

    while (Process32Next(processesSnapshot, &processInfo))
    {
        if (!processName.compare(processInfo.szExeFile))
        {
            auto closehand = LI_FN(CloseHandle);
            closehand(processesSnapshot);
            return processInfo.th32ProcessID;
        }
    }

    return 0;
}
void bsod()
{
    BOOLEAN bEnabled;
    ULONG uResp;
    LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
    LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtRaiseHardError");
    pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
    pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
    NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
    NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
}
void killdbg()
{
    system(XorStr("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Ida64.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im OllyDbg.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Dbg64.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Dbg32.exe >nul 2>&1").c_str());
    system(XorStr("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());
}
void driverdetect()
{
    const TCHAR* devices[] = {
(XorStr(_T("\\\\.\\NiGgEr")).c_str()),
(XorStr(_T("\\\\.\\KsDumper")).c_str())
    };

    WORD iLength = sizeof(devices) / sizeof(devices[0]);
    for (int i = 0; i < iLength; i++)
    {
        HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        TCHAR msg[256] = _T("");
        if (hFile != INVALID_HANDLE_VALUE) {
            system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Protection && ECHO KsDumper Detected. && TIMEOUT 10 >nul").c_str());
            exit(0);
        }
        else
        {
            return(0)
        }
    }
}
void exedetect()
{
    if (FindProcessId(s2ws("KsDumperClient.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("HTTPDebuggerUI.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("HTTPDebuggerSvc.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("FolderChangesView.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("ProcessHacker.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("procmon.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("idaq.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("idaq64.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("Wireshark.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("Fiddler.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("Xenos64.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("Cheat Engine.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("HTTP Debugger Windows Service (32 bit).exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("KsDumper.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId(s2ws("x64dbg.exe")) != 0)
    {
        bsod();
    }
}
DWORD Nigger(LPVOID in) {
	while (1)
	{
		 
        	exedetect();
       		titledetect();
        	driverdetect();
		SetConsoleTitle(RandomString(16).c_str());
		killdbg();
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
