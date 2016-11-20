#include "registry_prefs.h"
#include "gui/dialog.h"

LPCSTR heroes2RegistrySubKey = "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0";

template<> bool write_registry_pref(const std::string& pref_key, const DWORD& value) {
  DWORD cbData = 4;
  HKEY hKey = 0;

  if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, heroes2RegistrySubKey, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS) {
    return false;
  }

  if (RegSetValueExA(hKey, pref_key.c_str(), 0, REG_DWORD, (LPBYTE)&value, cbData) != ERROR_SUCCESS) {
    return false;
  }

  return true;
}


template<> DWORD read_registry_pref(const std::string& pref_key) {
  DWORD Type;
  DWORD cbData = 4;
  DWORD Data = (DWORD)-1;
  HKEY hKey = 0;
  if (RegCreateKeyA(HKEY_LOCAL_MACHINE, heroes2RegistrySubKey, &hKey) == ERROR_SUCCESS) {
    RegQueryValueExA(hKey, pref_key.c_str(), 0, &Type, (LPBYTE)&Data, &cbData);
  }

  return Data;
}

template<> bool write_registry_pref(const std::string& pref_key, const std::string& value) {
	HKEY hKey = 0;

	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, heroes2RegistrySubKey, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS) {
		return false;
	}

	if (RegSetValueExA(hKey, pref_key.c_str(), 0, REG_SZ, (const BYTE*)value.c_str(), value.size() + 1) != ERROR_SUCCESS) {
		return false;
	}

	return true;
}

template<> std::string read_registry_pref(const std::string& pref_key) {
	HKEY hKey = 0;

	CHAR data[512];
	DWORD cbData = sizeof(data);

	if (RegCreateKeyA(HKEY_LOCAL_MACHINE, heroes2RegistrySubKey, &hKey) == ERROR_SUCCESS) {
		RegQueryValueExA(hKey, pref_key.c_str(), 0, NULL, (LPBYTE)data, &cbData);
	}
	std::string sdata(data);
	return sdata;
}

template<> bool read_registry_pref(const std::string& pref_key, std::string& value) {
	HKEY hKey = 0;

	CHAR data[512];
	DWORD cbData = sizeof(data);

	if (RegCreateKeyA(HKEY_LOCAL_MACHINE, heroes2RegistrySubKey, &hKey) != ERROR_SUCCESS) {
		return false;
	}

	if (RegQueryValueExA(hKey, pref_key.c_str(), 0, NULL, (LPBYTE)data, &cbData) != ERROR_SUCCESS) {
		return false;
	}

	std::string sdata(data);
	value = sdata;
	return true;
}
