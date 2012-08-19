unit RSQ;

{ *********************************************************************** }
{                                                                         }
{ RSPak                                    Copyright (c) Rozhenko Sergey  }
{ http://sites.google.com/site/sergroj/                                   }
{ sergroj@mail.ru                                                         }
{                                                                         }
{ This file is a subject to any one of these licenses at your choice:     }
{ BSD License, MIT License, Apache License, Mozilla Public License.       }
{                                                                         }
{ *********************************************************************** )

 A set of small functions and types I made for my own use.

{ *********************************************************************** }
{$I RSPak.inc}

interface

uses
  SysUtils, Windows;

type
  int1=ShortInt;
  int2=SmallInt;
  int4=LongInt;
  int8=Int64;
  int=int4;
  pint1=^int1;
  pint2=^int2;
  pint4=^int4;
  pint8=^int8;
  pint=^int;

  uint1=byte;
  uint2=word;
  uint4=longWord;
  uint=uint4;
  puint1=^uint1;
  puint2=^uint2;
  puint4=^uint4;
  puint=^uint;

  ptr=pointer;
  pptr=^pointer;
  ppptr=^pptr;
  ppint=^pint;

  IntPtr = int;
  UintPtr = uint;

  PStr=^string;

  ext = extended;
  pext = ^ext;

const
  VK_PGUP = VK_PRIOR;
  VK_PGDN = VK_NEXT;
  VK_BACKSPACE = VK_BACK;
  VK_ALT = VK_MENU;
  VK_CAPSLOCK = VK_CAPITAL;
  BoolToInt:array[boolean] of byte=(0, 1);
  PalStart: int = $1000300;

var
  AppPath:string;
  AppTitle:string;

procedure msgz(const s:string); overload;
procedure msgz(const s1, s2:string); overload;
procedure msgz(i:integer); overload;
procedure msgz(i,j:int); overload;
procedure msgH(a:pointer); overload;
procedure msgH(a,b:pointer); overload;
procedure msgH(i:int); overload;
procedure msgH(i,j:int); overload;
function WinLong(wnd:hWnd; add:integer; sub:integer=0):integer;
function WinLongEx(wnd:hWnd; add:integer; sub:integer=0):integer;
function GetSysParamsInfo(Action:int; Param:int=0):int;
procedure zD;
function IfThen(b:boolean; t,f:int1):int1; overload;
function IfThen(b:boolean; t,f:int2):int2; overload;
function IfThen(b:boolean; t,f:int4):int4; overload;
function IfThen(b:boolean; const t,f:int8):int8; overload;
function IfThen(b:boolean; const t,f:string):string; overload;
function DecRect(const r:TRect):TRect;
function SizeRect(const r:TRect):TRect;
procedure zCount;
procedure zStopCount(min:DWord = 0);
function zSwap(var a,b):int; {$IFDEF D2005}inline;{$ENDIF}

// 'inline' is buggy. zSet(v, v - 1) would give wrong value if zSet is inlined
function zSet(var a: int1; b: int1):int1; overload;
function zSet(var a: int2; b: int2):int2; overload;
function zSet(var a: int4; b: int4):int4; overload;
function zSet(var a: int8; b: int8):int4; overload;
function zSet(var a: uint1; b: uint1):uint1; overload;
function zSet(var a: uint2; b: uint2):uint2; overload;
function zSet(var a: uint4; b: uint4):uint4; overload;
function zSet(var a: Boolean; b: Boolean):Boolean; overload;
function zSet(var a: ptr; b: ptr):ptr; overload;
function zSet(var a: string; const b: string):string; overload;

function IntoRange(v, min, max:int):int; {$IFDEF D2005}inline;{$ENDIF}
procedure CopyMemory(Destination: Pointer; Source: Pointer; Length: DWORD); {$IFDEF D2005}inline;{$ENDIF}
 // These two are only for elements' sizes less than 4096
procedure ArrayDelete(var Arr; Index:int; Size:int); // Call before SetLength
procedure ArrayInsert(var Arr; Index:int; Size:int); // Call after SetLength
function SqDifference(cl1,cl2:int):int;
function FileAge(const FileName: string): Integer;
function FileExists(const FileName: string): Boolean;

implementation

//function WinLong(wnd:hWnd; nIndex:integer; add:integer; sub:integer=0):integer;
//begin
//  Result:=SetWindowLong(wnd,nIndex,(GetWindowLong(wnd,nIndex) or add) and not sub);
//end;

procedure msgz(const s:string); overload;
begin
  MessageBox(0,pchar(s),'',0);
end;

procedure msgz(const s1, s2:string); overload;
begin
  MessageBox(0,pchar(s1+' '+s2),'',0);
end;

procedure msgz(i:integer); overload;
begin
  MessageBox(0,pchar(IntToStr(i)),'',0);
end;

procedure msgz(i,j:int); overload;
begin
  MessageBox(0,pchar(IntToStr(i)+' '+IntToStr(j)),'',0);
end;

procedure msgH(a:pointer); overload;
begin
  msgh(DWord(a));
end;

procedure msgH(a,b:pointer); overload;
begin
  msgh(DWord(a), DWord(b));
end;

procedure msgH(i:int); overload;
begin
  MessageBox(0,pchar(IntToHex(i,8)),'',0);
end;

procedure msgH(i,j:int); overload;
begin
  MessageBox(0,pchar(IntToHex(i,8)+' '+IntToHex(j,8)),'',0);
end;

function WinLong(wnd:hWnd; add:integer; sub:integer=0):integer;
begin
  Result:=SetWindowLong(wnd,GWL_STYLE,(GetWindowLong(wnd,GWL_STYLE) or add) and not sub);
end;

function WinLongEx(wnd:hWnd; add:integer; sub:integer=0):integer;
begin
  Result:=SetWindowLong(wnd,GWL_EXSTYLE,(GetWindowLong(wnd,GWL_EXSTYLE) or add) and not sub);
end;

function GetSysParamsInfo(Action:int; Param:int=0):int;
begin
  SystemParametersInfo(Action, Param, @Result, 0);
end;

procedure zD;
asm
  int 3
end;

function IfThen(b:boolean; t,f:int1):int1; overload;
begin
  if b then Result:=t else Result:=f;
end;

function IfThen(b:boolean; t,f:int2):int2; overload;
begin
  if b then Result:=t else Result:=f;
end;

function IfThen(b:boolean; t,f:int4):int4; overload;
begin
  if b then Result:=t else Result:=f;
end;

function IfThen(b:boolean; const t,f:int8):int8; overload;
begin
  if b then Result:=t else Result:=f;
end;

function IfThen(b:boolean; const t,f:string):string; overload;
begin
  if b then Result:=t else Result:=f;
end;

function DecRect(const r:TRect):TRect;
begin
  Result.Left:=r.Left+1;
  Result.Top:=r.Top+1;
  Result.Right:=r.Right-1;
  Result.Bottom:=r.Bottom-1;
end;

function SizeRect(const r:TRect):TRect;
begin
  Result.Right:=r.Right-r.Left;
  Result.Bottom:=r.Bottom-r.Top;
  Result.Left:=0;
  Result.Top:=0;
end;

var k:DWord;

procedure zCount;
begin
  k:=GetTickCount;
end;

procedure zStopCount(min:DWord = 0);
var i:DWord;
begin
  i:=GetTickCount-k;
  if i>min then
    MessageBox(0, ptr(IntToStr(i)), '', 0);
end;

function zSwap(var a,b):int; {$IFDEF D2005}inline;{$ENDIF}
begin
  Result:=int(b);
  int(b):=int(a);
  int(a):=Result;
end;

function zSet(var a: int1; b: int1):int1; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: int2; b: int2):int2; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: int4; b: int4):int4; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: int8; b: int8):int4; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: uint1; b: uint1):uint1; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: uint2; b: uint2):uint2; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: uint4; b: uint4):uint4; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: Boolean; b: Boolean):Boolean; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: ptr; b: ptr):ptr; overload;
begin
  a:= b;
  Result:= b;
