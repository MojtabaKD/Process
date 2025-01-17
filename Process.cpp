#include <iostream>
#include <windows.h>
#include <psapi.h>

void ShowProcessInfo() {
    DWORD processID = GetCurrentProcessId();
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

    if (hProcess != nullptr) {
        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
            std::cout << "Process ID: " << processID << std::endl;
            std::cout << "Working Set Size: " << pmc.WorkingSetSize << " bytes" << std::endl;
            std::cout << "Pagefile Usage: " << pmc.PagefileUsage << " bytes" << std::endl;
        }
        CloseHandle(hProcess);
    }
    else {
        std::cerr << "Failed to open process!" << std::endl;
    }
}

int main() {
    ShowProcessInfo();
    return 0;
}
