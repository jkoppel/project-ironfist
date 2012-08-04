{
  int v3; // ST38_4@3
  int v4; // ST3C_4@3
  const void *v6; // [sp+Ch] [bp-1F0h]@1
  int v7; // [sp+10h] [bp-1ECh]@1
  int v8; // [sp+30h] [bp-1CCh]@1
  char v9; // [sp+34h] [bp-1C8h]@1
  char v10; // [sp+35h] [bp-1C7h]@1
  char v11; // [sp+1F5h] [bp-7h]@1
  int v12; // [sp+1F8h] [bp-4h]@3

  v6 = a2;
  v7 = (int)a1;
  memset(&v10, 0, 0x1C0u);
  v11 = 0;
  outputHandleJustInCase = 0;
  bsInUse = 0;
  *_errno() = 0;
  blockSize100k = 3;
  LogStr("Encode 1");
  allocateCompressStructures();
  strcpy(&v9, ".\\DATA\\");
  *(_DWORD *)(&v9 + strlen(&v9)) = dword_520650;
  *(&v9 + strlen(&v9)) = Random(65, 90);
  *(&v9 + strlen(&v9)) = Random(65, 90);
  *(&v9 + strlen(&v9)) = Random(65, 90);
  *(&v9 + strlen(&v9)) = Random(65, 90);
  v8 = open(&v9, 33537, 128);
  if ( v8 == -1 )
    FileError(&v9);
  _write(v8, v6, a3);
  _close(v8);
  compress(&v9);
  *(_DWORD *)(&v9 + strlen(&v9)) = dword_520654;
  v3 = fopen(&v9, (int)"rb");
  v12 = fseek(v3, 0, 2);
  v4 = ftell(v3);
  v12 = fseek(v3, 0, 0);
  v12 = fread(v7, v4, 1, (FILE *)v3);
  v12 = fclose(v3);
  v12 = remove(&v9);
  FreeCompressStructures();
  return v4;
}