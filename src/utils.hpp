/// Bits and pieces that we need
#pragma once

#include "Rackspace.hpp"
#include "config_reader/config.hpp"

namespace cdnalizerd {

std::string getContainerUrl(const Rackspace &login, const ConfigEntry &config);

/// Returns true if 'path' is a directory
bool isDir(const char *path);

/// Calls 'callback' for each subdir (but not for each file)
void walkDir(const char *path, std::function<void(const char *)> callback);

/// Joins two urls with exactly one path separator
std::string joinPaths(const std::string &base, const std::string &extra);
}
