//=====================================================================================

#pragma once

#include <Windows.h>
#include <TlHelp32.h>

//=====================================================================================

class cMemory
{
public:
	
	template<typename TYPE>
	static BOOL MemRead(const char* process, DWORD_PTR address, TYPE* buffer)
	{
		return ReadProcessMemory(OpenProcess(PROCESS_ALL_ACCESS, FALSE, EnumProcess(process)), reinterpret_cast<LPCVOID>(address), buffer, sizeof(TYPE), NULL);
	}

	template<typename TYPE>
	static BOOL MemWrite(const char* process, DWORD_PTR address, TYPE buffer)
	{
		return WriteProcessMemory(OpenProcess(PROCESS_ALL_ACCESS, FALSE, EnumProcess(process)), reinterpret_cast<LPVOID>(address), &buffer, sizeof(TYPE), NULL);
	}

private:

	static DWORD EnumProcess(const char* name)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		PROCESSENTRY32 ProcessEntry = { NULL };
		ProcessEntry.dwSize = sizeof(PROCESSENTRY32);

		for (BOOL bSuccess = Process32First(hSnapshot, &ProcessEntry); bSuccess; bSuccess = Process32Next(hSnapshot, &ProcessEntry))
		{
			if (!strcmp(ProcessEntry.szExeFile, name))
				return ProcessEntry.th32ProcessID;
		}

		return NULL;
	}
};

//=====================================================================================