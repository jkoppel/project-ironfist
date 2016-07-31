
 // (Delphi Versions)

{$IFNDEF VER80}                      {Delphi 1}
  {$IFNDEF VER90}                    {Delphi 2}
    {$IFNDEF VER93}                  {BCB 1}
      {$DEFINE D3}
    {$ENDIF}
  {$ENDIF}
{$ENDIF}

{$IFNDEF VER110}                     {Delphi 4}
  {$IFNDEF VER115}                   {BCB 4}
    {$DEFINE D4}
  {$ENDIF}
{$ENDIF}

{$IFNDEF VER120}                     {Delphi 4}
  {$IFNDEF VER125}                   {BCB 4}
    {$DEFINE D5}
  {$ENDIF}
{$ENDIF}

{$IFNDEF VER130}                     {Delphi/BCB 5}
  {$DEFINE D6}
{$ENDIF}

{$IFNDEF VER140}                     {Delphi/BCB 6}
  {$DEFINE D7}
{$ENDIF}

{$IFNDEF VER150}                     {Delphi/BCB 7}
  {$DEFINE D8}
{$ENDIF}

{$IFNDEF VER160}                     {Delphi 8}
  {$DEFINE D2005}
{$ENDIF}

{$IFNDEF VER170}                     {Delphi 2005}
  {$DEFINE D2006}
{$ENDIF}

{$IFNDEF D3}     {$UNDEF D4}     {$ENDIF}
{$IFNDEF D4}     {$UNDEF D5}     {$ENDIF}
{$IFNDEF D5}     {$UNDEF D6}     {$ENDIF}
{$IFNDEF D6}     {$UNDEF D7}     {$ENDIF}
{$IFNDEF D7}     {$UNDEF D8}     {$ENDIF}
{$IFNDEF D8}     {$UNDEF D2005}  {$ENDIF}
{$IFNDEF D2005}  {$UNDEF D2006}  {$ENDIF}

 // (Options)

{$IFDEF D6}
{ $ObjExportAll On}  // Never used BCB. Should I turn this on? 
{$ENDIF}

{$IFDEF D7}
{$WARN UNSAFE_TYPE OFF}
{$WARN UNSAFE_CODE OFF}
{$WARN UNSAFE_CAST OFF}
{$ENDIF}

{$WARN SYMBOL_PLATFORM OFF}
{$B-} { Complete Boolean Evaluation }
{$R-} { Range-Checking }
{$T-} { Typed @ operator }
{$X+} { Extended syntax }
{$H+} { Use long strings }

