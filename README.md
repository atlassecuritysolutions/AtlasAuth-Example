# Atlas Auth - Example Integration

![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B17-orange.svg)

This example demonstrates how to integrate Atlas Auth into a C++ application. It showcases the complete authentication workflow in a clear and concise manner.

---

## What This Example Demonstrates

This example covers:
1. Initializing the authentication system  
2. Authenticating a user with a license key  
3. Displaying user information (license, expiration, level, hardware ID, IP address)  
4. Displaying live usage statistics (active users and total users)  
5. Verifying authentication and ban status  

---

## Example Code

```cpp
#include <iostream>
#include "Atlas Auth.h"

int main() {
    // Step 1: Initialize with your API key
    AtlasAuth::AuthenticationStartup("YOUR_API_KEY_HERE");

    // Step 2: Get license from user
    std::cout << "Enter your license key: ";
    std::string license;
    std::getline(std::cin, license);

    // Step 3: Authenticate
    if (AtlasAuth::Authenticate(license)) {
        std::cout << "
=== Authentication Successful ===" << std::endl;
        std::cout << "License: " << AtlasStats::GetLicense() << std::endl;
        std::cout << "Expiry: " << AtlasStats::GetExpiry() << std::endl;
        std::cout << "Level: " << AtlasStats::GetLevel() << std::endl;
        std::cout << "Note: " << AtlasStats::GetNote() << std::endl;
        std::cout << "HWID: " << AtlasStats::GetHWID() << std::endl;
        std::cout << "IP: " << AtlasStats::GetIP() << std::endl;
        std::cout << "
Active Users: " << AtlasStats::GetActiveUserCount() << std::endl;
        std::cout << "Total Users: " << AtlasStats::GetUserCount() << std::endl;

        std::cout << "
Press Enter to exit...";
        std::cin.get();
    } else {
        std::cout << "Authentication failed: " << AtlasStats::GetErrorMessage() << std::endl;
    }

    return 0;
}
```

---

## Quick Start

1. Obtain your API key from the Atlas Auth Panel (create an application first).  
2. Replace `"YOUR_API_KEY_HERE"` in the code with your actual API key.  
3. Build and run the example.  
4. Enter a license key when prompted.  
5. View the resulting authentication details.  

---

## Requirements

- Windows (x64)  
- Visual Studio 2019 or later  
- C++17 support  
- Atlas Auth library files  

---

## Key Functions Used

| Function | Description |
|----------|-------------|
| `AtlasAuth::AuthenticationStartup(apiKey)` | Initializes the system with your API key |
| `AtlasAuth::Authenticate(license)` | Validates the provided license key |
| `AtlasStats::GetLicense()` | Returns the user's license key |
| `AtlasStats::GetExpiry()` | Returns the license expiration date |
| `AtlasStats::GetLevel()` | Returns the license level |
| `AtlasStats::GetNote()` | Returns the custom note attached to the license |
| `AtlasStats::GetHWID()` | Returns the hardware ID |
| `AtlasStats::GetIP()` | Returns the user's IP address |
| `AtlasStats::GetActiveUserCount()` | Returns the number of active users |
| `AtlasStats::GetUserCount()` | Returns the total number of users |
| `AtlasStats::IsAuthenticated()` | Checks whether the session is authenticated |
| `AtlasStats::IsBanned()` | Indicates whether the user is banned |
| `AtlasStats::GetErrorMessage()` | Provides details on authentication errors |

---

## Atlas Auth Panel Overview

The Atlas Auth Panel provides full management control, including:

### Available Actions

- Create and manage applications  
- Generate license keys  
- Set license expiration dates and levels  
- View all active licenses  
- Reset hardware bindings  
- Ban or unban users  
- View real-time user sessions  
- Monitor active user statistics  
- Upload or distribute files to users  
- Add custom notes to licenses  
- Delete applications  

### Panel Features

- Secure two-factor authentication  
- Real-time statistics dashboard  
- Modern, clean interface  
- Automatic session updates  
- Optional automatic login  
- Responsive layout for all screen sizes  

---

## Tips

- The heartbeat system runs every 5 seconds to keep statistics up to date.  
- Always check `AtlasStats::IsAuthenticated()` before performing any sensitive logic.  
- Use `AtlasStats::GetErrorMessage()` to diagnose authentication failures.  
- License levels (1–10+) allow you to implement tiered access such as Basic or Premium.  

---

## Security Note

```cpp
AtlasAuth::AuthenticationStartup(S("YOUR_API_KEY_HERE"));
```

---

## Support

- Refer to the full API documentation included with the library  
- Report issues through the project's GitHub repository  
- Contact Atlas Auth support for further assistance  

---

<div align="center">
<strong>Start protecting your application today.</strong>
</div>
