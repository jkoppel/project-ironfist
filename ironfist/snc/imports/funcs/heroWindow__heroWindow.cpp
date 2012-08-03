{
  int fileID; // ST78_4@1
  __int16 code; // ax@3
  heroWindow *thisa; // [sp+10h] [bp-64h]@1
  listBox *v8; // [sp+14h] [bp-60h]@49
  int v9; // [sp+18h] [bp-5Ch]@45
  int v10; // [sp+1Ch] [bp-58h]@41
  int v11; // [sp+20h] [bp-54h]@37
  int v12; // [sp+24h] [bp-50h]@33
  int v13; // [sp+28h] [bp-4Ch]@29
  int v14; // [sp+2Ch] [bp-48h]@25
  textWidget *v15; // [sp+30h] [bp-44h]@21
  int v16; // [sp+34h] [bp-40h]@17
  iconWidget *v17; // [sp+38h] [bp-3Ch]@13
  button *v18; // [sp+3Ch] [bp-38h]@9
  border *v19; // [sp+40h] [bp-34h]@5
  widget *guiObj; // [sp+44h] [bp-30h]@3
  textWidget *v21; // [sp+48h] [bp-2Ch]@22
  textEntryWidget *v22; // [sp+4Ch] [bp-28h]@26
  textEntryWidget *v23; // [sp+4Ch] [bp-28h]@30
  textEntryWidget *v24; // [sp+4Ch] [bp-28h]@34
  textEntryWidget *v25; // [sp+4Ch] [bp-28h]@38
  textEntryWidget *v26; // [sp+4Ch] [bp-28h]@42
  iconWidget *this; // [sp+50h] [bp-24h]@14
  button *v28; // [sp+54h] [bp-20h]@10
  int v29; // [sp+58h] [bp-1Ch]@46
  border *bg; // [sp+5Ch] [bp-18h]@6
  int v31; // [sp+64h] [bp-10h]@18
  listBox *v32; // [sp+68h] [bp-Ch]@50
  signed int done; // [sp+6Ch] [bp-8h]@1

  thisa = ecx0;
  strcpy(ecx0->filename, a2);
  fileID = resourceManager::MakeId(gpResourceManager, a2, 1);
  resourceManager::PointToFile(gpResourceManager, fileID);
  thisa->bitmap = 0;
  thisa->prevWindow = 0;
  thisa->nextWindow = thisa->prevWindow;
  thisa->flags2 = 0;
  thisa->idx = -1;
  thisa->xOffset = xOff;
  thisa->yOffset = yOff;
  thisa->width = resourceManager::ReadWord(gpResourceManager);
  thisa->height = resourceManager::ReadWord(gpResourceManager);
  thisa->flags1 = resourceManager::ReadWord(gpResourceManager);
  thisa->flags1 |= 0x4000u;
  thisa->firstComponent = NULL;
  thisa->lastComponent = thisa->firstComponent;
  done = 0;
  while ( !done )
  {
    PollSound();
    code = resourceManager::ReadWord(gpResourceManager);
    guiObj = 0;
    if ( code > 8 )
    {
      if ( code > 64 )
      {
        if ( code > 513 )
        {
          switch ( code )
          {
            case 514:
              v12 = (int)operator new(sizeof(textEntryWidget));
              if ( v12 )
                v24 = textEntryWidget::textEntryWidget(v12);
              else
                v24 = 0;
              textEntryWidget::Read(v24, 3);
              guiObj = (widget *)v24;
              break;
            case 516:
              v11 = (int)operator new(78);
              if ( v11 )
                v25 = textEntryWidget::textEntryWidget(v11);
              else
                v25 = 0;
              textEntryWidget::Read(v25, 4);
              guiObj = (widget *)v25;
              break;
            case 518:
              v10 = (int)operator new(78);
              if ( v10 )
                v26 = textEntryWidget::textEntryWidget(v10);
              else
                v26 = 0;
              textEntryWidget::Read(v26, 5);
              guiObj = (widget *)v26;
              break;
            case 515:
              v9 = (int)operator new(180);
              if ( v9 )
                v29 = dropListWidget::dropListWidget(v9);
              else
                v29 = 0;
              dropListWidget::Read(v29);
              guiObj = (widget *)v29;
              break;
            case 517:
              v8 = (listBox *)operator new(146);
              if ( v8 )
                v32 = listBoxWidget::listBoxWidget(v8);
              else
                v32 = 0;
              listBoxWidget::Read(v32);
              guiObj = (widget *)v32;
              break;
            default:
              break;
          }
        }
        else if ( code == 513 )
        {
          v13 = (int)operator new(sizeof(textEntryWidget));
          if ( v13 )
            v23 = textEntryWidget::textEntryWidget(v13);
          else
            v23 = 0;
          textEntryWidget::Read(v23, 2);
          guiObj = (widget *)v23;
        }
        else if ( code == 256 )
        {
          v14 = (int)operator new(sizeof(textEntryWidget));
          if ( v14 )
            v22 = textEntryWidget::textEntryWidget(v14);
          else
            v22 = 0;
          textEntryWidget::Read(v22, 1);
          guiObj = (widget *)v22;
        }
      }
      else if ( code == 64 )
      {
        v16 = (int)operator new(32);
        if ( v16 )
          v31 = dimmerWidget::dimmerWidget(v16);
        else
          v31 = 0;
        dimmerWidget::Read(v31);
        guiObj = (widget *)v31;
      }
      else if ( code == 16 )
      {
        v17 = (iconWidget *)operator new(0x2Du);
        if ( v17 )
          this = iconWidget::iconWidget(v17);
        else
          this = 0;
        iconWidget::Read(this);
        guiObj = (widget *)this;
      }
    }
    else if ( code == 8 )
    {
      v15 = (textWidget *)operator new(43);
      if ( v15 )
        v21 = textWidget::textWidget(v15);
      else
        v21 = 0;
      textWidget::Read(v21);
      guiObj = (widget *)v21;
    }
    else if ( code )
    {
      if ( code == 1 )
      {
        v19 = (border *)operator new(42);
        if ( v19 )
          bg = border::border(v19);
        else
          bg = 0;
        border::Read(bg);
        guiObj = (widget *)bg;
      }
      else if ( code == 2 )
      {
        v18 = (button *)operator new(48);
        if ( v18 )
          v28 = button::button(v18);
        else
          v28 = 0;
        button::Read(v28);
        guiObj = (widget *)v28;
      }
    }
    else
    {
      done = 1;
    }
    if ( !done )
    {
      if ( guiObj )
        heroWindow::AddWidget(thisa, guiObj, -1);
    }
  }
  return thisa;
}