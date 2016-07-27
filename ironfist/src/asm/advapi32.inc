; --------------------------------------------------------------------------------------------------
;                          advapi32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ADVAPI32_INC
ADVAPI32_INC equ <1>

AbortSystemShutdownA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  AbortSystemShutdown equ <AbortSystemShutdownA>
ENDIF

AbortSystemShutdownW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  AbortSystemShutdown equ <AbortSystemShutdownW>
ENDIF

AccessCheck PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

AccessCheckAndAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AccessCheckAndAuditAlarm equ <AccessCheckAndAuditAlarmA>
ENDIF

AccessCheckAndAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AccessCheckAndAuditAlarm equ <AccessCheckAndAuditAlarmW>
ENDIF

AccessCheckByType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

AccessCheckByTypeAndAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AccessCheckByTypeAndAuditAlarm equ <AccessCheckByTypeAndAuditAlarmA>
ENDIF

AccessCheckByTypeAndAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AccessCheckByTypeAndAuditAlarm equ <AccessCheckByTypeAndAuditAlarmW>
ENDIF

AccessCheckByTypeResultList PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

AccessCheckByTypeResultListAndAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AccessCheckByTypeResultListAndAuditAlarm equ <AccessCheckByTypeResultListAndAuditAlarmA>
ENDIF

AccessCheckByTypeResultListAndAuditAlarmByHandleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AccessCheckByTypeResultListAndAuditAlarmByHandle equ <AccessCheckByTypeResultListAndAuditAlarmByHandleA>
ENDIF

AccessCheckByTypeResultListAndAuditAlarmByHandleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AccessCheckByTypeResultListAndAuditAlarmByHandle equ <AccessCheckByTypeResultListAndAuditAlarmByHandleW>
ENDIF

AccessCheckByTypeResultListAndAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AccessCheckByTypeResultListAndAuditAlarm equ <AccessCheckByTypeResultListAndAuditAlarmW>
ENDIF

AddAccessAllowedAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AddAccessAllowedAceEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAccessAllowedObjectAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAccessDeniedAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AddAccessDeniedAceEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAccessDeniedObjectAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAuditAccessAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAuditAccessAceEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAuditAccessObjectAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddUsersToEncryptedFile PROTO STDCALL :DWORD,:DWORD
AdjustTokenGroups PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AdjustTokenPrivileges PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateAndInitializeSid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateLocallyUniqueId PROTO STDCALL :DWORD
AreAllAccessesGranted PROTO STDCALL :DWORD,:DWORD
AreAnyAccessesGranted PROTO STDCALL :DWORD,:DWORD

BackupEventLogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  BackupEventLog equ <BackupEventLogA>
ENDIF

BackupEventLogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BackupEventLog equ <BackupEventLogW>
ENDIF

BuildExplicitAccessWithNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  BuildExplicitAccessWithName equ <BuildExplicitAccessWithNameA>
ENDIF

BuildExplicitAccessWithNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  BuildExplicitAccessWithName equ <BuildExplicitAccessWithNameW>
ENDIF

BuildImpersonateExplicitAccessWithNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  BuildImpersonateExplicitAccessWithName equ <BuildImpersonateExplicitAccessWithNameA>
ENDIF

BuildImpersonateExplicitAccessWithNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  BuildImpersonateExplicitAccessWithName equ <BuildImpersonateExplicitAccessWithNameW>
ENDIF

BuildImpersonateTrusteeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  BuildImpersonateTrustee equ <BuildImpersonateTrusteeA>
ENDIF

BuildImpersonateTrusteeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BuildImpersonateTrustee equ <BuildImpersonateTrusteeW>
ENDIF

BuildSecurityDescriptorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  BuildSecurityDescriptor equ <BuildSecurityDescriptorA>
ENDIF

BuildSecurityDescriptorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  BuildSecurityDescriptor equ <BuildSecurityDescriptorW>
ENDIF

BuildTrusteeWithNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  BuildTrusteeWithName equ <BuildTrusteeWithNameA>
ENDIF

BuildTrusteeWithNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BuildTrusteeWithName equ <BuildTrusteeWithNameW>
ENDIF

BuildTrusteeWithObjectsAndNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  BuildTrusteeWithObjectsAndName equ <BuildTrusteeWithObjectsAndNameA>
ENDIF

BuildTrusteeWithObjectsAndNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  BuildTrusteeWithObjectsAndName equ <BuildTrusteeWithObjectsAndNameW>
ENDIF

BuildTrusteeWithObjectsAndSidA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  BuildTrusteeWithObjectsAndSid equ <BuildTrusteeWithObjectsAndSidA>
ENDIF

BuildTrusteeWithObjectsAndSidW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  BuildTrusteeWithObjectsAndSid equ <BuildTrusteeWithObjectsAndSidW>
ENDIF

BuildTrusteeWithSidA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  BuildTrusteeWithSid equ <BuildTrusteeWithSidA>
ENDIF

BuildTrusteeWithSidW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BuildTrusteeWithSid equ <BuildTrusteeWithSidW>
ENDIF

CancelOverlappedAccess PROTO STDCALL :DWORD

ChangeServiceConfig2A PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ChangeServiceConfig2 equ <ChangeServiceConfig2A>
ENDIF

ChangeServiceConfig2W PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ChangeServiceConfig2 equ <ChangeServiceConfig2W>
ENDIF

ChangeServiceConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ChangeServiceConfig equ <ChangeServiceConfigA>
ENDIF

ChangeServiceConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ChangeServiceConfig equ <ChangeServiceConfigW>
ENDIF

CheckTokenMembership PROTO STDCALL :DWORD,:DWORD,:DWORD

ClearEventLogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ClearEventLog equ <ClearEventLogA>
ENDIF

ClearEventLogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ClearEventLog equ <ClearEventLogW>
ENDIF

