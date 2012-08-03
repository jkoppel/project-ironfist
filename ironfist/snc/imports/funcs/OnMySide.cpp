{
  return a1 != -1
      && (giCurPlayer == a1
       || gbInCampaign && !gpGame->field_2 && gpGame->field_4 == 9 && a1
       || gbInCampaign && gpGame->field_2 == 1 && gpGame->field_4 == 10 && a1
       || gpGame->winConditionType == 4
       && (gpGame->winConditionArgument == 99 && a1
        || gpGame->winConditionArgument != 99
        && (gpGame->players[giCurPlayer].color < (signed int)*(_WORD *)&gpGame->_3[3]
         && gpGame->players[a1].color < (signed int)*(_WORD *)&gpGame->_3[3]
         || gpGame->players[giCurPlayer].color >= (signed int)*(_WORD *)&gpGame->_3[3]
         && gpGame->players[a1].color >= (signed int)*(_WORD *)&gpGame->_3[3]))
       || gbInCampaign
       && !gpGame->field_2
       && gpGame->field_4 == 8
       && gpGame->players[a1].color
       && gpGame->players[a1].color != 3);
}