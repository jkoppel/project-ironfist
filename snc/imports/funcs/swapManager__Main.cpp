{
  signed int v2; // ST4C_4@15
  signed int result; // eax@99
  int v4; // [sp+10h] [bp-24h]@4
  int v5; // [sp+14h] [bp-20h]@1
  int v6; // [sp+18h] [bp-1Ch]@1
  signed int v7; // [sp+20h] [bp-14h]@10
  int a2a; // [sp+24h] [bp-10h]@10
  int v9; // [sp+28h] [bp-Ch]@20
  int v10; // [sp+28h] [bp-Ch]@36
  signed int v11; // [sp+2Ch] [bp-8h]@1
  bool a3; // [sp+30h] [bp-4h]@1

  v6 = this;
  v11 = 0;
  a3 = (*(_BYTE *)(a2 + 13) & 2) != 0;
  v5 = *(_DWORD *)a2;
  if ( v5 == 32 )
  {
    if ( !(*(_BYTE *)(a2 + 13) & 2) )
    {
      swapManager::Reset(this);
      swapManager::Update((void *)v6);
      swapManager::DrawSwapWin(v6);
    }
  }
  else
  {
    if ( v5 != 512 )
      goto LABEL_98;
    v4 = *(_DWORD *)(a2 + 4);
    if ( v4 == 12 )
    {
LABEL_88:
      switch ( *(_DWORD *)(a2 + 8) )
      {
        case 0xC8:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
        case 0xCD:
        case 0xCE:
        case 0xCF:
          v7 = 0;
          a2a = *(_DWORD *)(a2 + 8) - 200;
          goto LABEL_14;
        case 0xD8:
        case 0xD9:
        case 0xDA:
        case 0xDB:
        case 0xDC:
        case 0xDD:
        case 0xDE:
        case 0xDF:
          v7 = 0;
          a2a = *(_DWORD *)(a2 + 8) - 216;
          goto LABEL_14;
        case 0xD0:
        case 0xD1:
        case 0xD2:
        case 0xD3:
        case 0xD4:
        case 0xD5:
        case 0xD6:
        case 0xD7:
          v7 = 1;
          a2a = *(_DWORD *)(a2 + 8) - 208;
          goto LABEL_14;
        case 0xE0:
        case 0xE1:
        case 0xE2:
        case 0xE3:
        case 0xE4:
        case 0xE5:
        case 0xE6:
        case 0xE7:
          v7 = 1;
          a2a = *(_DWORD *)(a2 + 8) - 224;
LABEL_14:
          if ( *(_DWORD *)(*(_DWORD *)(this + 4 * v7 + 62) + 144) > a2a )
          {
            v2 = hero::GetNthSS(*(hero **)(this + 4 * v7 + 62), a2a);
            hero::DoSSLevelDialog(*(hero **)(v6 + 4 * v7 + 62), (SECONDARY_SKILL)v2, a3);
          }
          break;
        case 0x41:
          if ( !(*(_BYTE *)(a2 + 13) & 2) )
          {
            HeroView(*(_BYTE *)(*(_DWORD *)(this + 62) + 2), 1, 0);
            advManager::RedrawAdvScreen(gpAdvManager, 1, 0);
            swapManager::Update((void *)v6);
            swapManager::DrawSwapWin(v6);
            swapManager::Reset(v6);
            heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
          }
          break;
        case 0x42:
          if ( !(*(_BYTE *)(a2 + 13) & 2) )
          {
            HeroView(*(_BYTE *)(*(_DWORD *)(this + 66) + 2), 1, 0);
            advManager::RedrawAdvScreen(gpAdvManager, 1, 0);
            swapManager::Update((void *)v6);
            swapManager::DrawSwapWin(v6);
            swapManager::Reset(v6);
            heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
          }
          break;
        case 0x58:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x5E:
        case 0x5F:
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        case 0x64:
        case 0x65:
          v9 = *(_DWORD *)(a2 + 8) - 88;
          if ( *(_BYTE *)(a2 + 13) & 2 || *(_BYTE *)(*(_DWORD *)(this + 62) + v9 + 213) != 81 )
          {
            if ( *(_BYTE *)(a2 + 13) & 2 )
            {
              if ( *(_BYTE *)(*(_DWORD *)(this + 62) + v9 + 213) != -1 )
                hero::ViewArtifact(
                  (ARTIFACT)*(_BYTE *)(*(_DWORD *)(this + 62) + v9 + 213),
                  1u,
                  *(_BYTE *)(*(_DWORD *)(this + 62) + v9 + 236));
            }
            else if ( *(_DWORD *)(this + 86) == 1 )
            {
              *(_DWORD *)(this + 74) = 0;
              *(_DWORD *)(this + 82) = v9;
              if ( *(_DWORD *)(this + 70) || *(_DWORD *)(this + 78) != *(_DWORD *)(this + 82) )
              {
                swapManager::SwapArtifacts(this);
                swapManager::Reset(v6);
              }
              else
              {
                hero::ViewArtifact(
                  (ARTIFACT)*(_BYTE *)(*(_DWORD *)(this + 62) + v9 + 213),
                  0,
                  *(_BYTE *)(*(_DWORD *)(this + 62) + v9 + 236));
                swapManager::Reset(v6);
              }
            }
            else if ( *(_BYTE *)(*(_DWORD *)(this + 62) + v9 + 213) == -1 )
            {
              swapManager::Reset(this);
            }
            else
            {
              *(_DWORD *)(this + 70) = 0;
              *(_DWORD *)(this + 74) = -1;
              *(_DWORD *)(this + 86) = 1;
              *(_DWORD *)(this + 78) = v9;
              *(_DWORD *)(this + 82) = -1;
            }
          }
          else
          {
            NormalDialog("This item can't be traded.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          break;
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6A:
        case 0x6B:
        case 0x6C:
        case 0x6D:
        case 0x6E:
        case 0x6F:
        case 0x70:
        case 0x71:
        case 0x72:
        case 0x73:
          v10 = *(_DWORD *)(a2 + 8) - 102;
          if ( *(_BYTE *)(a2 + 13) & 2 || *(_BYTE *)(*(_DWORD *)(this + 66) + v10 + 213) != 81 )
          {
            if ( *(_BYTE *)(a2 + 13) & 2 )
            {
              if ( *(_BYTE *)(*(_DWORD *)(this + 66) + v10 + 213) != -1 )
                hero::ViewArtifact(
                  (ARTIFACT)*(_BYTE *)(*(_DWORD *)(this + 66) + v10 + 213),
                  1u,
                  *(_BYTE *)(*(_DWORD *)(this + 66) + v10 + 236));
            }
            else if ( *(_DWORD *)(this + 86) == 1 )
            {
              *(_DWORD *)(this + 74) = 1;
              *(_DWORD *)(this + 82) = v10;
              if ( *(_DWORD *)(this + 70) != 1 || *(_DWORD *)(this + 78) != *(_DWORD *)(this + 82) )
              {
                swapManager::SwapArtifacts(this);
                swapManager::Reset(v6);
              }
              else
              {
                hero::ViewArtifact(
                  (ARTIFACT)*(_BYTE *)(*(_DWORD *)(this + 66) + v10 + 213),
                  0,
                  *(_BYTE *)(*(_DWORD *)(this + 66) + v10 + 236));
                swapManager::Reset(v6);
              }
            }
            else if ( *(_BYTE *)(*(_DWORD *)(this + 66) + v10 + 213) == -1 )
            {
              swapManager::Reset(this);
            }
            else
            {
              *(_DWORD *)(this + 70) = 1;
              *(_DWORD *)(this + 74) = -1;
              *(_DWORD *)(this + 86) = 1;
              *(_DWORD *)(this + 78) = v10;
              *(_DWORD *)(this + 82) = -1;
            }
          }
          else
          {
            NormalDialog("This item can't be traded.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          break;
        case 0x4E:
        case 0x4F:
        case 0x50:
        case 0x51:
        case 0x52:
          if ( *(_BYTE *)(a2 + 13) & 2 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(a2 + 8) + *(_DWORD *)(this + 62) + 23) != -1 )
              game::ViewArmy(
                gpGame,
                119,
                20,
                (CREATURES)*(_BYTE *)(*(_DWORD *)(a2 + 8) + *(_DWORD *)(this + 62) + 23),
                *(_WORD *)(*(_DWORD *)(this + 62) + 2 * *(_DWORD *)(a2 + 8) - 50),
                0,
                0,
                1u,
                1,
                *(hero **)(this + 62),
                0,
                (armyGroup *)(*(_DWORD *)(this + 62) + 101),
                *(_DWORD *)(a2 + 8) - 78);
          }
          else if ( *(_DWORD *)(this + 86) )
          {
            if ( *(_BYTE *)(*(_DWORD *)(a2 + 8) + *(_DWORD *)(this + 62) + 23) == -1 )
            {
              swapManager::Reset(this);
            }
            else
            {
              *(_DWORD *)(this + 70) = 0;
              *(_DWORD *)(this + 74) = -1;
              *(_DWORD *)(this + 86) = 0;
              *(_DWORD *)(this + 78) = *(_DWORD *)(a2 + 8) - 78;
              *(_DWORD *)(this + 82) = -1;
            }
          }
          else
          {
            *(_DWORD *)(this + 74) = 0;
            *(_DWORD *)(this + 82) = *(_DWORD *)(a2 + 8) - 78;
            if ( *(_DWORD *)(this + 70) || *(_DWORD *)(this + 78) != *(_DWORD *)(this + 82) )
            {
              if ( *(_BYTE *)(a2 + 12) & 3
                && (*(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 74) + 62) + *(_DWORD *)(this + 82) + 101) == -1
                 || *(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + *(_DWORD *)(this + 78) + 101) == *(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 74) + 62) + *(_DWORD *)(this + 82) + 101)) )
              {
                swapManager::SplitMons(this);
                swapManager::Reset(v6);
              }
              else
              {
                swapManager::SwapMons(this);
                swapManager::Reset(v6);
              }
            }
            else
            {
              swapManager::ViewMon(this);
              swapManager::Reset(v6);
            }
          }
          break;
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
          if ( *(_BYTE *)(a2 + 13) & 2 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(a2 + 8) + *(_DWORD *)(this + 66) + 18) != -1 )
              game::ViewArmy(
                gpGame,
                119,
                20,
                (CREATURES)*(_BYTE *)(*(_DWORD *)(a2 + 8) + *(_DWORD *)(this + 66) + 18),
                *(_WORD *)(*(_DWORD *)(this + 66) + 2 * *(_DWORD *)(a2 + 8) - 60),
                0,
                0,
                1u,
                1,
                *(hero **)(this + 66),
                0,
                (armyGroup *)(*(_DWORD *)(this + 66) + 101),
                *(_DWORD *)(a2 + 8) - 83);
          }
          else if ( *(_DWORD *)(this + 86) )
          {
            if ( *(_BYTE *)(*(_DWORD *)(a2 + 8) + *(_DWORD *)(this + 66) + 18) == -1 )
            {
              swapManager::Reset(this);
            }
            else
            {
              *(_DWORD *)(this + 70) = 1;
              *(_DWORD *)(this + 74) = -1;
              *(_DWORD *)(this + 86) = 0;
              *(_DWORD *)(this + 78) = *(_DWORD *)(a2 + 8) - 83;
              *(_DWORD *)(this + 82) = -1;
            }
          }
          else
          {
            *(_DWORD *)(this + 74) = 1;
            *(_DWORD *)(this + 82) = *(_DWORD *)(a2 + 8) - 83;
            if ( *(_DWORD *)(this + 70) != 1 || *(_DWORD *)(this + 78) != *(_DWORD *)(this + 82) )
            {
              if ( *(_BYTE *)(a2 + 12) & 3
                && (*(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 74) + 62) + *(_DWORD *)(this + 82) + 101) == -1
                 || *(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + *(_DWORD *)(this + 78) + 101) == *(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 74) + 62) + *(_DWORD *)(this + 82) + 101)) )
              {
                swapManager::SplitMons(this);
                swapManager::Reset(v6);
              }
              else
              {
                swapManager::SwapMons(this);
                swapManager::Reset(v6);
              }
            }
            else
            {
              swapManager::ViewMon(this);
              swapManager::Reset(v6);
            }
          }
          break;
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4A:
        case 0x4B:
        case 0x4C:
        case 0x4D:
        case 0x74:
        case 0x75:
        case 0x76:
        case 0x77:
        case 0x78:
        case 0x79:
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
        case 0x80:
        case 0x81:
        case 0x82:
        case 0x83:
        case 0x84:
        case 0x85:
        case 0x86:
        case 0x87:
        case 0x88:
        case 0x89:
        case 0x8A:
        case 0x8B:
        case 0x8C:
        case 0x8D:
        case 0x8E:
        case 0x8F:
        case 0x90:
        case 0x91:
        case 0x92:
        case 0x93:
        case 0x94:
        case 0x95:
        case 0x96:
        case 0x97:
        case 0x98:
        case 0x99:
        case 0x9A:
        case 0x9B:
        case 0x9C:
        case 0x9D:
        case 0x9E:
        case 0x9F:
        case 0xA0:
        case 0xA1:
        case 0xA2:
        case 0xA3:
        case 0xA4:
        case 0xA5:
        case 0xA6:
        case 0xA7:
        case 0xA8:
        case 0xA9:
        case 0xAA:
        case 0xAB:
        case 0xAC:
        case 0xAD:
        case 0xAE:
        case 0xAF:
        case 0xB0:
        case 0xB1:
        case 0xB2:
        case 0xB3:
        case 0xB4:
        case 0xB5:
        case 0xB6:
        case 0xB7:
        case 0xB8:
        case 0xB9:
        case 0xBA:
        case 0xBB:
        case 0xBC:
        case 0xBD:
        case 0xBE:
        case 0xBF:
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC3:
        case 0xC4:
        case 0xC5:
        case 0xC6:
        case 0xC7:
          break;
      }
      if ( !a3 )
      {
        swapManager::Update((void *)v6);
        swapManager::DrawSwapWin(v6);
        swapManager::DrawSelector(v6);
      }
      goto LABEL_98;
    }
    if ( v4 != 13 )
    {
      if ( v4 != 14 )
        goto LABEL_98;
      goto LABEL_88;
    }
    if ( !(*(_BYTE *)(a2 + 13) & 2) && *(_DWORD *)(a2 + 8) == 30720 )
      v11 = 1;
  }
LABEL_98:
  if ( v11 == 1 )
  {
    *(_DWORD *)a2 = 16384;
    *(_DWORD *)(a2 + 4) = 4;
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}