end;

function zSet(var a: string; const b: string):string; overload;
begin
  a:= b;
  Result:= b;
end;

function IntoRange(v, min, max:int):int; {$IFDEF D2005}inline;{$ENDIF}
begin
  Result:=v;
  if Result<min then
    Result:=min
  else
    if Result>max then
      Result:=max;
end;

procedure CopyMemory(Destination: Pointer; Source: Pointer; Length: DWORD); {$IFDEF D2005}inline;{$ENDIF}
begin
  Move(Source^, Destination^, Length);
end;

procedure ArrayDelete(var Arr; Index:int; Size:int); // Call before SetLength
var
  Buf: array[0..4095] of byte;
  j:int; p:PChar;
begin
  j:=(length(string(Arr)) - 1)*Size; // High(Arr)*Size
  Index:=Index*Size;
  p:=PChar(Arr);
  CopyMemory(@Buf, p + Index, Size);
  CopyMemory(p + Index, p + Index + Size, j - Index);
  CopyMemory(p + j, @Buf, Size);
end;

procedure ArrayInsert(var Arr; Index:int; Size:int); // Call after SetLength
var
  Buf: array[0..4095] of byte;
  j:int; p:PChar;
begin
  j:=(length(string(Arr)) - 1)*Size; // High(Arr)*Size
  Index:=Index*Size;
  p:=PChar(Arr);
  CopyMemory(@Buf, p + j, Size);
  CopyMemory(p + Index + Size, p + Index, j - Index);
  CopyMemory(p + Index, @Buf, Size);
