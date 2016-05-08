// Has to be defined before any include <windows.h> (compatibility with POCO)
// In general, include analytics.h before anything else.
#include <WinSock2.h>
#include "base.h"

void send_event(char* category, char* action);
