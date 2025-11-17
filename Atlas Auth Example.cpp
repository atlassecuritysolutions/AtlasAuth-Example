// ============================================================================
// ATLAS AUTHENTICATION LIBRARY - EXAMPLE USAGE
// ============================================================================
// This example demonstrates how to integrate Atlas Authentication into your
// C++ application. Follow the numbered steps below to get started!
// Build as Release/x64
// ============================================================================

#include <Windows.h>
#include <iostream>
#include <fstream>
#include "AtlasAuth.h"

// ============================================================================
// STEP 1: Configure your API key (Critical)
// ============================================================================
// Replace "YOUR_API_KEY_HERE" with the API key from your Atlas Panel
// You can find this in the panel after creating an application by clicking "View API"
const std::string AuthAPIKEY = "9hzJ6V4ejRitW5OzI8zmepUaCI0eimU3nrnXdel6II5FWUVHJZPAdSagoiLjuDaH";

int main()
{
    // ========================================================================
    // STEP 2: Initialize the authentication system (Critical)
    // ========================================================================
    // This MUST be called once at the start of your program, before any other
    // Atlas functions. It sets up security protections and connects to the server.
    AuthenticationStartup(AuthAPIKEY);

    std::cout << "Atlas Authentication Example\n" << std::endl;

    // ========================================================================
    // STEP 3: Authenticate the user with their license key
    // ========================================================================
    // Prompt the user for their license key and verify it with the server
    std::cout << "Enter license: ";
    std::string license;
    std::getline(std::cin >> std::ws, license);

    std::cout << "Attempting to connect to server..." << std::endl;

    if (!login(license)) {
        // ====================================================================
        // Authentication failed - Get the detailed error message from server
        // This list may not includes some example errors, review your Logs tab
        // In the panel to view the full log with all details
        // ====================================================================
        // Possible error messages include:
        // - "Invalid license key" - License doesn't exist in database
        // - "License expired" - Subscription has ended
        // - "HWID mismatch - License locked to different hardware"
        // - "IP mismatch - License locked to different IP"
        // - "Application hash mismatch" - Unauthorized application
        // - "Access denied - Banned" - User has been banned
        // - "Too many active sessions" - Concurrent login limit reached
        // - "Rate limited - Try again later" - Too many failed attempts
        // ====================================================================

        std::string errorMsg = AtlasStats::GetErrorMessage();

        std::cout << "\n[!] Authentication failed!" << std::endl;
        if (!errorMsg.empty()) {
            std::cout << "[!] Reason: " << errorMsg << std::endl;
        }

        std::cout << "\nPress Enter to exit..." << std::endl;
        std::cin.get();
        return 1;
    }

    // ========================================================================
    // STEP 4: Verify session is validated (optional)
    // ========================================================================
    // You can call this periodically to ensure the user is actually authenticated
    // And is fully authorized by the server, if not it terminates the application
    ServerCheckAuthentication();

    // ========================================================================
    // STEP 5: Access user information
    // ========================================================================
    // After successful authentication, you can retrieve user data
    std::cout << "\n=== User Information ===" << std::endl;
    std::cout << "License: " << AtlasStats::GetLicense() << std::endl;
    std::cout << "Expiry: " << AtlasStats::GetExpiry() << std::endl;
    std::cout << "IP: " << AtlasStats::GetIP() << std::endl;
    std::cout << "HWID: " << AtlasStats::GetHWID() << std::endl;
    std::cout << "Level: " << AtlasStats::GetLevel() << std::endl;
    std::cout << "Note: " << AtlasStats::GetNote() << std::endl;
    std::cout << "Active Users: " << AtlasStats::GetActiveUserCount() << std::endl;
    std::cout << "Total Users: " << AtlasStats::GetUserCount() << std::endl;

    // ========================================================================
    // OPTIONAL: Download files from the server
    // ========================================================================
    // You can download up to 4 files (file slots 1-4) that you've uploaded
    // to the server through the Atlas Panel
    auto fileData = AtlasDownload(1);
    if (!fileData.empty()) {
        // Simple code to save the file if, it isnt empty -> (Sucessful download)
        std::ofstream file("downloaded_file.bin", std::ios::binary);
        file.write(reinterpret_cast<const char*>(fileData.data()), fileData.size());
        std::cout << "\nFile downloaded (" << fileData.size() << " bytes)" << std::endl;
    }

    // ========================================================================
    // Your application code continues here, performing whatever you wish!
    // ========================================================================
    std::cout << "\nPress Enter to exit program fully..." << std::endl;
    std::cin.get();
    return 0;
}

