#ifndef REGISTRY_PREFS_H
#define REGISTRY_PREFS_H

#include <Windows.h>
#include <string>

template<typename T> T read_registry_pref(const std::string& pref_key);

template<> DWORD read_registry_pref(const std::string& pref_key)
	{
	DWORD Type;
	DWORD cbData = 4;
	DWORD Data = (DWORD)-1;
	LPCSTR SubKey = "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0";
	HKEY hKey = nullptr;
	if(RegCreateKeyA(HKEY_LOCAL_MACHINE, SubKey, &hKey) == ERROR_SUCCESS)
		{
		RegQueryValueExA(hKey, pref_key.c_str(), 0, &Type, (LPBYTE)&Data, &cbData);
		}

	return Data;
	}

template<typename T> bool write_registry_pref(const std::string& pref_key, const T& value);

template<> bool write_registry_pref(const std::string& pref_key, const DWORD& value)
	{
	DWORD cbData = 4;
	LPCSTR SubKey = "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0";
	HKEY hKey = nullptr;

	if(RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &hKey) != ERROR_SUCCESS)
		return false;

	if(RegSetValueExA(hKey, pref_key.c_str(), 0, REG_DWORD, (LPBYTE)&value, cbData) != ERROR_SUCCESS)
		return false;

	return true;
	}


#endif
