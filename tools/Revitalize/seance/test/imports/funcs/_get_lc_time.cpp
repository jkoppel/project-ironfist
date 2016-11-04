{
  LCID v1; // ebx@1
  LCID v2; // edi@1
  int result; // eax@2
  int v4; // ebp@3
  int v5; // ebp@3
  int v6; // ebp@3
  int v7; // ebp@3
  int v8; // ebp@3
  int v9; // ebp@3
  int v10; // ebp@3
  int v11; // ebp@3
  int v12; // ebp@3
  int v13; // ebp@3
  int v14; // ebp@3
  int v15; // ebp@3
  int v16; // ebp@3
  int v17; // ebp@3
  int v18; // ebp@3
  int v19; // ebp@3
  int v20; // ebp@3
  int v21; // ebp@3
  int v22; // ebp@3
  int v23; // ebp@3
  int v24; // ebp@3
  int v25; // ebp@3
  int v26; // ebp@3
  int v27; // ebp@3
  int v28; // ebp@3
  int v29; // ebp@3
  int v30; // ebp@3
  int v31; // ebp@3
  int v32; // ebp@3
  int v33; // ebp@3
  int v34; // ebp@3
  int v35; // ebp@3
  int v36; // ebp@3
  int v37; // ebp@3
  int v38; // ebp@3
  int v39; // ebp@3
  int v40; // ebp@3
  int v41; // ebp@3
  int v42; // ebp@3
  int v43; // ebp@3
  int v44; // ebp@3
  int v45; // ebp@3

  v1 = (unsigned __int16)word_521B60;
  v2 = (unsigned __int16)Locale_0;
  if ( a1 )
  {
    v4 = __getlocaleinfo(1, (unsigned __int16)Locale_0, 0x31u, a1 + 4);
    v5 = __getlocaleinfo(1, v2, 0x32u, a1 + 8) | v4;
    v6 = __getlocaleinfo(1, v2, 0x33u, a1 + 12) | v5;
    v7 = __getlocaleinfo(1, v2, 0x34u, a1 + 16) | v6;
    v8 = __getlocaleinfo(1, v2, 0x35u, a1 + 20) | v7;
    v9 = __getlocaleinfo(1, v2, 0x36u, a1 + 24) | v8;
    v10 = __getlocaleinfo(1, v2, 0x37u, a1) | v9;
    v11 = __getlocaleinfo(1, v2, 0x2Au, a1 + 32) | v10;
    v12 = __getlocaleinfo(1, v2, 0x2Bu, a1 + 36) | v11;
    v13 = __getlocaleinfo(1, v2, 0x2Cu, a1 + 40) | v12;
    v14 = __getlocaleinfo(1, v2, 0x2Du, a1 + 44) | v13;
    v15 = __getlocaleinfo(1, v2, 0x2Eu, a1 + 48) | v14;
    v16 = __getlocaleinfo(1, v2, 0x2Fu, a1 + 52) | v15;
    v17 = __getlocaleinfo(1, v2, 0x30u, a1 + 28) | v16;
    v18 = __getlocaleinfo(1, v2, 0x44u, a1 + 56) | v17;
    v19 = __getlocaleinfo(1, v2, 0x45u, a1 + 60) | v18;
    v20 = __getlocaleinfo(1, v2, 0x46u, a1 + 64) | v19;
    v21 = __getlocaleinfo(1, v2, 0x47u, a1 + 68) | v20;
    v22 = __getlocaleinfo(1, v2, 0x48u, a1 + 72) | v21;
    v23 = __getlocaleinfo(1, v2, 0x49u, a1 + 76) | v22;
    v24 = __getlocaleinfo(1, v2, 0x4Au, a1 + 80) | v23;
    v25 = __getlocaleinfo(1, v2, 0x4Bu, a1 + 84) | v24;
    v26 = __getlocaleinfo(1, v2, 0x4Cu, a1 + 88) | v25;
    v27 = __getlocaleinfo(1, v2, 0x4Du, a1 + 92) | v26;
    v28 = __getlocaleinfo(1, v2, 0x4Eu, a1 + 96) | v27;
    v29 = __getlocaleinfo(1, v2, 0x4Fu, a1 + 100) | v28;
    v30 = __getlocaleinfo(1, v2, 0x38u, a1 + 104) | v29;
    v31 = __getlocaleinfo(1, v2, 0x39u, a1 + 108) | v30;
    v32 = __getlocaleinfo(1, v2, 0x3Au, a1 + 112) | v31;
    v33 = __getlocaleinfo(1, v2, 0x3Bu, a1 + 116) | v32;
    v34 = __getlocaleinfo(1, v2, 0x3Cu, a1 + 120) | v33;
    v35 = __getlocaleinfo(1, v2, 0x3Du, a1 + 124) | v34;
    v36 = __getlocaleinfo(1, v2, 0x3Eu, a1 + 128) | v35;
    v37 = __getlocaleinfo(1, v2, 0x3Fu, a1 + 132) | v36;
    v38 = __getlocaleinfo(1, v2, 0x40u, a1 + 136) | v37;
    v39 = __getlocaleinfo(1, v2, 0x41u, a1 + 140) | v38;
    v40 = __getlocaleinfo(1, v2, 0x42u, a1 + 144) | v39;
    v41 = __getlocaleinfo(1, v2, 0x43u, a1 + 148) | v40;
    v42 = __getlocaleinfo(1, v2, 0x28u, a1 + 152) | v41;
    v43 = __getlocaleinfo(1, v2, 0x29u, a1 + 156) | v42;
    v44 = __getlocaleinfo(1, v1, 0x1Fu, a1 + 160) | v43;
    v45 = __getlocaleinfo(1, v1, 0x20u, a1 + 164) | v44;
    result = storeTimeFmt(v1, a1) | v45;
  }
  else
  {
    result = -1;
  }
  return result;
}
