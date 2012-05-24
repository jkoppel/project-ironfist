GUIWindow *__thiscall GUIWindow_constructorFromFile(GUIWindow *ecx0, int xOff, int yOff, const char *filename)
{
  int fileID; // ST78_4@1
  __int16 code; // ax@3
  GUIWindow *thisa; // [sp+10h] [bp-64h]@1
  ListBox *v8; // [sp+14h] [bp-60h]@49
  int v9; // [sp+18h] [bp-5Ch]@45
  int v10; // [sp+1Ch] [bp-58h]@41
  int v11; // [sp+20h] [bp-54h]@37
  int v12; // [sp+24h] [bp-50h]@33
  int v13; // [sp+28h] [bp-4Ch]@29
  int v14; // [sp+2Ch] [bp-48h]@25
  TextWidget *v15; // [sp+30h] [bp-44h]@21
  int v16; // [sp+34h] [bp-40h]@17
  GUIIcon *v17; // [sp+38h] [bp-3Ch]@13
  Button *v18; // [sp+3Ch] [bp-38h]@9
  BackgroundGUI *v19; // [sp+40h] [bp-34h]@5
  AbstractGUIComponent *guiObj; // [sp+44h] [bp-30h]@3
  TextWidget *v21; // [sp+48h] [bp-2Ch]@22
  TextEntry *v22; // [sp+4Ch] [bp-28h]@26
  TextEntry *v23; // [sp+4Ch] [bp-28h]@30
  TextEntry *v24; // [sp+4Ch] [bp-28h]@34
  TextEntry *v25; // [sp+4Ch] [bp-28h]@38
  TextEntry *v26; // [sp+4Ch] [bp-28h]@42
  GUIIcon *this; // [sp+50h] [bp-24h]@14
  Button *v28; // [sp+54h] [bp-20h]@10
  int v29; // [sp+58h] [bp-1Ch]@46
  BackgroundGUI *bg; // [sp+5Ch] [bp-18h]@6
  int v31; // [sp+64h] [bp-10h]@18
  ListBox *v32; // [sp+68h] [bp-Ch]@50
  signed int done; // [sp+6Ch] [bp-8h]@1

  thisa = ecx0;
  strcpy((int)ecx0->filename);
  fileID = ResourceManager::setResource(resourceManager, filename, 1);
  ResourceManager::pointToFile(resourceManager, fileID);
  thisa->bitmap = 0;
  thisa->prevWindow = 0;
  thisa->nextWindow = thisa->prevWindow;
  thisa->flags2 = 0;
  thisa->idx = -1;
  thisa->xOffset = xOff;
  thisa->yOffset = yOff;
  thisa->width = ResourceManager::readShort(resourceManager);
  thisa->height = ResourceManager::readShort(resourceManager);
  thisa->flags1 = ResourceManager::readShort(resourceManager);
  thisa->flags1 |= 0x4000u;
  thisa->firstComponent = NULL;
  thisa->lastComponent = thisa->firstComponent;
  done = 0;
  while ( !done )
  {
    yieldToGlobalUpdater();
    code = ResourceManager::readShort(resourceManager);
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
              v12 = (int)operator new(sizeof(TextEntry));
              if ( v12 )
                v24 = TextEntry_constructor(v12);
              else
                v24 = 0;
              TextEntry::readSelf(v24, 3);
              guiObj = (AbstractGUIComponent *)v24;
              break;
            case 516:
              v11 = (int)operator new(78);
              if ( v11 )
                v25 = TextEntry_constructor(v11);
              else
                v25 = 0;
              TextEntry::readSelf(v25, 4);
              guiObj = (AbstractGUIComponent *)v25;
              break;
            case 518:
              v10 = (int)operator new(78);
              if ( v10 )
                v26 = TextEntry_constructor(v10);
              else
                v26 = 0;
              TextEntry::readSelf(v26, 5);
              guiObj = (AbstractGUIComponent *)v26;
              break;
            case 515:
              v9 = (int)operator new(180);
              if ( v9 )
                v29 = DropList_constructor(v9);
              else
                v29 = 0;
              sub_4DA960(v29);
              guiObj = (AbstractGUIComponent *)v29;
              break;
            case 517:
              v8 = (ListBox *)operator new(146);
              if ( v8 )
                v32 = ListBox_constructor(v8);
              else
                v32 = 0;
              ListBox__readself(v32);
              guiObj = (AbstractGUIComponent *)v32;
              break;
            default:
              break;
          }
        }
        else
        {
          if ( code == 513 )
          {
            v13 = (int)operator new(sizeof(TextEntry));
            if ( v13 )
              v23 = TextEntry_constructor(v13);
            else
              v23 = 0;
            TextEntry::readSelf(v23, 2);
            guiObj = (AbstractGUIComponent *)v23;
          }
          else
          {
            if ( code == 256 )
            {
              v14 = (int)operator new(sizeof(TextEntry));
              if ( v14 )
                v22 = TextEntry_constructor(v14);
              else
                v22 = 0;
              TextEntry::readSelf(v22, 1);
              guiObj = (AbstractGUIComponent *)v22;
            }
          }
        }
      }
      else
      {
        if ( code == 64 )
        {
          v16 = (int)operator new(32);
          if ( v16 )
            v31 = sub_4DBC10(v16);
          else
            v31 = 0;
          sub_4DBC30(v31);
          guiObj = (AbstractGUIComponent *)v31;
        }
        else
        {
          if ( code == 16 )
          {
            v17 = (GUIIcon *)operator new(0x2Du);
            if ( v17 )
              this = GUIIcon_noArgConstructor(v17);
            else
              this = 0;
            GUIIcon::readSelf(this);
            guiObj = (AbstractGUIComponent *)this;
          }
        }
      }
    }
    else
    {
      if ( code == 8 )
      {
        v15 = (TextWidget *)operator new(43);
        if ( v15 )
          v21 = TextWidget_noArgConstructor(v15);
        else
          v21 = 0;
        TextWidget::readSelf(v21);
        guiObj = (AbstractGUIComponent *)v21;
      }
      else
      {
        if ( code )
        {
          if ( code == 1 )
          {
            v19 = (BackgroundGUI *)operator new(42);
            if ( v19 )
              bg = BackgroundGUI_noArgConstructor(v19);
            else
              bg = 0;
            BackgroundGUI__readSelf(bg);
            guiObj = (AbstractGUIComponent *)bg;
          }
          else
          {
            if ( code == 2 )
            {
              v18 = (Button *)operator new(48);
              if ( v18 )
                v28 = Button_constructor(v18);
              else
                v28 = 0;
              Button::readSelf(v28);
              guiObj = (AbstractGUIComponent *)v28;
            }
          }
        }
        else
        {
          done = 1;
        }
      }
    }
    if ( !done )
    {
      if ( guiObj )
        GUIWindow::insertElement(thisa, guiObj, -1);
    }
  }
  return thisa;
}