end;

(*
{$W-}
function ArrayDo(var Arr; Index:int; Size:int; Buf:ptr; Delete:boolean):int;
var
  j:int; p:PChar;
begin
  j:=(length(string(Arr)) - 1)*Size; // High(Arr)*Size
  Index:=Index*Size;
  p:=PChar(Arr);
  if Delete then
  begin
    CopyMemory(Buf, p + Index, Size);
    CopyMemory(p + Index, p + Index + Size, j - Index);
    CopyMemory(p + j, Buf, Size);
  end else
  begin
    CopyMemory(Buf, p + j, Size);
    CopyMemory(p + Index + Size, p + Index, j - Index);
    CopyMemory(p + Index, Buf, Size);
  end;
  Result:=Size;
end;

{$W-}

// !!!! 4-byte boundary needed for esp!!!
procedure ArrayDelete(var Arr; Index:int; Size:int); // Call before SetLength
asm
  sub esp, ecx
  push esp
  push true
  call ArrayDo
  add esp, eax
end;

procedure ArrayInsert(var Arr; Index:int; Size:int); // Call after SetLength
asm
  sub esp, ecx
  push esp
  push false
  call ArrayDo
  add esp, eax
end;
*)

function SqDifference(cl1,cl2:int):int;
begin
  Result:= sqr(cl1 and $ff - cl2 and $ff) +
           sqr(cl1 shr 8 and $ff - cl2 shr 8 and $ff) +
           sqr(cl1 shr 16 and $ff - cl2 shr 16 and $ff);
end;

function FileAge(const FileName: string): Integer;
begin
{$WARNINGS OFF}
  Result:= SysUtils.FileAge(FileName);
{$WARNINGS ON}
end;

// code mostly by DVM
function FileExists(const FileName: string): Boolean;

  function ExistsLockedOrShared(const Filename: string): Boolean;
  var
    FindData: TWin32FindData;
    LHandle: THandle;
  begin
    LHandle := FindFirstFile(PChar(Filename), FindData);
    if LHandle <> INVALID_HANDLE_VALUE then
    begin
      Windows.FindClose(LHandle);
      Result := FindData.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY = 0;
    end
    else
      Result := False;
  end;

var
  Code: Integer;
  LastError: Cardinal;
  OldMode: Cardinal;
begin
  // avoid a dialog when checking CD
  OldMode := SetErrorMode(SEM_FAILCRITICALERRORS);
  try
    Code := Integer(GetFileAttributes(PChar(FileName)));
    if Code <> -1 then
      Result := (FILE_ATTRIBUTE_DIRECTORY and Code = 0)
    else
    begin
      LastError := GetLastError;
      Result := (LastError <> ERROR_FILE_NOT_FOUND) and
        (LastError <> ERROR_PATH_NOT_FOUND) and
        (LastError <> ERROR_INVALID_NAME) and ExistsLockedOrShared(Filename);
    end;
  finally
    SetErrorMode(OldMode);
  end;
end;

{------------------ Copy -----------------}
{

function SqDifference(cl1,cl2:TColor):integer;
begin
  cl1:=ColorToRGB(cl1);
  cl2:=ColorToRGB(cl2);
  Result:=sqr(Byte(cl1)-Byte(cl2))
          + sqr(Byte(cl1 shr 8)-Byte(cl2 shr 8))
          + sqr(Byte(cl1 shr 16)-Byte(cl2 shr 16));
end;

function IsThere(a:PChar; s2:string):integer;
begin
  if s2<>'' then
    Result := CompareString(LOCALE_USER_DEFAULT, NORM_IGNORECASE, a,
      length(s2), ptr(s2), length(s2)) - 2
  else
    Result:=false;
end;

function IsThere1(a:PChar; s:string):boolean;
begin
  if s='' then result:=false
  else Result:=CompareMem(a,PChar(s),length(s));
end;

function IncThere(var a:PChar; s:string):integer;
begin
  Result:=IsThere(a,s);
  if Result=0 then inc(a,length(s));
end;

function IncThere1(var a:PChar; s:string):boolean;
begin
  Result:=IsThere1(a,s);
  if Result then inc(a,length(s));
end;

}

initialization
  AppPath:=ExtractFilePath(ParamStr(0));
end.
