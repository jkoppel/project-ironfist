unit RSSysUtils;

{ *********************************************************************** }
{                                                                         }
{ RSPak                                    Copyright (c) Rozhenko Sergey  }
{ http://sites.google.com/site/sergroj/                                   }
{ sergroj@mail.ru                                                         }
{                                                                         }
{ This file is a subject to any one of these licenses at your choice:     }
{ BSD License, MIT License, Apache License, Mozilla Public License.       }
{                                                                         }
{ *********************************************************************** }
{$I RSPak.inc}

interface

uses
  SysUtils, Windows, Messages, SysConst, ShellAPI, Classes, RSQ, Types, Math;

type
  TRSApproveEvent = procedure(Sender:TObject; var Handled: Boolean) of object;

  TRSByteArray = Types.TByteDynArray; //packed array of byte;
  PRSByteArray = ^TRSByteArray;

  PWMMoving = ^TWMMoving;

  TRSArrayStream = class(TMemoryStream)
  protected
    FArr: PRSByteArray;
    function Realloc(var NewCapacity: Longint): Pointer; override;
  public
    constructor Create(var a: TRSByteArray);
    destructor Destroy; override;
  end;

  TRSStringStream = class(TMemoryStream)
  protected
    FStr: ^string;
    function Realloc(var NewCapacity: Longint): Pointer; override;
  public
    constructor Create(var a: string);
    destructor Destroy; override;
  end;

  TRSReplaceStream = class(TStream)
  protected
    FMain: TStream;
    FReplace: TStream;
    FRepPos: Int64;
    FRepLim: Int64;
    FPos: Int64;
    FOwnMain: Boolean;
    FOwnRep: Boolean;
    function GetSize: Int64; override;
    procedure SetSize(NewSize: Longint); overload; override;
    procedure SetSize(const NewSize: Int64); overload; override;
  public
    constructor Create(Main, Replace: TStream; OwnMain, OwnReplace: Boolean; Pos: Int64);
    destructor Destroy; override;
    function Read(var Buffer; Count: Longint): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    function Seek(const Offset: Int64; Origin: TSeekOrigin): Int64; override;
  end;
  
  TRSCompositeStream = class(TStream) // never tested, just an unused draft
  protected
    FPosition: int;
    FStreams: TList;
    FOwnStreams: Boolean;
    FCurrentStream: int;
    function GetSize: Int64; override;
    procedure SetSize(NewSize: Longint); overload; override;
    procedure SetSize(const NewSize: Int64); overload; override;
  public
    constructor Create;
    //constructor Create(const Streams: array of TStream; OwnStreams: Boolean);
    destructor Destroy; override;
    function Read(var Buffer; Count: Longint): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    function Seek(const Offset: Int64; Origin: TSeekOrigin): Int64; override;
    procedure AddStream(a: TStream);
  end;

  TRSFileStreamProxy = class(TFileStream)
  protected
    FMode: Word;
    FRights: Cardinal;
{$IFNDEF D2006}
    FFileName: string;
{$ENDIF}
    procedure Check;
    procedure SetSize(NewSize: Longint); override;
    procedure SetSize(const NewSize: Int64); override;
  public
    function Read(var Buffer; Count: Longint): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    function Seek(const Offset: Int64; Origin: TSeekOrigin): Int64; override;
    constructor Create(const AFileName: string; Mode: Word); overload;
    constructor Create(const AFileName: string; Mode: Word; Rights: Cardinal); overload;
{$IFNDEF D2006}
    property FileName: string read FFileName;
{$ENDIF}
  end;

var
  RSWndExceptions: Boolean = true;

type
   // Usage: TRSWnd(hWnd)
  TRSWnd = class
  private
    function GetAbsoluteRect: TRect;
    function GetBoundsRect: TRect;
    function GetClientRect: TRect;
    function GetClass: string;
    function GetExStyle: LongInt;
    function GetHeight: LongInt;
    function GetId: LongInt;
    function GetProcessId: DWord;
    function GetStayOnTop: Boolean;
    function GetStyle: LongInt;
    function GetText: string;
    function GetThreadId: DWord;
    function GetVisible:boolean;
    function GetWidth: LongInt;
    procedure SetAbsoluteRect(v: TRect);
    procedure SetBoundsRect(const v: TRect);
    procedure SetExStyle(v: LongInt);
    procedure SetHeight(v: LongInt);
    procedure SetId(v: LongInt);
    procedure SetStayOnTop(v: Boolean);
    procedure SetStyle(v: LongInt);
    procedure SetText(const v: string);
    procedure SetVisible(v: boolean);
    procedure SetWidth(v: LongInt);
    function GetLeft: LongInt;
    function GetTop: LongInt;
    procedure SetLeft(v: LongInt);
    procedure SetTop(v: LongInt);
  public
    class function Create(ClassName:PChar; WindowName:PChar; Style:DWORD;
      X, Y, Width, Height:Integer; hWndParent: HWND; hMenu:HMENU;
      hInstance:HINST; lpParam:Pointer=nil; ExStyle:DWORD=0):TRSWnd;
    destructor Destroy; override;
    procedure BorderChanged;
    function OpenProcess(dwDesiredAccess:DWORD=PROCESS_ALL_ACCESS;
            bInheritHandle:boolean=false): DWord;
    procedure SetBounds(x, y, w, h:int);
    procedure SetPosition(x, y:int);

    property AbsoluteRect: TRect read GetAbsoluteRect write SetAbsoluteRect;
    property BoundsRect: TRect read GetBoundsRect write SetBoundsRect;
    property ClientRect: TRect read GetClientRect;
{$WARNINGS OFF}
    property ClassName: string read GetClass;
{$WARNINGS ON}
    property ExStyle: LongInt read GetExStyle write SetExStyle;
    property Id: LongInt read GetId write SetId;
    property ProcessId: DWord read GetProcessId;
    property StayOnTop: Boolean read GetStayOnTop write SetStayOnTop;
    property Style: LongInt read GetStyle write SetStyle;
    property Text: string read GetText write SetText;
    property ThreadId: DWord read GetThreadId;
    property Visible: boolean read GetVisible write SetVisible;
    property Width: LongInt read GetWidth write SetWidth;
    property Height: LongInt read GetHeight write SetHeight;
    property Top: LongInt read GetTop write SetTop;
    property Left: LongInt read GetLeft write SetLeft;
  end;

   // Usage: TRSBits(PByte, PWord or pointer to data of any size)
   // For example, TRSBits(@i).';
  TRSBits = class
  private
    function GetBit(i:DWord): Boolean;
    procedure SetBit(i:DWord; v: Boolean);
  public
    constructor Create;
    procedure FromBooleans(Buffer:pointer; Count:DWord; StartIndex:DWord = 0);
    procedure ToBooleans(Buffer:pointer; Count:DWord; StartIndex:DWord = 0);
    property Bit[i:DWord]: Boolean read GetBit write SetBit; default;
  end;

   // No adding overhead at the cost of 4 bytes per block
  TRSCustomStack = class(TObject)
  private
    function GetSize:int;
  protected
    FBlockSize: int;
    FBlock: ptr; // First DWord = PLastBlock, then there goes data
    FNextBlock: ptr; // In case of pop
    FBlockCount: int;
    FLastSize: int; // Including PLastBlock
    FVirtualAlloc: Boolean;
    function AllocBlock:ptr; virtual;
    procedure FreeBlock(ABlock:ptr); virtual;
    function NewBlock:ptr;
    function WholePush(Size:int):ptr;
    function WholePop(Size:int):ptr;
    function DoPeakAt(Offset:int):ptr;
    procedure DoPeak(var v; Size:int);

    function BlockNextTo(p:ptr):ptr; // For Queue
  public
    constructor Create(BlockSize:int);
    destructor Destroy; override;
    procedure Clear; virtual;
    property Size: int read GetSize;
  end;

  TRSFixedStack = class(TRSCustomStack)
  protected
    FItemSize: int;
    function GetCount:int; virtual;
     // Unsafe routines
    function AllocBlock:ptr; override;
    procedure FreeBlock(ABlock:ptr); override;
    function DoPush:ptr;
    function DoPop:ptr;
    function DoPeak:ptr; overload;
    function DoPeakAtIndex(Index:int):ptr;
  public
    constructor Create(ItemSize:int; BlockSize:int=4096);

    procedure Peak(var v; Count:int);
    procedure PeakAll(var v);
    property Count: int read GetCount;
  end;

  TRSObjStack = class(TRSFixedStack)
  public
    constructor Create(BlockSize:int = 4096);
    procedure Push(Obj:TObject);
    function Pop:TObject;
    function Peak:TObject; overload;
    function PeakAt(Index:int):TObject;
  end;

(*
   // Thread-safe in case of single writer and single reader
  TRSCustomQueue = class(TRSFixedStack)
  protected
    FCount: int;
    FPopBlock: ptr;
    FPopCount: int;
    FPopIndex: int; // Inside block
    FFillEvent: THandle;
    function GetCount:int; override;
    function DoPop:ptr;
    function AfterPush:ptr;
  public
    constructor Create(ItemSize:int; BlockSize:int=4096);
    destructor Destroy; override;
    procedure WaitFor(var Queue:TRSCustomQueue); // Queue var for safe Destroy 
  end;

  TRSObjQueue = class(TRSCustomQueue)
  public
    procedure Push(Obj:TObject);
    function Pop:TObject;
    function Peak:TObject; overload;
    function PeakAt(Index:int):TObject;
  public
    constructor Create(BlockSize:int=4096);
  end;
*)

{
   // В этом самом общем случае стека байтов нет особого смысла
  TRSStack = class(TRSCustomStack)
    procedure GetSize:int;
  public
    constructor Create(BlockSize:int=PageSize);
    destructor Destroy; override;
    procedure Push(const v; Count:int); overload;
    procedure Pop(var v; Count:int); overload;
    procedure Peak(var v; Count:int); overload;
    procedure PeakAll(var v);
    property Size: int read GetSize;
  end;
}

  TRSSharedData = class(TObject)
  protected
    FAlreadyExists: Boolean;
    FData: ptr;
    FMMF: THandle;
    FSize: int;
  public
    constructor Create(Name:string; Size:int); overload;
    constructor Create(MMF:THandle; Size:int); overload;
    destructor Destroy; override;

    property AlreadyExists: Boolean read FAlreadyExists;
    property Data: ptr read FData;
    property MMF: THandle read FMMF;
    property Size: int read FSize;
  end;


{ Example:

  with TRSFindFile.Create('C:\*.*') do
    try
      while FindNextAttributes(0, FILE_ATTRIBUTE_DIRECTORY) do // Only files
        DoSomething(FileName);
    finally
      Free;
    end;
}
  TRSFindFile = class(TObject)
  protected
    FHandle: THandle;
    FFileName: string;
    FFound: Boolean;
    FNotFirst: Boolean;
    FPath: string;
    procedure CheckError;
    function GetFileName: string;
  public
    Data: TWin32FindData;
    constructor Create(FileMask:string);
    destructor Destroy; override;
    function FindNext: Boolean;
    function FindAttributes(Require, Exclude:DWord): Boolean;
    function FindNextAttributes(Require, Exclude:DWord): Boolean;
    property FileName: string read GetFileName;
    property Found: Boolean read FFound;
    property Path: string read FPath;
  end;

   // Used in RSWindowProc.pas
  TRSEventHook = class(TObject)
  protected
    FEventProc:ptr;
    FPriority:int;
    FLastProc: TMethod;
    FNext: TRSEventHook;
    FLockCount: int;
    FDeleting: boolean;
    function GetEvent:TMethod; virtual; abstract;
    procedure SetEvent(const v:TMethod); virtual; abstract;
    function GetLast:TRSEventHook;
    property ObjEvent:TMethod read GetEvent write SetEvent;
  public
    constructor Create(Priority:int);
    procedure Delete;
    procedure Lock(aLock:boolean);
  end;

  TRSShellChangeNotifier = class(TThread)
  private
    FOnChange: TNotifyEvent;
    function GetNeedRefresh: Boolean;
  protected
    FWakeEvent: THandle;
    FCS: TRTLCriticalSection;
    FReset: Boolean;
    FNeedRefresh: Boolean;

    FDirectory: string;
    FWatchSubTree: Boolean;
    FFlags: DWord;

    procedure Execute; override;
    procedure CallOnChange;
  public
    constructor Create(OnChange: TNotifyEvent = nil); virtual;
    destructor Destroy; override;
    procedure Free;
    procedure Terminate;
    procedure SetOptions(Directory: string; WatchSubTree: Boolean = false;
     Flags:DWord = FILE_NOTIFY_CHANGE_FILE_NAME or FILE_NOTIFY_CHANGE_DIR_NAME);
    procedure Cancel;
    procedure Reset;
    property NeedRefresh: Boolean read GetNeedRefresh write FNeedRefresh;
    property Directory: string read FDirectory;
    property WatchSubTree: Boolean read FWatchSubTree;
    property Flags: DWord read FFlags;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

{--------}

procedure RSCopyStream(Dest, Source: TStream; Count: int64);

procedure RSRaiseLastOSError;
function RSWin32Check(RetVal: BOOL): BOOL; register; overload;
function RSWin32Check(CheckForZero:int):int; register; overload;
function RSWin32Check(CheckForZero:ptr):ptr; register; overload;

procedure RSDispatchEx(Obj:TObject; AClass:TClass; var Message);

 // From Grids.pas
procedure RSFillDWord(Dest:ptr; Count, Value: Integer); register;

function RSQueryPerformanceCounter: int64;
function RSQueryPerformanceFrequency: int64;

{
procedure RSSetLayeredAttribs(Handle:HWnd;
             AlphaBlend:boolean; AlphaBlendValue:byte;
             TransparentColor:boolean; TransparentColorValue:int);
{}

{--------}

function RSGetModuleFileName(hModule: HINST = 0):string;
function PathFileExists(pszPath: PChar):Bool; stdcall; external 'shlwapi.dll' name 'PathFileExistsA';
function PathIsRoot(pPath: PChar):Bool; stdcall; external 'shlwapi.dll' name 'PathIsRootA';
function RSFileExists(const FileName: string): Boolean; {$IFDEF D2005}inline;{$ENDIF}

function RSMoveFile(const OldName, NewName: string; FailIfExists: Boolean): Bool;

function RSCreateFile(const FileName:string;
           dwDesiredAccess:DWord = GENERIC_READ or GENERIC_WRITE;
           dwShareMode:DWord = 0;
           lpSecurityAttributes:PSecurityAttributes = nil;
           dwCreationDistribution:DWord = CREATE_ALWAYS;
           dwFlagsAndAttributes:DWord = FILE_ATTRIBUTE_NORMAL;
           hTemplateFile:HFile=0):HFile;

function RSLoadFile(FileName:string):TRSByteArray;
procedure RSSaveFile(FileName:string; Data:TRSByteArray); overload;
procedure RSSaveFile(FileName:string; Data:TMemoryStream; RespectPosition: Boolean = false); overload;
procedure RSAppendFile(FileName:string; Data:TRSByteArray); overload;
procedure RSAppendFile(FileName:string; Data:TMemoryStream; RespectPosition: Boolean = false); overload;

function RSLoadTextFile(FileName:string):string;
procedure RSSaveTextFile(FileName:string; Data:string);
procedure RSAppendTextFile(FileName:string; Data:string);

function RSCreateDir(const PathName:string):boolean;

function RSCreateDirectory(const PathName:string;
           lpSecurityAttributes:PSecurityAttributes = nil):boolean;

function RSCreateDirectoryEx(const lpTemplateDirectory, NewDirectory:string;
           lpSecurityAttributes:PSecurityAttributes = nil):boolean;

function RSRemoveDir(const Dir:string):boolean;

const
  FO_MOVE = ShellAPI.FO_MOVE;
  FO_COPY = ShellAPI.FO_COPY;
  FO_DELETE = ShellAPI.FO_DELETE;
  FO_RENAME = ShellAPI.FO_RENAME;

function RSFileOperation(const aFrom, aTo:string; FileOperation: uint;
   Flags: FILEOP_FLAGS = FOF_NOCONFIRMATION or FOF_NOCONFIRMMKDIR or
          FOF_NOERRORUI or FOF_SILENT) : boolean; overload;

function RSFileOperation(const aFrom, aTo:array of string; FileOperation: uint;
   Flags: FILEOP_FLAGS = FOF_NOCONFIRMATION or FOF_NOCONFIRMMKDIR or
          FOF_NOERRORUI or FOF_SILENT) : boolean; overload;

function RSSearchPath(Path, FileName, Extension:string):string;

{--------}

function RSLoadProc(var Proc:Pointer; const LibName, ProcName:string; LoadLib:Boolean = true):hInst; overload;
function RSLoadProc(var Proc:Pointer; const LibName:string; ProcIndex:word; LoadLib:Boolean = true):hInst; overload;

function RSLoadProc(var Proc:Pointer; const LibName, ProcName:string;
   LoadLib:Boolean; RaiseException:boolean):hInst; overload;
function RSLoadProc(var Proc:Pointer; const LibName:string; ProcIndex:word;
   LoadLib:Boolean; RaiseException:boolean):hInst; overload;

procedure RSDelayLoad(var ProcAddress:Pointer; const LibName, ProcName:string;
   LoadLib:Boolean = true); overload;
procedure RSDelayLoad(var ProcAddress:Pointer; const LibName:string;
   ProcIndex:word; LoadLib:Boolean = true); overload;

{--------}

type
  TRSObjectInstance = packed record
    Code: array[0..4] of byte;
    Proc: ptr;
    Obj: ptr;
  end;

procedure RSMakeObjectInstance(var ObjInst:TRSObjectInstance;
             Obj, ProcStdCall:ptr); deprecated;

procedure RSCustomObjectInstance(var ObjInst:TRSObjectInstance;
             Obj, Proc, CustomProc:ptr); deprecated;

function RSMakeLessParamsFunction(
            ProcStdCall, Param:ptr):Pointer; overload; deprecated;

function RSMakeLessParamsFunction(
            ProcStdCall:pointer; DWordParams:Pointer;
            Count:integer; ResultInParam:integer=-1):Pointer; overload; deprecated;

function RSMakeLessParamsFunction(
            ProcStdCall:pointer; const DWordParams:array of DWord;
            ResultInParam:integer=-1):Pointer; overload; deprecated;

procedure RSFreeLessParamsFunction(Ptr:Pointer); deprecated;

{--------}

function RSEnableTokenPrivilege(TokenHandle:THandle; const Privilege:string;
  Enable:Boolean):boolean;

function RSEnableProcessPrivilege(hProcess:THandle; const Privilege:string;
  Enable:boolean):boolean;

function RSEnableDebugPrivilege(Enable:boolean):boolean;

{--------}

function RSCreateRemoteCopy(CurPtr:Pointer; var RemPtr:Pointer;
                      Len, hProcess:DWord; var Mapping:DWord):boolean;

function RSCreateRemoteCopyID(CurPtr:Pointer; var RemPtr:Pointer;
                      Len, ProcessID:DWord; var Mapping:DWord):boolean;

function RSCreateRemoteCopyWnd(CurPtr:Pointer; var RemPtr:Pointer;
                     Len:DWord; wnd:hWnd; var Mapping:DWord):boolean;

function RSFreeRemoteCopy(CurPtr, RemPtr:pointer;
                           Len, hProcess, Mapping:DWord):boolean;

function RSFreeRemoteCopyID(CurPtr, RemPtr:pointer;
                             Len, ProcessID, Mapping:DWord):boolean;

function RSFreeRemoteCopyWnd(CurPtr, RemPtr:pointer;
                          Len:DWord; wnd:hWnd; Mapping:DWord):boolean;

{--------}

function RSSendDataMessage(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; var lpdwResult:DWord; wDataLength:DWord=0;
           lDataLength:DWord=0; wReadOnly:boolean=false;
           lReadOnly:boolean=false):boolean;

function RSSendDataMessageTimeout(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; fuFlags,uTimeout:DWord; var lpdwResult:DWord;
           wDataLength:DWord=0; lDataLength:DWord=0;
           wReadOnly:boolean=false; lReadOnly:boolean=false):boolean;

function RSSendDataMessageCallback(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; lpCallBack:Pointer; dwData:DWord;
           wDataLength:DWord=0; lDataLength:DWord=0;
           wReadOnly:boolean=true; lReadOnly:boolean=true):boolean;

function RSPostDataMessage(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; wDataLength:DWord=0;
           lDataLength:DWord=0; wReadOnly:boolean=true;
           lReadOnly:boolean=true):boolean;

{--------}

function RSRunWait(Command:string; Dir:string;
           Timeout:DWord=INFINITE; showCmd:Word=SW_NORMAL):boolean;

{--------}

procedure RSShowException;

 // Usage: AssertErrorProc:=RSAssertDisable
procedure RSAssertDisable(const Message, FileName: string;
    LineNumber: Integer; ErrorAddr: Pointer);

 // Usage: AssertErrorProc:=RSAssertErrorHandler
procedure RSAssertErrorHandler(const Message, FileName: string;
    LineNumber: Integer; ErrorAddr: Pointer);

 // Use RSDebug instead
function RSHandleException(FuncSkip:integer=0; TraceLimit:integer=0; EAddr:pointer=nil; EObj:TObject=nil):string; deprecated;

{--------}

function RSMessageBox(hWnd:hwnd; Text, Caption:string; uType:DWord=0):int;

{--------}

var
  RSOSVersionInfo: OSVERSIONINFO;

resourcestring
  sRSCantLoadProc = 'Can''t load the "%s" procedure from "%s"';
  sRSCantLoadIndexProc = 'Can''t load the procedure number %d from "%s"';

implementation

var
  OSVersion: OSVERSIONINFO absolute RSOSVersionInfo;

const
  PageSize = 4096;

{$W-} // Unused stack frames are not welcome here (RSDelayLoad)
{$H+} // Long strings

function CalcJmpOffset(Src, Dest: Pointer): Pointer;
begin
  Result := ptr(Longint(Dest) - (Longint(Src) + 5));
end;

function MakeCall(Caller, JumpTo:ptr):ptr;
begin
  PByte(Caller)^:=$E8;
  inc(PByte(Caller));
  Result:=PChar(Caller)+4;
  pptr(Caller)^:= ptr(int(JumpTo) - int(Result));
end;

{
******************************** TRSArrayStream ********************************
}
constructor TRSArrayStream.Create(var a: TRSByteArray);
begin
  inherited Create;
  FArr:=@a;
  SetPointer(ptr(a), length(a));
end;

destructor TRSArrayStream.Destroy;
begin
  FArr:=nil;
end;

function TRSArrayStream.Realloc(var NewCapacity: Longint): Pointer;
begin
  if FArr<>nil then
  begin
    SetLength(FArr^, NewCapacity);
    Result:=ptr(FArr^);
  end else
    Result:=nil;
end;

{
******************************* TRSStringStream ********************************
}

constructor TRSStringStream.Create(var a: string);
begin
  inherited Create;
  FStr:=@a;
  SetPointer(ptr(a), length(a));
end;

destructor TRSStringStream.Destroy;
begin
  FStr:=nil;
end;

function TRSStringStream.Realloc(var NewCapacity: Integer): Pointer;
begin
  if FStr<>nil then
  begin
    SetLength(FStr^, NewCapacity);
    Result:=ptr(FStr^);
  end else
    Result:=nil;
end;

{
****************************** TRSReplcaeStream ******************************
}

constructor TRSReplaceStream.Create(Main, Replace: TStream; OwnMain,
  OwnReplace: Boolean; Pos: Int64);
begin
  FMain:= Main;
  FReplace:= Replace;
  FOwnMain:= OwnMain;
  FOwnRep:= OwnReplace;
  FRepPos:= Pos;
  FRepLim:= Pos + FReplace.Size;
  FPos:= FMain.Position;
end;

destructor TRSReplaceStream.Destroy;
begin
  if FOwnMain then
    FreeAndNil(FMain);
  if FOwnRep then
    FreeAndNil(FReplace);
  inherited;
end;

function TRSReplaceStream.GetSize: Int64;
begin
  Result:= FMain.Size;
end;

function TRSReplaceStream.Read(var Buffer; Count: Integer): Longint;
var
  i: int;
//  p: PChar;
begin
  Result:= Count;
//  p:= @Buffer;
  if (Count > 0) and (FPos < FRepPos) then
  begin
    i:= FMain.Read(Buffer, min(Count, FRepPos - FPos));
    inc(FPos, i);
    dec(Count, i);
//    inc(p, i);
    if FPos >= FRepPos then
      FReplace.Seek(0, 0);
  end;
  if (Count > 0) and (FPos >= FRepPos) and (FPos < FRepLim) then
  begin
    i:= FReplace.Read(Buffer, min(Count, FRepLim - FPos));
    inc(FPos, i);
    dec(Count, i);
//    inc(p, i);
    FMain.Seek(i, soCurrent);
  end;
  if FPos >= FRepLim then
  begin
    i:= FMain.Read(Buffer, Count);
    inc(FPos, i);
    dec(Count, i);
  end;
  dec(Result, Count);
end;

function TRSReplaceStream.Seek(const Offset: Int64; Origin: TSeekOrigin): Int64;
begin
  Result:= FMain.Seek(Offset, Origin);
  FPos:= Result;
  if (Result >= FRepPos) and (Result < FRepLim) then
    FReplace.Seek(Result - FRepPos, 0);
end;

procedure TRSReplaceStream.SetSize(NewSize: Integer);
begin
  FMain.Size:= NewSize;
end;

procedure TRSReplaceStream.SetSize(const NewSize: Int64);
begin
  FMain.Size:= NewSize;
end;

function TRSReplaceStream.Write(const Buffer; Count: Integer): Longint;
begin
  Assert(false); // copy from Read
  Result:= 0;
end;

{
****************************** TRSCompositeStream ******************************
}

constructor TRSCompositeStream.Create;
begin
  inherited;
  FStreams:= TList.Create;
  FOwnStreams:= true;
end;

destructor TRSCompositeStream.Destroy;
var
  i: int;
begin
  if FOwnStreams then
    for i := 0 to FStreams.Count - 1 do
      TObject(FStreams.Items[i]).Destroy;
  inherited;
end;

function TRSCompositeStream.GetSize: Int64;
var
  i: int;
begin
  Result:= 0;
  for i := 0 to FStreams.Count - 1 do
    inc(Result, TStream(FStreams[i]).Size);
end;

function TRSCompositeStream.Read(var Buffer; Count: Integer): Longint;
var
  i, j: int;
  p: PChar;
begin
  Result:= Count;
  if Count = 0 then  exit;
  p:= @Buffer;
  for i := FCurrentStream to FStreams.Count - 2 do
  begin
    j:= TStream(FStreams[i]).Read(p^, Count);
    inc(p, j);
    dec(Count, j);
    if Count = 0 then  exit;
    TStream(FStreams[i]).Seek(0, 0);
    inc(FCurrentStream);
  end;
  if FStreams.Count > 0 then
    dec(Count, TStream(FStreams[FCurrentStream]).Read(p^, Count));
  dec(Result, Count);
end;

function TRSCompositeStream.Seek(const Offset: Int64;
  Origin: TSeekOrigin): Int64;
var
  i, j, sz, off, n: int;
  a: TStream;
//  orig: TSeekOrigin;
begin
  Result:= 0;
  n:= FStreams.Count;
  if n = 0 then  exit;

  case Origin of
    soBeginning:
      i:= 0;
    soCurrent:
      i:= FCurrentStream;
    else //soEnd:
      i:= n - 1;
  end;
  if FCurrentStream <> i then
    TStream(FStreams[FCurrentStream]).Seek(0, 0);
  a:= TStream(FStreams[i]);
  off:= a.Seek(0, Origin) + Offset;
  if Origin <> soBeginning then
    a.Seek(0, 0);
  if off <= 0 then
  begin
    while (off < 0) and (i > 0) do
    begin
      dec(i);
      a:= TStream(FStreams[i]);
      inc(off, a.Size);
    end;
    Result:= a.Seek(off, 0);
    FCurrentStream:= i;
    for j := i - 1 downto 0 do
      inc(Result, TStream(FStreams[j]).Size);
  end else
  begin
    for j := i - 1 downto 0 do
      inc(Result, TStream(FStreams[j]).Size);
    sz:= a.Size;
    while (sz <= off) and (i < n - 1) do
    begin
      inc(Result, sz);
      dec(off, sz);
      inc(i);
      a:= TStream(FStreams[i]);
      sz:= a.Size;
    end;
    inc(Result, a.Seek(off, 0));
    FCurrentStream:= i;
  end;
end;

procedure TRSCompositeStream.SetSize(NewSize: Integer);
begin
  SetSize(Int64(NewSize));
end;

procedure TRSCompositeStream.SetSize(const NewSize: Int64);
var
  sz: Int64;
//  a: TStream;
  i: int;
begin
  sz:= NewSize;
  for i := 0 to FStreams.Count - 2 do
    dec(sz, TStream(FStreams[i]).Size);
  i:= FStreams.Count;
  Assert((i > 0) and (sz >= 0));
  TStream(FStreams[i - 1]).Size:= sz;
end;

function TRSCompositeStream.Write(const Buffer; Count: Integer): Longint;
var
  i, j: int;
  p: PChar;
  a: TStream;
begin
  Result:= Count;
  if Count = 0 then  exit;
  p:= @Buffer;
  for i := FCurrentStream to FStreams.Count - 2 do
  begin
    a:= TStream(FStreams[i]);
    j:= a.Size - a.Position;
    if Count < j then
      j:= Count;
    j:= a.Write(p^, j);
    inc(p, j);
    dec(Count, j);
    if Count = 0 then  exit;
    TStream(FStreams[i]).Seek(0, 0);
    inc(FCurrentStream);
  end;
  if FStreams.Count > 0 then
    dec(Count, TStream(FStreams[FCurrentStream]).Write(p^, Count));
  dec(Result, Count);
end;

procedure TRSCompositeStream.AddStream(a: TStream);
begin
  a.Seek(0, 0);
  FStreams.Add(a);
end;

{
****************************** TRSFileStreamProxy ******************************
}

constructor TRSFileStreamProxy.Create(const AFileName: string; Mode: Word);
begin
{$IFDEF MSWINDOWS}
  Create(AFileName, Mode, 0);
{$ELSE}
  Create(AFileName, Mode, FileAccessRights);
{$ENDIF}
end;

constructor TRSFileStreamProxy.Create(const AFileName: string; Mode: Word;
  Rights: Cardinal);
begin
  inherited Create(-1);
{$IFDEF D2006}
  string((@FileName)^):= AFileName;
{$ELSE}
  FFileName:= AFileName;
{$ENDIF}
  FMode:= Mode;
  FRights:= Rights;
end;

procedure TRSFileStreamProxy.Check;
begin
  if Handle < 0 then
    inherited Create(FileName, FMode, FRights);
end;

function TRSFileStreamProxy.Read(var Buffer; Count: Integer): Longint;
begin
  Check;
  Result:= inherited Read(Buffer, Count);
end;

function TRSFileStreamProxy.Seek(const Offset: Int64;
  Origin: TSeekOrigin): Int64;
begin
  Check;
  Result:= inherited Seek(Offset, Origin);
end;

procedure TRSFileStreamProxy.SetSize(NewSize: Integer);
begin
  Check;
  inherited;
end;

procedure TRSFileStreamProxy.SetSize(const NewSize: Int64);
begin
  Check;
  inherited;
end;

function TRSFileStreamProxy.Write(const Buffer; Count: Integer): Longint;
begin
  Check;
  Result:= inherited Write(Buffer, Count);
end;

{
************************************ TRSWnd ************************************
}

procedure RSWndCheck(b:Boolean);
asm
  test eax, eax
  jnz @Exit
  cmp RSWndExceptions, false
  jnz RSRaiseLastOSError
@Exit:
end;

class function TRSWnd.Create(ClassName:PChar; WindowName:PChar; Style:DWORD;
  X, Y, Width, Height:Integer; hWndParent: HWND; hMenu:HMENU;
  hInstance:HINST; lpParam:Pointer=nil; ExStyle:DWORD=0):TRSWnd;
begin
  Result:=TRSWnd(CreateWindowEx(ExStyle, ClassName, WindowName, Style, X, Y,
    Width, Height, hWndParent, hMenu, hInstance, lpParam));
end;

destructor TRSWnd.Destroy;
begin
  Assert(false);
  // TRSWnd isn't a normal class. Don't destroy it!
end;

procedure TRSWnd.BorderChanged;
begin
  SetWindowPos(HWnd(self),0,0,0,0,0,SWP_DRAWFRAME or SWP_FRAMECHANGED or
               SWP_NOZORDER or SWP_NOACTIVATE or SWP_NOMOVE or
               SWP_NOOWNERZORDER or SWP_NOSIZE or SWP_NOSENDCHANGING);
end;

function TRSWnd.GetAbsoluteRect: TRect;
begin
  RSWndCheck(GetWindowRect(HWnd(self), Result));
end;

function TRSWnd.GetBoundsRect: TRect;
var
  h: HWnd;
begin
  RSWndCheck(GetWindowRect(HWnd(self), Result));
  h:=GetParent(HWnd(self));
  if h=0 then exit;
  MapWindowPoints(0, h, Result, 2);
end;

function TRSWnd.GetClientRect: TRect;
begin
  RSWndCheck(windows.GetClientRect(HWnd(self), Result));
end;

function TRSWnd.GetClass: string;
var
  i: Integer;
begin
  SetLength(Result,255);
  i:=GetClassName(HWnd(self),pointer(Result),256);
  SetLength(Result, i);
  RSWndCheck(i<>0);
end;

function TRSWnd.GetExStyle: LongInt;
begin
  Result:=GetWindowLong(HWnd(self),GWL_EXSTYLE);
end;

function TRSWnd.GetHeight: LongInt;
begin
  with GetAbsoluteRect do
    Result:=Bottom-Top;
end;

function TRSWnd.GetId: LongInt;
begin
  Result:=GetWindowLong(HWnd(self),GWL_ID);
end;

function TRSWnd.GetProcessId: DWord;
begin
  RSWndCheck(GetWindowThreadProcessId(HWnd(self), Result) <> 0);
end;

function TRSWnd.GetStayOnTop: Boolean;
begin
  Result:=(GetWindowLong(HWnd(self),GWL_EXSTYLE) and WS_EX_Topmost)<>0;
end;

function TRSWnd.GetStyle: LongInt;
begin
  Result:=GetWindowLong(HWnd(self),GWL_STYLE);
end;

function TRSWnd.GetText: string;
var
  i: Integer;
begin
  i:=GetWindowTextLength(HWnd(self));
  if i<=0 then exit;
  SetLength(Result,i);
  GetWindowText(HWnd(self),pointer(Result),i+1);
end;

function TRSWnd.GetThreadId: DWord;
begin
  Result:= GetWindowThreadProcessId(HWnd(self), DWord(nil^));
  RSWndCheck(Result<>0);
end;

function TRSWnd.GetVisible:boolean;
begin
  Result:= GetWindowLong(HWnd(self),GWL_STYLE) and WS_VISIBLE <> 0;
end;

function TRSWnd.GetWidth: LongInt;
begin
  with GetAbsoluteRect do
    Result:=Right-Left;
end;

function TRSWnd.OpenProcess(dwDesiredAccess:DWORD=PROCESS_ALL_ACCESS; 
        bInheritHandle:boolean=false): DWord;
var
  pID: Dword;
begin
  GetWindowThreadProcessId(HWnd(self), pID);
  if pID=0 then
    Result:=0
  else
    Result:=Windows.OpenProcess(dwDesiredAccess, bInheritHandle, pID);
end;

procedure TRSWnd.SetAbsoluteRect(v: TRect);
var
  h: HWnd;
begin
  h:=GetParent(HWnd(self));
  if h<>0 then
    MapWindowPoints(0, h, v, 2);

  RSWndCheck(SetWindowPos(HWnd(self), 0,
                        v.Left, v.Top, v.Right-v.Left, v.Bottom-v.Top,
                        SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_NOZORDER));
end;

procedure TRSWnd.SetBoundsRect(const v: TRect);
begin
  SetBounds(v.Left, v.Top, v.Right-v.Left, v.Bottom-v.Top);
end;

procedure TRSWnd.SetExStyle(v: LongInt);
begin
  SetWindowLong(HWnd(self), GWL_EXSTYLE, v);
end;

procedure TRSWnd.SetHeight(v: LongInt);
begin
  RSWndCheck(SetWindowPos(HWnd(self), 0, 0, 0, Width, v,
           SWP_NOMOVE or SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_NOZORDER));
end;

procedure TRSWnd.SetId(v: LongInt);
begin
  SetWindowLong(HWnd(self), GWL_ID, v);
end;

procedure TRSWnd.SetStayOnTop(v: Boolean);
var h:hwnd;
begin
  if v then
    h:=HWND_TOPMOST
  else
    h:=HWND_NOTOPMOST;
  RSWndCheck(SetWindowPos(HWnd(self), h, 0, 0, 0, 0,
     SWP_NOACTIVATE or SWP_NOSIZE or SWP_NOMOVE or SWP_NOOWNERZORDER or SWP_NOSENDCHANGING))
end;

procedure TRSWnd.SetStyle(v: LongInt);
begin
  SetWindowLong(HWnd(self),GWL_STYLE,v);
end;

procedure TRSWnd.SetText(const v: string);
begin
  RSWndCheck(SetWindowText(HWnd(self),PChar(v)));
end;

procedure TRSWnd.SetVisible(v: boolean);
begin
  if v then
    ShowWindow(HWnd(self), SW_SHOWNOACTIVATE)
  else
    ShowWindow(HWnd(self), SW_HIDE);
end;

procedure TRSWnd.SetWidth(v: LongInt);
begin
  RSWndCheck(SetWindowPos(HWnd(self),0,0,0,v,Height,
             SWP_NOMOVE or SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_NOZORDER));
end;

function TRSWnd.GetLeft: LongInt;
begin
  Result:=AbsoluteRect.Left;
end;

function TRSWnd.GetTop: LongInt;
begin
  Result:=AbsoluteRect.Top;
end;

procedure TRSWnd.SetBounds(x, y, w, h:int);
begin
  RSWndCheck(SetWindowPos(HWnd(self), 0, x, y, w, h,
     SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_NOZORDER));
end;

procedure TRSWnd.SetPosition(x, y:int);
begin
  RSWndCheck(SetWindowPos(HWnd(self), 0, x, y, 0, 0,
     SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_NOZORDER or SWP_NOMOVE));
end;

procedure TRSWnd.SetLeft(v: LongInt);
begin
  SetPosition(v, BoundsRect.Top);
end;

procedure TRSWnd.SetTop(v: LongInt);
begin
  SetPosition(BoundsRect.Left, v);
end;

{
*********************************** TRSBits ************************************
}
constructor TRSBits.Create;
begin
  Assert(false);
  // Don't try to create TRSBits objects.
  // Use TRSBits(PByte, PWord or pointer to data of any size) instead.
  // For example, TRSBits(@i).
end;

function TRSBits.GetBit(i:DWord): Boolean;
begin
  Result := PByte(DWord(self) + i div 8)^ and (1 shl (i mod 8)) <> 0;
end;

procedure TRSBits.SetBit(i:DWord; v: Boolean);
var
  j: PByte;
begin
  j:=PByte(DWord(self) + i div 8);
  if v then
    j^ := j^ or (1 shl (i mod 8))
  else
    j^ := j^ and not (1 shl (i mod 8));
end;

procedure TRSBits.FromBooleans(Buffer:pointer; Count:DWord; StartIndex:DWord=0);
var
  p:PByte; i,j:DWord; k:Byte;
begin
   // Optimized to death

  if Count=0 then exit;
  
  p:=PByte(PChar(self) + StartIndex div 8);
  i:=StartIndex mod 8;
  if i<>0 then
  begin
    k:=p^;
    j:=1 shl i;
    i:=8-i;
    if Count<i then i:=Count;
    dec(Count,i);
    while i<>0 do
    begin
      if PBoolean(Buffer)^ then
        k := k or j
      else
        k := k and not j;
      j:=j shl 1;
      inc(PBoolean(Buffer));
      dec(i);
    end;
    p^:=k;
    inc(p);
  end;

  for i:=(Count div 8) downto 1 do
  begin
    k:=0;
    j:=pint(Buffer)^;
    inc(pint(Buffer));
    if j and $ff <> 0 then  k := k or 1;
    if j and $ff00 <> 0 then  k := k or 2;
    if j and $ff0000 <> 0 then  k := k or 4;
    if j and $ff000000 <> 0 then  k := k or 8;
    j:=pint(Buffer)^;
    inc(pint(Buffer));
    if j and $ff <> 0 then  k := k or 16;
    if j and $ff00 <> 0 then  k := k or 32;
    if j and $ff0000 <> 0 then  k := k or 64;
    if j and $ff000000 <> 0 then  k := k or 128;
    p^:=k;
    inc(p);
  end;

  i:=Count mod 8;
  if i<>0 then
  begin
    k:=p^;
    j:=1;
    for i:=i downto 1 do
    begin
      if PBoolean(Buffer)^ then
        k := k or j
      else
        k := k and not j;
      j:=j shl 1;
      inc(PBoolean(Buffer));
    end;
    p^:=k;
  end;
end;

procedure TRSBits.ToBooleans(Buffer:pointer; Count:DWord; StartIndex:DWord = 0);
var
  j, k: Byte;
  p: PByte;
  i: DWord;
begin
   // Optimized to death
  
  if Count=0 then exit;

  p:=PByte(DWord(self) + StartIndex div 8);
  i:=StartIndex mod 8;
  if i<>0 then
  begin
    k:=p^;
    j:=1 shl i;
    i:=8-i;
    if Count<i then i:=Count;
    dec(Count,i);
    while i<>0 do
    begin
      PBoolean(Buffer)^:=k and j <> 0;
      j:=j shl 1;
      inc(PBoolean(Buffer));
      dec(i);
    end;
    inc(p);
  end;
  
  for i:=(Count div 8) downto 1 do
  begin
    k:=p^;
    PBoolean(Buffer)^:=k and 1 <> 0;
    inc(PBoolean(Buffer));
    PBoolean(Buffer)^:=k and 2 <> 0;
    inc(PBoolean(Buffer));
    PBoolean(Buffer)^:=k and 4 <> 0;
    inc(PBoolean(Buffer));
    PBoolean(Buffer)^:=k and 8 <> 0;
    inc(PBoolean(Buffer));
    PBoolean(Buffer)^:=k and 16 <> 0;
    inc(PBoolean(Buffer));
    PBoolean(Buffer)^:=k and 32 <> 0;
    inc(PBoolean(Buffer));
    PBoolean(Buffer)^:=k and 64 <> 0;
    inc(PBoolean(Buffer));
    PBoolean(Buffer)^:=k and 128 <> 0;
    inc(PBoolean(Buffer));
    inc(p);
  end;

  i:=Count mod 8;
  if i<>0 then
  begin
    k:=p^;
    j:=1;
    for i:=i downto 1 do
    begin
      PBoolean(Buffer)^:=k and j <> 0;
      j:=j shl 1;
      inc(PBoolean(Buffer));
    end;
  end;
end;

{
******************************** TRSCustomStack *********************************
}

constructor TRSCustomStack.Create(BlockSize:int);
begin
  FBlockSize:=BlockSize;
  FLastSize:=BlockSize;
end;

destructor TRSCustomStack.Destroy;
begin
  Clear;
  if FNextBlock<>nil then
    FreeBlock(FNextBlock);
  inherited Destroy;
end;

function TRSCustomStack.AllocBlock: ptr;
begin
  GetMem(Result, FBlockSize);
end;

procedure TRSCustomStack.FreeBlock(ABlock: ptr);
begin
  FreeMem(ABlock, FBlockSize);
end;

procedure TRSCustomStack.Clear;
var p:pptr; p1:ptr;
begin
//  FreeMem(FNextBlock);
//  FNextBlock:=nil;
  p:=FBlock;
  while p<>nil do
  begin
    p1:=p;
    p:=p^;
    FreeBlock(p1);
  end;
  FBlock:=nil;
  FBlockCount:=0;
end;

function TRSCustomStack.NewBlock:ptr;
begin
  Result:=FNextBlock;
  if Result=nil then
    Result:=AllocBlock
  else
    FNextBlock:=nil;
  pptr(Result)^:=FBlock;
  FBlock:=Result;
  inc(FBlockCount);
end;

function TRSCustomStack.WholePush(Size:int):ptr;
var i:int;
begin
  i:=FLastSize;
  if i=FBlockSize then
  begin
    Result:=NewBlock;
    i:=4;
  end else
    Result:=FBlock;

  inc(pbyte(Result), i);
  FLastSize:=i+Size;
end;

function TRSCustomStack.WholePop(Size:int):ptr;
var i:int;
begin
  Result:=FBlock;
  if Result=nil then exit;
  i:=FLastSize-Size;
  if i=4 then
  begin
    FreeBlock(FNextBlock);
    FNextBlock:=Result;
    FBlock:=pptr(Result)^;
    FLastSize:=FBlockSize;
    dec(FBlockCount);
  end else
    FLastSize:=i;
  inc(pbyte(Result), i);
end;

function TRSCustomStack.DoPeakAt(Offset:int):ptr;
var l:int;
begin
  if Offset > FLastSize-4 then
  begin
    dec(Offset, FLastSize-4);
    Result:=pptr(FBlock)^;
    l:=FBlockSize-4;
    while Offset>l do
    begin
      Result:=pptr(Result)^;
      dec(Offset, l);
    end;
    Result:=PChar(Result)+FBlockSize-Offset;
  end else
    Result:=PChar(FBlock)+FLastSize-Offset;
end;

procedure TRSCustomStack.DoPeak(var v; Size:int);
var l,Offset:int; p,Result:PChar;
begin
  Offset:=Size;
  p:=PChar(@v);
  if Offset > FLastSize-4 then
  begin
    dec(Offset, FLastSize-4);
    CopyMemory(p+Offset, PChar(FBlock)+4, FLastSize-4);
    Result:=pptr(FBlock)^;
    l:=FBlockSize-4;
    while Offset>l do
    begin
      dec(Offset, l);
      CopyMemory(p+Offset, PChar(Result)+4, l);
      Result:=pptr(Result)^;
    end;
    CopyMemory(p, Result+FBlockSize-Offset, Offset);
  end else
    CopyMemory(p, PChar(FBlock)+FLastSize-Offset, Offset);
end;

function TRSCustomStack.GetSize:int;
begin
  Result:= (FBlockSize-4)*FBlockCount + FLastSize - FBlockSize;
end;

function TRSCustomStack.BlockNextTo(p:ptr):ptr;
begin
  Result:= FBlock;
  if Result <> p then
    while Result<>nil do
    begin
      if pptr(Result)^ = p then  exit;
      Result:= pptr(Result)^;
    end;
  Result:=nil;
end;

{
******************************** TRSFixedStack *********************************
}

constructor TRSFixedStack.Create(ItemSize:int; BlockSize:int=4096);
begin
  if BlockSize > PageSize then
    BlockSize:= (BlockSize + PageSize - 1) and not (PageSize - 1);
  BlockSize:= BlockSize - (BlockSize-4) mod ItemSize;
  if BlockSize<=4 then
  begin
    Assert(BlockSize>4);
    BlockSize:= max(PageSize - (PageSize-4) mod ItemSize, ItemSize + 4);
  end;
  inherited Create(BlockSize);
  FItemSize:=ItemSize;
end;

function TRSFixedStack.AllocBlock: ptr;
begin
  if FBlockSize + FItemSize > PageSize then
    Result:=VirtualAlloc(nil, FBlockSize, MEM_COMMIT or MEM_RESERVE, PAGE_EXECUTE_READWRITE)
  else
    GetMem(Result, FBlockSize);
end;

procedure TRSFixedStack.FreeBlock(ABlock: ptr);
begin
  if FBlockSize + FItemSize > PageSize then
    VirtualFree(ABlock, 0, MEM_DECOMMIT	or MEM_RELEASE)
  else
    FreeMem(ABlock, FBlockSize);
end;

function TRSFixedStack.DoPush:ptr;
begin
  Result:=WholePush(FItemSize);
end;

function TRSFixedStack.DoPop:ptr;
begin
  Result:=WholePop(FItemSize);
end;

function TRSFixedStack.DoPeak:ptr;
begin
  Result:=PChar(FBlock)+FLastSize-FItemSize;
end;

function TRSFixedStack.DoPeakAtIndex(Index:int):ptr;
begin
  inc(Index);
  Result:=DoPeakAt(Index*FItemSize);
end;

procedure TRSFixedStack.Peak(var v; Count:int);
begin
  DoPeak(v, Count*FItemSize);
end;

procedure TRSFixedStack.PeakAll(var v);
begin
  DoPeak(v, Size);
end;

function TRSFixedStack.GetCount:int;
begin
  Result:= Size div FItemSize;
end;

{
********************************* TRSObjStack **********************************
}

constructor TRSObjStack.Create(BlockSize:int=4096);
begin
  inherited Create(SizeOf(TObject), BlockSize);
end;

procedure TRSObjStack.Push(Obj:TObject);
begin
  pptr(WholePush(FItemSize))^:=Obj;
end;

function TRSObjStack.Pop:TObject;
begin
  Result:=pptr(WholePop(FItemSize))^;
end;

function TRSObjStack.Peak:TObject;
begin
  Result:=pptr(DoPeak)^;
end;

function TRSObjStack.PeakAt(Index:int):TObject;
begin
  inc(Index);
  Result:=pptr(DoPeakAt(Index*SizeOf(TObject)))^;
end;

(*
{
******************************** TRSCustomQueue ********************************
}

constructor TRSCustomQueue.Create(ItemSize:int; BlockSize:int=4096);
begin
  inherited;
  FFillEvent:= CreateEvent(nil, true, false, nil);
  FCount:= 0;
end;

destructor TRSCustomQueue.Destroy;
begin
  CloseHandle(FFillEvent);
  inherited;
end;

function TRSCustomQueue.DoPop: ptr;
begin
  if FCount<>FPopCount then
  begin
    inc(FPopCount);

  end else
    Result:= nil;
end;

function TRSCustomQueue.AfterPush: ptr;
begin
  inc(FCount);
  SetEvent(FFillEvent);
end;

function TRSCustomQueue.GetCount: int;
begin
  Result:= FCount - FPopCount;
end;

procedure TRSCustomQueue.WaitFor(var Queue:TRSCustomQueue);
begin
  while (self = Queue) and (FCount = FPopCount) do
    WaitForSingleObject(FFillEvent, INFINITE);
end;

{
********************************* TRSObjQueue **********************************
}

constructor TRSObjQueue.Create(BlockSize: int);
begin

end;

function TRSObjQueue.Peak: TObject;
begin

end;

function TRSObjQueue.PeakAt(Index: int): TObject;
begin

end;

function TRSObjQueue.Pop: TObject;
begin

end;

procedure TRSObjQueue.Push(Obj: TObject);
begin

end;

*)

{
******************************** TRSSharedData *********************************
}

constructor TRSSharedData.Create(Name:string; Size:int);
begin
  FSize:=Size;
  FMMF:= RSWin32Check(CreateFileMapping(INVALID_HANDLE_VALUE, nil,
                        PAGE_READWRITE, 0, Size, ptr(Name)));
  FAlreadyExists:= GetLastError = ERROR_ALREADY_EXISTS;
  FData:= RSWin32Check(MapViewOfFile(FMMF, FILE_MAP_ALL_ACCESS, 0, 0, 0));
end;

constructor TRSSharedData.Create(MMF:THandle; Size:int);
begin
  FSize:=Size;
  FMMF:=MMF;
  FAlreadyExists:= true;
  FData:= RSWin32Check(MapViewOfFile(MMF, FILE_MAP_ALL_ACCESS, 0, 0, 0));
end;

destructor TRSSharedData.Destroy;
begin
  UnmapViewOfFile(FData);
  CloseHandle(FMMF);
  inherited;
end;

{
********************************* TRSFindFile **********************************
}

constructor TRSFindFile.Create(FileMask:string);
begin
  FPath:= ExtractFilePath(FileMask);
  FHandle:= FindFirstFile(ptr(FileMask), Data);
  FFound:= FHandle<>INVALID_HANDLE_VALUE;
  if not Found then
    CheckError;
end;

destructor TRSFindFile.Destroy;
begin
  FindClose(FHandle);
  inherited;
end;

procedure TRSFindFile.CheckError;
begin
  case GetLastError of
    ERROR_FILE_NOT_FOUND, ERROR_PATH_NOT_FOUND, ERROR_NO_MORE_FILES: ;
    else  RSRaiseLastOSError;
  end;
end;

function TRSFindFile.FindNext: Boolean;
begin
  FNotFirst:= true;
  FFileName:='';
  Result:= FindNextFile(FHandle, Data);
  FFound:= Result;
  if not Result then
    CheckError;
end;

function TRSFindFile.FindNextAttributes(Require, Exclude: DWord): Boolean;
begin
  if FNotFirst then
    FindNext;
  FNotFirst:= true;
  Result:= FindAttributes(Require, Exclude);
end;

function TRSFindFile.FindAttributes(Require, Exclude: DWord): Boolean;
var bits:DWord;
begin
  bits:= Require or Exclude;
  while Found and ((Data.dwFileAttributes and bits) <> Require) do
    FindNext;
  Result:=Found;
end;

function TRSFindFile.GetFileName: string;
begin
  if Found and (FFileName = '') then
    FFileName:= Path + Data.cFileName;
  Result:= FFileName;
end;

{
********************************* TRSEventHook *********************************
}

constructor TRSEventHook.Create(Priority:int);
var Obj:TRSEventHook; NewMethod:TMethod;
begin
  inherited Create;
  FPriority:=Priority;

  NewMethod.Data:=self;
  NewMethod.Code:=FEventProc;
  FLastProc:=ObjEvent;
  Obj:=nil;
  while FLastProc.Code = NewMethod.Code do
  begin
    Obj:=FLastProc.Data;
    FLastProc:=Obj.FLastProc;
    if Obj.FPriority<=Priority then
      break;
  end;
  if Obj<>nil then
  begin
    FNext:=Obj;
    Obj.FLastProc:=NewMethod;
    if FLastProc.Code = NewMethod.Code then
      TRSEventHook(FLastProc.Data).FNext:=self;
  end else
    SetEvent(NewMethod);
end;

procedure TRSEventHook.Delete;
begin
  if FDeleting then exit;
  FDeleting:=true;

  if FNext<>nil then
    FNext.FLastProc:=FLastProc
  else
    if ObjEvent.Data<>self then
      exit
    else
      ObjEvent:=FLastProc;

  if FLastProc.Code = FEventProc then
    TRSEventHook(FLastProc.Data).FNext:=FNext;
  Lock(false);
end;

procedure TRSEventHook.Lock(aLock:boolean);
begin
  if self=nil then exit;
  if not aLock then
  begin
    dec(FLockCount);
    if FLockCount<0 then
      Free;
  end else
    inc(FLockCount);
end;

function TRSEventHook.GetLast:TRSEventHook;
begin
  Result:=FLastProc.Data;
  if FLastProc.Code<>FEventProc then
    Result:=nil;
end;


{
***************************** TRSShellChangeNotifier *****************************
}

constructor TRSShellChangeNotifier.Create(OnChange: TNotifyEvent = nil);
begin
  FOnChange:= OnChange;
  InitializeCriticalSection(FCS);
  inherited Create(false);
end;

destructor TRSShellChangeNotifier.Destroy;
begin
  FreeOnTerminate:= false;
  Terminate;
  DeleteCriticalSection(FCS);
  inherited Destroy;
end;

procedure TRSShellChangeNotifier.Free;
begin
  if self=nil then  exit;
  if FWakeEvent <> 0 then
  begin
    EnterCriticalSection(FCS);
    try
      if FWakeEvent <> 0 then
      begin
        FreeOnTerminate:=true;
        Terminate;
        exit;
      end;
    finally
      LeaveCriticalSection(FCS);
    end;
  end;
  Destroy;
end;

procedure TRSShellChangeNotifier.Terminate;
begin
  if not Terminated then
  begin
    inherited Terminate;
    if FWakeEvent <> 0 then
      SetEvent(FWakeEvent);
  end;
end;

procedure TRSShellChangeNotifier.Execute;
var
  WaitHandle: Integer; Handles: array[0..1] of Integer;
begin
  try
    FWakeEvent:= CreateEvent(nil, false, false, nil);
    Handles[0]:= FWakeEvent;
    while true do
    begin
      WaitHandle:= ERROR_INVALID_HANDLE;
      while true do
      begin
        if Terminated then  exit;
        EnterCriticalSection(FCS);
        try
          FReset:= false;
          if FDirectory<>'' then
            WaitHandle:= FindFirstChangeNotification(PChar(FDirectory),
               LongBool(FWatchSubTree), FFlags);
        finally
          LeaveCriticalSection(FCS);
        end;
        
        if WaitHandle <> ERROR_INVALID_HANDLE then  break;
        if WaitForSingleObject(FWakeEvent, INFINITE) = WAIT_FAILED then
          exit;
      end;
      Handles[1] := WaitHandle;
      case WaitForMultipleObjects(2, @Handles, false, INFINITE) of
        WAIT_OBJECT_0:
          FindCloseChangeNotification(WaitHandle);

        WAIT_OBJECT_0 + 1:
          if not Terminated and not FReset and TryEnterCriticalSection(FCS) then
          begin
            FNeedRefresh:=true;
            LeaveCriticalSection(FCS);
            Synchronize(CallOnChange);
            FindNextChangeNotification(WaitHandle);
          end else
            FindCloseChangeNotification(WaitHandle);

        WAIT_FAILED:
        begin
          FindCloseChangeNotification(WaitHandle);
          if WaitForSingleObject(FWakeEvent, INFINITE) = WAIT_FAILED then
            exit;
        end;
      end;
    end;
  finally
    EnterCriticalSection(FCS);
    CloseHandle(FWakeEvent);
    FWakeEvent:= 0;
    LeaveCriticalSection(FCS);
  end;
end;

procedure TRSShellChangeNotifier.CallOnChange;
var b:Boolean;
begin
  b:=FNeedRefresh;
  FNeedRefresh:=false;
  if b and not FReset and Assigned(FOnChange) then
    FOnChange(self);
end;

procedure TRSShellChangeNotifier.SetOptions(Directory: string;
  WatchSubTree: Boolean; Flags: DWord);
begin
  EnterCriticalSection(FCS);
  try
    FReset:= true;
    if FWakeEvent<>0 then  SetEvent(FWakeEvent);
    FDirectory:= Directory;
    FWatchSubTree:= WatchSubTree;
    FFlags:= Flags;
  except
    ptr(FDirectory):=nil;
    LeaveCriticalSection(FCS);
    raise;
  end;
  LeaveCriticalSection(FCS);
end;

procedure TRSShellChangeNotifier.Cancel;
begin
  SetOptions('', false, 0);
end;

procedure TRSShellChangeNotifier.Reset;
begin
  EnterCriticalSection(FCS);
  FReset:= true;
  if FWakeEvent<>0 then  SetEvent(FWakeEvent);
  LeaveCriticalSection(FCS);
end;

function TRSShellChangeNotifier.GetNeedRefresh: Boolean;
begin
  Result:= FNeedRefresh and not FReset;
end;

{---------------------------------------------------------------------}

procedure RaiseLastOSErrorAt(Offset:PChar);
var
  LastError: Integer;
  Error: EOSError;
begin
  LastError := GetLastError;
  if LastError <> 0 then
    Error := EOSError.CreateResFmt(@SOSError, [LastError,
      SysErrorMessage(LastError)])
  else
    Error := EOSError.CreateRes(@SUnkOSError);
  Error.ErrorCode := LastError;
  raise Error at Offset;
end;

procedure RSRaiseLastOSError;
asm
  mov eax, [esp]
  sub eax, 5
  jmp RaiseLastOSErrorAt
end;

function RSWin32Check(RetVal: LongBool): LongBool;
asm
  test eax, eax
  jz RSRaiseLastOSError
end;

function RSWin32Check(CheckForZero:int):int;
asm
  test eax, eax
  jz RSRaiseLastOSError
end;

function RSWin32Check(CheckForZero:ptr):ptr;
asm
  test eax, eax
  jz RSRaiseLastOSError
end;

function FindDynaClass(AClass:TClass; DMIndex:int):ptr; register;
asm
  jmp System.@FindDynaClass
end;

procedure RSDispatchEx(Obj:TObject; AClass:TClass; var Message);
var a:TMethod;
begin
  a.Data:=Obj;
  try
    a.Code:= FindDynaClass(AClass, word(Message));
  except
    Obj.DefaultHandler(Message);
    exit;
  end;
  TWndMethod(a)(TMessage(Message));
end;

 // From Grids.pas
procedure RSFillDWord(Dest:ptr; Count, Value: Integer); register;
asm
  XCHG  EDX, ECX
  PUSH  EDI
  MOV   EDI, EAX
  MOV   EAX, EDX
  REP   STOSD
  POP   EDI
end;


function RSQueryPerformanceCounter: int64;
begin
  RSWin32Check(QueryPerformanceCounter(Result));
end;

function RSQueryPerformanceFrequency: int64;
begin
  RSWin32Check(QueryPerformanceFrequency(Result));
end;


{
procedure RSSetLayeredAttribs(Handle:HWnd;
             AlphaBlend:boolean; AlphaBlendValue:byte;
             TransparentColor:boolean; TransparentColorValue:int);
const
  cUseAlpha: array [Boolean] of Integer = (0, LWA_ALPHA);
  cUseColorKey: array [Boolean] of Integer = (0, LWA_COLORKEY);
var
  Style: Integer;
begin
  if OSVersion.dwMajorVersion<5 then exit;
  Style := GetWindowLong(Handle, GWL_EXSTYLE);
  if AlphaBlend or TransparentColor then
  begin
    if (Style and WS_EX_LAYERED) = 0 then
      SetWindowLong(Handle, GWL_EXSTYLE, Style or WS_EX_LAYERED);
    SetLayeredWindowAttributes(Handle, TransparentColorValue, AlphaBlendValue,
      cUseAlpha[AlphaBlend] or cUseColorKey[TransparentColor]);
  end else
  if (Style and WS_EX_LAYERED) <> 0 then
  begin
    SetWindowLong(Handle, GWL_EXSTYLE, Style and not WS_EX_LAYERED);
    RedrawWindow(Handle, nil, 0, RDW_ERASE or RDW_INVALIDATE or RDW_FRAME or RDW_ALLCHILDREN);
  end;
end;
{}

function RSGetModuleFileName(hModule: HINST = 0):string;
var ss:array[0..MAX_PATH] of char;
begin
  RSWin32Check(GetModuleFileName(hModule, ss, MAX_PATH+1));
  Result:= PChar(@ss[0]);
end;

function RSFileExists(const FileName: string): Boolean; {$IFDEF D2005}inline;{$ENDIF}
begin
  Result:= RSQ.FileExists(FileName);
end;

function RSMoveFile(const OldName, NewName: string; FailIfExists: Boolean): Bool;
begin
  if not FailIfExists and FileExists(OldName) then
  begin
    //FileSetReadOnly(NewName, false);
    DeleteFile(ptr(NewName));
  end;
  Result:= MoveFile(ptr(OldName), ptr(NewName));
end;

function RSCreateFile(const FileName:string; dwDesiredAccess:DWord;
           dwShareMode:DWord;
           lpSecurityAttributes:PSecurityAttributes;
           dwCreationDistribution, dwFlagsAndAttributes:DWord;
           hTemplateFile:HFile):HFile;
begin
  if ((dwCreationDistribution =CREATE_ALWAYS)
     or (dwCreationDistribution = CREATE_NEW)
     or (dwCreationDistribution = OPEN_ALWAYS))
     and not RSCreateDir(ExtractFilePath(FileName)) then
  begin
    Result:=INVALID_HANDLE_VALUE;
  end else
    Result:=CreateFile(PChar(FileName), dwDesiredAccess, dwShareMode,
     lpSecurityAttributes, dwCreationDistribution, dwFlagsAndAttributes,
     hTemplateFile);
end;

function RSLoadFile(FileName:string):TRSByteArray;
var f:hfile; i:DWord;
begin
  f:=RSCreateFile(FileName, GENERIC_READ, FILE_SHARE_READ, nil, OPEN_EXISTING,
                   FILE_ATTRIBUTE_NORMAL or FILE_FLAG_SEQUENTIAL_SCAN);
  if f=INVALID_HANDLE_VALUE then RSRaiseLastOSError;
  try
    i:=GetFileSize(f,nil);
    if i=DWord(-1) then RSRaiseLastOSError;
    SetLength(Result,i);
    if (i<>0) and (DWord(FileRead(f,Result[0],i))<>i) then RSRaiseLastOSError;
  finally
    FileClose(f);
  end;
end;

function RSLoadTextFile(FileName:string):string;
var f:hfile; i:DWord;
begin
  f:=RSCreateFile(FileName, GENERIC_READ, FILE_SHARE_READ, nil, OPEN_EXISTING,
                   FILE_ATTRIBUTE_NORMAL or FILE_FLAG_SEQUENTIAL_SCAN);
  if f=INVALID_HANDLE_VALUE then RSRaiseLastOSError;
  try
    i:=GetFileSize(f,nil);
    if i=DWord(-1) then RSRaiseLastOSError;
    SetLength(Result,i);
    if (i<>0) and (DWord(FileRead(f,Result[1],i))<>i) then RSRaiseLastOSError;
  finally
    FileClose(f);
  end;
end;

procedure DoSaveFile(FileName:string; var Data; L:int);
var f:HFile;
begin
  //FileSetReadOnly(FileName, false);
  f:=RSCreateFile(FileName, GENERIC_WRITE);
  if f=INVALID_HANDLE_VALUE then RSRaiseLastOSError;
  try
    if (L<>0) and (FileWrite(f,Data,L)<>L) then  RSRaiseLastOSError;
  finally
    FileClose(f);
  end;
end;

procedure RSSaveFile(FileName:string; Data:TRSByteArray);
begin
  DoSaveFile(FileName, Data[0], length(Data));
end;

procedure RSSaveFile(FileName:string; Data:TMemoryStream; RespectPosition: Boolean = false);
var
  pos: Int64;
begin
  if RespectPosition then
  begin
    pos:= Data.Position;
    DoSaveFile(FileName, (PChar(Data.Memory) + pos)^, Data.Size - pos);
  end else
    DoSaveFile(FileName, Data.Memory^, Data.Size);
end;

procedure RSSaveTextFile(FileName:string; Data:string);
begin
  DoSaveFile(FileName, Data[1], length(Data));
end;

procedure DoAppendFile(FileName:string; var Data; L:int);
var f:hfile;
begin
  FileSetReadOnly(FileName, false);
  f:=RSCreateFile(FileName, GENERIC_WRITE, 0, nil, OPEN_ALWAYS);
  if f=INVALID_HANDLE_VALUE then RSRaiseLastOSError;
  try
    if (L<>0) and ((FileSeek(f, 0, 2) = -1) or (FileWrite(f,Data,L) <> L)) then
      RSRaiseLastOSError;
  finally
    FileClose(f);
  end;
end;

procedure RSAppendFile(FileName:string; Data:TRSByteArray);
begin
  DoAppendFile(FileName, Data[0], length(Data));
end;

procedure RSAppendFile(FileName:string; Data:TMemoryStream; RespectPosition: Boolean = false);
var
  pos: Int64;
begin
  if RespectPosition then
  begin
    pos:= Data.Position;
    DoAppendFile(FileName, (PChar(Data.Memory) + pos)^, Data.Size - pos);
  end else
    DoAppendFile(FileName, Data.Memory^, Data.Size);
end;

procedure RSAppendTextFile(FileName:string; Data:string);
begin
  DoAppendFile(FileName, Data[1], length(Data));
end;

function RSCreateDir(const PathName:string):boolean;
var s:string;
begin
  Result:=(PathName='') or DirectoryExists(PathName);
  if Result then exit;
  s:= ExtractFilePath(ExcludeTrailingPathDelimiter(ExpandFileName(PathName)));
  Result:= (s = PathName) or RSCreateDir(s) and CreateDir(PathName);
end;

function RSCreateDirectory(const PathName:string;
           lpSecurityAttributes:PSecurityAttributes):boolean;
begin
  Result:=RSCreateDir(
            ExtractFilePath(ExcludeTrailingPathDelimiter(PathName)));
  if Result then
    Result:=CreateDirectory(PChar(PathName), lpSecurityAttributes);
end;

function RSCreateDirectoryEx(const lpTemplateDirectory, NewDirectory:string;
   lpSecurityAttributes:PSecurityAttributes = nil):boolean;
begin
  Result:=RSCreateDir(
         ExtractFilePath(ExcludeTrailingPathDelimiter(NewDirectory)));
  if Result then
    Result:=CreateDirectoryEx(ptr(lpTemplateDirectory),
              ptr(NewDirectory), lpSecurityAttributes);
end;

function RSRemoveDir(const Dir:string):boolean;
begin
  Result:=RSFileOperation(Dir, '', FO_DELETE);
end;

function DoubleNull(const s:string):string;
begin
  if s <> '' then
    SetString(Result, PChar(ptr(s)), length(s))
  else
    Result:= '';
end;

function NullArray(const a:array of string):string;
var i,j,k:int;
begin
  j:=0;
  for i:=high(a) downto low(a) do
    if a[i]<>'' then
      inc(j, length(a[i])+1);
  SetLength(Result, j);
  if j=0 then exit;
  j:=1;
  for i:=high(a) downto low(a) do
    if a[i]<>'' then
    begin
      k:=length(a[i])+1;
      CopyMemory(@Result[j], @a[i][1], k);
      inc(j, k);
    end;
end;

function RSFileOperation(const aFrom, aTo:string; FileOperation: uint;
 Flags: FILEOP_FLAGS = FOF_NOCONFIRMATION or FOF_NOCONFIRMMKDIR or FOF_NOERRORUI or FOF_SILENT):boolean; overload;
var a:TSHFileOpStruct; s, s1:string;
begin
  s:= DoubleNull(aFrom);
  if FileOperation <> FO_DELETE then
    s1:= DoubleNull(aTo);

  with a do
  begin
    Wnd:=0;
    wFunc:=FileOperation;
    pFrom:=ptr(s);
    pTo:=ptr(s1);
    fFlags:=Flags and not (FOF_MULTIDESTFILES or FOF_WANTMAPPINGHANDLE);
    fAnyOperationsAborted:=false;
    hNameMappings:=nil;
    lpszProgressTitle:=nil;
  end;
  Result:= SHFileOperation(a)=0;
end;

function RSFileOperation(const aFrom, aTo: array of string; FileOperation: uint;
   Flags: FILEOP_FLAGS = FOF_NOCONFIRMATION or FOF_NOCONFIRMMKDIR or
          FOF_NOERRORUI or FOF_SILENT) : boolean; overload;
var a:TSHFileOpStruct; s, s1:string;
begin
  s:= NullArray(aFrom);
  if FileOperation <> FO_DELETE then
    s1:= NullArray(aTo);

  with a do
  begin
    Wnd:=0;
    wFunc:=FileOperation;
    pFrom:=ptr(s);
    pTo:=ptr(s1);
    fFlags:=Flags and not FOF_WANTMAPPINGHANDLE;
    fAnyOperationsAborted:=false;
    hNameMappings:=nil;
    lpszProgressTitle:=nil;
  end;
  Result:= SHFileOperation(a)=0;
end;

function RSSearchPath(Path, FileName, Extension:string):string;
var
  Buffer: array[0..MAX_PATH] of char;
  i:int; p:PChar;
begin
  i:= SearchPath(ptr(Path), ptr(FileName), ptr(Extension), MAX_PATH + 1, @Buffer, p);
  RSWin32Check(i);
  if i <= MAX_PATH + 1 then
  begin
    SetLength(Result, i - 1);
    if Result<>'' then
      Move(Buffer, Result[1], i - 1);
  end else
  begin
    SetLength(Result, i - 1);
    i:= SearchPath(ptr(Path), ptr(FileName), ptr(Extension), 0, ptr(Result), p);
    RSWin32Check(i);
  end;
end;

procedure RSCopyStream(Dest, Source: TStream; Count: int64);
var
  i: int64;
begin
  if (Source is TCustomMemoryStream) and (zSet(i, Source.Position) + Count < Source.Size) then
  begin
    Dest.WriteBuffer((PChar(TCustomMemoryStream(Source).Memory) + i)^, Count);
    Source.Seek(Count, soCurrent);
  end else
    if Dest is TMemoryStream then
      with TMemoryStream(Dest) do
      begin
        i:= Position;
        if i + Count > Size then
          Size:= i + Count;
        Source.ReadBuffer((PChar(Memory) + UintPtr(i))^, Count);
        Seek(Count, soCurrent);
      end
    else
      Dest.CopyFrom(Source, Count);
end;

{----------------------- RSLoadProc --------------------------}

function DoLoadProc(var Proc:Pointer; const LibName:string; ProcName:pointer;
   LoadLib:Boolean):hInst; overload;
var p:ptr;
begin
  if LoadLib then
    Result:= LoadLibrary(ptr(LibName))
  else
    Result:= GetModuleHandle(ptr(LibName));

  if Result<>0 then
  begin
    p:=GetProcAddress(Result, ProcName);
    if p = nil then
    begin
      if LoadLib then  FreeLibrary(Result);
      Result:=0;
    end else
      Proc:=p;
  end;
end;

function RSLoadProc(var Proc:Pointer; const LibName, ProcName:string;
   LoadLib:Boolean = true):hInst; overload;
begin
  Result:=DoLoadProc(Proc, LibName, ptr(ProcName), LoadLib);
end;

function RSLoadProc(var Proc:Pointer; const LibName:string; ProcIndex:word;
   LoadLib:Boolean = true):hInst; overload;
begin
  Result:=DoLoadProc(Proc, LibName, ptr(ProcIndex), LoadLib);
end;

function RSLoadProc(var Proc:Pointer; const LibName, ProcName:string;
   LoadLib:Boolean; RaiseException:boolean):hInst; overload;
begin
  Result:=DoLoadProc(Proc, LibName, ptr(ProcName), LoadLib);
  if (Result=0) and RaiseException then
    raise Exception.Create(Format(sRSCantLoadProc, [ProcName, LibName]));
end;

function RSLoadProc(var Proc:Pointer; const LibName:string; ProcIndex:word;
   LoadLib:Boolean; RaiseException:boolean):hInst; overload;
begin
  Result:=DoLoadProc(Proc, LibName, ptr(ProcIndex), LoadLib);
  if (Result=0) and RaiseException then
    raise Exception.Create(Format(sRSCantLoadIndexProc, [ProcIndex, LibName]));
end;

{---------------------- RSDelayLoad ---------------------}

type
  PDelayedImport = ^TDelayedImport;
  TDelayedImport = packed record
    Call: Byte;
    Adress: Pointer;
    State: Byte;
    Proc: PPointer;
    LibN: string;
    ProcN: pointer;
    Module: hInst;
  end;

const
  DelaySize = PageSize;
  DINamed = 1;
  DILoadLib = 2;

var
  Delays: TRSFixedStack;
  DelaysOnClose: procedure;

 // Returns the address to call
function DelayProc(var Import:TDelayedImport):pointer;
var h:hInst;
begin
  with Import do
    if Proc^=@Import then
    begin
      if State and DINamed <> 0 then
        h:=RSLoadProc(Proc^, LibN, string(ProcN), State and DILoadLib <> 0,true)
      else
        h:=RSLoadProc(Proc^, LibN, word(ProcN), State and DILoadLib <> 0, true);

      h:= InterlockedExchange(int(Module), h);
      if h<>0 then  FreeLibrary(h);
    end;
  Result:= Import.Proc^;
end;

procedure DelayAsmProc;
asm
   // Stack: <TDelayData adress + 5> <return adress> <proc params>
  xchg [esp], eax
  push ecx
  push edx

  add eax, -5
  call DelayProc

  pop edx
  pop ecx
  xchg [esp], eax
   // Stack: <loaded proc adress> <return adress> <proc params>
end;

procedure FreeDelayImports; forward;

procedure DoDelayLoad(var ProcAddress:Pointer; const LibName:string;
                      ProcName:pointer; LoadLib:Boolean; ANamed:boolean);
begin
  if Delays=nil then
  begin
    Delays:=TRSFixedStack.Create(SizeOf(TDelayedImport), DelaySize);
    if IsLibrary then  DelaysOnClose:=@FreeDelayImports;
  end;

  ProcAddress:=Delays.DoPush;
  with PDelayedImport(ProcAddress)^ do
  begin
    MakeCall(ProcAddress, @DelayAsmProc);
    Proc:= @ProcAddress;
    ptr(LibN):=nil;
    LibN:= LibName;
    ProcN:= ProcName;
    Module:= 0;
    State:= BoolToInt[ANamed]*DINamed + BoolToInt[LoadLib]*DILoadLib;
  end;
end;

procedure RSDelayLoad(var ProcAddress:Pointer; const LibName, ProcName:string;
   LoadLib:Boolean = true);
var s:string;
begin
  s:=ProcName;
  DoDelayLoad(ProcAddress, LibName, ptr(s), LoadLib, true);
  pointer(s):=nil;
end;

procedure RSDelayLoad(var ProcAddress:Pointer; const LibName:string;
  ProcIndex:word; LoadLib:Boolean = true);
begin
  DoDelayLoad(ProcAddress, LibName, ptr(ProcIndex), LoadLib, false);
end;

procedure FreeDelayImports;
var p:PDelayedImport;
begin
  p:=Delays.DoPop;
  repeat
    with p^ do
    begin
      LibN:='';
      if State and DINamed <> 0 then
        string(ProcN):='';
      if Module <> 0 then
        FreeLibrary(Module);
    end;
    p:=Delays.DoPop;
  until p=nil;

  FreeAndNil(Delays);
end;

{---------------------- RSMakeLessParamsFunction ---------------------}

procedure ObjectInstanceProc;
asm
  pop eax
  pop edx // Return address
  push [eax + 4] // Param
  push edx // Return address
  jmp [eax]
end;

procedure ObjectInstanceProcRegisterSmall;
asm
  mov ecx, edx
  mov edx, eax
  pop eax
  push [eax] // Return address
  mov eax, [eax+4] // Param
end;

{
procedure ObjectInstanceProcRegisterBig;
asm
  xchg ecx, [esp+4]
  xchg ecx, [esp]
  xchg edx, ecx
  xchg eax, edx
  push [eax] // Return address
  mov eax, [eax+4] // Param
end;
}

procedure RSMakeObjectInstance(var ObjInst:TRSObjectInstance;
   Obj, ProcStdCall:ptr);
begin
  MakeCall(@ObjInst.Code, @ObjectInstanceProc);
  ObjInst.Proc:=ProcStdCall;
  ObjInst.Obj:=Obj;
end;

procedure RSCustomObjectInstance(var ObjInst:TRSObjectInstance;
             Obj, Proc, CustomProc:ptr);
begin
  MakeCall(@ObjInst.Code, CustomProc);
  ObjInst.Proc:=Proc;
  ObjInst.Obj:=Obj;
end;

function RSMakeLessParamsFunction(
   ProcStdCall:pointer; Param:ptr):Pointer; overload;
begin
  GetMem(Result, SizeOf(TRSObjectInstance));
  RSMakeObjectInstance(TRSObjectInstance(Result^), ProcStdCall, Param);
end;

procedure LessParamsProc;
asm
  pop eax
  
// EAX structure:
//  Params Count
//  Proc address
//  Params...

  mov ecx, [eax] // Count
  add eax, 4 // Skip Count
   // Don't skip Proc address, ecx*4 will skip it
  pop edx // Return address

@loop:
  push [eax + ecx*4]
  dec ecx
  jz @loop

  push edx // Return address
  jmp [eax]
end;

function RSMakeLessParamsFunction(
            ProcStdCall:pointer; DWordParams:Pointer;
            Count:int; ResultInParam:int=-1):Pointer; overload;
var i:integer; n:int; p:pptr;
begin
  if (ResultInParam>=0) and (ResultInParam<=Count) then
    n:=Count+1
  else
    n:=Count;
  GetMem(Result, 5+8 + 4*n);
  p:=MakeCall(Result, @LessParamsProc);
  p^:=ptr(Count);
  inc(p);
  p^:=ProcStdCall;
  inc(p);

  for i:=0 to Count-1 do
  begin
    if ResultInParam=i then
    begin
      p^:=Result;
      inc(p);
    end;
    p^:=pptr(DWordParams)^;
    inc(p);
    inc(pptr(DWordParams));
  end;
  
  if ResultInParam=Count then p^:=Result;
end;

{
function RSMakeLessParamsFunction(
            ProcStdCall:pointer; DWordParams:Pointer;
            Count:integer; ResultInParam:integer=-1):Pointer; overload;
const First=$58;    // POP EAX
      Loop=$68;     // PUSH DWordParams[i]
      Middle=$B850; // PUSH EAX
                    // MOV EAX ProcPtr
      Last=$E0FF;   // JMP EAX
      EdgesSize = SizeOf(First) + SizeOf(Middle) + SizeOf(Last) + 4;
      LoopSize = SizeOf(Loop) + 4;

var p:Pointer;

  procedure AddParam(const i:DWord);
  begin
    PByte(p)^:=Loop;
    inc(PByte(p));
    PDWord(p)^:=i;
    inc(PDWord(p));
  end;

var i:integer; n:DWord;
begin
  if (ResultInParam>=0) and (ResultInParam<=Count) then n:=Count+1
  else n:=Count;
  i:= EdgesSize + LoopSize*n;
  GetMem(p,i);
  Result:=p;
  if Result=nil then exit;
  PByte(p)^:=First;
  inc(PByte(p));
  DWordParams:=pointer(DWord(DWordParams)+Dword(Count)*4);
  if ResultInParam=Count then AddParam(DWord(Result));
  for i:=Count-1 downto 0 do
  begin
    dec(PDWord(DWordParams));
    AddParam(PDWord(DWordParams)^);
    if ResultInParam=i then AddParam(DWord(Result));
  end;
  PWord(p)^:=Middle;
  inc(PWord(p));
  PPointer(p)^:=ProcStdCall;
  inc(PPointer(p));
  PWord(p)^:=Last;
//  inc(PWord(p));
end;
}

function RSMakeLessParamsFunction(
            ProcStdCall:pointer; const DWordParams:array of DWord;
            ResultInParam:integer=-1):Pointer; overload;
begin
  Result:=RSMakeLessParamsFunction(
                  ProcStdCall, @DWordParams[low(DWordParams)],
                  high(DWordParams)-low(DWordParams)+1, ResultInParam);
end;

procedure RSFreeLessParamsFunction(Ptr:Pointer);
begin
  FreeMem(Ptr);
end;

{
procedure ReplaceIATEntryInOneMod(PCSTR pszCalleeModName,
   PROC pfnCurrent, PROC pfnNew, HMODULE hmodCaller)
var Size:uint; pImportDesc:PIMAGE_IMPORT_DESCRIPTOR;
begin
     = (PIMAGE_IMPORT_DESCRIPTOR)
      ImageDirectoryEntryToData(hmodCaller, TRUE,
      IMAGE_DIRECTORY_ENTRY_IMPORT, &ulSize);

   if (pImportDesc == NULL)
      return;  // This module has no import section.

   for (; pImportDesc->Name; pImportDesc++) begin
      PSTR pszModName = (PSTR)
         ((PBYTE) hmodCaller + pImportDesc->Name);
      if (lstrcmpiA(pszModName, pszCalleeModName) == 0)
         break;
   end;

   if (pImportDesc->Name == 0)
      return;

   PIMAGE_THUNK_DATA pThunk = (PIMAGE_THUNK_DATA)
      ((PBYTE) hmodCaller + pImportDesc->FirstThunk);

   for (; pThunk->u1.Function; pThunk++) begin

      PROC* ppfn = (PROC*) &pThunk->u1.Function;

      BOOL fFound = ( *ppfn == pfnCurrent);

      if (fFound) begin
         // The addresses match; change the import section address.
         WriteProcessMemory(GetCurrentProcess(), ppfn, &pfnNew,
            sizeof(pfnNew), NULL);
         return;  // We did it; get out.
      end;
   end;
end;
}

{----------------------- TokenPrivileges --------------------------}

function RSEnableTokenPrivilege(TokenHandle:THandle; const Privilege:string;
  Enable:Boolean):boolean;
var
  Priv: TTokenPrivileges;
begin
  Priv.PrivilegeCount:= 1;
  if Enable then
    Priv.Privileges[0].Attributes:= SE_PRIVILEGE_ENABLED
  else
    Priv.Privileges[0].Attributes:= 0;

  Result:=
    LookupPrivilegeValue(nil, PChar(Privilege), Priv.Privileges[0].Luid) and
    AdjustTokenPrivileges(TokenHandle, false, Priv, 0, nil, DWord(nil^));
end;

function RSEnableProcessPrivilege(hProcess:THandle; const Privilege:string;
  Enable:boolean):boolean;
var
  TokenHandle:THandle; i:DWord;
begin
  Result:= OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, TokenHandle);
  if Result then
    try
      Result:= RSEnableTokenPrivilege(TokenHandle, Privilege, Enable);
    finally
      i:=GetLastError;
      CloseHandle(TokenHandle);
      SetLastError(i);
    end;
end;

function RSEnableDebugPrivilege(Enable:boolean):boolean;
const
  Priv = 'SeDebugPrivilege';
begin
  Result:= RSEnableProcessPrivilege(GetCurrentProcess, Priv, Enable);
end;

{----------------------- RSCreateRemoteCopy --------------------------}

function RSCreateRemoteCopy(CurPtr:Pointer; var RemPtr:Pointer;
                      Len, hProcess:DWord; var Mapping:DWord):boolean;
begin
  Result:=false;
  if OSVersion.dwPlatformId = VER_PLATFORM_WIN32_WINDOWS then
  begin // Win 9x
    Mapping:=CreateFileMapping(INVALID_HANDLE_VALUE, nil,
                                     PAGE_READWRITE, 0, Len, nil);
    if Mapping=0 then exit;
    RemPtr:=MapViewOfFile(Mapping,FILE_MAP_ALL_ACCESS,0,0,0);
    if RemPtr=nil then
    begin
      CloseHandle(Mapping);
      exit;
    end;
    Move(CurPtr^,RemPtr^,Len);
    Result:=true;
  end else
  begin // Win NT
    if hProcess=0 then exit;
    Mapping:=0;
    RemPtr:=VirtualAllocEx(hProcess, nil, Len, MEM_COMMIT,
                                   PAGE_EXECUTE_READWRITE);
    if RemPtr=nil then exit;
    Result:=WriteProcessMemory(hProcess, RemPtr,
                                       CurPtr, Len, Cardinal(nil^));
  end;
end;

function RSCreateRemoteCopyID(CurPtr:Pointer; var RemPtr:Pointer;
                      Len, ProcessID:DWord; var Mapping:DWord):boolean;
var Pr:DWord;
begin
  if OSVersion.dwPlatformId <> VER_PLATFORM_WIN32_WINDOWS then
    if ProcessID=0 then Result:=false
    else begin
      Pr:=OpenProcess(PROCESS_VM_OPERATION or PROCESS_VM_WRITE, false,
         ProcessID);
      Result:=RSCreateRemoteCopy(CurPtr, RemPtr, Len, Pr, Mapping);
      if Pr<>0 then CloseHandle(Pr);
    end
  else Result:=RSCreateRemoteCopy(CurPtr, RemPtr, Len, 0, Mapping);
end;

function RSCreateRemoteCopyWnd(CurPtr:Pointer; var RemPtr:Pointer;
                     Len:DWord; wnd:hWnd; var Mapping:DWord):boolean;
var pID, Pr:DWord;
begin
  if OSVersion.dwPlatformId <> VER_PLATFORM_WIN32_WINDOWS then
  begin
    GetWindowThreadProcessId(wnd, pID);
    if pID=0 then Result:=false
    else begin
      Pr:=OpenProcess(PROCESS_VM_OPERATION or PROCESS_VM_WRITE,
                         false, pID);
      Result:=RSCreateRemoteCopy(CurPtr, RemPtr, Len, Pr, Mapping);
      if Pr<>0 then CloseHandle(Pr);
    end;
  end else Result:=RSCreateRemoteCopy(CurPtr, RemPtr, Len, 0, Mapping);
end;

{------------------------- RSFreeRemoteCopy --------------------------}

function RSFreeRemoteCopy(CurPtr, RemPtr:pointer;
                           Len, hProcess, Mapping:DWord):boolean;
begin
  if OSVersion.dwPlatformId = VER_PLATFORM_WIN32_WINDOWS then
  begin // Win 9x
    try
      if Len<>0 then Move(RemPtr^, CurPtr^, Len);
      Result:=true;
    except
      Result:=false;
    end;
    UnmapViewOfFile(RemPtr);
    CloseHandle(Mapping);
  end else
  begin // Win NT
    if hProcess=0 then
    begin
      Result:=false;
      exit;
    end;
    Result:=(Len=0) or ReadProcessMemory(hProcess, RemPtr,
                                        CurPtr, Len, Cardinal(nil^));
    VirtualFreeEx(hProcess, RemPtr, 0, MEM_RELEASE);
  end;
end;

function RSFreeRemoteCopyID(CurPtr, RemPtr:pointer;
                             Len, ProcessID, Mapping:DWord):boolean;
var Pr:DWord;
begin
  if OSVersion.dwPlatformId <> VER_PLATFORM_WIN32_WINDOWS then
    if ProcessID=0 then Result:=false
    else begin
      Pr:=OpenProcess(PROCESS_VM_OPERATION or PROCESS_VM_READ, false,
         ProcessID);
      Result:=RSFreeRemoteCopy(CurPtr, RemPtr, Len, Pr, Mapping);
      if Pr<>0 then CloseHandle(Pr);
    end
  else Result:=RSFreeRemoteCopy(CurPtr, RemPtr, Len, 0, Mapping);
end;

function RSFreeRemoteCopyWnd(CurPtr, RemPtr:pointer;
                          Len:DWord; wnd:hWnd; Mapping:DWord):boolean;
var pID, Pr:DWord;
begin
  if OSVersion.dwPlatformId <> VER_PLATFORM_WIN32_WINDOWS then
  begin
    GetWindowThreadProcessId(wnd, pID);
    if pID=0 then Result:=false
    else begin
      Pr:=OpenProcess(PROCESS_VM_OPERATION or PROCESS_VM_READ,
                       false, pID);
      Result:=RSFreeRemoteCopy(CurPtr, RemPtr, Len, Pr, Mapping);
      if Pr<>0 then CloseHandle(Pr);
    end
  end else Result:=RSFreeRemoteCopy(CurPtr, RemPtr, Len, 0, Mapping);
end;

{------------------------- SendDataMessage ---------------------------}

type
  TCallback=procedure(hwnd:HWND; uMsg, dwData:DWord; lResult:LRESULT);
  TSendDetails=record
    Process:DWord;
    wMap:DWord;
    wParam:pointer;
    wPtr:pointer;
    wLen:DWord;
    lMap:DWord;
    lParam:pointer;
    lPtr:pointer;
    lLen:DWord;
    Callback:Pointer;
    CallData:DWord;
  end;
  PSendDetails=^TSendDetails;

function PrepareDataMessage(var SD:TSendDetails; hWnd:HWnd; var wParam:WParam;
           var lParam:LParam; wDataLength:DWord;
           lDataLength:DWord; wReadOnly:boolean;
           lReadOnly:boolean):boolean;
begin
  Result:=false;
  if OSVersion.dwPlatformId<>VER_PLATFORM_WIN32_WINDOWS then
  begin
    SD.Process:=TRSWnd(hWnd).OpenProcess(PROCESS_VM_OPERATION or
                        PROCESS_VM_READ or PROCESS_VM_WRITE, false);
    if SD.Process=0 then exit;
  end else SD.Process:=0; // For compiler

  SD.wParam:=pointer(wParam);
  if wReadOnly then SD.wLen:=0
  else SD.wLen:=wDataLength;
  if wDataLength=0 then SD.wPtr:=nil
  else begin
    if not RSCreateRemoteCopy(pointer(wParam),SD.wPtr,
                              wDataLength, SD.Process, SD.wMap)
    then exit;
    wParam:=DWord(SD.wPtr);
  end;

  SD.lParam:=pointer(lParam);
  if lReadOnly then SD.lLen:=0
  else SD.lLen:=lDataLength;

  if lDataLength=0 then SD.lPtr:=nil
  else begin
    if not RSCreateRemoteCopy(pointer(lParam),SD.lPtr,
          lDataLength, SD.Process, SD.lMap) and (wDataLength<>0) then
    begin
      RSFreeRemoteCopy(SD.wParam, SD.wPtr, 0, SD.Process, SD.wMap);
      exit;
    end;
    lParam:=DWord(SD.lPtr);
  end;

  SD.Callback:=nil;
  Result:=true;
end;

function FreeDataMessage(var SD:TSendDetails):boolean;
begin
  with SD do
  begin
    if wPtr<>nil then
      Result:=RSFreeRemoteCopy(wParam, wPtr, wLen, Process, wMap)
    else Result:=true;
    if lPtr<>nil then
      Result:=RSFreeRemoteCopy(lParam, lPtr, lLen, Process, lMap)
                                                         and Result;
    if Process<>0 then CloseHandle(Process);
  end;
end;

procedure FreeDataCallback(hwnd:HWND; uMsg, dwData:DWord;
                                            lResult:LRESULT); stdcall;
var SD:PSendDetails;
begin
  SD:=Pointer(dwData);
  FreeDataMessage(SD^);
  if SD^.Callback<>nil then
    TCallback(SD^.Callback)(hwnd, uMsg, SD^.CallData, lResult);
  Dispose(SD);
end;

function RSSendDataMessage(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; var lpdwResult:DWord; wDataLength:DWord=0;
           lDataLength:DWord=0; wReadOnly:boolean=false;
           lReadOnly:boolean=false):boolean;
var SD:TSendDetails;
begin
  Result:=PrepareDataMessage(SD, hwnd, wParam, lParam, wDataLength,
                                 lDataLength, wReadOnly, lReadOnly);
  if not Result then exit;
  lpdwResult:=SendMessage(hWnd, Msg, wParam, lParam);
  Result:=FreeDataMessage(SD);
end;

function RSSendDataMessageTimeout(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; fuFlags,uTimeout:DWord; var lpdwResult:DWord;
           wDataLength:DWord=0; lDataLength:DWord=0;
           wReadOnly:boolean=false; lReadOnly:boolean=false):boolean;
var SD:PSendDetails;
begin
  New(SD);
  Result:=PrepareDataMessage(SD^,hwnd,wParam,lParam,wDataLength,
                                 lDataLength,wReadOnly,lReadOnly);
  if not Result then
  begin
    lpdwResult:=0;
    Dispose(SD);
    exit;
  end;
  Result:=SendMessageTimeout(hWnd, Msg, wParam, lParam, fuFlags,
                                             uTimeout, lpdwResult)<>0;
  if Result then
  begin
    Result:=FreeDataMessage(SD^);
    Dispose(SD);
  end else
  begin
    SD.wLen:=0;
    SD.lLen:=0;
    if not SendMessageCallback(hWnd, WM_NULL, 0, 0,
            @FreeDataCallback, DWord(SD)) then
    begin
      FreeDataMessage(SD^);
      Dispose(SD);
    end;
  end;
end;

function RSSendDataMessageCallback(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; lpCallBack:Pointer; dwData:DWord;
           wDataLength:DWord=0; lDataLength:DWord=0;
           wReadOnly:boolean=true; lReadOnly:boolean=true):boolean;
var SD:PSendDetails;
begin
  New(SD);
  Result:=PrepareDataMessage(SD^,hwnd,wParam,lParam,wDataLength,
                                 lDataLength,wReadOnly,lReadOnly);
  if not Result then
  begin
    Dispose(SD);
    exit;
  end;
  SD^.Callback:=lpCallBack;
  SD^.CallData:=dwData;
  Result:=SendMessageCallback(hWnd, Msg, wParam, lParam,
                                 @FreeDataCallback, DWord(SD));
  if not Result then
  begin
    SD.wLen:=0;
    SD.lLen:=0;
    FreeDataMessage(SD^);
    Dispose(SD);
  end;
end;

function RSPostDataMessage(hWnd:HWnd; Msg:DWord; wParam:WParam;
           lParam:LParam; wDataLength:DWord=0;
           lDataLength:DWord=0; wReadOnly:boolean=true;
           lReadOnly:boolean=true):boolean;
begin
  Result:=RSSendDataMessageCallback(hWnd, Msg, wParam, lParam, nil, 0,
            wDataLength, lDataLength, wReadOnly, lReadOnly);
end;

function RSRunWait(Command:string; Dir:string; Timeout:DWord;
           showCmd:Word):boolean;
var
  SI: TStartupInfo; PI: TProcessInformation;
  i:integer;
begin
  FillChar(SI, SizeOf(SI), 0);
  FillChar(PI, SizeOf(PI), 0);
  SI.cb := SizeOf(SI);
  SI.dwFlags:=STARTF_USESHOWWINDOW;
  SI.wShowWindow:=showCmd;
  if not CreateProcess(nil, ptr(Command), nil, nil, False, 0, nil, ptr(Dir), SI, PI) then
    RSRaiseLastOSError;
  CloseHandle(PI.hThread);
  try
    i:= WaitForSingleObject(pi.hProcess, Timeout);
    Result:= i=WAIT_OBJECT_0;
    if not Result and (i<>WAIT_TIMEOUT) then  RSRaiseLastOSError;
  finally
    CloseHandle(pi.hProcess);
  end;
end;

procedure RSShowException;
begin
  ShowException(ExceptObject, ExceptAddr);
end;

 // Usage: AssertErrorProc:=RSAssertDisable
procedure RSAssertDisable(const Message, FileName: string;
    LineNumber: Integer; ErrorAddr: Pointer);
begin
end;

 // Copied from SysUtils
procedure RaiseAssertException(const E: Exception; const ErrorAddr, ErrorStack: Pointer);
asm
        MOV     ESP,ECX
        MOV     [ESP],EDX
        MOV     EBP,[EBP]
        JMP     System.@RaiseExcept
end;

function CreateAssertException(const Message, Filename: string;
  LineNumber: Integer): Exception;
var
  S: string;
begin
  if Message <> '' then S := Message else S := SAssertionFailed;
  Result := EAssertionFailed.CreateFmt(SAssertError,
    [S, ExtractFileName(FileName), LineNumber]);
end;

 // Usage: AssertErrorProc:=RSAssertErrorHandler
 // Based on SysUtils.AssertErrorHandler
procedure RSAssertErrorHandler(const Message, FileName: string;
    LineNumber: Integer; ErrorAddr: Pointer);
var
  E: Exception;
begin
  E := CreateAssertException(Message, Filename, LineNumber);
  RaiseAssertException(E, ErrorAddr, PChar(@ErrorAddr)+4);
end;

function MethodsList(EBP:pointer; FuncSkip:integer):string;
const
  CallInfo=
    'EBP = %p    Return address: %p'#13#10;
  Bug=
    '...'#13#10;
var p,p1:PPtr;
begin
  p:=EBP;
  p1:=p;
  inc(p1);
  try
    while (p<>nil) and (p^<>p) do
    begin
      if FuncSkip<=0 then
        Result:=Result+Format(CallInfo, [p, p1^])
      else
        dec(FuncSkip);
      p:=p^;
      p1:=p;
      inc(p1);
    end;
  except
    Result:=Result+Bug; // К сожалению, нередкая ситуация.
  end;
end;

function StackTrace(EBP:pointer; Lim:integer):string;
const
  CallInfo=
    'Call: EBP=%p  RetAddr=%p';
begin

end;

function Registers(Context:PContext):string;
begin
end;

function RSHandleException(FuncSkip:integer=0; TraceLimit:integer=0; EAddr:pointer=nil; EObj:TObject=nil):string;
const
  TextShort=
    'Exception %s in module %s at %p.'#13#10+
    '%s.';
  TextMain=
     TextShort+#13#10+
        #13#10+
    'Absolute address: %p  Allocation base: %p'#13#10+
    'Module: %s  Base address: %p'#13#10;
  TextProc=
        #13#10+
        #13#10+
    'Methods calls:'#13#10+
        #13#10;
  TextStack=
        #13#10+
        #13#10+
    'Stack trace:'#13#10+
        #13#10;

  function ConvertAddr(Address: Pointer): Pointer;
  asm
    test eax, eax // Always convert nil to nil
    je @exit
    sub eax, $1000 // offset from code start; code start set by linker to $1000
  @exit:
  end;

var
  ModuleName, ModulePath, EText, EName:string;
  Temp:array[0..MAX_PATH] of Char;
  Info:TMemoryBasicInformation;
  ConvertedAddress:Pointer; p, ModuleBase:pointer;
begin
  if EObj=nil then
  begin
    EObj:=ExceptObject;
    EAddr:=ExceptAddr;
  end;
  //if TraceLimit<=0 then TraceLimit:=MaxInt;
  if VirtualQuery(EAddr, Info, sizeof(Info))=0 then
  begin

  end else
  begin
    if (Info.State <> MEM_COMMIT) or
      (GetModuleFilename(THandle(Info.AllocationBase), Temp, SizeOf(Temp)) = 0)
      then
    begin
      ModuleBase:=ptr(HInstance);
      GetModuleFileName(HInstance, Temp, SizeOf(Temp));
      ConvertedAddress := ConvertAddr(EAddr);
    end else
    begin
      ModuleBase:=Info.AllocationBase;
      int(ConvertedAddress):=int(EAddr)-int(ModuleBase);
    end;
    ModulePath:=Temp;
    ModuleName:=ExtractFileName(ModulePath);
    if EObj<>nil then
    begin
      EName:=EObj.ClassName;
      if EObj is Exception then
        EText:=Exception(EObj).Message;
    end;
    Result:=Format(TextMain, [EName, ModuleName, ConvertedAddress, EText,
                    EAddr, Info.AllocationBase, ModulePath, ModuleBase]);

    asm
      mov p, ebp
    end;

    Result:= Result + TextProc + MethodsList(p, FuncSkip);
    //Result:=Result+TextStack+StackTrace(p,TraceLimit);
  end;
end;

function RSMessageBox(hWnd:hwnd; Text, Caption:string; uType:DWord=0):int;
begin
  Result:=MessageBox(hWnd, ptr(Text), ptr(Caption), uType);
end;

{-------------------------------------------------------}

initialization
  OSVersion.dwOSVersionInfoSize:=SizeOf(OSVersion);
  GetVersionEx(OSVersion);

finalization
  if @DelaysOnClose<>nil then
    DelaysOnClose;
end.
