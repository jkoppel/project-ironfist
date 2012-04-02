bool __fastcall sub_4B8CB0(int a1)
{
  return a1 != -1
      && (curPlayerIdx == a1
       || loadOrNewGameSelected && !gameObject->field_2 && gameObject->field_4 == 9 && a1
       || loadOrNewGameSelected && gameObject->field_2 == 1 && gameObject->field_4 == 10 && a1
       || gameObject->winConditionType == 4
       && (gameObject->winConditionArgument == 99 && a1
        || gameObject->winConditionArgument != 99
        && (gameObject->players[curPlayerIdx].color < (signed int)*(_WORD *)&gameObject->_3[3]
         && gameObject->players[a1].color < (signed int)*(_WORD *)&gameObject->_3[3]
         || gameObject->players[curPlayerIdx].color >= (signed int)*(_WORD *)&gameObject->_3[3]
         && gameObject->players[a1].color >= (signed int)*(_WORD *)&gameObject->_3[3]))
       || loadOrNewGameSelected
       && !gameObject->field_2
       && gameObject->field_4 == 8
       && gameObject->players[a1].color
       && gameObject->players[a1].color != 3);
}
