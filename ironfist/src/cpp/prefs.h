#ifndef PREFS_H
#define PREFS_H

#include "registry_prefs.h"
#include <string>

extern int gbUseEvilInterface;
extern char *cEvilTranslate[][2];

template<typename T> T read_pref(const std::string& key) {
  return read_registry_pref<T>(key);
}

template<typename T> bool read_pref(const std::string& key, std::string& value) {
	return read_registry_pref<T>(key, value);
}

template<typename T> bool write_pref(const std::string& key, const T& value) {
  return write_registry_pref<T>(key, value);
}

#endif
