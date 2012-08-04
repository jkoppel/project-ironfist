{
  int result; // eax@2
  __int16 v4; // ax@66
  int v5; // [sp+34h] [bp-5Ch]@4
  int v6; // [sp+38h] [bp-58h]@37
  int v7; // [sp+3Ch] [bp-54h]@3
  int v8; // [sp+40h] [bp-50h]@3
  int v9; // [sp+44h] [bp-4Ch]@3
  int v10; // [sp+48h] [bp-48h]@3
  int v11; // [sp+4Ch] [bp-44h]@1
  int v12; // [sp+50h] [bp-40h]@3
  int v13; // [sp+54h] [bp-3Ch]@3
  int v14; // [sp+58h] [bp-38h]@3
  int v15; // [sp+5Ch] [bp-34h]@3
  int v16; // [sp+60h] [bp-30h]@37
  int i; // [sp+64h] [bp-2Ch]@9
  char v18; // [sp+68h] [bp-28h]@40
  int v19; // [sp+6Ch] [bp-24h]@4
  int v20; // [sp+70h] [bp-20h]@4
  int v21[2]; // [sp+74h] [bp-1Ch]@8
  int v22; // [sp+7Ch] [bp-14h]@3
  int v23; // [sp+80h] [bp-10h]@3
  int v24; // [sp+84h] [bp-Ch]@3
  int v25; // [sp+88h] [bp-8h]@3
  int v26; // [sp+8Ch] [bp-4h]@40

  v11 = *(_BYTE *)(a2 + 9) & 0x7F;
  if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) == 1 )
  {
    result = 0;
  }
  else
  {
    v7 = 1;
    v8 = 3;
    v9 = 6;
    v10 = 12;
    v22 = 5;
    v23 = 10;
    v24 = 20;
    v25 = 40;
    v12 = 2;
    v13 = 3;
    v14 = 5;
    v15 = 10;
    if ( v11 == 12 )
    {
      v19 = 48;
      v20 = *(&v10 + (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5));
    }
    else if ( v11 == 32 )
    {
      v19 = 59;
      v20 = *(&v5 + (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5));
    }
    else
    {
      v19 = 47;
      v20 = v21[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)];
    }
    for ( i = 0; i < 5; ++i )
    {
      *((_BYTE *)gpMonGroup + i) = v19;
      *(_WORD *)((char *)gpMonGroup + 2 * i + 5) = v20;
    }
    v5 = 0;
    switch ( v11 )
    {
      case 12:
        switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
        {
          case 2u:
            v5 = (signed __int64)(flt_530730 * 500.0);
            break;
          case 3u:
            v5 = (signed __int64)(flt_530730 * 1000.0);
            break;
          case 4u:
            v5 = (signed __int64)(flt_530730 * 3000.0);
            break;
          case 5u:
            v5 = (signed __int64)(flt_530730 * 1000.0 + *(float *)&gpCurPlayer->_4[104]);
            break;
          default:
            goto LABEL_37;
        }
        break;
      case 32:
        switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
        {
          case 2u:
            v5 = (signed __int64)(flt_530730 * 1000.0);
            break;
          case 3u:
            v5 = (signed __int64)(flt_530730 * 2000.0);
            break;
          case 4u:
            v5 = (signed __int64)(flt_530730 * 5000.0);
            break;
          case 5u:
            v5 = (signed __int64)(flt_530730 * 2000.0 + *(float *)&gpCurPlayer->_4[104]);
            break;
          default:
            goto LABEL_37;
        }
        break;
      case 91:
        switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
        {
          case 2u:
            v5 = (signed __int64)(flt_530730 * 500.0);
            break;
          case 3u:
            v5 = (signed __int64)(flt_530730 * 1000.0);
            break;
          case 4u:
            v5 = (signed __int64)(flt_530730 * 2000.0);
            break;
          case 5u:
            v5 = (signed __int64)(flt_530730 * 5000.0);
            break;
          default:
            goto LABEL_37;
        }
        break;
    }
LABEL_37:
    philAI::ChooseEvaluateBattle(a1 + 101, a1, (unsigned int)gpMonGroup, 0, 0, v5, (int)&v16, (int)&v6);
    if ( a3 )
    {
      result = v6;
    }
    else
    {
      if ( v16 )
      {
        v26 = philAI::QuickCombat(a1 + 101, a1, (unsigned int)gpMonGroup, 0, 0, (float *)v21, (float *)&v18);
        if ( v26 )
        {
          switch ( v11 )
          {
            case 12:
              switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
              {
                case 2u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 500);
                  break;
                case 3u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 1000);
                  break;
                case 4u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 3000);
                  break;
                case 5u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 1000);
                  advManager::GiveRandomArtifact(gpAdvManager, (hero *)a1);
                  break;
                default:
                  goto LABEL_66;
              }
              break;
            case 32:
              switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
              {
                case 2u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 1000);
                  break;
                case 3u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 2000);
                  break;
                case 4u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 5000);
                  break;
                case 5u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 2000);
                  advManager::GiveRandomArtifact(gpAdvManager, (hero *)a1);
                  break;
                default:
                  goto LABEL_66;
              }
              break;
            case 91:
              switch ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) )
              {
                case 2u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 500);
                  break;
                case 3u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 1000);
                  break;
                case 4u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 2000);
                  break;
                case 5u:
                  advManager::GiveResource(gpAdvManager, (hero *)a1, 6, 5000);
                  break;
                default:
                  goto LABEL_66;
              }
              break;
          }
LABEL_66:
          v4 = *(_WORD *)(a2 + 4) & 7;
          LOBYTE(v4) = v4 | 8;
          *(_WORD *)(a2 + 4) = v4;
        }
      }
      result = 0;
    }
  }
  return result;
}