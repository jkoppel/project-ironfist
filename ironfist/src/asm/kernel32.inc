; --------------------------------------------------------------------------------------------------
;                          kernel32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF KERNEL32_INC
KERNEL32_INC equ <1>

ActivateActCtx PROTO STDCALL :DWORD,:DWORD

AddAtomA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  AddAtom equ <AddAtomA>
ENDIF

AddAtomW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  AddAtom equ <AddAtomW>
ENDIF

AddLocalAlternateComputerNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  AddLocalAlternateComputerName equ <AddLocalAlternateComputerNameA>
ENDIF

AddLocalAlternateComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  AddLocalAlternateComputerName equ <AddLocalAlternateComputerNameW>
ENDIF

AddRefActCtx PROTO STDCALL :DWORD
AddVectoredExceptionHandler PROTO STDCALL :DWORD,:DWORD
AllocConsole PROTO STDCALL
AllocateUserPhysicalPages PROTO STDCALL :DWORD,:DWORD,:DWORD
AreFileApisANSI PROTO STDCALL
AssignProcessToJobObject PROTO STDCALL :DWORD,:DWORD
AttachConsole PROTO STDCALL :DWORD
BackupRead PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BackupSeek PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BackupWrite PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
Beep PROTO STDCALL :DWORD,:DWORD

BeginUpdateResourceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  BeginUpdateResource equ <BeginUpdateResourceA>
ENDIF

BeginUpdateResourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BeginUpdateResource equ <BeginUpdateResourceW>
ENDIF

BindIoCompletionCallback PROTO STDCALL :DWORD,:DWORD,:DWORD

BuildCommDCBA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  BuildCommDCB equ <BuildCommDCBA>
ENDIF

BuildCommDCBAndTimeoutsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  BuildCommDCBAndTimeouts equ <BuildCommDCBAndTimeoutsA>
ENDIF

BuildCommDCBAndTimeoutsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  BuildCommDCBAndTimeouts equ <BuildCommDCBAndTimeoutsW>
ENDIF

BuildCommDCBW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BuildCommDCB equ <BuildCommDCBW>
ENDIF

CallNamedPipeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CallNamedPipe equ <CallNamedPipeA>
ENDIF

CallNamedPipeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CallNamedPipe equ <CallNamedPipeW>
ENDIF

CancelDeviceWakeupRequest PROTO STDCALL :DWORD
CancelIo PROTO STDCALL :DWORD
CancelTimerQueueTimer PROTO STDCALL :DWORD,:DWORD
CancelWaitableTimer PROTO STDCALL :DWORD
ChangeTimerQueueTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CheckNameLegalDOS8Dot3A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CheckNameLegalDOS8Dot3 equ <CheckNameLegalDOS8Dot3A>
ENDIF

CheckNameLegalDOS8Dot3W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CheckNameLegalDOS8Dot3 equ <CheckNameLegalDOS8Dot3W>
ENDIF

CheckRemoteDebuggerPresent PROTO STDCALL :DWORD,:DWORD
ClearCommBreak PROTO STDCALL :DWORD
ClearCommError PROTO STDCALL :DWORD,:DWORD,:DWORD
CloseHandle PROTO STDCALL :DWORD

CommConfigDialogA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CommConfigDialog equ <CommConfigDialogA>
ENDIF

CommConfigDialogW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CommConfigDialog equ <CommConfigDialogW>
ENDIF

CompareFileTime PROTO STDCALL :DWORD,:DWORD

CompareStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CompareString equ <CompareStringA>
ENDIF

CompareStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CompareString equ <CompareStringW>
ENDIF

ConnectNamedPipe PROTO STDCALL :DWORD,:DWORD
ContinueDebugEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
ConvertDefaultLocale PROTO STDCALL :DWORD
ConvertFiberToThread PROTO STDCALL
ConvertThreadToFiber PROTO STDCALL :DWORD

CopyFileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CopyFile equ <CopyFileA>
ENDIF

CopyFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CopyFileEx equ <CopyFileExA>
ENDIF

CopyFileExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CopyFileEx equ <CopyFileExW>
ENDIF

CopyFileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CopyFile equ <CopyFileW>
ENDIF

CreateActCtxA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CreateActCtx equ <CreateActCtxA>
ENDIF

CreateActCtxW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CreateActCtx equ <CreateActCtxW>
ENDIF

CreateConsoleScreenBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CreateDirectory equ <CreateDirectoryA>
ENDIF

CreateDirectoryExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateDirectoryEx equ <CreateDirectoryExA>
ENDIF

CreateDirectoryExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateDirectoryEx equ <CreateDirectoryExW>
ENDIF

CreateDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CreateDirectory equ <CreateDirectoryW>
ENDIF

CreateEventA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateEvent equ <CreateEventA>
ENDIF

CreateEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateEvent equ <CreateEventW>
ENDIF

CreateFiber PROTO STDCALL :DWORD,:DWORD,:DWORD
CreateFiberEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

CreateFileMappingA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFileMapping equ <CreateFileMappingA>
ENDIF

CreateFileMappingW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateFileMapping equ <CreateFileMappingW>
ENDIF

CreateFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateFile equ <CreateFileW>
ENDIF

CreateHardLinkA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateHardLink equ <CreateHardLinkA>
ENDIF

CreateHardLinkW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateHardLink equ <CreateHardLinkW>
ENDIF

CreateIoCompletionPort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CreateJobObjectA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CreateJobObject equ <CreateJobObjectA>
ENDIF

CreateJobObjectW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CreateJobObject equ <CreateJobObjectW>
ENDIF

CreateJobSet PROTO STDCALL :DWORD,:DWORD,:DWORD

CreateMailslotA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateMailslot equ <CreateMailslotA>
ENDIF

CreateMailslotW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateMailslot equ <CreateMailslotW>
ENDIF

CreateMemoryResourceNotification PROTO STDCALL :DWORD

CreateMutexA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateMutex equ <CreateMutexA>
ENDIF

CreateMutexW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateMutex equ <CreateMutexW>
ENDIF

CreateNamedPipeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateNamedPipe equ <CreateNamedPipeA>
ENDIF

CreateNamedPipeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateNamedPipe equ <CreateNamedPipeW>
ENDIF

CreatePipe PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CreateProcessA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateProcess equ <CreateProcessA>
ENDIF

CreateProcessInternalWSecure PROTO STDCALL

CreateProcessW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateProcess equ <CreateProcessW>
ENDIF

CreateRemoteThread PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateSemaphoreA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateSemaphore equ <CreateSemaphoreA>
ENDIF

CreateSemaphoreW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateSemaphore equ <CreateSemaphoreW>
ENDIF

CreateTapePartition PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CreateThread PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateTimerQueue PROTO STDCALL
CreateTimerQueueTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateToolhelp32Snapshot PROTO STDCALL :DWORD,:DWORD

CreateWaitableTimerA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateWaitableTimer equ <CreateWaitableTimerA>
ENDIF

CreateWaitableTimerW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateWaitableTimer equ <CreateWaitableTimerW>
ENDIF

DeactivateActCtx PROTO STDCALL :DWORD,:DWORD
DebugActiveProcess PROTO STDCALL :DWORD
DebugActiveProcessStop PROTO STDCALL :DWORD
DebugBreak PROTO STDCALL
DebugBreakProcess PROTO STDCALL :DWORD
DebugSetProcessKillOnExit PROTO STDCALL :DWORD
DecodePointer PROTO STDCALL :DWORD
DecodeSystemPointer PROTO STDCALL :DWORD

DefineDosDeviceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DefineDosDevice equ <DefineDosDeviceA>
ENDIF

DefineDosDeviceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DefineDosDevice equ <DefineDosDeviceW>
ENDIF

DeleteAtom PROTO STDCALL :DWORD
DeleteCriticalSection PROTO STDCALL :DWORD
DeleteFiber PROTO STDCALL :DWORD

DeleteFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteFile equ <DeleteFileA>
ENDIF

DeleteFileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeleteFile equ <DeleteFileW>
ENDIF

DeleteTimerQueue PROTO STDCALL :DWORD
DeleteTimerQueueEx PROTO STDCALL :DWORD,:DWORD
DeleteTimerQueueTimer PROTO STDCALL :DWORD,:DWORD,:DWORD

DeleteVolumeMountPointA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteVolumeMountPoint equ <DeleteVolumeMountPointA>
ENDIF

DeleteVolumeMountPointW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeleteVolumeMountPoint equ <DeleteVolumeMountPointW>
ENDIF

DeviceIoControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DisableThreadLibraryCalls PROTO STDCALL :DWORD
DisconnectNamedPipe PROTO STDCALL :DWORD

DnsHostnameToComputerNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DnsHostnameToComputerName equ <DnsHostnameToComputerNameA>
ENDIF

DnsHostnameToComputerNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DnsHostnameToComputerName equ <DnsHostnameToComputerNameW>
ENDIF

DosDateTimeToFileTime PROTO STDCALL :DWORD,:DWORD,:DWORD
DuplicateHandle PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EncodePointer PROTO STDCALL :DWORD
EncodeSystemPointer PROTO STDCALL :DWORD

EndUpdateResourceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EndUpdateResource equ <EndUpdateResourceA>
ENDIF

EndUpdateResourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  EndUpdateResource equ <EndUpdateResourceW>
ENDIF

EnterCriticalSection PROTO STDCALL :DWORD

EnumCalendarInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumCalendarInfo equ <EnumCalendarInfoA>
ENDIF

EnumCalendarInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumCalendarInfoEx equ <EnumCalendarInfoExA>
ENDIF

EnumCalendarInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumCalendarInfoEx equ <EnumCalendarInfoExW>
ENDIF

EnumCalendarInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumCalendarInfo equ <EnumCalendarInfoW>
ENDIF

EnumDateFormatsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumDateFormats equ <EnumDateFormatsA>
ENDIF

EnumDateFormatsExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumDateFormatsEx equ <EnumDateFormatsExA>
ENDIF

EnumDateFormatsExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumDateFormatsEx equ <EnumDateFormatsExW>
ENDIF

EnumDateFormatsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumDateFormats equ <EnumDateFormatsW>
ENDIF

EnumLanguageGroupLocalesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumLanguageGroupLocales equ <EnumLanguageGroupLocalesA>
ENDIF

EnumLanguageGroupLocalesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumLanguageGroupLocales equ <EnumLanguageGroupLocalesW>
ENDIF

EnumResourceLanguagesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumResourceLanguages equ <EnumResourceLanguagesA>
ENDIF

EnumResourceLanguagesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumResourceLanguages equ <EnumResourceLanguagesW>
ENDIF

EnumResourceNamesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumResourceNames equ <EnumResourceNamesA>
ENDIF

EnumResourceNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumResourceNames equ <EnumResourceNamesW>
ENDIF

EnumResourceTypesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumResourceTypes equ <EnumResourceTypesA>
ENDIF

EnumResourceTypesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumResourceTypes equ <EnumResourceTypesW>
ENDIF

EnumSystemCodePagesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EnumSystemCodePages equ <EnumSystemCodePagesA>
ENDIF

EnumSystemCodePagesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  EnumSystemCodePages equ <EnumSystemCodePagesW>
ENDIF

EnumSystemGeoID PROTO STDCALL :DWORD,:DWORD,:DWORD

EnumSystemLanguageGroupsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumSystemLanguageGroups equ <EnumSystemLanguageGroupsA>
ENDIF

EnumSystemLanguageGroupsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumSystemLanguageGroups equ <EnumSystemLanguageGroupsW>
ENDIF

EnumSystemLocalesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EnumSystemLocales equ <EnumSystemLocalesA>
ENDIF

EnumSystemLocalesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  EnumSystemLocales equ <EnumSystemLocalesW>
ENDIF

EnumTimeFormatsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumTimeFormats equ <EnumTimeFormatsA>
ENDIF

EnumTimeFormatsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumTimeFormats equ <EnumTimeFormatsW>
ENDIF

EnumUILanguagesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumUILanguages equ <EnumUILanguagesA>
ENDIF

EnumUILanguagesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumUILanguages equ <EnumUILanguagesW>
ENDIF

EnumerateLocalComputerNamesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumerateLocalComputerNames equ <EnumerateLocalComputerNamesA>
ENDIF

EnumerateLocalComputerNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumerateLocalComputerNames equ <EnumerateLocalComputerNamesW>
ENDIF

EraseTape PROTO STDCALL :DWORD,:DWORD,:DWORD
EscapeCommFunction PROTO STDCALL :DWORD,:DWORD
ExitProcess PROTO STDCALL :DWORD
ExitThread PROTO STDCALL :DWORD

ExpandEnvironmentStringsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ExpandEnvironmentStrings equ <ExpandEnvironmentStringsA>
ENDIF

ExpandEnvironmentStringsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ExpandEnvironmentStrings equ <ExpandEnvironmentStringsW>
ENDIF

FatalAppExitA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FatalAppExit equ <FatalAppExitA>
ENDIF

FatalAppExitW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FatalAppExit equ <FatalAppExitW>
ENDIF

FatalExit PROTO STDCALL :DWORD
FileTimeToDosDateTime PROTO STDCALL :DWORD,:DWORD,:DWORD
FileTimeToLocalFileTime PROTO STDCALL :DWORD,:DWORD
FileTimeToSystemTime PROTO STDCALL :DWORD,:DWORD
FillConsoleOutputAttribute PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

FillConsoleOutputCharacterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FillConsoleOutputCharacter equ <FillConsoleOutputCharacterA>
ENDIF

FillConsoleOutputCharacterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FillConsoleOutputCharacter equ <FillConsoleOutputCharacterW>
ENDIF

FindActCtxSectionGuid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

FindActCtxSectionStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindActCtxSectionString equ <FindActCtxSectionStringA>
ENDIF

FindActCtxSectionStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindActCtxSectionString equ <FindActCtxSectionStringW>
ENDIF

FindAtomA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  FindAtom equ <FindAtomA>
ENDIF

FindAtomW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  FindAtom equ <FindAtomW>
ENDIF

FindClose PROTO STDCALL :DWORD
FindCloseChangeNotification PROTO STDCALL :DWORD

FindFirstChangeNotificationA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstChangeNotification equ <FindFirstChangeNotificationA>
ENDIF

FindFirstChangeNotificationW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstChangeNotification equ <FindFirstChangeNotificationW>
ENDIF

FindFirstFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstFile equ <FindFirstFileA>
ENDIF

FindFirstFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstFileEx equ <FindFirstFileExA>
ENDIF

FindFirstFileExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstFileEx equ <FindFirstFileExW>
ENDIF

FindFirstFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstFile equ <FindFirstFileW>
ENDIF

FindFirstVolumeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstVolume equ <FindFirstVolumeA>
ENDIF

FindFirstVolumeMountPointA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstVolumeMountPoint equ <FindFirstVolumeMountPointA>
ENDIF

