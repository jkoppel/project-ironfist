#ifndef REGISTRY_PREFS_H
#define REGISTRY_PREFS_H

#include <Windows.h>
#include <string>

template<typename T> T read_registry_pref(const std::string& pref_key);
template<typename T> bool read_registry_pref(const std::string& pref_key, T& value);
template<typename T> bool write_registry_pref(const std::string& pref_key, const T& value);

#endif
