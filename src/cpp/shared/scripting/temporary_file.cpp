#include<stdio.h>
#include <Windows.h>

#include<string>
#include<vector>

using namespace std;

vector<string> temporaryFiles;

string dumpToTemp(string& contents) {
  char tempFileName[MAX_PATH];
  GetTempFileNameA(".", "script", 0, tempFileName);

  FILE *f = fopen(tempFileName, "w");
  fputs(contents.c_str(), f);
  fclose(f);

  return string(tempFileName);
}