FindFirstVolumeMountPointW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstVolumeMountPoint equ <FindFirstVolumeMountPointW>
ENDIF

FindFirstVolumeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstVolume equ <FindFirstVolumeW>
ENDIF

FindNextChangeNotification PROTO STDCALL :DWORD

FindNextFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FindNextFile equ <FindNextFileA>
ENDIF

FindNextFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FindNextFile equ <FindNextFileW>
ENDIF

FindNextVolumeA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindNextVolume equ <FindNextVolumeA>
ENDIF

FindNextVolumeMountPointA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindNextVolumeMountPoint equ <FindNextVolumeMountPointA>
ENDIF

FindNextVolumeMountPointW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindNextVolumeMountPoint equ <FindNextVolumeMountPointW>
ENDIF

FindNextVolumeW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindNextVolume equ <FindNextVolumeW>
ENDIF

FindResourceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindResource equ <FindResourceA>
ENDIF

FindResourceExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindResourceEx equ <FindResourceExA>
ENDIF

FindResourceExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindResourceEx equ <FindResourceExW>
ENDIF

FindResourceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindResource equ <FindResourceW>
ENDIF

FindVolumeClose PROTO STDCALL :DWORD
FindVolumeMountPointClose PROTO STDCALL :DWORD
FlushConsoleInputBuffer PROTO STDCALL :DWORD
FlushFileBuffers PROTO STDCALL :DWORD
FlushInstructionCache PROTO STDCALL :DWORD,:DWORD,:DWORD
FlushViewOfFile PROTO STDCALL :DWORD,:DWORD

FoldStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FoldString equ <FoldStringA>
ENDIF

FoldStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FoldString equ <FoldStringW>
ENDIF

FormatMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FormatMessage equ <FormatMessageA>
ENDIF

FormatMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FormatMessage equ <FormatMessageW>
ENDIF

FreeConsole PROTO STDCALL

FreeEnvironmentStringsA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  FreeEnvironmentStrings equ <FreeEnvironmentStringsA>
ENDIF

FreeEnvironmentStringsW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  FreeEnvironmentStrings equ <FreeEnvironmentStringsW>
ENDIF

FreeLibrary PROTO STDCALL :DWORD
FreeLibraryAndExitThread PROTO STDCALL :DWORD,:DWORD
FreeResource PROTO STDCALL :DWORD
FreeUserPhysicalPages PROTO STDCALL :DWORD,:DWORD,:DWORD
GenerateConsoleCtrlEvent PROTO STDCALL :DWORD,:DWORD
GetACP PROTO STDCALL

GetAtomNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetAtomName equ <GetAtomNameA>
ENDIF

GetAtomNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetAtomName equ <GetAtomNameW>
ENDIF


GetBinaryTypeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetBinaryType equ <GetBinaryTypeA>
ENDIF

GetBinaryTypeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetBinaryType equ <GetBinaryTypeW>
ENDIF

GetCPInfo PROTO STDCALL :DWORD,:DWORD

GetCPInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetCPInfoEx equ <GetCPInfoExA>
ENDIF

GetCPInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetCPInfoEx equ <GetCPInfoExW>
ENDIF

GetCalendarInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetCalendarInfo equ <GetCalendarInfoA>
ENDIF

GetCalendarInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetCalendarInfo equ <GetCalendarInfoW>
ENDIF

GetCommConfig PROTO STDCALL :DWORD,:DWORD,:DWORD
GetCommMask PROTO STDCALL :DWORD,:DWORD
GetCommModemStatus PROTO STDCALL :DWORD,:DWORD
GetCommProperties PROTO STDCALL :DWORD,:DWORD
GetCommState PROTO STDCALL :DWORD,:DWORD
GetCommTimeouts PROTO STDCALL :DWORD,:DWORD

GetCommandLineA PROTO STDCALL
IFNDEF __UNICODE__
  GetCommandLine equ <GetCommandLineA>
ENDIF

GetCommandLineW PROTO STDCALL
IFDEF __UNICODE__
  GetCommandLine equ <GetCommandLineW>
ENDIF

GetCompressedFileSizeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetCompressedFileSize equ <GetCompressedFileSizeA>
ENDIF

GetCompressedFileSizeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetCompressedFileSize equ <GetCompressedFileSizeW>
ENDIF

GetComputerNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetComputerName equ <GetComputerNameA>
ENDIF

GetComputerNameExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetComputerNameEx equ <GetComputerNameExA>
ENDIF

GetComputerNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerNameEx equ <GetComputerNameExW>
ENDIF

GetComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerName equ <GetComputerNameW>
ENDIF

GetConsoleCP PROTO STDCALL
GetConsoleCursorInfo PROTO STDCALL :DWORD,:DWORD
GetConsoleDisplayMode PROTO STDCALL :DWORD
GetConsoleFontSize PROTO STDCALL :DWORD,:DWORD
GetConsoleMode PROTO STDCALL :DWORD,:DWORD
GetConsoleOutputCP PROTO STDCALL
GetConsoleProcessList PROTO STDCALL :DWORD,:DWORD
GetConsoleScreenBufferInfo PROTO STDCALL :DWORD,:DWORD
GetConsoleSelectionInfo PROTO STDCALL :DWORD

GetConsoleTitleA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetConsoleTitle equ <GetConsoleTitleA>
ENDIF

GetConsoleTitleW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetConsoleTitle equ <GetConsoleTitleW>
ENDIF

GetConsoleWindow PROTO STDCALL

GetCurrencyFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetCurrencyFormat equ <GetCurrencyFormatA>
ENDIF

GetCurrencyFormatW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetCurrencyFormat equ <GetCurrencyFormatW>
ENDIF

GetCurrentActCtx PROTO STDCALL :DWORD
GetCurrentConsoleFont PROTO STDCALL :DWORD,:DWORD,:DWORD

GetCurrentDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetCurrentDirectory equ <GetCurrentDirectoryA>
ENDIF

GetCurrentDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetCurrentDirectory equ <GetCurrentDirectoryW>
ENDIF

GetCurrentProcess PROTO STDCALL
GetCurrentProcessId PROTO STDCALL
GetCurrentThread PROTO STDCALL
GetCurrentThreadId PROTO STDCALL

GetDateFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDateFormat equ <GetDateFormatA>
ENDIF

GetDateFormatW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDateFormat equ <GetDateFormatW>
ENDIF

GetDefaultCommConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDefaultCommConfig equ <GetDefaultCommConfigA>
ENDIF

GetDefaultCommConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDefaultCommConfig equ <GetDefaultCommConfigW>
ENDIF

GetDevicePowerState PROTO STDCALL :DWORD,:DWORD

GetDiskFreeSpaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDiskFreeSpace equ <GetDiskFreeSpaceA>
ENDIF

GetDiskFreeSpaceExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDiskFreeSpaceEx equ <GetDiskFreeSpaceExA>
ENDIF

GetDiskFreeSpaceExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDiskFreeSpaceEx equ <GetDiskFreeSpaceExW>
ENDIF

GetDiskFreeSpaceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDiskFreeSpace equ <GetDiskFreeSpaceW>
ENDIF

GetDllDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetDllDirectory equ <GetDllDirectoryA>
ENDIF

GetDllDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetDllDirectory equ <GetDllDirectoryW>
ENDIF

GetDriveTypeA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetDriveType equ <GetDriveTypeA>
ENDIF

GetDriveTypeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetDriveType equ <GetDriveTypeW>
ENDIF


