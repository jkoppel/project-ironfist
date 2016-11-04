#include "windows.h"

void __cdecl ShowMsg( LPCTSTR lpctszTitle_i, const DWORD dwIconType_i, LPCTSTR lpctszMessage_i, ... )
{
        va_list vaArgList;
        va_start( vaArgList, lpctszMessage_i );
 
        CString csMsg;
        csMsg.FormatV( lpctszMessage_i, vaArgList );
 
        MessageBox( AfxGetMainWnd()->GetSafeHwnd(),
                    csMsg,
                    lpctszTitle_i,
                    dwIconType_i );
 
        va_end( vaArgList );
}