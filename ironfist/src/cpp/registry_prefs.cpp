#include "registry_prefs.h"

LPCSTR Heroes2RegistrySubKey = "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0";

template<> bool write_registry_pref(const std::string& pref_key, const DWORD& value)
	{
	DWORD cbData = 4;
	HKEY hKey = 0;

	if(RegOpenKeyExA(HKEY_LOCAL_MACHINE, Heroes2RegistrySubKey, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
		return false;

	if(RegSetValueExA(hKey, pref_key.c_str(), 0, REG_DWORD, (LPBYTE)&value, cbData) != ERROR_SUCCESS)
		return false;

	return true;
	}


template<> DWORD read_registry_pref(const std::string& pref_key)
	{
	DWORD Type;
	DWORD cbData = 4;
	DWORD Data = (DWORD)-1;
	HKEY hKey = 0;
	if(RegCreateKeyA(HKEY_LOCAL_MACHINE, Heroes2RegistrySubKey, &hKey) == ERROR_SUCCESS)
		{
		RegQueryValueExA(hKey, pref_key.c_str(), 0, &Type, (LPBYTE)&Data, &cbData);
		}

	return Data;
	}