GetEnvironmentStringsA PROTO STDCALL
IFNDEF __UNICODE__
  GetEnvironmentStrings equ <GetEnvironmentStringsA>
ENDIF

GetEnvironmentStringsW PROTO STDCALL
IFDEF __UNICODE__
  GetEnvironmentStrings equ <GetEnvironmentStringsW>
ENDIF

GetEnvironmentVariableA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetEnvironmentVariable equ <GetEnvironmentVariableA>
ENDIF

GetEnvironmentVariableW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetEnvironmentVariable equ <GetEnvironmentVariableW>
ENDIF

GetExitCodeProcess PROTO STDCALL :DWORD,:DWORD
GetExitCodeThread PROTO STDCALL :DWORD,:DWORD

GetFileAttributesA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesA>
ENDIF

GetFileAttributesExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFileAttributesEx equ <GetFileAttributesExA>
ENDIF

GetFileAttributesExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFileAttributesEx equ <GetFileAttributesExW>
ENDIF

GetFileAttributesW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesW>
ENDIF

GetFileInformationByHandle PROTO STDCALL :DWORD,:DWORD
GetFileSize PROTO STDCALL :DWORD,:DWORD
GetFileSizeEx PROTO STDCALL :DWORD,:DWORD
GetFileTime PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetFileType PROTO STDCALL :DWORD

GetFirmwareEnvironmentVariableA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFirmwareEnvironmentVariable equ <GetFirmwareEnvironmentVariableA>
ENDIF

GetFirmwareEnvironmentVariableW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFirmwareEnvironmentVariable equ <GetFirmwareEnvironmentVariableW>
ENDIF

GetFullPathNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFullPathName equ <GetFullPathNameA>
ENDIF

GetFullPathNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFullPathName equ <GetFullPathNameW>
ENDIF

GetGeoInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetGeoInfo equ <GetGeoInfoA>
ENDIF

GetGeoInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetGeoInfo equ <GetGeoInfoW>
ENDIF

GetHandleInformation PROTO STDCALL :DWORD,:DWORD
GetLargestConsoleWindowSize PROTO STDCALL :DWORD
GetLastError PROTO STDCALL
GetLocalTime PROTO STDCALL :DWORD

GetLocaleInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetLocaleInfo equ <GetLocaleInfoA>
ENDIF

GetLocaleInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetLocaleInfo equ <GetLocaleInfoW>
ENDIF

GetLogicalDriveStringsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetLogicalDriveStrings equ <GetLogicalDriveStringsA>
ENDIF

GetLogicalDriveStringsW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetLogicalDriveStrings equ <GetLogicalDriveStringsW>
ENDIF

GetLogicalDrives PROTO STDCALL

GetLongPathNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetLongPathName equ <GetLongPathNameA>
ENDIF

GetLongPathNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetLongPathName equ <GetLongPathNameW>
ENDIF

GetMailslotInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetModuleFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleFileName equ <GetModuleFileNameA>
ENDIF

GetModuleFileNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetModuleFileName equ <GetModuleFileNameW>
ENDIF

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetModuleHandleExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleHandleEx equ <GetModuleHandleExA>
ENDIF

GetModuleHandleExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetModuleHandleEx equ <GetModuleHandleExW>
ENDIF

GetModuleHandleW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleW>
ENDIF

GetNamedPipeHandleStateA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNamedPipeHandleState equ <GetNamedPipeHandleStateA>
ENDIF

GetNamedPipeHandleStateW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNamedPipeHandleState equ <GetNamedPipeHandleStateW>
ENDIF

GetNamedPipeInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNativeSystemInfo PROTO STDCALL :DWORD
GetNumaAvailableMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
GetNumaAvailableMemoryNode PROTO STDCALL :DWORD,:DWORD
GetNumaHighestNodeNumber PROTO STDCALL :DWORD
GetNumaNodeProcessorMask PROTO STDCALL :DWORD,:DWORD
GetNumaProcessorMap PROTO STDCALL :DWORD,:DWORD,:DWORD
GetNumaProcessorNode PROTO STDCALL :DWORD,:DWORD

GetNumberFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNumberFormat equ <GetNumberFormatA>
ENDIF

GetNumberFormatW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNumberFormat equ <GetNumberFormatW>
ENDIF

GetNumberOfConsoleInputEvents PROTO STDCALL :DWORD,:DWORD
GetNumberOfConsoleMouseButtons PROTO STDCALL :DWORD
GetOEMCP PROTO STDCALL
GetOverlappedResult PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetPriorityClass PROTO STDCALL :DWORD

GetPrivateProfileIntA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrivateProfileInt equ <GetPrivateProfileIntA>
ENDIF

GetPrivateProfileIntW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrivateProfileInt equ <GetPrivateProfileIntW>
ENDIF

GetPrivateProfileSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrivateProfileSection equ <GetPrivateProfileSectionA>
ENDIF

GetPrivateProfileSectionNamesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrivateProfileSectionNames equ <GetPrivateProfileSectionNamesA>
ENDIF

GetPrivateProfileSectionNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrivateProfileSectionNames equ <GetPrivateProfileSectionNamesW>
ENDIF

GetPrivateProfileSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrivateProfileSection equ <GetPrivateProfileSectionW>
ENDIF

GetPrivateProfileStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrivateProfileString equ <GetPrivateProfileStringA>
ENDIF

GetPrivateProfileStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrivateProfileString equ <GetPrivateProfileStringW>
ENDIF

GetPrivateProfileStructA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrivateProfileStruct equ <GetPrivateProfileStructA>
ENDIF

GetPrivateProfileStructW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrivateProfileStruct equ <GetPrivateProfileStructW>
ENDIF

GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetProcessAffinityMask PROTO STDCALL :DWORD,:DWORD,:DWORD
GetProcessHandleCount PROTO STDCALL :DWORD,:DWORD
GetProcessHeap PROTO STDCALL
GetProcessHeaps PROTO STDCALL :DWORD,:DWORD
GetProcessId PROTO STDCALL :DWORD
GetProcessIoCounters PROTO STDCALL :DWORD,:DWORD
GetProcessPriorityBoost PROTO STDCALL :DWORD,:DWORD
GetProcessShutdownParameters PROTO STDCALL :DWORD,:DWORD
GetProcessTimes PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetProcessVersion PROTO STDCALL :DWORD
GetProcessWorkingSetSize PROTO STDCALL :DWORD,:DWORD,:DWORD

GetProfileIntA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetProfileInt equ <GetProfileIntA>
ENDIF

GetProfileIntW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetProfileInt equ <GetProfileIntW>
ENDIF

GetProfileSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetProfileSection equ <GetProfileSectionA>
ENDIF

GetProfileSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetProfileSection equ <GetProfileSectionW>
ENDIF

GetProfileStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetProfileString equ <GetProfileStringA>
ENDIF

GetProfileStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetProfileString equ <GetProfileStringW>
ENDIF

GetQueuedCompletionStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetShortPathNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetShortPathName equ <GetShortPathNameA>
ENDIF

GetShortPathNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetShortPathName equ <GetShortPathNameW>
ENDIF

GetStartupInfoA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetStartupInfo equ <GetStartupInfoA>
ENDIF

GetStartupInfoW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetStartupInfo equ <GetStartupInfoW>
ENDIF

GetStdHandle PROTO STDCALL :DWORD

GetStringTypeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetStringType equ <GetStringTypeA>
ENDIF

GetStringTypeExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetStringTypeEx equ <GetStringTypeExA>
ENDIF

GetStringTypeExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetStringTypeEx equ <GetStringTypeExW>
ENDIF

GetStringTypeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetStringType equ <GetStringTypeW>
ENDIF

GetSystemDefaultLCID PROTO STDCALL
GetSystemDefaultLangID PROTO STDCALL
GetSystemDefaultUILanguage PROTO STDCALL

GetSystemDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetSystemDirectory equ <GetSystemDirectoryA>
ENDIF

GetSystemDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetSystemDirectory equ <GetSystemDirectoryW>
ENDIF

GetSystemInfo PROTO STDCALL :DWORD
GetSystemPowerStatus PROTO STDCALL :DWORD
GetSystemRegistryQuota PROTO STDCALL :DWORD,:DWORD
GetSystemTime PROTO STDCALL :DWORD
GetSystemTimeAdjustment PROTO STDCALL :DWORD,:DWORD,:DWORD
GetSystemTimeAsFileTime PROTO STDCALL :DWORD
GetSystemTimes PROTO STDCALL :DWORD,:DWORD,:DWORD

GetSystemWindowsDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetSystemWindowsDirectory equ <GetSystemWindowsDirectoryA>
ENDIF

GetSystemWindowsDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetSystemWindowsDirectory equ <GetSystemWindowsDirectoryW>
ENDIF

GetSystemWow64DirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetSystemWow64Directory equ <GetSystemWow64DirectoryA>
ENDIF

GetSystemWow64DirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetSystemWow64Directory equ <GetSystemWow64DirectoryW>
ENDIF

GetTapeParameters PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetTapePosition PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetTapeStatus PROTO STDCALL :DWORD

GetTempFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempFileName equ <GetTempFileNameA>
ENDIF

GetTempFileNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetTempFileName equ <GetTempFileNameW>
ENDIF

GetTempPathA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempPath equ <GetTempPathA>
ENDIF

GetTempPathW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetTempPath equ <GetTempPathW>
ENDIF

GetThreadContext PROTO STDCALL :DWORD,:DWORD
GetThreadIOPendingFlag PROTO STDCALL :DWORD,:DWORD
GetThreadLocale PROTO STDCALL
GetThreadPriority PROTO STDCALL :DWORD
GetThreadPriorityBoost PROTO STDCALL :DWORD,:DWORD
GetThreadSelectorEntry PROTO STDCALL :DWORD,:DWORD,:DWORD
GetThreadTimes PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetTickCount PROTO STDCALL

GetTimeFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatA>
ENDIF

GetTimeFormatW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatW>
ENDIF

GetTimeZoneInformation PROTO STDCALL :DWORD
GetUserDefaultLCID PROTO STDCALL
GetUserDefaultLangID PROTO STDCALL
GetUserDefaultUILanguage PROTO STDCALL
GetUserGeoID PROTO STDCALL :DWORD
GetVersion PROTO STDCALL

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

GetVersionExW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetVersionEx equ <GetVersionExW>
ENDIF

GetVolumeInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetVolumeInformation equ <GetVolumeInformationA>
ENDIF

GetVolumeInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetVolumeInformation equ <GetVolumeInformationW>
ENDIF

GetVolumeNameForVolumeMountPointA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetVolumeNameForVolumeMountPoint equ <GetVolumeNameForVolumeMountPointA>
ENDIF

GetVolumeNameForVolumeMountPointW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetVolumeNameForVolumeMountPoint equ <GetVolumeNameForVolumeMountPointW>
ENDIF

GetVolumePathNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetVolumePathName equ <GetVolumePathNameA>
ENDIF

GetVolumePathNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetVolumePathName equ <GetVolumePathNameW>
ENDIF

GetVolumePathNamesForVolumeNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetVolumePathNamesForVolumeName equ <GetVolumePathNamesForVolumeNameA>
ENDIF

GetVolumePathNamesForVolumeNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetVolumePathNamesForVolumeName equ <GetVolumePathNamesForVolumeNameW>
ENDIF

GetWindowsDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetWindowsDirectory equ <GetWindowsDirectoryA>
ENDIF

GetWindowsDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetWindowsDirectory equ <GetWindowsDirectoryW>
ENDIF

GetWriteWatch PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GlobalAddAtomA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GlobalAddAtom equ <GlobalAddAtomA>
ENDIF

GlobalAddAtomW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GlobalAddAtom equ <GlobalAddAtomW>
ENDIF

GlobalAlloc PROTO STDCALL :DWORD,:DWORD
GlobalCompact PROTO STDCALL :DWORD
GlobalDeleteAtom PROTO STDCALL :DWORD

GlobalFindAtomA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GlobalFindAtom equ <GlobalFindAtomA>
ENDIF

GlobalFindAtomW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GlobalFindAtom equ <GlobalFindAtomW>
ENDIF

GlobalFix PROTO STDCALL :DWORD
GlobalFlags PROTO STDCALL :DWORD
GlobalFree PROTO STDCALL :DWORD

GlobalGetAtomNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GlobalGetAtomName equ <GlobalGetAtomNameA>
ENDIF

GlobalGetAtomNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GlobalGetAtomName equ <GlobalGetAtomNameW>
ENDIF

GlobalHandle PROTO STDCALL :DWORD
GlobalLock PROTO STDCALL :DWORD
GlobalMemoryStatus PROTO STDCALL :DWORD
GlobalMemoryStatusEx PROTO STDCALL :DWORD
GlobalReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
GlobalSize PROTO STDCALL :DWORD
GlobalUnWire PROTO STDCALL :DWORD
GlobalUnfix PROTO STDCALL :DWORD
GlobalUnlock PROTO STDCALL :DWORD
GlobalWire PROTO STDCALL :DWORD
Heap32First PROTO STDCALL :DWORD,:DWORD,:DWORD
Heap32ListFirst PROTO STDCALL :DWORD,:DWORD
Heap32ListNext PROTO STDCALL :DWORD,:DWORD
Heap32Next PROTO STDCALL :DWORD
HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapCompact PROTO STDCALL :DWORD,:DWORD
HeapCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapDestroy PROTO STDCALL :DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapLock PROTO STDCALL :DWORD
HeapQueryInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HeapReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HeapSetInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HeapSize PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapUnlock PROTO STDCALL :DWORD
HeapValidate PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapWalk PROTO STDCALL :DWORD,:DWORD
InitAtomTable PROTO STDCALL :DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
InitializeCriticalSectionAndSpinCount PROTO STDCALL :DWORD,:DWORD
InitializeSListHead PROTO STDCALL :DWORD
InterlockedCompareExchange PROTO STDCALL :DWORD,:DWORD,:DWORD
InterlockedDecrement PROTO STDCALL :DWORD
InterlockedExchange PROTO STDCALL :DWORD,:DWORD
InterlockedExchangeAdd PROTO STDCALL :DWORD,:DWORD
InterlockedFlushSList PROTO STDCALL :DWORD
InterlockedIncrement PROTO STDCALL :DWORD
InterlockedPopEntrySList PROTO STDCALL :DWORD
InterlockedPushEntrySList PROTO STDCALL :DWORD,:DWORD
IsBadCodePtr PROTO STDCALL :DWORD
IsBadHugeReadPtr PROTO STDCALL :DWORD,:DWORD
IsBadHugeWritePtr PROTO STDCALL :DWORD,:DWORD
IsBadReadPtr PROTO STDCALL :DWORD,:DWORD

IsBadStringPtrA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  IsBadStringPtr equ <IsBadStringPtrA>
ENDIF

