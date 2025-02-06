#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    STARTUPINFOW si = {sizeof(si)};
    PROCESS_INFORMATION pi;


    // Creating a new process (notepad.exe)
    if (CreateProcessW(
            L"C:\\Windows\\System32\\notepad.exe",  // Path to the executable
            NULL,    // Command line arguments
            NULL,    // Process security attributes
            NULL,    // Thread security attributes
            FALSE,   // Handle inheritance
            0,       // Creation flags
            NULL,    // Environment variables
            NULL,    // Current directory
            &si,     // Startup Info
            &pi      // Process Information
        )) {
        // Process created successfully
        std::cout << "Process created successfully. PID: " << pi.dwProcessId << std::endl;
        

        // Close process and thread handles.
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        // Process creation failed
        std::cerr << "Process creation failed. Error: " << GetLastError() << std::endl;
    }

    return 0;
}
