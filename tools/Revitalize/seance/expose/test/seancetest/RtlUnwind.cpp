void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  RtlUnwind(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}