CloseCodeAuthzLevel PROTO STDCALL :DWORD
CloseEncryptedFileRaw PROTO STDCALL :DWORD
CloseEventLog PROTO STDCALL :DWORD
CloseServiceHandle PROTO STDCALL :DWORD
CloseTrace PROTO STDCALL :DWORD,:DWORD
CommandLineFromMsiDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD
ComputeAccessTokenFromCodeAuthzLevel PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ControlService PROTO STDCALL :DWORD,:DWORD,:DWORD

ControlTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ControlTrace equ <ControlTraceA>
ENDIF

ControlTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ControlTrace equ <ControlTraceW>
ENDIF

ConvertAccessToSecurityDescriptorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertAccessToSecurityDescriptor equ <ConvertAccessToSecurityDescriptorA>
ENDIF

ConvertAccessToSecurityDescriptorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertAccessToSecurityDescriptor equ <ConvertAccessToSecurityDescriptorW>
ENDIF

ConvertSDToStringSDRootDomainA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertSDToStringSDRootDomain equ <ConvertSDToStringSDRootDomainA>
ENDIF

ConvertSDToStringSDRootDomainW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertSDToStringSDRootDomain equ <ConvertSDToStringSDRootDomainW>
ENDIF

ConvertSecurityDescriptorToAccessA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertSecurityDescriptorToAccess equ <ConvertSecurityDescriptorToAccessA>
ENDIF

ConvertSecurityDescriptorToAccessNamedA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertSecurityDescriptorToAccessNamed equ <ConvertSecurityDescriptorToAccessNamedA>
ENDIF

ConvertSecurityDescriptorToAccessNamedW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertSecurityDescriptorToAccessNamed equ <ConvertSecurityDescriptorToAccessNamedW>
ENDIF

ConvertSecurityDescriptorToAccessW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertSecurityDescriptorToAccess equ <ConvertSecurityDescriptorToAccessW>
ENDIF

ConvertSecurityDescriptorToStringSecurityDescriptorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertSecurityDescriptorToStringSecurityDescriptor equ <ConvertSecurityDescriptorToStringSecurityDescriptorA>
ENDIF

ConvertSecurityDescriptorToStringSecurityDescriptorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertSecurityDescriptorToStringSecurityDescriptor equ <ConvertSecurityDescriptorToStringSecurityDescriptorW>
ENDIF

ConvertSidToStringSidA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertSidToStringSid equ <ConvertSidToStringSidA>
ENDIF

ConvertSidToStringSidW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ConvertSidToStringSid equ <ConvertSidToStringSidW>
ENDIF

ConvertStringSDToSDDomainA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertStringSDToSDDomain equ <ConvertStringSDToSDDomainA>
ENDIF

ConvertStringSDToSDDomainW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertStringSDToSDDomain equ <ConvertStringSDToSDDomainW>
ENDIF

ConvertStringSDToSDRootDomainA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertStringSDToSDRootDomain equ <ConvertStringSDToSDRootDomainA>
ENDIF

ConvertStringSDToSDRootDomainW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertStringSDToSDRootDomain equ <ConvertStringSDToSDRootDomainW>
ENDIF

ConvertStringSecurityDescriptorToSecurityDescriptorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertStringSecurityDescriptorToSecurityDescriptor equ <ConvertStringSecurityDescriptorToSecurityDescriptorA>
ENDIF

ConvertStringSecurityDescriptorToSecurityDescriptorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConvertStringSecurityDescriptorToSecurityDescriptor equ <ConvertStringSecurityDescriptorToSecurityDescriptorW>
ENDIF

ConvertStringSidToSidA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ConvertStringSidToSid equ <ConvertStringSidToSidA>
ENDIF

ConvertStringSidToSidW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ConvertStringSidToSid equ <ConvertStringSidToSidW>
ENDIF

ConvertToAutoInheritPrivateObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CopySid PROTO STDCALL :DWORD,:DWORD,:DWORD
CreateCodeAuthzLevel PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreatePrivateObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreatePrivateObjectSecurityEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreatePrivateObjectSecurityWithMultipleInheritance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateProcessAsUserA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateProcessAsUser equ <CreateProcessAsUserA>
ENDIF

CreateProcessAsUserSecure PROTO STDCALL

CreateProcessAsUserW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateProcessAsUser equ <CreateProcessAsUserW>
ENDIF

CreateProcessWithLogonW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateProcessWithLogon equ <CreateProcessWithLogonW>
ENDIF

CreateRestrictedToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateServiceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateService equ <CreateServiceA>
ENDIF

CreateServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateService equ <CreateServiceW>
ENDIF

CreateTraceInstanceId PROTO STDCALL :DWORD,:DWORD
CreateWellKnownSid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CredDeleteA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredDelete equ <CredDeleteA>
ENDIF

CredDeleteW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredDelete equ <CredDeleteW>
ENDIF

CredEnumerateA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredEnumerate equ <CredEnumerateA>
ENDIF

CredEnumerateW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredEnumerate equ <CredEnumerateW>
ENDIF

CredFree PROTO STDCALL :DWORD
CredGetSessionTypes PROTO STDCALL :DWORD,:DWORD

CredGetTargetInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredGetTargetInfo equ <CredGetTargetInfoA>
ENDIF

CredGetTargetInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredGetTargetInfo equ <CredGetTargetInfoW>
ENDIF

CredIsMarshaledCredentialA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CredIsMarshaledCredential equ <CredIsMarshaledCredentialA>
ENDIF

CredIsMarshaledCredentialW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CredIsMarshaledCredential equ <CredIsMarshaledCredentialW>
ENDIF

CredMarshalCredentialA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredMarshalCredential equ <CredMarshalCredentialA>
ENDIF

CredMarshalCredentialW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredMarshalCredential equ <CredMarshalCredentialW>
ENDIF

CredReadA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredRead equ <CredReadA>
ENDIF

CredReadDomainCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredReadDomainCredentials equ <CredReadDomainCredentialsA>
ENDIF

CredReadDomainCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredReadDomainCredentials equ <CredReadDomainCredentialsW>
ENDIF

CredReadW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredRead equ <CredReadW>
ENDIF

CredRenameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredRename equ <CredRenameA>
ENDIF

CredRenameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredRename equ <CredRenameW>
ENDIF

CredUnmarshalCredentialA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredUnmarshalCredential equ <CredUnmarshalCredentialA>
ENDIF

CredUnmarshalCredentialW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredUnmarshalCredential equ <CredUnmarshalCredentialW>
ENDIF

CredWriteA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CredWrite equ <CredWriteA>
ENDIF

CredWriteDomainCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredWriteDomainCredentials equ <CredWriteDomainCredentialsA>
ENDIF

CredWriteDomainCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredWriteDomainCredentials equ <CredWriteDomainCredentialsW>
ENDIF

CredWriteW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CredWrite equ <CredWriteW>
ENDIF

CryptAcquireContextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptAcquireContext equ <CryptAcquireContextA>
ENDIF

CryptAcquireContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptAcquireContext equ <CryptAcquireContextW>
ENDIF

CryptContextAddRef PROTO STDCALL :DWORD,:DWORD,:DWORD
CryptCreateHash PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDecrypt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDeriveKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDestroyHash PROTO STDCALL :DWORD
CryptDestroyKey PROTO STDCALL :DWORD
CryptDuplicateHash PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptDuplicateKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptEncrypt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CryptEnumProviderTypesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptEnumProviderTypes equ <CryptEnumProviderTypesA>
ENDIF

CryptEnumProviderTypesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptEnumProviderTypes equ <CryptEnumProviderTypesW>
ENDIF

CryptEnumProvidersA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptEnumProviders equ <CryptEnumProvidersA>
ENDIF

CryptEnumProvidersW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptEnumProviders equ <CryptEnumProvidersW>
ENDIF

CryptExportKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGenKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptGenRandom PROTO STDCALL :DWORD,:DWORD,:DWORD

CryptGetDefaultProviderA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptGetDefaultProvider equ <CryptGetDefaultProviderA>
ENDIF

CryptGetDefaultProviderW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptGetDefaultProvider equ <CryptGetDefaultProviderW>
ENDIF

CryptGetHashParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetKeyParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetProvParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetUserKey PROTO STDCALL :DWORD,:DWORD,:DWORD
CryptHashData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptHashSessionKey PROTO STDCALL :DWORD,:DWORD,:DWORD
CryptImportKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptReleaseContext PROTO STDCALL :DWORD,:DWORD
CryptSetHashParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptSetKeyParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptSetProvParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CryptSetProviderA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CryptSetProvider equ <CryptSetProviderA>
ENDIF

CryptSetProviderExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptSetProviderEx equ <CryptSetProviderExA>
ENDIF

CryptSetProviderExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptSetProviderEx equ <CryptSetProviderExW>
ENDIF

CryptSetProviderW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CryptSetProvider equ <CryptSetProviderW>
ENDIF

CryptSignHashA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptSignHash equ <CryptSignHashA>
ENDIF

CryptSignHashW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptSignHash equ <CryptSignHashW>
ENDIF

CryptVerifySignatureA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptVerifySignature equ <CryptVerifySignatureA>
ENDIF

CryptVerifySignatureW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptVerifySignature equ <CryptVerifySignatureW>
ENDIF

DecryptFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DecryptFile equ <DecryptFileA>
ENDIF

DecryptFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DecryptFile equ <DecryptFileW>
ENDIF

DeleteAce PROTO STDCALL :DWORD,:DWORD
DeleteService PROTO STDCALL :DWORD
DeregisterEventSource PROTO STDCALL :DWORD
DestroyPrivateObjectSecurity PROTO STDCALL :DWORD
DuplicateEncryptionInfoFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DuplicateToken PROTO STDCALL :DWORD,:DWORD,:DWORD
DuplicateTokenEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ElfBackupEventLogFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ElfBackupEventLogFile equ <ElfBackupEventLogFileA>
ENDIF

ElfBackupEventLogFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ElfBackupEventLogFile equ <ElfBackupEventLogFileW>
ENDIF

ElfChangeNotify PROTO STDCALL :DWORD,:DWORD

ElfClearEventLogFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ElfClearEventLogFile equ <ElfClearEventLogFileA>
ENDIF

ElfClearEventLogFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ElfClearEventLogFile equ <ElfClearEventLogFileW>
ENDIF

ElfCloseEventLog PROTO STDCALL :DWORD
ElfDeregisterEventSource PROTO STDCALL :DWORD
ElfFlushEventLog PROTO STDCALL :DWORD
ElfNumberOfRecords PROTO STDCALL :DWORD,:DWORD
ElfOldestRecord PROTO STDCALL :DWORD,:DWORD

ElfOpenBackupEventLogA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ElfOpenBackupEventLog equ <ElfOpenBackupEventLogA>
ENDIF

ElfOpenBackupEventLogW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ElfOpenBackupEventLog equ <ElfOpenBackupEventLogW>
ENDIF

ElfOpenEventLogA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ElfOpenEventLog equ <ElfOpenEventLogA>
ENDIF

ElfOpenEventLogW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ElfOpenEventLog equ <ElfOpenEventLogW>
ENDIF

ElfReadEventLogA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ElfReadEventLog equ <ElfReadEventLogA>
ENDIF

ElfReadEventLogW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ElfReadEventLog equ <ElfReadEventLogW>
ENDIF

ElfRegisterEventSourceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ElfRegisterEventSource equ <ElfRegisterEventSourceA>
ENDIF

ElfRegisterEventSourceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ElfRegisterEventSource equ <ElfRegisterEventSourceW>
ENDIF

ElfReportEventA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ElfReportEvent equ <ElfReportEventA>
ENDIF

ElfReportEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ElfReportEvent equ <ElfReportEventW>
ENDIF

EnableTrace PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

EncryptFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  EncryptFile equ <EncryptFileA>
ENDIF

EncryptFileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  EncryptFile equ <EncryptFileW>
ENDIF

EncryptedFileKeyInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
EncryptionDisable PROTO STDCALL :DWORD,:DWORD

EnumDependentServicesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumDependentServices equ <EnumDependentServicesA>
ENDIF

EnumDependentServicesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumDependentServices equ <EnumDependentServicesW>
ENDIF

EnumServiceGroupW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumServiceGroup equ <EnumServiceGroupW>
ENDIF

EnumServicesStatusA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumServicesStatus equ <EnumServicesStatusA>
ENDIF

EnumServicesStatusExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumServicesStatusEx equ <EnumServicesStatusExA>
ENDIF

EnumServicesStatusExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumServicesStatusEx equ <EnumServicesStatusExW>
ENDIF

EnumServicesStatusW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumServicesStatus equ <EnumServicesStatusW>
ENDIF

EnumerateTraceGuids PROTO STDCALL :DWORD,:DWORD,:DWORD
EqualDomainSid PROTO STDCALL :DWORD,:DWORD,:DWORD
EqualPrefixSid PROTO STDCALL :DWORD,:DWORD
EqualSid PROTO STDCALL :DWORD,:DWORD

FileEncryptionStatusA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FileEncryptionStatus equ <FileEncryptionStatusA>
ENDIF

FileEncryptionStatusW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FileEncryptionStatus equ <FileEncryptionStatusW>
ENDIF

FindFirstFreeAce PROTO STDCALL :DWORD,:DWORD

FlushTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FlushTrace equ <FlushTraceA>
ENDIF

FlushTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FlushTrace equ <FlushTraceW>
ENDIF

FreeEncryptedFileKeyInfo PROTO STDCALL :DWORD
FreeEncryptionCertificateHashList PROTO STDCALL :DWORD
FreeInheritedFromArray PROTO STDCALL :DWORD,:DWORD,:DWORD
FreeSid PROTO STDCALL :DWORD

GetAccessPermissionsForObjectA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetAccessPermissionsForObject equ <GetAccessPermissionsForObjectA>
ENDIF

GetAccessPermissionsForObjectW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetAccessPermissionsForObject equ <GetAccessPermissionsForObjectW>
ENDIF

GetAce PROTO STDCALL :DWORD,:DWORD,:DWORD
GetAclInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

GetAuditedPermissionsFromAclA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetAuditedPermissionsFromAcl equ <GetAuditedPermissionsFromAclA>
ENDIF

GetAuditedPermissionsFromAclW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetAuditedPermissionsFromAcl equ <GetAuditedPermissionsFromAclW>
ENDIF

GetCurrentHwProfileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetCurrentHwProfile equ <GetCurrentHwProfileA>
ENDIF

GetCurrentHwProfileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetCurrentHwProfile equ <GetCurrentHwProfileW>
ENDIF

GetEffectiveRightsFromAclA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetEffectiveRightsFromAcl equ <GetEffectiveRightsFromAclA>
ENDIF

GetEffectiveRightsFromAclW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetEffectiveRightsFromAcl equ <GetEffectiveRightsFromAclW>
ENDIF

GetEventLogInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetExplicitEntriesFromAclA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetExplicitEntriesFromAcl equ <GetExplicitEntriesFromAclA>
ENDIF

GetExplicitEntriesFromAclW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetExplicitEntriesFromAcl equ <GetExplicitEntriesFromAclW>
ENDIF

GetFileSecurityA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFileSecurity equ <GetFileSecurityA>
ENDIF

GetFileSecurityW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFileSecurity equ <GetFileSecurityW>
ENDIF

GetInformationCodeAuthzLevelW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetInformationCodeAuthzLevel equ <GetInformationCodeAuthzLevelW>
ENDIF

GetInformationCodeAuthzPolicyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetInformationCodeAuthzPolicy equ <GetInformationCodeAuthzPolicyW>
ENDIF

GetInheritanceSourceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetInheritanceSource equ <GetInheritanceSourceA>
ENDIF

GetInheritanceSourceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetInheritanceSource equ <GetInheritanceSourceW>
ENDIF

GetKernelObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetLengthSid PROTO STDCALL :DWORD
GetLocalManagedApplicationData PROTO STDCALL :DWORD,:DWORD,:DWORD
GetLocalManagedApplications PROTO STDCALL :DWORD,:DWORD,:DWORD
GetManagedApplicationCategories PROTO STDCALL :DWORD,:DWORD
GetManagedApplications PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetMultipleTrusteeA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetMultipleTrustee equ <GetMultipleTrusteeA>
ENDIF

GetMultipleTrusteeOperationA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetMultipleTrusteeOperation equ <GetMultipleTrusteeOperationA>
ENDIF

GetMultipleTrusteeOperationW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetMultipleTrusteeOperation equ <GetMultipleTrusteeOperationW>
ENDIF

GetMultipleTrusteeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetMultipleTrustee equ <GetMultipleTrusteeW>
ENDIF

GetNamedSecurityInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNamedSecurityInfo equ <GetNamedSecurityInfoA>
ENDIF

GetNamedSecurityInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNamedSecurityInfoEx equ <GetNamedSecurityInfoExA>
ENDIF

GetNamedSecurityInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNamedSecurityInfoEx equ <GetNamedSecurityInfoExW>
ENDIF

GetNamedSecurityInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNamedSecurityInfo equ <GetNamedSecurityInfoW>
ENDIF

GetNumberOfEventLogRecords PROTO STDCALL :DWORD,:DWORD
GetOldestEventLogRecord PROTO STDCALL :DWORD,:DWORD
GetOverlappedAccessResults PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetPrivateObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSecurityDescriptorControl PROTO STDCALL :DWORD,:DWORD,:DWORD
GetSecurityDescriptorDacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetSecurityDescriptorGroup PROTO STDCALL :DWORD,:DWORD,:DWORD
GetSecurityDescriptorLength PROTO STDCALL :DWORD
GetSecurityDescriptorOwner PROTO STDCALL :DWORD,:DWORD,:DWORD
GetSecurityDescriptorRMControl PROTO STDCALL :DWORD,:DWORD
GetSecurityDescriptorSacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetSecurityInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetSecurityInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetSecurityInfoEx equ <GetSecurityInfoExA>
ENDIF

GetSecurityInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetSecurityInfoEx equ <GetSecurityInfoExW>
ENDIF

GetServiceDisplayNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetServiceDisplayName equ <GetServiceDisplayNameA>
ENDIF

GetServiceDisplayNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetServiceDisplayName equ <GetServiceDisplayNameW>
ENDIF

GetServiceKeyNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetServiceKeyName equ <GetServiceKeyNameA>
ENDIF

GetServiceKeyNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetServiceKeyName equ <GetServiceKeyNameW>
ENDIF

GetSidIdentifierAuthority PROTO STDCALL :DWORD
GetSidLengthRequired PROTO STDCALL :DWORD
GetSidSubAuthority PROTO STDCALL :DWORD,:DWORD
GetSidSubAuthorityCount PROTO STDCALL :DWORD
GetTokenInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetTraceEnableFlags PROTO STDCALL :DWORD,:DWORD
GetTraceEnableLevel PROTO STDCALL :DWORD,:DWORD
GetTraceLoggerHandle PROTO STDCALL :DWORD

GetTrusteeFormA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetTrusteeForm equ <GetTrusteeFormA>
ENDIF

GetTrusteeFormW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetTrusteeForm equ <GetTrusteeFormW>
ENDIF

GetTrusteeNameA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetTrusteeName equ <GetTrusteeNameA>
ENDIF

GetTrusteeNameW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetTrusteeName equ <GetTrusteeNameW>
ENDIF

GetTrusteeTypeA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetTrusteeType equ <GetTrusteeTypeA>
ENDIF

GetTrusteeTypeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetTrusteeType equ <GetTrusteeTypeW>
ENDIF

GetUserNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetUserName equ <GetUserNameA>
ENDIF

GetUserNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetUserName equ <GetUserNameW>
ENDIF

GetWindowsAccountDomainSid PROTO STDCALL :DWORD,:DWORD,:DWORD

I_ScSetServiceBitsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  I_ScSetServiceBits equ <I_ScSetServiceBitsA>
ENDIF

I_ScSetServiceBitsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  I_ScSetServiceBits equ <I_ScSetServiceBitsW>
ENDIF

IdentifyCodeAuthzLevelW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  IdentifyCodeAuthzLevel equ <IdentifyCodeAuthzLevelW>
ENDIF

ImpersonateAnonymousToken PROTO STDCALL :DWORD
ImpersonateLoggedOnUser PROTO STDCALL :DWORD
ImpersonateNamedPipeClient PROTO STDCALL :DWORD
ImpersonateSelf PROTO STDCALL :DWORD
InitializeAcl PROTO STDCALL :DWORD,:DWORD,:DWORD
InitializeSecurityDescriptor PROTO STDCALL :DWORD,:DWORD
InitializeSid PROTO STDCALL :DWORD,:DWORD,:DWORD

InitiateSystemShutdownA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InitiateSystemShutdown equ <InitiateSystemShutdownA>
ENDIF

InitiateSystemShutdownExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InitiateSystemShutdownEx equ <InitiateSystemShutdownExA>
ENDIF

InitiateSystemShutdownExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InitiateSystemShutdownEx equ <InitiateSystemShutdownExW>
ENDIF

InitiateSystemShutdownW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InitiateSystemShutdown equ <InitiateSystemShutdownW>
ENDIF

InstallApplication PROTO STDCALL :DWORD
IsTextUnicode PROTO STDCALL :DWORD,:DWORD,:DWORD
IsTokenRestricted PROTO STDCALL :DWORD
IsTokenUntrusted PROTO STDCALL :DWORD
IsValidAcl PROTO STDCALL :DWORD
IsValidSecurityDescriptor PROTO STDCALL :DWORD
IsValidSid PROTO STDCALL :DWORD
IsWellKnownSid PROTO STDCALL :DWORD,:DWORD
LockServiceDatabase PROTO STDCALL :DWORD

LogonUserA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LogonUser equ <LogonUserA>
ENDIF

LogonUserExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LogonUserEx equ <LogonUserExA>
ENDIF

LogonUserExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LogonUserEx equ <LogonUserExW>
ENDIF

LogonUserW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LogonUser equ <LogonUserW>
ENDIF

LookupAccountNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LookupAccountName equ <LookupAccountNameA>
ENDIF

LookupAccountNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupAccountName equ <LookupAccountNameW>
ENDIF

LookupAccountSidA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LookupAccountSid equ <LookupAccountSidA>
ENDIF

LookupAccountSidW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupAccountSid equ <LookupAccountSidW>
ENDIF

LookupPrivilegeDisplayNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LookupPrivilegeDisplayName equ <LookupPrivilegeDisplayNameA>
ENDIF

LookupPrivilegeDisplayNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupPrivilegeDisplayName equ <LookupPrivilegeDisplayNameW>
ENDIF

LookupPrivilegeNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LookupPrivilegeName equ <LookupPrivilegeNameA>
ENDIF

LookupPrivilegeNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupPrivilegeName equ <LookupPrivilegeNameW>
ENDIF

LookupPrivilegeValueA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LookupPrivilegeValue equ <LookupPrivilegeValueA>
ENDIF

LookupPrivilegeValueW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupPrivilegeValue equ <LookupPrivilegeValueW>
ENDIF

LookupSecurityDescriptorPartsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LookupSecurityDescriptorParts equ <LookupSecurityDescriptorPartsA>
ENDIF

LookupSecurityDescriptorPartsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupSecurityDescriptorParts equ <LookupSecurityDescriptorPartsW>
ENDIF

LsaAddAccountRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaAddPrivilegesToAccount PROTO STDCALL :DWORD,:DWORD
LsaClearAuditLog PROTO STDCALL :DWORD
LsaClose PROTO STDCALL :DWORD
LsaCreateAccount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaCreateSecret PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaCreateTrustedDomain PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaCreateTrustedDomainEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaDelete PROTO STDCALL :DWORD
LsaDeleteTrustedDomain PROTO STDCALL :DWORD,:DWORD
LsaEnumerateAccountRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaEnumerateAccounts PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaEnumerateAccountsWithUserRight PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaEnumeratePrivileges PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaEnumeratePrivilegesOfAccount PROTO STDCALL :DWORD,:DWORD
LsaEnumerateTrustedDomains PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaEnumerateTrustedDomainsEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaFreeMemory PROTO STDCALL :DWORD
LsaGetQuotasForAccount PROTO STDCALL :DWORD,:DWORD
LsaGetRemoteUserName PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaGetSystemAccessAccount PROTO STDCALL :DWORD,:DWORD
LsaGetUserName PROTO STDCALL :DWORD,:DWORD
LsaICLookupNames PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaICLookupNamesWithCreds PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaICLookupSids PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaICLookupSidsWithCreds PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaLookupNames2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaLookupNames PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaLookupPrivilegeDisplayName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaLookupPrivilegeName PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaLookupPrivilegeValue PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaLookupSids PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaNtStatusToWinError PROTO STDCALL :DWORD
LsaOpenAccount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenPolicySce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenSecret PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenTrustedDomain PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenTrustedDomainByName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaQueryDomainInformationPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaQueryForestTrustInformation PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaQueryInfoTrustedDomain PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaQueryInformationPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaQuerySecret PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaQuerySecurityObject PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaQueryTrustedDomainInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaQueryTrustedDomainInfoByName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaRemoveAccountRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaRemovePrivilegesFromAccount PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaRetrievePrivateData PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaSetDomainInformationPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaSetForestTrustInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaSetInformationPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaSetInformationTrustedDomain PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaSetQuotasForAccount PROTO STDCALL :DWORD,:DWORD
LsaSetSecret PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaSetSecurityObject PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaSetSystemAccessAccount PROTO STDCALL :DWORD,:DWORD
LsaSetTrustedDomainInfoByName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaSetTrustedDomainInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LsaStorePrivateData PROTO STDCALL :DWORD,:DWORD,:DWORD
MSChapSrvChangePassword2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MSChapSrvChangePassword PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MakeAbsoluteSD2 PROTO STDCALL :DWORD,:DWORD
MakeAbsoluteSD PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MakeSelfRelativeSD PROTO STDCALL :DWORD,:DWORD,:DWORD
MapGenericMask PROTO STDCALL :DWORD,:DWORD
NotifyBootConfigStatus PROTO STDCALL :DWORD
NotifyChangeEventLog PROTO STDCALL :DWORD,:DWORD

ObjectCloseAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ObjectCloseAuditAlarm equ <ObjectCloseAuditAlarmA>
ENDIF

ObjectCloseAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ObjectCloseAuditAlarm equ <ObjectCloseAuditAlarmW>
ENDIF

ObjectDeleteAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ObjectDeleteAuditAlarm equ <ObjectDeleteAuditAlarmA>
ENDIF

ObjectDeleteAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ObjectDeleteAuditAlarm equ <ObjectDeleteAuditAlarmW>
ENDIF

ObjectOpenAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ObjectOpenAuditAlarm equ <ObjectOpenAuditAlarmA>
ENDIF

ObjectOpenAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ObjectOpenAuditAlarm equ <ObjectOpenAuditAlarmW>
ENDIF

ObjectPrivilegeAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ObjectPrivilegeAuditAlarm equ <ObjectPrivilegeAuditAlarmA>
ENDIF

ObjectPrivilegeAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ObjectPrivilegeAuditAlarm equ <ObjectPrivilegeAuditAlarmW>
ENDIF

OpenBackupEventLogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  OpenBackupEventLog equ <OpenBackupEventLogA>
ENDIF

OpenBackupEventLogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  OpenBackupEventLog equ <OpenBackupEventLogW>
ENDIF

OpenEncryptedFileRawA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenEncryptedFileRaw equ <OpenEncryptedFileRawA>
ENDIF

OpenEncryptedFileRawW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenEncryptedFileRaw equ <OpenEncryptedFileRawW>
ENDIF

OpenEventLogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  OpenEventLog equ <OpenEventLogA>
ENDIF

OpenEventLogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  OpenEventLog equ <OpenEventLogW>
ENDIF

OpenProcessToken PROTO STDCALL :DWORD,:DWORD,:DWORD

OpenSCManagerA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenSCManager equ <OpenSCManagerA>
ENDIF

OpenSCManagerW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenSCManager equ <OpenSCManagerW>
ENDIF

OpenServiceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenService equ <OpenServiceA>
ENDIF

OpenServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenService equ <OpenServiceW>
ENDIF

OpenThreadToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

OpenTraceA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OpenTrace equ <OpenTraceA>
ENDIF

OpenTraceW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OpenTrace equ <OpenTraceW>
ENDIF

PrivilegeCheck PROTO STDCALL :DWORD,:DWORD,:DWORD

PrivilegedServiceAuditAlarmA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PrivilegedServiceAuditAlarm equ <PrivilegedServiceAuditAlarmA>
ENDIF

PrivilegedServiceAuditAlarmW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PrivilegedServiceAuditAlarm equ <PrivilegedServiceAuditAlarmW>
ENDIF

ProcessTrace PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

QueryAllTracesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryAllTraces equ <QueryAllTracesA>
ENDIF

QueryAllTracesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryAllTraces equ <QueryAllTracesW>
ENDIF

QueryRecoveryAgentsOnEncryptedFile PROTO STDCALL :DWORD,:DWORD

QueryServiceConfig2A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryServiceConfig2 equ <QueryServiceConfig2A>
ENDIF

QueryServiceConfig2W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryServiceConfig2 equ <QueryServiceConfig2W>
ENDIF

QueryServiceConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryServiceConfig equ <QueryServiceConfigA>
ENDIF

QueryServiceConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryServiceConfig equ <QueryServiceConfigW>
ENDIF

QueryServiceLockStatusA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryServiceLockStatus equ <QueryServiceLockStatusA>
ENDIF

QueryServiceLockStatusW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryServiceLockStatus equ <QueryServiceLockStatusW>
ENDIF

QueryServiceObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryServiceStatus PROTO STDCALL :DWORD,:DWORD
QueryServiceStatusEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

QueryTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryTrace equ <QueryTraceA>
ENDIF

QueryTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryTrace equ <QueryTraceW>
ENDIF

QueryUsersOnEncryptedFile PROTO STDCALL :DWORD,:DWORD
QueryWindows31FilesMigration PROTO STDCALL :DWORD
ReadEncryptedFileRaw PROTO STDCALL :DWORD,:DWORD,:DWORD

ReadEventLogA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReadEventLog equ <ReadEventLogA>
ENDIF

ReadEventLogW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadEventLog equ <ReadEventLogW>
ENDIF

RegCloseKey PROTO STDCALL :DWORD

RegConnectRegistryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegConnectRegistry equ <RegConnectRegistryA>
ENDIF

RegConnectRegistryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegConnectRegistry equ <RegConnectRegistryW>
ENDIF

RegCreateKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegCreateKey equ <RegCreateKeyA>
ENDIF

RegCreateKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExA>
ENDIF

RegCreateKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExW>
ENDIF

RegCreateKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKey equ <RegCreateKeyW>
ENDIF

RegDeleteKeyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyA>
ENDIF

RegDeleteKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyW>
ENDIF

RegDeleteValueA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RegDeleteValue equ <RegDeleteValueA>
ENDIF

RegDeleteValueW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteValue equ <RegDeleteValueW>
ENDIF

RegDisablePredefinedCache PROTO STDCALL

RegEnumKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegEnumKey equ <RegEnumKeyA>
ENDIF

RegEnumKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegEnumKeyEx equ <RegEnumKeyExA>
ENDIF

RegEnumKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumKeyEx equ <RegEnumKeyExW>
ENDIF

RegEnumKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumKey equ <RegEnumKeyW>
ENDIF

RegEnumValueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegEnumValue equ <RegEnumValueA>
ENDIF

RegEnumValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumValue equ <RegEnumValueW>
ENDIF

RegFlushKey PROTO STDCALL :DWORD
RegGetKeySecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

RegLoadKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegLoadKey equ <RegLoadKeyA>
ENDIF

RegLoadKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegLoadKey equ <RegLoadKeyW>
ENDIF

RegNotifyChangeKeyValue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegOpenCurrentUser PROTO STDCALL :DWORD,:DWORD

RegOpenKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKey equ <RegOpenKeyA>
ENDIF

RegOpenKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExA>
ENDIF

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegOpenKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKey equ <RegOpenKeyW>
ENDIF

RegOpenUserClassesRoot PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RegOverridePredefKey PROTO STDCALL :DWORD,:DWORD

RegQueryInfoKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryInfoKey equ <RegQueryInfoKeyA>
ENDIF

RegQueryInfoKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryInfoKey equ <RegQueryInfoKeyW>
ENDIF

RegQueryMultipleValuesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryMultipleValues equ <RegQueryMultipleValuesA>
ENDIF

RegQueryMultipleValuesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryMultipleValues equ <RegQueryMultipleValuesW>
ENDIF

RegQueryValueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValue equ <RegQueryValueA>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

RegQueryValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExW>
ENDIF

RegQueryValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryValue equ <RegQueryValueW>
ENDIF

RegReplaceKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegReplaceKey equ <RegReplaceKeyA>
ENDIF

RegReplaceKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegReplaceKey equ <RegReplaceKeyW>
ENDIF

RegRestoreKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegRestoreKey equ <RegRestoreKeyA>
ENDIF

RegRestoreKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegRestoreKey equ <RegRestoreKeyW>
ENDIF

RegSaveKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegSaveKey equ <RegSaveKeyA>
ENDIF

RegSaveKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegSaveKeyEx equ <RegSaveKeyExA>
ENDIF

RegSaveKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSaveKeyEx equ <RegSaveKeyExW>
ENDIF

RegSaveKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSaveKey equ <RegSaveKeyW>
ENDIF

RegSetKeySecurity PROTO STDCALL :DWORD,:DWORD,:DWORD

RegSetValueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegSetValue equ <RegSetValueA>
ENDIF

RegSetValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExA>
ENDIF

RegSetValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExW>
ENDIF

RegSetValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSetValue equ <RegSetValueW>
ENDIF

RegUnLoadKeyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RegUnLoadKey equ <RegUnLoadKeyA>
ENDIF

RegUnLoadKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegUnLoadKey equ <RegUnLoadKeyW>
ENDIF

RegisterEventSourceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RegisterEventSource equ <RegisterEventSourceA>
ENDIF

RegisterEventSourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegisterEventSource equ <RegisterEventSourceW>
ENDIF

RegisterServiceCtrlHandlerA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RegisterServiceCtrlHandler equ <RegisterServiceCtrlHandlerA>
ENDIF

RegisterServiceCtrlHandlerExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegisterServiceCtrlHandlerEx equ <RegisterServiceCtrlHandlerExA>
ENDIF

RegisterServiceCtrlHandlerExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegisterServiceCtrlHandlerEx equ <RegisterServiceCtrlHandlerExW>
ENDIF

RegisterServiceCtrlHandlerW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegisterServiceCtrlHandler equ <RegisterServiceCtrlHandlerW>
ENDIF

RegisterTraceGuidsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegisterTraceGuids equ <RegisterTraceGuidsA>
ENDIF

RegisterTraceGuidsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegisterTraceGuids equ <RegisterTraceGuidsW>
ENDIF

RemoveTraceCallback PROTO STDCALL :DWORD
RemoveUsersFromEncryptedFile PROTO STDCALL :DWORD,:DWORD

ReportEventA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReportEvent equ <ReportEventA>
ENDIF

ReportEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReportEvent equ <ReportEventW>
ENDIF