IsBadStringPtrW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  IsBadStringPtr equ <IsBadStringPtrW>
ENDIF

IsBadWritePtr PROTO STDCALL :DWORD,:DWORD
IsDBCSLeadByte PROTO STDCALL :DWORD
IsDBCSLeadByteEx PROTO STDCALL :DWORD,:DWORD
IsDebuggerPresent PROTO STDCALL
IsProcessInJob PROTO STDCALL :DWORD,:DWORD,:DWORD
IsProcessorFeaturePresent PROTO STDCALL :DWORD
IsSystemResumeAutomatic PROTO STDCALL
IsValidCodePage PROTO STDCALL :DWORD
IsValidLanguageGroup PROTO STDCALL :DWORD,:DWORD
IsValidLocale PROTO STDCALL :DWORD,:DWORD
IsWow64Process PROTO STDCALL :DWORD,:DWORD

LCMapStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LCMapString equ <LCMapStringA>
ENDIF

LCMapStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LCMapString equ <LCMapStringW>
ENDIF

LeaveCriticalSection PROTO STDCALL :DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LoadLibraryExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LoadLibraryEx equ <LoadLibraryExA>
ENDIF

LoadLibraryExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LoadLibraryEx equ <LoadLibraryExW>
ENDIF

LoadLibraryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  LoadLibrary equ <LoadLibraryW>
ENDIF

LoadModule PROTO STDCALL :DWORD,:DWORD
LoadResource PROTO STDCALL :DWORD,:DWORD
LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalCompact PROTO STDCALL :DWORD
LocalFileTimeToFileTime PROTO STDCALL :DWORD,:DWORD
LocalFlags PROTO STDCALL :DWORD
LocalFree PROTO STDCALL :DWORD
LocalHandle PROTO STDCALL :DWORD
LocalLock PROTO STDCALL :DWORD
LocalReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
LocalShrink PROTO STDCALL :DWORD,:DWORD
LocalSize PROTO STDCALL :DWORD
LocalUnlock PROTO STDCALL :DWORD
LockFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LockFileEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LockResource PROTO STDCALL :DWORD
MapUserPhysicalPages PROTO STDCALL :DWORD,:DWORD,:DWORD
MapUserPhysicalPagesScatter PROTO STDCALL :DWORD,:DWORD,:DWORD
MapViewOfFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MapViewOfFileEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

Module32FirstW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  Module32First equ <Module32FirstW>
ENDIF


Module32NextW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  Module32Next equ <Module32NextW>
ENDIF

MoveFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MoveFile equ <MoveFileA>
ENDIF

MoveFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MoveFileEx equ <MoveFileExA>
ENDIF

MoveFileExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MoveFileEx equ <MoveFileExW>
ENDIF

MoveFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MoveFile equ <MoveFileW>
ENDIF

MoveFileWithProgressA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MoveFileWithProgress equ <MoveFileWithProgressA>
ENDIF

MoveFileWithProgressW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MoveFileWithProgress equ <MoveFileWithProgressW>
ENDIF

MulDiv PROTO STDCALL :DWORD,:DWORD,:DWORD
MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NumaVirtualQueryNode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

OpenEventA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenEvent equ <OpenEventA>
ENDIF

OpenEventW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenEvent equ <OpenEventW>
ENDIF

OpenFile PROTO STDCALL :DWORD,:DWORD,:DWORD

OpenFileMappingA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenFileMapping equ <OpenFileMappingA>
ENDIF

OpenFileMappingW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenFileMapping equ <OpenFileMappingW>
ENDIF

OpenJobObjectA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenJobObject equ <OpenJobObjectA>
ENDIF

OpenJobObjectW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenJobObject equ <OpenJobObjectW>
ENDIF

OpenMutexA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenMutex equ <OpenMutexA>
ENDIF

OpenMutexW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenMutex equ <OpenMutexW>
ENDIF

OpenProcess PROTO STDCALL :DWORD,:DWORD,:DWORD

OpenSemaphoreA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenSemaphore equ <OpenSemaphoreA>
ENDIF

OpenSemaphoreW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenSemaphore equ <OpenSemaphoreW>
ENDIF

OpenThread PROTO STDCALL :DWORD,:DWORD,:DWORD

OpenWaitableTimerA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenWaitableTimer equ <OpenWaitableTimerA>
ENDIF

OpenWaitableTimerW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenWaitableTimer equ <OpenWaitableTimerW>
ENDIF

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

OutputDebugStringW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringW>
ENDIF

PeekConsoleInputA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PeekConsoleInput equ <PeekConsoleInputA>
ENDIF

PeekConsoleInputW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PeekConsoleInput equ <PeekConsoleInputW>
ENDIF

PeekNamedPipe PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PostQueuedCompletionStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PrepareTape PROTO STDCALL :DWORD,:DWORD,:DWORD

Process32FirstW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  Process32First equ <Process32FirstW>
ENDIF


Process32NextW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  Process32Next equ <Process32NextW>
ENDIF

ProcessIdToSessionId PROTO STDCALL :DWORD,:DWORD
PulseEvent PROTO STDCALL :DWORD
PurgeComm PROTO STDCALL :DWORD,:DWORD

QueryActCtxW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryActCtx equ <QueryActCtxW>
ENDIF

QueryDepthSList PROTO STDCALL :DWORD

QueryDosDeviceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryDosDevice equ <QueryDosDeviceA>
ENDIF

QueryDosDeviceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryDosDevice equ <QueryDosDeviceW>
ENDIF

QueryInformationJobObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryMemoryResourceNotification PROTO STDCALL :DWORD,:DWORD
QueryPerformanceCounter PROTO STDCALL :DWORD
QueryPerformanceFrequency PROTO STDCALL :DWORD
QueueUserAPC PROTO STDCALL :DWORD,:DWORD,:DWORD
QueueUserWorkItem PROTO STDCALL :DWORD,:DWORD,:DWORD
RaiseException PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ReadConsoleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReadConsole equ <ReadConsoleA>
ENDIF

ReadConsoleInputA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReadConsoleInput equ <ReadConsoleInputA>
ENDIF

ReadConsoleInputW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadConsoleInput equ <ReadConsoleInputW>
ENDIF

ReadConsoleOutputA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReadConsoleOutput equ <ReadConsoleOutputA>
ENDIF

ReadConsoleOutputAttribute PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ReadConsoleOutputCharacterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReadConsoleOutputCharacter equ <ReadConsoleOutputCharacterA>
ENDIF

ReadConsoleOutputCharacterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadConsoleOutputCharacter equ <ReadConsoleOutputCharacterW>
ENDIF

ReadConsoleOutputW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadConsoleOutput equ <ReadConsoleOutputW>
ENDIF

ReadConsoleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadConsole equ <ReadConsoleW>
ENDIF

ReadDirectoryChangesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadDirectoryChanges equ <ReadDirectoryChangesW>
ENDIF

ReadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadFileEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadFileScatter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadProcessMemory PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegisterWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegisterWaitForSingleObjectEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReleaseActCtx PROTO STDCALL :DWORD
ReleaseMutex PROTO STDCALL :DWORD
ReleaseSemaphore PROTO STDCALL :DWORD,:DWORD,:DWORD

RemoveDirectoryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RemoveDirectory equ <RemoveDirectoryA>
ENDIF

RemoveDirectoryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RemoveDirectory equ <RemoveDirectoryW>
ENDIF

RemoveLocalAlternateComputerNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RemoveLocalAlternateComputerName equ <RemoveLocalAlternateComputerNameA>
ENDIF

RemoveLocalAlternateComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RemoveLocalAlternateComputerName equ <RemoveLocalAlternateComputerNameW>
ENDIF

RemoveVectoredExceptionHandler PROTO STDCALL :DWORD

ReplaceFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReplaceFile equ <ReplaceFileA>
ENDIF

ReplaceFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReplaceFile equ <ReplaceFileW>
ENDIF

RequestDeviceWakeup PROTO STDCALL :DWORD
RequestWakeupLatency PROTO STDCALL :DWORD
ResetEvent PROTO STDCALL :DWORD
ResetWriteWatch PROTO STDCALL :DWORD,:DWORD
RestoreLastError PROTO STDCALL :DWORD
ResumeThread PROTO STDCALL :DWORD
RtlCaptureContext PROTO STDCALL :DWORD
RtlCaptureStackBackTrace PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlFillMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUnwind PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlZeroMemory PROTO STDCALL :DWORD,:DWORD

ScrollConsoleScreenBufferA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ScrollConsoleScreenBuffer equ <ScrollConsoleScreenBufferA>
ENDIF

ScrollConsoleScreenBufferW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ScrollConsoleScreenBuffer equ <ScrollConsoleScreenBufferW>
ENDIF

SearchPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SearchPath equ <SearchPathA>
ENDIF

SearchPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SearchPath equ <SearchPathW>
ENDIF

SetCalendarInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetCalendarInfo equ <SetCalendarInfoA>
ENDIF

SetCalendarInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetCalendarInfo equ <SetCalendarInfoW>
ENDIF

SetCommBreak PROTO STDCALL :DWORD
SetCommConfig PROTO STDCALL :DWORD,:DWORD,:DWORD
SetCommMask PROTO STDCALL :DWORD,:DWORD
SetCommState PROTO STDCALL :DWORD,:DWORD
SetCommTimeouts PROTO STDCALL :DWORD,:DWORD

SetComputerNameA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetComputerName equ <SetComputerNameA>
ENDIF

SetComputerNameExA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetComputerNameEx equ <SetComputerNameExA>
ENDIF

SetComputerNameExW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetComputerNameEx equ <SetComputerNameExW>
ENDIF

SetComputerNameW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetComputerName equ <SetComputerNameW>
ENDIF

SetConsoleActiveScreenBuffer PROTO STDCALL :DWORD
SetConsoleCP PROTO STDCALL :DWORD
SetConsoleCtrlHandler PROTO STDCALL :DWORD,:DWORD
SetConsoleCursor PROTO STDCALL :DWORD,:DWORD
SetConsoleCursorInfo PROTO STDCALL :DWORD,:DWORD
SetConsoleCursorPosition PROTO STDCALL :DWORD,:DWORD
SetConsoleMode PROTO STDCALL :DWORD,:DWORD
SetConsoleOutputCP PROTO STDCALL :DWORD
SetConsoleScreenBufferSize PROTO STDCALL :DWORD,:DWORD
SetConsoleTextAttribute PROTO STDCALL :DWORD,:DWORD

SetConsoleTitleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetConsoleTitle equ <SetConsoleTitleA>
ENDIF

SetConsoleTitleW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetConsoleTitle equ <SetConsoleTitleW>
ENDIF

SetConsoleWindowInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
SetCriticalSectionSpinCount PROTO STDCALL :DWORD,:DWORD

SetCurrentDirectoryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetCurrentDirectory equ <SetCurrentDirectoryA>
ENDIF

SetCurrentDirectoryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetCurrentDirectory equ <SetCurrentDirectoryW>
ENDIF

SetDefaultCommConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetDefaultCommConfig equ <SetDefaultCommConfigA>
ENDIF

SetDefaultCommConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetDefaultCommConfig equ <SetDefaultCommConfigW>
ENDIF

SetDllDirectoryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetDllDirectory equ <SetDllDirectoryA>
ENDIF

SetDllDirectoryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetDllDirectory equ <SetDllDirectoryW>
ENDIF

SetEndOfFile PROTO STDCALL :DWORD

SetEnvironmentVariableA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetEnvironmentVariable equ <SetEnvironmentVariableA>
ENDIF

SetEnvironmentVariableW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetEnvironmentVariable equ <SetEnvironmentVariableW>
ENDIF

SetErrorMode PROTO STDCALL :DWORD
SetEvent PROTO STDCALL :DWORD
SetFileApisToANSI PROTO STDCALL
SetFileApisToOEM PROTO STDCALL

SetFileAttributesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetFileAttributes equ <SetFileAttributesA>
ENDIF

SetFileAttributesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetFileAttributes equ <SetFileAttributesW>
ENDIF

SetFilePointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetFilePointerEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetFileShortNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetFileShortName equ <SetFileShortNameA>
ENDIF

SetFileShortNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetFileShortName equ <SetFileShortNameW>
ENDIF

SetFileTime PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetFileValidData PROTO STDCALL :DWORD,:DWORD,:DWORD

SetFirmwareEnvironmentVariableA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetFirmwareEnvironmentVariable equ <SetFirmwareEnvironmentVariableA>
ENDIF

SetFirmwareEnvironmentVariableW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetFirmwareEnvironmentVariable equ <SetFirmwareEnvironmentVariableW>
ENDIF

SetHandleCount PROTO STDCALL :DWORD
SetHandleInformation PROTO STDCALL :DWORD,:DWORD,:DWORD
SetInformationJobObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetLastError PROTO STDCALL :DWORD

SetLocalPrimaryComputerNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetLocalPrimaryComputerName equ <SetLocalPrimaryComputerNameA>
ENDIF

SetLocalPrimaryComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetLocalPrimaryComputerName equ <SetLocalPrimaryComputerNameW>
ENDIF

SetLocalTime PROTO STDCALL :DWORD

SetLocaleInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetLocaleInfo equ <SetLocaleInfoA>
ENDIF

SetLocaleInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetLocaleInfo equ <SetLocaleInfoW>
ENDIF

SetMailslotInfo PROTO STDCALL :DWORD,:DWORD
SetMessageWaitingIndicator PROTO STDCALL :DWORD,:DWORD
SetNamedPipeHandleState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetPriorityClass PROTO STDCALL :DWORD,:DWORD
SetProcessAffinityMask PROTO STDCALL :DWORD,:DWORD
SetProcessPriorityBoost PROTO STDCALL :DWORD,:DWORD
SetProcessShutdownParameters PROTO STDCALL :DWORD,:DWORD
SetProcessWorkingSetSize PROTO STDCALL :DWORD,:DWORD,:DWORD
SetStdHandle PROTO STDCALL :DWORD,:DWORD
SetSystemPowerState PROTO STDCALL :DWORD,:DWORD
SetSystemTime PROTO STDCALL :DWORD
SetSystemTimeAdjustment PROTO STDCALL :DWORD,:DWORD
SetTapeParameters PROTO STDCALL :DWORD,:DWORD,:DWORD
SetTapePosition PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetThreadAffinityMask PROTO STDCALL :DWORD,:DWORD
SetThreadContext PROTO STDCALL :DWORD,:DWORD
SetThreadExecutionState PROTO STDCALL :DWORD
SetThreadIdealProcessor PROTO STDCALL :DWORD,:DWORD
SetThreadLocale PROTO STDCALL :DWORD
SetThreadPriority PROTO STDCALL :DWORD,:DWORD
SetThreadPriorityBoost PROTO STDCALL :DWORD,:DWORD
SetTimeZoneInformation PROTO STDCALL :DWORD
SetTimerQueueTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetUnhandledExceptionFilter PROTO STDCALL :DWORD
SetUserGeoID PROTO STDCALL :DWORD

