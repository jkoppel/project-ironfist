{
  signed __int16 result; // ax@5
  int v3; // ST24_4@10
  int v4; // ST24_4@11
  int v5; // ST24_4@12
  int v6; // [sp+Ch] [bp-60h]@4
  int v7; // [sp+14h] [bp-58h]@13
  int v8; // [sp+18h] [bp-54h]@3
  int v9; // [sp+18h] [bp-54h]@13
  int v10; // [sp+18h] [bp-54h]@20
  struct _NCB pncb; // [sp+1Ch] [bp-50h]@8
  int v12; // [sp+5Ch] [bp-10h]@13
  int *v13; // [sp+60h] [bp-Ch]@1
  __int16 v14; // [sp+64h] [bp-8h]@2
  void *v15; // [sp+68h] [bp-4h]@2

  v13 = &a2;
  switch ( a1 )
  {
    case 0:
      ++v13;
      v15 = (void *)*(v13 - 1);
      byte_512EC4[(unsigned __int8)byte_512EBC] &= 0x7Fu;
      sub_4743B0((int)v15, &dword_52FA68[16 * (unsigned __int8)byte_512EBC]);
      memset((char *)&byte_52F868 + 64 * (unsigned __int8)byte_512EBC, 0, 0x40u);
      memcpy(
        (char *)&byte_52F868 + 64 * (unsigned __int8)byte_512EBC + 26,
        &dword_52FA68[16 * (unsigned __int8)byte_512EBC],
        0x10u);
      *((_BYTE *)&byte_52F868 + 64 * (unsigned __int8)byte_512EBC) = -80;
      dword_52F894[16 * (unsigned __int8)byte_512EBC] = (int)sub_473960;
      byte_52F899[64 * (unsigned __int8)byte_512EBC] = -1;
      byte_52F898[64 * (unsigned __int8)byte_512EBC] = byte_512EB4;
      v14 = Netbios((PNCB)&byte_52F868 + (unsigned __int8)byte_512EBC);
      goto LABEL_27;
    case 1:
      ++v13;
      v8 = *(v13 - 1);
      if ( (unsigned __int8)byte_52F899[64 * v8] != 255 )
        goto LABEL_9;
      v6 = *((_BYTE *)&byte_52F868 + 64 * v8) & 0x7F;
      if ( v6 == 16 || v6 == 35 )
        return 0;
      memset(&pncb, 0, 0x40u);
      pncb.ncb_command = 53;
      pncb.ncb_lana_num = byte_512EB4;
      pncb.ncb_buffer = (PUCHAR)((char *)&byte_52F868 + 64 * v8);
      Netbios(&pncb);
LABEL_9:
      v14 = sub_473B30(v8);
      goto LABEL_27;
    case 2:
      ++v13;
      v3 = *(v13 - 1);
      sub_4743B0(*v13, &dword_52FA68[16 * v3]);
      v14 = sub_473D40(v3, &dword_52FA68[16 * v3]);
      goto LABEL_27;
    case 3:
      v4 = *v13;
      sub_473040((unsigned __int8)byte_512EBC, 0, 0);
      v14 = sub_473E10(v4, off_512ED4);
      goto LABEL_27;
    case 4:
      ++v13;
      v5 = *(v13 - 1);
      sub_4743B0(*v13, &dword_52FA68[16 * v5]);
      v14 = sub_473E10(v5, &dword_52FA68[16 * v5]);
      goto LABEL_27;
    case 5:
      ++v13;
      v12 = *(v13 - 1);
      ++v13;
      v9 = *(v13 - 1);
      ++v13;
      v7 = *(v13 - 1);
      if ( (unsigned __int8)byte_512EBC == v12 )
        byte_512EBC = v9;
      if ( *((_BYTE *)&byte_527840 + v12) == 255 )
      {
        result = 0;
      }
      else
      {
        *((_BYTE *)&byte_527840 + v9) = *((_BYTE *)&byte_527840 + v12);
        byte_512EC4[v9] = byte_512EC4[v12];
        memcpy(&dword_52FA68[16 * v9], &dword_52FA68[16 * v12], 0x10u);
        sub_474010(v9);
        if ( v7 )
        {
          *((_BYTE *)&byte_527840 + v12) = -1;
          byte_512EC4[v12] = 0;
          memset(&dword_52FA68[16 * v12], 0, 0x10u);
        }
        v14 = 0;
LABEL_27:
        if ( v14 == 255 )
          v14 = 0;
        result = v14;
      }
      return result;
    case 6:
      ++v13;
      v10 = *(v13 - 1);
      if ( (unsigned __int8)byte_52F899[64 * v10] == 255 )
      {
        memset(&pncb, 0, 0x40u);
        pncb.ncb_command = 53;
        pncb.ncb_lana_num = byte_512EB4;
        pncb.ncb_buffer = (PUCHAR)((char *)&byte_52F868 + 64 * v10);
        Netbios(&pncb);
      }
      sub_474160(v10);
      v14 = 0;
      goto LABEL_27;
    case 7:
      byte_512EC4[*v13] &= 0xF7u;
      v14 = 0;
      goto LABEL_27;
    case 9:
      memcpy((void *)v13[1], &dword_52FA68[16 * *v13], 0x10u);
      v14 = 0;
      goto LABEL_27;
    default:
      return 1;
  }
}