RevertToSelf PROTO STDCALL
SaferCloseLevel PROTO STDCALL :DWORD
SaferComputeTokenFromLevel PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaferCreateLevel PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaferGetLevelInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaferGetPolicyInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaferIdentifyLevel PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SaferRecordEventLogEntry PROTO STDCALL :DWORD,:DWORD,:DWORD
SaferSetLevelInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SaferSetPolicyInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetAclInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetEntriesInAccessListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetEntriesInAccessList equ <SetEntriesInAccessListA>
ENDIF

SetEntriesInAccessListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetEntriesInAccessList equ <SetEntriesInAccessListW>
ENDIF

SetEntriesInAclA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetEntriesInAcl equ <SetEntriesInAclA>
ENDIF

SetEntriesInAclW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetEntriesInAcl equ <SetEntriesInAclW>
ENDIF

SetEntriesInAuditListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetEntriesInAuditList equ <SetEntriesInAuditListA>
ENDIF

SetEntriesInAuditListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetEntriesInAuditList equ <SetEntriesInAuditListW>
ENDIF

SetFileSecurityA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetFileSecurity equ <SetFileSecurityA>
ENDIF

SetFileSecurityW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetFileSecurity equ <SetFileSecurityW>
ENDIF

SetInformationCodeAuthzLevelW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetInformationCodeAuthzLevel equ <SetInformationCodeAuthzLevelW>
ENDIF

SetInformationCodeAuthzPolicyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetInformationCodeAuthzPolicy equ <SetInformationCodeAuthzPolicyW>
ENDIF

SetKernelObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD

SetNamedSecurityInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetNamedSecurityInfo equ <SetNamedSecurityInfoA>
ENDIF

SetNamedSecurityInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetNamedSecurityInfoEx equ <SetNamedSecurityInfoExA>
ENDIF

SetNamedSecurityInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetNamedSecurityInfoEx equ <SetNamedSecurityInfoExW>
ENDIF

SetNamedSecurityInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetNamedSecurityInfo equ <SetNamedSecurityInfoW>
ENDIF

SetPrivateObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrivateObjectSecurityEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetSecurityDescriptorControl PROTO STDCALL :DWORD,:DWORD,:DWORD
SetSecurityDescriptorDacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetSecurityDescriptorGroup PROTO STDCALL :DWORD,:DWORD,:DWORD
SetSecurityDescriptorOwner PROTO STDCALL :DWORD,:DWORD,:DWORD
SetSecurityDescriptorRMControl PROTO STDCALL :DWORD,:DWORD
SetSecurityDescriptorSacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetSecurityInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetSecurityInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetSecurityInfoEx equ <SetSecurityInfoExA>
ENDIF

SetSecurityInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetSecurityInfoEx equ <SetSecurityInfoExW>
ENDIF

SetServiceBits PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetServiceObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD
SetServiceStatus PROTO STDCALL :DWORD,:DWORD
SetThreadToken PROTO STDCALL :DWORD,:DWORD
SetTokenInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetTraceCallback PROTO STDCALL :DWORD,:DWORD
SetUserFileEncryptionKey PROTO STDCALL :DWORD

StartServiceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StartService equ <StartServiceA>
ENDIF

StartServiceCtrlDispatcherA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  StartServiceCtrlDispatcher equ <StartServiceCtrlDispatcherA>
ENDIF

StartServiceCtrlDispatcherW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  StartServiceCtrlDispatcher equ <StartServiceCtrlDispatcherW>
ENDIF

StartServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StartService equ <StartServiceW>
ENDIF

StartTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StartTrace equ <StartTraceA>
ENDIF

StartTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StartTrace equ <StartTraceW>
ENDIF

StopTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StopTrace equ <StopTraceA>
ENDIF

StopTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StopTrace equ <StopTraceW>
ENDIF

SynchronizeWindows31FilesAndWindowsNTRegistry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SystemFunction001 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction002 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction003 PROTO STDCALL :DWORD,:DWORD
SystemFunction004 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction005 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction006 PROTO STDCALL :DWORD,:DWORD
SystemFunction007 PROTO STDCALL :DWORD,:DWORD
SystemFunction008 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction009 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction010 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction011 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction012 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction013 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction014 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction015 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction016 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction017 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction018 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction019 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction020 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction021 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction022 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction023 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction024 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction025 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction026 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction027 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction028 PROTO STDCALL :DWORD,:DWORD
SystemFunction029 PROTO STDCALL :DWORD,:DWORD
SystemFunction030 PROTO STDCALL :DWORD,:DWORD
SystemFunction031 PROTO STDCALL :DWORD,:DWORD
SystemFunction032 PROTO STDCALL :DWORD,:DWORD
SystemFunction033 PROTO STDCALL :DWORD,:DWORD
SystemFunction034 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction036 PROTO STDCALL :DWORD,:DWORD
SystemFunction040 PROTO STDCALL :DWORD,:DWORD,:DWORD
SystemFunction041 PROTO STDCALL :DWORD,:DWORD,:DWORD
TraceEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
TraceEventInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TraceMessage PROTO C :VARARG
TraceMessageVa PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

TreeResetNamedSecurityInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TreeResetNamedSecurityInfo equ <TreeResetNamedSecurityInfoA>
ENDIF

TreeResetNamedSecurityInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TreeResetNamedSecurityInfo equ <TreeResetNamedSecurityInfoW>
ENDIF

TrusteeAccessToObjectA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TrusteeAccessToObject equ <TrusteeAccessToObjectA>
ENDIF

TrusteeAccessToObjectW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TrusteeAccessToObject equ <TrusteeAccessToObjectW>
ENDIF

UninstallApplication PROTO STDCALL :DWORD,:DWORD
UnlockServiceDatabase PROTO STDCALL :DWORD
UnregisterTraceGuids PROTO STDCALL :DWORD,:DWORD

UpdateTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  UpdateTrace equ <UpdateTraceA>
ENDIF

UpdateTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  UpdateTrace equ <UpdateTraceW>
ENDIF

Wow64Win32ApiEntry PROTO STDCALL :DWORD,:DWORD,:DWORD
WriteEncryptedFileRaw PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file advapi32.inc
  echo -------------------------------------------
ENDIF