SetVolumeLabelA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetVolumeLabel equ <SetVolumeLabelA>
ENDIF

SetVolumeLabelW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetVolumeLabel equ <SetVolumeLabelW>
ENDIF

SetVolumeMountPointA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetVolumeMountPoint equ <SetVolumeMountPointA>
ENDIF

SetVolumeMountPointW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetVolumeMountPoint equ <SetVolumeMountPointW>
ENDIF

SetWaitableTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupComm PROTO STDCALL :DWORD,:DWORD,:DWORD
SignalObjectAndWait PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SizeofResource PROTO STDCALL :DWORD,:DWORD
Sleep PROTO STDCALL :DWORD
SleepEx PROTO STDCALL :DWORD,:DWORD
SuspendThread PROTO STDCALL :DWORD
SwitchToFiber PROTO STDCALL :DWORD
SwitchToThread PROTO STDCALL
SystemTimeToFileTime PROTO STDCALL :DWORD,:DWORD
SystemTimeToTzSpecificLocalTime PROTO STDCALL :DWORD,:DWORD,:DWORD
TerminateJobObject PROTO STDCALL :DWORD,:DWORD
TerminateProcess PROTO STDCALL :DWORD,:DWORD
TerminateThread PROTO STDCALL :DWORD,:DWORD
Thread32First PROTO STDCALL :DWORD,:DWORD
Thread32Next PROTO STDCALL :DWORD,:DWORD
TlsAlloc PROTO STDCALL
TlsFree PROTO STDCALL :DWORD
TlsGetValue PROTO STDCALL :DWORD
TlsSetValue PROTO STDCALL :DWORD,:DWORD
Toolhelp32ReadProcessMemory PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TransactNamedPipe PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TransmitCommChar PROTO STDCALL :DWORD,:DWORD
TryEnterCriticalSection PROTO STDCALL :DWORD
TzSpecificLocalTimeToSystemTime PROTO STDCALL :DWORD,:DWORD,:DWORD
UnhandledExceptionFilter PROTO STDCALL :DWORD
UnlockFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UnlockFileEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UnmapViewOfFile PROTO STDCALL :DWORD
UnregisterWait PROTO STDCALL :DWORD
UnregisterWaitEx PROTO STDCALL :DWORD,:DWORD

UpdateResourceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  UpdateResource equ <UpdateResourceA>
ENDIF

UpdateResourceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  UpdateResource equ <UpdateResourceW>
ENDIF

VerLanguageNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  VerLanguageName equ <VerLanguageNameA>
ENDIF

VerLanguageNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  VerLanguageName equ <VerLanguageNameW>
ENDIF

VerSetConditionMask PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

VerifyVersionInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  VerifyVersionInfo equ <VerifyVersionInfoA>
ENDIF

VerifyVersionInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  VerifyVersionInfo equ <VerifyVersionInfoW>
ENDIF

VirtualAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VirtualAllocEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VirtualFree PROTO STDCALL :DWORD,:DWORD,:DWORD
VirtualFreeEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VirtualLock PROTO STDCALL :DWORD,:DWORD
VirtualProtect PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VirtualProtectEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VirtualQuery PROTO STDCALL :DWORD,:DWORD,:DWORD
VirtualQueryEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VirtualUnlock PROTO STDCALL :DWORD,:DWORD
WTSGetActiveConsoleSessionId PROTO STDCALL
WaitCommEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
WaitForDebugEvent PROTO STDCALL :DWORD,:DWORD
WaitForMultipleObjects PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WaitForMultipleObjectsEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD
WaitForSingleObjectEx PROTO STDCALL :DWORD,:DWORD,:DWORD

WaitNamedPipeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  WaitNamedPipe equ <WaitNamedPipeA>
ENDIF

WaitNamedPipeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  WaitNamedPipe equ <WaitNamedPipeW>
ENDIF

WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinExec PROTO STDCALL :DWORD,:DWORD

WriteConsoleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WriteConsole equ <WriteConsoleA>
ENDIF

WriteConsoleInputA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WriteConsoleInput equ <WriteConsoleInputA>
ENDIF

WriteConsoleInputW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WriteConsoleInput equ <WriteConsoleInputW>
ENDIF

WriteConsoleOutputA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WriteConsoleOutput equ <WriteConsoleOutputA>
ENDIF

WriteConsoleOutputAttribute PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

WriteConsoleOutputCharacterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WriteConsoleOutputCharacter equ <WriteConsoleOutputCharacterA>
ENDIF

WriteConsoleOutputCharacterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WriteConsoleOutputCharacter equ <WriteConsoleOutputCharacterW>
ENDIF

WriteConsoleOutputW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WriteConsoleOutput equ <WriteConsoleOutputW>
ENDIF

WriteConsoleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WriteConsole equ <WriteConsoleW>
ENDIF

WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFileEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFileGather PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

WritePrivateProfileSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WritePrivateProfileSection equ <WritePrivateProfileSectionA>
ENDIF

WritePrivateProfileSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WritePrivateProfileSection equ <WritePrivateProfileSectionW>
ENDIF

WritePrivateProfileStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WritePrivateProfileString equ <WritePrivateProfileStringA>
ENDIF

WritePrivateProfileStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WritePrivateProfileString equ <WritePrivateProfileStringW>
ENDIF

WritePrivateProfileStructA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WritePrivateProfileStruct equ <WritePrivateProfileStructA>
ENDIF

WritePrivateProfileStructW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WritePrivateProfileStruct equ <WritePrivateProfileStructW>
ENDIF

WriteProcessMemory PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

WriteProfileSectionA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  WriteProfileSection equ <WriteProfileSectionA>
ENDIF

WriteProfileSectionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  WriteProfileSection equ <WriteProfileSectionW>
ENDIF

WriteProfileStringA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WriteProfileString equ <WriteProfileStringA>
ENDIF

WriteProfileStringW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WriteProfileString equ <WriteProfileStringW>
ENDIF

WriteTapemark PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZombifyActCtx PROTO STDCALL :DWORD
_hread PROTO STDCALL :DWORD,:DWORD,:DWORD
_hwrite PROTO STDCALL :DWORD,:DWORD,:DWORD
_lclose PROTO STDCALL :DWORD
_lcreat PROTO STDCALL :DWORD,:DWORD
_llseek PROTO STDCALL :DWORD,:DWORD,:DWORD
_lopen PROTO STDCALL :DWORD,:DWORD
_lread PROTO STDCALL :DWORD,:DWORD,:DWORD
_lwrite PROTO STDCALL :DWORD,:DWORD,:DWORD

lstrcatA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcat equ <lstrcatA>
ENDIF

lstrcatW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcat equ <lstrcatW>
ENDIF


lstrcmpA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcmp equ <lstrcmpA>
ENDIF

lstrcmpW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcmp equ <lstrcmpW>
ENDIF


lstrcmpiA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcmpi equ <lstrcmpiA>
ENDIF

lstrcmpiW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcmpi equ <lstrcmpiW>
ENDIF


lstrcpyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpy equ <lstrcpyA>
ENDIF

lstrcpyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpy equ <lstrcpyW>
ENDIF


lstrcpynA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpyn equ <lstrcpynA>
ENDIF

lstrcpynW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpyn equ <lstrcpynW>
ENDIF


lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

lstrlenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  lstrlen equ <lstrlenW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file kernel32.inc
  echo -------------------------------------------
ENDIF
