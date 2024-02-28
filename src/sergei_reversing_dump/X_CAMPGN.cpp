#include "../../include2023/patcher_x86.hpp"
#include "../../include2023/gui.h"
#include "../../include2023/managers.h"
#include "../../include2023/map.h"
#include "../../include2023/game.h"
#include "../../include2023/combat.h"

#include <math.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

char ExpCampaign_HasAward(void* xCampaign, int a2)
{
  return *((char*)xCampaign + a2 + 44);
}

int ExpCampaign_CampaignID(void* xCampaign)
{
  return *(int*)xCampaign;
}

char* ExpCampaign_JosephName(void* xCampaign)
{
  char* result;

  return result;
}

char* ExpCampaign_IvanName(void* xCampaign)
{
  char *result;

  return result;
}
