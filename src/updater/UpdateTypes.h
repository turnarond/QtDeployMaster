// src/updater/UpdateTypes.h
#pragma once
#include <string>
#include <cstdint>

// Update check state machine
enum class UpdateState {
    Idle,
    Checking,
    Ready,        // new version available
    Downloading,
    Installed,    // download + verification complete, ready to install
    Error         // silent error (network/parse failure)
};

// GitHub Release parse result
struct ReleaseInfo {
    std::string tagName;        // "v2.2.0"
    std::string htmlUrl;        // release page URL
    std::string body;           // release notes (markdown)
    std::string assetName;      // "DeviceForge-v2.2.0-win64.zip"
    std::string downloadUrl;    // browser_download_url
    int64_t     assetSize = 0;  // bytes
    bool        isNewer = false; // tag > current?
};

// Semantic version
struct Version {
    int major = 0;
    int minor = 0;
    int patch = 0;

    std::string toString() const {
        return std::to_string(major) + "." +
               std::to_string(minor) + "." +
               std::to_string(patch);
    }
};

// Parse "v2.1.0" or "2.1.0" -> Version
inline Version parseVersion(const std::string& tag) {
    Version v;
    const char* s = tag.c_str();
    if (*s == 'v' || *s == 'V') ++s;
    v.major = std::atoi(s);
    while (*s && *s != '.') ++s; if (*s == '.') ++s;
    v.minor = std::atoi(s);
    while (*s && *s != '.') ++s; if (*s == '.') ++s;
    v.patch = std::atoi(s);
    return v;
}

// Returns: <0 (a older), 0 (same), >0 (a newer)
inline int compareVersion(const Version& a, const Version& b) {
    if (a.major != b.major) return a.major - b.major;
    if (a.minor != b.minor) return a.minor - b.minor;
    return a.patch - b.patch;
}
