{
  signed int v2; // [sp+Ch] [bp-8h]@1
  void *v3; // [sp+10h] [bp-4h]@1

  v2 = a2;
  v3 = a1;
  switch ( a2 )
  {
    case 257:
      putSymbol((int)&models, 1, a1);
      break;
    case 258:
      putSymbol((int)&models, 2, a1);
      break;
    case 259:
      putSymbol((int)&models, 11, a1);
      break;
    case 1:
      putSymbol((int)&models, 3, a1);
      break;
    default:
      if ( a2 < 2 || a2 > 3 )
      {
        if ( a2 < 4 || a2 > 7 )
        {
          if ( a2 < 8 || a2 > 15 )
          {
            if ( a2 < 16 || a2 > 31 )
            {
              if ( a2 < 32 || a2 > 63 )
              {
                if ( a2 < 64 || a2 > 127 )
                {
                  if ( a2 < 128 || a2 > 255 )
                  {
                    panic();
                  }
                  else
                  {
                    putSymbol((int)&models, 10, a1);
                    putSymbol((int)&unk_5374FC, v2 - 127, v3);
                  }
                }
                else
                {
                  putSymbol((int)&models, 9, a1);
                  putSymbol((int)&unk_5370D8, v2 - 63, v3);
                }
              }
              else
              {
                putSymbol((int)&models, 8, a1);
                putSymbol((int)&unk_536CB4, v2 - 31, v3);
              }
            }
            else
            {
              putSymbol((int)&models, 7, a1);
              putSymbol((int)&unk_536890, v2 - 15, v3);
            }
          }
          else
          {
            putSymbol((int)&models, 6, a1);
            putSymbol((int)&unk_53646C, v2 - 7, v3);
          }
        }
        else
        {
          putSymbol((int)&models, 5, a1);
          putSymbol((int)&unk_536048, v2 - 3, v3);
        }
      }
      else
      {
        putSymbol((int)&models, 4, a1);
        putSymbol((int)&unk_535C24, v2 - 1, v3);
      }
      break;
  }
}