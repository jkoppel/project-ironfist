{
  heroWindow *v2; // eax@1
  listBox *thisa; // esi@1
  int v4; // ebp@1
  int v5; // edx@1
  int v6; // ecx@1
  int v7; // ebx@1
  int v8; // eax@1
  int v9; // ecx@6
  int v10; // eax@7
  int v11; // ecx@11
  int v12; // edi@16
  int v13; // eax@16
  signed int result; // eax@22
  int v15; // edi@24
  int v16; // ecx@28
  int v17; // ecx@29
  __int16 v18; // ax@35
  __int16 v19; // ax@39
  int v20; // eax@42
  __int16 v21; // di@45
  int v22; // eax@45
  int v23; // ecx@53

  v2 = this->parentWindow;
  thisa = this;
  v4 = *(_DWORD *)a2;
  v5 = *(_DWORD *)(a2 + 16) - v2->xOffset;
  v6 = *(_DWORD *)(a2 + 20) - v2->yOffset;
  v7 = thisa->field_44[15];
  v8 = *(_DWORD *)(a2 + 20) - v2->yOffset - v7;
  if ( *(_DWORD *)a2 == 4 )
  {
    if ( HIBYTE(thisa->field_72[13]) )
    {
      v9 = thisa->field_44[11];
      if ( v8 <= v9 )
        v10 = 0;
      else
        v10 = (v8 - v9) / thisa->field_44[12] + 1;
      if ( v10 < 0 )
        v10 = 0;
      v11 = thisa->field_2A;
      if ( v10 >= v11 )
        v10 = v11 - 1;
      if ( v10 + thisa->field_40 == thisa->field_34 )
        return 1;
      thisa->field_34 = thisa->field_40 + v10;
    }
    else
    {
      if ( !LOBYTE(thisa->field_72[13]) )
        return 0;
      v12 = thisa->field_42;
      v13 = (v12 + 1) * (v6 - thisa->field_72[10] / 2 - thisa->field_72[0] - 4) / thisa->field_72[11];
      if ( v13 < 0 )
        v13 = 0;
      if ( v13 > v12 )
        v13 = thisa->field_42;
      if ( thisa->field_40 == v13 )
        return 1;
      thisa->field_40 = v13;
    }
    goto LABEL_59;
  }
  if ( v4 == 8 )
  {
    if ( !thisa->field_32 )
      return 1;
    v15 = thisa->field_44[14];
    if ( v5 < v15 || v6 < v7 || v15 + thisa->field_44[16] <= v5 || v7 + thisa->field_44[17] <= v6 )
    {
      if ( thisa->field_44[21] + thisa->field_44[19] <= v6 )
      {
        if ( thisa->field_72[4] > v6 )
        {
          v20 = thisa->field_72[8];
          if ( v6 >= v20 && v20 + thisa->field_72[10] > v6 )
          {
            LOBYTE(thisa->field_72[13]) = 1;
            gbSendMouseMoveMessages = 1;
          }
          v21 = thisa->field_42;
          v22 = (thisa->field_42 + 1) * (v6 - thisa->field_72[10] / 2 - thisa->field_72[0] - 4) / thisa->field_72[11];
          thisa->field_40 = v22;
          if ( (signed __int16)v22 < 0 )
            thisa->field_40 = 0;
          if ( thisa->field_40 > v21 )
            thisa->field_40 = v21;
        }
        else
        {
          v19 = thisa->field_40;
          if ( thisa->field_42 > v19 )
            thisa->field_40 = v19 + 1;
          HIBYTE(thisa->field_72[12]) = 1;
        }
      }
      else
      {
        v18 = thisa->field_40;
        if ( v18 > 0 )
          thisa->field_40 = v18 - 1;
        LOBYTE(thisa->field_72[12]) = 1;
      }
    }
    else
    {
      v16 = thisa->field_44[11];
      if ( v8 <= v16 )
        v17 = thisa->field_40;
      else
        v17 = thisa->field_40 + (v8 - v16) / thisa->field_44[12] + 1;
      if ( thisa->field_32 <= v17 )
        return 1;
      HIBYTE(thisa->field_72[13]) = 1;
      gbSendMouseMoveMessages = 1;
      if ( thisa->field_34 == v17 )
        return 1;
      thisa->field_34 = v17;
    }
LABEL_59:
    listBoxWidget::DrawLBStuff(thisa, 1);
    return 1;
  }
  if ( v4 != 16 )
    return 1;
  gbSendMouseMoveMessages = 0;
  if ( LOBYTE(thisa->field_72[12]) || HIBYTE(thisa->field_72[12]) || LOBYTE(thisa->field_72[13]) )
  {
    LOBYTE(thisa->field_72[13]) = 0;
    HIBYTE(thisa->field_72[12]) = 0;
    LOBYTE(thisa->field_72[12]) = 0;
    goto LABEL_59;
  }
  if ( HIBYTE(thisa->field_72[13]) )
  {
    HIBYTE(thisa->field_72[13]) = 0;
    *(_DWORD *)(a2 + 4) = 12;
    *(_DWORD *)a2 = 512;
    *(_DWORD *)(a2 + 8) = thisa->fieldID;
    v23 = thisa->field_34;
    *(_DWORD *)(a2 + 12) = 1;
    *(_DWORD *)(a2 + 24) = v23;
    if ( thisa->field_36 == thisa->field_34 )
    {
      if ( KBTickCount() < *(_DWORD *)&thisa->field_38 + 400 )
        *(_DWORD *)(a2 + 12) = 2;
    }
    thisa->field_36 = thisa->field_34;
    *(_DWORD *)&thisa->field_38 = KBTickCount();
    result = 2;
  }
  else
  {
    result = 0;
  }
  return result;
}