
  ManagerVtable *vtable;
  AbstractManager *next;
  AbstractManager *prev;
  MANAGER_TYPE type;
  int idx;
  char name[30];
  int ready;
  AbstractResource *loadedFileLinkedList;
  int numOpenAGGFiles;
  int curHandleIdx;
  int fileDescriptors[2];
  FileInAGGInfo *aggContentInfo[2];
  int numberOfFilesInAGG[2];
  int isFreeingAllResources;
  int field_5E;
  char resourceToLoad[60];
  int fileID;
