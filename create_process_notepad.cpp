#include <windows.h>
#include<iostream>

using namespace std;

int main() { STARTUPINFOW startupInfo = {sizeof(startupInfo)}; PROCESS_INFORMATION processInfo;


if (CreateProcessW(
        L"C:\\Windows\\System32\\notepad.exe",  // Path to the executable
        NULL,    // Command line arguments
        NULL,    // Process security attributes
        NULL,    // Thread security attributes
        FALSE,   // Handle inheritance
        0,       // Creation flags
        NULL,    // Environment variables
        NULL,    // Current directory
        &startupInfo, // Startup Info
        &processInfo  // Process Information
    )) {
    cout << "Process created successfully!" << endl;
    cout << "Process ID: " << processInfo.dwProcessId << endl;
    cout << "Thread ID: " << processInfo.dwThreadId << endl;
    cout << "Process Handle: " << processInfo.hProcess << endl;
    cout << "Thread Handle: " << processInfo.hThread << endl;
    cout << "Press Enter to terminate the process..." << endl;
    cin.get(); 
  
    if (TerminateProcess(processInfo.hProcess, 1)) {
        cout << "Process terminated." << endl;
    } else {
        cout << "Failed to terminate the process." << endl;
    }

   
    DWORD exitCode;
    if (GetExitCodeProcess(processInfo.hProcess, &exitCode)) {
        cout << "Exit Code: " << exitCode << endl;
    } else {
        cout << "Failed to retrieve exit code." << endl;
    }

   
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
} else {
    cout << "Failed to create process." << endl;
}

return 0;
}

