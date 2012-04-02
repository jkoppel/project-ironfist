size_t __fastcall sub_4D6670(void *a1, const void *a2, unsigned int a3)
{
  FILE *v3; // ST3C_4@3
  size_t v4; // ST40_4@3
  const void *v6; // [sp+Ch] [bp-1F4h]@1
  void *v7; // [sp+10h] [bp-1F0h]@1
  int v8; // [sp+34h] [bp-1CCh]@1
  char v9; // [sp+38h] [bp-1C8h]@1
  char v10; // [sp+39h] [bp-1C7h]@1
  char v11; // [sp+1F9h] [bp-7h]@1
  int v12; // [sp+1FCh] [bp-4h]@3

  v6 = a2;
  v7 = a1;
  memset(&v10, 0, 0x1C0u);
  v11 = 0;
  dword_534BE0 = 0;
  dword_537928 = 0;
  *_errno() = 0;
  dword_537934 = 0;
  sub_4D38B0();
  strcpy(&v9, ".\\DATA\\");
  *(_DWORD *)(&v9 + strlen(&v9)) = dword_520664;
  *(&v9 + strlen(&v9)) = unseededNextRand(65, 90);
  *(&v9 + strlen(&v9)) = unseededNextRand(65, 90);
  *(&v9 + strlen(&v9)) = unseededNextRand(65, 90);
  *(&v9 + strlen(&v9)) = unseededNextRand(65, 90);
  *(_DWORD *)(&v9 + strlen(&v9)) = dword_520668;
  v8 = _open(&v9, 33537, 128);
  if ( v8 == -1 )
    sub_436DF0(&v9);
  _write(v8, v6, a3);
  _close(v8);
  sub_4D6290(&v9);
  *((_BYTE *)&v8 + strlen(&v9) + 1) = 0;
  v3 = fopen(&v9, "rb");
  v12 = fseek(v3, 0, 2);
  v4 = ftell(v3);
  v12 = fseek(v3, 0, 0);
  v12 = fread(v7, v4, 1u, v3);
  v12 = fclose(v3);
  v12 = remove(&v9);
  sub_4D3810();
  return v4;
}
