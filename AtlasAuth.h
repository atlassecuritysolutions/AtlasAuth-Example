#pragma once
#include <string>
#include <vector>

// ============================================================================
// ATLAS AUTHENTICATION LIBRARY - API REFERENCE
// ============================================================================
// This header provides all the functions you need to integrate Atlas Auth
// into your application. See the example below for usage.
// ============================================================================

// Initialize the authentication system with your API key
// Call this ONCE at the start of your program, before any other Atlas functions
void AuthenticationStartup(std::string APIKEY);

// Authenticate a user with their license key
// Returns true if authentication succeeds, false otherwise
bool login(const std::string& license_key);

// Verify the user's session is still valid with the server
// Call this periodically to ensure the user hasn't been banned/expired and is allowed fully by the server
bool ServerCheckAuthentication();

// Download a file from the server (files 1-4)
// Returns the file data as a byte vector, or empty vector on failure
std::vector<uint8_t> AtlasDownload(int file_id_1_to_4);

// Report a user for banning (requires appropriate permissions)
// Useful for implementing your own anti-tamper or security measures
bool BanUser(const std::string& ban_reason);

// ============================================================================
// ATLAS STATS API
// ============================================================================

namespace AtlasStats {


    // Authentication Status
    bool IsAuthenticated();
    bool IsBanned();

    // User information that is set after a login
    std::string GetLicense();
    std::string GetIP();
    std::string GetHWID();
    std::string GetExpiry();
    std::string GetNote();
    std::string GetLevel();

    // Live server statistics about the application
    std::string GetActiveUserCount();
    std::string GetUserCount();

    // Error fetching/sourcing for all errors/issues within the authentication
    std::string GetErrorMessage();
    void ClearError();
    bool HasError();

    // Secure and 100% guaranteed to shutdown the program fully
    void AtlasForceExit();

}